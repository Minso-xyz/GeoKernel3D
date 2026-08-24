#pragma once
#include "Point3D.h"
#include "Vector3D.h"

class Ray
{
public:
	Point3D Origin;
	Vector3D Direction;

	Ray(Point3D origin, Vector3D direction)
	{
		Origin = origin;
		Direction = direction.Unit();
	}

public:
	Point3D Evaluate(double t)
	{
		if (t < 0)
		{
			throw std::invalid_argument("Ray allows only one direction.");
		}

		return Origin + Direction * t;
	}
};