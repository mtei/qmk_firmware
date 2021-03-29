ifneq ($(strip $(TEST)),)
  define KEYBOARD_OPTION_PARSE
    # parse 'consle', 'debug', 'mdelay0', 'mdelay1', 'mdelay5', 'mdelay10', 'mdelay30', 'scan', 'matrix_debug', 'matrix_scan', 'input_pin_delay'
    $(if $(SHOW_PARCE),$(info parse .$1.))  #for debug  'make SHOW_PARCE=y ...'
    ifeq ($(strip $1),console)
        CONSOLE_ENABLE = yes
    endif
    ifeq ($(strip $1),debug)
        DEBUG_CONFIG = yes
    endif
    ifeq ($(strip $1),mdelay0)
        MDELAY = 0
    endif
    ifeq ($(strip $1),mdelay1)
        MDELAY = 1
    endif
    ifeq ($(strip $1),mdelay2)
        MDELAY = 2
    endif
    ifeq ($(strip $1),mdelay3)
        MDELAY = 3
    endif
    ifeq ($(strip $1),mdelay4)
        MDELAY = 4
    endif
    ifeq ($(strip $1),mdelay5)
        MDELAY = 5
    endif
    ifeq ($(strip $1),mdelay10)
        MDELAY = 10
    endif
    ifeq ($(strip $1),mdelay30)
        MDELAY = 30
    endif
    ifeq ($(strip $1),input_pin_delay)
	INPUT_PIN_DELAY = yes
    endif
    ifeq ($(strip $1),adaptive_delay)
	ADAPTIVE_DELAY = yes
    endif
    ifeq ($(strip $1),allways_delay)
        ALLWAYS_DELAY = yes
    endif
    ifeq ($(strip $1),matrix_debug_delay)
	MATRIX_DEBUG_DELAY = yes
	MATRIX_DEBUG_SCAN = no
    endif
    ifeq ($(strip $1),matrix_debug_scan)
	MATRIX_DEBUG_DELAY = no
	MATRIX_DEBUG_SCAN = yes
    endif
    ifeq ($(strip $1),matrix_fast)
	MATRIX_FAST = yes
    endif
    ifeq ($(strip $1),no-scan)
#        MATRIX_SCAN_RATE = no
        DEBUG_MATRIX_SCAN_RATE_ENABLE = no
    endif
    ifeq ($(strip $1),scan)
#        MATRIX_SCAN_RATE = yes
        DEBUG_MATRIX_SCAN_RATE_ENABLE = yes
    endif
  endef # end of KEYMAP_OPTION_PARSE

  COMMA=,
  $(eval $(foreach A_OPTION_NAME,$(subst $(COMMA), ,$(TEST)),  \
      $(call KEYBOARD_OPTION_PARSE,$(A_OPTION_NAME))))
endif

ifneq ($(strip $(MDELAY)),)
    OPT_DEFS += -DMATRIX_IO_DELAY=$(strip $(MDELAY))
endif

ifeq ($(strip $(DEBUG_CONFIG)), yes)
    OPT_DEFS += -DDEBUG_CONFIG
endif

ifeq ($(strip $(MATRIX_DEBUG_DELAY)),yes)
    OPT_DEFS += -DDEBUG_CONFIG -DMATRIX_DEBUG_DELAY
    DEBUG_CONFIG = yes
endif
ifeq ($(strip $(MATRIX_DEBUG_SCAN)),yes)
    OPT_DEFS += -DDEBUG_CONFIG -DMATRIX_DEBUG_SCAN
    DEBUG_CONFIG = yes
endif

ifeq ($(strip $(INPUT_PIN_DELAY)),yes)
    OPT_DEFS += -DDEBUG_CONFIG -DLOOK_INPUT_PIN_DELAY
    DEBUG_CONFIG = yes
endif

ifeq ($(strip $(ADAPTIVE_DELAY)),yes)
    OPT_DEFS += -DDEBUG_CONFIG -DMATRIX_IO_DELAY_ADAPTIVE
    DEBUG_CONFIG = yes
endif

ifeq ($(strip $(ALLWAYS_DELAY)),yes)
    OPT_DEFS += -DDEBUG_CONFIG -DMATRIX_IO_DELAY_ALLWAYS
    DEBUG_CONFIG = yes
endif

ifeq ($(strip $(MATRIX_FAST)),yes)
    CUSTOM_MATRIX = yes
    SRC += matrix_common.c
    SRC += matrix_fast/matrix.c
else ifeq ($(strip $(DEBUG_CONFIG)),yes)
    CUSTOM_MATRIX = yes
    SRC += matrix_common.c
    SRC += matrix_debug/matrix.c
endif
