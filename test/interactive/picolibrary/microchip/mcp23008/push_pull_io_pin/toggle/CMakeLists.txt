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

# Description: picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin toggle interactive test
#       CMake rules.

# picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin toggle interactive test
if( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING} )
    option(
        PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_ENABLE_TOGGLE_INTERACTIVE_TEST
        "picolibrary-microchip-megaavr0: enable the picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin toggle interactive test"
        OFF
    )

    if( ${PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_ENABLE_TOGGLE_INTERACTIVE_TEST} )
        set(
            PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_TWI
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin toggle interactive test controller TWI"
        )
        set(
            PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_TWI_SDA_HOLD_TIME
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin toggle interactive test controller TWI SDA hold time"
        )
        set(
            PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_TWI_BUS_SPEED
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin toggle interactive test controller TWI bus speed"
        )
        set(
            PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_TWI_CLOCK_GENERATOR_SCALING_FACTOR
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin toggle interactive test controller TWI clock generator scaling factor"
        )
        set(
            PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_TWI_INACTIVE_BUS_TIME_OUT
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin toggle interactive test controller TWI inactive bus time-out"
        )
        set(
            PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_TWI_ROUTE
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin toggle interactive test controller TWI route"
        )

        set(
            PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_MCP23008_ADDRESS
            "Address_Numeric{ 0b0100'000 }" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin toggle interactive test MCP23008 address"
        )
        set(
            PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_MCP23008_PIN_MASK
            "1 << 0" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::MCP23008::Push_Pull_IO_Pin toggle interactive test MCP23008 pin mask"
        )

        add_executable(
            test-interactive-picolibrary-microchip-mcp23008-push_pull_io_pin-toggle
            main.cc
        )
        target_compile_definitions(
            test-interactive-picolibrary-microchip-mcp23008-push_pull_io_pin-toggle
            PRIVATE CONTROLLER_TWI=${PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_TWI}
            PRIVATE CONTROLLER_TWI_SDA_HOLD_TIME=${PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_TWI_SDA_HOLD_TIME}
            PRIVATE CONTROLLER_TWI_BUS_SPEED=${PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_TWI_BUS_SPEED}
            PRIVATE CONTROLLER_TWI_CLOCK_GENERATOR_SCALING_FACTOR=${PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_TWI_CLOCK_GENERATOR_SCALING_FACTOR}
            PRIVATE CONTROLLER_TWI_INACTIVE_BUS_TIME_OUT=${PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_TWI_INACTIVE_BUS_TIME_OUT}
            PRIVATE CONTROLLER_TWI_ROUTE=${PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_CONTROLLER_TWI_ROUTE}
            PRIVATE MCP23008_ADDRESS=${PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_MCP23008_ADDRESS}
            PRIVATE MCP23008_PIN_MASK=${PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_TOGGLE_INTERACTIVE_TEST_MCP23008_PIN_MASK}
        )
        target_link_libraries(
            test-interactive-picolibrary-microchip-mcp23008-push_pull_io_pin-toggle
            picolibrary
            picolibrary-microchip-megaavr0
            picolibrary-microchip-megaavr0-testing-interactive-fatal_error
        )
        add_avrdude_flash_programming_targets(
            test-interactive-picolibrary-microchip-mcp23008-push_pull_io_pin-toggle
            "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_RESET}"
            CONFIGURATION_FILE "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_CONFIGURATION_FILE}"
            PORT               "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_PORT}"
            VERBOSITY          "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_VERBOSITY}"
            PROGRAM            "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_PROGRAM_FLASH}"
            VERIFY             "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_VERIFY_FLASH}"
        )
    endif( ${PICOLIBRARY_MICROCHIP_MCP23008_PUSH_PULL_IO_PIN_ENABLE_TOGGLE_INTERACTIVE_TEST} )
endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING} )
