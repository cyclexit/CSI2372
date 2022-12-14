#include "Monochrome.h"

Monochrome::Monochrome() : Image() {
  intensity %= kMaxIntensity;
  for (int h = 0; h < height; ++h) {
    for (int w = 0; w < width; ++w) {
      pixels[h][w] = intensity;
    }
  }
}

Monochrome::Monochrome(int h, int w, int inten) : Image(h, w, inten) {
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

  Monochrome res(*this);
  for (int h = 0; h < height; ++h) {
    for (int w = 0; w < width; ++w) {
      res.pixels[h][w] += other.get_pixel(h, w);
      res.pixels[h][w] %= kMaxIntensity;
    }
  }

  return res;
}

Image Monochrome::operator++() {
  for (int h = 0; h < height; ++h) {
    for (int w = 0; w < width; ++w) {
      ++pixels[h][w];
      pixels[h][w] %= kMaxIntensity;
    }
  }
  return *this;
}

Image Monochrome::operator++(int) {
  Image old(*this);
  operator++();
  return old;
}
