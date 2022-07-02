/**
 * picolibrary-microchip-megaavr0
 *
 * Copyright 2021-2022, Andrew Countryman <apcountryman@gmail.com> and the
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
 * \brief picolibrary::Asynchronous_Serial::Reliable_Unbuffered_Output_Stream hello world
 *        interactive test program.
 */

#include <cstdint>

#include "picolibrary/asynchronous_serial/stream.h"
#include "picolibrary/microchip/megaavr0/asynchronous_serial.h"
#include "picolibrary/microchip/megaavr0/multiplexed_signals.h"
#include "picolibrary/microchip/megaavr0/peripheral.h"
#include "picolibrary/testing/interactive/asynchronous_serial/stream.h"
#include "picolibrary/testing/interactive/microchip/megaavr0/clock.h"
#include "picolibrary/testing/interactive/microchip/megaavr0/log.h"

namespace {

using ::picolibrary::Asynchronous_Serial::Reliable_Unbuffered_Output_Stream;
using ::picolibrary::Microchip::megaAVR0::Asynchronous_Serial::Transmitter;
using ::picolibrary::Microchip::megaAVR0::Asynchronous_Serial::USART_Clock_Generator_Operating_Speed;
using ::picolibrary::Microchip::megaAVR0::Asynchronous_Serial::USART_Data_Bits;
using ::picolibrary::Microchip::megaAVR0::Asynchronous_Serial::USART_Parity;
using ::picolibrary::Microchip::megaAVR0::Asynchronous_Serial::USART_Stop_Bits;
using ::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::set_usart_route;
using ::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::USART_Route;
using ::picolibrary::Testing::Interactive::Asynchronous_Serial::hello_world;
using ::picolibrary::Testing::Interactive::Microchip::megaAVR0::configure_clock;
using ::picolibrary::Testing::Interactive::Microchip::megaAVR0::Log;

using namespace ::picolibrary::Microchip::megaAVR0::Peripheral;

} // namespace

/**
 * \brief Execute the picolibrary::Asynchronous_Serial::Reliable_Unbuffered_Output_Stream
 *        hello world interactive test.
 *
 * \return N/A
 */
int main() noexcept
{
    configure_clock();

    Log::initialize();

    set_usart_route( TRANSMITTER_USART::instance(), USART_Route::TRANSMITTER_USART_ROUTE );

    hello_world<Reliable_Unbuffered_Output_Stream>( Transmitter<TRANSMITTER_DATA_TYPE>{
        TRANSMITTER_USART::instance(),
        USART_Data_Bits::TRANSMITTER_USART_DATA_BITS,
        USART_Parity::TRANSMITTER_USART_PARITY,
        USART_Stop_Bits::TRANSMITTER_USART_STOP_BITS,
        USART_Clock_Generator_Operating_Speed::TRANSMITTER_USART_CLOCK_GENERATOR_OPERATING_SPEED,
        TRANSMITTER_USART_CLOCK_GENERATOR_SCALING_FACTOR } );

    for ( ;; ) {} // for
}
