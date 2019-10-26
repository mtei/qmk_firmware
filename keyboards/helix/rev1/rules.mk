SRC += local_drivers/serial.c
KEYBOARD_PATHS += $(HELIX_TOP_DIR)/local_drivers

CUSTOM_MATRIX = yes

SRC += rev1/matrix.c
SRC += rev1/split_util.c

BACKLIGHT_ENABLE = no
