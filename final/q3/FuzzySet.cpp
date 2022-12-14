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

}

template<typename T>
FuzzySet<T> FuzzySet<T>::operator+(const FuzzySet<T>& other) const {

}

template<typename T>
FuzzySet<T> FuzzySet<T>::operator-(const FuzzySet<T>& other) const {

}

template<typename T>
FuzzySet<T> FuzzySet<T>::operator==(const FuzzySet<T>& other) const {
  
}
