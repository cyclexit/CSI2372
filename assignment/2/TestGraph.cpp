#include <iostream>

#include "Graph.h"

using namespace std;

int main() {
  /*
   * Simple test
   */
  Graph g1;
  if (g1.get_node_count() == Graph::kDefaultNodeCount) {
    cout << "Test - get_node_count ... Passed" << endl;
  } else {
    cout << "Test - get_node_count ... Failed" << endl;
  }

  // operator ++
  ++g1;
  if (g1.get_node_count() == Graph::kDefaultNodeCount + 1) {
    cout << "Test - operator++ ... Passed" << endl;
  } else {
    cout << "Test - operator++ ... Failed" << endl;
  }

  // add one edge
  g1.add_edge(1, 2);
  if (g1.edge_exist(1, 2)) {
    cout << "Test - edge_exist ... Passed" << endl;
  } else {
    cout << "Test - edge_exist ... Failed" << endl;
  }
  if (!g1.edge_exist(2, 1)) {
    cout << "Test - not edge_exist ... Passed" << endl;
  } else {
    cout << "Test - not edge_exist ... Failed" << endl;
  }

  if (g1.path_exist(1, 2)) {
    cout << "Test - path_exist ... Passed" << endl;
  } else {
    cout << "Test - path_exist ... Failed" << endl;
  }
  if (!g1.path_exist(2, 1)) {
    cout << "Test - not path_exist ... Passed" << endl;
  } else {
    cout << "Test - not path_exist ... Failed" << endl;
  }

  if (g1.get_degree(1) == 1 && g1.get_degree(2) == 0) {
    cout << "Test - get_degree ... Passed" << endl;
  } else {
    cout << "Test - get_degree ... Failed" << endl;
  }

  cout << g1 << endl;
  g1--;
  cout << g1 << endl;

  return 0;
}
