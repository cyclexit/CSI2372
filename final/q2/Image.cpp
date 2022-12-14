#include "Image.h"

Image::Image() : 
    width(kDefaultWidth),
    height(kDefaultHeight),
    intensity(kDefaultIntensity) {}

Image::Image(int w, int h, int inten) :
    width(w),
    height(h),
    intensity(inten) {}

Image::Image(const Image& other) :
    width(other.width),
    height(other.height),
    intensity(other.intensity) {}

bool Image::same_size(const Image& other) const {
  return (width == other.width) && (height == other.height);
}

Image Image::operator-(const Image& other) const {
  if (!same_size(other)) return *this;

  Image res(other);
  

  return res;
}
