CONSOLE_ENABLE = yes

SRC += wait_test.c aligned_nop_loop.c

ifneq ($(strip $(TEST)),)
  define KEYMAP_OPTION_PARSE
    #$(info .$1.) #debug
    ifeq ($(strip $1),slow)
        CLOCK = slow
    endif
    ifeq ($(strip $1),fast)
        CLOCK = fast
    endif
    ifeq ($(strip $1),normal)
        TEST_TYPE =
    endif
    ifeq ($(strip $1),long)
        TEST_TYPE = long
    endif
    ifeq ($(strip $1),loop)
        TEST_TYPE = loop
    endif
    ifeq ($(strip $1),align)
        TEST_TYPE = align
    endif
    ifeq ($(strip $1),align2)
        TEST_TYPE = align2
    endif
    ifeq ($(strip $1),allnop)
        TEST_TYPE = allnop
    endif
    ifeq ($(strip $1),iodelay)
        TEST_TYPE = iodelay
    endif
    ifeq ($(strip $1),iodelay2)
        TEST_TYPE = iodelay2
    endif
  endef

  COMMA=,
  $(eval $(foreach A_OPTION_NAME,$(subst $(COMMA), , $(TEST)),  \
      $(call KEYMAP_OPTION_PARSE, $(A_OPTION_NAME))))
endif

ifeq ($(strip $(CLOCK)),slow)
  OPT_DEFS += -DSLOW_CLOCK
endif
ifeq ($(strip $(TEST_TYPE)),long)
  OPT_DEFS += -DLONG_TEST
endif
ifeq ($(strip $(TEST_TYPE)),loop)
  OPT_DEFS += -DLOOP_TEST
endif
ifeq ($(strip $(TEST_TYPE)),align)
  OPT_DEFS += -DALIGN_TEST
endif
ifeq ($(strip $(TEST_TYPE)),align2)
  OPT_DEFS += -DALIGN2_TEST
endif
ifeq ($(strip $(TEST_TYPE)),allnop)
  OPT_DEFS += -DALLNOP_TEST
endif

ifeq ($(strip $(TEST_TYPE)),iodelay)
  OPT_DEFS += -DIODELAY_TEST
endif

ifeq ($(strip $(TEST_TYPE)),iodelay2)
  OPT_DEFS += -DIODELAY2_TEST
endif

$(info .)
$(info TEST_TYPE = $(TEST_TYPE))
$(info .)
