#include "../src/display-size-module.c"


int main(const int argc, const char **argv) {
  module(darwin_display_size) *ds = require(darwin_display_size);
  ds->set_display_id(0);
  ds->get_display_size();
  fprintf(stdout,
          "%fx%f mm\n",
          ds->width,
          ds->height
          );
  clib_module_free(ds);
  return(0);
}
