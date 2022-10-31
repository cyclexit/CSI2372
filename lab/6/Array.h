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
  bool add_item(T elem) {
    arr_.push_back(elem);
    ++upper_;
    return true;
  }

  bool insert_item(int idx, T elem) {
    if (!is_index_valid(idx)) return false;
    idx -= lower_;
    arr_.insert(arr_.begin() + idx, elem);
    ++upper_;
    return true;
  }

  void remove_item() {
    if (!arr_.empty()) arr_.pop_back();
    if (upper_ > lower_) --upper_;
  }

  void remove_item(T elem) {
    int idx = -1;
    if (find_item(elem, idx)) {
      idx -= lower_;
      arr_.erase(arr_.begin() + idx);
      --upper_;
    }
  }

  void erase_item(int idx) {
    if (is_index_valid(idx)) {
      idx -= lower_;
      arr_.erase(arr_.begin() + idx);
      --upper_;
    }
  }

  bool find_item(T elem, int& idx) {
    for (int i = 0; i < arr_.size(); ++i) {
      if (arr_[i] == elem) {
        idx = lower_ + i;
        return true;
      }
    }
    idx = -1;
    return false;
  }

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
