#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <wlr/types/wlr_output.h>

#include "output.h"
#include "server.h"

void new_output_notify(struct wl_listener *listener, void *data) {
    struct nwm_server *server = wl_container_of(listener, server, new_output);
    struct wlr_output *wlr_output = data;

    struct nwm_output *output = calloc(1, sizeof(struct nwm_output));
    assert(output);
    clock_gettime(CLOCK_MONOTONIC, &output->last_frame);
    output->server = server;
    output->wlr_output = wlr_output;
    wl_list_init(&output->link);
    wl_list_insert(&server->outputs, &output->link);
}

