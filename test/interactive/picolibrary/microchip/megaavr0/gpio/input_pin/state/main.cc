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
 * \brief picolibrary::Microchip::megaAVR0::GPIO::Input_Pin state interactive test
 *        program.
 */

#include <avr-libcpp/delay>

#include "picolibrary/microchip/megaavr0/gpio.h"
#include "picolibrary/microchip/megaavr0/peripheral.h"
#include "picolibrary/testing/interactive/gpio.h"
#include "picolibrary/testing/interactive/microchip/megaavr0/clock.h"
#include "picolibrary/testing/interactive/microchip/megaavr0/log.h"

namespace {

using ::picolibrary::Microchip::megaAVR0::GPIO::Input_Pin;
using ::picolibrary::Testing::Interactive::GPIO::state;
using ::picolibrary::Testing::Interactive::Microchip::megaAVR0::configure_clock;
using ::picolibrary::Testing::Interactive::Microchip::megaAVR0::Log;

using namespace ::picolibrary::Microchip::megaAVR0::Peripheral;

} // namespace

/**
 * \brief Execute the picolibrary::Microchip::megaAVR0::GPIO::Input_Pin state interactive
 *        test.
 *
 * \return N/A
 */
int main() noexcept
{
    configure_clock();

    Log::initialize();

    state( Log::instance(), Input_Pin{ PIN_PORT::instance(), PIN_MASK }, []() {
        avrlibcpp::delay_ms( 1000 );
    } );

    for ( ;; ) {} // for
}
