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
	Point3D GetCenter();
	static BoundingBox CalculateBoundingBox(std::vector<Point3D>& points);
	double GetModelRadius() const;
	double Width();
	double Height();
	double Depth();
	bool Contains(Point3D point);
	bool Intersects(BoundingBox other);
};