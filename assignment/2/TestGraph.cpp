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

  if (g1.connectivity_type() == 3) {
    cout << "Test - single vertex strongly connected ... Passed" << endl;
  } else {
    cout << "Test - single vertex strongly connected ... Failed" << endl;
  }

  // operator ++
  ++g1;
  if (g1.get_node_count() == Graph::kDefaultNodeCount + 1) {
    cout << "Test - operator++ ... Passed" << endl;
  } else {
    cout << "Test - operator++ ... Failed" << endl;
  }

  if (g1.connectivity_type() == 0) {
    cout << "Test - two vertex not connected ... Passed" << endl;
  } else {
    cout << "Test - two vertex not connected ... Failed" << endl;
  }

  // add 1->2
  g1.add_edge(1, 2);
  if (g1.edge_exist(1, 2)) {
    cout << "Test - edge_exist12 ... Passed" << endl;
  } else {
    cout << "Test - edge_exist ... Failed" << endl;
  }
  if (!g1.edge_exist(2, 1)) {
    cout << "Test - not edge_exist21 ... Passed" << endl;
  } else {
    cout << "Test - not edge_exist21 ... Failed" << endl;
  }

  if (g1.path_exist(1, 2)) {
    cout << "Test - path_exist12 ... Passed" << endl;
  } else {
    cout << "Test - path_exist12 ... Failed" << endl;
  }
  if (!g1.path_exist(2, 1)) {
    cout << "Test - not path_exist21 ... Passed" << endl;
  } else {
    cout << "Test - not path_exist21 ... Failed" << endl;
  }

  if (g1.connectivity_type() == 2) {
    cout << "Test - two vertex unilaterally connected ... Passed" << endl;
  } else {
    cout << "Test - two vertex unilaterally connected ... Failed" << endl;
  }

  if (g1.get_degree(1) == 1 && g1.get_degree(2) == 0) {
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

  if (g1.connectivity_type() == 3) {
    cout << "Test - two vertex strongly connected ... Passed" << endl;
  } else {
    cout << "Test - two vertex strongly connected ... Failed" << endl;
  }

  cout << g1 << endl;
  g1--;
  cout << g1 << endl;

  return 0;
}
