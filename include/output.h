#ifndef NWM_OUTPUT_H
#define NWM_OUTPUT_H

#include <wlr/types/wlr_output.h>

struct nwm_output {
    struct timespec last_frame;
    struct nwm_server *server;
    struct wlr_output *wlr_output;
    struct wl_list link;
};

void new_output_notify(struct wl_listener *listener, void *data);

#endif
