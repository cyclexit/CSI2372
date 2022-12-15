#pragma once

#include <iostream>

using namespace std;

class Triangle
{
//private:
	//only members of the class
protected:
	//members of the class and children
	double side1, side2, side3;
public:
	//members of the class and children and any object of the class
	Triangle();
	Triangle(double, double, double);
	double premieter();
	double getSide1();
	double getSide2();
	double getSide3();
	virtual double area();
	//virtual double area() = 0; area is a pure virtual function
	//pure virtual function must not have any implementation in the parent class
	//In other words, we postpone the implementation to the children
	//Class Shape, method draw
	//Class Animal, method sound
	//If we have just a pure virtual method in a class, then we call that class, an abstract class
	//Shape
	//Triangle, Rectangle, Circle, Oval
	//Vector <Shape*> vs;
};