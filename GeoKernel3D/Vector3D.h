#pragma once
#include <cmath>
#include <iostream>

class Vector3D
{
public:
	double X;
	double Y;
	double Z;

public:
	Vector3D()
	{
		X = 0;
		Y = 0;
		Z = 0;
	}

public:
	Vector3D(double x, double y, double z)
	{
		X = x;
		Y = y;
		Z = z;
	}

public:
	double Length()
	{
		return sqrt(X * X + Y * Y + Z * Z);
	}

public:
	Vector3D Unit()
	{
		double length = Length();

		if (length == 0)
		{
			return Vector3D();
		}

		double x = X / length;
		double y = Y / length;
		double z = Z / length;

		return Vector3D(x, y, z);
	}

public:
	Vector3D Normalize()
	{
		double x = Unit().X;
		double y = Unit().Y;
		double z = Unit().Z;

		X = x;
		Y = y;
		Z = z;

		return Vector3D(X, Y, Z);
	}

public:
	double Dot(Vector3D other)
	{
		return (X * other.X) + (Y * other.Y) + (Z * other.Z);
	}

public:
	Vector3D Cross(Vector3D other)
	{
		double x = (Y * other.Z) - (Z * other.Y);
		double y = (Z * other.X) - (X * other.Z);
		double z = (X * other.Y) - (Y * other.X);
		return Vector3D(x,y,z);
	}

public:
	Vector3D operator + (Vector3D other)
	{
		return Vector3D(
		    X + other.X,
			Y + other.Y,
			Z + other.Z);
	}

public:
	Vector3D operator - (Vector3D other)
	{
		return Vector3D(
			X - other.X,
			Y - other.Y,
			Z - other.Z
		);
	}

public:
	Vector3D operator * (double factor)
	{
		return Vector3D(
			X * factor,
			Y * factor,
			Z * factor
		);
	}

	public:
		Vector3D operator / (double factor)
		{
			if (factor == 0)
			{
				return Vector3D();   // return (0,0,0)
			}
			return Vector3D(
				X / factor,
				Y / factor,
				Z / factor
			);
		}


};
