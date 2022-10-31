#ifndef LAB_6_ARRAY_H_
#define LAB_6_ARRAY_H_

#include <iostream>
#include <vector>

template<typename T>
class Array {
 public:
  // ctors and dtors
  Array() {
    lower_ = 0;
    upper_ = 0;
  }

  Array(int n) {
    lower_ = 0;
    upper_ = n - 1;
    arr_.resize(n);
  }

  Array(int lower, int upper) {
    lower_ = lower;
    upper_ = upper;
    arr_.resize(upper - lower + 1);
  }

  Array(const Array<T>& other) {
    lower_ = other.lower_;
    upper_ = other.upper_;
    arr_ = other.arr_;
  }

  ~Array() {
    lower_ = 0;
    upper_ = 0;
  }

  // methods
  bool add_item(T elem);
  bool insert_item(int idx, T elem);
  void remove_item();
  void remove_item(T elem);
  void erase_item(int idx);
  bool find_item(T elem);

  // operators
  T& operator[](int idx) {
    return is_index_valid(idx) ? arr_[idx - lower_] : dummy;
  }

  Array<T>& operator=(const Array<T>& other) {
    lower_ = other.lower_;
    upper_ = other.upper_;
    arr_ = other.arr_;
  }

  friend std::ostream& operator<<(std::ostream& out, const Array<T>& a) {
    for (int i = 0; i < a.arr_.size(); ++i) {
      if (i) out << ", ";
      out << a.arr_[i];
    }
    return out;
  }

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
