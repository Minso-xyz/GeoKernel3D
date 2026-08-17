#include <iostream>
#include "Point3D.h"
#include "Vector3D.h"
#include "Line3D.h"

int main()
{
	// Vector3D Length
	Vector3D v(3, 4, 0);
	double lengthVector = v.Length();
	std::cout << lengthVector << std::endl;   // 5

	// Vector3D Unit
	Vector3D unit = v.Unit();
	std::cout << "(" << unit.X << ", " << unit.Y << ", " << unit.Z << ")" << std::endl;   // (0.6, 0.8, 0.0)

	// Vector3D Normalize
	Vector3D normalized = v.Normalize();
	std::cout << "(" << normalized.X << ", " << normalized.Y << ", " << normalized.Z << ")" << std::endl;  // Overwrite (0.6, 0.8, 0.0)

	// Vector3D Dot product
	Vector3D a(1, 0, 0);
	Vector3D b(0, 1, 0);
	double dot = a.Dot(b);
	std::cout << "Dot product = " << dot << std::endl;   // 0

	// Vector3D Cross product
	Vector3D c(2, 3, 4);
	Vector3D d(5, 6, 7);
	Vector3D cross = c.Cross(d);
	std::cout << "Cross product = (" << cross.X << ", " << cross.Y << ", " << cross.Z << ")" << std::endl;   // (-3, 6, -3)

	// Point3D VectorTo
	Point3D p1(0,0,0);
	Point3D p2(10, 0, 0);
	Vector3D vectorTo = p1.VectorTo(p2);
	std::cout << "VectorTo = (" << vectorTo.X << ", " << vectorTo.Y << ", " << vectorTo.Z << ")" << std::endl;

	// Point3D DistanceTo
	double distance = p1.DistanceTo(p2);
	std::cout << "Distance = " << distance << std::endl;   // 10

	// Line3D Length
	Point3D p3(0, 0, 0);
	Point3D p4(3, 4, 0);
	Line3D line(p3, p4);
	double lengthLine = line.Length();
	std::cout << "Length = " << lengthLine << std::endl;   // 10


	return 0;
}