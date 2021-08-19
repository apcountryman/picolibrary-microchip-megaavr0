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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::WDT interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_WDT_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_WDT_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr0/peripheral/instance.h"
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

        CTRLA() = delete;

        CTRLA( CTRLA && ) = delete;

        CTRLA( CTRLA const & ) = delete;

        ~CTRLA() = delete;

        auto operator=( CTRLA && ) = delete;

        auto operator=( CTRLA const & ) = delete;
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
    };

    /**
     * \brief CTRLA.
     */
    CTRLA ctrla;

    /**
     * \brief Status.
     */
    STATUS status;

    WDT() = delete;

    WDT( WDT && ) = delete;

    WDT( WDT const & ) = delete;

    ~WDT() = delete;

    auto operator=( WDT && ) = delete;

    auto operator=( WDT const & ) = delete;
};

/**
 * \brief Microchip megaAVR 0-series Watchdog Timer (WDT) peripheral instance.
 *
 * \tparam INSTANCE_ADDRESS The address of the WDT instance.
 */
template<std::uintptr_t INSTANCE_ADDRESS>
using WDT_Instance = Instance<WDT, INSTANCE_ADDRESS>;

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_WDT_H
