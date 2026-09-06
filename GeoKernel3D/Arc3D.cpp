#include "Arc3D.h"
#include "Circle3D.h"
#include "Point3D.h"

Point3D Arc3D::Evaluate(double t) const
{
	double angle = StartAngle + t * (EndAngle - StartAngle);

	return Circle.Evaluate(angle);
}

std::vector<Point3D> Arc3D::CreatePolyline(int segmentCount) const
{
	std::vector<Point3D> points;

	if (segmentCount < 2)
	{
		return points;
	}

	for (int i = 0;i <= segmentCount;i++)
	{
		double t = static_cast<double>(i) / static_cast<double>(segmentCount);

		points.push_back(Evaluate(t));
	}
	return points;
}