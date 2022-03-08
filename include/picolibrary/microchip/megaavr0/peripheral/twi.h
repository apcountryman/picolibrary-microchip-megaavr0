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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::TWI interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_TWI_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_TWI_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr0/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series Two-Wire Interface (TWI) peripheral.
 */
class TWI {
  public:
    /**
     * \brief Control A (CTRLA) register.
     *
     * This register has the following fields:
     * - FM Plus Enable (FMPEN)
     * - SDA Hold Time (SDAHOLD)
     * - SDA Setup Time (SDASETUP)
     */
    class CTRLA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto RESERVED0 = std::uint_fast8_t{ 1 }; ///< RESERVED0.
            static constexpr auto FMPEN     = std::uint_fast8_t{ 1 }; ///< FMPEN.
            static constexpr auto SDAHOLD   = std::uint_fast8_t{ 2 }; ///< SDAHOLD.
            static constexpr auto SDASETUP  = std::uint_fast8_t{ 1 }; ///< SDASETUP.
            static constexpr auto RESERVED5 = std::uint_fast8_t{ 3 }; ///< RESERVED5.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto RESERVED0 = std::uint_fast8_t{}; ///< RESERVED0.
            static constexpr auto FMPEN = std::uint_fast8_t{ RESERVED0 + Size::RESERVED0 }; ///< FMPEN.
            static constexpr auto SDAHOLD = std::uint_fast8_t{ FMPEN + Size::FMPEN }; ///< SDAHOLD.
            static constexpr auto SDASETUP = std::uint_fast8_t{ SDAHOLD + Size::SDAHOLD }; ///< SDASETUP.
            static constexpr auto RESERVED5 = std::uint_fast8_t{ SDASETUP + Size::SDASETUP }; ///< RESERVED5.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto RESERVED0 = mask<std::uint8_t>( Size::RESERVED0, Bit::RESERVED0 ); ///< RESERVED0.
            static constexpr auto FMPEN = mask<std::uint8_t>( Size::FMPEN, Bit::FMPEN ); ///< FMPEN.
            static constexpr auto SDAHOLD = mask<std::uint8_t>( Size::SDAHOLD, Bit::SDAHOLD ); ///< SDAHOLD.
            static constexpr auto SDASETUP = mask<std::uint8_t>( Size::SDASETUP, Bit::SDASETUP ); ///< SDASETUP.
            static constexpr auto RESERVED5 = mask<std::uint8_t>( Size::RESERVED5, Bit::RESERVED5 ); ///< RESERVED5.
        };

        /**
         * \brief SDAHOLD.
         */
        enum SDAHOLD : std::uint8_t {
            SDAHOLD_OFF   = 0x0 << Bit::SDAHOLD, ///< Hold time off.
            SDAHOLD_50NS  = 0x1 << Bit::SDAHOLD, ///< Short hold time.
            SDAHOLD_300NS = 0x2 << Bit::SDAHOLD, ///< Meets the SMBus 2.0 specifications under typical conditions.
            SDAHOLD_500NS = 0x3 << Bit::SDAHOLD, ///< Meets the SMBus 2.0 specifications acress all corners.
        };

        /**
         * \brief SDASETUP.
         */
        enum SDASETUP : std::uint8_t {
            SDASETUP_4CYC = 0 << Bit::SDASETUP, ///< SDA setup time is four clock cycles.
            SDASETUP_8CYC = 1 << Bit::SDASETUP, ///< SDA setup time is eight clock cycles.
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
     * \brief Dual Mode Control Configuration (DUALCTRL) register.
     *
     * This register has the following fields:
     * - Dual Control Enable (ENABLE)
     * - FM Plus Enable (FMPEN)
     * - SDA Hold Time (SDAHOLD)
     */
    class DUALCTRL : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto ENABLE    = std::uint_fast8_t{ 1 }; ///< ENABLE.
            static constexpr auto FMPEN     = std::uint_fast8_t{ 1 }; ///< FMPEN.
            static constexpr auto SDAHOLD   = std::uint_fast8_t{ 2 }; ///< SDAHOLD.
            static constexpr auto RESERVED4 = std::uint_fast8_t{ 4 }; ///< RESERVED4.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto ENABLE = std::uint_fast8_t{}; ///< ENABLE.
            static constexpr auto FMPEN = std::uint_fast8_t{ ENABLE + Size::ENABLE }; ///< FMPEN.
            static constexpr auto SDAHOLD = std::uint_fast8_t{ FMPEN + Size::FMPEN }; ///< SDAHOLD.
            static constexpr auto RESERVED4 = std::uint_fast8_t{ SDAHOLD + Size::SDAHOLD }; ///< RESERVED4.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto ENABLE = mask<std::uint8_t>( Size::ENABLE, Bit::ENABLE ); ///< ENABLE.
            static constexpr auto FMPEN = mask<std::uint8_t>( Size::FMPEN, Bit::FMPEN ); ///< FMPEN.
            static constexpr auto SDAHOLD = mask<std::uint8_t>( Size::SDAHOLD, Bit::SDAHOLD ); ///< SDAHOLD.
            static constexpr auto RESERVED4 = mask<std::uint8_t>( Size::RESERVED4, Bit::RESERVED4 ); ///< RESERVED4.
        };

        /**
         * \brief SDAHOLD.
         */
        enum SDAHOLD : std::uint8_t {
            SDAHOLD_OFF   = 0x0 << Bit::SDAHOLD, ///< Hold time off.
            SDAHOLD_50NS  = 0x1 << Bit::SDAHOLD, ///< Short hold time.
            SDAHOLD_300NS = 0x2 << Bit::SDAHOLD, ///< Meets the SMBus 2.0 specifications under typical conditions.
            SDAHOLD_500NS = 0x3 << Bit::SDAHOLD, ///< Meets the SMBus 2.0 specifications acress all corners.
        };

        DUALCTRL() = delete;

        DUALCTRL( DUALCTRL && ) = delete;

        DUALCTRL( DUALCTRL const & ) = delete;

        ~DUALCTRL() = delete;

        auto operator=( DUALCTRL && ) = delete;

        auto operator=( DUALCTRL const & ) = delete;

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
     * \brief Host Control A (MCTRLA) register.
     *
     * This register has the following fields:
     * - Enable TWI Host (ENABLE)
     * - Smart Mode Enable (SMEN)
     * - Inactive Bus Time-Out (TIMEOUT)
     * - Quick Command Enable (QCEN)
     * - Write Interrupt Enable (WIEN)
     * - Read Interrupt Enable (RIEN)
     */
    class MCTRLA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto ENABLE    = std::uint_fast8_t{ 1 }; ///< ENABLE.
            static constexpr auto SMEN      = std::uint_fast8_t{ 1 }; ///< SMEN.
            static constexpr auto TIMEOUT   = std::uint_fast8_t{ 2 }; ///< TIMEOUT.
            static constexpr auto QCEN      = std::uint_fast8_t{ 1 }; ///< QCEN.
            static constexpr auto RESERVED5 = std::uint_fast8_t{ 1 }; ///< RESERVED5.
            static constexpr auto WIEN      = std::uint_fast8_t{ 1 }; ///< WIEN.
            static constexpr auto RIEN      = std::uint_fast8_t{ 1 }; ///< RIEN.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto ENABLE = std::uint_fast8_t{}; ///< ENABLE.
            static constexpr auto SMEN = std::uint_fast8_t{ ENABLE + Size::ENABLE }; ///< SMEN.
            static constexpr auto TIMEOUT = std::uint_fast8_t{ SMEN + Size::SMEN }; ///< TIMEOUT.
            static constexpr auto QCEN = std::uint_fast8_t{ TIMEOUT + Size::TIMEOUT }; ///< QCEN.
            static constexpr auto RESERVED5 = std::uint_fast8_t{ QCEN + Size::QCEN }; ///< RESERVED5.
            static constexpr auto WIEN = std::uint_fast8_t{ RESERVED5 + Size::RESERVED5 }; ///< WIEN.
            static constexpr auto RIEN = std::uint_fast8_t{ WIEN + Size::WIEN }; ///< RIEN.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto ENABLE = mask<std::uint8_t>( Size::ENABLE, Bit::ENABLE ); ///< ENABLE.
            static constexpr auto SMEN = mask<std::uint8_t>( Size::SMEN, Bit::SMEN ); ///< SMEN.
            static constexpr auto TIMEOUT = mask<std::uint8_t>( Size::TIMEOUT, Bit::TIMEOUT ); ///< TIMEOUT.
            static constexpr auto QCEN = mask<std::uint8_t>( Size::QCEN, Bit::QCEN ); ///< QCEN.
            static constexpr auto RESERVED5 = mask<std::uint8_t>( Size::RESERVED5, Bit::RESERVED5 ); ///< RESERVED5.
            static constexpr auto WIEN = mask<std::uint8_t>( Size::WIEN, Bit::WIEN ); ///< WIEN.
            static constexpr auto RIEN = mask<std::uint8_t>( Size::RIEN, Bit::RIEN ); ///< RIEN.
        };

        /**
         * \brief TIMEOUT.
         */
        enum TIMEOUT : std::uint8_t {
            TIMEOUT_DISABLED = 0x0 << Bit::TIMEOUT, ///< Bus time-out disabled - I2C.
            TIMEOUT_50US     = 0x1 << Bit::TIMEOUT, ///< 50 us - SMBus (assume the baud rate is set to 100 kHz).
            TIMEOUT_100US = 0x2 << Bit::TIMEOUT, ///< 100 us (assume the baud rate is set to 100 kHz).
            TIMEOUT_200US = 0x3 << Bit::TIMEOUT, ///< 200 us (assume the baud rate is set to 100 kHz).
        };

        MCTRLA() = delete;

        MCTRLA( MCTRLA && ) = delete;

        MCTRLA( MCTRLA const & ) = delete;

        ~MCTRLA() = delete;

        auto operator=( MCTRLA && ) = delete;

        auto operator=( MCTRLA const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Host Control B (MCTRLB) register.
     *
     * This register has the following fields:
     * - Command (MCMD)
     * - Acknowledge Action (ACKACT)
     * - Flush (FLUSH)
     */
    class MCTRLB : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto MCMD      = std::uint_fast8_t{ 2 }; ///< MCMD.
            static constexpr auto ACKACT    = std::uint_fast8_t{ 1 }; ///< ACKACT.
            static constexpr auto FLUSH     = std::uint_fast8_t{ 1 }; ///< FLUSH.
            static constexpr auto RESERVED4 = std::uint_fast8_t{ 4 }; ///< RESERVED4.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto MCMD = std::uint_fast8_t{}; ///< MCMD.
            static constexpr auto ACKACT = std::uint_fast8_t{ MCMD + Size::MCMD }; ///< ACKACT.
            static constexpr auto FLUSH = std::uint_fast8_t{ ACKACT + Size::ACKACT }; ///< FLUSH.
            static constexpr auto RESERVED4 = std::uint_fast8_t{ FLUSH + Size::FLUSH }; ///< RESERVED4.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto MCMD = mask<std::uint8_t>( Size::MCMD, Bit::MCMD ); ///< MCMD.
            static constexpr auto ACKACT = mask<std::uint8_t>( Size::ACKACT, Bit::ACKACT ); ///< ACKACT.
            static constexpr auto FLUSH = mask<std::uint8_t>( Size::FLUSH, Bit::FLUSH ); ///< FLUSH.
            static constexpr auto RESERVED4 = mask<std::uint8_t>( Size::RESERVED4, Bit::RESERVED4 ); ///< RESERVED4.
        };

        /**
         * \brief ACKACT.
         */
        enum ACKACT : std::uint8_t {
            ACKACT_ACK  = 0 << Bit::ACKACT, ///< Send ACK.
            ACKACT_NACK = 1 << Bit::ACKACT, ///< Send NACK.
        };

        /**
         * \brief MCMD.
         */
        enum MCMD : std::uint8_t {
            MCMD_NOACT     = 0x0 << Bit::MCMD, ///< Reserved.
            MCMD_REPSTART  = 0x1 << Bit::MCMD, ///< Execute Acknowledge Action followed by repeated start condition.
            MCMD_RECVTRANS = 0x2 << Bit::MCMD, ///< See datasheet.
            MCMD_STOP      = 0x3 << Bit::MCMD, ///< Execute Acknowledge Action followed by issuing a stop condition.
        };

        MCTRLB() = delete;

        MCTRLB( MCTRLB && ) = delete;

        MCTRLB( MCTRLB const & ) = delete;

        ~MCTRLB() = delete;

        auto operator=( MCTRLB && ) = delete;

        auto operator=( MCTRLB const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Host Status (MSTATUS) register.
     *
     * This register has the following fields:
     * - Bus State (BUSSTATE)
     * - Bus Error (BUSERR)
     * - Arbitration Lost (ARBLOST)
     * - Received Acknowledge (RXACK)
     * - Clock Hold (CLKHOLD)
     * - Write Interrupt Flag (WIF)
     * - Read Interrupt Flag (RIF)
     */
    class MSTATUS : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto BUSSTATE = std::uint_fast8_t{ 2 }; ///< BUSSTATE.
            static constexpr auto BUSERR   = std::uint_fast8_t{ 1 }; ///< BUSERR.
            static constexpr auto ARBLOST  = std::uint_fast8_t{ 1 }; ///< ARBLOST.
            static constexpr auto RXACK    = std::uint_fast8_t{ 1 }; ///< RXACK.
            static constexpr auto CLKHOLD  = std::uint_fast8_t{ 1 }; ///< CLKHOLD.
            static constexpr auto WIF      = std::uint_fast8_t{ 1 }; ///< WIF.
            static constexpr auto RIF      = std::uint_fast8_t{ 1 }; ///< RIF.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto BUSSTATE = std::uint_fast8_t{}; ///< BUSSTATE.
            static constexpr auto BUSERR = std::uint_fast8_t{ BUSSTATE + Size::BUSSTATE }; ///< BUSERR.
            static constexpr auto ARBLOST = std::uint_fast8_t{ BUSERR + Size::BUSERR }; ///< ARBLOST.
            static constexpr auto RXACK = std::uint_fast8_t{ ARBLOST + Size::ARBLOST }; ///< RXACK.
            static constexpr auto CLKHOLD = std::uint_fast8_t{ RXACK + Size::RXACK }; ///< CLKHOLD.
            static constexpr auto WIF = std::uint_fast8_t{ CLKHOLD + Size::CLKHOLD }; ///< WIF.
            static constexpr auto RIF = std::uint_fast8_t{ WIF + Size::WIF }; ///< RIF.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto BUSSTATE = mask<std::uint8_t>( Size::BUSSTATE, Bit::BUSSTATE ); ///< BUSSTATE.
            static constexpr auto BUSERR = mask<std::uint8_t>( Size::BUSERR, Bit::BUSERR ); ///< BUSERR.
            static constexpr auto ARBLOST = mask<std::uint8_t>( Size::ARBLOST, Bit::ARBLOST ); ///< ARBLOST.
            static constexpr auto RXACK = mask<std::uint8_t>( Size::RXACK, Bit::RXACK ); ///< RXACK.
            static constexpr auto CLKHOLD = mask<std::uint8_t>( Size::CLKHOLD, Bit::CLKHOLD ); ///< CLKHOLD.
            static constexpr auto WIF = mask<std::uint8_t>( Size::WIF, Bit::WIF ); ///< WIF.
            static constexpr auto RIF = mask<std::uint8_t>( Size::RIF, Bit::RIF ); ///< RIF.
        };

        /**
         * \brief BUSSTATE.
         */
        enum BUSSTATE : std::uint8_t {
            BUSSTATE_UNKNOWN = 0x0 << Bit::BUSSTATE, ///< Unknown bus state.
            BUSSTATE_IDLE    = 0x1 << Bit::BUSSTATE, ///< Idle bus state.
            BUSSTATE_OWNER   = 0x2 << Bit::BUSSTATE, ///< This TWI controls the bus.
            BUSSTATE_BUSY    = 0x3 << Bit::BUSSTATE, ///< Busy bus state.
        };

        MSTATUS() = delete;

        MSTATUS( MSTATUS && ) = delete;

        MSTATUS( MSTATUS const & ) = delete;

        ~MSTATUS() = delete;

        auto operator=( MSTATUS && ) = delete;

        auto operator=( MSTATUS const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Client Control A (SCTRLA) register.
     *
     * This register has the following fields:
     * - Enable TWI Client (ENABLE)
     * - Smart Mode Enable (SMEN)
     * - Permissive Mode Enable (PMEN)
     * - Stop Interrupt Enable (PIEN)
     * - Address or Stop Interrupt Enable (APIEN)
     * - Data Interrupt Enable (DIEN)
     */
    class SCTRLA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto ENABLE    = std::uint_fast8_t{ 1 }; ///< ENABLE.
            static constexpr auto SMEN      = std::uint_fast8_t{ 1 }; ///< SMEN.
            static constexpr auto PMEN      = std::uint_fast8_t{ 1 }; ///< PMEN.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ 2 }; ///< RESERVED3.
            static constexpr auto PIEN      = std::uint_fast8_t{ 1 }; ///< PIEN.
            static constexpr auto APIEN     = std::uint_fast8_t{ 1 }; ///< APIEN.
            static constexpr auto DIEN      = std::uint_fast8_t{ 1 }; ///< DIEN.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto ENABLE = std::uint_fast8_t{}; ///< ENABLE.
            static constexpr auto SMEN = std::uint_fast8_t{ ENABLE + Size::ENABLE }; ///< SMEN.
            static constexpr auto PMEN = std::uint_fast8_t{ SMEN + Size::SMEN }; ///< PMEN.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ PMEN + Size::PMEN }; ///< RESERVED3.
            static constexpr auto PIEN = std::uint_fast8_t{ RESERVED3 + Size::RESERVED3 }; ///< PIEN.
            static constexpr auto APIEN = std::uint_fast8_t{ PIEN + Size::PIEN }; ///< APIEN.
            static constexpr auto DIEN = std::uint_fast8_t{ APIEN + Size::APIEN }; ///< DIEN.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto ENABLE = mask<std::uint8_t>( Size::ENABLE, Bit::ENABLE ); ///< ENABLE.
            static constexpr auto SMEN = mask<std::uint8_t>( Size::SMEN, Bit::SMEN ); ///< SMEN.
            static constexpr auto PMEN = mask<std::uint8_t>( Size::PMEN, Bit::PMEN ); ///< PMEN.
            static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
            static constexpr auto PIEN = mask<std::uint8_t>( Size::PIEN, Bit::PIEN ); ///< PIEN.
            static constexpr auto APIEN = mask<std::uint8_t>( Size::APIEN, Bit::APIEN ); ///< APIEN.
            static constexpr auto DIEN = mask<std::uint8_t>( Size::DIEN, Bit::DIEN ); ///< DIEN.
        };

        SCTRLA() = delete;

        SCTRLA( SCTRLA && ) = delete;

        SCTRLA( SCTRLA const & ) = delete;

        ~SCTRLA() = delete;

        auto operator=( SCTRLA && ) = delete;

        auto operator=( SCTRLA const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Client Control B (SCTRLB) register.
     *
     * This register has the following fields:
     * - Command (SCMD)
     * - Acknowledge Action (ACKACT)
     */
    class SCTRLB : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto SCMD      = std::uint_fast8_t{ 2 }; ///< SCMD.
            static constexpr auto ACKACT    = std::uint_fast8_t{ 1 }; ///< ACKACT.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ 5 }; ///< RESERVED3.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto SCMD = std::uint_fast8_t{}; ///< SCMD.
            static constexpr auto ACKACT = std::uint_fast8_t{ SCMD + Size::SCMD }; ///< ACKACT.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ ACKACT + Size::ACKACT }; ///< RESERVED3.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto SCMD = mask<std::uint8_t>( Size::SCMD, Bit::SCMD ); ///< SCMD.
            static constexpr auto ACKACT = mask<std::uint8_t>( Size::ACKACT, Bit::ACKACT ); ///< ACKACT.
            static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
        };

        /**
         * \brief ACKACT.
         */
        enum ACKACT : std::uint8_t {
            ACKACT_ACK  = 0 << Bit::ACKACT, ///< Send ACK.
            ACKACT_NACK = 1 << Bit::ACKACT, ///< Send NACK.
        };

        /**
         * \brief SCMD.
         */
        enum SCMD : std::uint8_t {
            SCMD_NOACT     = 0x0 << Bit::SCMD, ///< No action.
            SCMD_COMPTRANS = 0x2 << Bit::SCMD, ///< See datasheet.
            SCMD_RESPONSE  = 0x3 << Bit::SCMD, ///< See datasheet.
        };

        SCTRLB() = delete;

        SCTRLB( SCTRLB && ) = delete;

        SCTRLB( SCTRLB const & ) = delete;

        ~SCTRLB() = delete;

        auto operator=( SCTRLB && ) = delete;

        auto operator=( SCTRLB const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Client Status (SSTATUS) register.
     *
     * This register has the following fields:
     * - Address or Stop (AP)
     * - Read/Write Direction (DIR)
     * - Bus Error (BUSERR)
     * - Collision (COLL)
     * - Received Acknowledge (RXACK)
     * - Clock Hold (CLKHOLD)
     * - Address or Stop Interrupt Flag (APIF)
     * - Data Interrupt Flag (DIF)
     */
    class SSTATUS : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto AP      = std::uint_fast8_t{ 1 }; ///< AP.
            static constexpr auto DIR     = std::uint_fast8_t{ 1 }; ///< DIR.
            static constexpr auto BUSERR  = std::uint_fast8_t{ 1 }; ///< BUSERR.
            static constexpr auto COLL    = std::uint_fast8_t{ 1 }; ///< COLL.
            static constexpr auto RXACK   = std::uint_fast8_t{ 1 }; ///< RXACK.
            static constexpr auto CLKHOLD = std::uint_fast8_t{ 1 }; ///< CLKHOLD.
            static constexpr auto APIF    = std::uint_fast8_t{ 1 }; ///< APIF.
            static constexpr auto DIF     = std::uint_fast8_t{ 1 }; ///< DIF.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto AP     = std::uint_fast8_t{};                ///< AP.
            static constexpr auto DIR    = std::uint_fast8_t{ AP + Size::AP }; ///< DIR.
            static constexpr auto BUSERR = std::uint_fast8_t{ DIR + Size::DIR }; ///< BUSERR.
            static constexpr auto COLL = std::uint_fast8_t{ BUSERR + Size::BUSERR }; ///< COLL.
            static constexpr auto RXACK = std::uint_fast8_t{ COLL + Size::COLL }; ///< RXACK.
            static constexpr auto CLKHOLD = std::uint_fast8_t{ RXACK + Size::RXACK }; ///< CLKHOLD.
            static constexpr auto APIF = std::uint_fast8_t{ CLKHOLD + Size::CLKHOLD }; ///< APIF.
            static constexpr auto DIF = std::uint_fast8_t{ APIF + Size::APIF }; ///< DIF.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto AP = mask<std::uint8_t>( Size::AP, Bit::AP ); ///< AP.
            static constexpr auto DIR = mask<std::uint8_t>( Size::DIR, Bit::DIR ); ///< DIR.
            static constexpr auto BUSERR = mask<std::uint8_t>( Size::BUSERR, Bit::BUSERR ); ///< BUSERR.
            static constexpr auto COLL = mask<std::uint8_t>( Size::COLL, Bit::COLL ); ///< COLL.
            static constexpr auto RXACK = mask<std::uint8_t>( Size::RXACK, Bit::RXACK ); ///< RXACK.
            static constexpr auto CLKHOLD = mask<std::uint8_t>( Size::CLKHOLD, Bit::CLKHOLD ); ///< CLKHOLD.
            static constexpr auto APIF = mask<std::uint8_t>( Size::APIF, Bit::APIF ); ///< APIF.
            static constexpr auto DIF = mask<std::uint8_t>( Size::DIF, Bit::DIF ); ///< DIF.
        };

        /**
         * \brief AP.
         */
        enum AP : std::uint8_t {
            AP_STOP = 0 << Bit::AP, ///< A stop condition generated the interrupt on the APIF flag.
            AP_ADR = 1 << Bit::AP, ///< Address detection generated the interrupt on the APIF flag.
        };

        SSTATUS() = delete;

        SSTATUS( SSTATUS && ) = delete;

        SSTATUS( SSTATUS const & ) = delete;

        ~SSTATUS() = delete;

        auto operator=( SSTATUS && ) = delete;

        auto operator=( SSTATUS const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Client Address Mask (SADDRMASK) register.
     *
     * This register has the following fields:
     * - Address Mask Enable (ADDREN)
     * - Address Mask (ADDRMASK)
     */
    class SADDRMASK : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto ADDREN   = std::uint_fast8_t{ 1 }; ///< ADDREN.
            static constexpr auto ADDRMASK = std::uint_fast8_t{ 7 }; ///< ADDRMASK.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto ADDREN = std::uint_fast8_t{}; ///< ADDREN.
            static constexpr auto ADDRMASK = std::uint_fast8_t{ ADDREN + Size::ADDREN }; ///< ADDRMASK.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto ADDREN = mask<std::uint8_t>( Size::ADDREN, Bit::ADDREN ); ///< ADDREN.
            static constexpr auto ADDRMASK = mask<std::uint8_t>( Size::ADDRMASK, Bit::ADDRMASK ); ///< ADDRMASK.
        };

        SADDRMASK() = delete;

        SADDRMASK( SADDRMASK && ) = delete;

        SADDRMASK( SADDRMASK const & ) = delete;

        ~SADDRMASK() = delete;

        auto operator=( SADDRMASK && ) = delete;

        auto operator=( SADDRMASK const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief CTRLA.
     */
    CTRLA ctrla;

    /**
     * \brief DUALCTRL.
     */
    DUALCTRL dualctrl;

    /**
     * \brief DBGCTRL.
     */
    DBGCTRL dbgctrl;

    /**
     * \brief MCTRLA.
     */
    MCTRLA mctrla;

    /**
     * \brief MCTRLB.
     */
    MCTRLB mctrlb;

    /**
     * \brief MSTATUS.
     */
    MSTATUS mstatus;

    /**
     * \brief Host Baud Rate (MBAUD) register.
     */
    Register<std::uint8_t> mbaud;

    /**
     * \brief Host Address (MADDR) register.
     */
    Register<std::uint8_t> maddr;

    /**
     * \brief Host Data (MDATA) register.
     */
    Register<std::uint8_t> mdata;

    /**
     * \brief SCTRLA.
     */
    SCTRLA sctrla;

    /**
     * \brief SCTRLB.
     */
    SCTRLB sctrlb;

    /**
     * \brief SSTATUS.
     */
    SSTATUS sstatus;

    /**
     * \brief Client Address (SADDR) register.
     */
    Register<std::uint8_t> saddr;

    /**
     * \brief Client Data (SDATA) register.
     */
    Register<std::uint8_t> sdata;

    /**
     * \brief SADDRMASK.
     */
    SADDRMASK saddrmask;

    TWI() = delete;

    TWI( TWI && ) = delete;

    TWI( TWI const & ) = delete;

    ~TWI() = delete;

    auto operator=( TWI && ) = delete;

    auto operator=( TWI const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_TWI_H
