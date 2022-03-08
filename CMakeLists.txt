cmake_minimum_required(VERSION 3.12)

# set(PICO_TOOLCHAIN_PATH "/home/niksun/tools/gcc-arm-10.3-2021.07-x86_64-arm-none-eabi")
set(PICO_SDK_PATH "/home/niksun/development/pico/pico-sdk")
set(CMAKE_SYSROOT "/usr/arm-none-eabi")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(pico_examples C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if(PICO_SDK_VERSION_STRING VERSION_LESS "1.3.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.3.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

# Initialize the SDK
pico_sdk_init()

include(example_auto_set_url.cmake)

add_compile_options(
  -Wall
  -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
  -Wno-unused-function # we have some for the docs that aren't called
  -Wno-maybe-uninitialized
)

# Add blink example
add_subdirectory(blink)
# Add hello world example
add_subdirectory(hello_world)
# Add flow leds example
add_subdirectory(flow_leds)

# Hardware-specific examples in subdirectories:
# add_subdirectory(adc)
# add_subdirectory(clocks)
# add_subdirectory(cmake)
# add_subdirectory(divider)
# add_subdirectory(dma)
# add_subdirectory(flash)
# add_subdirectory(gpio)
# add_subdirectory(i2c)
# add_subdirectory(interp)
# add_subdirectory(multicore)
# add_subdirectory(picoboard)
# add_subdirectory(pio)
# add_subdirectory(pwm)
# add_subdirectory(reset)
# add_subdirectory(rtc)
# add_subdirectory(spi)
# add_subdirectory(system)
# add_subdirectory(timer)
# add_subdirectory(uart)
# add_subdirectory(usb)
# add_subdirectory(watchdog)
