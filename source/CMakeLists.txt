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

# Description: picolibrary-microchip-megaavr0 CMake rules.

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/picolibrary/microchip/megaavr0/version.cc.in"
    "${CMAKE_CURRENT_BINARY_DIR}/picolibrary/microchip/megaavr0/version.cc"
    @ONLY
)

set(
    PICOLIBRARY_MICROCHIP_MEGAAVR0_SOURCE_FILES
    "picolibrary/microchip/megaavr0.cc"
    "picolibrary/microchip/megaavr0/asynchronous_serial.cc"
    "picolibrary/microchip/megaavr0/clock.cc"
    "picolibrary/microchip/megaavr0/device_info.cc"
    "picolibrary/microchip/megaavr0/gpio.cc"
    "picolibrary/microchip/megaavr0/i2c.cc"
    "picolibrary/microchip/megaavr0/interrupt.cc"
    "picolibrary/microchip/megaavr0/multiplexed_signals.cc"
    "picolibrary/microchip/megaavr0/multiplexed_signals/spi.cc"
    "picolibrary/microchip/megaavr0/multiplexed_signals/twi.cc"
    "picolibrary/microchip/megaavr0/multiplexed_signals/usart.cc"
    "picolibrary/microchip/megaavr0/peripheral.cc"
    "picolibrary/microchip/megaavr0/peripheral/ac.cc"
    "picolibrary/microchip/megaavr0/peripheral/adc.cc"
    "picolibrary/microchip/megaavr0/peripheral/bod.cc"
    "picolibrary/microchip/megaavr0/peripheral/clkctrl.cc"
    "picolibrary/microchip/megaavr0/peripheral/cpuint.cc"
    "picolibrary/microchip/megaavr0/peripheral/crcscan.cc"
    "picolibrary/microchip/megaavr0/peripheral/instance.cc"
    "picolibrary/microchip/megaavr0/peripheral/nvmctrl.cc"
    "picolibrary/microchip/megaavr0/peripheral/port.cc"
    "picolibrary/microchip/megaavr0/peripheral/portmux.cc"
    "picolibrary/microchip/megaavr0/peripheral/rstctrl.cc"
    "picolibrary/microchip/megaavr0/peripheral/rtc.cc"
    "picolibrary/microchip/megaavr0/peripheral/sigrow.cc"
    "picolibrary/microchip/megaavr0/peripheral/slpctrl.cc"
    "picolibrary/microchip/megaavr0/peripheral/spi.cc"
    "picolibrary/microchip/megaavr0/peripheral/syscfg.cc"
    "picolibrary/microchip/megaavr0/peripheral/twi.cc"
    "picolibrary/microchip/megaavr0/peripheral/usart.cc"
    "picolibrary/microchip/megaavr0/peripheral/vport.cc"
    "picolibrary/microchip/megaavr0/peripheral/vref.cc"
    "picolibrary/microchip/megaavr0/peripheral/wdt.cc"
    "picolibrary/microchip/megaavr0/register.cc"
    "picolibrary/microchip/megaavr0/reset.cc"
    "picolibrary/microchip/megaavr0/spi.cc"
    "picolibrary/microchip/megaavr0/watchdog_timer.cc"
)
set(
    PICOLIBRARY_MICROCHIP_MEGAAVR0_LINK_LIBRARIES
    "picolibrary"
)

if( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING} )
    list(
        APPEND PICOLIBRARY_MICROCHIP_MEGAAVR0_SOURCE_FILES
        "picolibrary/testing/interactive/microchip/megaavr0.cc"
        "picolibrary/testing/interactive/microchip/megaavr0/clock.cc"
        "picolibrary/testing/interactive/microchip/megaavr0/device_info.cc"
        "picolibrary/testing/interactive/microchip/megaavr0/log.cc"
    )
endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING} )

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

if( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING} )
    set(
        PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_CONFIGURE_CLOCK_CLOCK_PRESCALER_VALUE
        "" CACHE STRING
        "picolibrary-microchip-megaavr0: picolibrary::Testing::Interactive::Microchip::megaAVR0::configure_clock() clock prescaler value"
    )
    set(
        PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_CONFIGURE_CLOCK_CLOCK_PRESCALER_CONFIGURATION
        "" CACHE STRING
        "picolibrary-microchip-megaavr0: picolibrary::Testing::Interactive::Microchip::megaAVR0::configure_clock() clock prescaler configuration"
    )

    set(
        PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_LOG_USART
        "" CACHE STRING
        "picolibrary-microchip-megaavr0: picolibrary::Testing::Interactive::Microchip::megaAVR0::Log USART"
    )
    set(
        PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_LOG_USART_ROUTE
        "" CACHE STRING
        "picolibrary-microchip-megaavr0: picolibrary::Testing::Interactive::Microchip::megaAVR0::Log USART route"
    )
    set(
        PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_LOG_USART_CLOCK_GENERATOR_OPERATING_SPEED
        "" CACHE STRING
        "picolibrary-microchip-megaavr0: picolibrary::Testing::Interactive::Microchip::megaAVR0::Log USART clock generator operating speed"
    )
    set(
        PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_LOG_USART_CLOCK_GENERATOR_SCALING_FACTOR
        "" CACHE STRING
        "picolibrary-microchip-megaavr0: picolibrary::Testing::Interactive::Microchip::megaAVR0::Log USART clock generator scaling factor"
    )

    target_compile_definitions(
        picolibrary-microchip-megaavr0
        PUBLIC "$<IF:$<BOOL:${PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_CONFIGURE_CLOCK_CLOCK_PRESCALER_VALUE}>,PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_CONFIGURE_CLOCK_CLOCK_PRESCALER_VALUE=${PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_CONFIGURE_CLOCK_CLOCK_PRESCALER_VALUE},>"
        PUBLIC "$<IF:$<BOOL:${PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_CONFIGURE_CLOCK_CLOCK_PRESCALER_VALUE}>,PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_CONFIGURE_CLOCK_CLOCK_PRESCALER_CONFIGURATION=${PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_CONFIGURE_CLOCK_CLOCK_PRESCALER_CONFIGURATION},>"
        PUBLIC "$<IF:$<BOOL:${PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_LOG_USART}>,PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_LOG_USART=${PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_LOG_USART},>"
        PUBLIC "$<IF:$<BOOL:${PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_LOG_USART}>,PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_LOG_USART_ROUTE=${PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_LOG_USART_ROUTE},>"
        PUBLIC "$<IF:$<BOOL:${PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_LOG_USART}>,PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_LOG_USART_CLOCK_GENERATOR_OPERATING_SPEED=${PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_LOG_USART_CLOCK_GENERATOR_OPERATING_SPEED},>"
        PUBLIC "$<IF:$<BOOL:${PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_LOG_USART}>,PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_LOG_USART_CLOCK_GENERATOR_SCALING_FACTOR=${PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_LOG_USART_CLOCK_GENERATOR_SCALING_FACTOR},>"
    )
endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING} )

add_library(
    picolibrary-microchip-megaavr0-version
    "${CMAKE_CURRENT_BINARY_DIR}/picolibrary/microchip/megaavr0/version.cc"
)
target_include_directories(
    picolibrary-microchip-megaavr0-version
    PUBLIC "${PROJECT_SOURCE_DIR}/include"
)
target_link_libraries(
    picolibrary-microchip-megaavr0-version
    picolibrary
)

if( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING} )
    add_library(
        picolibrary-microchip-megaavr0-testing-interactive-fatal_error STATIC
        "picolibrary/testing/interactive/microchip/megaavr0/fatal_error.cc"
    )
    target_link_libraries(
        picolibrary-microchip-megaavr0-testing-interactive-fatal_error
        picolibrary
        picolibrary-microchip-megaavr0
    )
endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING} )
