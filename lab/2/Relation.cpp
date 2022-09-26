#include "Relation.h"

Relation::Relation(const Relation& other) {
  elems_ = other.elems_;
  relations_ = other.relations_;
}

size_t Relation::cardinality() const {
  return relations_.size();
}

bool Relation::add_element(std::pair<int, int> r) {
  auto ret = relations_.insert(r);
  return ret.second;
}

void Relation::remove_element(std::pair<int, int> r) {
  auto itr = relations_.find(r);
  if (itr != relations_.end()) {
    relations_.erase(itr);
  }
}

bool Relation::is_member(std::pair<int, int> r) const {
  return relations_.count(r) > 0;
}

bool Relation::equal(const Relation& other) const {
  return (elems_ == other.elems_) && (relations_ == other.relations_);
}

bool Relation::reflexive() const {
  for (int e : elems_) {
    if (relations_.count({e, e}) == 0) {
      return false;
    }
  }
  return true;
}

bool Relation::irreflexive() const {
  for (int e : elems_) {
    if (relations_.count({e, e}) > 0) {
      return false;
    }
  }
  return true;
}
