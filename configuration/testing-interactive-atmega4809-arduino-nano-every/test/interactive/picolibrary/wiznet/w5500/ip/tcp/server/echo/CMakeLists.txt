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
#       picolibrary::WIZnet::W5500::IP::TCP::Server echo interactive test configuration.

set( PICOLIBRARY_WIZNET_W5500_IP_TCP_SERVER_ENABLE_ECHO_INTERACTIVE_TEST ON CACHE INTERNAL "" )

set( PICOLIBRARY_WIZNET_W5500_IP_TCP_SERVER_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI "SPI0" CACHE INTERNAL "" )

set(
    PICOLIBRARY_WIZNET_W5500_IP_TCP_SERVER_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_RATE
    "CLK_PER_2" CACHE STRING
    "picolibrary-microchip-megaavr0: picolibrary::WIZnet::W5500::IP::TCP::Server echo interactive test controller SPI clock rate"
)
set(
    PICOLIBRARY_WIZNET_W5500_IP_TCP_SERVER_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_POLARITY
    "IDLE_LOW" CACHE STRING
    "picolibrary-microchip-megaavr0: picolibrary::WIZnet::W5500::IP::TCP::Server echo interactive test controller SPI clock polarity"
)
set(
    PICOLIBRARY_WIZNET_W5500_IP_TCP_SERVER_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_PHASE
    "CAPTURE_IDLE_TO_ACTIVE" CACHE STRING
    "picolibrary-microchip-megaavr0: picolibrary::WIZnet::W5500::IP::TCP::Server echo interactive test controller SPI clock phase"
)
set(
    PICOLIBRARY_WIZNET_W5500_IP_TCP_SERVER_ECHO_INTERACTIVE_TEST_CONTROLLER_SPI_ROUTE
    "ALTERNATE_2" CACHE STRING
    "picolibrary-microchip-megaavr0: picolibrary::WIZnet::W5500::IP::TCP::Server echo interactive test controller SPI route"
)

set(
    PICOLIBRARY_WIZNET_W5500_IP_TCP_SERVER_ECHO_INTERACTIVE_TEST_DEVICE_SELECTOR_PORT
    "PORTE" CACHE STRING
    "picolibrary-microchip-megaavr0: picolibrary::WIZnet::W5500::IP::TCP::Server echo interactive test device selector PORT"
)
set(
    PICOLIBRARY_WIZNET_W5500_IP_TCP_SERVER_ECHO_INTERACTIVE_TEST_DEVICE_SELECTOR_MASK
    "1 << 3" CACHE STRING
    "picolibrary-microchip-megaavr0: picolibrary::WIZnet::W5500::IP::TCP::Server echo interactive test device selector mask"
)
