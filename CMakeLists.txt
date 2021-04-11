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

# File: CMakeLists.txt
# Description: picolibrary-microchip-megaavr0 core CMake rules.

cmake_minimum_required( VERSION 3.16.3 )
project(
    picolibrary-microchip-megaavr0
    LANGUAGES CXX
)

# project configuration
option( PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING     "picolibrary-microchip-megaavr0: enable interactive testing"       OFF )
option( PICOLIBRARY_MICROCHIP_MEGAAVR0_USE_PARENT_PROJECT_BUILD_FLAGS "picolibrary-microchip-megaavr0: use parent project's build flags" ON  )

# configure compilation and linking
if( NOT ${PICOLIBRARY_MICROCHIP_MEGAAVR0_USE_PARENT_PROJECT_BUILD_FLAGS} )
    set( CMAKE_CXX_STANDARD 17 )
    set( CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE )
    set( PICOLIBRARY_MICROCHIP_MEGAAVR0_MCU   "" CACHE STRING "picolibrary-microchip-megaavr0: MCU type"             )
    set( PICOLIBRARY_MICROCHIP_MEGAAVR0_F_CPU "" CACHE STRING "picolibrary-microchip-megaavr0: CPU frequency, in Hz" )
    set(
        CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} \
        -mmcu=${PICOLIBRARY_MICROCHIP_MEGAAVR0_MCU} \
        -DF_CPU=${PICOLIBRARY_MICROCHIP_MEGAAVR0_F_CPU} \
        -Werror -Wall -Wextra \
        -Wcast-align=strict \
        -Wcast-qual \
        -Wduplicated-cond \
        -Wextra-semi \
        -Wfloat-equal \
        -Wimplicit-fallthrough=5 \
        -Wlogical-op \
        -Wmissing-field-initializers \
        -Wmissing-include-dirs \
        -Wold-style-cast \
        -Wplacement-new=2 \
        -Wpointer-arith \
        -Wshadow \
        -Wunsafe-loop-optimizations \
        "
    )
endif( NOT ${PICOLIBRARY_MICROCHIP_MEGAAVR0_USE_PARENT_PROJECT_BUILD_FLAGS} )

# configure avrdude
if( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING} )
    if( "${CMAKE_AVRDUDE}" STREQUAL "CMAKE_AVRDUDE-NOTFOUND" )
        message( FATAL_ERROR "avrdude not found" )
    endif( "${CMAKE_AVRDUDE}" STREQUAL "CMAKE_AVRDUDE-NOTFOUND" )

    option( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_ALWAYS_RECOVER_FUSES_ENABLED          "picolibrary-microchip-megaavr0: avrdude always recover fuses"          OFF )
    option( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DISABLE_AUTOMATIC_FLASH_ERASE_ENABLED "picolibrary-microchip-megaavr0: avrdude disable automatic Flash erase" OFF )
    option( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DISABLE_AUTOMATIC_VERIFY_ENABLED      "picolibrary-microchip-megaavr0: avrdude disable automatic verify"      OFF )
    option( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DISABLE_FUSE_CHECKS_ENABLED           "picolibrary-microchip-megaavr0: avrdude disable fuse checks"           OFF )
    option( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DISABLE_WRITES_ENABLED                "picolibrary-microchip-megaavr0: avrdude disalbe writes"                OFF )
    option( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_ERASE_CHIP_ENABLED                    "picolibrary-microchip-megaavr0: avrdude erase chip"                    OFF )
    option( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_OVERRIDE_SIGNATURE_CHECK_ENABLED      "picolibrary-microchip-megaavr0: avrdude override signature check"      OFF )
    mark_as_advanced(
        PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_ALWAYS_RECOVER_FUSES_ENABLED
        PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DISABLE_AUTOMATIC_FLASH_ERASE_ENABLED
        PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DISABLE_AUTOMATIC_VERIFY_ENABLED
        PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DISABLE_FUSE_CHECKS_ENABLED
        PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DISABLE_WRITES_ENABLED
        PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_ERASE_CHIP_ENABLED
        PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_OVERRIDE_SIGNATURE_CHECK_ENABLED
    )

    set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_BAUD_RATE           ""        CACHE STRING "picolibrary-microchip-megaavr0: avrdude baud rate"           )
    set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_BIT_CLOCK           ""        CACHE STRING "picolibrary-microchip-megaavr0: avrdude bit clock"           )
    set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_CONFIGURATION_FILE  ""        CACHE STRING "picolibrary-microchip-megaavr0: avrdude configuration file"  )
    set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DELAY               ""        CACHE STRING "picolibrary-microchip-megaavr0: avrdude delay"               )
    set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_EXIT_SPECIFICATION  ""        CACHE STRING "picolibrary-microchip-megaavr0: avrdude exit specification"  )
    set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_EXTENDED_PARAMETERS ""        CACHE STRING "picolibrary-microchip-megaavr0: avrdude extended parameters" )
    set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_PART                ""        CACHE STRING "picolibrary-microchip-megaavr0: avrdude part"                )
    set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_PORT                ""        CACHE STRING "picolibrary-microchip-megaavr0: avrdude port"                )
    set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_PROGRAMMER          ""        CACHE STRING "picolibrary-microchip-megaavr0: avrdude programmer"          )
    set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_VERBOSITY           "VERBOSE" CACHE STRING "picolibrary-microchip-megaavr0: avrdude verbosity"           )

    set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_MEMORY_OPERATIONS_POST_FLASH_PROGRAM "" CACHE STRING "picolibrary-microchip-megaavr0: avrdude post Flash program memory operations" )
    set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_MEMORY_OPERATIONS_PRE_FLASH_PROGRAM  "" CACHE STRING "picolibrary-microchip-megaavr0: avrdude pre Flash program memory operations"  )

    if( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_ALWAYS_RECOVER_FUSES_ENABLED} )
        set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_ALWAYS_RECOVER_FUSES "ALWAYS_RECOVER_FUSES" )
    endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_ALWAYS_RECOVER_FUSES_ENABLED} )

    if( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DISABLE_AUTOMATIC_FLASH_ERASE_ENABLED} )
        set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DISABLE_AUTOMATIC_FLASH_ERASE "DISABLE_AUTOMATIC_FLASH_ERASE" )
    endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DISABLE_AUTOMATIC_FLASH_ERASE_ENABLED} )

    if( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DISABLE_AUTOMATIC_VERIFY_ENABLED} )
        set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DISABLE_AUTOMATIC_VERIFY "DISABLE_AUTOMATIC_VERIFY" )
    endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DISABLE_AUTOMATIC_VERIFY_ENABLED} )

    if( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DISABLE_FUSE_CHECKS_ENABLED} )
        set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DISABLE_FUSE_CHECKS "DISABLE_FUSE_CHECKS" )
    endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DISABLE_FUSE_CHECKS_ENABLED} )

    if( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DISABLE_WRITES_ENABLED} )
        set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DISABLE_WRITES "DISABLE_WRITES" )
    endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_DISABLE_WRITES_ENABLED} )

    if( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_ERASE_CHIP_ENABLED} )
        set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_ERASE_CHIP "ERASE_CHIP" )
    endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_ERASE_CHIP_ENABLED} )

    if( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_OVERRIDE_SIGNATURE_CHECK_ENABLED} )
        set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_OVERRIDE_SIGNATURE_CHECK "OVERRIDE_SIGNATURE_CHECK" )
    endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_OVERRIDE_SIGNATURE_CHECK_ENABLED} )
endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING} )

# build the library's tests
add_subdirectory( test )
