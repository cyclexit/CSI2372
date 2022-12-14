#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Vertebrate
{
protected:
	bool cold_blooded;
	string name;
	vector <string> features;
public:
	Vertebrate();
	Vertebrate(string, bool);
	void blood_type();
	void add_feature(string);
	virtual void sound() = 0;
};
