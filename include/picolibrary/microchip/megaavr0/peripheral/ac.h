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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::AC interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_AC_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_AC_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series Analog Comparator (AC) peripheral.
 */
class AC {
  public:
    /**
     * \brief Control A (CTRLA) register.
     *
     * This register has the following fields:
     * - Enable AC (ENABLE)
     * - Hysteresis Mode Select (HYSMODE)
     * - Low-Power Mode (LPMODE)
     * - Interrupt Modes (INTMODE)
     * - Analog Comparator Output Pad Enable (OUTEN)
     * - Run in Standby Mode (RUNSTDBY)
     */
    class CTRLA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto ENABLE   = std::uint_fast8_t{ 1 }; ///< ENABLE.
            static constexpr auto HYSMODE  = std::uint_fast8_t{ 2 }; ///< HYSMODE.
            static constexpr auto LPMODE   = std::uint_fast8_t{ 1 }; ///< LPMODE.
            static constexpr auto INTMODE  = std::uint_fast8_t{ 2 }; ///< INTMODE.
            static constexpr auto OUTEN    = std::uint_fast8_t{ 1 }; ///< OUTEN.
            static constexpr auto RUNSTDBY = std::uint_fast8_t{ 1 }; ///< RUNSTDBY.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto ENABLE = std::uint_fast8_t{}; ///< ENABLE.
            static constexpr auto HYSMODE = std::uint_fast8_t{ ENABLE + Size::ENABLE }; ///< HYSMODE.
            static constexpr auto LPMODE = std::uint_fast8_t{ HYSMODE + Size::HYSMODE }; ///< LPMODE.
            static constexpr auto INTMODE = std::uint_fast8_t{ LPMODE + Size::LPMODE }; ///< INTMODE.
            static constexpr auto OUTEN = std::uint_fast8_t{ INTMODE + Size::INTMODE }; ///< OUTEN.
            static constexpr auto RUNSTDBY = std::uint_fast8_t{ OUTEN + Size::OUTEN }; ///< RUNSTDBY.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto ENABLE = mask<std::uint8_t>( Size::ENABLE, Bit::ENABLE ); ///< ENABLE.
            static constexpr auto HYSMODE = mask<std::uint8_t>( Size::HYSMODE, Bit::HYSMODE ); ///< HYSMODE.
            static constexpr auto LPMODE = mask<std::uint8_t>( Size::LPMODE, Bit::LPMODE ); ///< LPMODE.
            static constexpr auto INTMODE = mask<std::uint8_t>( Size::INTMODE, Bit::INTMODE ); ///< INTMODE.
            static constexpr auto OUTEN = mask<std::uint8_t>( Size::OUTEN, Bit::OUTEN ); ///< OUTEN.
            static constexpr auto RUNSTDBY = mask<std::uint8_t>( Size::RUNSTDBY, Bit::RUNSTDBY ); ///< RUNSTDBY.
        };

        /**
         * \brief HYSMODE.
         */
        enum HYSMODE : std::uint8_t {
            HYSMODE_NONE   = 0x0 << Bit::HYSMODE, ///< No hysteresis.
            HYSMODE_SMALL  = 0x1 << Bit::HYSMODE, ///< Small hysteresis.
            HYSMODE_MEDIUM = 0x2 << Bit::HYSMODE, ///< Medium hysteresis.
            HYSMODE_LARGE  = 0x3 << Bit::HYSMODE, ///< Large hysteresis.
        };

        /**
         * \brief INTMODE.
         */
        enum INTMODE : std::uint8_t {
            INTMODE_BOTHEDGE = 0x0 << Bit::INTMODE, ///< Both negative and positive edge.
            INTMODE_NEGEDGE  = 0x2 << Bit::INTMODE, ///< Negative edge.
            INTMODE_POSEDGE  = 0x3 << Bit::INTMODE, ///< Positive edge.
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
     * \brief MUX Control A (MUXCTRLA) register.
     *
     * This register has the following fields:
     * - Negative Input Mux Selection (MUXNEG)
     * - Positive Input Mux Selection (MUXPOS)
     * - Invert AC Output (INVERT)
     */
    class MUXCTRLA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto MUXNEG    = std::uint_fast8_t{ 2 }; ///< MUXNEG.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ 1 }; ///< RESERVED2.
            static constexpr auto MUXPOS    = std::uint_fast8_t{ 2 }; ///< MUXPOS.
            static constexpr auto RESERVED5 = std::uint_fast8_t{ 2 }; ///< RESERVED5.
            static constexpr auto INVERT    = std::uint_fast8_t{ 1 }; ///< INVERT.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto MUXNEG = std::uint_fast8_t{}; ///< MUXNEG.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ MUXNEG + Size::MUXNEG }; ///< RESERVED2.
            static constexpr auto MUXPOS = std::uint_fast8_t{ RESERVED2 + Size::RESERVED2 }; ///< MUXPOS.
            static constexpr auto RESERVED5 = std::uint_fast8_t{ MUXPOS + Size::MUXPOS }; ///< RESERVED5.
            static constexpr auto INVERT = std::uint_fast8_t{ RESERVED5 + Size::RESERVED5 }; ///< INVERT.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto MUXNEG = mask<std::uint8_t>( Size::MUXNEG, Bit::MUXNEG ); ///< MUXNEG.
            static constexpr auto RESERVED2 = mask<std::uint8_t>( Size::RESERVED2, Bit::RESERVED2 ); ///< RESERVED2.
            static constexpr auto MUXPOS = mask<std::uint8_t>( Size::MUXPOS, Bit::MUXPOS ); ///< MUXPOS.
            static constexpr auto RESERVED5 = mask<std::uint8_t>( Size::RESERVED5, Bit::RESERVED5 ); ///< RESERVED5.
            static constexpr auto INVERT = mask<std::uint8_t>( Size::INVERT, Bit::INVERT ); ///< INVERT.
        };

        /**
         * \brief MUXNEG.
         */
        enum MUXNEG : std::uint8_t {
            MUXNEG_AINN0  = 0x0 << Bit::MUXNEG, ///< Negative pin 0.
            MUXNEG_AINN1  = 0x1 << Bit::MUXNEG, ///< Negative pin 1.
            MUXNEG_AINN2  = 0x2 << Bit::MUXNEG, ///< Negative pin 2.
            MUXNEG_DACREF = 0x3 << Bit::MUXNEG, ///< Internal DAC reference.
        };

        /**
         * \brief MUXPOS.
         */
        enum MUXPOS : std::uint8_t {
            MUXPOS_AINP0 = 0x0 << Bit::MUXPOS, ///< Positive pin 0.
            MUXPOS_AINP1 = 0x1 << Bit::MUXPOS, ///< Positive pin 1.
            MUXPOS_AINP2 = 0x2 << Bit::MUXPOS, ///< Positive pin 2.
            MUXPOS_AINP3 = 0x3 << Bit::MUXPOS, ///< Positive pin 3.
        };

        MUXCTRLA() = delete;

        MUXCTRLA( MUXCTRLA && ) = delete;

        MUXCTRLA( MUXCTRLA const & ) = delete;

        ~MUXCTRLA() = delete;

        auto operator=( MUXCTRLA && ) = delete;

        auto operator=( MUXCTRLA const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Interrupt Control (INTCTRL) register.
     *
     * This register has the following fields:
     * - Analog Comparator Interrupt Enable (CMP)
     */
    class INTCTRL : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto CMP       = std::uint_fast8_t{ 1 }; ///< CMP.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 7 }; ///< RESERVED1.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto CMP = std::uint_fast8_t{}; ///< CMP.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ CMP + Size::CMP }; ///< RESERVED1.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto CMP = mask<std::uint8_t>( Size::CMP, Bit::CMP ); ///< CMP.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
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
     * \brief Status (STATUS) register.
     *
     * This register has the following fields:
     * - Analog Comparator Interrupt Flag (CMP)
     * - Analog Comparator State (STATE)
     */
    class STATUS : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto CMP       = std::uint_fast8_t{ 1 }; ///< CMP.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 3 }; ///< RESERVED1.
            static constexpr auto STATE     = std::uint_fast8_t{ 1 }; ///< STATE.
            static constexpr auto RESERVED5 = std::uint_fast8_t{ 3 }; ///< RESERVED5.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto CMP = std::uint_fast8_t{}; ///< CMP.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ CMP + Size::CMP }; ///< RESERVED1.
            static constexpr auto STATE = std::uint_fast8_t{ RESERVED1 + Size::RESERVED1 }; ///< STATE.
            static constexpr auto RESERVED5 = std::uint_fast8_t{ STATE + Size::STATE }; ///< RESERVED5.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto CMP = mask<std::uint8_t>( Size::CMP, Bit::CMP ); ///< CMP.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
            static constexpr auto STATE = mask<std::uint8_t>( Size::STATE, Bit::STATE ); ///< STATE.
            static constexpr auto RESERVED5 = mask<std::uint8_t>( Size::RESERVED5, Bit::RESERVED5 ); ///< RESERVED5.
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
     * \brief CTRLA.
     */
    CTRLA ctrla;

    /**
     * \brief Reserved registers (offset 0x01-0x01).
     */
    Reserved_Register<std::uint8_t> const reserved_0x01_0x01[ ( 0x01 - 0x01 ) + 1 ];

    /**
     * \brief MUXCTRLA.
     */
    MUXCTRLA muxctrla;

    /**
     * \brief Reserved registers (offset 0x03-0x03).
     */
    Reserved_Register<std::uint8_t> const reserved_0x03_0x03[ ( 0x03 - 0x03 ) + 1 ];

    /**
     * \brief DAC Voltage Reference (DACREF) register.
     */
    Register<std::uint8_t> dacref;

    /**
     * \brief Reserved registers (offset 0x05-0x05).
     */
    Reserved_Register<std::uint8_t> const reserved_0x05_0x05[ ( 0x05 - 0x05 ) + 1 ];

    /**
     * \brief INTCTRL.
     */
    INTCTRL intctrl;

    /**
     * \brief STATUS.
     */
    STATUS status;

    AC() = delete;

    AC( AC && ) = delete;

    AC( AC const & ) = delete;

    ~AC() = delete;

    auto operator=( AC && ) = delete;

    auto operator=( AC const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_AC_H
