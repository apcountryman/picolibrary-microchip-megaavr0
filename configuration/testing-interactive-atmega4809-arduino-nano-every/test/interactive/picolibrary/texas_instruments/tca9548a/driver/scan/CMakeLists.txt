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

# Description: picolibrary-microchip-megaavr0 ATmega4809 Arduino Nano Every
#       picolibrary::Texas_Instruments::TCA9548A::Driver scan interactive test
#       configuration.

set( PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_ENABLE_SCAN_INTERACTIVE_TEST ON CACHE INTERNAL "" )

set( PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI "TWI0" CACHE INTERNAL "" )

set(
    PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_SDA_HOLD_TIME
    "OFF" CACHE STRING
    "picolibrary-microchip-megaavr0: picolibrary::Texas_Instruments::TCA9548A::Driver scan interactive test controller TWI SDA hold time"
)
set(
    PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_BUS_SPEED
    "STANDARD" CACHE STRING
    "picolibrary-microchip-megaavr0: picolibrary::Texas_Instruments::TCA9548A::Driver scan interactive test controller TWI bus speed"
)
set(
    PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_CLOCK_GENERATOR_SCALING_FACTOR
    "73" CACHE STRING
    "picolibrary-microchip-megaavr0: picolibrary::Texas_Instruments::TCA9548A::Driver scan interactive test controller TWI clock generator scaling factor"
)
set(
    PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_INACTIVE_BUS_TIME_OUT
    "DISABLED" CACHE STRING
    "picolibrary-microchip-megaavr0: picolibrary::Texas_Instruments::TCA9548A::Driver scan interactive test controller TWI inactive bus time-out"
)
set(
    PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_ROUTE
    "DEFAULT" CACHE STRING
    "picolibrary-microchip-megaavr0: picolibrary::Texas_Instruments::TCA9548A::Driver scan interactive test controller TWI route"
)
