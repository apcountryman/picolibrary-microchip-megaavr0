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

# Description: picolibrary::Microchip::megaAVR0::SPI::Fixed_Configuration_Controller<Peripheral::SPI>
#       echo interactive test CMake rules.

# picolibrary::Microchip::megaAVR0::SPI::Fixed_Configuration_Controller<Peripheral::SPI>
# echo interactive test
if( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING} )
    option(
        PICOLIBRARY_MICROCHIP_MEGAAVR0_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ENABLE_ECHO_INTERACTIVE_TEST
        "picolibrary-microchip-megaavr0: enable the picolibrary::Microchip::megaAVR0::SPI::Fixed_Configuration_Controller<Peripheral::SPI> echo interactive test"
        OFF
    )

    if( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ENABLE_ECHO_INTERACTIVE_TEST} )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR0_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::megaAVR0::SPI::Fixed_Configuration_Controller<Peripheral::SPI> echo interactive test controller SPI"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR0_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_RATE
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::megaAVR0::SPI::Fixed_Configuration_Controller<Peripheral::SPI> echo interactive test controller SPI clock rate"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR0_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_POLARITY
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::megaAVR0::SPI::Fixed_Configuration_Controller<Peripheral::SPI> echo interactive test controller SPI clock polarity"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR0_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_PHASE
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::megaAVR0::SPI::Fixed_Configuration_Controller<Peripheral::SPI> echo interactive test controller SPI clock phase"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR0_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_BIT_ORDER
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::megaAVR0::SPI::Fixed_Configuration_Controller<Peripheral::SPI> echo interactive test controller SPI bit order"
        )
        set(
            PICOLIBRARY_MICROCHIP_MEGAAVR0_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_ROUTE
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Microchip::megaAVR0::SPI::Fixed_Configuration_Controller<Peripheral::SPI> echo interactive test controller SPI route"
        )

        add_executable(
            test-interactive-picolibrary-microchip-megaavr0-spi-fixed_configuration_controller-spi-echo
            main.cc
        )
        target_compile_definitions(
            test-interactive-picolibrary-microchip-megaavr0-spi-fixed_configuration_controller-spi-echo
            PRIVATE CONTROLLER_SPI=${PICOLIBRARY_MICROCHIP_MEGAAVR0_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI}
            PRIVATE CONTROLLER_SPI_CLOCK_RATE=${PICOLIBRARY_MICROCHIP_MEGAAVR0_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_RATE}
            PRIVATE CONTROLLER_SPI_CLOCK_POLARITY=${PICOLIBRARY_MICROCHIP_MEGAAVR0_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_POLARITY}
            PRIVATE CONTROLLER_SPI_CLOCK_PHASE=${PICOLIBRARY_MICROCHIP_MEGAAVR0_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_PHASE}
            PRIVATE CONTROLLER_SPI_BIT_ORDER=${PICOLIBRARY_MICROCHIP_MEGAAVR0_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_BIT_ORDER}
            PRIVATE CONTROLLER_SPI_ROUTE=${PICOLIBRARY_MICROCHIP_MEGAAVR0_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_ROUTE}
        )
        target_link_libraries(
            test-interactive-picolibrary-microchip-megaavr0-spi-fixed_configuration_controller-spi-echo
            picolibrary
            picolibrary-microchip-megaavr0
            picolibrary-microchip-megaavr0-testing-interactive-fatal_error
        )
        add_avrdude_flash_programming_targets(
            test-interactive-picolibrary-microchip-megaavr0-spi-fixed_configuration_controller-spi-echo
            "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_RESET}"
            CONFIGURATION_FILE "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_CONFIGURATION_FILE}"
            PORT               "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_PORT}"
            VERBOSITY          "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_VERBOSITY}"
            PROGRAM            "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_PROGRAM_FLASH}"
            VERIFY             "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_VERIFY_FLASH}"
        )
    endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_SPI_FIXED_CONFIGURATION_CONTROLLER_SPI_ENABLE_ECHO_INTERACTIVE_TEST} )
endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING} )
