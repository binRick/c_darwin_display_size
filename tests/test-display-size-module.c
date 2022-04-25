#include "../src/display-size-module.c"


/***************************************/
void DUMP_DISPLAY_SIZE_MODULE(int ID, DISPLAY_SIZE_MODULE ds){
  fprintf(stdout,
          "|Test #%d> "
          "|# displays:%d|"
          "|display_id:%d|"
          "|logger mode:%d|"
          "|width:%fmm|"
          "|height:%fmm|"
          "|\n",
          ID,
          ds->displays_count,
          ds->display_id,
          ds->mode,
          ds->width,
          ds->height
          );
}


/***************************************/


int test_module3(void) {
  module(darwin_display_size) * ds = require(darwin_display_size);
  ds->mode                         = LOGGER_DEBUG;
  ds->set_display_id(0);
  ds->get_display_size();
  DUMP_DISPLAY_SIZE_MODULE(3, ds);
  clib_module_free(ds);
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
