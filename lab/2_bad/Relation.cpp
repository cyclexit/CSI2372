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

bool Relation::equal(const Relation& other) const {
  bool ok = elems_.equal(other.elems_) && (sz == other.sz);
  if (ok) {
    for (int i = 0; i < sz; ++i) {
      if (!other.is_member(relations_[i])) {
        return false;
      }
    }
  }
  return ok;
}

bool Relation::reflexive() {
  for (int e : elems_) {
    if (!is_member({e, e})) {
      return false;
    }
  }
  return true;
}

bool Relation::irreflexive() {
  for (int e : elems_) {
    if (is_member({e, e})) {
      return false;
    }
  }
  return true;
}

bool Relation::symmetric() const {
  for (int i = 0; i < sz; ++i) {
    if (!is_member({relations_[i].second, relations_[i].first})) {
      return false;
    }
  }
  return true;
}

bool Relation::asymmetric() const {
  for (int i = 0; i < sz; ++i) {
    if (relations_[i].first == relations_[i].second) continue;
    if (is_member({relations_[i].second, relations_[i].first})) {
      return false;
    }
  }
  return true;
}

bool Relation::transitive() {
  for (int i = 0; i < sz; ++i) {
    for (int x : elems_) {
      if (is_member({relations_[i].second, x})) {
        if (!is_member({relations_[i].first, x})) {
          return false;
        }
      }
    }
  }
  return true;
}

bool Relation::is_function() const {
  for (int i = 0; i < sz; ++i) {
    for (int j = 0; j < sz; ++j) {
      if ((relations_[i].first == relations_[j].first)
          && (relations_[i].second != relations_[j].second)) {
        return false;
      }
    }
  }
  return true;
}

Relation Relation::inverse() const {
  Relation res;
  for (int i = 0; i < sz; ++i) {
    res.add_element({relations_[i].second, relations_[i].first});
  }
  return res;
}

Relation Relation::combination(const Relation& other) const {
  Relation res;
  if (elems_.equal(other.elems_)) {
    for (int i = 0; i < sz; ++i) {
      for (int j = 0; j < other.sz; ++j) {
        if (relations_[i].second == other.relations_[j].first) {
          res.add_element({relations_[i].first, other.relations_[j].second});
        }
      }
    }
  }
  return res;
}

bool Relation::add_to_set(int x) {
  return elems_.add_element(x);
}
