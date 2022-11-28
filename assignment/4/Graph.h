#ifndef CSI2372_ASSIGNMENT_4_GRAPH_H_
#define CSI2372_ASSIGNMENT_4_GRAPH_H_

#include <algorithm>
#include <iostream>
#include <vector>

class Graph {
 public:
  // ctors and dtors
  Graph();
  Graph(int node_count);
  Graph(const Graph& other);
  ~Graph() = default;

  // methods
  bool add_edge(int u, int v);
  void remove_edge(int u, int v);
  bool edge_exist(int u, int v) const;
  int get_degree(int u) const;
  bool path_exist(int u, int v) const;
  std::vector<int> BFS(int start) const;
  std::vector<int> DFS(int start) const;

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
  std::vector<std::vector<int>> edges_; // 0 is unused

  // methods
  bool is_node_valid(int node) const {
    return (1 <= node) && (node <= edges_.size() - 1);
  }
};

#endif // CSI2372_ASSIGNMENT_4_GRAPH_H_