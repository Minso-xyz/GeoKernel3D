#pragma once
#include "Point3D.h"
#include "MathUtil.h"

class BoundingBox
{
public:
	Point3D Min;
	Point3D Max;

public:
	BoundingBox()
	{
		Min = Point3D(0, 0, 0);
		Max = Point3D(0, 0, 0);
	}

public:
	BoundingBox(
		Point3D min,
		Point3D max
	)
	{
		Min = min;
		Max = max;
	}

public:
	Point3D Center()
	{
		double x = (Min.X + Max.X) * 0.5;
		double y = (Min.Y + Max.Y) * 0.5;
		double z = (Min.Z + Max.Z) * 0.5;

		return Point3D(x,y,z);
	}

public:
	double Width()
	{
		return Max.X - Min.X;
	}

public:
	double Height()
	{
		return Max.Y - Min.Y;
	}

public:
	double Width()
	{
		return Max.Z - Min.Z;
	}

public:
	bool Contains(Point3D point)
	{
		bool x = false;
		bool y = false;
		bool z = false;

		if (point.X >= Min.X && point.X <= Max.X) x = true;
		if (point.Y >= Min.Y && point.Y <= Max.Y) y = true;
		if (point.Z >= Min.Z && point.Z <= Max.Z) z = true;
		
		return x && y && z;
	}

public:
	bool Intersects(BoundingBox other)
	{
		bool x = false;
		bool y = false;
		bool z = false;

		if (Max.X >= other.Min.X && other.Max.X >= Min.X) x = true;
		if (Max.Y >= other.Min.Y && other.Max.Y >= Min.Y) y = true;
		if (Max.Z >= other.Min.Z && other.Max.Z >= Min.Z) z = true;

		return x && y && z;
	}
};