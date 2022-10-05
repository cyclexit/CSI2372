#ifndef CSI2371_ASSIGNMENT_1_BIG_INTEGER_H_
#define CSI2371_ASSIGNMENT_1_BIG_INTEGER_H_

class BigInteger {
 public:
  // ctors and dtors
  BigInteger();
  BigInteger(int val, int base);
  BigInteger(const BigInteger& other);
  ~BigInteger();

 private:
  char* digits_;
  int len_;
  int base_;
};

#endif // CSI2371_ASSIGNMENT_1_BIG_INTEGER_H_