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


