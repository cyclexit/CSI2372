#ifndef FINAL_IMAGE_H_
#define FINAL_IMAGE_H_

#include <algorithm>
#include <vector>

using namespace std;

class Image {
 public:
  static constexpr int kDefaultHeight = 128;
  static constexpr int kDefaultWidth = 128;
  static constexpr int kDefaultIntensity = 0;

  Image();
  Image(int h, int w, int inten);
  Image(const Image& other);
  ~Image() = default;

  bool same_size(const Image& other) const;
  int get_pixel(int h, int w) const;

  Image operator-(const Image& other) const;
  virtual Image operator+(const Image& other) const;
  virtual Image operator++();
  virtual Image operator++(int);
  Image operator--();
  Image operator--(int);

  bool sub_image(const Image& other) const;

 protected:
  int height; // number of rows
  int width; // number of columns
  int intensity;

  vector<vector<int>> pixels;
};

#endif // FINAL_IMAGE_H_