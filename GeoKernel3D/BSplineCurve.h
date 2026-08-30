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

	// Control point influence function
	// N0, N1, N2, N3.... in P(t) = N0(t) * P0 + N1(t) * P1 + N2(t) * P2 + ....
	// (At the current "t" value, determine whether the control point "i" makes any effect)
	// Similar to Bezier curve's Bernstein Polynomial
	// Cox-de Boor Basis Function
public:
	double BasisFunction(int i, int degree, double t)   
	{
		if (degree == 0)
		{
			if (Knots[i] <= t && t < Knots[i + 1])  
			{
				return 1.0;
			}
			return 0.0;
		}

		double left = 0;
		double right = 0;

		double denom1 = Knots[i + degree] - Knots[i];

		if (denom1 != 0)
		{
			left = (t - Knots[i] / denom1 * BasisFunction(i, degree - 1, t));
		}

		double denom2 = Knots[i + degree + 1] - Knots[i + 1];

		if (denom2 != 0)
		{
			right = (Knots[i + degree + 1] - t) / denom2 * BasisFunction(i + 1, degree - 1, t);
		}
		return left + right;
	}

public:
	Point3D Evaluate(double t)
	{
		Point3D result(0, 0, 0);

		for (int i = 0; i < ControlPoints.size(); i++)
		{
			double weight = BasisFunction(i, Degree, t);
			result = result + ControlPoints[i] * weight;
		}
		return result;
	}
};


	
