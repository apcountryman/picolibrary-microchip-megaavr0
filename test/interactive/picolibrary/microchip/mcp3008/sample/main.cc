/**
 * picolibrary-microchip-megaavr0
 *
 * Copyright 2021, Andrew Countryman <apcountryman@gmail.com> and the
 * picolibrary-microchip-megaavr0 contributors
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not use this
 * file except in compliance with the License. You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software distributed under
 * the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

/**
 * \file
 * \brief picolibrary::Microchip::MCP3008 sample interactive test program.
 */

#include <avr-libcpp/delay>

#include "picolibrary/asynchronous_serial/stream.h"
#include "picolibrary/gpio.h"
#include "picolibrary/microchip/mcp3008.h"
#include "picolibrary/microchip/megaavr0/asynchronous_serial.h"
#include "picolibrary/microchip/megaavr0/clock.h"
#include "picolibrary/microchip/megaavr0/gpio.h"
#include "picolibrary/microchip/megaavr0/multiplexed_signals.h"
#include "picolibrary/microchip/megaavr0/peripheral.h"
#include "picolibrary/microchip/megaavr0/peripheral/port.h"
#include "picolibrary/microchip/megaavr0/peripheral/spi.h"
#include "picolibrary/microchip/megaavr0/peripheral/usart.h"
#include "picolibrary/microchip/megaavr0/spi.h"
#include "picolibrary/spi.h"
#include "picolibrary/testing/interactive/microchip/mcp3008.h"
#include "picolibrary/testing/interactive/microchip/megaavr0/clock.h"

namespace {

using namespace ::picolibrary::Microchip::megaAVR0::Peripheral;

using ::picolibrary::Asynchronous_Serial::Unbuffered_Output_Stream;
using ::picolibrary::GPIO::Active_Low_IO_Pin;
using ::picolibrary::Microchip::MCP3008::Channel;
using ::picolibrary::Microchip::MCP3008::Channel_Pair;
using ::picolibrary::Microchip::megaAVR0::Asynchronous_Serial::Transmitter_8_N_1;
using ::picolibrary::Microchip::megaAVR0::Clock::Prescaler;
using ::picolibrary::Microchip::megaAVR0::Clock::Prescaler_Value;
using ::picolibrary::Microchip::megaAVR0::GPIO::Push_Pull_IO_Pin;
using ::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::ds_mask;
using ::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::ds_port;
using ::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::set_spi_route;
using ::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::set_usart_route;
using ::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::SPI_Route;
using ::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::USART_Route;
using ::picolibrary::Microchip::megaAVR0::Peripheral::PORT;
using ::picolibrary::Microchip::megaAVR0::Peripheral::SPI;
using ::picolibrary::Microchip::megaAVR0::Peripheral::USART;
using ::picolibrary::SPI::GPIO_Output_Pin_Device_Selector;
using ::picolibrary::Testing::Interactive::Microchip::MCP3008::sample;
using ::picolibrary::Testing::Interactive::Microchip::megaAVR0::configure_clock;

using Fixed_Configuration_Controller = ::picolibrary::Microchip::megaAVR0::SPI::Fixed_Configuration_Controller<SPI>;

} // namespace

/**
 * \brief Execute the picolibrary::Microchip::MCP3008 sample interactive test.
 *
 * \return 0.
 */
int main()
{
    configure_clock( Prescaler_Value::CLOCK_PRESCALER_VALUE, Prescaler::CLOCK_PRESCALER_CONFIGURATION );

    set_usart_route( TRANSMITTER_USART::instance(), USART_Route::TRANSMITTER_USART_ROUTE );

    set_spi_route( CONTROLLER_SPI::instance(), SPI_Route::CONTROLLER_SPI_ROUTE );

    sample<Unbuffered_Output_Stream>(
        Transmitter_8_N_1{ TRANSMITTER_USART::instance(),
                           { .operating_speed = USART::Operating_Speed::TRANSMITTER_CLOCK_GENERATOR_OPERATING_SPEED,
                             .scaling_factor = TRANSMITTER_CLOCK_GENERATOR_SCALING_FACTOR } },
        Fixed_Configuration_Controller{ CONTROLLER_SPI::instance(),
                                        SPI::Clock_Rate::CONTROLLER_CLOCK_RATE,
                                        SPI::Clock_Polarity::IDLE_LOW,
                                        SPI::Clock_Phase::CAPTURE_IDLE_TO_ACTIVE,
                                        SPI::Bit_Order::MSB_FIRST },
        {},
        GPIO_Output_Pin_Device_Selector<Active_Low_IO_Pin<Push_Pull_IO_Pin<PORT>>>{
            ds_port( CONTROLLER_SPI::instance() ), ds_mask( CONTROLLER_SPI::instance() ) },
        MCP3008_INPUT,
        []() { avrlibcpp::delay_ms( 1000 ); } );

    for ( ;; ) {}
}
