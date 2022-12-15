#include <iostream>
#include "Vertebrate.h"
#include "Mammal.h"

using namespace std;

int main()
{
	Vertebrate* v = new Mammal("Cow", "Cat1");
	Mammal m;

	v->blood_type();
	v->sound();
	return 0;
}