#ifndef FINAL_IMAGE_H_
#define FINAL_IMAGE_H_

class Image {
 public:
  static constexpr int kDefaultWidth = 128;
  static constexpr int kDefaultHeight = 128;
  static constexpr int kDefaultIntensity = 0;

  Image();
  Image(int w, int h, int inten);

  Image operator-(const Image& other);
  Image operator+(const Image& other);
  Image operator++();
  Image operator++(int);
  Image operator--();
  Image operator--(int);

  bool sub_image(const Image& other);

 protected:
  int width;
  int height;
  int intensity;
};

#endif // FINAL_IMAGE_H_