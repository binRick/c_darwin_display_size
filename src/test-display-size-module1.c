#include "../src/display-size-module1.c"


int main(void) {
  module(darwin_display_size) * darwin_display_size = require(darwin_display_size);

  darwin_display_size->mode = LOGGER_DEBUG;
  darwin_display_size->info("hello");
  darwin_display_size->error("oops");
  darwin_display_size->debug("help");

  clib_module_free(darwin_display_size);
  return(0);
}
