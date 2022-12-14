#ifndef FINAL_MONOCHROME_H_
#define FINAL_MONOCHROME_H_

#include "Image.h"

class Monochrome : public Image {
 public:
  static constexpr int kMaxIntensity = 255;

  Monochrome();
  Monochrome(int w, int h, int inten);
  Monochrome(const Monochrome& other);
  ~Monochrome() = default;

  Image operator+(const Image& other) const override;
  Image operator++() override;
  Image operator++(int) override;

};

#endif // FINAL_MONOCHROME_H_
