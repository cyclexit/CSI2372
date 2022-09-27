#include "Relation.h"

Relation::Relation() {
  relations_ = new std::pair<int, int>[cap];
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

bool Relation::add_element(const std::pair<int, int>& r) {
  if (is_member(r)) return false;

  if (sz == cap) {
    // enlarge the size
    cap += cap / 2;
    std::pair<int, int>* temp = new std::pair<int, int>[cap];
    for (int i = 0; i < sz; ++i) {
      temp[i] = relations_[i];
    }
    delete[] relations_;
    relations_ = temp;
    // add the new elements now
    relations_[sz++] = r;
  } else {
    relations_[sz++] = r;
    elems_.add_element(r.first);
    elems_.add_element(r.second);
  }
  return true;
}

void Relation::remove_element(const std::pair<int, int>& r) {
  int idx = -1;
  for (int i = 0; i < sz; ++i) {
    if (relations_[i] == r) {
      idx = i;
      break;
    }
  }
  if (idx != -1) {
    for (int i = idx; i < sz; ++i) {
      if (i != sz - 1) {
        relations_[i] = relations_[i + 1];
      }
    }
    relations_[--sz] = std::pair<int, int>();
  }
}

bool Relation::is_member(const std::pair<int, int>& r) const {
  for (int i = 0; i < sz; ++i) {
    if (relations_[i] == r) {
      return true;
    }
  }
  return false;
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
