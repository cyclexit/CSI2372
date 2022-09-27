#ifndef RELATION_H_
#define RELATION_H_

#include <cstdint>
#include <utility>

#include "Set.h"

class Relation {
 public:
  // constants
  static constexpr int kInitCapacity = 100;

  // ctors and dtors
  Relation();
  Relation(const Relation& other);
  ~Relation();

  // methods
  size_t cardinality() const;

  bool add_element(const std::pair<int, int>& r);

  void remove_element(const std::pair<int, int>& r);

  bool is_member(const std::pair<int, int>& r) const;

  bool equal(const Relation& other) const;

  bool reflexive();

  bool irreflexive();

  bool symmetric() const;

  bool asymmetric() const;

  bool transitive() const;

  bool is_function() const;

  Relation inverse() const;

  Relation combination(const Relation& other) const;

 private:
  // data
  Set elems_;
  int cap = kInitCapacity;
  int sz = 0;
  std::pair<int, int>* relations_;
};

#endif // RELATION_H_
