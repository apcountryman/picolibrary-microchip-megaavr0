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
 * \brief picolibrary::Microchip::MCP23S08::Internally_Pulled_Up_Input_Pin state
 *        interactive test program.
 */

#include <avr-libcpp/delay>

#include "picolibrary/gpio.h"
#include "picolibrary/microchip/mcp23s08.h"
#include "picolibrary/microchip/megaavr0/gpio.h"
#include "picolibrary/microchip/megaavr0/multiplexed_signals.h"
#include "picolibrary/microchip/megaavr0/peripheral.h"
#include "picolibrary/microchip/megaavr0/peripheral/port.h"
#include "picolibrary/microchip/megaavr0/peripheral/spi.h"
#include "picolibrary/microchip/megaavr0/spi.h"
#include "picolibrary/spi.h"
#include "picolibrary/testing/interactive/microchip/mcp23s08.h"
#include "picolibrary/testing/interactive/microchip/megaavr0/clock.h"
#include "picolibrary/testing/interactive/microchip/megaavr0/log.h"

namespace {

using ::picolibrary::GPIO::Active_Low_IO_Pin;
using ::picolibrary::Microchip::MCP23S08::Address_Numeric;
using ::picolibrary::Microchip::MCP23S08::Address_Transmitted;
using ::picolibrary::Microchip::megaAVR0::GPIO::Push_Pull_IO_Pin;
using ::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::set_spi_route;
using ::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::SPI_Route;
using ::picolibrary::Microchip::megaAVR0::SPI::Fixed_Configuration_Controller;
using ::picolibrary::Microchip::megaAVR0::SPI::SPI_Bit_Order;
using ::picolibrary::Microchip::megaAVR0::SPI::SPI_Clock_Phase;
using ::picolibrary::Microchip::megaAVR0::SPI::SPI_Clock_Polarity;
using ::picolibrary::Microchip::megaAVR0::SPI::SPI_Clock_Rate;
using ::picolibrary::SPI::GPIO_Output_Pin_Device_Selector;
using ::picolibrary::Testing::Interactive::Microchip::MCP23S08::state;
using ::picolibrary::Testing::Interactive::Microchip::megaAVR0::configure_clock;
using ::picolibrary::Testing::Interactive::Microchip::megaAVR0::Log;

using namespace ::picolibrary::Microchip::megaAVR0::Peripheral;

} // namespace

/**
 * \brief Execute the picolibrary::Microchip::MCP23S08::Internally_Pulled_Up_Input_Pin
 *        state interactive test.
 *
 * \return N/A
 */
int main() noexcept
{
    configure_clock();

    Log::initialize();

    set_spi_route( CONTROLLER_SPI::instance(), SPI_Route::CONTROLLER_SPI_ROUTE );

    state(
        Log::instance(),
        Fixed_Configuration_Controller<SPI>{ CONTROLLER_SPI::instance(),
                                             SPI_Clock_Rate::CONTROLLER_SPI_CLOCK_RATE,
                                             SPI_Clock_Polarity::CONTROLLER_SPI_CLOCK_POLARITY,
                                             SPI_Clock_Phase::CONTROLLER_SPI_CLOCK_PHASE,
                                             SPI_Bit_Order::MSB_FIRST },
        Fixed_Configuration_Controller<SPI>::Configuration{},
        GPIO_Output_Pin_Device_Selector<Active_Low_IO_Pin<Push_Pull_IO_Pin<PORT>>>{
            DEVICE_SELECTOR_PORT::instance(), DEVICE_SELECTOR_MASK },
        MCP23S08_ADDRESS,
        MCP23S08_PIN_MASK,
        []() { avrlibcpp::delay_ms( 1000 ); } );

    for ( ;; ) {} // for
}
