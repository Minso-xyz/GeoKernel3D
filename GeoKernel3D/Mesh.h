#pragma once

#include <vector>
#include "Triangle.h"
#include "BoundingBox.h"
#include "Face.h"

class Mesh
{
public:

	std::vector<Vertex> Vertices;
	std::vector<Face> Faces;
	std::vector<Triangle> Triangles;

public:
	double Area()
	{
		double area = 0;

		for (int i = 0; i < Triangles.size(); i++)
		{
			area += Triangles[i].Area();
		}

		return area;
	}

public:
	BoundingBox GetBoundingBox()
	{
		Point3D min = Triangles[0].A;
		Point3D max = Triangles[0].A;

		if (Triangles.empty())
		{
			return BoundingBox();
		}

		for (int i = 0; i < Triangles.size(); i++)
		{
			// Minimum point
			// Point A
			if (Triangles[i].A.X < min.X)
			{
				min.X = Triangles[i].A.X;
			}

			if (Triangles[i].A.Y < min.Y)
			{
				min.Y = Triangles[i].A.Y;
			}

			if (Triangles[i].A.Z < min.Z)
			{
				min.Z = Triangles[i].A.Z;
			}

			// Point B
			if (Triangles[i].B.X < min.X)
			{
				min.X = Triangles[i].B.X;
			}

			if (Triangles[i].B.Y < min.Y)
			{
				min.Y = Triangles[i].B.Y;
			}

			if (Triangles[i].B.Z < min.Z)
			{
				min.Z = Triangles[i].B.Z;
			}

			// Point C
			if (Triangles[i].C.X < min.X)
			{
				min.X = Triangles[i].C.X;
			}

			if (Triangles[i].C.Y < min.Y)
			{
				min.Y = Triangles[i].C.Y;
			}

			if (Triangles[i].C.Z < min.Z)
			{
				min.Z = Triangles[i].C.Z;
			}

			// Maximum point
			// Point A
			if (Triangles[i].A.X >= max.X)
			{
				max.X = Triangles[i].A.X;
			}

			if (Triangles[i].A.Y >= max.Y)
			{
				max.Y = Triangles[i].A.Y;
			}

			if (Triangles[i].A.Z >= max.Z)
			{
				max.Z = Triangles[i].A.Z;
			}

			// Point B
			if (Triangles[i].B.X >= max.X)
			{
				max.X = Triangles[i].B.X;
			}

			if (Triangles[i].B.Y >= max.Y)
			{
				max.Y = Triangles[i].B.Y;
			}

			if (Triangles[i].B.Z >= max.Z)
			{
				max.Z = Triangles[i].B.Z;
			}

			// Point C
			if (Triangles[i].C.X >= max.X)
			{
				max.X = Triangles[i].C.X;
			}

			if (Triangles[i].C.Y >= max.Y)
			{
				max.Y = Triangles[i].C.Y;
			}

			if (Triangles[i].C.Z >= max.Z)
			{
				max.Z = Triangles[i].C.Z;
			}
		}
		return BoundingBox(min, max);
	}
};