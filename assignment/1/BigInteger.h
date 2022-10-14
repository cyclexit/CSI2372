#ifndef CSI2372_ASSIGNMENT_1_BIG_INTEGER_H_
#define CSI2372_ASSIGNMENT_1_BIG_INTEGER_H_

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>

class BigInteger {
 public:
  // ctors and dtors
  BigInteger();
  BigInteger(int num, int base);
  BigInteger(const BigInteger& other);
  ~BigInteger();

  // methods
  int num_digits();
  bool add_digit(int digit);
  void remove_digit();
  bool insert_digit(int digit, int pos);

  // operators
  char operator[](int pos) const;
  // comparison operators
  bool operator==(const BigInteger& other);
  bool operator>(const BigInteger& other);
  bool operator<(const BigInteger& other);
  bool operator>=(const BigInteger& other);
  bool operator<=(const BigInteger& other);
  bool operator!=(const BigInteger& other);
  // assignment operators
  BigInteger& operator=(const BigInteger& other);
  BigInteger& operator=(int num);
  // addition with int
  BigInteger& operator+=(int num);
  friend BigInteger operator+(BigInteger big_num, int num);
  friend BigInteger operator+(int num, BigInteger big_num);
  // addition with BigInteger
  BigInteger& operator+=(const BigInteger& other);
  friend BigInteger operator+(BigInteger lhs, const BigInteger& rhs);
  // subtraction with int
  BigInteger& operator-=(int num);
  friend BigInteger operator-(BigInteger big_num, int num);
  friend BigInteger operator-(int num, BigInteger big_num);
  // subtraction with BigInteger
  BigInteger& operator-=(const BigInteger& other);
  friend BigInteger operator-(BigInteger lhs, const BigInteger& rhs);
  // multiplication with int
  BigInteger& operator*=(int num);
  friend BigInteger operator*(BigInteger big_num, int num);
  friend BigInteger operator*(int num, BigInteger big_num);
  // multiplication with BigInteger
  BigInteger& operator*=(const BigInteger& other);
  friend BigInteger operator*(BigInteger lhs, const BigInteger& rhs);
  // ++ operators
  BigInteger& operator++();
  BigInteger operator++(int);
  // -- opeartors
  BigInteger& operator--();
  BigInteger operator--(int);
  // input and output operators
  friend std::ostream& operator<<(std::ostream& out, const BigInteger& big_num);
  friend std::istream& operator>>(std::istream& in, BigInteger& big_num);

  // bonus operators (do it when I have time...)
  // division with int
  BigInteger& operator/=(int num);
  friend BigInteger operator/(BigInteger big_num, int num);
  friend BigInteger operator/(int num, BigInteger big_num);
  // division with BigInteger
  BigInteger& operator*=(const BigInteger& other);
  friend BigInteger operator*(BigInteger lhs, const BigInteger& rhs);
  // mod with int
  BigInteger& operator%=(int num);
  friend BigInteger operator%(BigInteger big_num, int num);
  friend BigInteger operator%(int num, BigInteger big_num);
  // mod with BigInteger
  BigInteger& operator%=(const BigInteger& other);
  friend BigInteger operator%(BigInteger lhs, const BigInteger& rhs);

 private:
  // data member
  bool is_negative_;
  int base_;
  int len_;
  // Most significant digit index: (len_ - 1)
  // Least significant digit index: 0
  int* digits_; // possible values: [0, 35]

  // helper function
  static char int_to_digit(int digit);
  static int digit_to_int(char digit);
  static int calc_len(int num, int base);
  static int* calc_digits(int num, int base);
  void digit_wise_add(const BigInteger& other);
  void digit_wise_sub(const BigInteger& other);
  bool abs_less_than(const BigInteger& other);
  BigInteger to_same_base(const BigInteger& other);
};

#endif // CSI2372_ASSIGNMENT_1_BIG_INTEGER_H_
