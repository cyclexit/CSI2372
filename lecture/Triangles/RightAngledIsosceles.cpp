#include <iostream>
#include <cmath>
#include "RightAngeledIsosceles.h"
#include "Triangle.h"
#include "Isosceles.h"
#include "RightAngledTriangle.h"

using namespace std;

RightAngledIsosceles::RightAngledIsosceles() : Isosceles(1.0, 1.0, sqrt(1.0)) , RightAngledTriangle(1.0, 1.0)
{
	//Triangle t = Triangle(1.0, 1.0, sqrt(2.0));
	// RightAngledTriangle rt = RightAngledTriangle(1.0, 1.0);
}

RightAngledIsosceles::RightAngledIsosceles(double x) : Isosceles(x, x, sqrt(2.0) * x), RightAngledTriangle(x, x)
{
	//Triangle t = Triangle(x, x, sqrt(2.0) * x);
	// RightAngledTriangle rt = RightAngledTriangle(x, x);
}