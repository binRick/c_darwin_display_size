#ifndef DARWIN_DISPLAY_TYPES
#define DARWIN_DISPLAY_TYPES
#include "../include/base-includes.h"

struct DarwinDisplayResolution {
  size_t x, y;
  CGSize size;
  int    pixels;
};

typedef struct DarwinDisplaySize DarwinDisplaySize;
struct DarwinDisplaySize {
  double width; double height;
};

#endif
