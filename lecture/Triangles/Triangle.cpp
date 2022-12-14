#include <iostream>
#include "Triangle.h"

using namespace std;

Triangle::Triangle()
{
	side1 = side2 = side3 = 1.0;
}

Triangle::Triangle(double s1, double s2, double s3)
{
	double mx = max(max(s1, s2), s3);
	//double mn = min(min(s1, s2), s3);
	side1 = side2 = side3 = 1.0;

	if (s3 == mx)
	{
		if (s1 + s2 <= s3)
		{
			side1 = side2 = side3 = 1.0;
		}
		else
		{
			if (s1 < s2)
			{
				side1 = s1;
				side2 = s2;
			}
			else
			{
				side1 = s2;
				side2 = s1;
			}
			side3 = s3;
		}
	}

	if (s2 == mx)
	{
		if (s1 + s3 <= s2)
		{
			side1 = side2 = side3 = 1.0;
		}
		else
		{
			if (s1 < s3)
			{
				side1 = s1;
				side2 = s3;
			}
			else
			{
				side1 = s3;
				side2 = s1;
			}
			side3 = s2;
		}
	}

	if (s1 == mx)
	{
		if (s2 + s3 <= s1)
		{
			side1 = side2 = side3 = 1.0;
		}
		else
		{
			if (s2 < s3)
			{
				side1 = s2;
				side2 = s3;
			}
			else
			{
				side1 = s3;
				side2 = s2;
			}
			side3 = s1;
		}
	}
}

double Triangle::premieter()
{
	return side1 + side2 + side3;
}

double Triangle::area()
{
	cout << "This is the area of Regular Triangle." << endl;
	double p = premieter() / 2;
	return sqrt(p * (p - side1) * (p - side2) * (p - side3));
}

double Triangle::getSide1()
{
	return side1;
}

double Triangle::getSide2()
{
	return side2;
}

double Triangle::getSide3()
{
	return side3;
}
