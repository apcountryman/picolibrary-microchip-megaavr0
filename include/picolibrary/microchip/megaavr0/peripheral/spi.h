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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::SPI interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_SPI_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_SPI_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series Serial Peripheral Interface (SPI) peripheral.
 */
class SPI {
  public:
    /**
     * \brief Control A (CTRLA) register.
     *
     * This register has the following fields:
     * - SPI Enable (ENABLE)
     * - Prescaler (PRESC)
     * - Clock Double (CLK2X)
     * - Host/Client Select (MASTER)
     * - Data Order (DORD)
     */
    class CTRLA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto ENABLE    = std::uint_fast8_t{ 1 }; ///< ENABLE.
            static constexpr auto PRESC     = std::uint_fast8_t{ 2 }; ///< PRESC.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ 1 }; ///< RESERVED3.
            static constexpr auto CLK2X     = std::uint_fast8_t{ 1 }; ///< CLK2X.
            static constexpr auto MASTER    = std::uint_fast8_t{ 1 }; ///< MASTER.
            static constexpr auto DORD      = std::uint_fast8_t{ 1 }; ///< DORD.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ 1 }; ///< RESERVED7.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto ENABLE = std::uint_fast8_t{}; ///< ENABLE.
            static constexpr auto PRESC = std::uint_fast8_t{ ENABLE + Size::ENABLE }; ///< PRESC.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ PRESC + Size::PRESC }; ///< RESERVED3.
            static constexpr auto CLK2X = std::uint_fast8_t{ RESERVED3 + Size::RESERVED3 }; ///< CLK2X.
            static constexpr auto MASTER = std::uint_fast8_t{ CLK2X + Size::CLK2X }; ///< MASTER.
            static constexpr auto DORD = std::uint_fast8_t{ MASTER + Size::MASTER }; ///< DORD.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ DORD + Size::DORD }; ///< RESERVED7.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto ENABLE = mask<std::uint8_t>( Size::ENABLE, Bit::ENABLE ); ///< ENABLE.
            static constexpr auto PRESC = mask<std::uint8_t>( Size::PRESC, Bit::PRESC ); ///< PRESC.
            static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
            static constexpr auto CLK2X = mask<std::uint8_t>( Size::CLK2X, Bit::CLK2X ); ///< CLK2X.
            static constexpr auto MASTER = mask<std::uint8_t>( Size::MASTER, Bit::MASTER ); ///< MASTER.
            static constexpr auto DORD = mask<std::uint8_t>( Size::DORD, Bit::DORD ); ///< DORD.
            static constexpr auto RESERVED7 = mask<std::uint8_t>( Size::RESERVED7, Bit::RESERVED7 ); ///< RESERVED7.
        };

        /**
         * \brief PRESC.
         */
        enum PRESC : std::uint8_t {
            PRESC_DIV4   = 0x0 << Bit::PRESC, ///< CLK_PER/4.
            PRESC_DIV16  = 0x1 << Bit::PRESC, ///< CLK_PER/16.
            PRESC_DIV64  = 0x2 << Bit::PRESC, ///< CLK_PER/64.
            PRESC_DIV128 = 0x3 << Bit::PRESC, ///< CLK_PER/128.
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
     * - Mode (MODE)
     * - Client Select Disable (SSD)
     * - Buffer Mode Wait for Receive (BUFWR)
     * - Buffer Mode Enable (BUFEN)
     */
    class CTRLB : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto MODE      = std::uint_fast8_t{ 2 }; ///< MODE.
            static constexpr auto SSD       = std::uint_fast8_t{ 1 }; ///< SSD.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ 3 }; ///< RESERVED3.
            static constexpr auto BUFWR     = std::uint_fast8_t{ 1 }; ///< BUFWR.
            static constexpr auto BUFEN     = std::uint_fast8_t{ 1 }; ///< BUFEN.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto MODE = std::uint_fast8_t{}; ///< MODE.
            static constexpr auto SSD  = std::uint_fast8_t{ MODE + Size::MODE }; ///< SSD.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ SSD + Size::SSD }; ///< RESERVED3.
            static constexpr auto BUFWR = std::uint_fast8_t{ RESERVED3 + Size::RESERVED3 }; ///< BUFWR.
            static constexpr auto BUFEN = std::uint_fast8_t{ BUFWR + Size::BUFWR }; ///< BUFEN.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto MODE = mask<std::uint8_t>( Size::MODE, Bit::MODE ); ///< MODE.
            static constexpr auto SSD = mask<std::uint8_t>( Size::SSD, Bit::SSD ); ///< SSD.
            static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
            static constexpr auto BUFWR = mask<std::uint8_t>( Size::BUFWR, Bit::BUFWR ); ///< BUFWR.
            static constexpr auto BUFEN = mask<std::uint8_t>( Size::BUFEN, Bit::BUFEN ); ///< BUFEN.
        };

        /**
         * \brief MODE.
         */
        enum MODE : std::uint8_t {
            MODE_0 = 0x0 << Bit::MODE, ///< Leading edge: rising, sample; trailing edge: falling, setup.
            MODE_1 = 0x1 << Bit::MODE, ///< Leading edge: rising, setup; trailing edge: falling, sample.
            MODE_2 = 0x2 << Bit::MODE, ///< Leading edge: falling, sample; trailing edge: rising, setup.
            MODE_3 = 0x3 << Bit::MODE, ///< Leading edge: falling, setup; trailing edge: rising, sample.
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
     * \brief Interrupt Control (INTCTRL) register.
     *
     * This register has the following fields:
     * - Interrupt Enable (IE)
     * - Client Select Trigger Interrupt Enable (SSIE)
     * - Data Register Empty Interrupt Enable (DREIE)
     * - Transfer Complete Interrupt Enable (TXCIE)
     * - Receive Complete Interrupt Enable (RXCIE)
     */
    class INTCTRL : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto IE        = std::uint_fast8_t{ 1 }; ///< IE.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 3 }; ///< RESERVED1.
            static constexpr auto SSIE      = std::uint_fast8_t{ 1 }; ///< SSIE.
            static constexpr auto DREIE     = std::uint_fast8_t{ 1 }; ///< DREIE.
            static constexpr auto TXCIE     = std::uint_fast8_t{ 1 }; ///< TXCIE.
            static constexpr auto RXCIE     = std::uint_fast8_t{ 1 }; ///< RXCIE.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto IE        = std::uint_fast8_t{};                ///< IE.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ IE + Size::IE }; ///< RESERVED1.
            static constexpr auto SSIE = std::uint_fast8_t{ RESERVED1 + Size::RESERVED1 }; ///< SSIE.
            static constexpr auto DREIE = std::uint_fast8_t{ SSIE + Size::SSIE }; ///< DREIE.
            static constexpr auto TXCIE = std::uint_fast8_t{ DREIE + Size::DREIE }; ///< TXCIE.
            static constexpr auto RXCIE = std::uint_fast8_t{ TXCIE + Size::TXCIE }; ///< RXCIE.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto IE = mask<std::uint8_t>( Size::IE, Bit::IE ); ///< IE.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
            static constexpr auto SSIE = mask<std::uint8_t>( Size::SSIE, Bit::SSIE ); ///< SSIE.
            static constexpr auto DREIE = mask<std::uint8_t>( Size::DREIE, Bit::DREIE ); ///< DREIE.
            static constexpr auto TXCIE = mask<std::uint8_t>( Size::TXCIE, Bit::TXCIE ); ///< TXCIE.
            static constexpr auto RXCIE = mask<std::uint8_t>( Size::RXCIE, Bit::RXCIE ); ///< RXCIE.
        };

        INTCTRL() = delete;

        INTCTRL( INTCTRL && ) = delete;

        INTCTRL( INTCTRL const & ) = delete;

        ~INTCTRL() = delete;

        auto operator=( INTCTRL && ) = delete;

        auto operator=( INTCTRL const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Interrupt Flags (INTFLAGS) register.
     *
     * This register has the following fields when buffer mode is not enabled:
     * - Write Collision (WRCOL)
     * - Interrupt Flag (IF)
     *
     * This register has the following fields when buffer mode is enabled:
     * - Buffer Overflow (BUFOVF)
     * - Client Select Trigger Interrupt Flag (SSIF)
     * - Data Register Empty Interrupt Flag (DREIF)
     * - Transfer Complete Interrupt Flag (TXCIF)
     * - Receive Complete Interrupt Flag (RXCIF)
     */
    class INTFLAGS : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto RESERVED0 = std::uint_fast8_t{ 6 }; ///< RESERVED0.
            static constexpr auto WRCOL     = std::uint_fast8_t{ 1 }; ///< WRCOL.
            static constexpr auto IF        = std::uint_fast8_t{ 1 }; ///< IF.

            static constexpr auto BUFOVF    = std::uint_fast8_t{ 1 }; ///< BUFOVF.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 3 }; ///< RESERVED1.
            static constexpr auto SSIF      = std::uint_fast8_t{ 1 }; ///< SSIF.
            static constexpr auto DREIF     = std::uint_fast8_t{ 1 }; ///< DREIF.
            static constexpr auto TXCIF     = std::uint_fast8_t{ 1 }; ///< TXCIF.
            static constexpr auto RXCIF     = std::uint_fast8_t{ 1 }; ///< RXCIF.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto RESERVED0 = std::uint_fast8_t{}; ///< RESERVED0.
            static constexpr auto WRCOL = std::uint_fast8_t{ RESERVED0 + Size::RESERVED0 }; ///< WRCOL.
            static constexpr auto IF = std::uint_fast8_t{ WRCOL + Size::WRCOL }; ///< IF.

            static constexpr auto BUFOVF = std::uint_fast8_t{}; ///< BUFOVF.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ BUFOVF + Size::BUFOVF }; ///< RESERVED1.
            static constexpr auto SSIF = std::uint_fast8_t{ RESERVED1 + Size::RESERVED1 }; ///< SSIF.
            static constexpr auto DREIF = std::uint_fast8_t{ SSIF + Size::SSIF }; ///< DREIF.
            static constexpr auto TXCIF = std::uint_fast8_t{ DREIF + Size::DREIF }; ///< TXCIF.
            static constexpr auto RXCIF = std::uint_fast8_t{ TXCIF + Size::TXCIF }; ///< RXCIF.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto RESERVED0 = mask<std::uint8_t>( Size::RESERVED0, Bit::RESERVED0 ); ///< RESERVED0.
            static constexpr auto WRCOL = mask<std::uint8_t>( Size::WRCOL, Bit::WRCOL ); ///< WRCOL.
            static constexpr auto IF = mask<std::uint8_t>( Size::IF, Bit::IF ); ///< IF.

            static constexpr auto BUFOVF = mask<std::uint8_t>( Size::BUFOVF, Bit::BUFOVF ); ///< BUFOVF.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
            static constexpr auto SSIF = mask<std::uint8_t>( Size::SSIF, Bit::SSIF ); ///< SSIF.
            static constexpr auto DREIF = mask<std::uint8_t>( Size::DREIF, Bit::DREIF ); ///< DREIF.
            static constexpr auto TXCIF = mask<std::uint8_t>( Size::TXCIF, Bit::TXCIF ); ///< TXCIF.
            static constexpr auto RXCIF = mask<std::uint8_t>( Size::RXCIF, Bit::RXCIF ); ///< RXCIF.
        };

        INTFLAGS() = delete;

        INTFLAGS( INTFLAGS && ) = delete;

        INTFLAGS( INTFLAGS const & ) = delete;

        ~INTFLAGS() = delete;

        auto operator=( INTFLAGS && ) = delete;

        auto operator=( INTFLAGS const & ) = delete;

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

    /**
     * \brief INTCTRL.
     */
    INTCTRL intctrl;

    /**
     * \brief INTFLAGS.
     */
    INTFLAGS intflags;

    /**
     * \brief Data (DATA) register.
     */
    Register<std::uint8_t> data;

    SPI() = delete;

    SPI( SPI && ) = delete;

    SPI( SPI const & ) = delete;

    ~SPI() = delete;

    auto operator=( SPI && ) = delete;

    auto operator=( SPI const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_SPI_H
