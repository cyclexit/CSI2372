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
    if (other.fuzzy.count(p.first) == 1) {
      res.fuzzy[p.first] = min(p.second, other.fuzzy[p.first]);
    }
  }

  return res;
}

template<typename T>
FuzzySet<T> FuzzySet<T>::operator+(const FuzzySet<T>& other) const {

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
