#pragma once
#include "Vertex.h"

class Edge
{
public:
	Vertex Start;
	Vertex End;

public:
	Edge()
	{
		Start = Vertex(Point3D(0, 0, 0));
		End = Vertex(Point3D(0, 0, 0));
	}

public:
	Edge(Vertex start, Vertex end)
	{
		Start = start;
		End = end;
	}
};