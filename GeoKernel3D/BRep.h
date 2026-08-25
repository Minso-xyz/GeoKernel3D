#pragma once
#include <vector>
#include "Vertex.h"
#include "Edge.h"
#include "Face.h"

class BRep
{
public:
	std::vector<Vertex> Vertices;
	std::vector<Edge> Edges;
	std::vector<Face> Faces;

public:
	BRep(std::vector<Vertex> vertices, std::vector<Edge> edges, std::vector<Face> faces)
	{
		Vertices = vertices;
		Edges = edges;
		Faces = faces;
	}

public:
	int VertexCount()
	{
		return Vertices.size();
	}

public:
	int EdgeCount()
	{
		return Edges.size();
	}

public:
	int FaceCount()
	{
		return Faces.size();
	}
};