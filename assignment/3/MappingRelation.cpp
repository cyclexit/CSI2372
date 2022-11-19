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
size_t MappingRelation<Domain, Range>::cardinality() const {
  return relations_.size();
}

template<typename Domain, typename Range>
bool MappingRelation<Domain, Range>::add_element(const Domain& d, const Range& r) {
  domain_.insert(d);
  range_.insert(r);
  auto res = relations_.insert({d, r});
  return res.second;
}

template<typename Domain, typename Range>
void MappingRelation<Domain, Range>::remove_element(const Domain& d, const Range& r) {
  auto itr = relations_.find({d, r});
  if (itr != relations_.end()) {
    relations_.erase(itr);
  }
}

template<typename Domain, typename Range>
bool MappingRelation<Domain, Range>::is_member(const Domain& d, const Range& r) const {
  return relations_.find({d, r}) != relations_.end();
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
    if (other.is_member(p.first, p.second)) {
      res.add_element(p.first, p.second);
    }
  }
  return res;
}

// bonus
template<typename Domain, typename Range>
MappingRelation<Range, Domain> MappingRelation<Domain, Range>::inverse() const {
  MappingRelation<Range, Domain> res(range_, domain_);
  for (const auto& p : relations_) {
    res.add_element(p.second, p.first);
  }
  return res;
}

template<typename Domain, typename Range>
bool MappingRelation<Domain, Range>::operator==(const MappingRelation<Domain, Range>& other) const {
  return (domain_ == other.domain_)
         && (range_ == other.range_)
         && (relations_ == other.relations_);
}

template<typename Domain, typename Range>
MappingRelation<Domain, Range> MappingRelation<Domain, Range>::operator+(const MappingRelation<Domain, Range>& other) const {
  MappingRelation<Domain, Range> res;
  for (const auto& p : relations_) {
    res.add_element(p.first, p.second);
  }
  for (const auto& p : other.relations_) {
    res.add_element(p.first, p.second);
  }
  return res;
}

template<typename Domain, typename Range>
MappingRelation<Domain, Range> MappingRelation<Domain, Range>::operator-(const MappingRelation<Domain, Range>& other) const {
  MappingRelation<Domain, Range> res;
  for (const auto& p : relations_) {
    if (!other.is_member(p.first, p.second)) {
      res.add_element(p.first, p.second);
    }
  }
  return res;
}

template<typename Domain, typename Range>
std::vector<Range> MappingRelation<Domain, Range>::operator[](Domain d) const {
  std::vector<Range> res;
  for (const auto& p : relations_) {
    if (p.first == d) {
      res.push_back(p.second);
    }
  }
  return res;
}

template<typename Domain, typename Range>
std::ostream& operator<<(std::ostream& out, const MappingRelation<Domain, Range>& mr) {
  out << "{";
  for (auto itr = mr.relations_.begin(); itr != mr.relations_.end(); ++itr) {
    if (itr != mr.relations_.begin()) out << ", ";
    out << "(" << itr->first << ", " << itr->second << ")";
  }
  out << "}";
  return out;
}
