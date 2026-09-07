#include "BoundingBox.h"
#include <vector>
#include "Edge.h"

Point3D BoundingBox::GetCenter() const
{
	double x = (Min.X + Max.X) * 0.5;
	double y = (Min.Y + Max.Y) * 0.5;
	double z = (Min.Z + Max.Z) * 0.5;

	return Point3D(x, y, z);
}

double BoundingBox::Width()
{
	return Max.X - Min.X;
}

double BoundingBox::Height()
{
	return Max.Y - Min.Y;
}

double BoundingBox::Depth()
{
	return Max.Z - Min.Z;
}

bool BoundingBox::Contains(Point3D point)
{
	bool x = false;
	bool y = false;
	bool z = false;

	if (point.X >= Min.X && point.X <= Max.X) x = true;
	if (point.Y >= Min.Y && point.Y <= Max.Y) y = true;
	if (point.Z >= Min.Z && point.Z <= Max.Z) z = true;

	return x && y && z;
}

bool BoundingBox::Intersects(BoundingBox other)
{
	bool x = false;
	bool y = false;
	bool z = false;

	if (Max.X >= other.Min.X && other.Max.X >= Min.X) x = true;
	if (Max.Y >= other.Min.Y && other.Max.Y >= Min.Y) y = true;
	if (Max.Z >= other.Min.Z && other.Max.Z >= Min.Z) z = true;

	return x && y && z;
}

BoundingBox BoundingBox::CalculateBoundingBox(const std::vector<Point3D>& points)
{
	double minX = points[0].X;
	double minY = points[0].Y;
	double minZ = points[0].Z;

	double maxX = points[0].X;
	double maxY = points[0].Y;
	double maxZ = points[0].Z;

	for (const Point3D& point : points)
	{
		minX = std::min(minX, point.X);
		minY = std::min(minY, point.Y);
		minZ = std::min(minZ, point.Z);

		maxX = std::max(maxX, point.X);
		maxY = std::max(maxY, point.Y);
		maxZ = std::max(maxZ, point.Z);
	}

	Point3D min = Point3D(minX, minY, minZ);
	Point3D max = Point3D(maxX, maxY, maxZ);

	return BoundingBox(min, max);
}

double BoundingBox::GetModelRadius() const
{
	double dx = Max.X - Min.X;
	double dy = Max.Y - Min.Y;
	double dz = Max.Z - Min.Z;

	double diagonal = sqrt(dx * dx + dy * dy + dz * dz);

	return diagonal * 0.5;
}

BoundingBox BoundingBox::CreateFromEdgePoints(const std::vector<Edge>& edges)
{
	// Get the points from the edges
	std::vector<Point3D> modelPoints;
	for (const Edge& edge : edges)
	{
		modelPoints.push_back(edge.Start.Position);
		modelPoints.push_back(edge.End.Position);
	}
	return CalculateBoundingBox(modelPoints);
}

