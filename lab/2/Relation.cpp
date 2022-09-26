#include "Relation.h"

Relation::Relation(const Relation& other) {
  relations_ = other.relations_;
}

size_t Relation::cardinality() const {
  return relations_.size();
}

bool Relation::add_element(std::pair<int, int> r) {
  if (is_member(r)) return false;
  relations_.push_back(r);
  return true;
}

void Relation::remove_element(std::pair<int, int> r) {
  int idx = -1;
  for (int i = 0; i < relations_.size(); ++i) {
    if (r == relations_[i]) {
      idx = i;
      break;
    }
  }
  if (idx != -1) relations_.erase(relations_.begin() + idx);
}

bool Relation::is_member(std::pair<int, int> r) const {
  for (int i = 0; i < relations_.size(); ++i) {
    if (r == relations_[i]) {
      return true;
    }
  }
  return false;
}
