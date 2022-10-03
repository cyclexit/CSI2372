#ifndef LAB_3_VECTOR_H_
#define LAB_3_VECTOR_H_

#include <iostream>

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
  Vector& operator+(const Vector& other);
  Vector& operator-(const Vector& other);
  Vector& operator+=(const Vector& other);
  Vector& operator-=(const Vector& other);
  Vector& operator*(double val);
  Vector& operator*(const Vector& other);
  friend std::ostream& operator<<(std::ostream& out, const Vector& v);

 private:
  double* elems_;
  int sz_;
};

constexpr Vector operator*(Vector lhs, const Vector& rhs);

#endif // LAB_3_VECTOR_H_