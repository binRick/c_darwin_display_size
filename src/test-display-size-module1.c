#include "../src/display-size-module1.c"


int test_module1(void) {
  module(darwin_display_size) * ds = require(darwin_display_size);

  assert(ds);
  assert(ds->displays_count > 0);

  assert(ds->mode == LOGGER_NONE);

  ds->mode = LOGGER_INFO;
  assert(ds->mode == LOGGER_INFO);

  ds->mode = LOGGER_DEBUG;
  assert(ds->mode == LOGGER_DEBUG);

  assert(ds->width == -1);
  assert(ds->height == -1);
  assert(ds->display_id == -1);

  assert(ds->set_display_id(0));
  assert(ds->set_display_id(ds->displays_count) == -1);

  assert(ds->get_display_size());

  assert(ds->width > 0);
  assert(ds->height > 0);

  fprintf(stdout,
          "|"
          "|# displays:%d|"
          "|display_id:%d|"
          "|logger mode:%d|"
          "|width:%fmm|"
          "|height:%fmm|"
          "|\n"
          , ds->displays_count
          , ds->display_id
          , ds->mode
          , ds->width
          , ds->height
          );

  clib_module_free(ds);
  return(0);
} /* main */


int main(void) {
  assert(test_module1() == 0);

  return(0);
}
