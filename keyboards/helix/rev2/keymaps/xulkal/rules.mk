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

ifneq ($(strip $(SPLIT_KEYBOARD)), yes)
  CUSTOM_MATRIX = yes  # use Helix old code

  LIB_SRC += local_drivers/serial.c
  KEYBOARD_PATHS += $(HELIX_TOP_DIR)/local_drivers
  SRC += rev2/matrix.c
  SRC += rev2/split_util.c
  SRC += rev2/split_scomm.c
endif
