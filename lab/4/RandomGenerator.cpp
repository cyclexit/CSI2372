#include "RandomGenerator.h"

RandomGenerator::RandomGenerator() {
  s_ = 4;
  len_ = kMinSeqLen;
  modulo_ = fast_pow(10, s_);

  random_seq_ = new int[len_];
  for (int i = 0; i < len_; ++i) {
    random_seq_[i] = rand() % modulo_;
  }
}

RandomGenerator::RandomGenerator(int s, int rnd1, int rnd2) {
  s_ = s;
  len_ = kMinSeqLen;
  modulo_ = fast_pow(10, s_);

  random_seq_ = new int[len_];
  random_seq_[0] = rnd1 % modulo_;
  random_seq_[1] = rnd2 % modulo_;
}

RandomGenerator::RandomGenerator(const RandomGenerator& other) {
  s_ = other.s_;
  len_ = other.len_;
  modulo_ = other.modulo_;

  if (random_seq_ != nullptr) delete[] random_seq_;
  random_seq_ = new int[len_];

  for (int i = 0; i < len_; ++i) {
    random_seq_[i] = other.random_seq_[i];
  }
}

RandomGenerator::~RandomGenerator() {
  s_ = len_ = modulo_ = 0;
  if (random_seq_ != nullptr) delete[] random_seq_;
}

int RandomGenerator::operator[](int idx) const {
  return random_seq_[idx];
}

bool RandomGenerator::operator==(const RandomGenerator& other) {
  if (len_ != other.len_ || s_ != other.s_) return false;

  for (int i = 0; i < len_; ++i) {
    if (random_seq_[i] != other.random_seq_[i]) {
      return false;
    }
  }

  return true;
}

bool RandomGenerator::operator!=(const RandomGenerator& other) {
  // TODO: think this logic twice. It seems alright...
  return !(*this == other);
}

RandomGenerator& RandomGenerator::operator=(const RandomGenerator& other) {
  s_ = other.s_;
  len_ = other.len_;
  modulo_ = other.modulo_;

  if (random_seq_ != nullptr) delete[] random_seq_;
  random_seq_ = new int[len_];

  for (int i = 0; i < len_; ++i) {
    random_seq_[i] = other.random_seq_[i];
  }

  return *this;
}

RandomGenerator operator+(RandomGenerator lhs, RandomGenerator& rhs) {
  return lhs += rhs;
}

RandomGenerator operator-(RandomGenerator lhs, RandomGenerator& rhs) {
  return lhs -= rhs;
}

RandomGenerator operator*(RandomGenerator lhs, RandomGenerator& rhs) {
  return lhs *= rhs;
}

RandomGenerator& RandomGenerator::operator+=(RandomGenerator& other) {
  while (len_ != other.len_) {
    len_ < other.len_ ? operator++() : ++other;
  }

  for (int i = 0; i < len_; ++i) {
    random_seq_[i] = (random_seq_[i] + other.random_seq_[i]) % modulo_;
  }

  return *this;
}

RandomGenerator& RandomGenerator::operator-=(RandomGenerator& other) {
  while (len_ != other.len_) {
    len_ < other.len_ ? operator++() : ++other;
  }

  for (int i = 0; i < len_; ++i) {
    random_seq_[i] = abs(random_seq_[i] + other.random_seq_[i]);
  }

  return *this;
}

RandomGenerator& RandomGenerator::operator++() {
  int* temp = new int[len_ + 1];
  for (int i = 0; i < len_; ++i) {
    temp[i] = random_seq_[i];
  }
  delete[] random_seq_;
  random_seq_ = temp;
  // TODO: do the generation here. Don't use rand here
  random_seq_[len_++] = rand() % modulo_;
  return *this;
}

RandomGenerator RandomGenerator::operator++(int) {
  RandomGenerator old(*this);
  operator++();
  return old;
}

RandomGenerator& RandomGenerator::operator--() {
  if (len_ <= kMinSeqLen) return *this;

  int* temp = new int[len_ - 1];
  for (int i = 0; i < len_ - 1; ++i) {
    temp[i] = random_seq_[i];
  }
  delete[] random_seq_;
  random_seq_ = temp;
  --len_;
  return *this;
}

RandomGenerator RandomGenerator::operator--(int) {
  RandomGenerator old(*this);
  operator--();
  return old;
}

std::ostream& operator<<(std::ostream& out, const RandomGenerator& rng) {
  for (int i = 0; i < rng.len_; ++i) {
    if (i) out << ", ";
    out << rng.random_seq_[i];
  }
}