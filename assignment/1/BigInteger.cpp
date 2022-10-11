#include "BigInteger.h"

/**
 * public
 */

BigInteger::BigInteger() {
  base_ = 10;
  len_ = kInitLen;
  digits_ = new int[len_];
}

BigInteger::BigInteger(int num, int base) {
  base_ = base;
  len_ = calc_len(num, base);
  digits_ = new int[len_];

  if (num == 0) {
    digits_[0] = num;
  } else {
    int i = 0;
    while(num) {
      digits_[i++] = num % base_;
      num /= base_;
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

int BigInteger::num_digits() {
  return len_;
}

bool BigInteger::add_digit(int digit) {
  return insert_digit(digit, len_);
}

void BigInteger::remove_digit() {
  int* temp = new int[len_ - 1];

  for (int i = 0; i < len_ - 1; ++i) {
    temp[i] = digits_[i];
  }

  delete[] digits_;
  digits_ = temp;
  --len_;
}

bool BigInteger::insert_digit(int digit, int pos) {
  if (pos > len_) return false;

  int* temp = new int[len_ + 1];
  if (temp == nullptr) return false;

  for (int i = 0; i < pos; ++i) {
    temp[i] = digits_[i];
  }
  temp[pos] = digit;
  for (int i = pos; i < len_; ++i) {
    temp[i + 1] = digits_[i];
  }

  delete[] digits_;
  digits_ = temp;
  ++len_;
  return true;
}

/**
 * private
 */

// Convert the value for a signle digit in the range [0, 35] to the char
// representation 0, 1, ..., 9, A, B, ..., Z.
char BigInteger::int_to_digit(int digit) {
  if (digit < 10) {
    return '0' + digit;
  } else {
    return 'A' + (digit - 10) % 26;
  }
}

// Calculate the digit length of the num with the given base.
int BigInteger::calc_len(int num, int base) {
  if (num == 0) return 1;

  int res = 0;
  while (num) {
    ++res;
    num /= base;
  }
  return res;
}
