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
 * \brief picolibrary::Microchip::megaAVR0::SPI::Controller<picolibrary::Microchip::megaAVR0::Peripheral::SPI>
 *        echo interactive test program.
 */

#include <avr-libcpp/delay>

#include "picolibrary/asynchronous_serial/stream.h"
#include "picolibrary/microchip/megaavr0/asynchronous_serial.h"
#include "picolibrary/microchip/megaavr0/clock.h"
#include "picolibrary/microchip/megaavr0/multiplexed_signals.h"
#include "picolibrary/microchip/megaavr0/peripheral.h"
#include "picolibrary/microchip/megaavr0/peripheral/spi.h"
#include "picolibrary/microchip/megaavr0/spi.h"
#include "picolibrary/testing/interactive/microchip/megaavr0/clock.h"
#include "picolibrary/testing/interactive/spi.h"

namespace {

using namespace ::picolibrary::Microchip::megaAVR0::Peripheral;

using ::picolibrary::Asynchronous_Serial::Unbuffered_Output_Stream;
using ::picolibrary::Microchip::megaAVR0::Asynchronous_Serial::Clock_Configuration;
using ::picolibrary::Microchip::megaAVR0::Asynchronous_Serial::Transmitter_8_N_1;
using ::picolibrary::Microchip::megaAVR0::Clock::Prescaler;
using ::picolibrary::Microchip::megaAVR0::Clock::Prescaler_Value;
using ::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::set_spi_route;
using ::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::set_usart_route;
using ::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::SPI_Route;
using ::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::USART_Route;
using ::picolibrary::Microchip::megaAVR0::Peripheral::SPI;
using ::picolibrary::Testing::Interactive::Microchip::megaAVR0::configure_clock;
using ::picolibrary::Testing::Interactive::SPI::echo;

using Controller = ::picolibrary::Microchip::megaAVR0::SPI::Controller<SPI>;

} // namespace

/**
 * \brief Execute the
 *        picolibrary::Microchip::megaAVR0::SPI::Controller<picolibrary::Microchip::megaAVR0::Peripheral::SPI>
 *        echo interactive test.
 *
 * \return 0.
 */
int main()
{
    configure_clock( Prescaler_Value::CLOCK_PRESCALER_VALUE, Prescaler::CLOCK_PRESCALER_CONFIGURATION );

    set_usart_route( TRANSMITTER_USART::instance(), USART_Route::TRANSMITTER_USART_ROUTE );

    set_spi_route( CONTROLLER_SPI::instance(), SPI_Route::CONTROLLER_SPI_ROUTE );

    echo<Unbuffered_Output_Stream>(
        Transmitter_8_N_1{ TRANSMITTER_USART::instance(),
                           { .operating_speed = Clock_Configuration::Operating_Speed::TRANSMITTER_CLOCK_GENERATOR_OPERATING_SPEED,
                             .scaling_factor = TRANSMITTER_CLOCK_GENERATOR_SCALING_FACTOR } },
        Controller{ CONTROLLER_SPI::instance() },
        { .clock_rate     = SPI::Clock_Rate::CONTROLLER_CLOCK_RATE,
          .clock_polarity = SPI::Clock_Polarity::CONTROLLER_CLOCK_POLARITY,
          .clock_phase    = SPI::Clock_Phase::CONTROLLER_CLOCK_PHASE,
          .bit_order      = SPI::Bit_Order::CONTROLLER_BIT_ORDER },
        []() { avrlibcpp::delay_ms( 100 ); } );

    for ( ;; ) {}
}
