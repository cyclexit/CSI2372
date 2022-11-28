#ifndef CSI2372_ASSIGNMENT_4_GRAPH_H_
#define CSI2372_ASSIGNMENT_4_GRAPH_H_

#include <iostream>
#include <vector>

class Graph {
 public:
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
  std::vector<int> BFS(int start);
  std::vector<int> DFS(int start);

  // operators
  Graph& operator++();
  Graph operator++(int);
  Graph& operator--();
  Graph operator--(int);
  friend std::ostream& operator<<(std::ostream& out, const Graph& graph);

 private:
  // constants
  static constexpr int kDefaultNodeCount = 1;

  // data
  std::vector<int> edges_; // size: node_count_ + 1; 0 is unused
};

#endif // CSI2372_ASSIGNMENT_4_GRAPH_H_