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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::TWI interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_TWI_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_TWI_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr0/peripheral/instance.h"
#include "picolibrary/microchip/megaavr0/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series Two-Wire Interface (TWI) peripheral.
 */
class TWI {
  public:
    enum class SDA_Hold_Time : std::uint8_t;

    enum class Fast_Mode_Plus : std::uint8_t;

    enum class Quick_Command_Mode : std::uint8_t;

    enum class Smart_Mode : std::uint8_t;

    enum class Timeout : std::uint8_t;

    enum class Bus_State : std::uint8_t;

    enum class Command : std::uint8_t;

    enum class Response : std::uint8_t;

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
            static constexpr auto RESERVED0 = std::uint_fast8_t{ 1 }; ///< Reserved.
            static constexpr auto FMPEN     = std::uint_fast8_t{ 1 }; ///< FMPEN.
            static constexpr auto SDAHOLD   = std::uint_fast8_t{ 2 }; ///< SDAHOLD.
            static constexpr auto SDASETUP  = std::uint_fast8_t{ 1 }; ///< SDASETUP.
            static constexpr auto RESERVED5 = std::uint_fast8_t{ 3 }; ///< Reserved.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto RESERVED0 = std::uint_fast8_t{}; ///< Reserved.
            static constexpr auto FMPEN = std::uint_fast8_t{ RESERVED0 + Size::RESERVED0 }; ///< FMPEN.
            static constexpr auto SDAHOLD = std::uint_fast8_t{ FMPEN + Size::FMPEN }; ///< SDAHOLD.
            static constexpr auto SDASETUP = std::uint_fast8_t{ SDAHOLD + Size::SDAHOLD }; ///< SDASETUP.
            static constexpr auto RESERVED5 = std::uint_fast8_t{ SDASETUP + Size::SDASETUP }; ///< Reserved.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto RESERVED0 = mask<std::uint8_t>( Size::RESERVED0, Bit::RESERVED0 ); ///< Reserved.
            static constexpr auto FMPEN = mask<std::uint8_t>( Size::FMPEN, Bit::FMPEN ); ///< FMPEN.
            static constexpr auto SDAHOLD = mask<std::uint8_t>( Size::SDAHOLD, Bit::SDAHOLD ); ///< SDAHOLD.
            static constexpr auto SDASETUP = mask<std::uint8_t>( Size::SDASETUP, Bit::SDASETUP ); ///< SDASETUP.
            static constexpr auto RESERVED5 = mask<std::uint8_t>( Size::RESERVED5, Bit::RESERVED5 ); ///< Reserved.
        };

        CTRLA() = delete;

        CTRLA( CTRLA && ) = delete;

        CTRLA( CTRLA const & ) = delete;

        ~CTRLA() = delete;

        auto operator=( CTRLA && ) = delete;

        auto operator=( CTRLA const & ) = delete;

        using Register<std::uint8_t>::operator=;

        /**
         * \brief Configure the TWI for use as an I2C controller.
         *
         * \param[in] sda_hold_time The desired SDA hold time configuration.
         * \param[in] fast_mode_plus The desired fast mode plus configuration.
         */
        void configure_as_i2c_controller( SDA_Hold_Time sda_hold_time, Fast_Mode_Plus fast_mode_plus ) noexcept
        {
            *this = static_cast<std::uint8_t>( sda_hold_time )
                    | static_cast<std::uint8_t>( fast_mode_plus );
        }
    };

    /**
     * \brief Dual Mode Control Configuration (DUALCTRL) register.
     *
     * This register has the following fields:
     * - Dual control Enable (ENABLE)
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
            static constexpr auto RESERVED4 = std::uint_fast8_t{ 4 }; ///< Reserved.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto ENABLE = std::uint_fast8_t{}; ///< ENABLE.
            static constexpr auto FMPEN = std::uint_fast8_t{ ENABLE + Size::ENABLE }; ///< FMPEN.
            static constexpr auto SDAHOLD = std::uint_fast8_t{ FMPEN + Size::FMPEN }; ///< SDAHOLD.
            static constexpr auto RESERVED4 = std::uint_fast8_t{ SDAHOLD + Size::SDAHOLD }; ///< Reserved.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto ENABLE = mask<std::uint8_t>( Size::ENABLE, Bit::ENABLE ); ///< ENABLE.
            static constexpr auto FMPEN = mask<std::uint8_t>( Size::FMPEN, Bit::FMPEN ); ///< FMPEN.
            static constexpr auto SDAHOLD = mask<std::uint8_t>( Size::SDAHOLD, Bit::SDAHOLD ); ///< SDAHOLD.
            static constexpr auto RESERVED4 = mask<std::uint8_t>( Size::RESERVED4, Bit::RESERVED4 ); ///< Reserved.
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
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 7 }; ///< Reserved.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto DBGRUN = std::uint_fast8_t{}; ///< DBGRUN.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ DBGRUN + Size::DBGRUN }; ///< Reserved.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto DBGRUN = mask<std::uint8_t>( Size::DBGRUN, Bit::DBGRUN ); ///< DBGRUN.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< Reserved.
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
     * \brief Host Control A (HCTRLA) register.
     *
     * This register has the following fields:
     * - Enable TWI Host (ENABLE)
     * - Smart Mode Enable (SMEN)
     * - Inactive Bus Time-Out (TIMEOUT)
     * - Quick Command Enable (QCEN)
     * - Write Interrupt Enable (WIEN)
     * - Read Interrupt Enable (RIEN)
     */
    class HCTRLA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto ENABLE    = std::uint_fast8_t{ 1 }; ///< ENABLE.
            static constexpr auto SMEN      = std::uint_fast8_t{ 1 }; ///< SMEN.
            static constexpr auto TIMEOUT   = std::uint_fast8_t{ 2 }; ///< TIMEOUT.
            static constexpr auto QCEN      = std::uint_fast8_t{ 1 }; ///< QCEN.
            static constexpr auto RESERVED5 = std::uint_fast8_t{ 1 }; ///< Reserved.
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
            static constexpr auto RESERVED5 = std::uint_fast8_t{ QCEN + Size::QCEN }; ///< Reserved.
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
            static constexpr auto RESERVED5 = mask<std::uint8_t>( Size::RESERVED5, Bit::RESERVED5 ); ///< Reserved.
            static constexpr auto WIEN = mask<std::uint8_t>( Size::WIEN, Bit::WIEN ); ///< WIEN.
            static constexpr auto RIEN = mask<std::uint8_t>( Size::RIEN, Bit::RIEN ); ///< RIEN.
        };

        HCTRLA() = delete;

        HCTRLA( HCTRLA && ) = delete;

        HCTRLA( HCTRLA const & ) = delete;

        ~HCTRLA() = delete;

        auto operator=( HCTRLA && ) = delete;

        auto operator=( HCTRLA const & ) = delete;

        using Register<std::uint8_t>::operator=;

        /**
         * \brief Configure the TWI for use as an I2C controller.
         *
         * \param[in] timeout The desired inactive bus timeout configuration.
         */
        void configure_as_i2c_controller( Timeout timeout ) noexcept;

        /**
         * \brief Enable the TWI.
         */
        void enable() noexcept
        {
            *this |= Mask::ENABLE;
        }

        /**
         * \brief Disable the TWI.
         */
        void disable() noexcept
        {
            *this &= ~Mask::ENABLE;
        }
    };

    /**
     * \brief Host Control B (HCTRLB) register.
     *
     * This register has the following fields:
     * - Host Command (HCMD)
     * - Acknowledge Action (ACKACT)
     * - Flush (FLUSH)
     */
    class HCTRLB : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto HCMD      = std::uint_fast8_t{ 2 }; ///< HCMD.
            static constexpr auto ACKACT    = std::uint_fast8_t{ 1 }; ///< ACKACT.
            static constexpr auto FLUSH     = std::uint_fast8_t{ 1 }; ///< FLUSH.
            static constexpr auto RESERVED4 = std::uint_fast8_t{ 4 }; ///< Reserved.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto HCMD = std::uint_fast8_t{}; ///< HCMD.
            static constexpr auto ACKACT = std::uint_fast8_t{ HCMD + Size::HCMD }; ///< ACKACT.
            static constexpr auto FLUSH = std::uint_fast8_t{ ACKACT + Size::ACKACT }; ///< FLUSH.
            static constexpr auto RESERVED4 = std::uint_fast8_t{ FLUSH + Size::FLUSH }; ///< Reserved.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto HCMD = mask<std::uint8_t>( Size::HCMD, Bit::HCMD ); ///< HCMD.
            static constexpr auto ACKACT = mask<std::uint8_t>( Size::ACKACT, Bit::ACKACT ); ///< ACKACT.
            static constexpr auto FLUSH = mask<std::uint8_t>( Size::FLUSH, Bit::FLUSH ); ///< FLUSH.
            static constexpr auto RESERVED4 = mask<std::uint8_t>( Size::RESERVED4, Bit::RESERVED4 ); ///< Reserved.
        };

        HCTRLB() = delete;

        HCTRLB( HCTRLB && ) = delete;

        HCTRLB( HCTRLB const & ) = delete;

        ~HCTRLB() = delete;

        auto operator=( HCTRLB && ) = delete;

        auto operator=( HCTRLB const & ) = delete;

        using Register<std::uint8_t>::operator=;

        /**
         * \brief Transmit a stop condition.
         */
        void stop() noexcept;

        /**
         * \brief Configure the response to be transmitted when data is received from a
         *         device.
         *
         * \param[in] response The response to be transmitted when data is received from a
         *            device.
         */
        void configure_read_response( Response response ) noexcept
        {
            *this = static_cast<std::uint8_t>( response );
        }
    };

    /**
     * \brief Host Status (HSTATUS) register.
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
    class HSTATUS : public Register<std::uint8_t> {
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

        HSTATUS() = delete;

        HSTATUS( HSTATUS && ) = delete;

        HSTATUS( HSTATUS const & ) = delete;

        ~HSTATUS() = delete;

        auto operator=( HSTATUS && ) = delete;

        auto operator=( HSTATUS const & ) = delete;

        using Register<std::uint8_t>::operator=;

        /**
         * \brief Get the bus state.
         *
         * \return The bus state.
         */
        auto bus_state() const noexcept
        {
            return static_cast<Bus_State>( *this & Mask::BUSSTATE );
        }

        /**
         * \brief Check if device addressing is complete.
         *
         * \return true if device addressing is complete.
         * \return false if device addressing is not complete.
         */
        auto addressing_complete() const noexcept -> bool
        {
            return *this & ( Mask::WIF | Mask::RIF );
        }

        /**
         * \brief Check if data received from a device is available.
         *
         * \return true if data received from a device is available.
         * \return false if data received from a device is not available.
         */
        auto data_available() const noexcept -> bool
        {
            return *this & Mask::RIF;
        }

        /**
         * \brief Check if data transmission is complete.
         *
         * \return true if data transmission is complete.
         * \return false if data transmission is not complete.
         */
        auto transmission_complete() const noexcept -> bool
        {
            return *this & Mask::WIF;
        }

        /**
         * \brief Check if a bus error occurred.
         *
         * \return true if a bus error occurred.
         * \return false if a bus error has not occurred.
         */
        auto bus_error() const noexcept -> bool
        {
            return *this & Mask::BUSERR;
        }

        /**
         * \brief Check if arbitration was lost.
         *
         * \return true if arbitration was lost.
         * \return false if arbitration was not lost.
         */
        auto arbitration_lost() const noexcept -> bool
        {
            return *this & Mask::ARBLOST;
        }

        /**
         * \brief Check if a NACK was received.
         *
         * \return true if a NACK was received.
         * \return false if a NACK was not received.
         */
        auto nack_received() const noexcept -> bool
        {
            return *this & Mask::RXACK;
        }

        /**
         * \brief Force the bus state to idle.
         */
        void force_bus_state_to_idle() noexcept;
    };

    /**
     * \brief Client Control A (CCTRLA) register.
     *
     * This register has the following fields:
     * - Enable TWI Client (ENABLE)
     * - Smart Mode Enable (SMEN)
     * - Permissive Mode Enable (PMEN)
     * - Stop Interript Enable (PIEN)
     * - Address or Stop Interrupt Enable (APIEN)
     * - Data Interrupt Enable (DIEN)
     */
    class CCTRLA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto ENABLE    = std::uint_fast8_t{ 1 }; ///< ENABLE.
            static constexpr auto SMEN      = std::uint_fast8_t{ 1 }; ///< SMEN.
            static constexpr auto PMEN      = std::uint_fast8_t{ 1 }; ///< PMEN.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ 2 }; ///< Reserved.
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
            static constexpr auto RESERVED3 = std::uint_fast8_t{ PMEN + Size::PMEN }; ///< Reserved.
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
            static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< Reserved.
            static constexpr auto PIEN = mask<std::uint8_t>( Size::PIEN, Bit::PIEN ); ///< PIEN.
            static constexpr auto APIEN = mask<std::uint8_t>( Size::APIEN, Bit::APIEN ); ///< APIEN.
            static constexpr auto DIEN = mask<std::uint8_t>( Size::DIEN, Bit::DIEN ); ///< DIEN.
        };

        CCTRLA() = delete;

        CCTRLA( CCTRLA && ) = delete;

        CCTRLA( CCTRLA const & ) = delete;

        ~CCTRLA() = delete;

        auto operator=( CCTRLA && ) = delete;

        auto operator=( CCTRLA const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Host Control B (CCTRLB) register.
     *
     * This register has the following fields:
     * - Client Command (CCMD)
     * - Acknowledge Action (ACKACT)
     */
    class CCTRLB : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto CCMD      = std::uint_fast8_t{ 2 }; ///< CCMD.
            static constexpr auto ACKACT    = std::uint_fast8_t{ 1 }; ///< ACKACT.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ 5 }; ///< Reserved.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto CCMD = std::uint_fast8_t{}; ///< CCMD.
            static constexpr auto ACKACT = std::uint_fast8_t{ CCMD + Size::CCMD }; ///< ACKACT.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ ACKACT + Size::ACKACT }; ///< Reserved.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto CCMD = mask<std::uint8_t>( Size::CCMD, Bit::CCMD ); ///< CCMD.
            static constexpr auto ACKACT = mask<std::uint8_t>( Size::ACKACT, Bit::ACKACT ); ///< ACKACT.
            static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< Reserved.
        };

        CCTRLB() = delete;

        CCTRLB( CCTRLB && ) = delete;

        CCTRLB( CCTRLB const & ) = delete;

        ~CCTRLB() = delete;

        auto operator=( CCTRLB && ) = delete;

        auto operator=( CCTRLB const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Client Status (CSTATUS) register.
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
    class CSTATUS : public Register<std::uint8_t> {
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

        CSTATUS() = delete;

        CSTATUS( CSTATUS && ) = delete;

        CSTATUS( CSTATUS const & ) = delete;

        ~CSTATUS() = delete;

        auto operator=( CSTATUS && ) = delete;

        auto operator=( CSTATUS const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Client Status (CADDRMASK) register.
     *
     * This register has the following fields:
     * - Address Mask Enable (ADDREN)
     * - Address Mask (ADDRMASK)
     */
    class CADDRMASK : public Register<std::uint8_t> {
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

        CADDRMASK() = delete;

        CADDRMASK( CADDRMASK && ) = delete;

        CADDRMASK( CADDRMASK const & ) = delete;

        ~CADDRMASK() = delete;

        auto operator=( CADDRMASK && ) = delete;

        auto operator=( CADDRMASK const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief SDA hold time configuration.
     */
    enum class SDA_Hold_Time : std::uint8_t {
        OFF     = 0x0 << CTRLA::Bit::SDAHOLD, ///< Off.
        _50_NS  = 0x1 << CTRLA::Bit::SDAHOLD, ///< 50 ns (short hold time).
        _300_NS = 0x2 << CTRLA::Bit::SDAHOLD, ///< 300 ns (meets SMBus 2.0 specifications under typical conditions).
        _500_NS = 0x3 << CTRLA::Bit::SDAHOLD, ///< 500 ns (meets SMBus 2.0 specifications across all corners).
    };

    /**
     * \brief Fast mode plus configuration.
     */
    enum class Fast_Mode_Plus : std::uint8_t {
        DISABLED = 0b0 << CTRLA::Bit::FMPEN, ///< Disabled.
        ENABLED  = 0b1 << CTRLA::Bit::FMPEN, ///< Enabled.
    };

    /**
     * \brief Quick command mode configuration.
     */
    enum class Quick_Command_Mode : std::uint8_t {
        DISABLED = 0b0 << HCTRLA::Bit::QCEN, ///< Disabled.
        ENABLED  = 0b1 << HCTRLA::Bit::QCEN, ///< Enabled.
    };

    /**
     * \brief Smart mode configuration.
     */
    enum class Smart_Mode : std::uint8_t {
        DISABLED = 0b0 << HCTRLA::Bit::SMEN, ///< Disabled.
        ENABLED  = 0b1 << HCTRLA::Bit::SMEN, ///< Enabled.
    };

    /**
     * \brief Inactive bus timeout configuration.
     */
    enum class Timeout : std::uint8_t {
        DISABLED = 0x0 << HCTRLA::Bit::TIMEOUT, ///< Disabled (I2C).
        _50_US   = 0x1 << HCTRLA::Bit::TIMEOUT, ///< 50 us (SMBus, assumes clock frequency is set to 100 kHz).
        _100_US  = 0x2 << HCTRLA::Bit::TIMEOUT, ///< 100 us (assumes clock frequency is set to 100 kHz).
        _200_US  = 0x3 << HCTRLA::Bit::TIMEOUT, ///< 200 us (assumes clock frequency is set to 100 kHz).
    };

    /**
     * \brief Bus state.
     */
    enum class Bus_State : std::uint8_t {
        UNKNOWN = 0x0 << HSTATUS::Bit::BUSSTATE, ///< Unknown.
        IDLE    = 0x1 << HSTATUS::Bit::BUSSTATE, ///< Idle.
        OWNER   = 0x2 << HSTATUS::Bit::BUSSTATE, ///< Owner.
        BUSY    = 0x3 << HSTATUS::Bit::BUSSTATE, ///< Busy.
    };

    /**
     * \brief Command.
     */
    enum class Command : std::uint8_t {
        NONE = 0x0 << HCTRLB::Bit::HCMD, ///< None.
        STOP = 0x3 << HCTRLB::Bit::HCMD, ///< Transmit a stop condition.
    };

    /**
     * \brief Response.
     */
    enum class Response : std::uint8_t {
        ACK  = 0b0 << HCTRLB::Bit::ACKACT, ///< ACK.
        NACK = 0b1 << HCTRLB::Bit::ACKACT, ///< NACK.
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
     * \brief HCTRLA.
     */
    HCTRLA hctrla;

    /**
     * \brief HCTRLB.
     */
    HCTRLB hctrlb;

    /**
     * \brief HSTATUS.
     */
    HSTATUS hstatus;

    /**
     * \brief Host Baud Rate (HBAUD) register.
     */
    Register<std::uint8_t> hbaud;

    /**
     * \brief Host Address (HADDR) register.
     */
    Register<std::uint8_t> haddr;

    /**
     * \brief Host Data (HDATA) register.
     */
    Register<std::uint8_t> hdata;

    /**
     * \brief CCTRLA.
     */
    CCTRLA cctrla;

    /**
     * \brief CCTRLB.
     */
    CCTRLB cctrlb;

    /**
     * \brief CSTATUS.
     */
    CSTATUS cstatus;

    /**
     * \brief Client Address (CADDR) register.
     */
    Register<std::uint8_t> caddr;

    /**
     * \brief Client Data (CDATA) register.
     */
    Register<std::uint8_t> cdata;

    /**
     * \brief CADDRMASK.
     */
    CADDRMASK caddrmask;

    TWI() = delete;

    TWI( TWI && ) = delete;

    TWI( TWI const & ) = delete;

    ~TWI() = delete;

    auto operator=( TWI && ) = delete;

    auto operator=( TWI const & ) = delete;

    /**
     * \brief Configure the TWI for use as an I2C controller.
     *
     * \param[in] sda_hold_time The desired SDA hold time configuration.
     * \param[in] fast_mode_plus The desired fast mode plus configuration.
     * \param[in] clock_scaling_factor The desired clock scaling factor.
     * \param[in] timeout The desired inactive bus timeout configuration.
     */
    void configure_as_i2c_controller(
        SDA_Hold_Time  sda_hold_time,
        Fast_Mode_Plus fast_mode_plus,
        std::uint8_t   clock_scaling_factor,
        Timeout        timeout ) noexcept
    {
        ctrla.configure_as_i2c_controller( sda_hold_time, fast_mode_plus );
        hbaud = clock_scaling_factor;
        hctrla.configure_as_i2c_controller( timeout );
    }

    /**
     * \brief Enable the TWI.
     */
    void enable() noexcept
    {
        hctrla.enable();
        hstatus.force_bus_state_to_idle();
    }

    /**
     * \brief Disable the TWI.
     */
    void disable() noexcept
    {
        hctrla.disable();
    }

    /**
     * \brief Transmit a stop condition.
     */
    void stop() noexcept
    {
        hctrlb.stop();
    }

    /**
     * \brief Get the bus state.
     *
     * \return The bus state.
     */
    auto bus_state() const noexcept
    {
        return hstatus.bus_state();
    }

    /**
     * \brief Check if a bus error occurred.
     *
     * \return true if a bus error occurred.
     * \return false if a bus error has not occurred.
     */
    auto bus_error() const noexcept
    {
        return hstatus.bus_error();
    }

    /**
     * \brief Check if arbitration was lost.
     *
     * \return true if arbitration was lost.
     * \return false if arbitration was not lost.
     */
    auto arbitration_lost() const noexcept
    {
        return hstatus.arbitration_lost();
    }

    /**
     * \brief Check if a NACK was received.
     *
     * \return true if a NACK was received.
     * \return false if a NACK was not received.
     */
    auto nack_received() const noexcept
    {
        return hstatus.nack_received();
    }

    /**
     * \brief Address a device.
     *
     * \param[in] device_address_and_operation The address of the device to be addressed
     *            and the operation to be performed.
     */
    void address( std::uint8_t device_address_and_operation ) noexcept
    {
        haddr = device_address_and_operation;
    }

    /**
     * \brief Check if device addressing is complete.
     *
     * \return true if device addressing is complete.
     * \return false if device addressing is not complete.
     */
    auto addressing_complete() const noexcept
    {
        return hstatus.addressing_complete();
    }

    /**
     * \brief Configure the response to be transmitted when data is received from a
     *        device.
     *
     * \param[in] response The response to be transmitted when data is received from a
     *            device.
     */
    void configure_read_response( Response response ) noexcept
    {
        hctrlb.configure_read_response( response );
    }

    /**
     * \brief Check if data received from a device is available.
     *
     * \return true if data received from a device is available.
     * \return false if data received from a device is not available.
     */
    auto data_available() const noexcept
    {
        return hstatus.data_available();
    }

    /**
     * \brief Read data received from a device.
     *
     * \return The data received from a device.
     */
    auto receive() noexcept -> std::uint8_t
    {
        return hdata;
    }

    /**
     * \brief Transmit data to a device.
     *
     * \param[in] data The data to transmit to the device.
     */
    void transmit( std::uint8_t data ) noexcept
    {
        hdata = data;
    }

    /**
     * \brief Check if data transmission is complete.
     *
     * \return true if data transmission is complete.
     * \return false if data transmission is not complete.
     */
    auto transmission_complete() const noexcept
    {
        return hstatus.transmission_complete();
    }
};

inline void TWI::HCTRLA::configure_as_i2c_controller( Timeout timeout ) noexcept
{
    *this = static_cast<std::uint8_t>( Quick_Command_Mode::DISABLED )
            | static_cast<std::uint8_t>( Smart_Mode::ENABLED )
            | static_cast<std::uint8_t>( timeout );
}

inline void TWI::HCTRLB::stop() noexcept
{
    *this |= static_cast<std::uint8_t>( Command::STOP );
}

inline void TWI::HSTATUS::force_bus_state_to_idle() noexcept
{
    *this = static_cast<std::uint8_t>( Bus_State::IDLE );
}

/**
 * \brief Microchip megaAVR 0-series Two-Wire Interface (TWI) peripheral instance.
 *
 * \tparam INSTANCE_ADDRESS The address of the TWI instance.
 */
template<std::uintptr_t INSTANCE_ADDRESS>
using TWI_Instance = Instance<TWI, INSTANCE_ADDRESS>;

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_TWI_H
