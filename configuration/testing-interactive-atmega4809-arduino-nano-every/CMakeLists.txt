# picolibrary-microchip-megaavr0
#
# Copyright 2021, Andrew Countryman <apcountryman@gmail.com> and the
# picolibrary-microchip-megaavr0 contributors
#
# Licensed under the Apache License, Version 2.0 (the "License"); you may not use this
# file except in compliance with the License. You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software distributed under
# the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied. See the License for the specific language governing
# permissions and limitations under the License.

# File: configuration/testing-interactive-atmega4809-arduino-nano-every/CMakeLists.txt
# Description: picolibrary-microchip-megaavr0 ATmega4809 Arduino Nano Every interactive
#       testing configuration.

# install prefix is not applicable
mark_as_advanced( CMAKE_INSTALL_PREFIX )

# build configuration
set( CMAKE_BUILD_TYPE                                              "MinSizeRel" CACHE STRING "" FORCE )
set( CMAKE_EXPORT_COMPILE_COMMANDS                                 ON           CACHE BOOL   "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_F_CPU                          "16000000UL" CACHE STRING "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_MCU                            "atmega4809" CACHE STRING "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_USE_PARENT_PROJECT_BUILD_FLAGS OFF          CACHE BOOL   "" FORCE )
mark_as_advanced(
    CMAKE_BUILD_TYPE
    CMAKE_EXPORT_COMPILE_COMMANDS
    PICOLIBRARY_MICROCHIP_MEGAAVR0_F_CPU
    PICOLIBRARY_MICROCHIP_MEGAAVR0_MCU
    PICOLIBRARY_MICROCHIP_MEGAAVR0_USE_PARENT_PROJECT_BUILD_FLAGS
)

# avr-libcpp configuration
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_USE_PARENT_PROJECT_AVRLIBCPP OFF CACHE BOOL "" FORCE )
mark_as_advanced( PICOLIBRARY_MICROCHIP_MEGAAVR0_USE_PARENT_PROJECT_AVRLIBCPP )

# picolibrary configuration
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_USE_PARENT_PROJECT_PICOLIBRARY OFF CACHE BOOL "" FORCE )
mark_as_advanced( PICOLIBRARY_MICROCHIP_MEGAAVR0_USE_PARENT_PROJECT_PICOLIBRARY )

# interactive testing configuration
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING ON CACHE BOOL "" FORCE )
mark_as_advanced( PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING )

# configure avrdude
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_ALWAYS_RECOVER_FUSES_ENABLED          OFF                                                CACHE BOOL   "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_BAUD_RATE                             "115200"                                           CACHE STRING "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_BIT_CLOCK                             ""                                                 CACHE STRING "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DELAY                                 ""                                                 CACHE STRING "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DISABLE_AUTOMATIC_FLASH_ERASE_ENABLED ON                                                 CACHE BOOL   "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DISABLE_AUTOMATIC_VERIFY_ENABLED      OFF                                                CACHE BOOL   "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DISABLE_FUSE_CHECKS_ENABLED           OFF                                                CACHE BOOL   "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DISABLE_WRITES_ENABLED                OFF                                                CACHE BOOL   "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_ERASE_CHIP_ENABLED                    ON                                                 CACHE BOOL   "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_EXIT_SPECIFICATION                    ""                                                 CACHE STRING "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_EXTENDED_PARAMETERS                   ""                                                 CACHE STRING "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_MEMORY_OPERATIONS_POST_FLASH_PROGRAM  "fuse2:w:0x01:m" "fuse5:w:0xC9:m" "fuse8:w:0x00:m" CACHE STRING "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_MEMORY_OPERATIONS_PRE_FLASH_PROGRAM   ""                                                 CACHE STRING "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_OVERRIDE_SIGNATURE_CHECK_ENABLED      OFF                                                CACHE BOOL   "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_PART                                  "atmega4809"                                       CACHE STRING "" FORCE )
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_PROGRAMMER                            "jtag2updi"                                        CACHE STRING "" FORCE )
mark_as_advanced(
    PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_ALWAYS_RECOVER_FUSES_ENABLED
    PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_BAUD_RATE
    PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_BIT_CLOCK
    PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DELAY
    PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DISABLE_AUTOMATIC_FLASH_ERASE_ENABLED
    PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DISABLE_AUTOMATIC_VERIFY_ENABLED
    PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DISABLE_FUSE_CHECKS_ENABLED
    PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DISABLE_WRITES_ENABLED
    PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_ERASE_CHIP_ENABLED
    PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_EXIT_SPECIFICATION
    PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_EXTENDED_PARAMETERS
    PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_MEMORY_OPERATIONS_POST_FLASH_PROGRAM
    PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_MEMORY_OPERATIONS_PRE_FLASH_PROGRAM
    PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_OVERRIDE_SIGNATURE_CHECK_ENABLED
    PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_PART
    PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_PROGRAMMER
)
