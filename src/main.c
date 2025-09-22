#include "kwm_server.h"
#include <wlr/util/log.h>

int main(int argc, char **argv) {
  wlr_log_init(WLR_DEBUG, NULL);

  struct s_kwm_server server = {0};

  if (!kwm_server_init(&server)) {
    wlr_log(WLR_ERROR, "Failed to initialize KiranWM server.");
    kwm_server_fini(&server);
    return 1;
  }

  // TODO: Add the Wayland socket, start the backend, run the event loop,

  wlr_log(
      WLR_INFO,
      "KiranWM is running! (Currently not starting the backend or event loop)");

  kwm_server_fini(&server);
  return 0;
}
