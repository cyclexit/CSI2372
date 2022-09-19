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
  if (elems_.size() >= elem) {
    std::cout << "Set is full!" << std::endl;
    return false;
  }
  elems_.push_back(elem);
  return true;
}

bool Set::is_member(int elem) {
  for (const int x : elems_) {
    if (x == elem) {
      return true;
    }
  }
  return false;
}

/*
 * private
 */
