#include <iostream>

#include "Graph.h"

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
  Graph g1;

  // operator ++
  ++g1;

  // add 1->2
  g1.add_edge(1, 2);
  if (g1.edge_exist(1, 2)) {
    cout << "Test - edge_exist12 ... Passed" << endl;
  } else {
    cout << "Test - edge_exist ... Failed" << endl;
  }
  if (g1.edge_exist(2, 1)) {
    cout << "Test - edge_exist21 ... Passed" << endl;
  } else {
    cout << "Test - edge_exist21 ... Failed" << endl;
  }

  if (g1.path_exist(1, 2)) {
    cout << "Test - path_exist12 ... Passed" << endl;
  } else {
    cout << "Test - path_exist12 ... Failed" << endl;
  }
  if (g1.path_exist(2, 1)) {
    cout << "Test - path_exist21 ... Passed" << endl;
  } else {
    cout << "Test - path_exist21 ... Failed" << endl;
  }

  if (g1.get_degree(1) == 1 && g1.get_degree(2) == 1) {
    cout << "Test - get_degree ... Passed" << endl;
  } else {
    cout << "Test - get_degree ... Failed" << endl;
  }

  // add 2->1
  g1.add_edge(2, 1);
  if (g1.edge_exist(2, 1)) {
    cout << "Test - edge_exist21 ... Passed" << endl;
  } else {
    cout << "Test - edge_exist21 ... Failed" << endl;
  }

  if (g1.path_exist(2, 1)) {
    cout << "Test - path_exist21 ... Passed" << endl;
  } else {
    cout << "Test - path_exist21 ... Failed" << endl;
  }

  cout << g1 << endl;
  g1--;
  cout << g1 << endl;

  Graph g2(4);
  g2.add_edge(1, 2);
  g2.add_edge(1, 3);
  g2.add_edge(4, 2);
  g2.add_edge(4, 3);

  cout << g2 << endl;
  cout << "g2.DFS(1): " << g2.DFS(1) << endl;
  cout << "g2.BFS(4): " << g2.BFS(4) << endl;

  Graph g3(7); // binary tree
  g3.add_edge(1, 2);
  g3.add_edge(1, 3);
  g3.add_edge(2, 4);
  g3.add_edge(2, 5);
  g3.add_edge(3, 6);
  g3.add_edge(3, 7);

  cout << g3 << endl;
  cout << "g3.DFS(1): " << g3.DFS(1) << endl;
  cout << "g3.BFS(1): " << g3.BFS(1) << endl;

  auto res = g3.DFS(2);
  cout << "g3.DFS(2): " << res << endl;

  return 0;
}
