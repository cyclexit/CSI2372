#include <iostream>
#include "Mammal.h"

using namespace std;

Mammal::Mammal()
{
	cold_blooded = false;
	name = "Unknown";
	category = "Unknown";
}

Mammal::Mammal(string n, string c)
{
	cold_blooded = false;
	name = n;
	category = c;
}

void Mammal::sound()
{
	cout << "Some sound!" << endl;
}
