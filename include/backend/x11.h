#ifndef WLR_X11_H
#define WLR_X11_H

#include <stdbool.h>
#include <xcb/xcb.h>
#include <X11/Xlib-xcb.h>
#include <wayland-server.h>
#include <wlr/egl.h>
#include <wlr/types/wlr_output.h>
#include <wlr/types/wlr_input_device.h>

struct wlr_x11_backend;

struct wlr_x11_output {
	struct wlr_output wlr_output;
	struct wlr_x11_backend *x11;

	xcb_window_t win;
	EGLSurface surf;
};

struct wlr_x11_backend {
	struct wlr_backend backend;

	Display *xlib_conn;
	xcb_connection_t *xcb_conn;
	xcb_screen_t *screen;

	struct wlr_x11_output output;

	struct wlr_keyboard keyboard;
	struct wlr_input_device keyboard_dev;

	struct wlr_pointer pointer;
	struct wlr_input_device pointer_dev;

	struct wlr_egl egl;
	struct wl_event_source *event_source;
	struct wl_event_source *frame_timer;
};

#endif
