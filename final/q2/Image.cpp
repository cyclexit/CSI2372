#include "Image.h"

Image::Image() : 
    height(kDefaultHeight),
    width(kDefaultWidth),
    intensity(kDefaultIntensity) {
  pixels.resize(height, vector<int>(width, intensity));
}

Image::Image(int w, int h, int inten) :
    height(h),
    width(w),
    intensity(inten) {
  pixels.resize(height, vector<int>(width, intensity));
}

Image::Image(const Image& other) :
    height(other.height),
    width(other.width),
    intensity(other.intensity) {
  pixels.clear();
  pixels.resize(height, vector<int>(width, 0));
  for (int h = 0; h < height; ++h) {
    for (int w = 0; w < width; ++w) {
      pixels[h][w] = other.pixels[h][w];
    }
  }
}

bool Image::same_size(const Image& other) const {
  return (width == other.width) && (height == other.height);
}

Image Image::operator-(const Image& other) const {
  if (!same_size(other)) return *this;

  Image res(*this);
  for (int h = 0; h < height; ++h) {
    for (int w = 0; w < width; ++w) {
      res.pixels[h][w] -= other.pixels[h][w];
      res.pixels[h][w] = max(res.pixels[h][w], 0);
    }
  }

  return res;
}

Image Image::operator+(const Image& other) const {
  if (!same_size(other)) return *this;

  Image res(*this);
  for (int h = 0; h < height; ++h) {
    for (int w = 0; w < width; ++w) {
      res.pixels[h][w] += other.pixels[h][w];
    }
  }

  return res;
}

Image Image::operator++() {
  Image res(*this);
  for (int h = 0; h < height; ++h) {
    for (int w = 0; w < width; ++w) {
      ++pixels[h][w];
    }
  }
}

Image Image::operator++(int) {
  Image old(*this);
  operator++();
  return old;
}

Image Image::operator--() {
  Image res(*this);
  for (int h = 0; h < height; ++h) {
    for (int w = 0; w < width; ++w) {
      --pixels[h][w];
      pixels[h][w] = max(0, pixels[h][w]);
    }
  }
}

Image Image::operator--(int) {
  Image old(*this);
  operator--();
  return old;
}
