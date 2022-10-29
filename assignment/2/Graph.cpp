#include "Graph.h"

Graph::Graph() {
  node_count_ = kDefaultNodeCount;
  edges_ = new DoubleLinkedList[node_count_ + 1];
}

Graph::Graph(int node_count) {
  node_count_ = node_count;
  edges_ = new DoubleLinkedList[node_count_ + 1];
}

Graph::Graph(const Graph& other) {
  node_count_ = other.node_count_;
  edges_ = new DoubleLinkedList[node_count_ + 1];

  for (int i = 1; i <= node_count_; ++i) {
    for (int j = 1; j <= node_count_; ++j) {
      if (other.edge_exist(i, j)) {
        add_edge(i, j);
      }
    }
  }
}

Graph::~Graph() {
  node_count_ = 0;
  if (edges_) delete[] edges_;
}

bool Graph::add_edge(int u, int v) {
  if (u > node_count_ || v > node_count_) {
    printf("Error: Node %d and/or %d not exist.\n", u, v);
    return false;
  }
  // NOTE: assume add the edge from u to v
  edges_[u].add_to_back(v);
  return true;
}

void Graph::remove_edge(int u, int v) {
  if (u > node_count_ || v > node_count_) return;
  edges_[u].remove_item(v);
}

bool Graph::edge_exist(int u, int v) const {
  if (u > node_count_ || v > node_count_) {
    printf("Error: Node %d and/or %d not exist.\n", u, v);
    return false;
  }
  return edges_[u].find(v);
}
