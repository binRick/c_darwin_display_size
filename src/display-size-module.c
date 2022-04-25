#include "../include/module-includes.h"
#include "../src/display-size.c"


enum darwin_display_size_logger_mode {
  LOGGER_NONE,
  LOGGER_INFO,
  LOGGER_ERROR,
  LOGGER_DEBUG,
};

// Module Type Interface
module(darwin_display_size) {
  define(darwin_display_size, CLIB_MODULE);

  enum darwin_display_size_logger_mode mode;
  uint32_t                             displays_count;
  struct DarwinDisplayResolution       *resolution;
  double                               width;
  double                               height;
  int                                  display_id;

  int                                  (*get_display_size)();
  int                                  (*set_display_id)(uint32_t);
};

int darwin_display_size_init(module(darwin_display_size) *exports);

void darwin_display_size_deinit(module(darwin_display_size) *exports);

// Default Module Exports
exports(darwin_display_size) {
  .mode           = LOGGER_NONE,
  .displays_count = -1,
  .width          = -1,
  .height         = -1,
  .display_id     = -1,
  .init           = darwin_display_size_init,
  .deinit         = darwin_display_size_deinit,
};


void darwin_display_size_deinit(module(darwin_display_size) *exports) {
  if (require(darwin_display_size)->mode >= LOGGER_DEBUG) {
    fprintf(stderr, "deinit.....\n");
  }
  clib_module_deinit(darwin_display_size);
}


static inline int set_display_id(uint32_t id) {
  if (id < (require(darwin_display_size)->displays_count)) {
    require(darwin_display_size)->display_id = id;
    return(1);
  }
  return(-1);
}


static inline int __get_display_size() {
  if (require(darwin_display_size)->display_id < 0) {
    return(-1);
  }

  if (require(darwin_display_size)->mode >= LOGGER_DEBUG) {
    fprintf(stderr, "getting size of display #%d.....\n", require(darwin_display_size)->display_id);
  }
  require(darwin_display_size)->resolution = get_display_resolution(get_display_id(require(darwin_display_size)->display_id));
  require(darwin_display_size)->width      = require(darwin_display_size)->resolution->size.width;
  require(darwin_display_size)->height     = require(darwin_display_size)->resolution->size.height;
  return(1);
}


int darwin_display_size_init(module(darwin_display_size) *exports) {
  clib_module_init(darwin_display_size, exports);
  if (exports->displays_count == -1) {
    fprintf(stderr, "getting display count.....\n");
    exports->displays_count = get_display_count();
  }
  assert(exports->displays_count > 0);

  exports->width            = -1;
  exports->height           = -1;
  exports->mode             = LOGGER_NONE;
  exports->get_display_size = __get_display_size;
  exports->set_display_id   = set_display_id;
  return(0);
}

typedef module(darwin_display_size) *DISPLAY_SIZE_MODULE;
