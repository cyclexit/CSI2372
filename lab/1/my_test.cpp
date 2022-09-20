#include <iostream>

#include "set.hpp"

int main() {
  Set a, b;
  
  a.add_element(1);
  a.add_element(4);
  a.add_element(5);
  a.add_element(6);
  a.print();

  b.add_element(1);
  b.add_element(2);
  b.add_element(4);
  b.add_element(10);
  b.print();

  a.set_union(b).print();
  a.mutal_difference(b).print();

  return 0;
}
