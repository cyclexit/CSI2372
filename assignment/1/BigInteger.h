#ifndef CSI2372_ASSIGNMENT_1_BIG_INTEGER_H_
#define CSI2372_ASSIGNMENT_1_BIG_INTEGER_H_

#include <algorithm>
#include <iostream>

class BigInteger {
 public:
  // ctors and dtors
  BigInteger();
  BigInteger(int num, int base);
  BigInteger(const BigInteger& other);
  ~BigInteger();

  // methods
  int num_digits(); // done
  bool add_digit(int digit); // done
  void remove_digit(); // done
  bool insert_digit(int digit, int pos); // done

  // operators
  char operator[](int pos) const; // done
  // comparison operators
  bool operator==(const BigInteger& other);
  bool operator>(const BigInteger& other);
  bool operator<(const BigInteger& other);
  bool operator>=(const BigInteger& other);
  bool operator<=(const BigInteger& other);
  bool operator!=(const BigInteger& other);
  // arithmetic operators
  BigInteger& operator=(const BigInteger& other);
  // addition with int
  BigInteger& operator+=(int num); // done
  friend BigInteger operator+(BigInteger big_num, int num); // done
  friend BigInteger operator+(int num, BigInteger big_num); // done
  // addition with BigInteger
  BigInteger& operator+=(const BigInteger& other);
  BigInteger operator+(const BigInteger& other);
  // multiplication with int
  BigInteger& operator*=(int num);
  friend BigInteger operator*(BigInteger big_num, int num);
  friend BigInteger operator*(int num, BigInteger big_num);
  // multiplication with BigInteger
  BigInteger& operator*=(const BigInteger& other);
  BigInteger operator*(const BigInteger& other);
  // input and output operators
  friend std::ostream& operator<<(std::ostream& out, const BigInteger& big_num);

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
  static int calc_len(int num, int base);
  int to_base_10() const;
};

#endif // CSI2372_ASSIGNMENT_1_BIG_INTEGER_H_
