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

template<typename Domain, typename Range>
bool MappingRelation<Domain, Range>::add_to_domain(const Domain& d) {
  auto res = domain_.insert(d);
  return res.second;
}

template<typename Domain, typename Range>
bool MappingRelation<Domain, Range>::add_to_range(const Range& r) {
  auto res = range_.insert(r);
  return res.second;
}

template<typename Domain, typename Range>
bool MappingRelation<Domain, Range>::add_element(const std::pair<Domain, Range>& r) {
  if (domain_.find(r.first) == domain_.end()
      || range_.find(r.second) == range_.end()) {
    return false;
  }
  auto res = relations_.insert(r);
  return res.second;
}

template<typename Domain, typename Range>
void MappingRelation<Domain, Range>::remove_element(const std::pair<Domain, Range>& r) {
  auto itr = relations_.find(r);
  if (itr != relations_.end()) {
    relations_.erase(itr);
  }
}

template<typename Domain, typename Range>
bool MappingRelation<Domain, Range>::is_member(const std::pair<Domain, Range>& r) const {
  return relations_.find(r) != relations_.end();
}

template<typename Domain, typename Range>
bool MappingRelation<Domain, Range>::is_function() const {
  for (auto p1 : relations_) {
    for (auto p2 : relations_) {
      if ((p1.first == p2.first) && (p1.second != p2.second)) {
        return false;
      }
    }
  }
  return true;
}

template<typename Domain, typename Range>
MappingRelation<Domain, Range> MappingRelation<Domain, Range>::intersection(const MappingRelation<Domain, Range>& other) const {
  MappingRelation<Domain, Range> res;
  for (const auto& p : relations_) {
    if (other.is_member(p)) {
      res.add_to_domain(p.first);
      res.add_to_range(p.second);
      res.add_element(p);
    }
  }
  return res;
}

template<typename Domain, typename Range>
bool MappingRelation<Domain, Range>::operator==(const MappingRelation<Domain, Range>& other) const {
  return (domain_ == other.domain_)
         && (range_ = other.range_)
         && (relations_ == other.relations_);
}

template<typename Domain, typename Range>
MappingRelation<Domain, Range> MappingRelation<Domain, Range>::operator+(const MappingRelation<Domain, Range>& other) const {
  MappingRelation<Domain, Range> res;
  for (const auto& p : relations_) {
    res.add_to_domain(p.first);
    res.add_to_range(p.second);
    res.add_element(p);
  }
  for (const auto& p : other.relations_) {
    res.add_to_domain(p.first);
    res.add_to_range(p.second);
    res.add_element(p);
  }
  return res;
}
