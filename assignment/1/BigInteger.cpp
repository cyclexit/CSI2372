#include "BigInteger.h"

/**
 * public
 */

BigInteger::BigInteger() {
  base_ = 10;
  len_ = kInitLen;
  digits_ = new int[len_];
}

BigInteger::BigInteger(int val, int base) {
  base_ = base;
  len_ = calc_len(val, base);
  digits_ = new int[len_];

  if (val == 0) {
    digits_[0] = val;
  } else {
    int i = 0;
    while(val) {
      digits_[i++] = val % base_;
      val /= base_;
    }
  }
}

BigInteger::BigInteger(const BigInteger& other) {
  base_ = other.base_;
  len_ = other.len_;
  digits_ = new int[len_];

  for (int i = 0; i < len_; ++i) {
    digits_[i] = other.digits_[i];
  }
}

BigInteger::~BigInteger() {
  len_ = 0;
  if (digits_ != nullptr) delete[] digits_;
}

/**
 * private
 */

// Convert the value for a signle digit in the range [0, 35] to the char
// representation 0, 1, ..., 9, A, B, ..., Z.
char BigInteger::int_to_digit(int d) {
  if (d < 10) {
    return '0' + d;
  } else {
    return 'A' + (d - 10) % 26;
  }
}

// Calculate the digit length of the val with the given base.
int BigInteger::calc_len(int val, int base) {
  if (val == 0) return 1;

  int res = 0;
  while (val) {
    ++res;
    val /= base;
  }
  return res;
}
