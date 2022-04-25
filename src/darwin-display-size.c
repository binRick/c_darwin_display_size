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

#ifdef DARWIN_DISPLAY_AUTO_INIT
DarwinDisplaySize *dds;

void __init__() __attribute__((constructor));

void __attribute__((destructor)) __de_init__();


void __init__() {
  dds = get_darwin_display_size(DISPLAY_ID);
}


void __de_init__() {
  free(dds);
}
#endif
