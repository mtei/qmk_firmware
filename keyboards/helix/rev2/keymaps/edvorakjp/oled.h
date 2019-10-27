#ifndef OLED_USER_H
#define OLED_USER_H

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED
#include "ssd1306.h"
#endif
#include "edvorakjp.h"

//assign the right code to your layers for OLED display
#define L_BASE 0

extern uint8_t is_master;
extern bool japanese_mode;

#ifdef SSD1306OLED
void matrix_update(struct CharacterMatrix *dest,
                   const struct CharacterMatrix *source);
void render_status(struct CharacterMatrix *matrix);
void iota_gfx_task_user(void);
#else
void render_status(void);
#endif

#endif // OLED_CONFIG_USER_H
