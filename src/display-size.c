#include "../include/display-size.h"
#include "../include/includes.h"

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


uint32_t get_display_count(){
  uint32_t          displays_count;
  CGDirectDisplayID displays[8];

  CGGetActiveDisplayList(8, displays, &displays_count);
  return(displays_count);
}


CGDirectDisplayID get_display_id(){
  uint32_t          displays_count;
  CGDirectDisplayID display_id;
  CGDisplayModeRef  display_mode = NULL;

  CGDirectDisplayID displays[8];

  CGGetActiveDisplayList(8, displays, &displays_count);
  display_id = displays[0];
  CGDisplayModeRelease(display_mode);
  return(display_id);
}

