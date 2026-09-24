#pragma once

class Vector2D
{
public:
	double X;
	double Y;

public:
	Vector2D(double x, double y)
	{
		X = x;
		Y = y;
	}

public:
	double Cross(const Vector2D& other) const
	{
		return (X * other.Y) - (Y * other.X);
	}

public:
	Vector2D operator * (double& factor) const
	{
		return Vector2D(X * factor, Y * factor);
	}
};
