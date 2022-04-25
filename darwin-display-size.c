#include "./src/darwin-display-size.c"

#define DISPLAY_ID 0 // First Display

int main(const int argc, const char **argv) {
  DarwinDisplaySize *dds = get_darwin_display_size(DISPLAY_ID);

  fprintf(stdout,
          "%fx%f mm\n",
          dds->width,
          dds->height
          );

  free(dds);
  return(0);
}
