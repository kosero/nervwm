#define _POSIX_C_SOURCE 200809L
#include <assert.h>
#include <getopt.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <wayland-server-core.h>
#include <wlroots-0.19/wlr/backend.h>
#include <wlr/render/allocator.h>
#include <wlr/render/wlr_renderer.h>

struct nwm_server
{
    struct wl_display *wl_display;
    struct wl_event_loop *wl_event_loop;

    struct wlr_backend *backend;
};

int main(int argc, char **argv)
{
    struct nwm_server server;

    server.wl_display = wl_display_create();
    assert(server.wl_display);
    server.wl_event_loop = wl_display_get_event_loop(server.wl_display);
    assert(server.wl_event_loop);

    server.backend = wlr_backend_autocreate(wl_display_get_event_loop(server.wl_display), NULL);
    assert(server.backend);

    if (!wlr_backend_start(server.backend)) {
        fprintf(stderr, "Failed to start backend\n");
        wl_display_destroy(server.wl_display);
        return 1;
    }

    wl_display_run(server.wl_display);
    wl_display_destroy(server.wl_display);

    return 0;
}

