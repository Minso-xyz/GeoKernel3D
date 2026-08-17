#pragma once
#define _USE_MATH_DEFINES
#include "Point3D.h"
#include <cmath>

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
	static Matrix4x4 Identity()
	{
		return Matrix4x4(
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		);
	}

public:
	static Matrix4x4 CreateTranslation(double dx, double dy, double dz)
	{
		return Matrix4x4(
			1, 0, 0, dx,  // X + dx
			0, 1, 0, dy,  // Y + dy
			0, 0, 1, dz,  // Z + dz
			0, 0, 0, 1
		);
	}

public:
	static Matrix4x4 CreateScale(double scaleX, double scaleY, double scaleZ)
	{
		return Matrix4x4(
			scaleX, 0, 0, 0,
			0, scaleY, 0, 0,
			0, 0, scaleZ, 0,
			0, 0, 0, 1
		);
	}

public:
	static Matrix4x4 CreateScale(double factor)
	{
		return CreateScale(factor, factor, factor);
	}

public:
	static Matrix4x4 CreateMirrorYZ()   // X => -X
	{
		return Matrix4x4(
			-1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		);
	}

public:
	static Matrix4x4 CreateMirrorXZ()   // Y => -Y
	{
		return Matrix4x4(
			1, 0, 0, 0,
			0, -1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		);
	}

public:
	static Matrix4x4 CreateMirrorXY()   // Z => -Z
	{
		return Matrix4x4(
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, -1, 0,
			0, 0, 0, 1
		);
	}

public:
	static double ConvertToRadian(double angleDegree)
	{
		return angleDegree * M_PI / 180.0;
	}

public:
	static Matrix4x4 CreateRotationX(double angleDegree)
	{
		double radians = ConvertToRadian(angleDegree);
		double cos = std::cos(radians);
		double sin = std::sin(radians);

		return Matrix4x4(
			1, 0, 0, 0,
			0, cos, -sin, 0,
			0, sin, cos, 0,
			0, 0, 0, 1
		);
	}

public:
	static Matrix4x4 CreateRotationY(double angleDegree)
	{
		double radians = ConvertToRadian(angleDegree);
		double cos = std::cos(radians);
		double sin = std::sin(radians);

		return Matrix4x4(
			cos, 0, sin, 0,
			0, 1, 0, 0,
			-sin, 0, cos, 0,
			0, 0, 0, 1
		);
	}

public:
	static Matrix4x4 CreateRotationZ(double angleDegree)
	{
		double radians = ConvertToRadian(angleDegree);
		double cos = std::cos(radians);
		double sin = std::sin(radians);

		return Matrix4x4(
			cos, -sin, 0, 0,
			sin, cos, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		);
	}

public:
	Point3D Transform(Point3D point)
	{
		double x = M11 * point.X + M12 * point.Y + M13 * point.Z + M14;
		double y = M21 * point.X + M22 * point.Y + M23 * point.Z + M24;
		double z = M31 * point.X + M32 * point.Y + M33 * point.Z + M34;
		double w = M41 * point.X + M42 * point.Y + M43 * point.Z + M44;  // Homogenous coordinates

		if (w == 0)
		{
			return Point3D();
		}

		return Point3D(x / w, y / w, z / w);   // w = 1 (homogenous coordinates)
	}

public:
	Matrix4x4 operator * (Matrix4x4 a)
	{
		double m11 = M11 * a.M11 + M12 * a.M21 + M13 * a.M31 + M14 * a.M41;
		double m12 = M11 * a.M12 + M12 * a.M22 + M13 * a.M32 + M14 * a.M42;
		double m13 = M11 * a.M13 + M12 * a.M23 + M13 * a.M33 + M14 * a.M43;
		double m14 = M11 * a.M14 + M12 * a.M24 + M13 * a.M34 + M14 * a.M44;

		double m21 = M21 * a.M11 + M22 * a.M21 + M23 * a.M31 + M24 * a.M41;
		double m22 = M21 * a.M12 + M22 * a.M22 + M23 * a.M32 + M24 * a.M42;
		double m23 = M21 * a.M13 + M22 * a.M23 + M23 * a.M33 + M24 * a.M43;
		double m24 = M21 * a.M14 + M22 * a.M24 + M23 * a.M34 + M24 * a.M44;

		double m31 = M31 * a.M11 + M32 * a.M21 + M33 * a.M31 + M34 * a.M41;
		double m32 = M31 * a.M12 + M32 * a.M22 + M33 * a.M32 + M34 * a.M42;
		double m33 = M31 * a.M13 + M32 * a.M23 + M33 * a.M33 + M34 * a.M43;
		double m34 = M31 * a.M14 + M32 * a.M24 + M33 * a.M34 + M34 * a.M44;

		double m41 = M41 * a.M11 + M42 * a.M21 + M43 * a.M31 + M44 * a.M41;
		double m42 = M41 * a.M12 + M42 * a.M22 + M43 * a.M32 + M44 * a.M42;
		double m43 = M41 * a.M13 + M42 * a.M23 + M43 * a.M33 + M44 * a.M43;
		double m44 = M41 * a.M14 + M42 * a.M24 + M43 * a.M34 + M44 * a.M44;

		return Matrix4x4(
			m11, m12, m13, m14,
			m21, m22, m23, m24,
			m31, m32, m33, m34,
			m41, m42, m43, m44
		);
	}
};