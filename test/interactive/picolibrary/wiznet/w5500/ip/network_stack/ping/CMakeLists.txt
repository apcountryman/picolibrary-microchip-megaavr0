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

# Description: picolibrary::WIZnet::W5500::IP::Network_Stack ping interactive test CMake
#       rules.

# picolibrary::WIZnet::W5500::IP::Network_Stack ping interactive test
if( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING} )
    option(
        PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_ENABLE_PING_INTERACTIVE_TEST
        "picolibrary-microchip-megaavr0: enable the picolibrary::WIZnet::W5500::IP::Network_Stack ping interactive test"
        OFF
    )

    if( ${PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_ENABLE_PING_INTERACTIVE_TEST} )
        set(
            PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_CONTROLLER_SPI
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::WIZnet::W5500::IP::Network_Stack ping interactive test controller SPI"
        )
        set(
            PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_RATE
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::WIZnet::W5500::IP::Network_Stack ping interactive test controller SPI clock rate"
        )
        set(
            PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_POLARITY
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::WIZnet::W5500::IP::Network_Stack ping interactive test controller SPI clock polarity"
        )
        set(
            PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_PHASE
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::WIZnet::W5500::IP::Network_Stack ping interactive test controller SPI clock phase"
        )
        set(
            PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_CONTROLLER_SPI_ROUTE
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::WIZnet::W5500::IP::Network_Stack ping interactive test controller SPI route"
        )

        set(
            PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_DEVICE_SELECTOR_PORT
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::WIZnet::W5500::IP::Network_Stack ping interactive test device selector PORT"
        )
        set(
            PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_DEVICE_SELECTOR_MASK
            "" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::WIZnet::W5500::IP::Network_Stack ping interactive test device selector mask"
        )

        set(
            PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_NETWORK_STACK_PHY_MODE
            "ALL_CAPABLE_AUTO_NEGOTIATION_ENABLED" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::WIZnet::W5500::IP::Network_Stack ping interactive test network stack PHY mode"
        )

        set(
            PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_NETWORK_STACK_ARP_FORCING_CONFIGURATION
            "DISABLED" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::WIZnet::W5500::IP::Network_Stack ping interactive test network stack ARP forcing configuration"
        )

        set(
            PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_NETWORK_STACK_RETRANSMISSION_RETRY_TIME
            "2000" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::WIZnet::W5500::IP::Network_Stack ping interactive test network stack retransmission retry time"
        )
        set(
            PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_NETWORK_STACK_RETRANSMISSION_RETRY_COUNT
            "8" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::WIZnet::W5500::IP::Network_Stack ping interactive test network stack retransmission retry count"
        )

        set(
            PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_NETWORK_STACK_MAC_ADDRESS
            "0x02,0x00,0x00,0x00,0x00,0x00" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::WIZnet::W5500::IP::Network_Stack ping interactive test network stack MAC address"
        )

        set(
            PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_NETWORK_STACK_IPV4_ADDRESS
            "0,0,0,0" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::WIZnet::W5500::IP::Network_Stack ping interactive test network stack IPv4 address"
        )
        set(
            PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_NETWORK_STACK_IPV4_GATEWAY_ADDRESS
            "0,0,0,0" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::WIZnet::W5500::IP::Network_Stack ping interactive test network stack IPv4 gateway address"
        )
        set(
            PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_NETWORK_STACK_IPV4_SUBNET_MASK
            "255,255,255,255" CACHE STRING
            "picolibrary-microchip-megaavr0: picolibrary::WIZnet::W5500::IP::Network_Stack ping interactive test network stack IPv4 subnet mask"
        )

        add_executable(
            test-interactive-picolibrary-wiznet-w5500-ip-network_stack-ping
            main.cc
        )
        target_compile_definitions(
            test-interactive-picolibrary-wiznet-w5500-ip-network_stack-ping
            PRIVATE CONTROLLER_SPI=${PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_CONTROLLER_SPI}
            PRIVATE CONTROLLER_SPI_CLOCK_RATE=${PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_RATE}
            PRIVATE CONTROLLER_SPI_CLOCK_POLARITY=${PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_POLARITY}
            PRIVATE CONTROLLER_SPI_CLOCK_PHASE=${PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_CONTROLLER_SPI_CLOCK_PHASE}
            PRIVATE CONTROLLER_SPI_ROUTE=${PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_CONTROLLER_SPI_ROUTE}
            PRIVATE DEVICE_SELECTOR_PORT=${PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_DEVICE_SELECTOR_PORT}
            PRIVATE DEVICE_SELECTOR_MASK=${PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_DEVICE_SELECTOR_MASK}
            PRIVATE NETWORK_STACK_PHY_MODE=${PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_NETWORK_STACK_PHY_MODE}
            PRIVATE NETWORK_STACK_ARP_FORCING_CONFIGURATION=${PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_NETWORK_STACK_ARP_FORCING_CONFIGURATION}
            PRIVATE NETWORK_STACK_RETRANSMISSION_RETRY_TIME=${PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_NETWORK_STACK_RETRANSMISSION_RETRY_TIME}
            PRIVATE NETWORK_STACK_RETRANSMISSION_RETRY_COUNT=${PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_NETWORK_STACK_RETRANSMISSION_RETRY_COUNT}
            PRIVATE NETWORK_STACK_MAC_ADDRESS=${PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_NETWORK_STACK_MAC_ADDRESS}
            PRIVATE NETWORK_STACK_IPV4_ADDRESS=${PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_NETWORK_STACK_IPV4_ADDRESS}
            PRIVATE NETWORK_STACK_IPV4_GATEWAY_ADDRESS=${PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_NETWORK_STACK_IPV4_GATEWAY_ADDRESS}
            PRIVATE NETWORK_STACK_IPV4_SUBNET_MASK=${PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_PING_INTERACTIVE_TEST_NETWORK_STACK_IPV4_SUBNET_MASK}
        )
        target_link_libraries(
            test-interactive-picolibrary-wiznet-w5500-ip-network_stack-ping
            picolibrary
            picolibrary-microchip-megaavr0
            picolibrary-microchip-megaavr0-testing-interactive-fatal_error
        )
        add_avrdude_flash_programming_targets(
            test-interactive-picolibrary-wiznet-w5500-ip-network_stack-ping
            "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_RESET}"
            CONFIGURATION_FILE "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_CONFIGURATION_FILE}"
            PORT               "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_PORT}"
            VERBOSITY          "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_VERBOSITY}"
            PROGRAM            "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_PROGRAM_FLASH}"
            VERIFY             "${PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_VERIFY_FLASH}"
        )
    endif( ${PICOLIBRARY_WIZNET_W5500_IP_NETWORK_STACK_ENABLE_PING_INTERACTIVE_TEST} )
endif( ${PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING} )
