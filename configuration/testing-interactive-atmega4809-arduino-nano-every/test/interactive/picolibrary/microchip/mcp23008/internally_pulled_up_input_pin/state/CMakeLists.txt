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

# Description: picolibrary-microchip-megaavr0 ATmega4809 Arduino Nano Every
#       picolibrary::Microchip::MCP23008::Internally_Pulled_Up_Input_Pin state interactive
#       test configuration.

set( PICOLIBRARY_MICROCHIP_MCP23008_INTERNALLY_PULLED_UP_INPUT_PIN_ENABLE_STATE_INTERACTIVE_TEST ON CACHE INTERNAL "" )

set( PICOLIBRARY_MICROCHIP_MCP23008_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_CONTROLLER_TWI "TWI0" CACHE INTERNAL "" )

set(
    PICOLIBRARY_MICROCHIP_MCP23008_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_CONTROLLER_TWI_SDA_HOLD_TIME
    "OFF" CACHE STRING
    "picolibrary-microchip-megaavr0: picolibrary::Microchip::MCP23008::Internally_Pulled_Up_Input_Pin state interactive test controller TWI SDA hold time"
)
set(
    PICOLIBRARY_MICROCHIP_MCP23008_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_CONTROLLER_TWI_BUS_SPEED
    "FAST_PLUS" CACHE STRING
    "picolibrary-microchip-megaavr0: picolibrary::Microchip::MCP23008::Internally_Pulled_Up_Input_Pin state interactive test controller TWI bus speed"
)
set(
    PICOLIBRARY_MICROCHIP_MCP23008_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_CONTROLLER_TWI_CLOCK_GENERATOR_SCALING_FACTOR
    "2" CACHE STRING
    "picolibrary-microchip-megaavr0: picolibrary::Microchip::MCP23008::Internally_Pulled_Up_Input_Pin state interactive test controller TWI clock generator scaling factor"
)
set(
    PICOLIBRARY_MICROCHIP_MCP23008_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_CONTROLLER_TWI_INACTIVE_BUS_TIME_OUT
    "DISABLED" CACHE STRING
    "picolibrary-microchip-megaavr0: picolibrary::Microchip::MCP23008::Internally_Pulled_Up_Input_Pin state interactive test controller TWI inactive bus time-out"
)
set(
    PICOLIBRARY_MICROCHIP_MCP23008_INTERNALLY_PULLED_UP_INPUT_PIN_STATE_INTERACTIVE_TEST_CONTROLLER_TWI_ROUTE
    "DEFAULT" CACHE STRING
    "picolibrary-microchip-megaavr0: picolibrary::Microchip::MCP23008::Internally_Pulled_Up_Input_Pin state interactive test controller TWI route"
)
