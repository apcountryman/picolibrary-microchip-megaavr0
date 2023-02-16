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
 * \brief picolibrary::Microchip::megaAVR0::SPI::Variable_Configuration_Controller<Peripheral::SPI>
 *        echo interactive test program.
 */

#include <avr-libcpp/delay>

#include "picolibrary/microchip/megaavr0/multiplexed_signals.h"
#include "picolibrary/microchip/megaavr0/peripheral.h"
#include "picolibrary/microchip/megaavr0/peripheral/spi.h"
#include "picolibrary/microchip/megaavr0/spi.h"
#include "picolibrary/testing/interactive/microchip/megaavr0/clock.h"
#include "picolibrary/testing/interactive/microchip/megaavr0/log.h"
#include "picolibrary/testing/interactive/spi.h"

namespace {

using ::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::set_spi_route;
using ::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::SPI_Route;
using ::picolibrary::Microchip::megaAVR0::SPI::SPI_Bit_Order;
using ::picolibrary::Microchip::megaAVR0::SPI::SPI_Clock_Phase;
using ::picolibrary::Microchip::megaAVR0::SPI::SPI_Clock_Polarity;
using ::picolibrary::Microchip::megaAVR0::SPI::SPI_Clock_Rate;
using ::picolibrary::Microchip::megaAVR0::SPI::Variable_Configuration_Controller;
using ::picolibrary::Testing::Interactive::Microchip::megaAVR0::configure_clock;
using ::picolibrary::Testing::Interactive::Microchip::megaAVR0::Log;
using ::picolibrary::Testing::Interactive::SPI::echo;

using namespace ::picolibrary::Microchip::megaAVR0::Peripheral;

} // namespace

/**
 * \brief Execute the
 *        picolibrary::Microchip::megaAVR0::SPI::Variable_Configuration_Controller<Peripheral::SPI>
 *        echo interactive test.
 *
 * \return N/A
 */
int main() noexcept
{
    configure_clock();

    Log::initialize();

    set_spi_route( CONTROLLER_SPI::instance(), SPI_Route::CONTROLLER_SPI_ROUTE );

    echo(
        Log::instance(),
        Variable_Configuration_Controller<SPI>{ CONTROLLER_SPI::instance() },
        Variable_Configuration_Controller<SPI>::Configuration{
            SPI_Clock_Rate::CONTROLLER_SPI_CLOCK_RATE,
            SPI_Clock_Polarity::CONTROLLER_SPI_CLOCK_POLARITY,
            SPI_Clock_Phase::CONTROLLER_SPI_CLOCK_PHASE,
            SPI_Bit_Order::CONTROLLER_SPI_BIT_ORDER },
        []() { avrlibcpp::delay_ms( 100 ); } );

    for ( ;; ) {} // for
}
