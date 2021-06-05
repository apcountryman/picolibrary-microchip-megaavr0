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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::SPI interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_SPI_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_SPI_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr0/peripheral/instance.h"
#include "picolibrary/microchip/megaavr0/register.h"

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
     * - Host/Client Select (HOST)
     * - Data Order (DORD)
     */
    class CTRLA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field Sizes.
         */
        struct Size {
            static constexpr auto ENABLE    = std::uint_fast8_t{ 1 }; ///< ENABLE.
            static constexpr auto PRESC     = std::uint_fast8_t{ 2 }; ///< PRESC.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ 1 }; ///< Reserved.
            static constexpr auto CLK2X     = std::uint_fast8_t{ 1 }; ///< CLK2X.
            static constexpr auto HOST      = std::uint_fast8_t{ 1 }; ///< HOST.
            static constexpr auto DORD      = std::uint_fast8_t{ 1 }; ///< DORD.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ 1 }; ///< Reserved.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto ENABLE = std::uint_fast8_t{}; ///< ENABLE.
            static constexpr auto PRESC = std::uint_fast8_t{ ENABLE + Size::ENABLE }; ///< PRESC.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ PRESC + Size::PRESC }; ///< Reserved.
            static constexpr auto CLK2X = std::uint_fast8_t{ RESERVED3 + Size::RESERVED3 }; ///< CLK2X.
            static constexpr auto HOST = std::uint_fast8_t{ CLK2X + Size::CLK2X }; ///< HOST.
            static constexpr auto DORD = std::uint_fast8_t{ HOST + Size::HOST }; ///< DORD.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ DORD + Size::DORD }; ///< Reserved.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto ENABLE = mask<std::uint8_t>( Size::ENABLE, Bit::ENABLE ); ///< ENABLE.
            static constexpr auto PRESC = mask<std::uint8_t>( Size::PRESC, Bit::PRESC ); ///< PRESC.
            static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< Reserved.
            static constexpr auto CLK2X = mask<std::uint8_t>( Size::CLK2X, Bit::CLK2X ); ///< CLK2X.
            static constexpr auto HOST = mask<std::uint8_t>( Size::HOST, Bit::HOST ); ///< HOST.
            static constexpr auto DORD = mask<std::uint8_t>( Size::DORD, Bit::DORD ); ///< DORD.
            static constexpr auto RESERVED7 = mask<std::uint8_t>( Size::RESERVED7, Bit::RESERVED7 ); ///< Reserved.
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
     * - Client Select Disable (CSD)
     * - Buffer Mode Wait for Receive (BUFWR)
     * - Buffer Mode Enable (BUFEN)
     */
    class CTRLB : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field Sizes.
         */
        struct Size {
            static constexpr auto MODE      = std::uint_fast8_t{ 2 }; ///< MODE.
            static constexpr auto CSD       = std::uint_fast8_t{ 1 }; ///< CSD.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ 3 }; ///< Reserved.
            static constexpr auto BUFWR     = std::uint_fast8_t{ 1 }; ///< BUFWR.
            static constexpr auto BUFEN     = std::uint_fast8_t{ 1 }; ///< BUFEN.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto MODE = std::uint_fast8_t{}; ///< MODE.
            static constexpr auto CSD  = std::uint_fast8_t{ MODE + Size::MODE }; ///< CSD.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ CSD + Size::CSD }; ///< Reserved.
            static constexpr auto BUFWR = std::uint_fast8_t{ RESERVED3 + Size::RESERVED3 }; ///< BUFWR.
            static constexpr auto BUFEN = std::uint_fast8_t{ BUFWR + Size::BUFWR }; ///< BUFEN.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto MODE = mask<std::uint8_t>( Size::MODE, Bit::MODE ); ///< MODE.
            static constexpr auto CSD = mask<std::uint8_t>( Size::CSD, Bit::CSD ); ///< CSD.
            static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< Reserved.
            static constexpr auto BUFWR = mask<std::uint8_t>( Size::BUFWR, Bit::BUFWR ); ///< BUFWR.
            static constexpr auto BUFEN = mask<std::uint8_t>( Size::BUFEN, Bit::BUFEN ); ///< BUFEN.
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
     * - Client Select Trigger Interrupt Enable (CSIE)
     * - Data Register Empty Interrupt Enable (DREIE)
     * - Transfer Complete Interrupt Enable (TXCIE)
     * - Receive Complete Interrupt Enable (RXCIE)
     */
    class INTCTRL : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field Sizes.
         */
        struct Size {
            static constexpr auto IE        = std::uint_fast8_t{ 1 }; ///< IE.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 3 }; ///< Reserved.
            static constexpr auto CSIE      = std::uint_fast8_t{ 1 }; ///< CSIE.
            static constexpr auto DREIE     = std::uint_fast8_t{ 1 }; ///< DREIE.
            static constexpr auto TXCIE     = std::uint_fast8_t{ 1 }; ///< TXCIE.
            static constexpr auto RXCIE     = std::uint_fast8_t{ 1 }; ///< RXCIE.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto IE        = std::uint_fast8_t{};                ///< IE.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ IE + Size::IE }; ///< Reserved.
            static constexpr auto CSIE = std::uint_fast8_t{ RESERVED1 + Size::RESERVED1 }; ///< CSIE.
            static constexpr auto DREIE = std::uint_fast8_t{ CSIE + Size::CSIE }; ///< DREIE.
            static constexpr auto TXCIE = std::uint_fast8_t{ DREIE + Size::DREIE }; ///< TXCIE.
            static constexpr auto RXCIE = std::uint_fast8_t{ TXCIE + Size::TXCIE }; ///< RXCIE.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto IE = mask<std::uint8_t>( Size::IE, Bit::IE ); ///< IE.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< Reserved.
            static constexpr auto CSIE = mask<std::uint8_t>( Size::CSIE, Bit::CSIE ); ///< CSIE.
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
     * This register has the following fields:
     * - Write Collision (WRCOL)
     * - Interrupt Flag (IF)
     * - Buffer Overflow (BUFOVF)
     * - Client Select Trigger Interrupt Flag (CSIF)
     * - Data Register Empty Interrupt Flag (DREIF)
     * - Transfer Complete Interrupt Flag (TXCIF)
     * - Receive Complete Interrupt Flag (RXCIE)
     */
    class INTFLAGS : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field Sizes.
         */
        struct Size {
            static constexpr auto RESERVED0 = std::uint_fast8_t{ 6 }; ///< Reserved.
            static constexpr auto WRCOL     = std::uint_fast8_t{ 1 }; ///< WRCOL.
            static constexpr auto IF        = std::uint_fast8_t{ 1 }; ///< IF.

            static constexpr auto BUFOVF    = std::uint_fast8_t{ 1 }; ///< BUFOVF.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 3 }; ///< Reserved.
            static constexpr auto CSIF      = std::uint_fast8_t{ 1 }; ///< CSIF.
            static constexpr auto DREIF     = std::uint_fast8_t{ 1 }; ///< DREIF.
            static constexpr auto TXCIF     = std::uint_fast8_t{ 1 }; ///< TXCIF.
            static constexpr auto RXCIF     = std::uint_fast8_t{ 1 }; ///< RXCIF.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto RESERVED0 = std::uint_fast8_t{}; ///< Reserved.
            static constexpr auto WRCOL = std::uint_fast8_t{ RESERVED0 + Size::RESERVED0 }; ///< WRCOL.
            static constexpr auto IF = std::uint_fast8_t{ WRCOL + Size::WRCOL }; ///< IF.

            static constexpr auto BUFOVF = std::uint_fast8_t{}; ///< BUFOVF.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ BUFOVF + Size::BUFOVF }; ///< Reserved.
            static constexpr auto CSIF = std::uint_fast8_t{ RESERVED1 + Size::RESERVED1 }; ///< CSIF.
            static constexpr auto DREIF = std::uint_fast8_t{ CSIF + Size::CSIF }; ///< DREIF.
            static constexpr auto TXCIF = std::uint_fast8_t{ DREIF + Size::DREIF }; ///< TXCIF.
            static constexpr auto RXCIF = std::uint_fast8_t{ TXCIF + Size::TXCIF }; ///< RXCIF.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto RESERVED0 = mask<std::uint8_t>( Size::RESERVED0, Bit::RESERVED0 ); ///< Reserved.
            static constexpr auto WRCOL = mask<std::uint8_t>( Size::WRCOL, Bit::WRCOL ); ///< WRCOL.
            static constexpr auto IF = mask<std::uint8_t>( Size::IF, Bit::IF ); ///< IF.

            static constexpr auto BUFOVF = mask<std::uint8_t>( Size::BUFOVF, Bit::BUFOVF ); ///< BUFOVF.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< Reserved.
            static constexpr auto CSIF = mask<std::uint8_t>( Size::CSIF, Bit::CSIF ); ///< CSIF.
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

/**
 * \brief Microchip megaAVR 0-series Serial Peripheral Interface (SPI) peripheral
 *        instance.
 *
 * \tparam INSTANCE_ADDRESS The address of the SPI instance.
 */
template<std::uintptr_t INSTANCE_ADDRESS>
using SPI_Instance = Instance<SPI, INSTANCE_ADDRESS>;

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_SPI_H
