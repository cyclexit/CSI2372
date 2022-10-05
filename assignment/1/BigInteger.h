#ifndef CSI2372_ASSIGNMENT_1_BIG_INTEGER_H_
#define CSI2372_ASSIGNMENT_1_BIG_INTEGER_H_

class BigInteger {
 public:
  // ctors and dtors
  BigInteger();
  BigInteger(int val, int base);
  BigInteger(const BigInteger& other);
  ~BigInteger();

 private:
  // data member
  static constexpr int kInitLen = 32;
  int base_;
  int len_;
  int* digits_; // possible values: [0, 35]

  static char int_to_digit(int d);
  static int calc_len(int val, int base);
};

#endif // CSI2372_ASSIGNMENT_1_BIG_INTEGER_H_
