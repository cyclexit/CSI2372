#include <cmath>

#include "Vector.h"

Vector::Vector() {
  dimension_ = kDefaultDimension;
  elems_ = new double[dimension_];
}

Vector::Vector(double* arr, int n) : dimension_(n) {
  elems_ = new double[dimension_];
  for (int i = 0; i < dimension_; ++i) {
    elems_[i] = arr[i];
  }
}

Vector::Vector(const Vector& other) : dimension_(other.dimension_) {
  // NOTE: in the constructor this is not valid.
  // if (elems_ != nullptr) delete[] elems_;
  elems_ = new double[dimension_];
  for (int i = 0; i < dimension_; ++i) {
    elems_[i] = other.elems_[i];
  }
}

Vector::~Vector() {
  dimension_ = 0;
  if (elems_ != nullptr) delete[] elems_;
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

  for (int i = 0; i < idx; ++i) {
    tmp[i] = elems_[i];
  }
  for (int i = idx + 1; i < dimension_; ++i) {
    tmp[i - 1] = elems_[i];
  }

  delete[] elems_;
  elems_ = tmp;
  --dimension_;
  return true;
}

bool Vector::insert_dimension(int idx, double val) {
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
  double sqr_sum = 0.0;
  for (int i = 0; i < dimension_; ++i) {
    sqr_sum += elems_[i] * elems_[i];
  }
  return sqrt(sqr_sum);
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
  dimension_ = other.dimension_;

  if (elems_ != nullptr) delete[] elems_;
  elems_ = new double[dimension_];

  for (int i = 0; i < dimension_; ++i) {
    elems_[i] = other.elems_[i];
  }
  return *this;
}

Vector& operator+(Vector lhs, const Vector& rhs) {
  return (lhs += rhs);
}

Vector& operator-(Vector lhs, const Vector& rhs) {
  return (lhs -= rhs);
}

// multiplying a scalar and a vector
Vector operator*(double val, const Vector& v) {
  Vector res(v);
  for (int i = 0; i < res.dimension_; ++i) {
    res.elems_[i] *= val;
  }
  return res;
}

Vector& Vector::operator+=(const Vector& other) {
  int smaller_dimension = std::min(other.dimension_, dimension_);
  int res_dimension = std::max(other.dimension_, dimension_);
  
  double* res = new double[res_dimension];
  for (int i = 0; i < res_dimension; ++i) {
    if (i < smaller_dimension) {
      // NOTE: If use "return ((*this) += (-other));" to implement operator-=(),
      // the order of the addition below is very important !!! this->elems[i]
      // must be on the left-hand side of +.
      res[i] = elems_[i] + other.elems_[i];
    } else {
      res[i] = (i >= dimension_ ? other.elems_[i] : elems_[i]);
    }
  }

  delete[] elems_;
  elems_ = res;
  dimension_ = res_dimension;
  return (*this);
}

Vector& Vector::operator-=(const Vector& other) {
  // The solution below works depending on the implementation of operator+=().
  return ((*this) += (-other));
}

// multiplying a vector and a scalar
Vector Vector::operator*(double val) {
  return val * (*this);
}

// internal product
Vector Vector::operator*(const Vector& other) {
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

  return Vector(res, res_dimension);
}

std::ostream& operator<<(std::ostream& out, const Vector& v) {
  out << "v = (";
  for (int i = 0; i < v.dimension_; ++i) {
    if (i) out << ", ";
    out << v.elems_[i];
  }
  out << ")";
  return out;
}
