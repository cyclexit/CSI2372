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

bool BigInteger::operator==(const BigInteger& other) {
  if (base_ != other.base_) {
    // TODO: implement this case
    return false;
  } else {
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
    if (len_ != other.len_) return len_ < other.len_;
    for (int i = len_ - 1; i >= 0; --i) {
      if (digits_[i] > other.digits_[i]) {
        return false;
      }
    }
    return true;
  }
}

bool BigInteger::operator!=(const BigInteger& other) {
  return !operator==(other);
}

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

BigInteger& BigInteger::operator+=(int num) {
  BigInteger big_num(num, base_);
  // TODO: 
  // 1. check the sign of num and this object
  // 2. if the sign is different, use -= with -num
  //    if the sign is the same, go ahead
  // 3. determine the sign of this object

  int slen = std::min(len_, big_num.len_);
  int llen = std::max(len_, big_num.len_);
  int* temp = new int[llen];

  // simply add each digit
  for (int i = 0; i < slen; ++i) {
    temp[i] = digits_[i] + big_num.digits_[i];
  }
  for (int i = slen; i < llen; ++i) {
    temp[i] = len_ < big_num.len_ ? big_num.digits_[i] : digits_[i];
  }

  // check if the most significant digit has overflow
  // and change the data members here
  if (temp[llen] >= base_) {
    delete[] digits_;
    len_ = llen + 1;
    digits_ = new int[len_];
    for (int i = 0; i < llen; ++i) {
      digits_[i] = temp[i];
    }
    delete[] temp;
  } else {
    delete[] digits_;
    len_ = llen;
    digits_ = temp;
  }

  // deal with carry
  for (int i = 0; i < len_ - 1; ++i) {
    if (digits_[i] >= base_) {
      digits_[i + 1] += digits_[i] / base_;
      digits_[i] %= base_;
    }
  }

  return *this;
}

BigInteger operator+(BigInteger big_num, int num) {
  return big_num += num;
}

BigInteger operator+(int num, BigInteger big_num) {
  return big_num += num;
}

BigInteger& BigInteger::operator+=(const BigInteger& other) {
  return *this;
}

BigInteger operator+(BigInteger lhs, const BigInteger& rhs) {
  return lhs += rhs;
}

BigInteger& BigInteger::operator-=(int num) {
  return *this;
}

BigInteger operator-(BigInteger big_num, int num) {
  return big_num -= num;
}

BigInteger operator-(int num, BigInteger big_num) {
  return big_num -= num;
}

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
