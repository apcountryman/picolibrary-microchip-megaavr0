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

# Description: picolibrary::Texas_Instruments::TCA9548A::Driver scan interactive test
#       CMake rules.

# picolibrary::Texas_Instruments::TCA9548A::Driver scan interactive test
if( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING} )
    option(
        PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_ENABLE_SCAN_INTERACTIVE_TEST
        "picolibrary-microchip-megaavr0: enable the picolibrary::Texas_Instruments::TCA9548A::Driver scan interactive test"
        OFF
    )

    if( ${PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_ENABLE_SCAN_INTERACTIVE_TEST} )
        set(
            PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Texas_Instruments::TCA9548A::Driver scan interactive test controller TWI"
        )
        set(
            PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_SDA_HOLD_TIME
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Texas_Instruments::TCA9548A::Driver scan interactive test controller TWI SDA hold time"
        )
        set(
            PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_BUS_SPEED
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Texas_Instruments::TCA9548A::Driver scan interactive test controller TWI bus speed"
        )
        set(
            PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_CLOCK_GENERATOR_SCALING_FACTOR
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Texas_Instruments::TCA9548A::Driver scan interactive test controller TWI clock generator scaling factor"
        )
        set(
            PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_INACTIVE_BUS_TIME_OUT
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Texas_Instruments::TCA9548A::Driver scan interactive test controller TWI inactive bus time-out"
        )
        set(
            PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_ROUTE
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Texas_Instruments::TCA9548A::Driver scan interactive test controller TWI route"
        )

        set(
            PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_SCAN_INTERACTIVE_TEST_TCA9548A_ADDRESS
            "Address_Numeric{ 0b1110'000 }" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::Texas_Instruments::TCA9548A::Driver scan interactive test TCA9548A address"
        )

        add_executable(
            test-interactive-picolibrary-texas_instruments-tca9548a-driver-scan
            main.cc
        )
        target_compile_definitions(
            test-interactive-picolibrary-texas_instruments-tca9548a-driver-scan
            PRIVATE CONTROLLER_TWI=${PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI}
            PRIVATE CONTROLLER_TWI_SDA_HOLD_TIME=${PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_SDA_HOLD_TIME}
            PRIVATE CONTROLLER_TWI_BUS_SPEED=${PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_BUS_SPEED}
            PRIVATE CONTROLLER_TWI_CLOCK_GENERATOR_SCALING_FACTOR=${PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_CLOCK_GENERATOR_SCALING_FACTOR}
            PRIVATE CONTROLLER_TWI_INACTIVE_BUS_TIME_OUT=${PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_INACTIVE_BUS_TIME_OUT}
            PRIVATE CONTROLLER_TWI_ROUTE=${PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_ROUTE}
            PRIVATE TCA9548A_ADDRESS=${PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_SCAN_INTERACTIVE_TEST_TCA9548A_ADDRESS}
        )
        target_link_libraries(
            test-interactive-picolibrary-texas_instruments-tca9548a-driver-scan
            picolibrary
            picolibrary-microchip-megaavr0
            picolibrary-microchip-megaavr0-testing-interactive-fatal_error
        )
        add_avrdude_flash_programming_targets(
            test-interactive-picolibrary-texas_instruments-tca9548a-driver-scan
            "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_RESET}"
            CONFIGURATION_FILE "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_CONFIGURATION_FILE}"
            PORT               "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_PORT}"
            VERBOSITY          "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_VERBOSITY}"
            PROGRAM            "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_PROGRAM_FLASH}"
            VERIFY             "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_VERIFY_FLASH}"
        )
    endif( ${PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_ENABLE_SCAN_INTERACTIVE_TEST} )
endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING} )
