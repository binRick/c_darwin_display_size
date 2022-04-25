#include "../src/display-size.c"


int main(int argc, const char *argv[]){
  CGDirectDisplayID              display_id = get_display_id();
  struct DarwinDisplayResolution *res       = get_display_resolution(display_id);

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

