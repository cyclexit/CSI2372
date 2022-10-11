#ifndef LAB_4_RANDOM_GENERATOR_H_
#define LAB_4_RANDOM_GENERATOR_H_

#include <cmath>
#include <cstdlib>
#include <iostream>

template<typename T>
T fast_pow(T base, T pow) {
  T res = 1;
  while (pow) {
    if (pow & 1) res = res * base;
    base = base * base;
    pow >>= 1;
  }
  return res;
}

class RandomGenerator {
 public:
  // ctors and dtors
  RandomGenerator();
  RandomGenerator(int s, int rnd1, int rnd2);
  RandomGenerator(const RandomGenerator& other);
  ~RandomGenerator();

  // operators
  int operator[](int idx) const;
  bool operator==(const RandomGenerator& other);
  bool operator!=(const RandomGenerator& other);
  RandomGenerator& operator=(const RandomGenerator& other);
  friend RandomGenerator operator+(RandomGenerator lhs, RandomGenerator& rhs);
  friend RandomGenerator operator-(RandomGenerator lhs, RandomGenerator& rhs);
  friend RandomGenerator operator*(RandomGenerator lhs, RandomGenerator& rhs);
  RandomGenerator& operator+=(RandomGenerator& other);
  RandomGenerator& operator-=(RandomGenerator& other);
  RandomGenerator& operator*=(RandomGenerator& other);
  RandomGenerator& operator++();
  RandomGenerator operator++(int);
  RandomGenerator& operator--();
  RandomGenerator operator--(int);
  friend std::ostream& operator<<(std::ostream& out, const RandomGenerator& rng);

 private:
  static constexpr int kMinSeqLen = 2;
  int s_, len_, modulo_;
  int* random_seq_;
};

#endif // LAB_4_RANDOM_GENERATOR_H_
