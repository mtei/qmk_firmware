ifneq ($(strip $(SPLIT_KEYBOARD)), yes)
  SRC += local_drivers/serial.c
  KEYBOARD_PATHS += $(HELIX_TOP_DIR)/local_drivers

  CUSTOM_MATRIX = yes

  SRC += pico/matrix.c
  SRC += pico/split_util.c
endif
