cmake_minimum_required(VERSION 3.13...3.27)

# 1. Force the SDK to build for the RP2350 family (required for RP2354A)
set(PICO_PLATFORM rp2350 CACHE STRING "Pico platform" FORCE)

# 2. Tell CMake to look inside your project's "boards" folder for header files
set(PICO_BOARD_HEADER_DIRS "${CMAKE_CURRENT_LIST_DIR}/boards" CACHE STRING "Board header dirs" FORCE)


# 3. Match this name exactly to your filename (custom_pico2.h -> custom_pico2)
set(PICO_BOARD custom_pico2 CACHE STRING "Board type" FORCE)


# initialize the SDK, which lives in /opt/pico-sdk (shared across projects)
# must be included before project()
include(/opt/pico-sdk/pico_sdk_init.cmake)

project(custom-pico2-blink)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

##################################### boilerplate

add_executable(blink src/blink.c)

target_link_libraries(blink pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(blink)
