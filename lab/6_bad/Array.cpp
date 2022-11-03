#include "Array.h"

template<typename T>
Array<T>::Array() {
  lower_ = 0;
  upper_ = 0;
}

template<typename T>
Array<T>::Array(int n) {
  lower_ = 0;
  upper_ = n - 1;
  arr_.resize(n);
}

template<typename T>
Array<T>::Array(int lower, int upper) {
  lower_ = lower;
  upper_ = upper;
  arr_.resize(upper - lower + 1);
}

template<typename T>
Array<T>::Array(const Array<T>& other) {
  lower_ = other.lower_;
  upper_ = other.upper_;
  arr_ = other.arr_;
}

template<typename T>
Array<T>::~Array() {
  lower_ = 0;
  upper_ = 0;
}

template<typename T>
bool Array<T>::add_item(T elem) {
  arr_.push_back(elem);
  ++upper_;
  return true;
}

template<typename T>
bool Array<T>::insert_item(int idx, T elem) {
  if (!is_index_valid(idx)) return false;
  idx -= lower_;
  arr_.insert(arr_.begin() + idx, elem);
  ++upper_;
  return true;
}

template<typename T>
void Array<T>::remove_item() {
  if (!arr_.empty()) arr_.pop_back();
  if (upper_ > lower_) --upper_;
}

template<typename T>
void Array<T>::remove_item(T elem) {
  int idx = -1;
  if (find_item(elem, idx)) {
    idx -= lower_;
    arr_.erase(arr_.begin() + idx);
    --upper_;
  }
}

template<typename T>
void Array<T>::erase_item(int idx) {
  if (is_index_valid(idx)) {
    idx -= lower_;
    arr_.erase(arr_.begin() + idx);
    --upper_;
  }
}

template<typename T>
bool Array<T>::find_item(T elem, int& idx) {
  for (int i = 0; i < arr_.size(); ++i) {
    if (arr_[i] == elem) {
      idx = lower_ + i;
      return true;
    }
  }
  idx = -1;
  return false;
}

template<typename T>
T& Array<T>::operator[](int idx) {
  return is_index_valid(idx) ? arr_[idx - lower_] : dummy;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
  lower_ = other.lower_;
  upper_ = other.upper_;
  arr_ = other.arr_;
  return *this;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& a) {
  for (int i = 0; i < a.arr_.size(); ++i) {
    if (i) out << ", ";
    out << a.arr_[i];
  }
  return out;
}
