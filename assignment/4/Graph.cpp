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
