// Hongyi Lin 300053082
// Stacy Guo 300157080

#include "MappingRelation.h"

template<typename Domain, typename Range>
MappingRelation<Domain, Range>::MappingRelation(const MappingRelation<Domain, Range>& other) {
  domain_ = other.domain_;
  range_ = other.range_;
  relations_ = other.relations_;
}

template<typename Domain, typename Range>
MappingRelation<Domain, Range>::MappingRelation(std::set<Domain> domain,
                                                std::set<Range> range) {
  domain_ = domain;
  range_ = range;
}
