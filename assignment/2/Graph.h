#ifndef CSI2372_ASSIGNMENT_2_GRAPH_H_
#define CSI2372_ASSIGNMENT_2_GRAPH_H_

#include <cstdio>
#include <iostream>

#include "DoubleLinkedList.h"

class Graph {
 public:
  // constants
  static constexpr int kDefaultNodeCount = 1;

  // ctors and dtors
  Graph();
  Graph(int node_count);
  Graph(const Graph& other);
  ~Graph();

  // methods
  bool add_edge(int u, int v);
  void remove_edge(int u, int v);
  bool edge_exist(int u, int v) const;
  int get_degree(int u) const;
  bool path_exist(int u, int v) const;

  // operators
  Graph& operator++();
  Graph operator++(int);
  Graph& operator--();
  Graph operator--(int);
  friend std::ostream& operator<<(std::ostream& out, const Graph& graph);

  // bonus part

 private:
  int node_count_; // node index: 1 to node_count_
  DoubleLinkedList* edges_; // size: node_count_ + 1; 0 is unused
};

#endif // CSI2372_ASSIGNMENT_2_GRAPH_H_