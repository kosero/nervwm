#ifndef KIRANWM_H
#define KIRANWM_H

#include <wayland-server-protocol.h>

struct s_kwm_server {
  struct wl_display *display;
  struct wl_event_loop *event_loop;
  struct wlr_backend *backend;
};

#endif