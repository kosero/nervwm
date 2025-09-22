#ifndef KIRANWM_H
#define KIRANWM_H

#include <wayland-server.h>
#include <wlr/render/allocator.h>
#include <wlr/render/wlr_renderer.h>

struct s_kwm_server {
  struct wl_display *display;
  struct wl_event_loop *event_loop;
  struct wlr_backend *backend;
  struct wlr_renderer *renderer;
  struct wlr_allocator *allocator;
};

int kwm_server_init(struct s_kwm_server *server);
void kwm_server_fini(struct s_kwm_server *server);

#endif
