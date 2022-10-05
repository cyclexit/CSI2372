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
  int res = 0;
  while (base) {
    ++res;
    val /= base;
  }
}
