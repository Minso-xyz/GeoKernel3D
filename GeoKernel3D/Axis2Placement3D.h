#pragma once

#include "Point3D.h"
#include "Vector3D.h"

class Axis2Placement3D
{
public:
	Point3D Origin;
	Vector3D Axis;   // Local Z-direction (Normal)
	Vector3D RefDirection;   // Local X-direction

public:
	Axis2Placement3D()
	{
		Origin = Point3D(0, 0, 0);
		Axis = Vector3D(0, 0, 1);
		RefDirection = Vector3D(1, 0, 0);
	}
public:
	Axis2Placement3D(Point3D origin, Vector3D axis, Vector3D refDirection)
	{
		Origin = origin;
		Axis = axis;
		RefDirection = refDirection;
	}

public:
	Vector3D GetXAxis() const
	{
		return RefDirection;
	}

public:
	Vector3D GetZAxis() const
	{
		return Axis;
	}

public:
	Vector3D GetYAxis() const
	{
		return Axis.Cross(RefDirection);
	}
};
