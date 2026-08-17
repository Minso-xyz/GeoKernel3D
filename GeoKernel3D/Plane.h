#pragma once
#include "Point3D.h"
#include "Vector3D.h"


class Plane
{
public:
	Point3D Origin;
	Vector3D Normal;

public:
	double DistanceTo(Point3D point)   // TO DO
	{
		/*double dist = Origin.DistanceTo(point);

		Vector3D OP = point.VectorTo(Origin);
		Vector3D OQ;*/

		return 0;
	}
};
