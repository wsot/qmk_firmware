
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


#define MK_3_SPEED true
#define MK_MOMENTARY_ACCEL true

#define MOUSEKEY_DELAY 50 // Delay between pressing a movement key and cursor movement, default=300
#define MOUSEKEY_INTERVAL 16 // Time between cursor movements, default=50
#define MOUSEKEY_TIME_TO_MAX 20 // Time until maximum cursor speed is reached, default=20
#define MOUSEKEY_WHEEL_DELAY 300 // Delay between pressing a wheel key and wheel movement, default=300
#define MOUSEKEY_WHEEL_INTERVAL 100 // Time between wheel movements, default=100
#define MOUSEKEY_WHEEL_MAX_SPEED 8 // Maximum number of scroll steps per scroll action, default=8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40 // Time until maximum scroll speed is reached, default=40


#define MK_C_OFFSET_UNMOD 16
#define MK_C_INTERVAL_UNMOD 16
#define MK_C_OFFSET_0 1
#define MK_C_INTERVAL_0 16
#define MK_C_OFFSET_1 4
#define MK_C_INTERVAL_1 16
#define MK_C_OFFSET_2 32
#define MK_C_INTERVAL_2 16
