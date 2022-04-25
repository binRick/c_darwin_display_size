#define DISPLAY_ID                  0 // First Display
#define DARWIN_DISPLAY_AUTO_INIT      // automatically initialize display dds
#include "../src/darwin-display-size.c"


int main(const int argc, const char **argv) {
  fprintf(stdout,
          "%fx%f mm\n",
          dds->width,
          dds->height
          );
  return(0);
}
