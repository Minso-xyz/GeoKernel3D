#include <iostream>
#include "Point3D.h"
#include "Vector3D.h"
#include "Line3D.h"
#include "Matrix4x4.h"
#include "MathUtil.h"
#include "BezierCurve.h"
#include <fstream>

int main()
{
	// Vector3D Length
	Vector3D v1(3, 4, 0);
	double lengthVector = v1.Length();
	std::cout << lengthVector << std::endl;   // 5

	// Vector3D Unit
	Vector3D unit = v1.Unit();
	std::cout << "(" << unit.X << ", " << unit.Y << ", " << unit.Z << ")" << std::endl;   // (0.6, 0.8, 0.0)

	// Vector3D Normalize
	Vector3D normalized = v1.Normalize();
	std::cout << "(" << normalized.X << ", " << normalized.Y << ", " << normalized.Z << ")" << std::endl;  // Overwrite (0.6, 0.8, 0.0)

	// Vector3D Dot product
	Vector3D a(1, 0, 0);
	Vector3D b(0, 1, 0);
	double dot = a.Dot(b);
	std::cout << "Dot product = " << dot << std::endl;   // 0

	// Vector3D Cross product
	Vector3D c(2, 3, 4);
	Vector3D d(5, 6, 7);
	Vector3D cross = c.Cross(d);
	std::cout << "Cross product = (" << cross.X << ", " << cross.Y << ", " << cross.Z << ")" << std::endl;   // (-3, 6, -3)

	// Point3D VectorTo
	Point3D p1(0,0,0);
	Point3D p2(10, 0, 0);
	Vector3D vectorTo = p1.VectorTo(p2);
	std::cout << "VectorTo = (" << vectorTo.X << ", " << vectorTo.Y << ", " << vectorTo.Z << ")" << std::endl;

	// Point3D DistanceTo
	double distance = p1.DistanceTo(p2);
	std::cout << "Distance = " << distance << std::endl;   // 10

	// Line3D Length
	Point3D p3(0, 0, 0);
	Point3D p4(3, 4, 0);
	Line3D line(p3, p4);
	double lengthLine = line.Length();
	std::cout << "Length = " << lengthLine << std::endl;   // 10

	// Matrix4x4 Tests
	// Point3D Transform
	Point3D p(1, 0, 0);
	Matrix4x4 rotZ = Matrix4x4::CreateRotationZ(90);
	Point3D p_RotZ = rotZ.Transform(p);

	p_RotZ.X = MathUtil::SnapToZero(p_RotZ.X);
	p_RotZ.Y = MathUtil::SnapToZero(p_RotZ.Y);
	p_RotZ.Z = MathUtil::SnapToZero(p_RotZ.Z);
	std::cout << "Point3D : Rotated about Z-axis = (" << p_RotZ.X << ", " << p_RotZ.Y << ", " << p_RotZ.Z << ")" << std::endl;

	// Vector3D Transform
	Vector3D v(1, 0, 0);
	Matrix4x4 rotY = Matrix4x4::CreateRotationY(90);
	Vector3D v_RotY = rotY.Transform(v);

	v_RotY.X = MathUtil::SnapToZero(v_RotY.X);
	v_RotY.Y = MathUtil::SnapToZero(v_RotY.Y);
	v_RotY.Z = MathUtil::SnapToZero(v_RotY.Z);
	std::cout << "Vector3D : Rotated about Y-axis = (" << v_RotY.X << ", " << v_RotY.Y << ", " << v_RotY.Z << ")" << std::endl;

	// Bezier Curve
	Point3D P0 (0, 0, 0);
	Point3D P1(10, 0, 0);
	Point3D P2(10, 10, 0);
	Point3D P3(20, 10, 0);

	BezierCurve curve(P0, P1, P2, P3);
	Point3D point1 = curve.Evaluate_CubicBezier(0);
	std::cout << "Bezier Curve::Evaluate(0) = (" << point1.X << ", " << point1.Y << ", " << point1.Z << ")" << std::endl;   // P0
	Point3D point3 = curve.Evaluate_CubicBezier(1);
	std::cout << "Bezier Curve::Evaluate(1) = (" << point3.X << ", " << point3.Y << ", " << point3.Z << ")" << std::endl;   // P3
	// P1 and P1 are a control point, the curve doesn't always pass
	Point3D pointMid = curve.Evaluate_CubicBezier(0.75);
	std::cout << "Bezier Curve::Evaluate(0.75) = (" << pointMid.X << ", " << pointMid.Y << ", " << pointMid.Z << ")" << std::endl;   // Control point

	// Bezier Curve - creating .csv file to test
	std::ofstream file("BezierCurve.csv");
	file << "X,Y,Z" << std::endl;

	for (double t = 0.0; t <= 1.0; t += 0.01)
	{
		Point3D p = curve.Evaluate_CubicBezier(t);

		file
			<< p.X << ","
			<< p.Y << ","
			<< p.Z
			<< std::endl;
	}

	file.close();

	return 0;
}