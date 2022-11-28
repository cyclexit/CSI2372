#include <cstdio>

#include "Graph.h"

Graph::Graph() {
  edges_.resize(kDefaultNodeCount + 1);
}

Graph::Graph(int node_count) {
  edges_.resize(node_count + 1);
}

Graph::Graph(const Graph& other) {
  edges_ = other.edges_;
}

bool Graph::add_edge(int u, int v) {
  if (!is_node_valid(u) || !is_node_valid(v)) {
    printf("Error: Node %d and/or %d not exist.\n", u, v);
    return false;
  }
  edges_[u].push_back(v);
  edges_[v].push_back(u);
  return true;
}

void Graph::remove_edge(int u, int v) {
  if (!is_node_valid(u) || !is_node_valid(v)) return;

  auto uv_itr = std::find(edges_[u].begin(), edges_[u].end(), v);
  if (uv_itr != edges_[u].end()) edges_[u].erase(uv_itr);

  auto vu_itr = std::find(edges_[v].begin(), edges_[v].end(), u);
  if (vu_itr != edges_[v].end()) edges_[v].erase(vu_itr);
}

bool Graph::edge_exist(int u, int v) const {
  if (!is_node_valid(u) || !is_node_valid(v)) {
    printf("Error: Node %d and/or %d not exist.\n", u, v);
    return false;
  }
  auto uv_itr = std::find(edges_[u].begin(), edges_[u].end(), v);
  auto vu_itr = std::find(edges_[v].begin(), edges_[v].end(), u);
  return (uv_itr != edges_[u].end()) && (vu_itr != edges_[v].end());
}

int Graph::get_degree(int u) const {
  return edges_[u].size();
}
