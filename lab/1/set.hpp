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
  size_t cardinality();
  bool add_element(int elem);
  void remove_element(int elem);
  bool is_member(int elem);
  bool equal(Set& other);
  bool subset(const Set& other);
  Set set_union(const Set& other);
  Set intersection(const Set& other);
  Set difference(const Set& other);
  Set mutal_difference(const Set& other);

 private:
  // data
  std::vector<int> elems_;
};

#endif // SET_HPP_
