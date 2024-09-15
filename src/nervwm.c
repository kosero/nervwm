#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <wayland-server-core.h>
#include <wlroots-0.19/wlr/backend.h>
#include <wlroots-0.19/wlr/render/allocator.h>
#include <wlroots-0.19/wlr/render/wlr_renderer.h>
#include <wlroots-0.19/wlr/types/wlr_output.h>

struct nwm_output {
    struct timespec last_frame;
    struct nwm_server *server;
    struct wlr_output *wlr_output;
    struct wl_list link;
};

struct nwm_server {
    struct wl_display *wl_display;
    struct wl_event_loop *wl_event_loop;
    struct wlr_backend *backend;
    struct wl_listener new_output;
    struct wl_list outputs;
};

static void new_output_notify(struct wl_listener *listener, void *data) {
    struct nwm_server *server = wl_container_of(listener, server, new_output);
    struct wlr_output *wlr_output = data;
    
    if (!wl_list_empty(&wlr_output->modes)) {
        struct wlr_output_mode *mode = wl_container_of(wlr_output->modes.prev, mode, link);
    }

    struct nwm_output *output = calloc(1, sizeof(struct nwm_output));
    clock_gettime(CLOCK_MONOTONIC, &output->last_frame);
    output->server = server;
    output->wlr_output = wlr_output;
    wl_list_init(&output->link); // Initialize the link list
    wl_list_insert(&server->outputs, &output->link);
}

int main(int argc, char **argv) {
    struct nwm_server server;
    server.wl_display = wl_display_create();
    assert(server.wl_display);
    server.wl_event_loop = wl_display_get_event_loop(server.wl_display);
    assert(server.wl_event_loop);

    server.backend = wlr_backend_autocreate(server.wl_event_loop, NULL);
    assert(server.backend);

    wl_list_init(&server.outputs);

    server.new_output.notify = new_output_notify;
    wl_signal_add(&server.backend->events.new_output, &server.new_output);

    if (!wlr_backend_start(server.backend)) {
        fprintf(stderr, "Failed to start backend\n");
        wl_display_destroy(server.wl_display);
        return 1;
    }

    wl_display_run(server.wl_display);
    wl_display_destroy(server.wl_display);

    return 0;
}

