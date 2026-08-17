#pragma once
#include "Point3D.h"
#include "Vector3D.h"

class Line3D
{
public:
	Point3D Start;
	Point3D End;

public:
	Line3D(Point3D p1, Point3D p2)
	{
		Start = p1;
		End = p2;
	}

public:
	double Length()
	{
		return Start.DistanceTo(End);
	}

public:
	Point3D MidPoint()
	{
		double x = (Start.X + End.X) * 0.5;
		double y = (Start.Y + End.Y) * 0.5;
		double z = (Start.Z + End.Z) * 0.5;
		
		return Point3D(x, y, z);
	}

public:
	Line3D Reverse()
	{
		return Line3D(End, Start);
	}

public:
	Vector3D Direction()
	{
		double x = (End.X - Start.X);
		double y = (End.Y - Start.Y);
		double z = (End.Z - Start.Z);

		return Vector3D(x, y, z);
	}

public:
	Point3D ProjectionPoint(Point3D point)
	{
		Vector3D ab = Start.VectorTo(End);
		Vector3D unit_ab = ab.Unit();
		Vector3D ap = Start.VectorTo(point);

		double projectionLength = ap.Dot(unit_ab);

		return Start + (unit_ab * projectionLength);
		//return Start.Translate(unit_ab * projectionLength);  // start + (vector) unit_ab * projection length
	}
};