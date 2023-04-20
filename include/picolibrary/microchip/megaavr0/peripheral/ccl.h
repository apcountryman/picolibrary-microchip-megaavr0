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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::CCL interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_CCL_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_CCL_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr0/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series Configurable Custom Logic (CCL) peripheral.
 */
class CCL {
  public:
    /**
     * \brief Control A (CTRLA) register.
     *
     * This register has the following fields:
     * - Enable (ENABLE)
     * - Run in Standby (RUNSTDBY)
     */
    class CTRLA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto ENABLE    = std::uint_fast8_t{ 1 }; ///< ENABLE.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 5 }; ///< RESERVED1.
            static constexpr auto RUNSTDBY  = std::uint_fast8_t{ 1 }; ///< RUNSTDBY.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ 1 }; ///< RESERVED7.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto ENABLE = std::uint_fast8_t{}; ///< ENABLE.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ ENABLE + Size::ENABLE }; ///< RESERVED1.
            static constexpr auto RUNSTDBY = std::uint_fast8_t{ RESERVED1 + Size::RESERVED1 }; ///< RUNSTDBY.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ RUNSTDBY + Size::RUNSTDBY }; ///< RESERVED7.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto ENABLE = mask<std::uint8_t>( Size::ENABLE, Bit::ENABLE ); ///< ENABLE.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
            static constexpr auto RUNSTDBY = mask<std::uint8_t>( Size::RUNSTDBY, Bit::RUNSTDBY ); ///< RUNSTDBY.
            static constexpr auto RESERVED7 = mask<std::uint8_t>( Size::RESERVED7, Bit::RESERVED7 ); ///< RESERVED7.
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
     * \brief Sequence Control 0 (SEQCTRL0) register.
     *
     * This register has the following fields:
     * - LUT0 and LUT1 Sequencer Selection (SEQSEL0)
     */
    class SEQCTRL0 : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto SEQSEL0   = std::uint_fast8_t{ 4 }; ///< SEQSEL0.
            static constexpr auto RESERVED4 = std::uint_fast8_t{ 4 }; ///< RESERVED4.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto SEQSEL0 = std::uint_fast8_t{}; ///< SEQSEL0.
            static constexpr auto RESERVED4 = std::uint_fast8_t{ SEQSEL0 + Size::SEQSEL0 }; ///< RESERVED4.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto SEQSEL0 = mask<std::uint8_t>( Size::SEQSEL0, Bit::SEQSEL0 ); ///< SEQSEL0.
            static constexpr auto RESERVED4 = mask<std::uint8_t>( Size::RESERVED4, Bit::RESERVED4 ); ///< RESERVED4.
        };

        /**
         * \brief SEQSEL0.
         */
        enum SEQSEL0 : std::uint8_t {
            SEQSEL0_DISABLE = 0x0 << Bit::SEQSEL0, ///< The sequencer is disabled.
            SEQSEL0_DFF     = 0x1 << Bit::SEQSEL0, ///< D flip-flop.
            SEQSEL0_JK      = 0x2 << Bit::SEQSEL0, ///< JK flip-flop.
            SEQSEL0_LATCH   = 0x3 << Bit::SEQSEL0, ///< D latch.
            SEQSEL0_RS      = 0x4 << Bit::SEQSEL0, ///< RS latch.
        };

        SEQCTRL0() = delete;

        SEQCTRL0( SEQCTRL0 && ) = delete;

        SEQCTRL0( SEQCTRL0 const & ) = delete;

        ~SEQCTRL0() = delete;

        auto operator=( SEQCTRL0 && ) = delete;

        auto operator=( SEQCTRL0 const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Sequence Control 1 (SEQCTRL1) register.
     *
     * This register has the following fields:
     * - LUT2 and LUT3 Sequencer Selection (SEQSEL1)
     */
    class SEQCTRL1 : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto SEQSEL1   = std::uint_fast8_t{ 4 }; ///< SEQSEL1.
            static constexpr auto RESERVED4 = std::uint_fast8_t{ 4 }; ///< RESERVED4.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto SEQSEL1 = std::uint_fast8_t{}; ///< SEQSEL1.
            static constexpr auto RESERVED4 = std::uint_fast8_t{ SEQSEL1 + Size::SEQSEL1 }; ///< RESERVED4.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto SEQSEL1 = mask<std::uint8_t>( Size::SEQSEL1, Bit::SEQSEL1 ); ///< SEQSEL1.
            static constexpr auto RESERVED4 = mask<std::uint8_t>( Size::RESERVED4, Bit::RESERVED4 ); ///< RESERVED4.
        };

        /**
         * \brief SEQSEL1.
         */
        enum SEQSEL1 : std::uint8_t {
            SEQSEL1_DISABLE = 0x0 << Bit::SEQSEL1, ///< The sequencer is disabled.
            SEQSEL1_DFF     = 0x1 << Bit::SEQSEL1, ///< D flip-flop.
            SEQSEL1_JK      = 0x2 << Bit::SEQSEL1, ///< JK flip-flop.
            SEQSEL1_LATCH   = 0x3 << Bit::SEQSEL1, ///< D latch.
            SEQSEL1_RS      = 0x4 << Bit::SEQSEL1, ///< RS latch.
        };

        SEQCTRL1() = delete;

        SEQCTRL1( SEQCTRL1 && ) = delete;

        SEQCTRL1( SEQCTRL1 const & ) = delete;

        ~SEQCTRL1() = delete;

        auto operator=( SEQCTRL1 && ) = delete;

        auto operator=( SEQCTRL1 const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Interrupt Control 0 (INTCTRL0) register.
     *
     * This register has the following fields:
     * - LUT0 Interrupt Mode (INTMODE0)
     * - LUT1 Interrupt Mode (INTMODE1)
     * - LUT2 Interrupt Mode (INTMODE2)
     * - LUT3 Interrupt Mode (INTMODE3)
     */
    class INTCTRL0 : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto INTMODE0 = std::uint_fast8_t{ 2 }; ///< INTMODE0.
            static constexpr auto INTMODE1 = std::uint_fast8_t{ 2 }; ///< INTMODE1.
            static constexpr auto INTMODE2 = std::uint_fast8_t{ 2 }; ///< INTMODE2.
            static constexpr auto INTMODE3 = std::uint_fast8_t{ 2 }; ///< INTMODE3.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto INTMODE0 = std::uint_fast8_t{}; ///< INTMODE0.
            static constexpr auto INTMODE1 = std::uint_fast8_t{ INTMODE0 + Size::INTMODE0 }; ///< INTMODE1.
            static constexpr auto INTMODE2 = std::uint_fast8_t{ INTMODE1 + Size::INTMODE1 }; ///< INTMODE2.
            static constexpr auto INTMODE3 = std::uint_fast8_t{ INTMODE2 + Size::INTMODE2 }; ///< INTMODE3.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto INTMODE0 = mask<std::uint8_t>( Size::INTMODE0, Bit::INTMODE0 ); ///< INTMODE0.
            static constexpr auto INTMODE1 = mask<std::uint8_t>( Size::INTMODE1, Bit::INTMODE1 ); ///< INTMODE1.
            static constexpr auto INTMODE2 = mask<std::uint8_t>( Size::INTMODE2, Bit::INTMODE2 ); ///< INTMODE2.
            static constexpr auto INTMODE3 = mask<std::uint8_t>( Size::INTMODE3, Bit::INTMODE3 ); ///< INTMODE3.
        };

        /**
         * \brief INTMODE0.
         */
        enum INTMODE0 : std::uint8_t {
            INTMODE0_INTDISABLE = 0x0 << Bit::INTMODE0, ///< Interrupt disabled.
            INTMODE0_RISING     = 0x1 << Bit::INTMODE0, ///< Sense rising edge.
            INTMODE0_FALLING    = 0x2 << Bit::INTMODE0, ///< Sense falling edge.
            INTMODE0_BOTH       = 0x3 << Bit::INTMODE0, ///< Sense both edges.
        };

        /**
         * \brief INTMODE1.
         */
        enum INTMODE1 : std::uint8_t {
            INTMODE1_INTDISABLE = 0x0 << Bit::INTMODE1, ///< Interrupt disabled.
            INTMODE1_RISING     = 0x1 << Bit::INTMODE1, ///< Sense rising edge.
            INTMODE1_FALLING    = 0x2 << Bit::INTMODE1, ///< Sense falling edge.
            INTMODE1_BOTH       = 0x3 << Bit::INTMODE1, ///< Sense both edges.
        };

        /**
         * \brief INTMODE2.
         */
        enum INTMODE2 : std::uint8_t {
            INTMODE2_INTDISABLE = 0x0 << Bit::INTMODE2, ///< Interrupt disabled.
            INTMODE2_RISING     = 0x1 << Bit::INTMODE2, ///< Sense rising edge.
            INTMODE2_FALLING    = 0x2 << Bit::INTMODE2, ///< Sense falling edge.
            INTMODE2_BOTH       = 0x3 << Bit::INTMODE2, ///< Sense both edges.
        };

        /**
         * \brief INTMODE3.
         */
        enum INTMODE3 : std::uint8_t {
            INTMODE3_INTDISABLE = 0x0 << Bit::INTMODE3, ///< Interrupt disabled.
            INTMODE3_RISING     = 0x1 << Bit::INTMODE3, ///< Sense rising edge.
            INTMODE3_FALLING    = 0x2 << Bit::INTMODE3, ///< Sense falling edge.
            INTMODE3_BOTH       = 0x3 << Bit::INTMODE3, ///< Sense both edges.
        };

        INTCTRL0() = delete;

        INTCTRL0( INTCTRL0 && ) = delete;

        INTCTRL0( INTCTRL0 const & ) = delete;

        ~INTCTRL0() = delete;

        auto operator=( INTCTRL0 && ) = delete;

        auto operator=( INTCTRL0 const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Interrupt Flag (INTFLAGS) register.
     *
     * This register has the following fields:
     * - LUT0 Interrupt Flag (INT0)
     * - LUT1 Interrupt Flag (INT1)
     * - LUT2 Interrupt Flag (INT2)
     * - LUT3 Interrupt Flag (INT3)
     * - (RESERVED4)
     */
    class INTFLAGS : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto INT0      = std::uint_fast8_t{ 1 }; ///< INT0.
            static constexpr auto INT1      = std::uint_fast8_t{ 1 }; ///< INT1.
            static constexpr auto INT2      = std::uint_fast8_t{ 1 }; ///< INT2.
            static constexpr auto INT3      = std::uint_fast8_t{ 1 }; ///< INT3.
            static constexpr auto RESERVED4 = std::uint_fast8_t{ 1 }; ///< RESERVED4.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto INT0 = std::uint_fast8_t{}; ///< INT0.
            static constexpr auto INT1 = std::uint_fast8_t{ INT0 + Size::INT0 }; ///< INT1.
            static constexpr auto INT2 = std::uint_fast8_t{ INT1 + Size::INT1 }; ///< INT2.
            static constexpr auto INT3 = std::uint_fast8_t{ INT2 + Size::INT2 }; ///< INT3.
            static constexpr auto RESERVED4 = std::uint_fast8_t{ INT3 + Size::INT3 }; ///< RESERVED4.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto INT0 = mask<std::uint8_t>( Size::INT0, Bit::INT0 ); ///< INT0.
            static constexpr auto INT1 = mask<std::uint8_t>( Size::INT1, Bit::INT1 ); ///< INT1.
            static constexpr auto INT2 = mask<std::uint8_t>( Size::INT2, Bit::INT2 ); ///< INT2.
            static constexpr auto INT3 = mask<std::uint8_t>( Size::INT3, Bit::INT3 ); ///< INT3.
            static constexpr auto RESERVED4 = mask<std::uint8_t>( Size::RESERVED4, Bit::RESERVED4 ); ///< RESERVED4.
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
     * \brief LUT Control A (LUTCTRLA) register.
     *
     * This register has the following fields:
     * - LUT Enable (ENABLE)
     * - Clock Source Selection (CLKSRC)
     * - Filter Selection (FILTSEL)
     * - Output Enable (OUTEN)
     * - Edge Detection (EDGEDET)
     */
    class LUTCTRLA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto ENABLE  = std::uint_fast8_t{ 1 }; ///< ENABLE.
            static constexpr auto CLKSRC  = std::uint_fast8_t{ 3 }; ///< CLKSRC.
            static constexpr auto FILTSEL = std::uint_fast8_t{ 2 }; ///< FILTSEL.
            static constexpr auto OUTEN   = std::uint_fast8_t{ 1 }; ///< OUTEN.
            static constexpr auto EDGEDET = std::uint_fast8_t{ 1 }; ///< EDGEDET.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto ENABLE = std::uint_fast8_t{}; ///< ENABLE.
            static constexpr auto CLKSRC = std::uint_fast8_t{ ENABLE + Size::ENABLE }; ///< CLKSRC.
            static constexpr auto FILTSEL = std::uint_fast8_t{ CLKSRC + Size::CLKSRC }; ///< FILTSEL.
            static constexpr auto OUTEN = std::uint_fast8_t{ FILTSEL + Size::FILTSEL }; ///< OUTEN.
            static constexpr auto EDGEDET = std::uint_fast8_t{ OUTEN + Size::OUTEN }; ///< EDGEDET.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto ENABLE = mask<std::uint8_t>( Size::ENABLE, Bit::ENABLE ); ///< ENABLE.
            static constexpr auto CLKSRC = mask<std::uint8_t>( Size::CLKSRC, Bit::CLKSRC ); ///< CLKSRC.
            static constexpr auto FILTSEL = mask<std::uint8_t>( Size::FILTSEL, Bit::FILTSEL ); ///< FILTSEL.
            static constexpr auto OUTEN = mask<std::uint8_t>( Size::OUTEN, Bit::OUTEN ); ///< OUTEN.
            static constexpr auto EDGEDET = mask<std::uint8_t>( Size::EDGEDET, Bit::EDGEDET ); ///< EDGEDET.
        };

        /**
         * \brief CLKSRC.
         */
        enum CLKSRC : std::uint8_t {
            CLKSRC_CLKPER    = 0x0 << Bit::CLKSRC, ///< CLK_PER is clocking the LUT.
            CLKSRC_IN2       = 0x1 << Bit::CLKSRC, ///< LUT input 2 is clocking the LUT.
            CLKSRC_OSC20M    = 0x4 << Bit::CLKSRC, ///< 16/20 MHz oscillator before prescaler is clocking the LUT.
            CLKSRC_OSCULP32K = 0x5 << Bit::CLKSRC, ///< 32.768 kHz internal oscillator is clocking the LUT.
            CLKSRC_OSCULP1K  = 0x6 << Bit::CLKSRC, ///< 1.024 kHz (OSCKILP32K after DIV32) is clocking the LUT.
        };

        /**
         * \brief FILTSEL.
         */
        enum FILTSEL : std::uint8_t {
            FILTSEL_DISABLE = 0x0 << Bit::FILTSEL, ///< Filter disabled.
            FILTSEL_SYNCH   = 0x1 << Bit::FILTSEL, ///< Synchronizer enabled.
            FILTSEL_FILTER  = 0x2 << Bit::FILTSEL, ///< Filter enabled.
        };

        LUTCTRLA() = delete;

        LUTCTRLA( LUTCTRLA && ) = delete;

        LUTCTRLA( LUTCTRLA const & ) = delete;

        ~LUTCTRLA() = delete;

        auto operator=( LUTCTRLA && ) = delete;

        auto operator=( LUTCTRLA const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief LUT Control B (LUTCTRLB) register.
     *
     * This register has the following fields:
     * - LUT Input 0 Source Selection (INSEL0)
     * - LUT Input 1 Source Selection (INSEL1)
     */
    class LUTCTRLB : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto INSEL0 = std::uint_fast8_t{ 4 }; ///< INSEL0.
            static constexpr auto INSEL1 = std::uint_fast8_t{ 4 }; ///< INSEL1.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto INSEL0 = std::uint_fast8_t{}; ///< INSEL0.
            static constexpr auto INSEL1 = std::uint_fast8_t{ INSEL0 + Size::INSEL0 }; ///< INSEL1.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto INSEL0 = mask<std::uint8_t>( Size::INSEL0, Bit::INSEL0 ); ///< INSEL0.
            static constexpr auto INSEL1 = mask<std::uint8_t>( Size::INSEL1, Bit::INSEL1 ); ///< INSEL1.
        };

        /**
         * \brief INSEL0.
         */
        enum INSEL0 : std::uint8_t {
            INSEL0_MASK     = 0x0 << Bit::INSEL0, ///< None (masked).
            INSEL0_FEEDBACK = 0x1 << Bit::INSEL0, ///< Feedback input.
            INSEL0_LINK     = 0x2 << Bit::INSEL0, ///< Output from LUTn+1.
            INSEL0_EVENTA   = 0x3 << Bit::INSEL0, ///< Event input source A.
            INSEL0_EVENTB   = 0x4 << Bit::INSEL0, ///< Event input source B.
            INSEL0_IO       = 0x5 << Bit::INSEL0, ///< I/O-pin LUTn-IN0.
            INSEL0_AC0      = 0x6 << Bit::INSEL0, ///< AC0 out.
            INSEL0_USART0   = 0x8 << Bit::INSEL0, ///< USART0 TXD.
            INSEL0_SPI0     = 0x9 << Bit::INSEL0, ///< SPI0 MOSI.
            INSEL0_TCA0     = 0xA << Bit::INSEL0, ///< TCA0 WO0.
            INSEL0_TCB0     = 0xC << Bit::INSEL0, ///< TCB0 WO.
        };

        /**
         * \brief INSEL1.
         */
        enum INSEL1 : std::uint8_t {
            INSEL1_MASK     = 0x0 << Bit::INSEL1, ///< None (masked).
            INSEL1_FEEDBACK = 0x1 << Bit::INSEL1, ///< Feedback input.
            INSEL1_LINK     = 0x2 << Bit::INSEL1, ///< Output from LUTn+1.
            INSEL1_EVENTA   = 0x3 << Bit::INSEL1, ///< Event input source A.
            INSEL1_EVENTB   = 0x4 << Bit::INSEL1, ///< Event input source B.
            INSEL1_IO       = 0x5 << Bit::INSEL1, ///< I/O-pin LUTn-IN1.
            INSEL1_AC0      = 0x6 << Bit::INSEL1, ///< AC0 out.
            INSEL1_USART1   = 0x8 << Bit::INSEL1, ///< USART1 TXD.
            INSEL1_SPI0     = 0x9 << Bit::INSEL1, ///< SPI0 MOSI.
            INSEL1_TCA0     = 0xA << Bit::INSEL1, ///< TCA0 WO1.
            INSEL1_TCB1     = 0xC << Bit::INSEL1, ///< TCB1 WO.
        };

        LUTCTRLB() = delete;

        LUTCTRLB( LUTCTRLB && ) = delete;

        LUTCTRLB( LUTCTRLB const & ) = delete;

        ~LUTCTRLB() = delete;

        auto operator=( LUTCTRLB && ) = delete;

        auto operator=( LUTCTRLB const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief LUT Control C (LUTCTRLC) register.
     *
     * This register has the following fields:
     * - LUT Input 2 Source Selection (INSEL2)
     */
    class LUTCTRLC : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto INSEL2    = std::uint_fast8_t{ 4 }; ///< INSEL2.
            static constexpr auto RESERVED4 = std::uint_fast8_t{ 4 }; ///< RESERVED4.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto INSEL2 = std::uint_fast8_t{}; ///< INSEL2.
            static constexpr auto RESERVED4 = std::uint_fast8_t{ INSEL2 + Size::INSEL2 }; ///< RESERVED4.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto INSEL2 = mask<std::uint8_t>( Size::INSEL2, Bit::INSEL2 ); ///< INSEL2.
            static constexpr auto RESERVED4 = mask<std::uint8_t>( Size::RESERVED4, Bit::RESERVED4 ); ///< RESERVED4.
        };

        /**
         * \brief INSEL2.
         */
        enum INSEL2 : std::uint8_t {
            INSEL2_MASK     = 0x0 << Bit::INSEL2, ///< None (masked).
            INSEL2_FEEDBACK = 0x1 << Bit::INSEL2, ///< Feedback input.
            INSEL2_LINK     = 0x2 << Bit::INSEL2, ///< Output from LUTn+1.
            INSEL2_EVENTA   = 0x3 << Bit::INSEL2, ///< Event input source A.
            INSEL2_EVENTB   = 0x4 << Bit::INSEL2, ///< Event input source B.
            INSEL2_IO       = 0x5 << Bit::INSEL2, ///< I/O-pin LUTn-IN2.
            INSEL2_AC0      = 0x6 << Bit::INSEL2, ///< AC0 out.
            INSEL2_USART0   = 0x8 << Bit::INSEL2, ///< USART2 TXD.
            INSEL2_SPI0     = 0x9 << Bit::INSEL2, ///< SPI0 SCK.
            INSEL2_TCA0     = 0xA << Bit::INSEL2, ///< TCA0 WO2.
            INSEL2_TCB2     = 0xC << Bit::INSEL2, ///< TCB2 WO.
        };

        LUTCTRLC() = delete;

        LUTCTRLC( LUTCTRLC && ) = delete;

        LUTCTRLC( LUTCTRLC const & ) = delete;

        ~LUTCTRLC() = delete;

        auto operator=( LUTCTRLC && ) = delete;

        auto operator=( LUTCTRLC const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief CTRLA.
     */
    CTRLA ctrla;

    /**
     * \brief SEQCTRL0.
     */
    SEQCTRL0 seqctrl0;

    /**
     * \brief SEQCTRL1.
     */
    SEQCTRL1 seqctrl1;

    /**
     * \brief Reserved registers (offset 0x03-0x04).
     */
    Reserved_Register<std::uint8_t> const reserved_0x03_0x04[ ( 0x04 - 0x03 ) + 1 ];

    /**
     * \brief INTCTRL0.
     */
    INTCTRL0 intctrl0;

    /**
     * \brief Reserved registers (offset 0x06-0x06).
     */
    Reserved_Register<std::uint8_t> const reserved_0x06_0x06[ ( 0x06 - 0x06 ) + 1 ];

    /**
     * \brief INTFLAGS.
     */
    INTFLAGS intflags;

    union {
        struct {
            /**
             * \brief LUTCTRLA.
             */
            LUTCTRLA lutctrla;

            /**
             * \brief LUTCTRLB.
             */
            LUTCTRLB lutctrlb;

            /**
             * \brief LUTCTRLC.
             */
            LUTCTRLC lutctrlc;

            /**
             * \brief LUT Truth Table (TRUTH) register.
             */
            Register<std::uint8_t> truth;
        } lut[ 3 + 1 ];

        struct {
            /**
             * \brief LUT 0 Control A (LUT0CTRLA) register.
             */
            LUTCTRLA lut0ctrla;

            /**
             * \brief LUT 0 Control B (LUT0CTRLB) register.
             */
            LUTCTRLA lut0ctrlb;

            /**
             * \brief LUT 0 Control C (LUT0CTRLC) register.
             */
            LUTCTRLA lut0ctrlc;

            /**
             * \brief LUT 0 Truth Table (TRUTH0) register.
             */
            Register<std::uint8_t> truth0;

            /**
             * \brief LUT 1 Control A (LUT1CTRLA) register.
             */
            LUTCTRLA lut1ctrla;

            /**
             * \brief LUT 1 Control B (LUT1CTRLB) register.
             */
            LUTCTRLA lut1ctrlb;

            /**
             * \brief LUT 1 Control C (LUT1CTRLC) register.
             */
            LUTCTRLA lut1ctrlc;

            /**
             * \brief LUT 1 Truth Table (TRUTH1) register.
             */
            Register<std::uint8_t> truth1;

            /**
             * \brief LUT 2 Control A (LUT2CTRLA) register.
             */
            LUTCTRLA lut2ctrla;

            /**
             * \brief LUT 2 Control B (LUT2CTRLB) register.
             */
            LUTCTRLA lut2ctrlb;

            /**
             * \brief LUT 2 Control C (LUT2CTRLC) register.
             */
            LUTCTRLA lut2ctrlc;

            /**
             * \brief LUT 2 Truth Table (TRUTH2) register.
             */
            Register<std::uint8_t> truth2;

            /**
             * \brief LUT 3 Control A (LUT3CTRLA) register.
             */
            LUTCTRLA lut3ctrla;

            /**
             * \brief LUT 3 Control B (LUT3CTRLB) register.
             */
            LUTCTRLA lut3ctrlb;

            /**
             * \brief LUT 3 Control C (LUT3CTRLC) register.
             */
            LUTCTRLA lut3ctrlc;

            /**
             * \brief LUT 3 Truth Table (TRUTH3) register.
             */
            Register<std::uint8_t> truth3;
        };
    };

    CCL() = delete;

    CCL( CCL && ) = delete;

    CCL( CCL const & ) = delete;

    ~CCL() = delete;

    auto operator=( CCL && ) = delete;

    auto operator=( CCL const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_CCL_H
