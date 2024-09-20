#ifndef NWM_CURSOR_H
#define NWM_CURSOR_H

#include <wlr/types/wlr_cursor.h>
#include <wlr/types/wlr_xcursor_manager.h>

#include "server.h"

enum nwm_cursor_mode {
	NWM_CURSOR_PASSTHROUGH,
	NWM_CURSOR_MOVE,
	NWM_CURSOR_RESIZE,
};

void server_new_pointer(struct nwm_server *server, struct wlr_input_device *device);

#endif // !NWM_CURSOR_H
