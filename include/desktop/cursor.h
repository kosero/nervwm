#ifndef NWM_CURSOR_H
#define NWM_CURSOR_H

#include <wlr/types/wlr_cursor.h>
#include <wlr/types/wlr_xcursor_manager.h>

struct nervwm_output;

enum nervwm_cursor_mode {
	nervwm_CURSOR_PASSTHROUGH,
	nervwm_CURSOR_MOVE,
	nervwm_CURSOR_RESIZE,
};



#endif
