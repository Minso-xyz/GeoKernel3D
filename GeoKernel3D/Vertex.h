#pragma once
#include "Point3D.h"

class Vertex
{
public:
	Point3D Position;
	Vector3D Normal;

public:
	Vertex() 
	{
		Position = Point3D();
	}

public:
	Vertex(Point3D position)
	{
		Position = position;
	}
};
