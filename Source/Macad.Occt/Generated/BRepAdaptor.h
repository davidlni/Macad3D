// Generated wrapper code for package BRepAdaptor

#pragma once

#include "Adaptor3d.h"
#include "Geom2dAdaptor.h"

namespace Macad
{
namespace Occt
{
//---------------------------------------------------------------------
//  Class  BRepAdaptor_Array1OfCurve
//---------------------------------------------------------------------
public ref class BRepAdaptor_Array1OfCurve sealed : public BaseClass<::BRepAdaptor_Array1OfCurve>
{

#ifdef Include_BRepAdaptor_Array1OfCurve_h
public:
	Include_BRepAdaptor_Array1OfCurve_h
#endif

public:
	BRepAdaptor_Array1OfCurve(::BRepAdaptor_Array1OfCurve* nativeInstance)
		: BaseClass<::BRepAdaptor_Array1OfCurve>( nativeInstance, true )
	{}

	BRepAdaptor_Array1OfCurve(::BRepAdaptor_Array1OfCurve& nativeInstance)
		: BaseClass<::BRepAdaptor_Array1OfCurve>( &nativeInstance, false )
	{}

	property ::BRepAdaptor_Array1OfCurve* NativeInstance
	{
		::BRepAdaptor_Array1OfCurve* get()
		{
			return static_cast<::BRepAdaptor_Array1OfCurve*>(_NativeInstance);
		}
	}

public:
	BRepAdaptor_Array1OfCurve();
	BRepAdaptor_Array1OfCurve(int theLower, int theUpper);
	BRepAdaptor_Array1OfCurve(Macad::Occt::BRepAdaptor_Array1OfCurve^ theOther);
	BRepAdaptor_Array1OfCurve(Macad::Occt::BRepAdaptor_Curve^ theBegin, int theLower, int theUpper);
	void Init(Macad::Occt::BRepAdaptor_Curve^ theValue);
	int Size();
	int Length();
	bool IsEmpty();
	int Lower();
	int Upper();
	bool IsDeletable();
	bool IsAllocated();
	Macad::Occt::BRepAdaptor_Array1OfCurve^ Assign(Macad::Occt::BRepAdaptor_Array1OfCurve^ theOther);
	Macad::Occt::BRepAdaptor_Array1OfCurve^ Move(Macad::Occt::BRepAdaptor_Array1OfCurve^ theOther);
	Macad::Occt::BRepAdaptor_Curve^ First();
	Macad::Occt::BRepAdaptor_Curve^ ChangeFirst();
	Macad::Occt::BRepAdaptor_Curve^ Last();
	Macad::Occt::BRepAdaptor_Curve^ ChangeLast();
	Macad::Occt::BRepAdaptor_Curve^ Value(int theIndex);
	Macad::Occt::BRepAdaptor_Curve^ ChangeValue(int theIndex);
	void SetValue(int theIndex, Macad::Occt::BRepAdaptor_Curve^ theItem);
	void Resize(int theLower, int theUpper, bool theToCopyData);
}; // class BRepAdaptor_Array1OfCurve

//---------------------------------------------------------------------
//  Class  BRepAdaptor_Curve
//---------------------------------------------------------------------
public ref class BRepAdaptor_Curve sealed : public Macad::Occt::Adaptor3d_Curve
{

#ifdef Include_BRepAdaptor_Curve_h
public:
	Include_BRepAdaptor_Curve_h
#endif

public:
	BRepAdaptor_Curve(::BRepAdaptor_Curve* nativeInstance)
		: Macad::Occt::Adaptor3d_Curve( nativeInstance )
	{}

	BRepAdaptor_Curve(::BRepAdaptor_Curve& nativeInstance)
		: Macad::Occt::Adaptor3d_Curve( nativeInstance )
	{}

	property ::BRepAdaptor_Curve* NativeInstance
	{
		::BRepAdaptor_Curve* get()
		{
			return static_cast<::BRepAdaptor_Curve*>(_NativeInstance);
		}
	}

	static Macad::Occt::BRepAdaptor_Curve^ CreateDowncasted(::BRepAdaptor_Curve* instance);

public:
	BRepAdaptor_Curve();
	BRepAdaptor_Curve(Macad::Occt::TopoDS_Edge^ E);
	BRepAdaptor_Curve(Macad::Occt::TopoDS_Edge^ E, Macad::Occt::TopoDS_Face^ F);
	BRepAdaptor_Curve(Macad::Occt::BRepAdaptor_Curve^ parameter1);
	Macad::Occt::Adaptor3d_Curve^ ShallowCopy();
	void Reset();
	void Initialize(Macad::Occt::TopoDS_Edge^ E);
	void Initialize(Macad::Occt::TopoDS_Edge^ E, Macad::Occt::TopoDS_Face^ F);
	Macad::Occt::Trsf Trsf();
	bool Is3DCurve();
	bool IsCurveOnSurface();
	Macad::Occt::GeomAdaptor_Curve^ Curve();
	Macad::Occt::Adaptor3d_CurveOnSurface^ CurveOnSurface();
	Macad::Occt::TopoDS_Edge^ Edge();
	double Tolerance();
	double FirstParameter();
	double LastParameter();
	Macad::Occt::GeomAbs_Shape Continuity();
	int NbIntervals(Macad::Occt::GeomAbs_Shape S);
	void Intervals(Macad::Occt::TColStd_Array1OfReal^ T, Macad::Occt::GeomAbs_Shape S);
	Macad::Occt::Adaptor3d_Curve^ Trim(double First, double Last, double Tol);
	bool IsClosed();
	bool IsPeriodic();
	double Period();
	Macad::Occt::Pnt Value(double U);
	void D0(double U, Macad::Occt::Pnt% P);
	void D1(double U, Macad::Occt::Pnt% P, Macad::Occt::Vec% V);
	void D2(double U, Macad::Occt::Pnt% P, Macad::Occt::Vec% V1, Macad::Occt::Vec% V2);
	void D3(double U, Macad::Occt::Pnt% P, Macad::Occt::Vec% V1, Macad::Occt::Vec% V2, Macad::Occt::Vec% V3);
	Macad::Occt::Vec DN(double U, int N);
	double Resolution(double R3d);
	Macad::Occt::GeomAbs_CurveType GetGeomType();
	Macad::Occt::gp_Lin^ Line();
	Macad::Occt::gp_Circ^ Circle();
	Macad::Occt::gp_Elips^ Ellipse();
	Macad::Occt::gp_Hypr^ Hyperbola();
	Macad::Occt::gp_Parab^ Parabola();
	int Degree();
	bool IsRational();
	int NbPoles();
	int NbKnots();
	Macad::Occt::Geom_BezierCurve^ Bezier();
	Macad::Occt::Geom_BSplineCurve^ BSpline();
	Macad::Occt::Geom_OffsetCurve^ OffsetCurve();
}; // class BRepAdaptor_Curve

//---------------------------------------------------------------------
//  Class  BRepAdaptor_HArray1OfCurve
//---------------------------------------------------------------------
public ref class BRepAdaptor_HArray1OfCurve sealed : public Macad::Occt::Standard_Transient
{

#ifdef Include_BRepAdaptor_HArray1OfCurve_h
public:
	Include_BRepAdaptor_HArray1OfCurve_h
#endif

public:
	BRepAdaptor_HArray1OfCurve(::BRepAdaptor_HArray1OfCurve* nativeInstance)
		: Macad::Occt::Standard_Transient( nativeInstance )
	{}

	BRepAdaptor_HArray1OfCurve(::BRepAdaptor_HArray1OfCurve& nativeInstance)
		: Macad::Occt::Standard_Transient( nativeInstance )
	{}

	property ::BRepAdaptor_HArray1OfCurve* NativeInstance
	{
		::BRepAdaptor_HArray1OfCurve* get()
		{
			return static_cast<::BRepAdaptor_HArray1OfCurve*>(_NativeInstance);
		}
	}

	static Macad::Occt::BRepAdaptor_HArray1OfCurve^ CreateDowncasted(::BRepAdaptor_HArray1OfCurve* instance);

public:
	BRepAdaptor_HArray1OfCurve();
	BRepAdaptor_HArray1OfCurve(int theLower, int theUpper);
	BRepAdaptor_HArray1OfCurve(int theLower, int theUpper, Macad::Occt::BRepAdaptor_Curve^ theValue);
	BRepAdaptor_HArray1OfCurve(Macad::Occt::BRepAdaptor_Array1OfCurve^ theOther);
	BRepAdaptor_HArray1OfCurve(Macad::Occt::BRepAdaptor_HArray1OfCurve^ parameter1);
	Macad::Occt::BRepAdaptor_Array1OfCurve^ Array1();
	Macad::Occt::BRepAdaptor_Array1OfCurve^ ChangeArray1();
	void Init(Macad::Occt::BRepAdaptor_Curve^ theValue);
	int Size();
	int Length();
	bool IsEmpty();
	int Lower();
	int Upper();
	bool IsDeletable();
	bool IsAllocated();
	/* Method skipped due to unknown mapping: NCollection_Array1<BRepAdaptor_Curve> Assign(NCollection_Array1<BRepAdaptor_Curve> theOther, ) */
	/* Method skipped due to unknown mapping: NCollection_Array1<BRepAdaptor_Curve> Move(NCollection_Array1<BRepAdaptor_Curve> theOther, ) */
	Macad::Occt::BRepAdaptor_Curve^ First();
	Macad::Occt::BRepAdaptor_Curve^ ChangeFirst();
	Macad::Occt::BRepAdaptor_Curve^ Last();
	Macad::Occt::BRepAdaptor_Curve^ ChangeLast();
	Macad::Occt::BRepAdaptor_Curve^ Value(int theIndex);
	Macad::Occt::BRepAdaptor_Curve^ ChangeValue(int theIndex);
	void SetValue(int theIndex, Macad::Occt::BRepAdaptor_Curve^ theItem);
	void Resize(int theLower, int theUpper, bool theToCopyData);
}; // class BRepAdaptor_HArray1OfCurve

//---------------------------------------------------------------------
//  Class  BRepAdaptor_CompCurve
//---------------------------------------------------------------------
public ref class BRepAdaptor_CompCurve sealed : public Macad::Occt::Adaptor3d_Curve
{

#ifdef Include_BRepAdaptor_CompCurve_h
public:
	Include_BRepAdaptor_CompCurve_h
#endif

public:
	BRepAdaptor_CompCurve(::BRepAdaptor_CompCurve* nativeInstance)
		: Macad::Occt::Adaptor3d_Curve( nativeInstance )
	{}

	BRepAdaptor_CompCurve(::BRepAdaptor_CompCurve& nativeInstance)
		: Macad::Occt::Adaptor3d_Curve( nativeInstance )
	{}

	property ::BRepAdaptor_CompCurve* NativeInstance
	{
		::BRepAdaptor_CompCurve* get()
		{
			return static_cast<::BRepAdaptor_CompCurve*>(_NativeInstance);
		}
	}

	static Macad::Occt::BRepAdaptor_CompCurve^ CreateDowncasted(::BRepAdaptor_CompCurve* instance);

public:
	BRepAdaptor_CompCurve();
	BRepAdaptor_CompCurve(Macad::Occt::TopoDS_Wire^ W, bool KnotByCurvilinearAbcissa);
	BRepAdaptor_CompCurve(Macad::Occt::TopoDS_Wire^ W);
	BRepAdaptor_CompCurve(Macad::Occt::TopoDS_Wire^ W, bool KnotByCurvilinearAbcissa, double First, double Last, double Tol);
	BRepAdaptor_CompCurve(Macad::Occt::BRepAdaptor_CompCurve^ parameter1);
	Macad::Occt::Adaptor3d_Curve^ ShallowCopy();
	void Initialize(Macad::Occt::TopoDS_Wire^ W, bool KnotByCurvilinearAbcissa);
	void Initialize(Macad::Occt::TopoDS_Wire^ W, bool KnotByCurvilinearAbcissa, double First, double Last, double Tol);
	Macad::Occt::TopoDS_Wire^ Wire();
	void Edge(double U, Macad::Occt::TopoDS_Edge^ E, double% UonE);
	double FirstParameter();
	double LastParameter();
	Macad::Occt::GeomAbs_Shape Continuity();
	int NbIntervals(Macad::Occt::GeomAbs_Shape S);
	void Intervals(Macad::Occt::TColStd_Array1OfReal^ T, Macad::Occt::GeomAbs_Shape S);
	Macad::Occt::Adaptor3d_Curve^ Trim(double First, double Last, double Tol);
	bool IsClosed();
	bool IsPeriodic();
	double Period();
	Macad::Occt::Pnt Value(double U);
	void D0(double U, Macad::Occt::Pnt% P);
	void D1(double U, Macad::Occt::Pnt% P, Macad::Occt::Vec% V);
	void D2(double U, Macad::Occt::Pnt% P, Macad::Occt::Vec% V1, Macad::Occt::Vec% V2);
	void D3(double U, Macad::Occt::Pnt% P, Macad::Occt::Vec% V1, Macad::Occt::Vec% V2, Macad::Occt::Vec% V3);
	Macad::Occt::Vec DN(double U, int N);
	double Resolution(double R3d);
	Macad::Occt::GeomAbs_CurveType GetGeomType();
	Macad::Occt::gp_Lin^ Line();
	Macad::Occt::gp_Circ^ Circle();
	Macad::Occt::gp_Elips^ Ellipse();
	Macad::Occt::gp_Hypr^ Hyperbola();
	Macad::Occt::gp_Parab^ Parabola();
	int Degree();
	bool IsRational();
	int NbPoles();
	int NbKnots();
	Macad::Occt::Geom_BezierCurve^ Bezier();
	Macad::Occt::Geom_BSplineCurve^ BSpline();
}; // class BRepAdaptor_CompCurve

//---------------------------------------------------------------------
//  Class  BRepAdaptor_Curve2d
//---------------------------------------------------------------------
public ref class BRepAdaptor_Curve2d sealed : public Macad::Occt::Geom2dAdaptor_Curve
{

#ifdef Include_BRepAdaptor_Curve2d_h
public:
	Include_BRepAdaptor_Curve2d_h
#endif

public:
	BRepAdaptor_Curve2d(::BRepAdaptor_Curve2d* nativeInstance)
		: Macad::Occt::Geom2dAdaptor_Curve( nativeInstance )
	{}

	BRepAdaptor_Curve2d(::BRepAdaptor_Curve2d& nativeInstance)
		: Macad::Occt::Geom2dAdaptor_Curve( nativeInstance )
	{}

	property ::BRepAdaptor_Curve2d* NativeInstance
	{
		::BRepAdaptor_Curve2d* get()
		{
			return static_cast<::BRepAdaptor_Curve2d*>(_NativeInstance);
		}
	}

	static Macad::Occt::BRepAdaptor_Curve2d^ CreateDowncasted(::BRepAdaptor_Curve2d* instance);

public:
	BRepAdaptor_Curve2d();
	BRepAdaptor_Curve2d(Macad::Occt::TopoDS_Edge^ E, Macad::Occt::TopoDS_Face^ F);
	BRepAdaptor_Curve2d(Macad::Occt::BRepAdaptor_Curve2d^ parameter1);
	Macad::Occt::Adaptor2d_Curve2d^ ShallowCopy();
	void Initialize(Macad::Occt::TopoDS_Edge^ E, Macad::Occt::TopoDS_Face^ F);
	Macad::Occt::TopoDS_Edge^ Edge();
	Macad::Occt::TopoDS_Face^ Face();
}; // class BRepAdaptor_Curve2d

//---------------------------------------------------------------------
//  Class  BRepAdaptor_Surface
//---------------------------------------------------------------------
public ref class BRepAdaptor_Surface sealed : public Macad::Occt::Adaptor3d_Surface
{

#ifdef Include_BRepAdaptor_Surface_h
public:
	Include_BRepAdaptor_Surface_h
#endif

public:
	BRepAdaptor_Surface(::BRepAdaptor_Surface* nativeInstance)
		: Macad::Occt::Adaptor3d_Surface( nativeInstance )
	{}

	BRepAdaptor_Surface(::BRepAdaptor_Surface& nativeInstance)
		: Macad::Occt::Adaptor3d_Surface( nativeInstance )
	{}

	property ::BRepAdaptor_Surface* NativeInstance
	{
		::BRepAdaptor_Surface* get()
		{
			return static_cast<::BRepAdaptor_Surface*>(_NativeInstance);
		}
	}

	static Macad::Occt::BRepAdaptor_Surface^ CreateDowncasted(::BRepAdaptor_Surface* instance);

public:
	BRepAdaptor_Surface();
	BRepAdaptor_Surface(Macad::Occt::TopoDS_Face^ F, bool R);
	BRepAdaptor_Surface(Macad::Occt::TopoDS_Face^ F);
	BRepAdaptor_Surface(Macad::Occt::BRepAdaptor_Surface^ parameter1);
	Macad::Occt::Adaptor3d_Surface^ ShallowCopy();
	void Initialize(Macad::Occt::TopoDS_Face^ F, bool Restriction);
	void Initialize(Macad::Occt::TopoDS_Face^ F);
	Macad::Occt::GeomAdaptor_Surface^ Surface();
	Macad::Occt::GeomAdaptor_Surface^ ChangeSurface();
	Macad::Occt::Trsf Trsf();
	Macad::Occt::TopoDS_Face^ Face();
	double Tolerance();
	double FirstUParameter();
	double LastUParameter();
	double FirstVParameter();
	double LastVParameter();
	Macad::Occt::GeomAbs_Shape UContinuity();
	Macad::Occt::GeomAbs_Shape VContinuity();
	int NbUIntervals(Macad::Occt::GeomAbs_Shape theSh);
	int NbVIntervals(Macad::Occt::GeomAbs_Shape theSh);
	void UIntervals(Macad::Occt::TColStd_Array1OfReal^ T, Macad::Occt::GeomAbs_Shape S);
	void VIntervals(Macad::Occt::TColStd_Array1OfReal^ T, Macad::Occt::GeomAbs_Shape S);
	Macad::Occt::Adaptor3d_Surface^ UTrim(double First, double Last, double Tol);
	Macad::Occt::Adaptor3d_Surface^ VTrim(double First, double Last, double Tol);
	bool IsUClosed();
	bool IsVClosed();
	bool IsUPeriodic();
	double UPeriod();
	bool IsVPeriodic();
	double VPeriod();
	Macad::Occt::Pnt Value(double U, double V);
	void D0(double U, double V, Macad::Occt::Pnt% P);
	void D1(double U, double V, Macad::Occt::Pnt% P, Macad::Occt::Vec% D1U, Macad::Occt::Vec% D1V);
	void D2(double U, double V, Macad::Occt::Pnt% P, Macad::Occt::Vec% D1U, Macad::Occt::Vec% D1V, Macad::Occt::Vec% D2U, Macad::Occt::Vec% D2V, Macad::Occt::Vec% D2UV);
	void D3(double U, double V, Macad::Occt::Pnt% P, Macad::Occt::Vec% D1U, Macad::Occt::Vec% D1V, Macad::Occt::Vec% D2U, Macad::Occt::Vec% D2V, Macad::Occt::Vec% D2UV, Macad::Occt::Vec% D3U, Macad::Occt::Vec% D3V, Macad::Occt::Vec% D3UUV, Macad::Occt::Vec% D3UVV);
	Macad::Occt::Vec DN(double U, double V, int Nu, int Nv);
	double UResolution(double theR3d);
	double VResolution(double theR3d);
	Macad::Occt::GeomAbs_SurfaceType GetGeomType();
	Macad::Occt::Pln Plane();
	Macad::Occt::gp_Cylinder^ Cylinder();
	Macad::Occt::gp_Cone^ Cone();
	Macad::Occt::gp_Sphere^ Sphere();
	Macad::Occt::gp_Torus^ Torus();
	int UDegree();
	int NbUPoles();
	int VDegree();
	int NbVPoles();
	int NbUKnots();
	int NbVKnots();
	bool IsURational();
	bool IsVRational();
	Macad::Occt::Geom_BezierSurface^ Bezier();
	Macad::Occt::Geom_BSplineSurface^ BSpline();
	Macad::Occt::Ax1 AxeOfRevolution();
	Macad::Occt::Dir Direction();
	Macad::Occt::Adaptor3d_Curve^ BasisCurve();
	Macad::Occt::Adaptor3d_Surface^ BasisSurface();
	double OffsetValue();
}; // class BRepAdaptor_Surface

}; // namespace Occt
}; // namespace Macad
