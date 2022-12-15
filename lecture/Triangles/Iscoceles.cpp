#include <iostream>
#include "Isosceles.h"
#include "Triangle.h"

Isosceles::Isosceles()
{
	side1 = side2 = 5.0;
	side3 = 7.0;
}

Isosceles::Isosceles(double s1, double s2, double s3)
{
	if (s1 == s2 || s1 == s3 || s2 == s3)
	{
		Triangle t = Triangle(s1, s2, s3);
		side1 = t.getSide1();
		side2 = t.getSide2();
		side3 = t.getSide3();
	}
	else
	{
		side1 = side2 = 5.0;
		side3 = 7.0;
	}
}

double Isosceles::getSmallestSide()
{
	return side1;
}

/*double Isosceles::area()
{
	cout << "This is the area of Isosceles." << endl;
	return Triangle::area();
}*/
