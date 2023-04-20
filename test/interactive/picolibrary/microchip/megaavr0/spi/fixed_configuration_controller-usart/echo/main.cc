/**
 * picolibrary-microchip-megaavr0
 *
 * Copyright 2021-2023, Andrew Countryman <apcountryman@gmail.com> and the
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
 * \brief picolibrary::Microchip::megaAVR0::SPI::Fixed_Configuration_Controller<Peripheral::USART>
 *        echo interactive test program.
 */

#include <avr-libcpp/delay>

#include "picolibrary/microchip/megaavr0/multiplexed_signals.h"
#include "picolibrary/microchip/megaavr0/peripheral.h"
#include "picolibrary/microchip/megaavr0/peripheral/usart.h"
#include "picolibrary/microchip/megaavr0/spi.h"
#include "picolibrary/testing/interactive/microchip/megaavr0/clock.h"
#include "picolibrary/testing/interactive/microchip/megaavr0/log.h"
#include "picolibrary/testing/interactive/spi.h"

namespace {

using ::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::USART_Route;
using ::picolibrary::Microchip::megaAVR0::SPI::Fixed_Configuration_Controller;
using ::picolibrary::Microchip::megaAVR0::SPI::USART_Bit_Order;
using ::picolibrary::Microchip::megaAVR0::SPI::USART_Clock_Phase;
using ::picolibrary::Microchip::megaAVR0::SPI::USART_Clock_Polarity;
using ::picolibrary::Testing::Interactive::Microchip::megaAVR0::configure_clock;
using ::picolibrary::Testing::Interactive::Microchip::megaAVR0::Log;
using ::picolibrary::Testing::Interactive::SPI::echo;

using namespace ::picolibrary::Microchip::megaAVR0::Peripheral;

} // namespace

/**
 * \brief Execute the
 *        picolibrary::Microchip::megaAVR0::SPI::Fixed_Configuration_Controller<Peripheral::USART>
 *        echo interactive test.
 *
 * \return N/A
 */
int main() noexcept
{
    configure_clock();

    Log::initialize();

    echo(
        Log::instance(),
        Fixed_Configuration_Controller<USART>{ CONTROLLER_USART::instance(),
                                               CONTROLLER_USART_CLOCK_GENERATOR_SCALING_FACTOR,
                                               USART_Clock_Polarity::CONTROLLER_USART_CLOCK_POLARITY,
                                               USART_Clock_Phase::CONTROLLER_USART_CLOCK_PHASE,
                                               USART_Bit_Order::CONTROLLER_USART_BIT_ORDER,
                                               USART_Route::CONTROLLER_USART_ROUTE },
        Fixed_Configuration_Controller<USART>::Configuration{},
        []() { avrlibcpp::delay_ms( 100 ); } );

    for ( ;; ) {} // for
}
