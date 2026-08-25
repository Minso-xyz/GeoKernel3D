#pragma once
#include "Vertex.h"

class Edge
{
public:
	Vertex Start;
	Vertex End;

public:
	Edge(Vertex start, Vertex end)
	{
		Start = start;
		End = end;
	}
};