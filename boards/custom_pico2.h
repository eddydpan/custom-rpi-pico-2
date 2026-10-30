#ifndef _BOARDS_MY_CUSTOM_BOARD_H
#define _BOARDS_MY_CUSTOM_BOARD_H

// Identify the target platform architecture
#include "boards/pico2.h"

// Override defaults to reflect the exact RP2354A specs
#undef PICO_FLASH_SIZE_BYTES
#define PICO_FLASH_SIZE_BYTES (2 * 1024 * 1024) // 2MB internal flash

// (Optional) Define custom User LED pin globally
#undef PICO_DEFAULT_LED_PIN
#define PICO_DEFAULT_LED_PIN 19

#endif
