#pragma once

class Matrix4x4
{
public:
	double M11; double M12; double M13; double M14;
	double M21; double M22; double M23; double M24;
	double M31; double M32; double M33; double M34;
	double M41; double M42; double M43; double M44;

public:
	Matrix4x4(
		double m11, double m12, double m13, double m14,
		double m21, double m22, double m23, double m24,
		double m31, double m32, double m33, double m34,
		double m41, double m42, double m43, double m44)
	{
		M11 = m11;  M12 = m12; M13 = m13; M14 = m14;
		M21 = m21; M22 = m22; M23 = m23; M24 = m24;
		M31 = m31; M32 = m32; M33 = m33; M34 = m34;
		M41 = m41; M42 = m42; M43 = m43; M44 = m44;
	}

public:
	Matrix4x4 Identity()
	{
		return Matrix4x4(
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		);
	}

public:
	Matrix4x4 CreateTranslation(double dx, double dy, double dz)
	{
		return Matrix4x4(
			1, 0, 0, dx,
			0, 1, 0, dy,
			0, 0, 1, dz,
			0, 0, 0, 1
		);
	}

public:
	Matrix4x4 CreateScale(double scaleX, double scaleY, double scaleZ)
	{
		return Matrix4x4(
			scaleX, 0, 0, 0,
			0, scaleY, 0, 0,
			0, 0, scaleZ, 0,
			0, 0, 0, 1
		);
	}

public:
	Matrix4x4 CreateScale(double factor)
	{
		return CreateScale(factor, factor, factor);
	}

public:
	Matrix4x4 CreateMirror()
	{
		return Matrix4x4(
			-1, 0, 0, 0,
			0, -1, 0, 0,
			0, 0, -1, 0,
			0, 0, 0, 1
		);
	}
};