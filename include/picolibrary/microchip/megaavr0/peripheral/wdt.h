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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::WDT interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_WDT_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_WDT_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr0/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series Watchdog Timer (WDT) peripheral.
 */
class WDT {
  public:
    /**
     * \brief Control A (CTRLA) register.
     *
     * This register has the following fields:
     * - Period (PERIOD)
     * - Window (WINDOW)
     */
    class CTRLA : public Protected_Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto PERIOD = std::uint_fast8_t{ 4 }; ///< PERIOD.
            static constexpr auto WINDOW = std::uint_fast8_t{ 4 }; ///< WINDOW.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto PERIOD = std::uint_fast8_t{}; ///< PERIOD.
            static constexpr auto WINDOW = std::uint_fast8_t{ PERIOD + Size::PERIOD }; ///< WINDOW.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto PERIOD = mask<std::uint8_t>( Size::PERIOD, Bit::PERIOD ); ///< PERIOD.
            static constexpr auto WINDOW = mask<std::uint8_t>( Size::WINDOW, Bit::WINDOW ); ///< WINDOW.
        };

        /**
         * \brief PERIOD.
         */
        enum PERIOD : std::uint8_t {
            PERIOD_OFF    = 0x0 << Bit::PERIOD, ///< Off.
            PERIOD_8CLK   = 0x1 << Bit::PERIOD, ///< 0.008 s.
            PERIOD_16CLK  = 0x2 << Bit::PERIOD, ///< 0.016 s.
            PERIOD_32CLK  = 0x3 << Bit::PERIOD, ///< 0.031 s.
            PERIOD_64CLK  = 0x4 << Bit::PERIOD, ///< 0.063 s.
            PERIOD_128CLK = 0x5 << Bit::PERIOD, ///< 0.125 s.
            PERIOD_256CLK = 0x6 << Bit::PERIOD, ///< 0.25 s.
            PERIOD_512CLK = 0x7 << Bit::PERIOD, ///< 0.5 s.
            PERIOD_1KCLK  = 0x8 << Bit::PERIOD, ///< 1 s.
            PERIOD_2KCLK  = 0x9 << Bit::PERIOD, ///< 2 s.
            PERIOD_4KCLK  = 0xA << Bit::PERIOD, ///< 4 s.
            PERIOD_8KCLK  = 0xB << Bit::PERIOD, ///< 8 s.
        };

        /**
         * \brief WINDOW.
         */
        enum WINDOW : std::uint8_t {
            WINDOW_OFF    = 0x0 << Bit::WINDOW, ///< Off.
            WINDOW_8CLK   = 0x1 << Bit::WINDOW, ///< 0.008 s.
            WINDOW_16CLK  = 0x2 << Bit::WINDOW, ///< 0.016 s.
            WINDOW_32CLK  = 0x3 << Bit::WINDOW, ///< 0.031 s.
            WINDOW_64CLK  = 0x4 << Bit::WINDOW, ///< 0.063 s.
            WINDOW_128CLK = 0x5 << Bit::WINDOW, ///< 0.125 s.
            WINDOW_256CLK = 0x6 << Bit::WINDOW, ///< 0.25 s.
            WINDOW_512CLK = 0x7 << Bit::WINDOW, ///< 0.5 s.
            WINDOW_1KCLK  = 0x8 << Bit::WINDOW, ///< 1 s.
            WINDOW_2KCLK  = 0x9 << Bit::WINDOW, ///< 2 s.
            WINDOW_4KCLK  = 0xA << Bit::WINDOW, ///< 4 s.
            WINDOW_8KCLK  = 0xB << Bit::WINDOW, ///< 8 s.
        };

        CTRLA() = delete;

        CTRLA( CTRLA && ) = delete;

        CTRLA( CTRLA const & ) = delete;

        ~CTRLA() = delete;

        auto operator=( CTRLA && ) = delete;

        auto operator=( CTRLA const & ) = delete;

        using Protected_Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Status (STATUS) register.
     *
     * This register has the following fields:
     * - Synchronization Busy (SYNCBUSY)
     * - Lock (LOCK)
     */
    class STATUS : public Protected_Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto SYNCBUSY  = std::uint_fast8_t{ 1 }; ///< SYNCBUSY.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 6 }; ///< RESERVED1.
            static constexpr auto LOCK      = std::uint_fast8_t{ 1 }; ///< LOCK.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto SYNCBUSY = std::uint_fast8_t{}; ///< SYNCBUSY.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ SYNCBUSY + Size::SYNCBUSY }; ///< RESERVED1.
            static constexpr auto LOCK = std::uint_fast8_t{ RESERVED1 + Size::RESERVED1 }; ///< LOCK.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto SYNCBUSY = mask<std::uint8_t>( Size::SYNCBUSY, Bit::SYNCBUSY ); ///< SYNCBUSY.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
            static constexpr auto LOCK = mask<std::uint8_t>( Size::LOCK, Bit::LOCK ); ///< LOCK.
        };

        STATUS() = delete;

        STATUS( STATUS && ) = delete;

        STATUS( STATUS const & ) = delete;

        ~STATUS() = delete;

        auto operator=( STATUS && ) = delete;

        auto operator=( STATUS const & ) = delete;

        using Protected_Register<std::uint8_t>::operator=;
    };

    /**
     * \brief CTRLA.
     */
    CTRLA ctrla;

    /**
     * \brief STATUS.
     */
    STATUS status;

    WDT() = delete;

    WDT( WDT && ) = delete;

    WDT( WDT const & ) = delete;

    ~WDT() = delete;

    auto operator=( WDT && ) = delete;

    auto operator=( WDT const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_WDT_H
