#include <iostream>
#include <cmath>
#include "RightAngledTriangle.h"

using namespace std;

RightAngledTriangle::RightAngledTriangle()
{
	side1 = 3.0;
	side2 = 4.0;
	side3 = 5.0;
}

RightAngledTriangle::RightAngledTriangle(double s1, double s2)
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

	side3 = sqrt(side1 * side1 + side2 * side2);
}

double RightAngledTriangle::getSmallestSide()
{
	return side1;
}

//overriding the area method in the parent
double RightAngledTriangle::area()
{
	//cout << "Child" << endl;
	// accessing the area function in the parent class
	//double x = Triangle::area();
	cout << "This is the area of RightAngled Triangle." << endl;
	cout << side1 << " " << side2 << endl;
	return side1 * side2 / 2.0;
}

Triangle RightAngledTriangle::operator()()
{
	Triangle t;
	t = (*this);
	return t;
}

