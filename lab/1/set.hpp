#ifndef SET_HPP_
#define SET_HPP_

#include <cstdint>
#include <vector>

class Set {
 public:
  // constants
  static const uint64_t kMaxSize = 1000;

  // constructors
  Set() = default;
  Set(const Set& other);

  // methods
  size_t cardinality() const;
  bool add_element(int elem);
  void remove_element(int elem);
  bool is_member(int elem) const;
  bool equal(const Set& other) const;
  bool subset(const Set& other) const;
  Set set_union(const Set& other) const;
  Set intersection(const Set& other) const;
  Set difference(const Set& other) const;
  Set mutal_difference(const Set& other) const;

  void print() const;

 private:
  // data
  std::vector<int> elems_;
};

#endif // SET_HPP_
