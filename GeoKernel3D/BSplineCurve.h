#pragma once
#include<vector>
#include"Point3D.h"

class BSplineCurve
{
public:
	std::vector<Point3D> ControlPoints;

	std::vector<double> Knots;

	int Degree;

	BSplineCurve(std::vector<Point3D> controlPoints, std::vector<double> knots, int degree)
	{
		ControlPoints = controlPoints;
		Knots = knots;
		Degree = degree;
	}

	BSplineCurve()
	{
		std::vector<Point3D> points;
		points.push_back(Point3D(0, 0, 0));
		points.push_back(Point3D(1, 1, 1));

		std::vector<double> knots;
		knots.push_back(0);
		knots.push_back(1);

		ControlPoints = points;
		Knots = knots;
		Degree = 1;
	}

public:
	double BasisFunction(int i, int degree, double t) const;
	Point3D Evaluate(double t) const;
	std::vector<Point3D> CreatePolyline(int segmentCount) const;


public:
	bool IsValid()
	{
		return Knots.size() == ControlPoints.size() + Degree + 1;
	}

public:
	int ControlPointCount()
	{
		return ControlPoints.size();
	}

public:
	int KnotCount()
	{
		return Knots.size();
	}

public:
	double StartParameter()
	{
		return Knots[Degree];
	}

public:
	double EndParameter()
	{
		return Knots[
			Knots.size()
				- Degree
				- 1];
	}

};


	
