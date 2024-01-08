/**
 * picolibrary-microchip-megaavr0
 *
 * Copyright 2021-2024, Andrew Countryman <apcountryman@gmail.com> and the
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
 * \brief picolibrary::Adafruit::PID781::Driver hello world interactive test program.
 */

#include <cstdint>

#include "picolibrary/microchip/megaavr0/asynchronous_serial.h"
#include "picolibrary/microchip/megaavr0/multiplexed_signals.h"
#include "picolibrary/microchip/megaavr0/peripheral.h"
#include "picolibrary/testing/interactive/adafruit/pid781.h"
#include "picolibrary/testing/interactive/microchip/megaavr0/clock.h"
#include "picolibrary/testing/interactive/microchip/megaavr0/log.h"

namespace {

using ::picolibrary::Microchip::megaAVR0::Asynchronous_Serial::Transmitter;
using ::picolibrary::Microchip::megaAVR0::Asynchronous_Serial::USART_Clock_Generator_Operating_Speed;
using ::picolibrary::Microchip::megaAVR0::Asynchronous_Serial::USART_Data_Bits;
using ::picolibrary::Microchip::megaAVR0::Asynchronous_Serial::USART_Parity;
using ::picolibrary::Microchip::megaAVR0::Asynchronous_Serial::USART_Stop_Bits;
using ::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::USART_Route;
using ::picolibrary::Testing::Interactive::Adafruit::PID781::hello_world;
using ::picolibrary::Testing::Interactive::Microchip::megaAVR0::configure_clock;
using ::picolibrary::Testing::Interactive::Microchip::megaAVR0::Log;

using namespace ::picolibrary::Microchip::megaAVR0::Peripheral;

} // namespace

/**
 * \brief Execute the picolibrary::Adafruit::PID781::Driver hello world interactive test.
 *
 * \return N/A
 */
int main() noexcept
{
    configure_clock();

    Log::initialize();

    hello_world( Transmitter<std::uint8_t>{ TRANSMITTER_USART::instance(),
                                            USART_Data_Bits::_8,
                                            USART_Parity::NONE,
                                            USART_Stop_Bits::_1,
                                            USART_Clock_Generator_Operating_Speed::TRANSMITTER_USART_CLOCK_GENERATOR_OPERATING_SPEED,
                                            TRANSMITTER_USART_CLOCK_GENERATOR_SCALING_FACTOR,
                                            USART_Route::TRANSMITTER_USART_ROUTE } );

    for ( ;; ) {} // for
}
