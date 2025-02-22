# Enable-IfNot-Set Link Time Optimization (LTO) to squeeze space on AVR platform
ifeq ($(PLATFORM),AVR)
	LTO_ENABLE ?= yes
endif
