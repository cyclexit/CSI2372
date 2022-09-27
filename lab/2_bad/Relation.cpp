#include "Relation.h"

Relation::Relation() {
  relations_ = new std::pair<int, int>[kInitCapacity];
}

Relation::Relation(const Relation& other) : elems_(other.elems_), sz(other.sz) {
  relations_ = other.relations_;
}

Relation::~Relation() {
  delete[] relations_;
}

size_t Relation::cardinality() const {
  return sz;
}

bool Relation::add_element(std::pair<int, int> r) {
  
}

void Relation::remove_element(std::pair<int, int> r) {
  // auto itr = relations_.find(r);
  // if (itr != relations_.end()) {
  //   relations_.erase(itr);
  // }
}

bool Relation::is_member(std::pair<int, int> r) const {
  
}

/*


bool Relation::equal(const Relation& other) const {
  return (elems_ == other.elems_) && (relations_ == other.relations_);
}

bool Relation::reflexive() const {
  for (int e : elems_) {
    if (!is_member({e, e})) {
      return false;
    }
  }
  return true;
}

bool Relation::irreflexive() const {
  for (int e : elems_) {
    if (is_member({e, e})) {
      return false;
    }
  }
  return true;
}

bool Relation::symmetric() const {
  for (auto p : relations_) {
    if (!is_member({p.second, p.first})) {
      return false;
    }
  }
  return true;
}

bool Relation::asymmetric() const {
  for (auto p : relations_) {
    if (p.first == p.second) continue;
    if (is_member({p.second, p.first})) {
      return false;
    }
  }
  return true;
}

bool Relation::transitive() const {
  for (auto p : relations_) {
    for (int x : elems_) {
      if (is_member({p.second, x})) {
        if (!is_member({p.first, x})) {
          return false;
        }
      }
    }
  }
  return true;
}

bool Relation::is_function() const {
  for (auto p1 : relations_) {
    for (auto p2 : relations_) {
      if ((p1.first == p2.first) && (p1.second != p2.second)) {
        return false;
      }
    }
  }
  return true;
}

Relation Relation::inverse() const {
  Relation res;
  for (auto p : relations_) {
    res.add_element({p.second, p.first});
  }
  return res;
}

Relation Relation::combination(const Relation& other) const {
  Relation res;
  if (elems_ == other.elems_) {
    for (auto p1 : relations_) {
      for (auto p2 : other.relations_) {
        if (p1.second == p2.first) {
          res.add_element({p1.first, p2.second});
        }
      }
    }
  }
  return res;
}
*/
