#ifndef LAB_8_MAPPING_H_
#define LAB_8_MAPPING_H_

#include <map>
#include <set>
#include <iostream>

template<typename T1, typename T2>
class Mapping;

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const Mapping<T1, T2>& m);

template<typename T1, typename T2>
class Mapping {
 public:
  // ctors and dtors
  Mapping() = default;
  Mapping(const Mapping& other);
  ~Mapping() = default;

  // methods
  void add_item(T1 k, T2 v);
  void remove_item(T1 k, T2 v);
  void clear_item(T1 k);
  std::set<T2> find_item(T1 k);

  // operators
  std::set<T2> operator[](T1 k);
  Mapping<T1, T2>& operator=(const Mapping<T1, T2>& other);
  friend std::ostream& operator<< <> (std::ostream& out, const Mapping<T1, T2>& m);

 private:
  std::map<T1, std::set<T2>> my_map_;
};

#endif // LAB_8_MAPPING_H_
