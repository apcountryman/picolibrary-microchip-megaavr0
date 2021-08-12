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
 * \brief picolibrary::Microchip::megaAVR0::Asynchronous_Serial::Transmitter_8_N_1 hello
 *        world interactive test program.
 */

#include "picolibrary/microchip/megaavr0/asynchronous_serial.h"
#include "picolibrary/microchip/megaavr0/clock.h"
#include "picolibrary/microchip/megaavr0/multiplexed_signals.h"
#include "picolibrary/microchip/megaavr0/peripheral.h"
#include "picolibrary/microchip/megaavr0/peripheral/usart.h"
#include "picolibrary/testing/interactive/asynchronous_serial.h"
#include "picolibrary/testing/interactive/microchip/megaavr0/clock.h"

namespace {

using namespace ::picolibrary::Microchip::megaAVR0::Peripheral;

using ::picolibrary::Microchip::megaAVR0::Asynchronous_Serial::Transmitter_8_N_1;
using ::picolibrary::Microchip::megaAVR0::Clock::Prescaler;
using ::picolibrary::Microchip::megaAVR0::Clock::Prescaler_Value;
using ::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::set_usart_route;
using ::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::USART_Route;
using ::picolibrary::Microchip::megaAVR0::Peripheral::USART;
using ::picolibrary::Testing::Interactive::Asynchronous_Serial::hello_world;
using ::picolibrary::Testing::Interactive::Microchip::megaAVR0::configure_clock;

} // namespace

/**
 * \brief Execute the
 *        picolibrary::Microchip::megaAVR0::Asynchronous_Serial::Transmitter_8_N_1 hello
 *        world interactive test.
 *
 * \return 0.
 */
int main()
{
    configure_clock( Prescaler_Value::CLOCK_PRESCALER_VALUE, Prescaler::CLOCK_PRESCALER_CONFIGURATION );

    set_usart_route( TRANSMITTER_USART::instance(), USART_Route::TRANSMITTER_USART_ROUTE );

    hello_world( Transmitter_8_N_1{
        TRANSMITTER_USART::instance(),
        { .operating_speed = USART::Operating_Speed::TRANSMITTER_CLOCK_GENERATOR_OPERATING_SPEED,
          .scaling_factor = TRANSMITTER_CLOCK_GENERATOR_SCALING_FACTOR } } );

    for ( ;; ) {}
}
