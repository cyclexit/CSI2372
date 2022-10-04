#include <cmath>

#include "Vector.h"

Vector::Vector() {
  dimension_ = kDefaultDimension;
  elems_ = new double[dimension_];
}

Vector::Vector(double* arr, int n) : elems_(arr), dimension_(n) {}

Vector::Vector(const Vector& other) {
  elems_ = other.elems_;
  dimension_ = other.dimension_;
}

int Vector::dimension() {
  return dimension_;
}

bool Vector::add_dimension(double val) {
  // Without std::vector, this function implementation is so fxxking stupid!
  double* tmp = new double[dimension_ + 1];
  if (tmp == nullptr) return false;

  for (int i = 0; i < dimension_; ++i) {
    tmp[i] = elems_[i];
  }

  delete[] elems_;
  elems_ = tmp;
  elems_[dimension_++] = val;
  return true;
}

bool Vector::remove_dimension(int idx) {
  // Same comment as above
  if (idx >= dimension_) return false;

  double* tmp = new double[dimension_ - 1];
  if (tmp == nullptr) return false;

  for (int i = 0; i < dimension_; ++i) {
    if (i != idx) tmp[i] = elems_[i];
  }

  delete[] elems_;
  elems_ = tmp;
  --dimension_;
  return true;
}

bool Vector::insert_dimension(double val, int idx) {
  if (idx > dimension_) return false;

  double* tmp = new double[dimension_ + 1];
  if (tmp == nullptr) return false;

  for (int i = 0; i < idx; ++i) {
    tmp[i] = elems_[i];
  }
  tmp[idx] = val;
  for (int i = idx; i < dimension_; ++i) {
    tmp[i + 1] = elems_[i];
  }

  delete[] elems_;
  elems_ = tmp;
  ++dimension_;
  return true;
}

double Vector::magnitude() {
  double res = 0.0;
  for (int i = 0; i < dimension_; ++i) {
    res += elems_[i] * elems_[i];
  }
  return sqrt(res);
}

double Vector::operator[](int idx) {
  return idx >= dimension_ ? kInvalidValue : elems_[idx];
}

bool Vector::operator==(const Vector& other) {
  if (other.dimension_ != dimension_) return false;

  for (int i = 0; i < dimension_; ++i) {
    if (other.elems_[i] != elems_[i]) return false;
  }
  return true;
}

bool Vector::operator!=(const Vector& other) {
  return !((*this) == other);
}

Vector& Vector::operator=(const Vector& other) {
  elems_ = other.elems_;
  dimension_ = other.dimension_;
}

Vector& operator+(Vector lhs, const Vector& rhs) {
  return (lhs += rhs);
}

Vector& Vector::operator+=(const Vector& other) {
  int smaller_dimension = std::min(other.dimension_, dimension_);
  int res_dimension = std::max(other.dimension_, dimension_);
  
  double* res = new double[res_dimension];
  for (int i = 0; i < res_dimension; ++i) {
    if (i < smaller_dimension) {
      res[i] = elems_[i] * other.elems_[i];
    } else {
      res[i] = 0.0;
    }
  }

  delete[] elems_;
  elems_ = res;
  dimension_ = res_dimension;
  return (*this);
}
