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
#       picolibrary::Microchip::megaAVR0::GPIO::Input_Pin state interactive test
#       configuration.

set( PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INPUT_PIN_ENABLE_STATE_INTERACTIVE_TEST ON CACHE INTERNAL "" )

set(
    PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INPUT_PIN_STATE_INTERACTIVE_TEST_PIN_PORT
    "PORTA" CACHE STRING
    "picolibrary-microchip-megaavr0: picolibrary::Microchip::megaAVR0::GPIO::Input_Pin state interactive test pin PORT"
)
set(
    PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INPUT_PIN_STATE_INTERACTIVE_TEST_PIN_MASK
    "1 << 0" CACHE STRING
    "picolibrary-microchip-megaavr0: picolibrary::Microchip::megaAVR0::GPIO::Input_Pin state interactive test pin mask"
)
