#pragma once

#define PS2_MOUSE_SCROLL_BTN_MASK (1<<PS2_MOUSE_BTN_MIDDLE) /* Default */

/*
#define PS2_MOUSE_SCROLL_BTN_SEND 300
#define PS2_MOUSE_SCROLL_DIVISOR_H 2
#define PS2_MOUSE_SCROLL_DIVISOR_V 2
*/

/*
#define PS2_MOUSE_INVERT_X
#define PS2_MOUSE_INVERT_X
*/

#define PS2_MOUSE_ROTATE 180 /* Compensate for South-facing device orientation. */

#define ONESHOT_TAP_TOGGLE 3  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 1600
