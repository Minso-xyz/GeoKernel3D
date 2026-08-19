#pragma once
#include "Point3D.h"
#include <vector>

class BezierCurve
{
public:
	Point3D P0;
	Point3D P1;
	Point3D P2;
	Point3D P3;
	Point3D P4;
	
	// Linear Bezier - 1st degree
	BezierCurve(
		Point3D p0,
		Point3D p1
	)
	{
		P0 = p0;
		P1 = p1;
	}

	// Quadratic Bezier - 2nd degree
	BezierCurve(
		Point3D p0,
		Point3D p1,
		Point3D p2
	)
	{
		P0 = p0;
		P1 = p1;
		P2 = p2;
	}

	// Cubic Bezier - 3rd degree
	BezierCurve(
		Point3D p0,
		Point3D p1,
		Point3D p2,
		Point3D p3)
	{
		P0 = p0;
		P1 = p1;
		P2 = p2;
		P3 = p3;
	}

	// Quartic Bezier - 4th degree
	BezierCurve(
		Point3D p0,
		Point3D p1,
		Point3D p2,
		Point3D p3,
		Point3D p4
	)
	{
		P0 = p0;
		P1 = p1;
		P2 = p2;
		P3 = p3;
		P4 = p4;
	}

public:
	Point3D Evaluate_LinearBezier(double t)
	{
		return
			P0 * (1 - t) +
			P1 * t;
	}

public:
	Point3D Evaluate_QuadraticBezier(double t)
	{
		double t1 = (1 - t);

		return
			P0 * (t1 * t1) +
			P1 * (2 * t1 * t) +
			P2 * (t * t);
	}

public:
	Point3D Evaluate_CubicBezier(double t)
	{
		double t1 = (1 - t);

		return
			P0 * (t1 * t1 * t1) +
			P1 * (3 * t1 * t1 * t) +
			P2 * (3 * t1 * t * t) +
			P3 * (t * t * t);
	}

public:
	Point3D Evaluate_QuarticBezier(double t)
	{
		double t1 = (1 - t);

		return
			P0 * (t1 * t1 * t1 * t1) +
			P1 * (4 * t1 * t1 * t1 * t) +
			P2 * (6 * t1 * t1 * t * t) +
			P3 * (4 * t1 * t * t * t) +
			P4 * (t * t * t * t);
	}

	// Generate control points for a Bezier curve by dividing the range from 0 to 1 into small steps based on segmentCount
public:
	std::vector<Point3D>
		Tessellate(int segmentCount)
	{
		std::vector<Point3D> points;

		for (int i = 0; i <= segmentCount; i++)
		{
			double t = (double)i / segmentCount;
			points.push_back(Evaluate_CubicBezier(t));
		}
		return points;
	}
};