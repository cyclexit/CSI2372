// Hongyi Lin 300053082
// Stacy Guo 300157080

#include "Forest.h"

Forest::Forest() {
  edges_.resize(kDefaultNodeCount + 1);
}

Forest::Forest(int node_count) {
  edges_.resize(node_count + 1);
}

Forest::Forest(const Forest& other) {
  edges_ = other.edges_;
}

bool Forest::add_edge(int u, int v) {
  if (!is_node_valid(u) || !is_node_valid(v)) {
    printf("Error: Node %d and/or %d not exist.\n", u, v);
    return false;
  }
  if (!edge_exist(u, v) && path_exist(u, v)) {
    printf("Error: Add the edge (%d, %d) will form a cycle!\n", u, v);
    return false;
  }
  edges_[u].push_back(v);
  edges_[v].push_back(u);
  return true;
}
