#include "../src/display-size-module.c"


int main(const int argc, const char **argv) {
  darwin_display_size *dds = init_darwin_display_size();

  dds->set_display_id(0);
  dds->get_display_size();
  fprintf(stdout,
          "%fx%f mm\n",
          dds->width,
          dds->height
          );
  clib_module_free(dds);
  return(0);
}
