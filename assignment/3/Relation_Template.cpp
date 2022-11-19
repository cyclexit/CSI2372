// Hongyi Lin 300053082
// Stacy Guo 300157080

#include "Relation_Template.h"

template<typename T>
Relation<T>::Relation(const std::set<T>& elems) {
  elems_ = elems;
}

template<typename T>
Relation<T>::Relation(const Relation<T>& other) {
  elems_ = other.elems_;
  relations_ = other.relations_;
}

template<typename T>
size_t Relation<T>::cardinality() const {
  return relations_.size();
}

template<typename T>
bool Relation<T>::add_to_set(const T& elem) {
  auto ret = elems_.insert(elem);
  return ret.second;
}

template<typename T>
bool Relation<T>::add_element(const T& a, const T& b) {
  if (elems_.find(a) == elems_.end()
      || elems_.find(b) == elems_.end()) {
    return false;
  }
  auto ret = relations_.insert({a, b});
  return ret.second;
}

template<typename T>
void Relation<T>::remove_element(const T& a, const T& b) {
  auto itr = relations_.find({a, b});
  if (itr != relations_.end()) {
    relations_.erase(itr);
  }
}

template<typename T>
bool Relation<T>::is_member(const T& a, const T& b) const {
  return relations_.find({a, b}) != relations_.end();
}

template<typename T>
bool Relation<T>::reflexive() const {
  for (const T& e : elems_) {
    if (!is_member(e, e)) {
      return false;
    }
  }
  return true;
}

template<typename T>
bool Relation<T>::irreflexive() const {
  for (const T& e : elems_) {
    if (is_member(e, e)) {
      return false;
    }
  }
  return true;
}

template<typename T>
bool Relation<T>::symmetric() const {
  for (auto p : relations_) {
    if (!is_member(p.second, p.first)) {
      return false;
    }
  }
  return true;
}

template<typename T>
bool Relation<T>::asymmetric() const {
  for (auto p : relations_) {
    if (p.first == p.second) continue;
    if (is_member(p.second, p.first)) {
      return false;
    }
  }
  return true;
}

template<typename T>
bool Relation<T>::transitive() const {
  for (auto p : relations_) {
    for (auto x : elems_) {
      if (is_member(p.second, x)) {
        if (!is_member(p.first, x)) {
          return false;
        }
      }
    }
  }
  return true;
}

template<typename T>
bool Relation<T>::is_function() const {
  for (auto p1 : relations_) {
    for (auto p2 : relations_) {
      if ((p1.first == p2.first) && (p1.second != p2.second)) {
        return false;
      }
    }
  }
  return true;
}

template<typename T>
Relation<T> Relation<T>::inverse() const {
  Relation<T> res;
  for (auto p : relations_) {
    res.add_element(p.second, p.first);
  }
  return res;
}

template<typename T>
Relation<T> Relation<T>::combination(const Relation<T>& other) const {
  Relation<T> res;
  if (elems_ == other.elems_) {
    for (auto p1 : relations_) {
      for (auto p2 : other.relations_) {
        if (p1.second == p2.first) {
          res.add_element(p1.first, p2.second);
        }
      }
    }
  }
  return res;
}

template<typename T>
bool Relation<T>::operator==(const Relation<T>& other) const {
  return (elems_ == other.elems_) && (relations_ == other.relations_);
}

template<typename T>
std::vector<T> Relation<T>::operator[](T key) const {
  std::vector<T> res;
  for (auto p : relations_) {
    if (p.first == key) {
      res.push_back(p.second);
    }
  }
  return res;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Relation<T>& rel) {
  out << "{";
  for (auto itr = rel.relations_.begin(); itr != rel.relations_.end(); ++itr) {
    if (itr != rel.relations_.begin()) out << ", ";
    out << "(" << itr->first << ", " << itr->second << ")";
  }
  out << "}";
  return out;
}
