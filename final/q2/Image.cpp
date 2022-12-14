#include "Image.h"

Image::Image() : width(kDefaultWidth), height(kDefaultHeight), intensity(kDefaultIntensity) {}

Image::Image(int w, int h, int inten) : width(w), height(h), intensity(inten) {}


