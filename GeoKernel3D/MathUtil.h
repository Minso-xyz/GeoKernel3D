#pragma once
#include <cmath>

class MathUtil
{
public:
	static constexpr double Epsillon = 1e-10;   // To avoid Floating-Point errors

	static bool IsZero(double value)
	{
		return std::abs(value) < Epsillon;
	}

	static bool AreEqual(double value1, double value2)
	{
		return std::abs(value2 - value1) < Epsillon ? true : false;
	}

	static double SnapToZero(double value)
	{
		return std::abs(value) < Epsillon ? 0.0 : value;
	}

};
