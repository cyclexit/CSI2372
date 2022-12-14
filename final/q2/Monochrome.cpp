#include "Monochrome.h"

Monochrome::Monochrome() : Image() {
  intensity %= kMaxIntensity;
  for (int h = 0; h < height; ++h) {
    for (int w = 0; w < width; ++w) {
      pixels[h][w] = intensity;
    }
  }
}

Monochrome::Monochrome(int w, int h, int inten) : Image(w, h, inten) {
  intensity %= kMaxIntensity;
  for (int h = 0; h < height; ++h) {
    for (int w = 0; w < width; ++w) {
      pixels[h][w] = intensity;
    }
  }
}

Monochrome::Monochrome(const Monochrome& other) : Image(other) {
  intensity %= kMaxIntensity;
  for (int h = 0; h < height; ++h) {
    for (int w = 0; w < width; ++w) {
      pixels[h][w] = intensity;
    }
  }
}

Image Monochrome::operator+(const Image& other) const {
  if (!same_size(other)) return *this;

  Image res(*this);
  for (int h = 0; h < height; ++h) {
    for (int w = 0; w < width; ++w) {
      res.pixels[h][w] += other.pixels[h][w];
      res.pixels[h][w] %= kMaxIntensity;
    }
  }

  return res;
}

Image Monochrome::operator++() {
  
}

Image Monochrome::operator++(int) {

}
