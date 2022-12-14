#pragma once

#include <iostream>
#include "Isosceles.h"
#include "RightAngledTriangle.h"

class RightAngledIsosceles: public RightAngledTriangle, public Isosceles 
{
public:
	RightAngledIsosceles();
	RightAngledIsosceles(double);
};