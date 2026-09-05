#pragma once
#include "Point3D.h"
#include "Vector3D.h"
#include "Axis2Placement3D.h"
#include <vector>
#include <math.h>

class Circle3D
{
public:
	Axis2Placement3D Position;
	double Radius;

public:
	Circle3D()
	{
		Position = Axis2Placement3D();
		Radius = 1.0;
	}

public:
	Circle3D(Axis2Placement3D position, double radius)
	{
		Position = position;
		Radius = radius;
	}

public:
	Point3D Evaluate(double& angle) const   // returns the point of the circle at the given angle
	{
		Point3D center = Position.Origin;
		Vector3D xAxis = Position.RefDirection;
		Vector3D zAxis = Position.GetZAxis();
		Vector3D yAxis = Position.GetYAxis();
		const double& t = angle;

		return Point3D(
			center.X
			+ Radius * cos(t) * xAxis.X
			+ Radius * sin(t) * yAxis.X,

			center.Y
			+ Radius * cos(t) * xAxis.Y
			+ Radius * sin(t) * yAxis.Y,

			center.Z
			+ Radius * cos(t) * xAxis.Z
			+ Radius * sin(t) * yAxis.Z
		);
	}

public:
	std::vector<Point3D> CreatePolyline(int& segmentCount) const  // Divide the circle by "segmentCount"
	{
		std::vector<Point3D> points;

		for (int i = 0; i <= segmentCount; i++)
		{
			double pi = 3.14159265359;
			double t = 2 * pi * i / segmentCount;

			points.push_back(Evaluate(t));
		}
		return points;
	}
public:
	Vector3D GetYDirection()
	{
		Vector3D xAxis = Position.GetXAxis();
		Vector3D zAxis = Position.GetZAxis();
		return zAxis.Cross(xAxis);
	}

public:
	double Length() const
	{
		double pi = 3.14159265359;
		return 2 * pi * Radius;
	}
};
