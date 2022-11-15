// Hongyi Lin 300053082
// Stacy Guo 300157080

#ifndef CSI2372_ASSIGNMENT_3_RELATION_H_
#define CSI2372_ASSIGNMENT_3_RELATION_H_

#include <set>
#include <utility>

class Relation {
 public:
  // ctors and dtors
  Relation() = default;
  Relation(const Relation& other);
  ~Relation() = default;

  // methods
  size_t cardinality() const;
  bool add_element(const std::pair<int, int>& r);
  void remove_element(const std::pair<int, int>& r);
  bool is_member(const std::pair<int, int>& r) const;
  bool equal(const Relation& other) const;
  bool reflexive() const;
  bool irreflexive() const;
  bool symmetric() const;
  bool asymmetric() const;
  bool transitive() const;
  bool is_function() const;
  Relation inverse() const;
  Relation combination(const Relation& other) const;

 private:
  std::set<int> elems_;
  std::set<std::pair<int, int>> relations_;
};

#endif // CSI2372_ASSIGNMENT_3_RELATION_H_
