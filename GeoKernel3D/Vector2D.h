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
	double Length() const
	{
		return sqrt(X * X + Y * Y);
	}

public:
	Vector2D Normalize() const
	{
		double length = Length();

		if (length == 0)
		{
			return Vector2D();
		}

		return Vector2D(
			X / length,
			Y / length
		);
	}

public:
	Vector2D Normal() const
	{
		// X' = cosX - sinY = -Y
		// Y' = sinX + cosY = X
		return Vector2D(-Y, X);
	}

public:
	Vector2D operator * (double& factor) const
	{
		return Vector2D(X * factor, Y * factor);
	}
};
