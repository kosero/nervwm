#ifndef NWM_SERVER_H
#define NWM_SERVER_H

#include <wayland-server-core.h>

struct nwm_server {
  struct wl_display *wl_display;
	struct wlr_backend *backend;
	struct wlr_renderer *renderer;
	struct wlr_allocator *allocator;
	struct wlr_scene *scene;
	struct wlr_scene_output_layout *scene_layout;

	struct wlr_output_layout *output_layout;
	struct wl_list outputs;
	struct wl_listener new_output; 
};

#endif // !NWM_SERVER_H
