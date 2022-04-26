# picolibrary-microchip-megaavr0
#
# Copyright 2021-2022, Andrew Countryman <apcountryman@gmail.com> and the
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

# Description: picolibrary::Microchip::megaAVR0::GPIO::Input_Pin state interactive test
#       CMake rules.

# build the picolibrary::Microchip::megaAVR0::GPIO::Input_Pin state interactive test
if( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING} )
    option(
        PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INPUT_PIN_ENABLE_STATE_INTERACTIVE_TEST
        "picolibrary-microchip-megaavr0: enable the picolibrary::Microchip::megaAVR0::GPIO::Input_Pin state interactive test"
        OFF
    )

    if( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INPUT_PIN_ENABLE_STATE_INTERACTIVE_TEST} )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INPUT_PIN_STATE_INTERACTIVE_TEST_PIN_PORT
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::megaAVR0::GPIO::Input_Pin state interactive test pin PORT"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INPUT_PIN_STATE_INTERACTIVE_TEST_PIN_VPORT
            "V${PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INPUT_PIN_STATE_INTERACTIVE_TEST_PIN_PORT}"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INPUT_PIN_STATE_INTERACTIVE_TEST_PIN_MASK
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::megaAVR0::GPIO::Input_Pin state interactive test pin mask"
        )

        add_executable(
            test-interactive-picolibrary-microchip-megaavr0-gpio-input_pin-port-state
            main.cc
        )
        target_compile_definitions(
            test-interactive-picolibrary-microchip-megaavr0-gpio-input_pin-port-state
            PRIVATE PIN_PORT=${PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INPUT_PIN_STATE_INTERACTIVE_TEST_PIN_PORT}
            PRIVATE PIN_MASK=${PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INPUT_PIN_STATE_INTERACTIVE_TEST_PIN_MASK}
        )
        target_link_libraries(
            test-interactive-picolibrary-microchip-megaavr0-gpio-input_pin-port-state
            picolibrary
            picolibrary-microchip-megaavr0
            picolibrary-microchip-megaavr0-testing-interactive-fatal_error
        )
        add_avrdude_programming_targets(
            test-interactive-picolibrary-microchip-megaavr0-gpio-input_pin-port-state
            "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_RESET}"
            CONFIGURATION_FILE "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_CONFIGURATION_FILE}"
            PORT               "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_PORT}"
            PROGRAM_FLASH      "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_PROGRAM_FLASH}"
            VERBOSITY          "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_VERBOSITY}"
            VERIFY_FLASH       "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_VERIFY_FLASH}"
        )

        add_executable(
            test-interactive-picolibrary-microchip-megaavr0-gpio-input_pin-vport-state
            main.cc
        )
        target_compile_definitions(
            test-interactive-picolibrary-microchip-megaavr0-gpio-input_pin-vport-state
            PRIVATE PIN_PORT=${PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INPUT_PIN_STATE_INTERACTIVE_TEST_PIN_VPORT}
            PRIVATE PIN_MASK=${PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INPUT_PIN_STATE_INTERACTIVE_TEST_PIN_MASK}
        )
        target_link_libraries(
            test-interactive-picolibrary-microchip-megaavr0-gpio-input_pin-vport-state
            picolibrary
            picolibrary-microchip-megaavr0
            picolibrary-microchip-megaavr0-testing-interactive-fatal_error
        )
        add_avrdude_programming_targets(
            test-interactive-picolibrary-microchip-megaavr0-gpio-input_pin-vport-state
            "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_RESET}"
            CONFIGURATION_FILE "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_CONFIGURATION_FILE}"
            PORT               "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_PORT}"
            PROGRAM_FLASH      "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_PROGRAM_FLASH}"
            VERBOSITY          "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_VERBOSITY}"
            VERIFY_FLASH       "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_VERIFY_FLASH}"
        )
    endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INPUT_PIN_ENABLE_STATE_INTERACTIVE_TEST} )
endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING} )
