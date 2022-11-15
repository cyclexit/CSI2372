#include "Mapping.h"

template<typename T1, typename T2>
Mapping<T1, T2>::Mapping(const Mapping& other) {
  my_map_ = other.my_map_;
}

template<typename T1, typename T2>
void Mapping<T1, T2>::add_item(T1 k, T2 v) {
  my_map_[k].insert(v);
}

template<typename T1, typename T2>
void Mapping<T1, T2>::remove_item(T1 k, T2 v) {
  if (my_map_.find(k) == my_map_.end()) return;

  auto set_itr = my_map_[k].find(v);
  if (set_itr != my_map_[k].end()) {
    my_map_[k].erase(set_itr);
  }
}

template<typename T1, typename T2>
void Mapping<T1, T2>::clear_item(T1 k) {
  my_map_.erase(k);
}

template<typename T1, typename T2>
std::set<T2> Mapping<T1, T2>::find_item(T1 k) {
  auto map_itr = my_map_.find(k);
  return map_itr == my_map_.end() ? {} : map_itr->second;
}
