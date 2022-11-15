#ifndef LAB_8_MAPPING_H_
#define LAB_8_MAPPING_H_

#include <map>
#include <set>
#include <iostream>

template<typename T1, typename T2>
class Mapping {
 public:
  Mapping() = default;
  Mapping(const Mapping& other);
  ~Mapping() = default;
 
 private:
  std::map<T1, std::set<T2>> mp;
};

#endif // LAB_8_MAPPING_H_
