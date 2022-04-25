#include "../src/display-size-module.c"


/***************************************/
void DUMP_DISPLAY_SIZE_MODULE(int ID, darwin_display_size *dds){
  fprintf(stdout,
          "|Test #%d> "
          "|# displays:%d|"
          "|display_id:%d|"
          "|logger mode:%d|"
          "|width:%fmm|"
          "|height:%fmm|"
          "|\n",
          ID,
          dds->displays_count,
          dds->display_id,
          dds->mode,
          dds->width,
          dds->height
          );
}
