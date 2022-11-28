#include "Forest.h"

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