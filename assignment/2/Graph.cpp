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
