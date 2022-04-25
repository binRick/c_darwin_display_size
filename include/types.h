#ifndef DARWIN_DISPLAY_TYPES
#define DARWIN_DISPLAY_TYPES
#include "../include/base-includes.h"

struct DarwinDisplayResolution {
  size_t x, y;
  CGSize size;
  int    pixels;
};

#endif
