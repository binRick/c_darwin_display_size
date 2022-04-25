#include "../include/module-includes.h"
#include "../src/display-size.c"

enum channel_status {
  CHANNEL_STATUS_ERROR  = -1,
  CHANNEL_STATUS_NONE   = 0,
  CHANNEL_STATUS_OPEN   = 1,
  CHANNEL_STATUS_CLOSED = 2,
};

enum darwin_display_size_mode {
  LOGGER_NONE,
  LOGGER_INFO,
  LOGGER_ERROR,
  LOGGER_DEBUG,
};

// Module Type Interface
module(darwin_display_size) {
  define(darwin_display_size, CLIB_MODULE);

  enum darwin_display_size_mode mode;

  void                          (*info)(char *);
  void                          (*debug)(char *);
  void                          (*error)(char *);
};

int
darwin_display_size_init(module(darwin_display_size) *exports);

void
darwin_display_size_deinit(module(darwin_display_size) *exports);

// Default Module Exports
exports(darwin_display_size) {
  .mode   = LOGGER_NONE,
  .init   = darwin_display_size_init,
  .deinit = darwin_display_size_deinit,
};


void darwin_display_size_deinit(module(darwin_display_size) *exports) {
  clib_module_deinit(darwin_display_size);
}


static inline void darwin_display_size_info(char *message) {
  if (require(darwin_display_size)->mode >= LOGGER_INFO) {
    fprintf(stdout, " info: %s\n", message);
  }
}


static inline void darwin_display_size_error(char *message) {
  if (require(darwin_display_size)->mode >= LOGGER_ERROR) {
    fprintf(stderr, "error: %s\n", message);
  }
}


static inline void darwin_display_size_debug(char *message) {
  if (require(darwin_display_size)->mode >= LOGGER_DEBUG) {
    fprintf(stderr, "debug: %s\n", message);
  }
}


int darwin_display_size_init(module(darwin_display_size) *exports) {
  clib_module_init(darwin_display_size, exports);
  exports->mode  = LOGGER_NONE;
  exports->info  = darwin_display_size_info;
  exports->error = darwin_display_size_error;
  exports->debug = darwin_display_size_debug;
  return(0);
}

