WAIT_FOR_USB = yes

OLED_ENABLE = yes
OLED_DRIVER = SSD1306

RGBLIGHT_ENABLE = yes

PIN_COMPATIBLE = promicro

ifneq ($(filter $(strip $(CONVERT_TO)),kb2040 promicro_rp2040),)
	MCU = RP2040
	BOOTLOADER = rp2040

	WS2812_DRIVER = vendor

	LTO_ENABLE = no

	VPATH += keyboards/saikocat/kotoe42/rev1/kb2040
else
	MCU = atmega32u4
	BOOTLOADER = atmel-dfu

	LTO_ENABLE = yes
endif
