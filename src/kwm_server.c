#include <wlr/backend.h>
#include <wlr/render/wlr_renderer.h>
#include <wlr/types/wlr_data_device.h>
#include <wlr/types/wlr_output_layout.h>
#include <wlr/types/wlr_subcompositor.h>
#include <wlr/util/log.h>
#include <wlr/types/wlr_scene.h>

#include "kwm_server.h"
#include "output.h"

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


  wlr_compositor_create(server->display, 5, server->renderer);
  wlr_subcompositor_create(server->display);
  wlr_data_device_manager_create(server->display);

  server->output_layout = wlr_output_layout_create(server->display);

  wl_list_init(&server->outputs);
  server->new_output.notify = server_new_output;
  wl_signal_add(&server->backend->events.new_output, &server->new_output);

  server->scene = wlr_scene_create();
  server->scene_layout =
      wlr_scene_attach_output_layout(server->scene, server->output_layout);

  wlr_log(WLR_INFO, "KiranWM server initialized successfully.");
  return true;
}

void kwm_server_finish(struct s_kwm_server *server) {
  wlr_log(WLR_INFO, "Cleaning up KiranWM server...");
  wl_list_remove(&server->new_output.link);

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
