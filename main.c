#include <ApplicationServices/ApplicationServices.h>
#include <stdio.h>
#include <stdlib.h>

struct DarwinDisplayResolution {
  size_t x, y;
  CGSize size;
  int    pixels;
};

struct DarwinDisplayResolution * get_display_resolution(CGDirectDisplayID display_id);


int main(int argc, const char *argv[]){
  uint32_t          displays_count;
  CGDirectDisplayID display_id;
  CGDisplayModeRef  display_mode = NULL;

  CGDirectDisplayID displays[8];

  CGGetActiveDisplayList(8, displays, &displays_count);
  display_id = displays[0];

  struct DarwinDisplayResolution *res = get_display_resolution(display_id);

  CGDisplayModeRelease(display_mode);

  fprintf(stdout,
          "> x:%zu|y:%zu|pixels:%d|width:%fmm|height:%fmm|\n",
          res->x,
          res->y,
          res->pixels,
          res->size.width,
          res->size.height
          );
  return(0);
}


struct DarwinDisplayResolution * get_display_resolution(CGDirectDisplayID display_id){
  CGDisplayModeRef mode, current_mode; CFArrayRef mode_list;

  mode_list    = CGDisplayCopyAllDisplayModes(display_id, NULL);
  current_mode = CGDisplayCopyDisplayMode(display_id);
  mode         = (CGDisplayModeRef)CFArrayGetValueAtIndex(mode_list, 0);

  struct DarwinDisplayResolution *res = malloc(sizeof(struct DarwinDisplayResolution));

  res->x      = CGDisplayModeGetWidth(mode);
  res->y      = CGDisplayModeGetHeight(mode);
  res->pixels = res->x * res->y;
  res->size   = CGDisplayScreenSize(display_id);

  CFRelease(current_mode);
  CFRelease(mode_list);
  return(res);
}

