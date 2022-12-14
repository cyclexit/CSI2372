#pragma once
#include <iostream>
#include "Vertebrate.h"

// Regular functions
// We have to implement these functions in the parrent and
// We are allowed to override or use the parent version of 
// these functions in the children of the class

// Virtual functions
// We have to implement these functions in the parrent and 
// override these functions in the children of the class

// Pure Virtual functions
// We must not implement these functions in the parrent and 
// we are allowed to override these functions in the children
// of the class, note that if we don't implement them the
// child class is also an abstract class

class Mammal: public Vertebrate
{
private:
	string category;
public:
	Mammal();
	Mammal(string, string);
	virtual void sound();
};