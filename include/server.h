#ifndef NWM_SERVER_H
#define NWM_SERVER_H

#include "output.h"

struct nwm_output;

struct nwm_server {
    struct wl_display *wl_display;
    struct wl_event_loop *wl_event_loop;
    struct wlr_backend *backend;
    struct wl_listener new_output;
    struct wl_list outputs;
};


#endif
