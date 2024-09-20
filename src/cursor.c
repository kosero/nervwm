#include <wlr/types/wlr_cursor.h>
#include <wlr/types/wlr_xcursor_manager.h>

#include "cursor.h"
#include "server.h"

void server_new_pointer(struct nwm_server *server,
		struct wlr_input_device *device) {
	wlr_cursor_attach_input_device(server->cursor, device);
}
