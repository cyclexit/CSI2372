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
  virtual ~Graph() = default;

  // methods
  virtual bool add_edge(int u, int v);
  virtual void remove_edge(int u, int v);
  virtual bool edge_exist(int u, int v) const;
  virtual int get_degree(int u) const;
  virtual bool path_exist(int u, int v) const;
  virtual std::vector<int> BFS(int start) const;
  virtual std::vector<int> DFS(int start) const;

  // operators
  virtual Graph& operator++();
  virtual Graph operator++(int);
  virtual Graph& operator--();
  virtual Graph operator--(int);
  friend std::ostream& operator<<(std::ostream& out, const Graph& graph);

 protected:
  // constants
  static constexpr int kDefaultNodeCount = 1;

  // data
  std::vector<std::vector<int>> edges_; // 0 is unused

  // methods
  bool is_node_valid(int node) const {
    return (1 <= node) && (node <= edges_.size() - 1);
  }

  void remove_all_edges(int u, int v) {
    auto itr = std::find(edges_[u].begin(), edges_[u].end(), v);
    while (itr != edges_[u].end()) {
      edges_[u].erase(itr);
      itr = std::find(edges_[u].begin(), edges_[u].end(), v);
    }

    itr = std::find(edges_[v].begin(), edges_[v].end(), u);
    while (itr != edges_[v].end()) {
      edges_[v].erase(itr);
      itr = std::find(edges_[v].begin(), edges_[v].end(), u);
    }
  }
};

#endif // CSI2372_ASSIGNMENT_4_GRAPH_H_