#pragma once

#include <vector>
#include "Triangle.h"
#include "BoundingBox.h"

class Mesh
{
public:

	std::vector<Triangle> triangles;

public:
	double Area()
	{
		double area = 0;

		for (int i = 0; i < triangles.size(); i++)
		{
			area += triangles[i].Area();
		}

		return area;
	}

public:
	BoundingBox GetBoundingBox()
	{
		Point3D min = triangles[0].A;
		Point3D max = triangles[0].A;

		if (triangles.empty())
		{
			return BoundingBox();
		}

		for (int i = 0; i < triangles.size(); i++)
		{
			// Minimum point
			// Point A
			if (triangles[i].A.X < min.X)
			{
				min.X = triangles[i].A.X;
			}

			if (triangles[i].A.Y < min.Y)
			{
				min.Y = triangles[i].A.Y;
			}

			if (triangles[i].A.Z < min.Z)
			{
				min.Z = triangles[i].A.Z;
			}

			// Point B
			if (triangles[i].B.X < min.X)
			{
				min.X = triangles[i].B.X;
			}

			if (triangles[i].B.Y < min.Y)
			{
				min.Y = triangles[i].B.Y;
			}

			if (triangles[i].B.Z < min.Z)
			{
				min.Z = triangles[i].B.Z;
			}

			// Point C
			if (triangles[i].C.X < min.X)
			{
				min.X = triangles[i].C.X;
			}

			if (triangles[i].C.Y < min.Y)
			{
				min.Y = triangles[i].C.Y;
			}

			if (triangles[i].C.Z < min.Z)
			{
				min.Z = triangles[i].C.Z;
			}

			// Maximum point
			// Point A
			if (triangles[i].A.X >= max.X)
			{
				max.X = triangles[i].A.X;
			}

			if (triangles[i].A.Y >= max.Y)
			{
				max.Y = triangles[i].A.Y;
			}

			if (triangles[i].A.Z >= max.Z)
			{
				max.Z = triangles[i].A.Z;
			}

			// Point B
			if (triangles[i].B.X >= max.X)
			{
				max.X = triangles[i].B.X;
			}

			if (triangles[i].B.Y >= max.Y)
			{
				max.Y = triangles[i].B.Y;
			}

			if (triangles[i].B.Z >= max.Z)
			{
				max.Z = triangles[i].B.Z;
			}

			// Point C
			if (triangles[i].C.X >= max.X)
			{
				max.X = triangles[i].C.X;
			}

			if (triangles[i].C.Y >= max.Y)
			{
				max.Y = triangles[i].C.Y;
			}

			if (triangles[i].C.Z >= max.Z)
			{
				max.Z = triangles[i].C.Z;
			}
		}
		return BoundingBox(min, max);
	}
};