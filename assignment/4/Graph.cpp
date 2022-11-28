#include <cstdio>
#include <functional>
#include <queue>

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

bool Graph::add_edge(int u, int v) {
  if (!is_node_valid(u) || !is_node_valid(v)) {
    printf("Error: Node %d and/or %d not exist.\n", u, v);
    return false;
  }
  edges_[u].push_back(v);
  edges_[v].push_back(u);
  return true;
}

// NOTE: just remove one edge between u and v
void Graph::remove_edge(int u, int v) {
  if (!is_node_valid(u) || !is_node_valid(v)) return;

  auto uv_itr = std::find(edges_[u].begin(), edges_[u].end(), v);
  if (uv_itr != edges_[u].end()) edges_[u].erase(uv_itr);

  auto vu_itr = std::find(edges_[v].begin(), edges_[v].end(), u);
  if (vu_itr != edges_[v].end()) edges_[v].erase(vu_itr);
}

bool Graph::edge_exist(int u, int v) const {
  if (!is_node_valid(u) || !is_node_valid(v)) {
    printf("Error: Node %d and/or %d not exist.\n", u, v);
    return false;
  }
  auto uv_itr = std::find(edges_[u].begin(), edges_[u].end(), v);
  auto vu_itr = std::find(edges_[v].begin(), edges_[v].end(), u);
  return (uv_itr != edges_[u].end()) && (vu_itr != edges_[v].end());
}

int Graph::get_degree(int u) const {
  return edges_[u].size();
}

bool Graph::path_exist(int u, int v) const {
  if (!is_node_valid(u) || !is_node_valid(v)) {
    printf("Error: Node %d and/or %d not exist.\n", u, v);
    return false;
  }

  // BFS
  std::vector<bool> visited(edges_.size(), false);
  std::queue<int> q;
  q.push(u);
  while (q.size() > 0) {
    int cur = q.front();
    q.pop();
    visited[cur] = true;
    for (int i = 0; i < edges_[cur].size(); ++i) {
      if (edges_[cur][i] == v) {
        return true;
      }
      if (!visited[edges_[cur][i]]) q.push(edges_[cur][i]);
    }
  }
  return false;
}

std::vector<int> Graph::BFS(int start) const {
  if (!is_node_valid(start)) {
    printf("Error: Start node %d not exist.\n", start);
    return {};
  }
  std::vector<int> res;
  std::vector<bool> visited(edges_.size(), false);
  std::queue<int> q;
  q.push(start);
  while (q.size() > 0) {
    int cur = q.front();
    q.pop();
    res.push_back(cur);
    visited[cur] = true;
    for (int i = 0; i < edges_[cur].size(); ++i) {
      if (!visited[edges_[cur][i]]) q.push(edges_[cur][i]);
    }
  }
  return res;
}

std::vector<int> Graph::DFS(int start) const {
  if (!is_node_valid(start)) {
    printf("Error: Start node %d not exist.\n", start);
    return {};
  }
  std::vector<int> res;
  std::vector<bool> visited(edges_.size(), false);
  std::function<void(int)> dfs = [&](int cur) {
    visited[cur] = true;
    res.push_back(cur);
    for (int i = 0; i < edges_[cur].size(); ++i) {
      if (!visited[edges_[cur][i]]) {
        dfs(edges_[cur][i]);
      }
    }
  };
  dfs(start);
  return res;
}

Graph& Graph::operator++() {
  edges_.push_back({});
  return *this;
}

Graph Graph::operator++(int) {
  Graph old(*this);
  operator++();
  return old;
}

Graph& Graph::operator--() {
  int last = edges_.size() - 1;
  for (int i = 1 ; i < last; ++i) {
    remove_all_edges(i, last);
  }
  edges_.pop_back();
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
  for (int i = 1; i < graph.edges_.size(); ++i) {
    if (i > 1) out << ", ";
    out << i;
  }
  out << "}" << std::endl;

  // edges
  out << "E =" << std::endl << "{" << std::endl;
  for (int i = 1; i < graph.edges_.size(); ++i) {
    out << "  " << i << " => ";
    if (graph.edges_[i].size() > 0) {
      for (int j = 0; j < graph.edges_[i].size(); ++j) {
        if (j > 0) out << ", ";
        out << graph.edges_[i][j];
      }
      out << std::endl;
    } else {
      out << "None" << std::endl;
    }
  }
  out << "}" << std::endl;

  return out;
}
