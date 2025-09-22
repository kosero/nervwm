#include "kwm_server.h"
#include <wlr/backend.h>
#include <wlr/render/allocator.h>
#include <wlr/render/wlr_renderer.h>
#include <wlr/util/log.h>

int kwm_server_init(struct s_kwm_server *server) {
  wlr_log(WLR_INFO, "Initializing KiranWM server...");

  server->display = wl_display_create();
  if (!server->display) {
    wlr_log(WLR_ERROR, "Failed to create Wayland display");
    return 1;
  }
  wlr_log(WLR_INFO, "Wayland display created successfully.");

  server->event_loop = wl_display_get_event_loop(server->display);
  if (!server->event_loop) {
    wlr_log(WLR_ERROR, "Failed to get event loop");
    return 1;
  }
  wlr_log(WLR_INFO, "Event loop obtained successfully.");

  server->backend = wlr_backend_autocreate(server->event_loop, NULL);
  if (!server->backend) {
    wlr_log(WLR_ERROR, "Failed to create wlr_backend");
    return 1;
  }
  wlr_log(WLR_INFO, "wlroots backend created successfully.");

  server->renderer = wlr_renderer_autocreate(server->backend);
  if (!server->renderer) {
    wlr_log(WLR_ERROR, "Failed to create wlr_renderer");
    return 1;
  }
  wlr_log(WLR_INFO, "wlroots renderer created successfully.");

  wlr_renderer_init_wl_display(server->renderer, server->display);

  server->allocator =
      wlr_allocator_autocreate(server->backend, server->renderer);
  if (!server->allocator) {
    wlr_log(WLR_ERROR, "Failed to create wlr_allocator");
    return 1;
  }
  wlr_log(WLR_INFO, "wlroots allocator created successfully.");

  wlr_log(WLR_INFO, "KiranWM server initialized successfully.");
  return true;
}

void kwm_server_fini(struct s_kwm_server *server) {
  wlr_log(WLR_INFO, "Cleaning up KiranWM server...");

  if (server->allocator) {
    wlr_allocator_destroy(server->allocator);
    wlr_log(WLR_INFO, "Allocator destroyed.");
  }
  if (server->renderer) {
    wlr_renderer_destroy(server->renderer);
    wlr_log(WLR_INFO, "Renderer destroyed.");
  }
  if (server->backend) {
    wlr_backend_destroy(server->backend);
    wlr_log(WLR_INFO, "Backend destroyed.");
  }
  if (server->display) {
    wl_display_destroy_clients(server->display);
    wl_display_destroy(server->display);
    wlr_log(WLR_INFO, "Wayland display and clients destroyed.");
  }

  wlr_log(WLR_INFO, "KiranWM server cleanup complete.");
}
