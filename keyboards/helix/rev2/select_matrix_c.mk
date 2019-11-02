ifneq ($(strip $(SPLIT_KEYBOARD)), yes)
  SRC += local_drivers/serial.c
  KEYBOARD_PATHS += $(HELIX_TOP_DIR)/local_drivers

  CUSTOM_MATRIX = yes

  SRC += rev2/matrix.c
  SRC += rev2/split_util.c
  SRC += rev2/split_scomm.c
endif
