// Hongyi Lin 300053082
// Stacy Guo 300157080

#include "Relation.h"

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
bool Relation<T>::add_element(const std::pair<T, T>& r) {
  if (elems_.find(r.first) == elems_.end()
      || elems_.find(r.second) == elems_.end()) {
    return false;
  }
  auto ret = relations_.insert(r);
  return ret.second;
}

template<typename T>
void Relation<T>::remove_element(const std::pair<T, T>& r) {
  auto itr = relations_.find(r);
  if (itr != relations_.end()) {
    relations_.erase(itr);
  }
}

template<typename T>
bool Relation<T>::is_member(const std::pair<T, T>& r) const {
  return relations_.count(r) > 0;
}
