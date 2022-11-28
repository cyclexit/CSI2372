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

// void Graph::remove_edge(int u, int v) {
//   if (!is_node_valid(u) || !is_node_valid(v)) return;
//   edges_[u].remove_item(v);
// }

// bool Graph::edge_exist(int u, int v) const {
//   if (!is_node_valid(u) || !is_node_valid(v)) {
//     printf("Error: Node %d and/or %d not exist.\n", u, v);
//     return false;
//   }
//   // NOTE: assume only check the edge from u to v
//   return edges_[u].find(v);
// }

int Graph::get_degree(int u) const {
  return edges_[u].size();
}
