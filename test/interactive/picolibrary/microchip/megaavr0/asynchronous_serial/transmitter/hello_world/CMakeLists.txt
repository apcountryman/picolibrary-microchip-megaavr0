# picolibrary-microchip-megaavr0
#
# Copyright 2021-2024, Andrew Countryman <apcountryman@gmail.com> and the
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

# Description: picolibrary::Microchip::megaAVR0::Asynchronous_Serial::Transmitter hello
#       world interactive test CMake rules.

# picolibrary::Microchip::megaAVR0::Asynchronous_Serial::Transmitter hello world
# interactive test
if( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING} )
    option(
        PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_TRANSMITTER_ENABLE_HELLO_WORLD_INTERACTIVE_TEST
        "picolibrary-microchip-megaavr0: enable the picolibrary::Microchip::megaAVR0::Asynchronous_Serial::Transmitter hello world interactive test"
        OFF
    )

    if( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_TRANSMITTER_ENABLE_HELLO_WORLD_INTERACTIVE_TEST} )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_TRANSMITTER_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_DATA_TYPE
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::megaAVR0::Asynchronous_Serial::Transmitter hello world interactive test transmitter data type"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_TRANSMITTER_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_USART
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::megaAVR0::Asynchronous_Serial::Transmitter hello world interactive test transmitter USART"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_TRANSMITTER_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_USART_DATA_BITS
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::megaAVR0::Asynchronous_Serial::Transmitter hello world interactive test transmitter USART data bits"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_TRANSMITTER_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_USART_PARITY
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::megaAVR0::Asynchronous_Serial::Transmitter hello world interactive test transmitter USART parity"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_TRANSMITTER_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_USART_STOP_BITS
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::megaAVR0::Asynchronous_Serial::Transmitter hello world interactive test transmitter USART stop bits"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_TRANSMITTER_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_USART_CLOCK_GENERATOR_OPERATING_SPEED
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::megaAVR0::Asynchronous_Serial::Transmitter hello world interactive test transmitter USART clock generator operating speed"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_TRANSMITTER_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_USART_CLOCK_GENERATOR_SCALING_FACTOR
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::megaAVR0::Asynchronous_Serial::Transmitter hello world interactive test transmitter USART clock generator scaling factor"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_TRANSMITTER_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_USART_ROUTE
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::megaAVR0::Asynchronous_Serial::Transmitter hello world interactive test transmitter USART route"
        )

        add_executable(
            test-interactive-picolibrary-microchip-megaavr0-asynchronous_serial-transmitter-hello_world
            main.cc
        )
        target_compile_definitions(
            test-interactive-picolibrary-microchip-megaavr0-asynchronous_serial-transmitter-hello_world
            PRIVATE TRANSMITTER_DATA_TYPE=${PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_TRANSMITTER_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_DATA_TYPE}
            PRIVATE TRANSMITTER_USART=${PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_TRANSMITTER_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_USART}
            PRIVATE TRANSMITTER_USART_DATA_BITS=${PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_TRANSMITTER_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_USART_DATA_BITS}
            PRIVATE TRANSMITTER_USART_PARITY=${PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_TRANSMITTER_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_USART_PARITY}
            PRIVATE TRANSMITTER_USART_STOP_BITS=${PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_TRANSMITTER_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_USART_STOP_BITS}
            PRIVATE TRANSMITTER_USART_CLOCK_GENERATOR_OPERATING_SPEED=${PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_TRANSMITTER_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_USART_CLOCK_GENERATOR_OPERATING_SPEED}
            PRIVATE TRANSMITTER_USART_CLOCK_GENERATOR_SCALING_FACTOR=${PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_TRANSMITTER_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_USART_CLOCK_GENERATOR_SCALING_FACTOR}
            PRIVATE TRANSMITTER_USART_ROUTE=${PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_TRANSMITTER_HELLO_WORLD_INTERACTIVE_TEST_TRANSMITTER_USART_ROUTE}
        )
        target_link_libraries(
            test-interactive-picolibrary-microchip-megaavr0-asynchronous_serial-transmitter-hello_world
            picolibrary
            picolibrary-microchip-megaavr0
            picolibrary-microchip-megaavr0-testing-interactive-fatal_error
        )
        add_avrdude_flash_programming_targets(
            test-interactive-picolibrary-microchip-megaavr0-asynchronous_serial-transmitter-hello_world
            "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_RESET}"
            CONFIGURATION_FILE "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_CONFIGURATION_FILE}"
            PORT               "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_PORT}"
            VERBOSITY          "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_VERBOSITY}"
            PROGRAM            "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_PROGRAM_FLASH}"
            VERIFY             "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_VERIFY_FLASH}"
        )
    endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_TRANSMITTER_ENABLE_HELLO_WORLD_INTERACTIVE_TEST} )
endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING} )
