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

std::ostream& operator<<(std::ostream& out, const Tree& t) {
  std::vector<bool> visited(t.edges_.size(), false);
  std::function<void(int, int)> dfs = [&](int cur, int depth) {
    visited[cur] = true;
    if (depth == 0) {
      out << cur << std::endl;
    } else {
      for (int i = 1; i < depth; ++i) {
        out << "\t";
      }
      out << "---" << cur << std::endl;
    }
    for (int i = 0; i < t.edges_[cur].size(); ++i) {
      if (!visited[t.edges_[cur][i]]) {
        dfs(t.edges_[cur][i], depth + 1);
      }
    }
  };
  dfs(t.root, 0);
  return out;
}
