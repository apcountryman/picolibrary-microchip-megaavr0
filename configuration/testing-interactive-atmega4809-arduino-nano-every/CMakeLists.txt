# picolibrary-microchip-megaavr0
#
# Copyright 2021-2023, Andrew Countryman <apcountryman@gmail.com> and the
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

# Description: picolibrary-microchip-megaavr0 ATmega4809 Arduino Nano Every interactive
#       testing configuration.

# build configuration
set( CMAKE_BUILD_TYPE                                              "MinSizeRel" CACHE INTERNAL "" )
set( CMAKE_EXPORT_COMPILE_COMMANDS                                 ON           CACHE INTERNAL "" )
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_F_CPU                          "16000000UL" CACHE INTERNAL "" )
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_MCU                            "atmega4809" CACHE INTERNAL "" )
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_USE_PARENT_PROJECT_BUILD_FLAGS OFF          CACHE INTERNAL "" )

# avr-libcpp configuration
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_USE_PARENT_PROJECT_AVRLIBCPP OFF CACHE INTERNAL "" )

# picolibrary configuration
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_USE_PARENT_PROJECT_PICOLIBRARY OFF CACHE INTERNAL "" )
set( PICOLIBRARY_SUPPRESS_ASSERTION_FAILURE_LOCATION_INFORMATION   OFF CACHE INTERNAL "" )
set( PICOLIBRARY_SUPPRESS_HUMAN_READABLE_ERROR_INFORMATION         OFF CACHE INTERNAL "" )
set( PICOLIBRARY_SUPPRESS_HUMAN_READABLE_EVENT_INFORMATION         OFF CACHE INTERNAL "" )

# interactive testing configuration
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING                                        ON          CACHE INTERNAL "" )
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_CONFIGURE_CLOCK_CLOCK_PRESCALER_VALUE         "_2"        CACHE INTERNAL "" )
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_CONFIGURE_CLOCK_CLOCK_PRESCALER_CONFIGURATION "DISABLED"  CACHE INTERNAL "" )
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_LOG_USART                                     "USART3"    CACHE INTERNAL "" )
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_LOG_USART_ROUTE                               "ALTERNATE" CACHE INTERNAL "" )

set(
    PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_LOG_USART_CLOCK_GENERATOR_OPERATING_SPEED
    "NORMAL" CACHE STRING
    "picolibrary-microchip-megaavr0: picolibrary::Testing::Interactive::Microchip::megaAVR0::Log USART clock generator operating speed"
)
set(
    PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_LOG_USART_CLOCK_GENERATOR_SCALING_FACTOR
    "556" CACHE STRING
    "picolibrary-microchip-megaavr0: picolibrary::Testing::Interactive::Microchip::megaAVR0::Log USART clock generator scaling factor"
)

# configure avrdude
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_PROGRAM_FLASH "-p" "atmega4809" "-c" "jtag2updi" "-b" "115200" "-e" "-D" CACHE INTERNAL "" )
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_RESET_ENABLED ON                                                         CACHE INTERNAL "" )
set( PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_VERIFY_FLASH  "-p" "atmega4809" "-c" "jtag2updi" "-b" "115200"           CACHE INTERNAL "" )

# configure interactive tests
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/adafruit/pid781/driver/hello_world/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/asynchronous_serial/reliable_unbuffered_output_stream/hello_world/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/microchip/mcp23008/internally_pulled_up_input_pin/state/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/microchip/mcp23008/open_drain_io_pin/toggle/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/microchip/mcp23008/push_pull_io_pin/toggle/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/microchip/mcp23s08/internally_pulled_up_input_pin/state/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/microchip/mcp23s08/open_drain_io_pin/toggle/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/microchip/mcp23s08/push_pull_io_pin/toggle/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/microchip/mcp3008/blocking_single_sample_converter/sample/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/microchip/megaavr0/asynchronous_serial/transmitter/hello_world/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/microchip/megaavr0/device_info/print/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/microchip/megaavr0/gpio/input_pin/state/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/microchip/megaavr0/gpio/internally_pulled_up_input_pin/state/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/microchip/megaavr0/gpio/open_drain_io_pin/toggle/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/microchip/megaavr0/gpio/push_pull_io_pin/toggle/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/microchip/megaavr0/i2c/controller/scan/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/microchip/megaavr0/spi/fixed_configuration_controller-spi/echo/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/microchip/megaavr0/spi/fixed_configuration_controller-usart/echo/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/microchip/megaavr0/spi/variable_configuration_controller-spi/echo/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/microchip/megaavr0/spi/variable_configuration_controller-usart/echo/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/texas_instruments/tca9548a/driver/scan/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/wiznet/w5500/ip/network_stack/ping/CMakeLists.txt" )
include( "${CMAKE_CURRENT_LIST_DIR}/test/interactive/picolibrary/wiznet/w5500/ip/tcp/client/echo/CMakeLists.txt" )
