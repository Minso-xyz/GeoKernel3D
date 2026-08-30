#pragma once
#include "Shell.h"
#include <vector>

class Solid
{
public:
	std::vector<Shell> Shells;

public:
	Solid(std::vector<Shell> shells)
	{
		Shells = shells;
	}
};
