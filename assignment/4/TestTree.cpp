// Hongyi Lin 300053082
// Stacy Guo 300157080

#include <bits/stdc++.h>

#include "Tree.h"

using namespace std;

template<typename T>
ostream& operator<<(ostream& out, const vector<T> vec) {
  for (int i = 0; i < vec.size(); ++i) {
    if (i > 0) out << ", ";
    out << vec[i];
  }
  return out;
}

int main() {
  // operator ++
  cout << "Test operator++" << endl;
  Tree t1;
  ++t1;
  ++t1;
  cout << t1 << endl;

  t1.set_root(2);
  cout << t1 << endl;

  // NOTE: should see an error message
  assert(t1.add_edge(1, 3) == false);

  for (int i = 0; i < 5; ++i) {
    t1++;
  }
  cout << t1 << endl;

  // remove_edge and add_edge
  cout << "Test remove_edge and add_edge" << endl;
  t1.set_root(1);
  cout << t1 << endl;

  t1.remove_edge(4, 5);
  t1.add_edge(1, 5);
  cout << t1 << endl;

  t1.remove_edge(7, 8);
  t1.add_edge(8, 1);
  cout << t1 << endl;

  t1.remove_edge(3, 4);
  t1.add_edge(2, 4);
  cout << t1 << endl;

  // operator --
  cout << "Test operator--" << endl;
  cout << t1-- << endl;
  cout << t1 << endl;
  cout << static_cast<Graph>(t1) << endl;
  // NOTE: should see an error message
  assert(t1.path_exist(8, 1) == false);
  // NOTE: should see an error message
  assert(t1.edge_exist(8, 1) == false);

  return 0;
}
