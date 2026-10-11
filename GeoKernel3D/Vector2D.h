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
	Vector2D()
	{
		X = 0;
		Y = 0;
	}

public:
	double Dot(const Vector2D& other) const
	{
		return (X * other.X) + (Y * other.Y);
	}

public:
	double Cross(const Vector2D& other) const
	{
		return (X * other.Y) - (Y * other.X);
	}

public:
	double Length()
	{
		return sqrt(X * X + Y * Y);
	}

public:
	Vector2D Unit()
	{
		double length = Length();

		if (length == 0)
		{
			return Vector2D();
		}

		double x = X / length;
		double y = Y / length;

		return Vector2D(x, y);
	}

public:
	Vector2D Normalize()
	{
		double x = Unit().X;
		double y = Unit().Y;

		X = x;
		Y = y;

		return Vector2D(X, Y);
	}

public:
	Vector2D operator * (double& factor) const
	{
		return Vector2D(X * factor, Y * factor);
	}
};
