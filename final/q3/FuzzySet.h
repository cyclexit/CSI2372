#ifndef FINAL_FUZZYSET_H_
#define FINAL_FUZZYSET_H_

#include <iostream>
#include <map>
#include <utility>

using namespace std;

template<typename T>
class FuzzySet;

template<typename T>
std::ostream& operator<<(std::ostream& out, const FuzzySet<T>& fz);

template<typename T>
class FuzzySet {
 public:
  FuzzySet();
  FuzzySet(const FuzzySet<T>& other);
  ~FuzzySet() = default;

  FuzzySet intersection(const FuzzySet& other);
  FuzzySet operator+(const FuzzySet& other) const;
  FuzzySet operator-(const FuzzySet& other) const;
  FuzzySet operator==(const FuzzySet& other) const;

  friend std::ostream& operator<< <> (std::ostream& out, const FuzzySet<T>& fz);

 private:
  map<T, double> fuzzy;
};

#endif // FINAL_FUZZYSET_H_