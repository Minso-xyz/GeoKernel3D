#pragma once
#include <cmath>
#include "Vector3D.h"

class Point3D
{
public:
	double X;
	double Y;
	double Z;

public:
	Point3D()
	{
		X = 0;
		Y = 0;
		Z = 0;
	}

public:
	Point3D(double x, double y, double z)
	{
		X = x;
		Y = y;
		Z = z;
	}

public:
	Vector3D VectorTo(Point3D other)
	{
		return Vector3D(other.X - X, other.Y - Y, other.Z - Z);
	}

public:
	double DistanceTo(Point3D other)
	{
		double dx = X - other.X;
		double dy = Y - other.Y;
		double dz = Z - other.Z;

		return sqrt(dx * dx + dy * dy + dz * dz);
	}

public:
	Point3D Translate(double dx, double dy, double dz)
	{
		return Point3D(X + dx, Y + dy, Z + dz);
	}

public:
	Point3D Translate(Vector3D v)
	{
		return Point3D(
			X + v.X,
			Y + v.Y,
			Z + v.Z
		);
	}

public:
	Point3D operator+(Vector3D v)
	{
		return Point3D(
			X + v.X,
			Y + v.Y,
			Z + v.Z
		);
	}
};
