#ifndef LAB_6_ARRAY_H_
#define LAB_6_ARRAY_H_

#include <iostream>
#include <vector>

// pre-declaration
template<typename T> class Array;
template<typename T> std::ostream& operator<<(std::ostream& out, const Array<T>& a);

template<typename T>
class Array {
 public:
  // ctors and dtors
  Array();
  Array(int n);
  Array(int lower, int upper);
  Array(const Array<T>& other);
  ~Array();

  // methods
  bool add_item(T elem);
  bool insert_item(int idx, T elem);
  void remove_item();
  void remove_item(T elem);
  void erase_item(int idx);
  bool find_item(T elem, int& idx);

  // operators
  T& operator[](int idx);
  Array<T>& operator=(const Array<T>& other);
  friend std::ostream& operator<< <> (std::ostream& out, const Array<T>& a);

 private:
  // range [lower_, upper_] (inclusively)
  int lower_;
  int upper_;
  T dummy;
  std::vector<T> arr_;

  bool is_index_valid(int idx) {
    return lower_ <= idx && idx <= upper_;
  }
};

#endif // LAB_6_ARRAY_H_
