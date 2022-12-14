#include <iostream>
#include <vector>
#include "Triangle.h"
#include "RightAngledTriangle.h"
#include "RightAngeledIsosceles.h"

using namespace std;

int main()
{
  //Polymorphism
  Triangle t(3.0, 5.0, 7.0);
  RightAngledTriangle rt2;
  RightAngledTriangle rt(rt2);
  RightAngledIsosceles rit(2.0);
  Isosceles it(5.0, 5.0, 7.0);
  Triangle t2(rt);
  vector <Triangle*> vt;

  vt.push_back(&t);
  vt.push_back(&rt);
  vt.push_back(&it);

  cout << it.getSide1() << endl;
  cout << it.getSide2() << endl;
  cout << it.getSide3() << endl;

  //t2 = rt;

  cout << t.premieter() << endl;
  cout << t.area() << endl;

  cout << rt.premieter() << endl;
  //int a, b;
  //(double)a / b;
  //cout << ((Triangle)rt).area() << endl;
  cout << (static_cast<Triangle>(rt)).area() << endl;
  //cout << (dynamic_cast<Triangle>(rt)).area() << endl;

  /*t2 = rt;
  cout << t2.area() << endl;*/

  cout << "Polymorphism Checking 1." << endl;
  cout << vt[0]->area() << endl; // vt[0] is a triangle
  cout << vt[1]->area() << endl; // vt[1] is a right angled
  cout << vt[2]->area() << endl; // vt[2] is an isosceles

  cout << "Polymorphism Checking 2." << endl;
  //cout << (static_cast<RightAngledTriangle>(rit)).area() << endl;
  cout << rit.Isosceles::area() << endl;
  cout << rit.RightAngledTriangle::area() << endl;
  return 0;
}