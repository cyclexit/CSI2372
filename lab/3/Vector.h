#ifndef LAB_3_VECTOR_H_
#define LAB_3_VECTOR_H_

#include <iostream>
#include <limits>

class Vector {
 public:
  // ctors and dtors
  Vector();
  Vector(double* arr, int n);
  Vector(const Vector& other);
  ~Vector();

  // methods
  int dimension();
  bool add_dimension(double val);
  bool remove_dimension(int idx);
  bool insert_dimension(double val, int idx);
  double magnitude();

  // operators
  double operator[](int idx);
  bool operator==(const Vector& other);
  bool operator!=(const Vector& other);
  Vector& operator=(const Vector& other);
  friend Vector& operator+(Vector lhs, const Vector& rhs);
  Vector& operator-(const Vector& other);
  friend Vector& operator*(double val, const Vector& v); // multiplying a scalar and a vector
  Vector& operator+=(const Vector& other);
  Vector& operator-=(const Vector& other);
  Vector& operator*(const Vector& other); // multiplying a vector and a scalar
  friend std::ostream& operator<<(std::ostream& out, const Vector& v);

 private:
  static constexpr int kDefaultDimension = 2;
  static constexpr double kInvalidValue = std::numeric_limits<double>::max();
  double* elems_;
  int dimension_;
};

constexpr Vector operator*(const Vector& lhs, const Vector& rhs);

#endif // LAB_3_VECTOR_H_
