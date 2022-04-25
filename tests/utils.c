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
