// Hongyi Lin 300053082
// Stacy Guo 300157080

#ifndef CSI2372_ASSIGNMENT_3_MAPPING_RELATION_H_
#define CSI2372_ASSIGNMENT_3_MAPPING_RELATION_H_

#include <iostream>
#include <set>
#include <utility>

template<typename Domain, typename Range>
class MappingRelation;

template<typename Domain, typename Range>
class MappingRelation {
 public:
  // ctors and dtors
  MappingRelation() = default;
  MappingRelation(const MappingRelation<Domain, Range>& other);
  MappingRelation(std::set<Domain> domain, std::set<Range> range);
  ~MappingRelation() = default;

  // methods
  bool add_to_domain(Domain d);
  bool add_to_range(Range r);

 private:
  std::set<Domain> domain_;
  std::set<Range> range_;
  std::set<std::pair<Domain, Range>> relations_;
};

#endif // CSI2372_ASSIGNMENT_3_MAPPING_RELATION_H_
