#pragma once
#include "Point3D.h"
#include <vector>

class NURBSCurve
{
public:
	std::vector<Point3D> ControlPoints;
	std::vector<double> Knots;
	std::vector<double> Weights;
	int Degree;

public:
	NURBSCurve(
		const std::vector<Point3D>& controlPoints,
		const std::vector<double>& knots,
		const std::vector<double>& weights,
		int degree
	)
	{
		ControlPoints = controlPoints;
		Knots = knots;
		Weights = weights;
		Degree = degree;

	}

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
		Point3D numerator(0,0,0);
		double denominator = 0.0;

		for (int i = 0; i < ControlPoints.size(); i++)
		{
			double basis =BasisFunction(i, Degree, t);
			double weight = Weights[i];

			numerator = numerator + ControlPoints[i] * basis * weight;
			denominator =denominator + basis * weight;
		}
		return (numerator / denominator);
	}
};