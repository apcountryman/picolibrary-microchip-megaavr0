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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::PORT interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_PORT_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_PORT_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr0/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series I/O Pin Configuration (PORT) peripheral.
 */
class PORT {
  public:
    /**
     * \brief Port Control (PORTCTRL) register.
     *
     * This register has the following fields:
     * - Slew Rate Limit Enable (SRL)
     */
    class PORTCTRL : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto SRL       = std::uint_fast8_t{ 1 }; ///< SRL.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 7 }; ///< RESERVED1.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto SRL = std::uint_fast8_t{}; ///< SRL.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ SRL + Size::SRL }; ///< RESERVED1.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto SRL = mask<std::uint8_t>( Size::SRL, Bit::SRL ); ///< SRL.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
        };

        PORTCTRL() = delete;

        PORTCTRL( PORTCTRL && ) = delete;

        PORTCTRL( PORTCTRL const & ) = delete;

        ~PORTCTRL() = delete;

        auto operator=( PORTCTRL && ) = delete;

        auto operator=( PORTCTRL const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Pin Control (PINCTRL) register.
     *
     * This register has the following fields:
     * - Input/Sense Configuration (ISC)
     * - Pull-Up Enable (PULLUPEN)
     * - Inverted I/O Enable (INVEN)
     */
    class PINCTRL : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto ISC       = std::uint_fast8_t{ 3 }; ///< ISC.
            static constexpr auto PULLUPEN  = std::uint_fast8_t{ 1 }; ///< PULLUPEN.
            static constexpr auto RESERVED4 = std::uint_fast8_t{ 3 }; ///< RESERVED4.
            static constexpr auto INVEN     = std::uint_fast8_t{ 1 }; ///< INVEN.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto ISC = std::uint_fast8_t{}; ///< ISC.
            static constexpr auto PULLUPEN = std::uint_fast8_t{ ISC + Size::ISC }; ///< PULLUPEN.
            static constexpr auto RESERVED4 = std::uint_fast8_t{ PULLUPEN + Size::PULLUPEN }; ///< RESERVED4.
            static constexpr auto INVEN = std::uint_fast8_t{ RESERVED4 + Size::RESERVED4 }; ///< INVEN.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto ISC = mask<std::uint8_t>( Size::ISC, Bit::ISC ); ///< ISC.
            static constexpr auto PULLUPEN = mask<std::uint8_t>( Size::PULLUPEN, Bit::PULLUPEN ); ///< PULLUPEN.
            static constexpr auto RESERVED4 = mask<std::uint8_t>( Size::RESERVED4, Bit::RESERVED4 ); ///< RESERVED4.
            static constexpr auto INVEN = mask<std::uint8_t>( Size::INVEN, Bit::INVEN ); ///< INVEN.
        };

        /**
         * \brief ISC.
         */
        enum ISC : std::uint8_t {
            ISC_INTDISABLE = 0x0 << Bit::ISC, ///< Interrupt disabled but input buffer enabled.
            ISC_BOTHEDGES = 0x1 << Bit::ISC, ///< Interrupt enabled with sense on both edges.
            ISC_RISING = 0x2 << Bit::ISC, ///< Interrupt enabled with sense on rising edge.
            ISC_FALLING = 0x3 << Bit::ISC, ///< Interrupt enabled with sense on falling edge.
            ISC_INPUT_DISABLE = 0x4 << Bit::ISC, ///< Interrupt and digital input buffer disabled.
            ISC_LEVEL = 0x5 << Bit::ISC, ///< Interrupt enabled with sense on low level.
        };

        PINCTRL() = delete;

        PINCTRL( PINCTRL && ) = delete;

        PINCTRL( PINCTRL const & ) = delete;

        ~PINCTRL() = delete;

        auto operator=( PINCTRL && ) = delete;

        auto operator=( PINCTRL const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Data Direction (DIR) register.
     */
    Register<std::uint8_t> dir;

    /**
     * \brief Data Direction Set (DIRSET) register.
     */
    Register<std::uint8_t> dirset;

    /**
     * \brief Data Direction Clear (DIRCLR) register.
     */
    Register<std::uint8_t> dirclr;

    /**
     * \brief Data Direction Toggle (DIRTGL) register.
     */
    Register<std::uint8_t> dirtgl;

    /**
     * \brief Output Value (OUT) register.
     */
    Register<std::uint8_t> out;

    /**
     * \brief Output Value Set (OUTSET) register.
     */
    Register<std::uint8_t> outset;

    /**
     * \brief Output Value Clear (OUTCLR) register.
     */
    Register<std::uint8_t> outclr;

    /**
     * \brief Output Value Toggle (OUTTGL) register.
     */
    Register<std::uint8_t> outtgl;

    /**
     * \brief Input Value (IN) register.
     */
    Register<std::uint8_t> in;

    /**
     * \brief Interrupt Flags (INTFLAGS) register.
     */
    Register<std::uint8_t> intflags;

    /**
     * \brief PORTCTRL.
     */
    PORTCTRL portctrl;

    /**
     * \brief Reserved registers (offset 0x0B-0x0F).
     */
    Reserved_Register<std::uint8_t> const reserved_0x0B_0x0F[ ( 0x0F - 0x0B ) + 1 ];

    /**
     * \brief PINCTRL.
     */
    PINCTRL pinctrl[ ( 0x17 - 0x10 ) + 1 ];

    PORT() = delete;

    PORT( PORT && ) = delete;

    PORT( PORT const & ) = delete;

    ~PORT() = delete;

    auto operator=( PORT && ) = delete;

    auto operator=( PORT const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_PORT_H
