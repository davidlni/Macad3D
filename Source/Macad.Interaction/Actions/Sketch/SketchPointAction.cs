﻿using System.Collections.Generic;
using System.Diagnostics;
using Macad.Interaction.Editors.Shapes;
using Macad.Interaction.Visual;
using Macad.Core;
using Macad.Occt;


namespace Macad.Interaction
{
    public class SketchPointAction : ToolAction
    {
        public Pnt2d Point { get; private set; }
        public Pnt2d PointOnWorkingPlane { get; private set; }
        public int MergeCandidateIndex { get; private set; }
        public bool EnablePointMerge { get; set; }
        public IEnumerable<Pnt2d> AdditionalSnapPoints { get; set; }

        //--------------------------------------------------------------------------------------------------

        public override SnapMode SupportedSnapModes => SnapMode.Grid | SnapMode.Vertex;

        //--------------------------------------------------------------------------------------------------

        readonly SketchEditorTool _SketchEditorTool;
        AIS_Point _Marker;
        Marker _MergePreviewMarker;
        Pnt2d _MergeCandidatePoint;
        SelectionContext _SelectionContext;

        //--------------------------------------------------------------------------------------------------

        #region Constraint Point Callback

        public delegate void ConstraintPointCallback(SketchPointAction sender, ref Pnt2d point);

        public event ConstraintPointCallback ConstraintPoint;

        public void OnConstraintPoint(ref Pnt2d point)
        {
            ConstraintPoint?.Invoke(this, ref point);
        }

        //--------------------------------------------------------------------------------------------------

        #endregion

        public SketchPointAction(SketchEditorTool sketchEditorTool)
            : base(sketchEditorTool)
        {
            _SketchEditorTool = sketchEditorTool;
            EnablePointMerge = true;
        }

        //--------------------------------------------------------------------------------------------------

        public override bool Start()
        {
            Debug.Assert(_SketchEditorTool != null);

            _SelectionContext = WorkspaceController.Selection.OpenContext();
            _SketchEditorTool.Elements.Activate(true, false, false);

            return true;
        }

        //--------------------------------------------------------------------------------------------------

        void EnsureMarker()
        {
            if (_Marker == null)
            {
                _Marker = new AIS_Point(new Geom_CartesianPoint(0, 0, 0));
                _Marker.SetMarker(Aspect_TypeOfMarker.Aspect_TOM_PLUS);
                _Marker.SetWidth(2.0);
                _Marker.SetZLayer(-3); // TOPMOST
                WorkspaceController.Workspace.AisContext.Display(_Marker, false);
                WorkspaceController.Workspace.AisContext.Deactivate(_Marker);
            }
        }

        //--------------------------------------------------------------------------------------------------

        void ProcessMouseInput(MouseEventData data)
        {
            // Get new point from parameters
            double u = 0, v = 0;
            ElSLib.Parameters(_SketchEditorTool.Sketch.Plane, data.PointOnPlane, ref u, ref v);
            var sketchPoint = new Pnt2d(u, v);

            Point = Snap(sketchPoint);

            // Recalculate point on working plane
            if (_SketchEditorTool.Sketch.Plane.Location.IsEqual(WorkspaceController.Workspace.WorkingPlane.Location, 0.00001))
            {
                PointOnWorkingPlane = Point;
            }
            else
            {
                ElSLib.Parameters(WorkspaceController.Workspace.WorkingPlane, _SketchEditorTool.Sketch.Plane.Location, ref u, ref v);
                PointOnWorkingPlane = Point.Translated(new Vec2d(u, v));
            }
        }

        //--------------------------------------------------------------------------------------------------

        public override bool OnMouseMove(MouseEventData data)
        {
            if (!IsFinished)
            {
                EnsureMarker();

                ProcessMouseInput(data);

                _Marker.SetComponent(new Geom_CartesianPoint(ElSLib.Value(Point.X, Point.Y, _SketchEditorTool.Sketch.Plane)));
                WorkspaceController.Workspace.AisContext.RecomputePrsOnly(_Marker, false);
                WorkspaceController.Invalidate();

                UpdateMergeMarker();

                return base.OnMouseMove(data);
            }
            return false;
        }

        //--------------------------------------------------------------------------------------------------

        public override bool OnMouseUp(MouseEventData data, bool shiftSelected)
        {
            if (!IsFinished)
            {
                ProcessMouseInput(data);

                if (MergeCandidateIndex >= 0)
                {
                    Point = _SketchEditorTool.Sketch.Points[MergeCandidateIndex];
                }
                IsFinished = true;
            }
            return true;
        }

        //--------------------------------------------------------------------------------------------------

        public override void Stop()
        {
            if (_Marker != null)
            {
                WorkspaceController.Workspace.AisContext.Remove(_Marker, false);
                _Marker = null;
            }
            if (_MergePreviewMarker != null)
            {
                _MergePreviewMarker.Remove();
                _MergePreviewMarker = null;
            }

            WorkspaceController.Selection.CloseContext(_SelectionContext);
            _SelectionContext = null;

            WorkspaceController.Invalidate();

            base.Stop();
        }

        //--------------------------------------------------------------------------------------------------

        Pnt2d Snap(Pnt2d point)
        {
            Pnt2d snapPoint = point;

            // Snap
            double snapDistance = WorkspaceController.ActiveViewport.GizmoScale*0.2;
            var snapInfo = SketchToolHelper.Snap(point, _SketchEditorTool.Sketch, AdditionalSnapPoints);
            if (snapInfo.Distance < snapDistance)
            {
                snapPoint = snapInfo.Point;
            }

            // Constraint point
            OnConstraintPoint(ref snapPoint);

            // Find merge candidate
            double mergeDistance = WorkspaceController.ActiveViewport.GizmoScale*0.2;
            MergeCandidateIndex = -1;

            if (EnablePointMerge)
            {
                foreach (var pointKvp in _SketchEditorTool.Sketch.Points)
                {
                    var distance = pointKvp.Value.Distance(snapPoint);
                    if (distance < mergeDistance)
                    {
                        _MergeCandidatePoint = pointKvp.Value;
                        MergeCandidateIndex = pointKvp.Key;
                    }
                }
            }

            return snapPoint;
        }

        //--------------------------------------------------------------------------------------------------

        void UpdateMergeMarker()
        {
            if (MergeCandidateIndex >= 0)
            {
                var geomPoint = new Geom_CartesianPoint(_MergeCandidatePoint.X, _MergeCandidatePoint.Y, 0);
                geomPoint.Transform(_SketchEditorTool.Transform);
                if (_MergePreviewMarker == null)
                {
                    _MergePreviewMarker = new Marker(WorkspaceController, Marker.Styles.Bitmap | Marker.Styles.Topmost, Marker.RingImage);
                    _MergePreviewMarker.Set(geomPoint);
                    _MergePreviewMarker.SetColor(Colors.Highlight);
                }
                else
                {
                    _MergePreviewMarker.Set(geomPoint);
                }
            }
            else
            {
                if (_MergePreviewMarker != null)
                {
                    _MergePreviewMarker.Remove();
                    _MergePreviewMarker = null;
                }
            }

            WorkspaceController.Invalidate();
        }

        //--------------------------------------------------------------------------------------------------

    }
}