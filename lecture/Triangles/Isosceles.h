#pragma once

#include <iostream>
#include "Triangle.h"

using namespace std;

class Isosceles : public Triangle
{
	//protected:
	//double side1, side2, side3;
public:
	Isosceles();
	Isosceles(double, double, double);
	//double area();
	double getSmallestSide();
};