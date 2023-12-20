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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::RSTCTRL interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_RSTCTRL_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_RSTCTRL_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr0/register.h"
#include "picolibrary/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series Reset Controller (RSTCTRL) peripheral.
 */
class RSTCTRL {
  public:
    /**
     * \brief Reset Flag Register (RSTFR) register.
     *
     * This register has the following fields:
     * - Power-On Reset Flag (PORF)
     * - Brown-Out Reset Flag (BORF)
     * - External Reset Flag (EXTRF)
     * - Watchdog Reset Flag (WDRF)
     * - Software Reset Flag (SWRF)
     * - UPDI Reset Flag (UPDIRF)
     */
    class RSTFR : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto PORF      = std::uint_fast8_t{ 1 }; ///< PORF.
            static constexpr auto BORF      = std::uint_fast8_t{ 1 }; ///< BORF.
            static constexpr auto EXTRF     = std::uint_fast8_t{ 1 }; ///< EXTRF.
            static constexpr auto WDRF      = std::uint_fast8_t{ 1 }; ///< WDRF.
            static constexpr auto SWRF      = std::uint_fast8_t{ 1 }; ///< SWRF.
            static constexpr auto UPDIRF    = std::uint_fast8_t{ 1 }; ///< UPDIRF.
            static constexpr auto RESERVED6 = std::uint_fast8_t{ 2 }; ///< RESERVED6.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto PORF = std::uint_fast8_t{}; ///< PORF.
            static constexpr auto BORF = std::uint_fast8_t{ PORF + Size::PORF }; ///< BORF.
            static constexpr auto EXTRF = std::uint_fast8_t{ BORF + Size::BORF }; ///< EXTRF.
            static constexpr auto WDRF = std::uint_fast8_t{ EXTRF + Size::EXTRF }; ///< WDRF.
            static constexpr auto SWRF = std::uint_fast8_t{ WDRF + Size::WDRF }; ///< SWRF.
            static constexpr auto UPDIRF = std::uint_fast8_t{ SWRF + Size::SWRF }; ///< UPDIRF.
            static constexpr auto RESERVED6 = std::uint_fast8_t{ UPDIRF + Size::UPDIRF }; ///< RESERVED6.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto PORF = mask<std::uint8_t>( Size::PORF, Bit::PORF ); ///< PORF.
            static constexpr auto BORF = mask<std::uint8_t>( Size::BORF, Bit::BORF ); ///< BORF.
            static constexpr auto EXTRF = mask<std::uint8_t>( Size::EXTRF, Bit::EXTRF ); ///< EXTRF.
            static constexpr auto WDRF = mask<std::uint8_t>( Size::WDRF, Bit::WDRF ); ///< WDRF.
            static constexpr auto SWRF = mask<std::uint8_t>( Size::SWRF, Bit::SWRF ); ///< SWRF.
            static constexpr auto UPDIRF = mask<std::uint8_t>( Size::UPDIRF, Bit::UPDIRF ); ///< UPDIRF.
            static constexpr auto RESERVED6 = mask<std::uint8_t>( Size::RESERVED6, Bit::RESERVED6 ); ///< RESERVED6.
        };

        RSTFR() = delete;

        RSTFR( RSTFR && ) = delete;

        RSTFR( RSTFR const & ) = delete;

        ~RSTFR() = delete;

        auto operator=( RSTFR && ) = delete;

        auto operator=( RSTFR const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Software Reset Register (SWRR) register.
     *
     * This register has the following fields:
     * - Software Reset Enable (SWRE)
     */
    class SWRR : public Protected_Register<std::uint8_t, CPU_CCP_Key::IOREG> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto SWRE      = std::uint_fast8_t{ 1 }; ///< SWRE.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 7 }; ///< RESERVED1.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto SWRE = std::uint_fast8_t{}; ///< SWRE.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ SWRE + Size::SWRE }; ///< RESERVED1.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto SWRE = mask<std::uint8_t>( Size::SWRE, Bit::SWRE ); ///< SWRE.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
        };

        SWRR() = delete;

        SWRR( SWRR && ) = delete;

        SWRR( SWRR const & ) = delete;

        ~SWRR() = delete;

        auto operator=( SWRR && ) = delete;

        auto operator=( SWRR const & ) = delete;

        using Protected_Register<std::uint8_t, CPU_CCP_Key::IOREG>::operator=;
    };

    /**
     * \brief RSTFR.
     */
    RSTFR rstfr;

    /**
     * \brief SWRR.
     */
    SWRR swrr;

    RSTCTRL() = delete;

    RSTCTRL( RSTCTRL && ) = delete;

    RSTCTRL( RSTCTRL const & ) = delete;

    ~RSTCTRL() = delete;

    auto operator=( RSTCTRL && ) = delete;

    auto operator=( RSTCTRL const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_RSTCTRL_H
