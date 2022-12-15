#include <iostream>
#include "Vertebrate.h"

Vertebrate::Vertebrate()
{
	cold_blooded = true;
	name = "Unknown";
	features = vector <string>();
}

Vertebrate::Vertebrate(string n, bool cb)
{
	cold_blooded = cb;
	name = n;
	features = vector <string>();
}

void Vertebrate::blood_type()
{
	cout << name << " is " << (cold_blooded ? "Cold-blooded." : "Warm-blooded.") << endl;
}

void Vertebrate::add_feature(string f)
{
	features.push_back(f);
}


