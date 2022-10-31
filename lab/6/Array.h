#ifndef LAB_6_ARRAY_H_
#define LAB_6_ARRAY_H_

#include <iostream>
#include <vector>

template<typename T>
class Array {
 public:
  // ctors and dtors
  Array();
  Array(int n);
  Array(int lower, int upper);
  Array(const Array<T>& other);

  // methods
  bool add_item(T elem);
  bool insert_item(int idx, T elem);
  void remove_item();
  void remove_item(T elem);
  void erase_item(int idx);
  bool find_item(T elem);

  // operators
  T& operator[](int idx);

  Array& operator=(const Array<T>& other);

  friend std::ostream& operator<<(std::ostream& out, const Array<T>& a) {
    for (int i = 0; i < a.arr_.size(); ++i) {
      if (i) out << ", ";
      out << a.arr_[i];
    }
    return out;
  }

 private:
  int lower_;
  int upper_;
  std::vector<T> arr_;
};

#endif // LAB_6_ARRAY_H_
