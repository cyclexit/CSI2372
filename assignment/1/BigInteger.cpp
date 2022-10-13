#include "BigInteger.h"

/**
 * public
 */

BigInteger::BigInteger() {
  is_negative_ = false;
  base_ = 10;
  len_ = 1;
  digits_ = new int[len_]{0};
}

BigInteger::BigInteger(int num, int base) {
  is_negative_ = num < 0;
  num = abs(num);
  base_ = base;
  len_ = calc_len(num, base);
  digits_ = calc_digits(num, base_);
}

BigInteger::BigInteger(const BigInteger& other) {
  is_negative_ = other.is_negative_;
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
  return insert_digit(digit, 0);
}

void BigInteger::remove_digit() {
  int* temp = new int[len_ - 1];

  for (int i = 1; i < len_; ++i) {
    temp[i - 1] = digits_[i];
  }

  delete[] digits_;
  digits_ = temp;
  --len_;
}

bool BigInteger::insert_digit(int digit, int pos) {
  if (pos > len_) return false;
  // NOTE: if digit >= base, the insertion is invalid.
  if (digit >= base_) return false;

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

char BigInteger::operator[](int pos) const {
  return int_to_digit(digits_[pos]);
}

// comparison operators
bool BigInteger::operator==(const BigInteger& other) {
  if (base_ != other.base_) {
    // TODO: implement this case
    return false;
  } else {
    if (is_negative_ ^ other.is_negative_) return false;
    if (len_ != other.len_) return false;
    for (int i = 0; i < len_; ++i) {
      if (digits_[i] != other.digits_[i]) {
        return false;
      }
    }
    return true;
  }
}

bool BigInteger::operator>(const BigInteger& other) {
  return !operator<=(other);
}

bool BigInteger::operator<(const BigInteger& other) {
  return operator<=(other) && operator!=(other);
}

bool BigInteger::operator>=(const BigInteger& other) {
  return operator>(other) || operator==(other);
}

bool BigInteger::operator<=(const BigInteger& other) {
  if (base_ != other.base_) {
    // TODO: implement this case
    return false;
  } else {
    if (is_negative_ && !other.is_negative_) return true;
    if (!is_negative_ && other.is_negative_) return false;
    bool both_negative = is_negative_ && other.is_negative_;
    if (len_ != other.len_) return (len_ < other.len_) ^ both_negative;
    for (int i = len_ - 1; i >= 0; --i) {
      if (digits_[i] > other.digits_[i]) {
        return false ^ both_negative;
      }
    }
    return true ^ both_negative;
  }
}

bool BigInteger::operator!=(const BigInteger& other) {
  return !operator==(other);
}

// assignment operators
BigInteger& BigInteger::operator=(const BigInteger& other) {
  is_negative_ = other.is_negative_;
  base_ = other.base_;
  len_ = other.len_;

  if (digits_ != nullptr) delete[] digits_;
  digits_ = new int[len_];

  for (int i = 0; i < len_; ++i) {
    digits_[i] = other.digits_[i];
  }

  return *this;
}

BigInteger& BigInteger::operator=(int num) {
  is_negative_ = num < 0;
  num = abs(num);
  len_ = calc_len(num, base_);
  delete[] digits_;
  digits_ = calc_digits(num, base_);
  return *this;
}

// addition with int
BigInteger& BigInteger::operator+=(int num) {
  // 1. check the sign of num and this object
  // 2. (1) if the sign is different, digit-wise sub
  //    and determine the sign of this object;
  //    (2) if the sign is the same, digit-wise add
  BigInteger other(num, base_);

  if (is_negative_ ^ other.is_negative_) {
    // different sign
    if (abs_less_than(other)) is_negative_ = !is_negative_;
    digit_wise_sub(other);
  } else {
    // same sign
    digit_wise_add(other);
  }

  return *this;
}

BigInteger operator+(BigInteger big_num, int num) {
  return big_num += num;
}

BigInteger operator+(int num, BigInteger big_num) {
  return big_num += num;
}

// addition with BigInteger
BigInteger& BigInteger::operator+=(const BigInteger& other) {
  // TODO: implement this
  return *this;
}

BigInteger operator+(BigInteger lhs, const BigInteger& rhs) {
  return lhs += rhs;
}

// subtraction with int
BigInteger& BigInteger::operator-=(int num) {
  return operator+=(-num);
}

BigInteger operator-(BigInteger big_num, int num) {
  return big_num -= num;
}

BigInteger operator-(int num, BigInteger big_num) {
  return big_num -= num;
}

// subtraction with BigInteger
BigInteger& BigInteger::operator-=(const BigInteger& other) {
  // TODO: implement this
  return *this;
}

BigInteger operator-(BigInteger lhs, const BigInteger& rhs) {
  return lhs -= rhs;
}

// multiplication with int
BigInteger& BigInteger::operator*=(int num) {
  BigInteger other(num, base_);
  is_negative_ ^= other.is_negative_;

  int* temp = new int[other.len_ + len_];
  for (int i = 0; i < other.len_ + len_; ++i) {
    temp[i] = 0;
  }
  for (int i = 0; i < len_; ++i) {
    for (int j = 0; j < other.len_; ++j) {
      temp[i + j] += digits_[i] * other.digits_[j];
    }
  }

  // deal with carry
  for (int i = 0; i < len_ + other.len_ - 1; ++i) {
    temp[i + 1] += temp[i] / base_;
    temp[i] %= base_;
  }

  delete[] digits_;
  digits_ = temp;
  len_ += other.len_;
  if (digits_[len_ - 1] == 0) --len_;

  return *this;
}

BigInteger operator*(BigInteger big_num, int num) {
  return big_num *= num;
}

BigInteger operator*(int num, BigInteger big_num) {
  return big_num *= num;
}

// multiplication with BigInteger
BigInteger& BigInteger::operator*=(const BigInteger& other) {
  // TODO: implement this
  return *this;
}

BigInteger operator*(BigInteger lhs, const BigInteger& rhs) {
  return lhs *= rhs;
}

// input and output operators
std::ostream& operator<<(std::ostream& out, const BigInteger& big_num) {
  if (big_num.is_negative_) out << "-";
  for (int i = big_num.len_ - 1; i >= 0; --i) {
    out << big_num.digits_[i];
  }
  return out;
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

// num: should be positive
int* BigInteger::calc_digits(int num, int base) {
  int* res = new int[calc_len(num, base)];

  if (num == 0) {
    res[0] = num;
  } else {
    int i = 0;
    while (num) {
      res[i++] = num % base;
      num /= base;
    }
  }

  return res;
}

// other: should have the same base as (*this)
// Don't deal with sign in this function
// Sign is resolved in arithmetic operators
void BigInteger::digit_wise_add(const BigInteger& other) {
  int shorter_len = std::min(len_, other.len_);
  int longer_len = std::max(len_, other.len_);
  // reserve one more digit for potential carry
  int* temp = new int[longer_len + 1];

  // simply add each digit
  for (int i = 0; i < shorter_len; ++i) {
    temp[i] = digits_[i] + other.digits_[i];
  }
  for (int i = shorter_len; i < longer_len; ++i) {
    temp[i] = len_ < other.len_ ? other.digits_[i] : digits_[i];
  }

  // deal with carry
  for (int i = 0; i < longer_len; ++i) {
    if (temp[i] >= base_) {
      temp[i + 1] += temp[i] / base_;
      temp[i] %= base_;
    }
  }

  // assgin
  len_ = longer_len + (temp[longer_len] > 0);
  delete[] digits_;
  digits_ = temp;
}

// other: should have the same base as (*this)
// Don't deal with sign in this function
// Sign is resolved in arithmetic operators
void BigInteger::digit_wise_sub(const BigInteger& other) {
  int shorter_len = std::min(len_, other.len_);
  int longer_len = std::max(len_, other.len_);
  int* temp = new int[longer_len];

  // simply subtract each digit
  if (operator<(other)) {
    for (int i = 0; i < shorter_len; ++i) {
      temp[i] = other.digits_[i] - digits_[i];
    }
  } else {
    for (int i = 0; i < shorter_len; ++i) {
      temp[i] = digits_[i] - other.digits_[i];
    }
  }
  for (int i = shorter_len; i < longer_len; ++i) {
    temp[i] = len_ < other.len_ ? other.digits_[i] : digits_[i];
  }

  // deal with borrow
  for (int i = 0; i < longer_len; ++i) {
    if (temp[i] < 0) {
      --temp[i + 1];
      temp[i] += base_;
    }
  }

  // assgin
  len_ = longer_len - (temp[longer_len - 1] == 0);
  delete[] digits_;
  digits_ = temp;
}

bool BigInteger::abs_less_than(const BigInteger& other) {
  if (len_ != other.len_) return len_ < other.len_;
  for (int i = len_ - 1; i >= 0; --i) {
    if (digits_[i] > other.digits_[i]) {
      return false;
    }
  }
  return true;
}
