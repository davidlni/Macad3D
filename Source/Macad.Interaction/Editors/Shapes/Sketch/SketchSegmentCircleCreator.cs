﻿using System.Collections.Generic;
using Macad.Interaction.Visual;
using Macad.Common;
using Macad.Core.Shapes;
using Macad.Occt;
using Macad.Presentation;

namespace Macad.Interaction.Editors.Shapes
{
    public sealed class SketchSegmentCircleCreator : ISketchSegmentCreator
    {
        SketchEditorTool _SketchEditorTool;
        SketchPointAction _PointAction;
        SketchSegmentCircle _Segment;
        SketchEditorSegmentElement _Element;
        Coord2DHudElement _Coord2DHudElement;
        ValueHudElement _ValueHudElement;
        readonly Dictionary<int, Pnt2d> _Points = new(2);
        readonly int[] _MergePointIndices = new int[2];
        Marker _Marker;

        //--------------------------------------------------------------------------------------------------

        public bool Start(SketchEditorTool sketchEditorTool)
        {
            _SketchEditorTool = sketchEditorTool;

            _PointAction = new SketchPointAction(_SketchEditorTool);
            if (!_SketchEditorTool.WorkspaceController.StartToolAction(_PointAction, false))
                return false;
            _PointAction.Previewed += _OnActionPreview;
            _PointAction.Finished += _OnActionFinished;

            _Coord2DHudElement = _SketchEditorTool.WorkspaceController.HudManager?.CreateElement<Coord2DHudElement>(this);

            _SketchEditorTool.StatusText = "Select center point of the circle.";

            return true;
        }

        //--------------------------------------------------------------------------------------------------

        public void Stop()
        {
            _Marker?.Remove();
            _Element?.Remove();

            _PointAction.Stop();
            _SketchEditorTool.WorkspaceController.Invalidate();

            _SketchEditorTool.WorkspaceController.HudManager?.RemoveElement(_Coord2DHudElement);
            _Coord2DHudElement = null;
            _SketchEditorTool.WorkspaceController.HudManager?.RemoveElement(_ValueHudElement);
            _ValueHudElement = null;
        }

        //--------------------------------------------------------------------------------------------------

        public bool Continue(int continueWithPoint)
        {
            return false;
        }

        //--------------------------------------------------------------------------------------------------

        void _OnActionPreview(ToolAction toolAction)
        {
            if (toolAction == _PointAction)
            {
                if (_Segment != null)
                {
                    _Points[1] = _PointAction.Point;
                    _Element.OnPointsChanged(_Points, null);
                    _SketchEditorTool.WorkspaceController.Invalidate();

                    if (_ValueHudElement == null && _SketchEditorTool.WorkspaceController.HudManager != null)
                    {
                        _ValueHudElement = _SketchEditorTool.WorkspaceController.HudManager?.CreateElement<ValueHudElement>(this);
                        _ValueHudElement.Label = "Radius:";
                        _ValueHudElement.Units = ValueUnits.Length;
                        _ValueHudElement.ValueEntered += _ValueHudElement_ValueEntered;
                    }
                    _ValueHudElement?.SetValue(_Segment.Radius(_Points));
                }

                _Coord2DHudElement?.SetValues(_PointAction.PointOnWorkingPlane.X, _PointAction.PointOnWorkingPlane.Y);
            }
        }

        //--------------------------------------------------------------------------------------------------

        void _OnActionFinished(ToolAction toolAction)
        {
            if (toolAction == _PointAction)
            {
                if (_Segment == null)
                {
                    _Points.Add(0, _PointAction.Point);
                    _MergePointIndices[0] = _PointAction.MergeCandidateIndex;
                    _Points.Add(1, _PointAction.Point);
                    _Segment = new SketchSegmentCircle(0, 1);

                    _Marker = new Marker(_SketchEditorTool.WorkspaceController, Marker.Styles.Bitmap | Marker.Styles.Topmost, Marker.BallImage);
                    _Marker.Set(_PointAction.Point, _SketchEditorTool.Sketch.Plane);

                    _Element = new SketchEditorSegmentElement(_SketchEditorTool, -1, _Segment, _SketchEditorTool.Transform, _SketchEditorTool.Sketch.Plane);
                    _Element.IsCreating = true;
                    _Element.OnPointsChanged(_Points, null);

                    _SketchEditorTool.WorkspaceController.Invalidate();

                    _SketchEditorTool.StatusText = "Select any rim point of the circle.";

                    _PointAction.Reset();
                } 
                else
                {
                    if (_Points[0].Distance(_PointAction.Point) < 0.001)
                    {
                        // Minimum length not met
                        _PointAction.Reset();
                        return;
                    }

                    _Points[1] = _PointAction.Point;
                    _MergePointIndices[1] = _PointAction.MergeCandidateIndex;

                    _PointAction.Stop();

                    _SketchEditorTool.FinishSegmentCreation(_Points, _MergePointIndices, new SketchSegment[] { _Segment }, null);
                }
            }
        }

        //--------------------------------------------------------------------------------------------------

        void _ValueHudElement_ValueEntered(ValueHudElement hudElement, double newValue)
        {
            if (newValue <= 0)
                return;

            Vec2d vec = new(_Points[0], _Points[1]);
            if (vec.Magnitude() == 0)
                return;

            _Points[1] = _Points[0].Translated(vec.Normalized().Scaled(newValue));
            _MergePointIndices[1] = -1;
            _PointAction.Stop();
            _SketchEditorTool.FinishSegmentCreation(_Points, _MergePointIndices, new SketchSegment[] { _Segment }, null);
        }

        //--------------------------------------------------------------------------------------------------

    }
}