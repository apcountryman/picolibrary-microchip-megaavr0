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
 * \brief picolibrary::Microchip::megaAVR0::I2C::Controller scan interactive test program.
 */

#include "picolibrary/microchip/megaavr0/i2c.h"
#include "picolibrary/microchip/megaavr0/multiplexed_signals.h"
#include "picolibrary/microchip/megaavr0/peripheral.h"
#include "picolibrary/testing/interactive/i2c.h"
#include "picolibrary/testing/interactive/microchip/megaavr0/clock.h"
#include "picolibrary/testing/interactive/microchip/megaavr0/log.h"

namespace {

using ::picolibrary::Microchip::megaAVR0::I2C::Controller;
using ::picolibrary::Microchip::megaAVR0::I2C::TWI_Bus_Speed;
using ::picolibrary::Microchip::megaAVR0::I2C::TWI_Inactive_Bus_Time_Out;
using ::picolibrary::Microchip::megaAVR0::I2C::TWI_SDA_Hold_Time;
using ::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::TWI_Route;
using ::picolibrary::Testing::Interactive::Microchip::megaAVR0::configure_clock;
using ::picolibrary::Testing::Interactive::Microchip::megaAVR0::Log;

using namespace ::picolibrary::Microchip::megaAVR0::Peripheral;

} // namespace

/**
 * \brief Execute the picolibrary::Microchip::megaAVR0::I2C::Controller scan interactive
 *        test.
 *
 * \return N/A
 */
int main() noexcept
{
    configure_clock();

    Log::initialize();

    ::picolibrary::Testing::Interactive::I2C::scan(
        Log::instance(),
        Controller{ CONTROLLER_TWI::instance(),
                    TWI_SDA_Hold_Time::CONTROLLER_TWI_SDA_HOLD_TIME,
                    TWI_Bus_Speed::CONTROLLER_TWI_BUS_SPEED,
                    CONTROLLER_TWI_CLOCK_GENERATOR_SCALING_FACTOR,
                    TWI_Inactive_Bus_Time_Out::CONTROLLER_TWI_INACTIVE_BUS_TIME_OUT,
                    TWI_Route::CONTROLLER_TWI_ROUTE } );

    for ( ;; ) {} // for
}
