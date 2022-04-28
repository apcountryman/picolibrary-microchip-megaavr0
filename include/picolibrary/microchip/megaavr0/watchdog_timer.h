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
 * \brief picolibrary::Microchip::megaAVR0::Watchdog_Timer interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_WATCHDOG_TIMER_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_WATCHDOG_TIMER_H

#include <avr-libcpp/wdt>
#include <cstdint>

#include "picolibrary/microchip/megaavr0/peripheral.h"
#include "picolibrary/microchip/megaavr0/peripheral/wdt.h"
#include "picolibrary/utility.h"

/**
 * \brief Microchip megaAVR 0-series watchdog timer facilities.
 */
namespace picolibrary::Microchip::megaAVR0::Watchdog_Timer {

/**
 * \brief Normal mode time-out period.
 */
enum class Period : std::uint8_t {
    _8_ms   = Peripheral::WDT::CTRLA::PERIOD_8CLK,   ///< 8 ms.
    _16_ms  = Peripheral::WDT::CTRLA::PERIOD_16CLK,  ///< 16 ms.
    _32_ms  = Peripheral::WDT::CTRLA::PERIOD_32CLK,  ///< 32 ms.
    _63_ms  = Peripheral::WDT::CTRLA::PERIOD_64CLK,  ///< 63 ms.
    _125_ms = Peripheral::WDT::CTRLA::PERIOD_128CLK, ///< 125 ms.
    _250_ms = Peripheral::WDT::CTRLA::PERIOD_256CLK, ///< 250 ms.
    _500_ms = Peripheral::WDT::CTRLA::PERIOD_512CLK, ///< 500 ms.
    _1_s    = Peripheral::WDT::CTRLA::PERIOD_1KCLK,  ///< 1 s.
    _2_s    = Peripheral::WDT::CTRLA::PERIOD_2KCLK,  ///< 2 s.
    _4_s    = Peripheral::WDT::CTRLA::PERIOD_4KCLK,  ///< 4 s.
    _8_s    = Peripheral::WDT::CTRLA::PERIOD_8KCLK,  ///< 8 s.
};

/**
 * \brief Window mode window closed period.
 */
enum class Closed_Period : std::uint8_t {
    _8_ms   = Peripheral::WDT::CTRLA::WINDOW_8CLK,   ///< 8 ms.
    _16_ms  = Peripheral::WDT::CTRLA::WINDOW_16CLK,  ///< 16 ms.
    _32_ms  = Peripheral::WDT::CTRLA::WINDOW_32CLK,  ///< 32 ms.
    _63_ms  = Peripheral::WDT::CTRLA::WINDOW_64CLK,  ///< 63 ms.
    _125_ms = Peripheral::WDT::CTRLA::WINDOW_128CLK, ///< 125 ms.
    _250_ms = Peripheral::WDT::CTRLA::WINDOW_256CLK, ///< 250 ms.
    _500_ms = Peripheral::WDT::CTRLA::WINDOW_512CLK, ///< 500 ms.
    _1_s    = Peripheral::WDT::CTRLA::WINDOW_1KCLK,  ///< 1 s.
    _2_s    = Peripheral::WDT::CTRLA::WINDOW_2KCLK,  ///< 2 s.
    _4_s    = Peripheral::WDT::CTRLA::WINDOW_4KCLK,  ///< 4 s.
    _8_s    = Peripheral::WDT::CTRLA::WINDOW_8KCLK,  ///< 8 s.
};

/**
 * \brief Window mode window open period.
 */
enum class Open_Period : std::uint8_t {
    _8_ms   = Peripheral::WDT::CTRLA::PERIOD_8CLK,   ///< 8 ms.
    _16_ms  = Peripheral::WDT::CTRLA::PERIOD_16CLK,  ///< 16 ms.
    _32_ms  = Peripheral::WDT::CTRLA::PERIOD_32CLK,  ///< 32 ms.
    _63_ms  = Peripheral::WDT::CTRLA::PERIOD_64CLK,  ///< 63 ms.
    _125_ms = Peripheral::WDT::CTRLA::PERIOD_128CLK, ///< 125 ms.
    _250_ms = Peripheral::WDT::CTRLA::PERIOD_256CLK, ///< 250 ms.
    _500_ms = Peripheral::WDT::CTRLA::PERIOD_512CLK, ///< 500 ms.
    _1_s    = Peripheral::WDT::CTRLA::PERIOD_1KCLK,  ///< 1 s.
    _2_s    = Peripheral::WDT::CTRLA::PERIOD_2KCLK,  ///< 2 s.
    _4_s    = Peripheral::WDT::CTRLA::PERIOD_4KCLK,  ///< 4 s.
    _8_s    = Peripheral::WDT::CTRLA::PERIOD_8KCLK,  ///< 8 s.
};

/**
 * \brief Enable the watchdog timer in normal mode.
 *
 * \param[in] period The desired watchdog timer time-out period.
 */
inline void enable( Period period ) noexcept
{
    Peripheral::WDT0::instance().ctrla = to_underlying( period );
}

/**
 * \brief Enable the watchdog timer in window mode.
 *
 * \param[in] closed_period The desired watchdog timer window closed period.
 * \param[in] open_period The desired watchdog timer window open period.
 */
inline void enable( Closed_Period closed_period, Open_Period open_period ) noexcept
{
    Peripheral::WDT0::instance().ctrla = to_underlying( closed_period ) | to_underlying( open_period );
}

/**
 * \brief Check if a watchdog timer configuration change is in progress.
 *
 * \return true if a watchdog timer configuration change is in progress.
 * \return false if a watchdog timer configuration change is not in progress.
 */
inline auto configuration_change_in_progress() noexcept -> bool
{
    return Peripheral::WDT0::instance().status & Peripheral::WDT::STATUS::Mask::SYNCBUSY;
}

/**
 * \brief Check if the watchdog timer configuration is locked.
 *
 * \return true if the watchdog timer configuration is locked.
 * \return false if the watchdog timer configuration is not locked.
 */
inline auto configuration_locked() noexcept -> bool
{
    return Peripheral::WDT0::instance().status & Peripheral::WDT::STATUS::Mask::LOCK;
}

/**
 * \brief Lock the watchdog timer configuration.
 */
inline void lock_configuration() noexcept
{
    Peripheral::WDT0::instance().status = Peripheral::WDT::STATUS::Mask::LOCK;
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
