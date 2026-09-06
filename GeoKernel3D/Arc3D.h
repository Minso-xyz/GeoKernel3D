#pragma once
#include "Circle3D.h"

class Arc3D
{
public:
	Circle3D Circle;
	double StartAngle;
	double EndAngle;

public:
	Arc3D();

public:
	Arc3D(Circle3D circle, double startAngle, double endAngle)
	{
		Circle = circle;
		StartAngle = startAngle;
		EndAngle = endAngle;
	}

public:
	Point3D Evaluate(double t) const;
	std::vector<Point3D> CreatePolyline(int segmentCount) const;
};
