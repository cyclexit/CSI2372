// Hongyi Lin 300053082
// Stacy Guo 300157080

#ifndef CSI2372_ASSIGNMENT_3_MAPPING_RELATION_H_
#define CSI2372_ASSIGNMENT_3_MAPPING_RELATION_H_

#include <iostream>
#include <set>
#include <utility>
#include <vector>

template<typename Domain, typename Range>
class MappingRelation;

template<typename Domain, typename Range>
std::ostream& operator<<(std::ostream& out, const MappingRelation<Domain, Range>& mr);

template<typename Domain, typename Range>
class MappingRelation {
 public:
  // ctors and dtors
  MappingRelation() = default;
  MappingRelation(const MappingRelation<Domain, Range>& other);
  MappingRelation(std::set<Domain> domain, std::set<Range> range);
  ~MappingRelation() = default;

  // methods
  size_t cardinality() const;
  bool add_to_domain(const Domain& d);
  bool add_to_range(const Range& r);
  bool add_element(const Domain& d, const Range& r);
  void remove_element(const Domain& d, const Range& r);
  bool is_member(const Domain& d, const Range& r) const;
  bool is_function() const;
  MappingRelation<Domain, Range> intersection(const MappingRelation<Domain, Range>& other) const;
  MappingRelation<Range, Domain> inverse() const; // bonus
  MappingRelation<Domain, Range> combination(const MappingRelation<Domain, Range>& other) const; // bonus

  // operators
  bool operator==(const MappingRelation<Domain, Range>& other) const;
  MappingRelation<Domain, Range> operator+(const MappingRelation<Domain, Range>& other) const;
  MappingRelation<Domain, Range> operator-(const MappingRelation<Domain, Range>& other) const;
  std::vector<Range> operator[](Domain d) const;
  friend std::ostream& operator<< <> (std::ostream& out, const MappingRelation<Domain, Range>& mr);

 private:
  std::set<Domain> domain_;
  std::set<Range> range_;
  std::set<std::pair<Domain, Range>> relations_;
};

#endif // CSI2372_ASSIGNMENT_3_MAPPING_RELATION_H_
