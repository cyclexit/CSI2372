#include <iostream>

#include "Forest.h"

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
  /*
   * Simple test
   */
  Forest f1;

  // operator ++
  ++f1;

  // add 1->2
  f1.add_edge(1, 2);
  if (f1.edge_exist(1, 2)) {
    cout << "Test - edge_exist12 ... Passed" << endl;
  } else {
    cout << "Test - edge_exist ... Failed" << endl;
  }
  if (f1.edge_exist(2, 1)) {
    cout << "Test - edge_exist21 ... Passed" << endl;
  } else {
    cout << "Test - edge_exist21 ... Failed" << endl;
  }

  if (f1.path_exist(1, 2)) {
    cout << "Test - path_exist12 ... Passed" << endl;
  } else {
    cout << "Test - path_exist12 ... Failed" << endl;
  }
  if (f1.path_exist(2, 1)) {
    cout << "Test - path_exist21 ... Passed" << endl;
  } else {
    cout << "Test - path_exist21 ... Failed" << endl;
  }

  if (f1.get_degree(1) == 1 && f1.get_degree(2) == 1) {
    cout << "Test - get_degree ... Passed" << endl;
  } else {
    cout << "Test - get_degree ... Failed" << endl;
  }

  // add 2->1
  f1.add_edge(2, 1);

  cout << f1 << endl;
  f1--;
  cout << f1 << endl;

  Graph f2(4);
  f2.add_edge(1, 2);
  f2.add_edge(1, 3);
  f2.add_edge(4, 2);
  f2.add_edge(4, 3);

  cout << "\nf2 looks like:" << endl;
  cout << f2 << endl;
  cout << "f2.DFS(1): " << f2.DFS(1) << endl;
  cout << "f2.BFS(4): " << f2.BFS(4) << endl;

  Graph f3(7); // binary tree
  f3.add_edge(1, 2);
  f3.add_edge(1, 3);
  f3.add_edge(2, 4);
  f3.add_edge(2, 5);
  f3.add_edge(3, 6);
  f3.add_edge(3, 7);

  cout << "\nf3 looks like:" << endl;
  cout << f3 << endl;
  cout << "f3.DFS(1): " << f3.DFS(1) << endl;
  cout << "f3.BFS(1): " << f3.BFS(1) << endl;

  auto res = f3.DFS(2);
  cout << "f3.DFS(2): " << res << endl;

  return 0;
}
