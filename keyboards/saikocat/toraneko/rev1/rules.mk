WAIT_FOR_USB = yes

PIN_COMPATIBLE = promicro

ifneq ($(filter $(strip $(CONVERT_TO)),kb2040 promicro_rp2040),)
	MCU = RP2040
	BOOTLOADER = rp2040
	LTO_ENABLE = no
	VPATH += keyboards/saikocat/toraneko/rev1/rp2040
else
	MCU = atmega32u4
	BOOTLOADER = atmel-dfu
	LTO_ENABLE = yes
endif

OLED_DRIVER = SSD1306
