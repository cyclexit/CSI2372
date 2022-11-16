// Hongyi Lin 300053082
// Stacy Guo 300157080

#ifndef CSI2372_ASSIGNMENT_3_RELATION_H_
#define CSI2372_ASSIGNMENT_3_RELATION_H_

#include <iostream>
#include <set>
#include <utility>

template<typename T>
class Relation;

template<typename T>
std::ostream& operator<<(std::ostream& out, const Relation<T>& rel);

template<typename T>
class Relation {
 public:
  // ctors and dtors
  Relation() = default;
  Relation(const std::set<T>& elems);
  Relation(const Relation<T>& other);
  ~Relation() = default;

  // methods
  size_t cardinality() const;
  bool add_to_set(const T& elem);
  bool add_element(const std::pair<T, T>& r);
  void remove_element(const std::pair<T, T>& r);
  bool is_member(const std::pair<T, T>& r) const;
  bool reflexive() const;
  bool irreflexive() const;
  bool symmetric() const;
  bool asymmetric() const;
  bool transitive() const;
  bool is_function() const;
  Relation<T> inverse() const;
  Relation<T> combination(const Relation<T>& other) const;

  // operators
  bool operator==(const Relation<T>& other) const;
  std::set<T> operator[](T key) const;
  friend std::ostream& operator<< <> (std::ostream& out, const Relation<T>& rel);

 private:
  std::set<T> elems_;
  std::set<std::pair<T, T>> relations_;
};

#endif // CSI2372_ASSIGNMENT_3_RELATION_H_
