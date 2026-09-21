#pragma once

#include "Vector2D.h"

class Point2D
{
public:
	double X;
	double Y;

public:
	Point2D()
	{
		X = 0;
		Y = 0;
	}

public:
	Point2D(double x, double y)
	{
		X = x;
		Y = y;
	}

public:
	Vector2D VectorTo(const Point2D& other) const
	{
		return Vector2D(other.X - X, other.Y - Y);
	}
};