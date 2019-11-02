RGBLIGHT_ENABLE = yes
# Enable RGBLIGHT Animations
OPT_DEFS += -DRGBLIGHT_ANIMATIONS
# Helix specific define for correct RGBLED_NUM
OPT_DEFS += -DRGBLED_BACK

OLED_DRIVER_ENABLE = yes
# Helix specific font file
OPT_DEFS += -DOLED_FONT_H=\"common/glcdfont.c\"
# Xulkal specific oled define
OPT_DEFS += -DOLED_90ROTATION

## select helix local matrix.c or split_common/matrix.c
include $(strip $(SELECT_MATRIX_C_MK))
ifneq ($(strip $(SPLIT_KEYBOARD)), yes)
  LIB_SRC += local_drivers/serial.c # workarund for LINK_TIME_OPTIMIZATION_ENABLE=yes problem
endif
