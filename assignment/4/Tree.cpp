#include "Tree.h"

Tree::Tree() {
  edges_.resize(kDefaultNodeCount + 1);
  set_root(1);
}

bool Tree::set_root(int node) {
  if (!is_node_valid(node)) return false;
  return root = node;
}
