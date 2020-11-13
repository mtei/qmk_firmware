SRC += wait_test.c aligned_4clock_delay.c

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
    ifeq ($(strip $1),4clock)
        TEST_TYPE = 4clock
    endif
    ifeq ($(strip $1),16clock)
        TEST_TYPE = 16clock
    endif
    ifeq ($(strip $1),align)
        TEST_TYPE = align
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
ifeq ($(strip $(TEST_TYPE)),4clock)
  OPT_DEFS += -DTEST_4CLOCK
endif
ifeq ($(strip $(TEST_TYPE)),16clock)
  OPT_DEFS += -DTEST_16CLOCK
endif
ifeq ($(strip $(TEST_TYPE)),align)
  OPT_DEFS += -DALIGN_TEST
endif

$(info .)
$(info TEST_TYPE = $(TEST_TYPE))
$(info .)
