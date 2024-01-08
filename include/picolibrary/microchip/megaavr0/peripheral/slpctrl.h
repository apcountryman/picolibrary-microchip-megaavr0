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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::SLPCTRL interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_SLPCTRL_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_SLPCTRL_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series Sleep Controller (SLPCTRL) peripheral.
 */
class SLPCTRL {
  public:
    /**
     * \brief Control A (CTRLA) register.
     *
     * This register has the following fields:
     * - Sleep Enable (SEN)
     * - Sleep Mode (SMODE)
     */
    class CTRLA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto SEN       = std::uint_fast8_t{ 1 }; ///< SEN.
            static constexpr auto SMODE     = std::uint_fast8_t{ 2 }; ///< SMODE.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ 5 }; ///< RESERVED3.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto SEN   = std::uint_fast8_t{};                  ///< SEN.
            static constexpr auto SMODE = std::uint_fast8_t{ SEN + Size::SEN }; ///< SMODE.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ SMODE + Size::SMODE }; ///< RESERVED3.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto SEN = mask<std::uint8_t>( Size::SEN, Bit::SEN ); ///< SEN.
            static constexpr auto SMODE = mask<std::uint8_t>( Size::SMODE, Bit::SMODE ); ///< SMODE.
            static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
        };

        /**
         * \brief SMODE.
         */
        enum SMODE : std::uint8_t {
            SMODE_IDLE    = 0x0 << Bit::SMODE, ///< Idle sleep mode.
            SMODE_STANDBY = 0x1 << Bit::SMODE, ///< Standby sleep mode.
            SMODE_PDOWN   = 0x2 << Bit::SMODE, ///< Power-down sleep mode.
        };

        CTRLA() = delete;

        CTRLA( CTRLA && ) = delete;

        CTRLA( CTRLA const & ) = delete;

        ~CTRLA() = delete;

        auto operator=( CTRLA && ) = delete;

        auto operator=( CTRLA const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief CTRLA.
     */
    CTRLA ctrla;

    SLPCTRL() = delete;

    SLPCTRL( SLPCTRL && ) = delete;

    SLPCTRL( SLPCTRL const & ) = delete;

    ~SLPCTRL() = delete;

    auto operator=( SLPCTRL && ) = delete;

    auto operator=( SLPCTRL const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_SLPCTRL_H
