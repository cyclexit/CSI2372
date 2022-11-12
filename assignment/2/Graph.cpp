#include <functional>

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
  if (u > node_count_ || v > node_count_ || u < 1 || v < 1) {
    printf("Error: Node %d and/or %d not exist.\n", u, v);
    return false;
  }
  // NOTE: assume add the edge from u to v
  edges_[u].add_to_back(v);
  return true;
}

void Graph::remove_edge(int u, int v) {
  if (u > node_count_ || v > node_count_ || u < 1 || v < 1) return;
  edges_[u].remove_item(v);
}

bool Graph::edge_exist(int u, int v) const {
  if (u > node_count_ || v > node_count_ || u < 1 || v < 1) {
    printf("Error: Node %d and/or %d not exist.\n", u, v);
    return false;
  }
  // NOTE: assume only check the edge from u to v
  return edges_[u].find(v);
}

int Graph::get_degree(int u) const {
  // NOTE: assume get the out degree
  return edges_[u].count_nodes();
}

bool Graph::path_exist(int u, int v) const {
  if (u > node_count_ || v > node_count_ || u < 1 || v < 1) {
    printf("Error: Node %d and/or %d not exist.\n", u, v);
    return false;
  }

  bool* visited = new bool[node_count_];
  for (int i = 0; i <= node_count_; ++i) {
    visited[i] = false;
  }

  // BFS
  // NOTE: assume only check the path from u to v
  DoubleLinkedList q;
  q.add_to_back(u);
  while (q.count_nodes() > 0) {
    int cur = q[0]; // get front
    q.remove_from_front();
    visited[cur] = true;
    for (int i = 0; i < edges_[cur].count_nodes(); ++i) {
      if (edges_[cur][i] == v) {
        delete[] visited;
        return true;
      }
      if (!visited[edges_[cur][i]]) q.add_to_back(edges_[cur][i]);
    }
  }
  delete[] visited;
  return false;
}

int Graph::get_node_count() const {
  return node_count_;
}

Graph& Graph::operator++() {
  DoubleLinkedList* tmp = new DoubleLinkedList[node_count_ + 2];
  int edge_count;
  for (int i = 1; i <= node_count_; ++i) {
    edge_count = edges_[i].count_nodes();
    for (int j = 0; j < edge_count; ++j) {
      tmp[i].add_to_back(edges_[i][j]);
    }
  }
  delete[] edges_;
  edges_ = tmp;

  ++node_count_;

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

std::ostream& operator<<(std::ostream& out, const Graph& graph) {
  // nodes
  out << "V = {";
  for (int i = 1; i <= graph.node_count_; ++i) {
    if (i > 1) out << ", ";
    out << i;
  }
  out << "}" << std::endl;

  // edges
  out << "E =" << std::endl << "{" << std::endl;
  for (int i = 1; i <= graph.node_count_; ++i) {
    out << "  " << i << " => ";
    if (graph.edges_[i].count_nodes() > 0) {
      out << graph.edges_[i] << std::endl;
    } else {
      out << "None" << std::endl;
    }
  }
  out << "}" << std::endl;

  return out;
}

int Graph::connectivity_type() {
  bool unilaterally_connected = true;
  bool strongly_connected = true;
  for (int i = 1; i <= node_count_; ++i) {
    for (int j = i + 1; j <= node_count_; ++j) {
      bool i_to_j = path_exist(i, j);
      bool j_to_i = path_exist(j, i);
      if (!(i_to_j && j_to_i)) {
        strongly_connected = false;
      }
      if (!(i_to_j || j_to_i)) {
        unilaterally_connected = false;
      }
    }
  }
  if (strongly_connected) {
    return 3;
  } else if (unilaterally_connected) {
    return 2;
  }

  // construct the underlying undirected graph
  Graph undirected(node_count_);
  for (int i = 1; i <= node_count_; ++i) {
    for (int j = 1; j <= node_count_; ++j) {
      if (edge_exist(i, j)) {
        undirected.add_edge(i, j);
        undirected.add_edge(j, i);
      }
    }
  }
  for (int i = 1; i <= node_count_; ++i) {
    for (int j = i + 1; j <= node_count_; ++j) {
      if (!undirected.path_exist(i, j)) {
        return 0;
      }
    }
  }
  return 1;
}

DoubleLinkedList Graph::BFS(int start) {
  if (start < 1 || start > node_count_) {
    printf("Error: Start node %d not exist.\n", start);
    return DoubleLinkedList();
  }

  DoubleLinkedList res;

  bool* visited = new bool[node_count_];
  for (int i = 0; i <= node_count_; ++i) {
    visited[i] = false;
  }

  DoubleLinkedList q;
  q.add_to_back(start);
  while (q.count_nodes() > 0) {
    int cur = q[0];
    q.remove_from_front();
    visited[cur] = true;
    res.add_to_back(cur);
    for (int i = 0; i < edges_[cur].count_nodes(); ++i) {
      if (!visited[edges_[cur][i]]) q.add_to_back(edges_[cur][i]);
    }
  }
  delete[] visited;

  return res;
}

DoubleLinkedList Graph::DFS(int start) {
  if (start < 1 || start > node_count_) {
    printf("Error: Start node %d not exist.\n", start);
    return DoubleLinkedList();
  }

  DoubleLinkedList res;

  bool* visited = new bool[node_count_];
  for (int i = 0; i <= node_count_; ++i) {
    visited[i] = false;
  }

  std::function<void(int)> dfs = [&](int cur) {
    visited[cur] = true;
    res.add_to_back(cur);
    for (int i = 0; i < edges_[cur].count_nodes(); ++i) {
      if (!visited[edges_[cur][i]]) {
        dfs(edges_[cur][i]);
      }
    }
  };
  dfs(start);
  delete[] visited;

  return res;
}
