#pragma once
#include "Point3D.h"
#include "Vector3D.h"
#include "Axis2Placement3D.h"
#include <vector>
#include <math.h>

class Circle3D
{
public:
	Axis2Placement3D Position;
	double Radius;

public:
	Circle3D()
	{
		Position = Axis2Placement3D();
		Radius = 1.0;
	}

public:
	Point3D Evaluate(double angle) const;
	std::vector<Point3D> CreatePolyline(int& segmentCount) const;
	Vector3D GetYDirection();

public:
	Circle3D(Axis2Placement3D position, double radius)
	{
		Position = position;
		Radius = radius;
	}

public:
	double Length() const
	{
		double pi = 3.14159265359;
		return 2 * pi * Radius;
	}
};
