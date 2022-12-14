#include "FuzzySet.h"

template<typename T>
FuzzySet<T>::FuzzySet() {
  // empty map by default
}

template<typename T>
FuzzySet<T>::FuzzySet(const FuzzySet<T>& other) :
    fuzzy(other.fuzzy) {}

template<typename T>
FuzzySet<T> FuzzySet<T>::intersection(const FuzzySet<T>& other) {
  FuzzySet<T> res;

  for (pair<T, double> p : fuzzy) {
    if (p.second == 0) continue;
    if (other.fuzzy.count(p.first) == 1) {
      if (other.fuzzy[p.first] > 0) {
        res.fuzzy[p.first] = min(p.second, other.fuzzy[p.first]);
      }
    }
  }

  return res;
}

template<typename T>
FuzzySet<T> FuzzySet<T>::operator+(const FuzzySet<T>& other) const {
  FuzzySet<T> res;

  for (pair<T, double> p : fuzzy) {
    res.fuzzy[p.first] = p.second;
  }

  for (pair<T, double> p : other.fuzzy) {
    res.fuzzy[p.first] = max(res.fuzzy[p.first], p.second);
  }

  return res;
}

template<typename T>
FuzzySet<T> FuzzySet<T>::operator-(const FuzzySet<T>& other) const {

}

template<typename T>
FuzzySet<T> FuzzySet<T>::operator==(const FuzzySet<T>& other) const {
  for (pair<T, double> p : fuzzy) {
    if (other.fuzzy[p.first] != p.second) {
      return false;
    }
  }
  return true;
}
