#include "../src/display-size-module.c"


DarwinDisplaySize *get_darwin_display_size(uint32_t id){
  DarwinDisplaySize   *DDS = malloc(sizeof(struct DarwinDisplaySize));
  darwin_display_size *dds = init_darwin_display_size();

  dds->set_display_id(id);
  dds->get_display_size();
  DDS->width  = dds->width;
  DDS->height = dds->height;
  clib_module_free(dds);
  return(DDS);
}
