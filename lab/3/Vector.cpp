#include "Vector.h"

Vector::Vector() {
  dimension_ = kDefaultDimension;
  elems_ = new double[dimension_];
}
