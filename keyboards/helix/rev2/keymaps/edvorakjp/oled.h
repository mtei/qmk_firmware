#ifndef OLED_USER_H
#define OLED_USER_H

#include "edvorakjp.h"

//assign the right code to your layers for OLED display
#define L_BASE 0

extern uint8_t is_master;
extern bool japanese_mode;

void render_status(void);

#endif // OLED_CONFIG_USER_H
