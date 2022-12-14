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
  FuzzySet<T> res;

  for (pair<T, double> p : fuzzy) {
    if (p.second == 0) continue;
    if (other.fuzzy.count(p.first) == 1) {
      double value = p.second - other.fuzzy[p.first];
      if (value > 0.0) {
        res[p.first] = value;
      }
    }
  }

  return res;
}

template<typename T>
FuzzySet<T> FuzzySet<T>::operator==(const FuzzySet<T>& other) const {
  if (fuzzy.size() != other.fuzzy.size()) return false;

  for (pair<T, double> p : fuzzy) {
    if (other.fuzzy[p.first] != p.second) {
      return false;
    }
  }
  return true;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const FuzzySet<T>& fz) {
  out << "{";
  bool flag = true;
  for (pair<T, double> p : fz.fuzzy) {
    if (flag) {
      flag = false;
    } else {
      out << ", ";
    }
    out << "(" << p.first << ", " << p.second ")";
  }
  out << "}";
  return out;
}
