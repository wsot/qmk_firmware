
#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    Wulkan
#define PRODUCT         Handwired48Keys
#define DESCRIPTION     A compact ortholinear handwired keyboard

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 18

#define MATRIX_ROW_PINS { B9, B8, B7, B6, B5 }
#define MATRIX_COL_PINS { \
    B4, B3, A15, A10, A9, A8, B15, B14, B13, \
    B1, B0, A3, A2, A1, A0, C15, C14, C13 \
}

#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

#define FORCE_NKRO

#define WS2812_SPI SPID1 // default: SPID1
#define WS2812_SPI_MOSI_PAL_MODE 5 // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 5
