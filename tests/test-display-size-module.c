#include "../src/display-size-module.c"
#include "../tests/utils.c"


int test_module3(void) {
  darwin_display_size *dds = init_darwin_display_size();

  dds->mode = LOGGER_NONE;
  dds->set_display_id(0);
  dds->get_display_size();
  DUMP_DISPLAY_SIZE_MODULE(3, dds);
  clib_module_free(dds);
  return(0);
}


int test_module2(void) {
  module(darwin_display_size) * ds = require(darwin_display_size);
  ds->mode                         = LOGGER_DEBUG;
  assert(ds->mode == LOGGER_DEBUG);
  assert(ds->set_display_id(0) == 1);
  assert(ds->get_display_size() == 1);
  assert(ds->width > 0);
  assert(ds->height > 0);
  DUMP_DISPLAY_SIZE_MODULE(2, ds);
  clib_module_free(ds);
  return(0);
}


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

  assert(ds->set_display_id(ds->displays_count) == -1);
  assert(ds->get_display_size() == -1);

  assert(ds->set_display_id(0) == 1);
  assert(ds->get_display_size() == 1);

  assert(ds->width > 0);
  assert(ds->height > 0);

  DUMP_DISPLAY_SIZE_MODULE(1, ds);

  clib_module_free(ds);
  return(0);
}


int main(void) {
  assert(test_module1() == 0);
  assert(test_module2() == 0);
  assert(test_module3() == 0);

  return(0);
}
