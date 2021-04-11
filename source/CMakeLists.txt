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

# File: source/CMakeLists.txt
# Description: picolibrary-microchip-megaavr0 CMake rules.

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/picolibrary/microchip/megaavr0/version.cc.in"
    "${CMAKE_CURRENT_BINARY_DIR}/picolibrary/microchip/megaavr0/version.cc"
    @ONLY
)

set(
    PICOLIBRARY_MICROCHIP_MEGAAVR0_SOURCE_FILES
    "${CMAKE_CURRENT_BINARY_DIR}/picolibrary/microchip/megaavr0/version.cc"
    "picolibrary/microchip/megaavr0.cc"
)
set(
    PICOLIBRARY_MICROCHIP_MEGAAVR0_LINK_LIBRARIES
    "picolibrary"
)

add_library(
    picolibrary-microchip-megaavr0
    ${PICOLIBRARY_MICROCHIP_MEGAAVR0_SOURCE_FILES}
)
target_include_directories(
    picolibrary-microchip-megaavr0
    PUBLIC "${PROJECT_SOURCE_DIR}/include"
)
target_link_libraries(
    picolibrary-microchip-megaavr0
    ${PICOLIBRARY_MICROCHIP_MEGAAVR0_LINK_LIBRARIES}
)