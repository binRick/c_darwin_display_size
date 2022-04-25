#include "../src/display-size.c"


int main(int argc, const char *argv[]){
  uint32_t          displays_count;
  CGDirectDisplayID display_id;
  CGDisplayModeRef  display_mode = NULL;

  CGDirectDisplayID displays[8];

  CGGetActiveDisplayList(8, displays, &displays_count);
  display_id = displays[0];

  struct DarwinDisplayResolution *res = get_display_resolution(display_id);

  CGDisplayModeRelease(display_mode);

  fprintf(stdout,
          "x:%zu|y:%zu|pixels:%d|width:%fmm|height:%fmm|\n",
          res->x,
          res->y,
          res->pixels,
          res->size.width,
          res->size.height
          );
  return(0);
}

