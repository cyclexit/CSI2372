#ifndef CSI2372_ASSIGNMENT_1_BIG_INTEGER_H_
#define CSI2372_ASSIGNMENT_1_BIG_INTEGER_H_

class BigInteger {
 public:

  // ctors and dtors

  BigInteger();
  BigInteger(int num, int base);
  BigInteger(const BigInteger& other);
  ~BigInteger();

  // methods

  int num_digits();

  // NOTE: check if d < base
  bool add_digit(int digit);

  void remove_digit();

  bool insert_digit(int digit, int pos);

  // operators

  char operator[](int pos);
  // TODO: base conversion with BigInteger itself
  bool operator==(const BigInteger& other);
  bool operator>(const BigInteger& other);
  bool operator<(const BigInteger& other);
  bool operator>=(const BigInteger& other);
  bool operator<=(const BigInteger& other);
  bool operator!=(const BigInteger& other);

 private:

  // data member

  static constexpr int kInitLen = 32;
  int base_;
  int len_;
  // Most significant digit index: 0
  // Least significant digit index: (len_ - 1)
  int* digits_; // possible values: [0, 35]

  static char int_to_digit(int digit);
  static int calc_len(int num, int base);
  int to_base_10() const;
};

#endif // CSI2372_ASSIGNMENT_1_BIG_INTEGER_H_
