#include "BSplineCurve.h"
#include <vector>
#include"Point3D.h"

// Control point influence function
	// N0, N1, N2, N3.... in P(t) = N0(t) * P0 + N1(t) * P1 + N2(t) * P2 + ....
	// (At the current "t" value, determine whether the control point "i" makes any effect)
	// Similar to Bezier curve's Bernstein Polynomial
	// Cox-de Boor Basis Function

double BSplineCurve::BasisFunction(int i, int degree, double t) const
{
	if (degree == 0)
	{
		if ((Knots[i] <= t && t < Knots[i + 1]) || (t == Knots.back() && i == ControlPoints.size() - 1))
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
		left = ((t - Knots[i]) / denom1) * BasisFunction(i, degree - 1, t);
	}

	double denom2 = Knots[i + degree + 1] - Knots[i + 1];

	if (denom2 != 0)
	{
		right = (Knots[i + degree + 1] - t) / denom2 * BasisFunction(i + 1, degree - 1, t);
	}
	return left + right;
}


Point3D BSplineCurve::Evaluate(double t) const
{
	Point3D result(0, 0, 0);

	for (int i = 0; i < ControlPoints.size(); i++)
	{
		double weight = BasisFunction(i, Degree, t);
		result = result + ControlPoints[i] * weight;
	}
	return result;
}

std::vector<Point3D> BSplineCurve::CreatePolyline(int segmentCount) const
{
	std::vector<Point3D> points;

	double start = Knots[Degree];
	double end = Knots[Knots.size() - Degree - 1];

	for (int i = 0; i < segmentCount; i++)
	{
		double t = start + (end - start) * static_cast<double>(i) / static_cast<double>(segmentCount);
		points.push_back(Evaluate(t));
	}
	return points;
}