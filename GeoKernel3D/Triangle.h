#pragma once
#include "Point3D.h"
#include "Vector3D.h"
#include <cmath>

class Triangle
{
public:
	Point3D A;
	Point3D B;
	Point3D C;

	Triangle(Point3D a, Point3D b, Point3D c) {
		A = a;
		B = b;
		C = c;
	}

public:
	double Area() 
	{
		Vector3D ab = A.VectorTo(B);
		Vector3D ac = A.VectorTo(C);
		Vector3D cross = ab.Cross(ac);

		return cross.Length() / 2;
	}

public:
	Vector3D Normal()
	{
		Vector3D ab = A.VectorTo(B);
		Vector3D ac = A.VectorTo(C);

		Vector3D crossProduct = ab.Cross(ac);

		return crossProduct.Unit();;  // Normalize
	}
};