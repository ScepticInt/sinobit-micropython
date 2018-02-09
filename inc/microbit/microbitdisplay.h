
#ifndef __MICROPY_INCLUDED_MICROBIT_DISPLAY_H__
#define __MICROPY_INCLUDED_MICROBIT_DISPLAY_H__

#include "py/runtime.h"
#include "microbitimage.h"

typedef struct _microbit_display_obj_t {
    mp_obj_base_t base;
    bool    active;
} microbit_display_obj_t;

#define ASYNC_MODE_STOPPED 0
#define ASYNC_MODE_ANIMATION 1
#define ASYNC_MODE_CLEAR 2

extern microbit_display_obj_t microbit_display_obj;


extern "C" {

void microbit_display_show(microbit_display_obj_t *display, microbit_image_obj_t *image);

void microbit_display_animate(microbit_display_obj_t *display, mp_obj_t iterable, mp_int_t delay, bool clear, bool wait);

void microbit_display_scroll(microbit_display_obj_t *display, const char* str, bool wait);

mp_int_t microbit_display_get_pixel(microbit_display_obj_t *display, mp_int_t x, mp_int_t y);

void microbit_display_set_pixel(microbit_display_obj_t *display, mp_int_t x, mp_int_t y, mp_int_t val);

void microbit_display_clear(void);

void microbit_display_tick(void);

bool microbit_display_active_animation(void);

}

#endif // __MICROPY_INCLUDED_MICROBIT_DISPLAY_H__
