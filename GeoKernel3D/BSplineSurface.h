#pragma once
#include <vector>
#include "Point3D.h"

class BSplineSurface
{
public:
	int DegreeU;
	int DegreeV;

	std::vector<double> KnotsU;
	std::vector<double> KnotsV;

	std::vector<std::vector<Point3D>> ControlPoints;

public:
	Point3D Evaluate(double u, double v) const;
};