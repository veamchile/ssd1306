# This is Makefile for ESP32 IDF

COMPONENT_ADD_INCLUDEDIRS := ./src
COMPONENT_SRCDIRS := ./src/ssd1306_hal \
                     ./src/ssd1306_hal/esp \
                     ./src/intf \
                     ./src/intf/i2c \
                     ./src/intf/spi \
                     ./src/lcd \
                     ./src/nano_engine

