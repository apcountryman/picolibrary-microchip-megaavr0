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
 * \brief picolibrary::Microchip::megaAVR0::Watchdog_Timer interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_WATCHDOG_TIMER_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_WATCHDOG_TIMER_H

#include <avr-libcpp/wdt>

#include "picolibrary/microchip/megaavr0/peripheral.h"
#include "picolibrary/microchip/megaavr0/peripheral/wdt.h"

/**
 * \brief Microchip megaAVR 0-series watchdog timer facilities.
 */
namespace picolibrary::Microchip::megaAVR0::Watchdog_Timer {

/**
 * \brief Normal mode time-out period.
 */
using Period = Peripheral::WDT::Period;

/**
 * \brief Window mode window closed period.
 */
using Closed_Period = Peripheral::WDT::Closed_Period;

/**
 * \brief Window mode window open period.
 */
using Open_Period = Peripheral::WDT::Open_Period;

/**
 * \brief Enable the watchdog timer in normal mode.
 *
 * \param[in] period The watchdog timer time-out period.
 */
inline void enable( Period period ) noexcept
{
    Peripheral::WDT0::instance().enable( period );
}

/**
 * \brief Enable the watchdog timer in window mode.
 *
 * \param[in] closed_period The watchdog timer window closed period.
 * \param[in] open_period The watchdog timer window open period.
 */
inline void enable( Closed_Period closed_period, Open_Period open_period ) noexcept
{
    Peripheral::WDT0::instance().enable( closed_period, open_period );
}

/**
 * \brief Disable the watchdog timer.
 */
inline void disable() noexcept
{
    Peripheral::WDT0::instance().disable();
}

/**
 * \brief Check if a watchdog timer configuration change is in progress.
 *
 * \return true if a watchdog timer configuration change is in progress.
 * \return false if a watchdog timer configuration change is not in progress.
 */
inline auto configuration_change_in_progress() noexcept
{
    return Peripheral::WDT0::instance().configuration_change_in_progress();
}

/**
 * \brief Lock the watchdog timer configuration.
 */
inline void lock_configuration() noexcept
{
    Peripheral::WDT0::instance().lock_configuration();
}

/**
 * \brief Reset the watchdog timer.
 */
inline void reset() noexcept
{
    wdt_reset();
}

} // namespace picolibrary::Microchip::megaAVR0::Watchdog_Timer

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_WATCHDOG_TIMER_H
