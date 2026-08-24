#pragma once
#include "Point3D.h"
#include "Vector3D.h"
#include "MathUtil.h"
#include "Line3D.h"


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

public:
	bool Contains(Point3D point)
	{
		return std::abs(DistanceTo(point)) < MathUtil::Epsillon;
	}

public:
	struct PlaneEquation
	{
		double A;
		double B;
		double C;
		double D;
	};

public:
	PlaneEquation Equation()
	{
		PlaneEquation eq;

		eq.A = Normal.X;
		eq.B = Normal.Y;
		eq.C = Normal.Z;
		eq.D = D();

		return eq;
	}

public:
	double D()
	{
		return -(Normal.X * Origin.X + Normal.Y * Origin.Y + Normal.Z * Origin.Z);
	}

public:
	Point3D Intersection(Line3D line)
	{
		double startDistance = DistanceTo(line.Start);   // Calculate how far the start point of the line is from the plane
		double normalMovement = line.Direction().Dot(Normal);   // calculate how far the point on the line moves along the plane's normal direction

		// Calculate what percentage of that movement is needed to reach the plane, and use it as "t"  
		// A Point3D of the Line3D : P(t) = Start + Direction * t
		double t = -startDistance / normalMovement;
		
		return line.Evaluate(t);   // Find the intersection point
	}

public:
	bool TryIntersection(Line3D line, Point3D& intersection)
	{
		double startDistance = DistanceTo(line.Start);   // Calculate how far the start point of the line is from the plane
		double normalMovement = line.Direction().Dot(Normal);   // calculate how far the point on the line moves along the plane's normal direction

		if (MathUtil::IsZero(normalMovement))   // the line and the plane are in parallel (dot product = 0)
		{
			return false;
		}

		// Calculate what percentage of that movement is needed to reach the plane, and use it as "t"  
		// A Point3D of the Line3D : P(t) = Start + Direction * t
		double t = -startDistance / normalMovement;

		intersection =  line.Evaluate(t);   // Find the intersection point

		return true;
	}
};
