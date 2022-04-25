#include "../src/display-size-module.c"


int main(const int argc, const char **argv) {
  module(darwin_display_size) * ds = require(darwin_display_size);
  ds->mode                         = LOGGER_NONE;
  ds->set_display_id(0);
  ds->get_display_size();
  fprintf(stdout,
          "|> "
          "|# displays:%d|"
          "|display_id:%d|"
          "|logger mode:%d|"
          "|width:%fmm|"
          "|height:%fmm|"
          "|\n",
          ds->displays_count,
          ds->display_id,
          ds->mode,
          ds->width,
          ds->height
  );
  clib_module_free(ds);
  return(0);
}
