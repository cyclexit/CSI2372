#include <iostream>

#include "Array.h"

using namespace std;

int main() {
  Array<double> arr;
  arr.add_item(2.5);
  cout << arr << endl;
  arr.remove_item();
  cout << arr << endl;
  return 0;
}