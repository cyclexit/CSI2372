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
  if (len_ == 0) return;

  int* temp = new int[len_ - 1];
  for (int i = 1; i < len_; ++i) {
    temp[i - 1] = digits_[i];
  }

  delete[] digits_;
  digits_ = temp;
  --len_;
}

// NOTE: pos is indexed from the least significant digit.
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
bool BigInteger::operator==(const BigInteger& other) const {
  BigInteger same_base = to_same_base(other);

  if (is_negative_ ^ same_base.is_negative_) return false;
  if (len_ != same_base.len_) return false;
  for (int i = 0; i < len_; ++i) {
    if (digits_[i] != same_base.digits_[i]) {
      return false;
    }
  }
  return true;
}
bool BigInteger::operator==(int num) const {
  return operator==(BigInteger(num, base_));
}

bool BigInteger::operator>(const BigInteger& other) const {
  return !operator<=(other);
}
bool BigInteger::operator>(int num) const {
  return operator>(BigInteger(num, base_));
}

bool BigInteger::operator<(const BigInteger& other) const {
  return operator<=(other) && operator!=(other);
}
bool BigInteger::operator<(int num) const {
  return operator<(BigInteger(num, base_));
}

bool BigInteger::operator>=(const BigInteger& other) const {
  return operator>(other) || operator==(other);
}
bool BigInteger::operator>=(int num) const {
  return operator>=(BigInteger(num, base_));
}

bool BigInteger::operator<=(const BigInteger& other) const {
  BigInteger same_base = to_same_base(other);

  if (is_negative_ && !same_base.is_negative_) return true;
  if (!is_negative_ && same_base.is_negative_) return false;
  bool both_negative = is_negative_ && same_base.is_negative_;
  if (len_ != same_base.len_) return (len_ < same_base.len_) ^ both_negative;
  for (int i = len_ - 1; i >= 0; --i) {
    if (digits_[i] > same_base.digits_[i]) {
      return false ^ both_negative;
    }
  }
  return true ^ both_negative;
}
bool BigInteger::operator<=(int num) const {
  return operator<=(BigInteger(num, base_));
}

bool BigInteger::operator!=(const BigInteger& other) const {
  return !operator==(other);
}
bool BigInteger::operator!=(int num) const {
  return operator!=(BigInteger(num, base_));
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
  // NOTE: commutative law for addition
  return big_num += num;
}

// addition with BigInteger
BigInteger& BigInteger::operator+=(const BigInteger& other) {
  BigInteger same_base = to_same_base(other);

  if (is_negative_ ^ same_base.is_negative_) {
    // different sign
    if (abs_less_than(same_base)) is_negative_ = !is_negative_;
    digit_wise_sub(same_base);
  } else {
    // same sign
    digit_wise_add(same_base);
  }

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
  BigInteger res = BigInteger(num, big_num.base_);
  res = res - big_num;
  return res;
}

// subtraction with BigInteger
BigInteger& BigInteger::operator-=(const BigInteger& other) {
  // NOTE: no need to convert the base here
  //       the base is converted in operator+=
  BigInteger flip_sign(other);
  flip_sign.is_negative_ = !other.is_negative_;
  return operator+=(flip_sign);
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
  return BigInteger(num, big_num.base_) *= big_num;
}

// multiplication with BigInteger
BigInteger& BigInteger::operator*=(const BigInteger& other) {
  BigInteger same_base = to_same_base(other);
  is_negative_ ^= same_base.is_negative_;

  int* temp = new int[same_base.len_ + len_];
  // NOTE: init all values to 0 for a safe play
  for (int i = 0; i < same_base.len_ + len_; ++i) {
    temp[i] = 0;
  }

  for (int i = 0; i < len_; ++i) {
    for (int j = 0; j < same_base.len_; ++j) {
      temp[i + j] += digits_[i] * same_base.digits_[j];
    }
  }

  // deal with carry
  for (int i = 0; i < len_ + same_base.len_ - 1; ++i) {
    temp[i + 1] += temp[i] / base_;
    temp[i] %= base_;
  }

  delete[] digits_;
  digits_ = temp;
  len_ += same_base.len_;
  if (digits_[len_ - 1] == 0) --len_;

  return *this;
}

BigInteger operator*(BigInteger lhs, const BigInteger& rhs) {
  return lhs *= rhs;
}

// ++ operators
BigInteger& BigInteger::operator++() {
  operator+=(1);
  return *this;
}

BigInteger BigInteger::operator++(int) {
  BigInteger old(*this);
  operator++();
  return old;
}

// -- opeartors
BigInteger& BigInteger::operator--() {
  operator-=(1);
  return *this;
}

BigInteger BigInteger::operator--(int) {
  BigInteger old(*this);
  operator--();
  return old;
}

// input and output operators
std::ostream& operator<<(std::ostream& out, const BigInteger& big_num) {
  if (big_num.is_negative_) out << "-";
  for (int i = big_num.len_ - 1; i >= 0; --i) {
    out << big_num[i];
  }
  return out;
}

std::istream& operator>>(std::istream& in, BigInteger& big_num) {
  std::string str;
  int base;
  in >> str >> base;

  // validate the digits in str
  bool base_matched = true;
  for (int i = 0; i < str.size(); ++i) {
    int d = BigInteger::digit_to_int(str[i]);
    if (d == -1) {
      std::cout << "Fatal Error (Hongyi Lin) : Input contains invalid character, the parsing result will be invalid" << std::endl;
    } else if (d >= base) {
      base = d + 1;
    }
  }
  if (!base_matched) {
    std::cout << "Error: base not matched!" << std::endl;
  }

  // parse the values
  big_num = BigInteger(0, base);
  big_num += BigInteger::digit_to_int(str[0]);
  for (int i = 1; i < str.size(); ++i) {
    big_num *= big_num.base_;
    big_num += BigInteger::digit_to_int(str[i]);
  }
  return in;
}

// bonus operators

// division with int
BigInteger& BigInteger::operator/=(int num) {
  if (num == 0) throw("Math Error: divided by zero!");

  BigInteger other(num, base_);
  if (abs_less_than(other)) return *this = BigInteger(0, base_);
  // deal with sign here
  is_negative_ ^= other.is_negative_;
  other.is_negative_ = false;
  digit_wise_div(other);

  return *this;
}

BigInteger operator/(BigInteger big_num, int num) {
  return big_num /= num;
}

BigInteger operator/(int num, BigInteger big_num) {
  return BigInteger(num, big_num.base_) /= big_num;
}

// division with BigInteger
BigInteger& BigInteger::operator/=(const BigInteger& other) {
  if (other == 0) throw("Math Error: divided by zero!");

  BigInteger same_base = to_same_base(other);
  if (abs_less_than(same_base)) return *this = BigInteger(0, base_);
  // deal with sign here
  is_negative_ ^= same_base.is_negative_;
  same_base.is_negative_ = false;
  digit_wise_div(same_base);

  return *this;
}

BigInteger operator/(BigInteger lhs, const BigInteger& rhs) {
  return lhs /= rhs;
}

// mod with int
// NOTE: The mod logic is the same with the C++ primitive signed mod, especially
//       mod with negative values. Basically speaking, C++ mod has two features:
//       1. The result sign is the same as the left-hand side.
//       2. Then, do the modulo with the abs values of two numbers.
BigInteger& BigInteger::operator%=(int num) {
  if (num == 0) throw("Math Error: modulo by zero!");

  BigInteger other(num, base_);
  other.is_negative_ = false;
  bool old_sign = is_negative_;
  digit_wise_mod(other);
  is_negative_ = old_sign;

  return *this;
}

BigInteger operator%(BigInteger big_num, int num) {
  return big_num %= num;
}

BigInteger operator%(int num, BigInteger big_num) {
  return BigInteger(num, big_num.base_) %= big_num;
}

// mod with BigInteger
BigInteger& BigInteger::operator%=(const BigInteger& other) {
  if (other == 0) throw("Math Error: modulo by zero!");

  BigInteger same_base = to_same_base(other);
  same_base.is_negative_ = false;
  bool old_sign = is_negative_;
  digit_wise_mod(same_base);
  is_negative_ = old_sign;

  return *this;
}

BigInteger operator%(BigInteger lhs, const BigInteger& rhs) {
  return lhs %= rhs;
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

int BigInteger::digit_to_int(char digit) {
  if ('0' <= digit && digit <= '9') {
    return digit - '0';
  } else if ('A' <= digit && digit <= 'Z') {
    return digit - 'A' + 10;
  } else {
    return -1;
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
  // NOTE: init all values to 0 for a safe play
  for (int i = 0; i <= longer_len; ++i) {
    temp[i] = 0;
  }

  // simply add each digit from Least Significant Digit
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
  // NOTE: init all values to 0 for a safe play
  for (int i = 0; i < longer_len; ++i) {
    temp[i] = 0;
  }

  // simply subtract each digit from Least Significant Digit
  // NOTE: use the one with bigger abs value to avoid underflow
  if (abs_less_than(other)) {
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

// other: should have the same base as (*this), and should be POSITIVE(+)!
// Don't deal with sign in this function
// Sign is resolved in arithmetic operators
void BigInteger::digit_wise_div(const BigInteger& other) {
  // digit-wise div with abs value
  BigInteger temp(0, base_);
  // find the starting position
  int idx = len_ - 1;
  while (idx >= 0 && temp.abs_less_than(other)) {
    if (idx != len_ - 1) temp *= base_;
    temp += digits_[idx];
    if (temp.abs_less_than(other)) --idx;
  }
  // calculate the result
  int res_len = idx + 1;
  int* res = new int[res_len];
  for ( ; idx >= 0; --idx) {
    int q = base_ - 1;
    while (temp.abs_less_than(other * q)) --q;
    temp -= q * other;
    res[idx] = q;
    if (idx) {
      temp *= base_;
      temp += digits_[idx - 1];
    }
  }

  len_ = res_len;
  delete[] digits_;
  digits_ = res;
}

// other: should have the same base as (*this), and should be POSITIVE(+)!
// Don't deal with sign in this function
// Sign is resolved in arithmetic operators
void BigInteger::digit_wise_mod(const BigInteger& other) {
  // digit-wise div with abs value
  BigInteger temp(0, base_);
  // find the starting position
  int idx = len_ - 1;
  while (idx >= 0 && temp.abs_less_than(other)) {
    if (idx != len_ - 1) temp *= base_;
    temp += digits_[idx];
    if (temp.abs_less_than(other)) --idx;
  }
  // calculate the result
  for ( ; idx >= 0; --idx) {
    int q = base_ - 1;
    while (temp.abs_less_than(other * q)) --q;
    temp -= q * other;
    if (idx) {
      temp *= base_;
      temp += digits_[idx - 1];
    }
  }

  *this = temp;
}

// other: should have the same base as (*this)
bool BigInteger::abs_less_than(const BigInteger& other) {
  if (len_ != other.len_) return len_ < other.len_;
  for (int i = len_ - 1; i >= 0; --i) {
    if (digits_[i] < other.digits_[i]) {
      return true;
    }
  }
  return false;
}

// NOTE: in my opinion, this function is the key of this assignment
// Sign is handled in this funcion
BigInteger BigInteger::to_same_base(const BigInteger& other) const {
  BigInteger res(0, base_);
  // transform the abs value
  res += other.digits_[other.len_ - 1];
  for (int i = other.len_ - 2; i >= 0; --i) {
    res *= other.base_;
    res += other.digits_[i];
  }
  // make the sign correct
  res.is_negative_ = other.is_negative_;
  return res;
}
