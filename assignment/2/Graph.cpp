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
  return edges_[u].find(v) || edges_[v].find(u);
}

int Graph::get_degree(int u) const {
  return edges_[u].count_nodes();
}

bool Graph::path_exist(int u, int v) const {
  bool* visited = new bool[node_count_];
  for (int i = 0; i <= node_count_; ++i) {
    visited[i] = false;
  }

  // BFS
  DoubleLinkedList q;
  q.add_to_back(u);
  while (q.count_nodes() > 0) {
    int cur = q[0]; // get front
    visited[cur] = true;
    for (int i = 0; i < edges_[cur].count_nodes(); ++i) {
      if (edges_[cur][i] == v) return true;
      if (!visited[edges_[cur][i]]) q.add_to_back(edges_[cur][i]);
    }
  }
  return false;
}

Graph& Graph::operator++() {
  ++node_count_;

  DoubleLinkedList* tmp = new DoubleLinkedList[node_count_ + 1];
  int edge_count;
  for (int i = 1; i <= node_count_; ++i) {
    edge_count = edges_[i].count_nodes();
    for (int j = 0; j < edge_count; ++j) {
      tmp[i].add_to_back(edges_[i][j]);
    }
  }
  delete[] edges_;
  edges_ = tmp;

  return *this;
}

Graph Graph::operator++(int) {
  Graph old(*this);
  operator++();
  return old;
}

Graph& Graph::operator--() {
  DoubleLinkedList* tmp = new DoubleLinkedList[node_count_];
  int edge_count;
  for (int i = 1; i < node_count_; ++i) {
    edge_count = edges_[i].count_nodes();
    for (int j = 0; j < edge_count; ++j) {
      if (edges_[i][j] != node_count_) {
        tmp[i].add_to_back(edges_[i][j]);
      }
    }
  }
  delete[] edges_;
  edges_ = tmp;

  --node_count_;

  return *this;
}

Graph Graph::operator--(int) {
  Graph old(*this);
  operator--();
  return old;
}
