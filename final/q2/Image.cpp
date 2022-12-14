#include "Image.h"

Image::Image() : 
    height(kDefaultHeight),
    width(kDefaultWidth),
    intensity(kDefaultIntensity) {
  pixels.resize(height, vector<int>(width, intensity));
}

Image::Image(int h, int w, int inten) :
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
  for (int h = 0; h < height; ++h) {
    for (int w = 0; w < width; ++w) {
      ++pixels[h][w];
    }
  }
  return *this;
}

Image Image::operator++(int) {
  Image old(*this);
  operator++();
  return old;
}

Image Image::operator--() {
  for (int h = 0; h < height; ++h) {
    for (int w = 0; w < width; ++w) {
      --pixels[h][w];
      pixels[h][w] = max(0, pixels[h][w]);
    }
  }
  return *this;
}

Image Image::operator--(int) {
  Image old(*this);
  operator--();
  return old;
}

bool Image::sub_image(const Image& other) const {
  // current image is larger than the other image in width or height
  if (width > other.width || height > other.height) return false;

  bool found = false;
  for (int h = 0; h < other.height; ++h) {
    if (found) break;
    if (h + height > other.height) break;

    for (int w = 0; w < other.width; ++w) {
      if (w + width > other.width) break;

      bool flag = true;
      for (int i = 0; i < height; ++i) {
        if (!flag) break;
        for (int j = 0; j < width; ++j) {
          if (pixels[i][j] != other.pixels[h + i][w + j]) {
            flag = false;
            break;
          }
        }
      }
      found = flag;
    }
  }

  return found;
}
