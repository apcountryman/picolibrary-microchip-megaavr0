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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::VREF interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_VREF_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_VREF_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr0/register.h"
#include "picolibrary/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series Voltage Reference (VREF) peripheral.
 */
class VREF {
  public:
    /**
     * \brief Control A (CTRLA) register.
     *
     * This register has the following fields:
     * - AC0 Reference Select (AC0REFSEL)
     * - ADC0 Reference Select (ADC0REFSEL)
     */
    class CTRLA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto AC0REFSEL  = std::uint_fast8_t{ 3 }; ///< AC0REFSEL.
            static constexpr auto RESERVED3  = std::uint_fast8_t{ 1 }; ///< RESERVED3.
            static constexpr auto ADC0REFSEL = std::uint_fast8_t{ 3 }; ///< ADC0REFSEL.
            static constexpr auto RESERVED7  = std::uint_fast8_t{ 1 }; ///< RESERVED7.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto AC0REFSEL = std::uint_fast8_t{}; ///< AC0REFSEL.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ AC0REFSEL + Size::AC0REFSEL }; ///< RESERVED3.
            static constexpr auto ADC0REFSEL = std::uint_fast8_t{ RESERVED3 + Size::RESERVED3 }; ///< ADC0REFSEL.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ ADC0REFSEL + Size::ADC0REFSEL }; ///< RESERVED7.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto AC0REFSEL = mask<std::uint8_t>( Size::AC0REFSEL, Bit::AC0REFSEL ); ///< AC0REFSEL.
            static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
            static constexpr auto ADC0REFSEL = mask<std::uint8_t>( Size::ADC0REFSEL, Bit::ADC0REFSEL ); ///< ADC0REFSEL.
            static constexpr auto RESERVED7 = mask<std::uint8_t>( Size::RESERVED7, Bit::RESERVED7 ); ///< RESERVED7.
        };

        /**
         * \brief AC0REFSEL.
         */
        enum AC0REFSEL : std::uint8_t {
            AC0REFSEL_0V55 = 0x0 << Bit::AC0REFSEL, ///< 0.55 V internal reference.
            AC0REFSEL_1V1  = 0x1 << Bit::AC0REFSEL, ///< 1.1 V internal reference.
            AC0REFSEL_2V5  = 0x2 << Bit::AC0REFSEL, ///< 2.5 V internal reference.
            AC0REFSEL_4V3  = 0x3 << Bit::AC0REFSEL, ///< 4.3 V internal reference.
            AC0REFSEL_1V5  = 0x4 << Bit::AC0REFSEL, ///< 1.5 V internal reference.
            AC0REFSEL_AVDD = 0x7 << Bit::AC0REFSEL, ///< AVDD.
        };

        /**
         * \brief ADC0REFSEL.
         */
        enum ADC0REFSEL : std::uint8_t {
            ADC0REFSEL_0V55 = 0x0 << Bit::ADC0REFSEL, ///< 0.55 V internal reference.
            ADC0REFSEL_1V1  = 0x1 << Bit::ADC0REFSEL, ///< 1.1 V internal reference.
            ADC0REFSEL_2V5  = 0x2 << Bit::ADC0REFSEL, ///< 2.5 V internal reference.
            ADC0REFSEL_4V3  = 0x3 << Bit::ADC0REFSEL, ///< 4.3 V internal reference.
            ADC0REFSEL_1V5  = 0x4 << Bit::ADC0REFSEL, ///< 1.5 V internal reference.
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
     * \brief Control B (CTRLB) register.
     *
     * This register has the following fields:
     * - AC0 DACREF Reference Force Enable (AC0REFEN)
     * - ADC0 Reference Force Enable (ADC0REFEN)
     */
    class CTRLB : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto AC0REFEN  = std::uint_fast8_t{ 1 }; ///< AC0REFEN.
            static constexpr auto ADC0REFEN = std::uint_fast8_t{ 1 }; ///< ADC0REFEN.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ 6 }; ///< RESERVED2.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto AC0REFEN = std::uint_fast8_t{}; ///< AC0REFEN.
            static constexpr auto ADC0REFEN = std::uint_fast8_t{ AC0REFEN + Size::AC0REFEN }; ///< ADC0REFEN.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ ADC0REFEN + Size::ADC0REFEN }; ///< RESERVED2.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto AC0REFEN = mask<std::uint8_t>( Size::AC0REFEN, Bit::AC0REFEN ); ///< AC0REFEN.
            static constexpr auto ADC0REFEN = mask<std::uint8_t>( Size::ADC0REFEN, Bit::ADC0REFEN ); ///< ADC0REFEN.
            static constexpr auto RESERVED2 = mask<std::uint8_t>( Size::RESERVED2, Bit::RESERVED2 ); ///< RESERVED2.
        };

        CTRLB() = delete;

        CTRLB( CTRLB && ) = delete;

        CTRLB( CTRLB const & ) = delete;

        ~CTRLB() = delete;

        auto operator=( CTRLB && ) = delete;

        auto operator=( CTRLB const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief CTRLA.
     */
    CTRLA ctrla;

    /**
     * \brief CTRLB.
     */
    CTRLB ctrlb;

    VREF() = delete;

    VREF( VREF && ) = delete;

    VREF( VREF const & ) = delete;

    ~VREF() = delete;

    auto operator=( VREF && ) = delete;

    auto operator=( VREF const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_VREF_H
