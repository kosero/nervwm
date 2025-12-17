#include <wlr/util/log.h>

#include "kwm_server.h"

int main(int argc, char **argv) {
  wlr_log_init(WLR_DEBUG, NULL);

  struct s_kwm_server server = {0};

  if (!kwm_server_init(&server)) {
    wlr_log(WLR_ERROR, "Failed to initialize KiranWM server.");
    kwm_server_finish(&server);
    return 1;
  }

  wlr_log(WLR_INFO, "KiranWM is running!");

  kwm_server_finish(&server);
  return 0;
}
