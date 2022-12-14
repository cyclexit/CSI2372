#include <iostream>

#include "Set.h"

/*
 * public
 */

// constructors
Set::Set(const Set& other) {
  elems_ = other.elems_;
};

// methods
size_t Set::cardinality() const {
  return elems_.size();
}

bool Set::add_element(int elem) {
  if (is_member(elem)) {
#ifdef ENABLE_DEBUG
    std::cout << elem << " is already in the set." << std::endl;
#endif // ENABLE_DEBUG
    return false;
  }
  if (elems_.size() >= kMaxSize) {
#ifdef ENABLE_DEBUG
    std::cout << "Set is full!" << std::endl;
#endif // ENABLE_DEBUG
    return false;
  }
  elems_.push_back(elem);
  return true;
}

void Set::remove_element(int elem) {
  int idx = -1;
  for (int i = 0; i < elems_.size(); ++i) {
    if (elems_[i] == elem) {
      idx = i;
      break;
    }
  }
  if (idx != -1) {
    elems_.erase(elems_.begin() + idx);
  }
}

bool Set::is_member(int elem) const {
  for (const int& x : elems_) {
    if (x == elem) {
      return true;
    }
  }
  return false;
}

bool Set::equal(const Set& other) const {
  return subset(other) && (cardinality() == other.cardinality());
}

bool Set::subset(const Set& other) const {
  for (const int x : elems_) {
    if (!other.is_member(x)) {
      return false;
    }
  }
  return true;
}

Set Set::Union(const Set& other) const {
  Set res(other);
  for (const int x : elems_) {
    res.add_element(x);
  }
  return res;
}

Set Set::intersection(const Set& other) const {
  Set res;
  for (const int x : elems_) {
    if (other.is_member(x)) {
      res.add_element(x);
    }
  }
  return res;
}

Set Set::difference(const Set& other) const {
  Set res;
  for (const int x : elems_) {
    if (!other.is_member(x)) {
      res.add_element(x);
    }
  }
  return res;
}

Set Set::mutual_difference(const Set& other) const {
  return difference(other).Union(other.difference(*this));
}

void Set::print() const {
  for (const int x : elems_) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
}

/*
 * private
 */
