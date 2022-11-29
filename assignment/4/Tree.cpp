#include "Tree.h"

Tree::Tree() {
  edges_.resize(kDefaultNodeCount + 1);
  set_root(1);
}

bool Tree::set_root(int node) {
  if (!is_node_valid(node)) return false;
  return root = node;
}

Graph& Tree::operator++() {
  int u = edges_.size() - 1;
  edges_.push_back({});
  int v = edges_.size() - 1;
  add_edge(u, v);
  return *this;
}

Graph Tree::operator++(int) {
  Tree old(*this);
  operator++();
  return old;
}

Graph& Tree::operator--() {
  int last = edges_.size() - 1;
  for (int neighbour : edges_[last]) {
    auto itr = std::find(edges_[neighbour].begin(), edges_[neighbour].end(), last);
    if (itr != edges_[neighbour].end()) edges_[neighbour].erase(itr);
  }
  edges_.pop_back();
  return *this;
}

Graph Tree::operator--(int) {
  Tree old(*this);
  operator--();
  return old;
}
