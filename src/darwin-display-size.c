#include "../src/display-size-module.c"


DarwinDisplaySize *get_darwin_display_size(uint32_t id){
  DarwinDisplaySize *DDS = malloc(sizeof(struct DarwinDisplaySize));

  module(darwin_display_size) * ds = require(darwin_display_size);
  ds->set_display_id(id);
  ds->get_display_size();
  DDS->width  = ds->width;
  DDS->height = ds->height;
  clib_module_free(ds);
  return(DDS);
}
