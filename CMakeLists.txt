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
