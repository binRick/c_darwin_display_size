#include "../src/display-size-module.c"
#include "../tests/utils.c"


int main(const int argc, const char **argv) {
  module(darwin_display_size) * ds = require(darwin_display_size);
  ds->mode                         = LOGGER_NONE;
  ds->set_display_id(0);
  ds->get_display_size();
  DUMP_DISPLAY_SIZE_MODULE(3, ds);
  clib_module_free(ds);
  return(0);
}
