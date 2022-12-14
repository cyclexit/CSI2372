#ifndef FINAL_IMAGE_H_
#define FINAL_IMAGE_H_

#include <vector>

using namespace std;

class Image {
 public:
  static constexpr int kDefaultHeight = 128;
  static constexpr int kDefaultWidth = 128;
  static constexpr int kDefaultIntensity = 0;

  Image();
  Image(int w, int h, int inten);
  Image(const Image& other);
  ~Image() = default;

  bool same_size(const Image& other) const;

  Image operator-(const Image& other) const;
  Image operator+(const Image& other) const;
  Image operator++();
  Image operator++(int);
  Image operator--();
  Image operator--(int);

  bool sub_image(const Image& other) const;

 protected:
  int height;
  int width;
  int intensity;

  vector<vector<int>> pixels;
};

#endif // FINAL_IMAGE_H_