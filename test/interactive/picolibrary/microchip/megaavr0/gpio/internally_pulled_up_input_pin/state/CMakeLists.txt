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

# File: test/interactive/picolibrary/microchip/megaavr0/gpio/internally_pulled_up_input_pin/state/CMakeLists.txt
# Description: picolibrary::Microchip::megaAVR0::GPIO::Internally_Pulled_Up_Input_Pin
#       state interactive test CMake rules.

# build the picolibrary::Microchip::megaAVR0::GPIO::Internally_Pulled_Up_Input_Pin state
# interactive test
if( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING} )
    option(
        PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INTERNALLY_PULLED_UP_INPUT_PIN_ENABLE_STATE_INTERACTIVE_TEST
        "picolibrary-microchip-megaavr0: enable the picolibrary::Microchip::megaAVR0::GPIO::Internally_Pulled_Up_Input_Pin state interactive test"
        OFF
    )

    if( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INTERNALLY_PULLED_UP_INPUT_PIN_ENABLE_STATE_INTERACTIVE_TEST} )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_CLOCK_PRESCALER_VALUE
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::megaAVR0::GPIO::Internally_Pulled_Up_Input_Pin state interactive test clock prescaler value"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_CLOCK_PRESCALER_CONFIGURATION
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::megaAVR0::GPIO::Internally_Pulled_Up_Input_Pin state interactive test clock prescaler configuration"
        )

        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_TRANSMITTER_USART
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::megaAVR0::GPIO::Internally_Pulled_Up_Input_Pin state interactive test transmitter USART"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_TRANSMITTER_USART_ROUTE
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::megaAVR0::GPIO::Internally_Pulled_Up_Input_Pin state interactive test transmitter USART route"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_TRANSMITTER_CLOCK_GENERATOR_OPERATING_SPEED
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::megaAVR0::GPIO::Internally_Pulled_Up_Input_Pin state interactive test transmitter clock generator operating speed"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_TRANSMITTER_CLOCK_GENERATOR_SCALING_FACTOR
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::megaAVR0::GPIO::Internally_Pulled_Up_Input_Pin state interactive test transmitter clock generator scaling factor"
        )

        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_PIN_PORT
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::megaAVR0::GPIO::Internally_Pulled_Up_Input_Pin state interactive test pin PORT"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_PIN_MASK
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::megaAVR0::GPIO::Internally_Pulled_Up_Input_Pin state interactive test pin MASK"
        )

        add_executable(
            test-interactive-picolibrary-microchip-megaavr0-gpio-internally_pulled_up_input_pin-state
            main.cc
        )
        target_compile_definitions(
            test-interactive-picolibrary-microchip-megaavr0-gpio-internally_pulled_up_input_pin-state
            PRIVATE CLOCK_PRESCALER_VALUE=${PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_CLOCK_PRESCALER_VALUE}
            PRIVATE CLOCK_PRESCALER_CONFIGURATION=${PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_CLOCK_PRESCALER_CONFIGURATION}
            PRIVATE TRANSMITTER_USART=${PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_TRANSMITTER_USART}
            PRIVATE TRANSMITTER_USART_ROUTE=${PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_TRANSMITTER_USART_ROUTE}
            PRIVATE TRANSMITTER_CLOCK_GENERATOR_OPERATING_SPEED=${PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_TRANSMITTER_CLOCK_GENERATOR_OPERATING_SPEED}
            PRIVATE TRANSMITTER_CLOCK_GENERATOR_SCALING_FACTOR=${PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_TRANSMITTER_CLOCK_GENERATOR_SCALING_FACTOR}
            PRIVATE PIN_PORT=${PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_PIN_PORT}
            PRIVATE PIN_MASK=${PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_PIN_MASK}
        )
        target_link_libraries(
            test-interactive-picolibrary-microchip-megaavr0-gpio-internally_pulled_up_input_pin-state
            picolibrary-fatal_error
            picolibrary-microchip-megaavr0
        )
        add_avrdude_programming_targets(
            test-interactive-picolibrary-microchip-megaavr0-gpio-internally_pulled_up_input_pin-state
            "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_RESET}"
            CONFIGURATION_FILE "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_CONFIGURATION_FILE}"
            PORT               "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_PORT}"
            PROGRAM_FLASH      ${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_PROGRAM_FLASH}
            VERBOSITY          "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_VERBOSITY}"
            VERIFY_FLASH       ${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_VERIFY_FLASH}
        )
    endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INTERNALLY_PULLED_UP_INPUT_PIN_ENABLE_STATE_INTERACTIVE_TEST} )
endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING} )
