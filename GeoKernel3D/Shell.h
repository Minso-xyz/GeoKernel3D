#pragma once
#include "Face.h"
#include <vector>

class Shell
{
public:
	std::vector<Face> Faces;

public:
	Shell(std::vector<Face> faces)
	{
		Faces = faces;
	}
};