#pragma once
#include "Point3D.h"
#include "Vector3D.h"


class Plane
{
public:
	Point3D Origin;
	Vector3D Normal;

	Plane(Point3D origin, Vector3D normal)
	{
		Origin = origin;
		Normal = normal.Unit();  // Normalized
	}

public:
	double DistanceTo(Point3D point)
	{
		Vector3D v = Origin.VectorTo(point);
		return v.Dot(Normal);
	}

public:
	Point3D ProjectPoint(Point3D point)
	{
		double distance = DistanceTo(point);
		return point - (Normal * distance);
	}
};
