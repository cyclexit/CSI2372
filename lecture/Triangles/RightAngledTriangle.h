#pragma once

#include <iostream>
#include "Triangle.h"

using namespace std;

//Inheritance access level
//Child class members

// Inheritance access level on the rows
// Parent class members access levels on the columns
// Cells represent the child members access levels
				//public		//protected		//private
//public		public			protected		XXXXXX
//protected		protected		protected		XXXXXX
//private		private			private 		XXXXXX

class RightAngledTriangle : public Triangle
{
	//protected:
	//double side1, side2, side3;
public:
	RightAngledTriangle();
	RightAngledTriangle(double, double);
	double getSmallestSide();
	double area();
	Triangle operator () ();
};
