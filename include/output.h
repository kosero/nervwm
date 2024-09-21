#ifndef NWM_OUTPUT_H
#define NWM_OUTPUT_H

#include <wayland-server-core.h>
#include <wayland-util.h>
#include <wlr/types/wlr_output.h>
#include "server.h"

struct nwm_output {
  struct wl_list link;
  struct nwm_server *server;
  struct wlr_output *wlr_output;
  struct wl_listener frame;
  struct wl_listener request_state;
  struct wl_listener destroy;
};

void output_frame(struct wl_listener *listener, void *data);
void output_request_state(struct wl_listener *listener, void *data);
void server_new_output(struct wl_listener *listener, void *data);

#endif // !NWM_SERVER_H
