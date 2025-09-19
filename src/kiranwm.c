#include "kiranwm.h"
#include "wlr/backend.h"
#include <assert.h>
#include <wayland-server-core.h>

int main(int argc, char **argv) {
  struct s_kwm_server server;

  server.display = wl_display_create();
  assert(server.display);

  server.event_loop = wl_display_get_event_loop(server.display);
  assert(server.event_loop);

  server.backend =
      wlr_backend_autocreate(wl_display_get_event_loop(server.display), NULL);
  assert(server.backend);

  return 0;
}
