#include <iostream>

#include "set.hpp"

/*
 * public
 */

// constructors
Set::Set(const Set& other) {
  elems_ = other.elems_;
};

// methods
size_t Set::cardinality() {
  return elems_.size();
}

bool Set::add_element(int elem) {
  if (is_member(elem)) {
    std::cout << elem << " is already in the set." << std::endl;
    return false;
  }
  if (elems_.size() >= kMaxSize) {
    std::cout << "Set is full!" << std::endl;
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

bool Set::is_member(int elem) {
  for (const int& x : elems_) {
    if (x == elem) {
      return true;
    }
  }
  return false;
}

bool Set::equal(Set& other) {
  return subset(other) && (cardinality() == other.cardinality());
}

bool Set::subset(Set& other) {
  for (const int x : elems_) {
    if (!other.is_member(x)) {
      return false;
    }
  }
  return true;
}

/*
 * private
 */
