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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::USART interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_USART_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_USART_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr0/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series Universal Synchronous and Asynchronous Receiver and
 *        Transmitter (USART) peripheral.
 */
class USART {
  public:
    /**
     * \brief Receiver Data High Byte (RXDATAH) register.
     *
     * This register has the following fields:
     * - Receiver Data Register Bit 8 (DATA8)
     * - Parity Error (PERR)
     * - Frame Error (FERR)
     * - Buffer Overflow (BUFOVF)
     * - USART Receive Complete Interrupt Flag (RXCIF)
     */
    class RXDATAH : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto DATA8     = std::uint_fast8_t{ 1 }; ///< DATA8.
            static constexpr auto PERR      = std::uint_fast8_t{ 1 }; ///< PERR.
            static constexpr auto FERR      = std::uint_fast8_t{ 1 }; ///< FERR.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ 3 }; ///< RESERVED3.
            static constexpr auto BUFOVF    = std::uint_fast8_t{ 1 }; ///< BUFOVF.
            static constexpr auto RXCIF     = std::uint_fast8_t{ 1 }; ///< RXCIF.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto DATA8 = std::uint_fast8_t{}; ///< DATA8.
            static constexpr auto PERR = std::uint_fast8_t{ DATA8 + Size::DATA8 }; ///< PERR.
            static constexpr auto FERR = std::uint_fast8_t{ PERR + Size::PERR }; ///< FERR.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ FERR + Size::FERR }; ///< RESERVED3.
            static constexpr auto BUFOVF = std::uint_fast8_t{ RESERVED3 + Size::RESERVED3 }; ///< BUFOVF.
            static constexpr auto RXCIF = std::uint_fast8_t{ BUFOVF + Size::BUFOVF }; ///< RXCIF.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto DATA8 = mask<std::uint8_t>( Size::DATA8, Bit::DATA8 ); ///< DATA8.
            static constexpr auto PERR = mask<std::uint8_t>( Size::PERR, Bit::PERR ); ///< PERR.
            static constexpr auto FERR = mask<std::uint8_t>( Size::FERR, Bit::FERR ); ///< FERR.
            static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
            static constexpr auto BUFOVF = mask<std::uint8_t>( Size::BUFOVF, Bit::BUFOVF ); ///< BUFOVF.
            static constexpr auto RXCIF = mask<std::uint8_t>( Size::RXCIF, Bit::RXCIF ); ///< RXCIF.
        };

        RXDATAH() = delete;

        RXDATAH( RXDATAH && ) = delete;

        RXDATAH( RXDATAH const & ) = delete;

        ~RXDATAH() = delete;

        auto operator=( RXDATAH && ) = delete;

        auto operator=( RXDATAH const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Transmitter Data High Byte (TXDATAH) register.
     *
     * This register has the following fields:
     * - Transmitter Data Register Bit 8 (DATA8)
     */
    class TXDATAH : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto DATA8     = std::uint_fast8_t{ 1 }; ///< DATA8.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 7 }; ///< RESERVED1.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto DATA8 = std::uint_fast8_t{}; ///< DATA8.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ DATA8 + Size::DATA8 }; ///< RESERVED1.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto DATA8 = mask<std::uint8_t>( Size::DATA8, Bit::DATA8 ); ///< DATA8.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
        };

        TXDATAH() = delete;

        TXDATAH( TXDATAH && ) = delete;

        TXDATAH( TXDATAH const & ) = delete;

        ~TXDATAH() = delete;

        auto operator=( TXDATAH && ) = delete;

        auto operator=( TXDATAH const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief USART Status (STATUS) register.
     *
     * This register has the following fields:
     * - Wait For Break (WFB)
     * - Break Detected Flag (BDF)
     * - Inconsistent Synchronization Field Interrupt Flag (ISFIF)
     * - USART Receive Start Interrupt Flag (RXSIF)
     * - USART Data Register Empty Interrupt Flag (DREIF)
     * - USART Transmit Complete Interrupt Flag (TXCIF)
     * - USART Receive Complete Interrupt Flag (RXCIF)
     */
    class STATUS : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto WFB       = std::uint_fast8_t{ 1 }; ///< WFB.
            static constexpr auto BDF       = std::uint_fast8_t{ 1 }; ///< BDF.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ 1 }; ///< RESERVED2.
            static constexpr auto ISFIF     = std::uint_fast8_t{ 1 }; ///< ISFIF.
            static constexpr auto RXSIF     = std::uint_fast8_t{ 1 }; ///< RXSIF.
            static constexpr auto DREIF     = std::uint_fast8_t{ 1 }; ///< DREIF.
            static constexpr auto TXCIF     = std::uint_fast8_t{ 1 }; ///< TXCIF.
            static constexpr auto RXCIF     = std::uint_fast8_t{ 1 }; ///< RXCIF.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto WFB = std::uint_fast8_t{};                  ///< WFB.
            static constexpr auto BDF = std::uint_fast8_t{ WFB + Size::WFB }; ///< BDF.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ BDF + Size::BDF }; ///< RESERVED2.
            static constexpr auto ISFIF = std::uint_fast8_t{ RESERVED2 + Size::RESERVED2 }; ///< ISFIF.
            static constexpr auto RXSIF = std::uint_fast8_t{ ISFIF + Size::ISFIF }; ///< RXSIF.
            static constexpr auto DREIF = std::uint_fast8_t{ RXSIF + Size::RXSIF }; ///< DREIF.
            static constexpr auto TXCIF = std::uint_fast8_t{ DREIF + Size::DREIF }; ///< TXCIF.
            static constexpr auto RXCIF = std::uint_fast8_t{ TXCIF + Size::TXCIF }; ///< RXCIF.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto WFB = mask<std::uint8_t>( Size::WFB, Bit::WFB ); ///< WFB.
            static constexpr auto BDF = mask<std::uint8_t>( Size::BDF, Bit::BDF ); ///< BDF.
            static constexpr auto RESERVED2 = mask<std::uint8_t>( Size::RESERVED2, Bit::RESERVED2 ); ///< RESERVED2.
            static constexpr auto ISFIF = mask<std::uint8_t>( Size::ISFIF, Bit::ISFIF ); ///< ISFIF.
            static constexpr auto RXSIF = mask<std::uint8_t>( Size::RXSIF, Bit::RXSIF ); ///< RXSIF.
            static constexpr auto DREIF = mask<std::uint8_t>( Size::DREIF, Bit::DREIF ); ///< DREIF.
            static constexpr auto TXCIF = mask<std::uint8_t>( Size::TXCIF, Bit::TXCIF ); ///< TXCIF.
            static constexpr auto RXCIF = mask<std::uint8_t>( Size::RXCIF, Bit::RXCIF ); ///< RXCIF.
        };

        STATUS() = delete;

        STATUS( STATUS && ) = delete;

        STATUS( STATUS const & ) = delete;

        ~STATUS() = delete;

        auto operator=( STATUS && ) = delete;

        auto operator=( STATUS const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Control A (CTRLA) register.
     *
     * This register has the following fields:
     * - RS-485 Mode (RS485)
     * - Auto-Baud Error Interrupt Enable (ABEIE)
     * - Loop-Back Mode Enable (LBME)
     * - Receiver Start Frame Interrupt Enable (RXSIE)
     * - Data Register Empty Interrupt Enable (DREIE)
     * - Transmit Complete Interrupt Enable (TXCIE)
     * - Receive Complete Interrupt Enable (RXCIE)
     */
    class CTRLA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto RS485 = std::uint_fast8_t{ 2 }; ///< RS485.
            static constexpr auto ABEIE = std::uint_fast8_t{ 1 }; ///< ABEIE.
            static constexpr auto LBME  = std::uint_fast8_t{ 1 }; ///< LBME.
            static constexpr auto RXSIE = std::uint_fast8_t{ 1 }; ///< RXSIE.
            static constexpr auto DREIE = std::uint_fast8_t{ 1 }; ///< DREIE.
            static constexpr auto TXCIE = std::uint_fast8_t{ 1 }; ///< TXCIE.
            static constexpr auto RXCIE = std::uint_fast8_t{ 1 }; ///< RXCIE.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto RS485 = std::uint_fast8_t{}; ///< RS485.
            static constexpr auto ABEIE = std::uint_fast8_t{ RS485 + Size::RS485 }; ///< ABEIE.
            static constexpr auto LBME = std::uint_fast8_t{ ABEIE + Size::ABEIE }; ///< LBME.
            static constexpr auto RXSIE = std::uint_fast8_t{ LBME + Size::LBME }; ///< RXSIE.
            static constexpr auto DREIE = std::uint_fast8_t{ RXSIE + Size::RXSIE }; ///< DREIE.
            static constexpr auto TXCIE = std::uint_fast8_t{ DREIE + Size::DREIE }; ///< TXCIE.
            static constexpr auto RXCIE = std::uint_fast8_t{ TXCIE + Size::TXCIE }; ///< RXCIE.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto RS485 = mask<std::uint8_t>( Size::RS485, Bit::RS485 ); ///< RS485.
            static constexpr auto ABEIE = mask<std::uint8_t>( Size::ABEIE, Bit::ABEIE ); ///< ABEIE.
            static constexpr auto LBME = mask<std::uint8_t>( Size::LBME, Bit::LBME ); ///< LBME.
            static constexpr auto RXSIE = mask<std::uint8_t>( Size::RXSIE, Bit::RXSIE ); ///< RXSIE.
            static constexpr auto DREIE = mask<std::uint8_t>( Size::DREIE, Bit::DREIE ); ///< DREIE.
            static constexpr auto TXCIE = mask<std::uint8_t>( Size::TXCIE, Bit::TXCIE ); ///< TXCIE.
            static constexpr auto RXCIE = mask<std::uint8_t>( Size::RXCIE, Bit::RXCIE ); ///< RXCIE.
        };

        /**
         * \brief RS485.
         */
        enum RS485 : std::uint8_t {
            RS485_OFF = 0x0 << Bit::RS485, ///< RS485 mode disabled.
            RS485_EXT = 0x1 << Bit::RS485, ///< RS485 mode external drive.
            RS485_INT = 0x2 << Bit::RS485, ///< RS485 mode internal drive.
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
     * - Multi-Processor Communication Mode (MPCM)
     * - Receiver Mode (RXMODE)
     * - Open Drain Mode Enable (ODME)
     * - Start-of-Frame Detection Enable (SFDEN)
     * - Transmitter Enable (TXEN)
     * - Receiver Enable (RXEN)
     */
    class CTRLB : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto MPCM      = std::uint_fast8_t{ 1 }; ///< MPCM.
            static constexpr auto RXMODE    = std::uint_fast8_t{ 2 }; ///< RXMODE.
            static constexpr auto ODME      = std::uint_fast8_t{ 1 }; ///< ODME.
            static constexpr auto SFDEN     = std::uint_fast8_t{ 1 }; ///< SFDEN.
            static constexpr auto RESERVED5 = std::uint_fast8_t{ 1 }; ///< RESERVED5.
            static constexpr auto TXEN      = std::uint_fast8_t{ 1 }; ///< TXEN.
            static constexpr auto RXEN      = std::uint_fast8_t{ 1 }; ///< RXEN.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto MPCM = std::uint_fast8_t{}; ///< MPCM.
            static constexpr auto RXMODE = std::uint_fast8_t{ MPCM + Size::MPCM }; ///< RXMODE.
            static constexpr auto ODME = std::uint_fast8_t{ RXMODE + Size::RXMODE }; ///< ODME.
            static constexpr auto SFDEN = std::uint_fast8_t{ ODME + Size::ODME }; ///< SFDEN.
            static constexpr auto RESERVED5 = std::uint_fast8_t{ SFDEN + Size::SFDEN }; ///< RESERVED5.
            static constexpr auto TXEN = std::uint_fast8_t{ RESERVED5 + Size::RESERVED5 }; ///< TXEN.
            static constexpr auto RXEN = std::uint_fast8_t{ TXEN + Size::TXEN }; ///< RXEN.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto MPCM = mask<std::uint8_t>( Size::MPCM, Bit::MPCM ); ///< MPCM.
            static constexpr auto RXMODE = mask<std::uint8_t>( Size::RXMODE, Bit::RXMODE ); ///< RXMODE.
            static constexpr auto ODME = mask<std::uint8_t>( Size::ODME, Bit::ODME ); ///< ODME.
            static constexpr auto SFDEN = mask<std::uint8_t>( Size::SFDEN, Bit::SFDEN ); ///< SFDEN.
            static constexpr auto RESERVED5 = mask<std::uint8_t>( Size::RESERVED5, Bit::RESERVED5 ); ///< RESERVED5.
            static constexpr auto TXEN = mask<std::uint8_t>( Size::TXEN, Bit::TXEN ); ///< TXEN.
            static constexpr auto RXEN = mask<std::uint8_t>( Size::RXEN, Bit::RXEN ); ///< RXEN.
        };

        /**
         * \brief RXMODE.
         */
        enum RXMODE : std::uint8_t {
            RXMODE_NORMAL  = 0x0 << Bit::RXMODE, ///< Normal-speed mode.
            RXMODE_CLK2X   = 0x1 << Bit::RXMODE, ///< Double-speed mode.
            RXMODE_GENAUTO = 0x2 << Bit::RXMODE, ///< Generic auto-baud mode.
            RXMODE_LINAUTO = 0x3 << Bit::RXMODE, ///< LIN constrained auto-baud mode.
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
     * \brief Control C (CTRLC) register.
     *
     * This register has the following fields when it not in host SPI mode:
     * - Character Size (CHSIZE)
     * - Stop Bit Mode (SBMODE)
     * - Parity Mode (PMODE)
     * - USART Communication Mode (CMODE)
     *
     * This register has the following fields when it is in host SPI mode:
     * - USART Clock Phase (UCPHA)
     * - USART Data Order (UDORD)
     * - USART Communication Mode (CMODE)
     */
    class CTRLC : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto CHSIZE = std::uint_fast8_t{ 3 }; ///< CHSIZE.
            static constexpr auto SBMODE = std::uint_fast8_t{ 1 }; ///< SBMODE.
            static constexpr auto PMODE  = std::uint_fast8_t{ 2 }; ///< PMODE.

            static constexpr auto RESERVED0 = std::uint_fast8_t{ 1 }; ///< RESERVED0.
            static constexpr auto UCPHA     = std::uint_fast8_t{ 1 }; ///< UCPHA.
            static constexpr auto UDORD     = std::uint_fast8_t{ 1 }; ///< UDORD.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ 3 }; ///< RESERVED3.

            static constexpr auto CMODE = std::uint_fast8_t{ 2 }; ///< CMODE.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto CHSIZE = std::uint_fast8_t{}; ///< CHSIZE.
            static constexpr auto SBMODE = std::uint_fast8_t{ CHSIZE + Size::CHSIZE }; ///< SBMODE.
            static constexpr auto PMODE = std::uint_fast8_t{ SBMODE + Size::SBMODE }; ///< PMODE.

            static constexpr auto RESERVED0 = std::uint_fast8_t{}; ///< RESERVED0.
            static constexpr auto UCPHA = std::uint_fast8_t{ RESERVED0 + Size::RESERVED0 }; ///< UCPHA.
            static constexpr auto UDORD = std::uint_fast8_t{ UCPHA + Size::UCPHA }; ///< UDORD.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ UDORD + Size::UDORD }; ///< RESERVED3.

            static constexpr auto CMODE = std::uint_fast8_t{ 6 }; ///< CMODE.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto CHSIZE = mask<std::uint8_t>( Size::CHSIZE, Bit::CHSIZE ); ///< CHSIZE.
            static constexpr auto SBMODE = mask<std::uint8_t>( Size::SBMODE, Bit::SBMODE ); ///< SBMODE.
            static constexpr auto PMODE = mask<std::uint8_t>( Size::PMODE, Bit::PMODE ); ///< PMODE.

            static constexpr auto RESERVED0 = mask<std::uint8_t>( Size::RESERVED0, Bit::RESERVED0 ); ///< RESERVED0.
            static constexpr auto UCPHA = mask<std::uint8_t>( Size::UCPHA, Bit::UCPHA ); ///< UCPHA.
            static constexpr auto UDORD = mask<std::uint8_t>( Size::UDORD, Bit::UDORD ); ///< UDORD.
            static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.

            static constexpr auto CMODE = mask<std::uint8_t>( Size::CMODE, Bit::CMODE ); ///< CMODE.
        };

        /**
         * \brief CHSIZE.
         */
        enum CHSIZE : std::uint8_t {
            CHSIZE_5BIT  = 0x0 << Bit::CHSIZE, ///< 5-bit.
            CHSIZE_6BIT  = 0x1 << Bit::CHSIZE, ///< 6-bit.
            CHSIZE_7BIT  = 0x2 << Bit::CHSIZE, ///< 7-bit.
            CHSIZE_8BIT  = 0x3 << Bit::CHSIZE, ///< 8-bit.
            CHSIZE_9BITL = 0x6 << Bit::CHSIZE, ///< 9-bit (low byte first).
            CHSIZE_9BITH = 0x7 << Bit::CHSIZE, ///< 9-bit (high byte first).
        };

        /**
         * \brief PMODE.
         */
        enum PMODE : std::uint8_t {
            PMODE_DISABLED = 0x0 << Bit::PMODE, ///< Disabled.
            PMODE_EVEN     = 0x2 << Bit::PMODE, ///< Enabled, even parity.
            PMODE_ODD      = 0x3 << Bit::PMODE, ///< Enabled, odd parity.
        };

        /**
         * \brief CMODE.
         */
        enum CMODE : std::uint8_t {
            CMODE_ASYNCHRONOUS = 0x0 << Bit::CMODE, ///< Asynchronous USART.
            CMODE_SYNCHRONOUS  = 0x1 << Bit::CMODE, ///< Synchronous USART.
            CMODE_IRCOM        = 0x2 << Bit::CMODE, ///< Infrared communication.
            CMODE_MSPI         = 0x3 << Bit::CMODE, ///< Host SPI.
        };

        CTRLC() = delete;

        CTRLC( CTRLC && ) = delete;

        CTRLC( CTRLC const & ) = delete;

        ~CTRLC() = delete;

        auto operator=( CTRLC && ) = delete;

        auto operator=( CTRLC const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Control D (CTRLD) register.
     *
     * This register has the following fields:
     * - Auto-Baud Window Size (ABW)
     */
    class CTRLD : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto RESERVED0 = std::uint_fast8_t{ 6 }; ///< RESERVED0.
            static constexpr auto ABW       = std::uint_fast8_t{ 2 }; ///< ABW.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto RESERVED0 = std::uint_fast8_t{}; ///< RESERVED0.
            static constexpr auto ABW = std::uint_fast8_t{ RESERVED0 + Size::RESERVED0 }; ///< ABW.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto RESERVED0 = mask<std::uint8_t>( Size::RESERVED0, Bit::RESERVED0 ); ///< RESERVED0.
            static constexpr auto ABW = mask<std::uint8_t>( Size::ABW, Bit::ABW ); ///< ABW.
        };

        /**
         * \brief ABW.
         */
        enum ABW : std::uint8_t {
            ABW_WDW0 = 0x0 << Bit::ABW, ///< 32 +/- 6 (18% tolerance).
            ABW_WDW1 = 0x1 << Bit::ABW, ///< 32 +/- 5 (15% tolerance).
            ABW_WDW2 = 0x2 << Bit::ABW, ///< 32 +/- 7 (21% tolerance).
            ABW_WDW3 = 0x3 << Bit::ABW, ///< 32 +/- 8 (25% tolerance).
        };

        CTRLD() = delete;

        CTRLD( CTRLD && ) = delete;

        CTRLD( CTRLD const & ) = delete;

        ~CTRLD() = delete;

        auto operator=( CTRLD && ) = delete;

        auto operator=( CTRLD const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Debug Control (DBGCTRL) register.
     *
     * This register has the following fields:
     * - Debug Run (DBGRUN)
     */
    class DBGCTRL : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto DBGRUN    = std::uint_fast8_t{ 1 }; ///< DBGRUN.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 7 }; ///< RESERVED1.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto DBGRUN = std::uint_fast8_t{}; ///< DBGRUN.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ DBGRUN + Size::DBGRUN }; ///< RESERVED1.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto DBGRUN = mask<std::uint8_t>( Size::DBGRUN, Bit::DBGRUN ); ///< DBGRUN.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
        };

        DBGCTRL() = delete;

        DBGCTRL( DBGCTRL && ) = delete;

        DBGCTRL( DBGCTRL const & ) = delete;

        ~DBGCTRL() = delete;

        auto operator=( DBGCTRL && ) = delete;

        auto operator=( DBGCTRL const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief IrDA Control (EVCTRL) register.
     *
     * This register has the following fields:
     * - IrDA Event Input Enable (IREI)
     */
    class EVCTRL : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto IREI      = std::uint_fast8_t{ 1 }; ///< IREI.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 7 }; ///< RESERVED1.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto IREI = std::uint_fast8_t{}; ///< IREI.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ IREI + Size::IREI }; ///< RESERVED1.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto IREI = mask<std::uint8_t>( Size::IREI, Bit::IREI ); ///< IREI.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
        };

        EVCTRL() = delete;

        EVCTRL( EVCTRL && ) = delete;

        EVCTRL( EVCTRL const & ) = delete;

        ~EVCTRL() = delete;

        auto operator=( EVCTRL && ) = delete;

        auto operator=( EVCTRL const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief IRCOM Receiver Pulse Length Control (RXPLCTRL) register.
     *
     * This register has the following fields:
     * - Receiver Pulse Length (RXPL)
     */
    class RXPLCTRL : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto RXPL      = std::uint_fast8_t{ 7 }; ///< RXPL.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ 1 }; ///< RESERVED7.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto RXPL = std::uint_fast8_t{}; ///< RXPL.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ RXPL + Size::RXPL }; ///< RESERVED7.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto RXPL = mask<std::uint8_t>( Size::RXPL, Bit::RXPL ); ///< RXPL.
            static constexpr auto RESERVED7 = mask<std::uint8_t>( Size::RESERVED7, Bit::RESERVED7 ); ///< RESERVED7.
        };

        RXPLCTRL() = delete;

        RXPLCTRL( RXPLCTRL && ) = delete;

        RXPLCTRL( RXPLCTRL const & ) = delete;

        ~RXPLCTRL() = delete;

        auto operator=( RXPLCTRL && ) = delete;

        auto operator=( RXPLCTRL const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Receiver Data Low Byte (RXDATAL) register.
     */
    Register<std::uint8_t> const rxdatal;

    /**
     * \brief RXDATAH.
     */
    RXDATAH const rxdatah;

    /**
     * \brief Transmitter Data Low Byte (TXDATAL) register.
     */
    Register<std::uint8_t> txdatal;

    /**
     * \brief TXDATAH.
     */
    TXDATAH txdatah;

    /**
     * \brief STATUS.
     */
    STATUS status;

    /**
     * \brief CTRLA.
     */
    CTRLA ctrla;

    /**
     * \brief CTRLB.
     */
    CTRLB ctrlb;

    /**
     * \brief CTRLC.
     */
    CTRLC ctrlc;

    union {
        /**
         * \brief Baud (BAUD) register.
         */
        Register<std::uint16_t> baud;

        struct {
            /**
             * \brief Baud Low Byte (BAUDL) register.
             */
            Register<std::uint8_t> baudl;

            /**
             * \brief Baud High Byte (BAUDH) register.
             */
            Register<std::uint8_t> baudh;
        };
    };

    /**
     * \brief CTRLD.
     */
    CTRLD ctrld;

    /**
     * \brief DBGCTRL.
     */
    DBGCTRL dbgctrl;

    /**
     * \brief EVCTRL.
     */
    EVCTRL evctrl;

    /**
     * \brief IRCOM Transmitter Pulse Length Control (TXPLCTRL) register.
     */
    Register<std::uint8_t> txplctrl;

    /**
     * \brief RXPLCTRL.
     */
    RXPLCTRL rxplctrl;

    USART() = delete;

    USART( USART && ) = delete;

    USART( USART const & ) = delete;

    ~USART() = delete;

    auto operator=( USART && ) = delete;

    auto operator=( USART const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_USART_H
