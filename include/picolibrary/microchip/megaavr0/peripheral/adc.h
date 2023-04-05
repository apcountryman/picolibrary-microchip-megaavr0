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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::ADC interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_ADC_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_ADC_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr0/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series Serial Peripheral Interface (ADC) peripheral.
 */
class ADC {
  public:
    /**
     * \brief Control A (CTRLA) register.
     *
     * This register has the following fields:
     * - ADC Enable (ENABLE)
     * - Free-Running (FREERUN)
     * - Resolution Selection (RESSEL)
     * - Run in Standby (RUNSTBY)
     */
    class CTRLA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto ENABLE    = std::uint_fast8_t{ 1 }; ///< ENABLE.
            static constexpr auto FREERUN   = std::uint_fast8_t{ 1 }; ///< FREERUN.
            static constexpr auto RESSEL    = std::uint_fast8_t{ 1 }; ///< RESSEL.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ 4 }; ///< RESERVED3.
            static constexpr auto RUNSTBY   = std::uint_fast8_t{ 1 }; ///< RUNSTBY.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto ENABLE = std::uint_fast8_t{}; ///< ENABLE.
            static constexpr auto FREERUN = std::uint_fast8_t{ ENABLE + Size::ENABLE }; ///< FREERUN.
            static constexpr auto RESSEL = std::uint_fast8_t{ FREERUN + Size::FREERUN }; ///< RESSEL.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ RESSEL + Size::RESSEL }; ///< RESERVED3.
            static constexpr auto RUNSTBY = std::uint_fast8_t{ RESERVED3 + Size::RESERVED3 }; ///< RUNSTBY.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto ENABLE = mask<std::uint8_t>( Size::ENABLE, Bit::ENABLE ); ///< ENABLE.
            static constexpr auto FREERUN = mask<std::uint8_t>( Size::FREERUN, Bit::FREERUN ); ///< FREERUN.
            static constexpr auto RESSEL = mask<std::uint8_t>( Size::RESSEL, Bit::RESSEL ); ///< RESSEL.
            static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
            static constexpr auto RUNSTBY = mask<std::uint8_t>( Size::RUNSTBY, Bit::RUNSTBY ); ///< RUNSTBY.
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
     * - Sample Accumulation Number Select (SAMPNUM)
     */
    class CTRLB : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto SAMPNUM   = std::uint_fast8_t{ 3 }; ///< SAMPNUM.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ 5 }; ///< RESERVED3.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto SAMPNUM = std::uint_fast8_t{}; ///< SAMPNUM.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ SAMPNUM + Size::SAMPNUM }; ///< RESERVED3.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto SAMPNUM = mask<std::uint8_t>( Size::SAMPNUM, Bit::SAMPNUM ); ///< SAMPNUM.
            static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
        };

        /**
         * \brief SAMPNUM.
         */
        enum SAMPNUM : std::uint8_t {
            SAMPNUM_NONE  = 0x0 << Bit::SAMPNUM, ///< No accumulation.
            SAMPNUM_ACC2  = 0x1 << Bit::SAMPNUM, ///< 2 results accumulated.
            SAMPNUM_ACC4  = 0x2 << Bit::SAMPNUM, ///< 4 results accumulated.
            SAMPNUM_ACC8  = 0x3 << Bit::SAMPNUM, ///< 8 results accumulated.
            SAMPNUM_ACC16 = 0x4 << Bit::SAMPNUM, ///< 16 results accumulated.
            SAMPNUM_ACC32 = 0x5 << Bit::SAMPNUM, ///< 32 results accumulated.
            SAMPNUM_ACC64 = 0x6 << Bit::SAMPNUM, ///< 64 results accumulated.
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
     * This register has the following fields:
     * - Prescaler (PRESC)
     * - Reference Selection (REFSEL)
     * - Sample Capacitance Selection (SAMPCAP)
     */
    class CTRLC : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto PRESC     = std::uint_fast8_t{ 3 }; ///< PRESC.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ 1 }; ///< RESERVED3.
            static constexpr auto REFSEL    = std::uint_fast8_t{ 2 }; ///< REFSEL.
            static constexpr auto SAMPCAP   = std::uint_fast8_t{ 1 }; ///< SAMPCAP.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ 1 }; ///< RESERVED7.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto PRESC = std::uint_fast8_t{}; ///< PRESC.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ PRESC + Size::PRESC }; ///< RESERVED3.
            static constexpr auto REFSEL = std::uint_fast8_t{ RESERVED3 + Size::RESERVED3 }; ///< REFSEL.
            static constexpr auto SAMPCAP = std::uint_fast8_t{ REFSEL + Size::REFSEL }; ///< SAMPCAP.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ SAMPCAP + Size::SAMPCAP }; ///< RESERVED7.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto PRESC = mask<std::uint8_t>( Size::PRESC, Bit::PRESC ); ///< PRESC.
            static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
            static constexpr auto REFSEL = mask<std::uint8_t>( Size::REFSEL, Bit::REFSEL ); ///< REFSEL.
            static constexpr auto SAMPCAP = mask<std::uint8_t>( Size::SAMPCAP, Bit::SAMPCAP ); ///< SAMPCAP.
            static constexpr auto RESERVED7 = mask<std::uint8_t>( Size::RESERVED7, Bit::RESERVED7 ); ///< RESERVED7.
        };

        /**
         * \brief PRESC.
         */
        enum PRESC : std::uint8_t {
            PRESC_DIV2   = 0x0 << Bit::PRESC, ///< CLK_PER divided by 2.
            PRESC_DIV4   = 0x1 << Bit::PRESC, ///< CLK_PER divided by 4.
            PRESC_DIV8   = 0x2 << Bit::PRESC, ///< CLK_PER divided by 8.
            PRESC_DIV16  = 0x3 << Bit::PRESC, ///< CLK_PER divided by 16.
            PRESC_DIV32  = 0x4 << Bit::PRESC, ///< CLK_PER divided by 32.
            PRESC_DIV64  = 0x5 << Bit::PRESC, ///< CLK_PER divided by 64.
            PRESC_DIV128 = 0x6 << Bit::PRESC, ///< CLK_PER divided by 128.
            PRESC_DIV256 = 0x7 << Bit::PRESC, ///< CLK_PER divided by 256.
        };

        /**
         * \brief REFSEL.
         */
        enum REFSEL : std::uint8_t {
            REFSEL_INTERNAL = 0x0 << Bit::REFSEL, ///< Internal reference.
            REFSEL_VDD      = 0x1 << Bit::REFSEL, ///< VDD.
            REFSEL_VREFA    = 0x2 << Bit::REFSEL, ///< External reference VREFA.
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
     * - Sampling Delay Selection (SAMPDLY)
     * - Automatic Sampling Delay Variation (ASDV)
     * - Initialization Delay (INITDLY)
     */
    class CTRLD : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto SAMPDLY = std::uint_fast8_t{ 4 }; ///< SAMPDLY.
            static constexpr auto ASDV    = std::uint_fast8_t{ 1 }; ///< ASDV.
            static constexpr auto INITDLY = std::uint_fast8_t{ 3 }; ///< INITDLY.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto SAMPDLY = std::uint_fast8_t{}; ///< SAMPDLY.
            static constexpr auto ASDV = std::uint_fast8_t{ SAMPDLY + Size::SAMPDLY }; ///< ASDV.
            static constexpr auto INITDLY = std::uint_fast8_t{ ASDV + Size::ASDV }; ///< INITDLY.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto SAMPDLY = mask<std::uint8_t>( Size::SAMPDLY, Bit::SAMPDLY ); ///< SAMPDLY.
            static constexpr auto ASDV = mask<std::uint8_t>( Size::ASDV, Bit::ASDV ); ///< ASDV.
            static constexpr auto INITDLY = mask<std::uint8_t>( Size::INITDLY, Bit::INITDLY ); ///< INITDLY.
        };

        /**
         * \brief ASDV.
         */
        enum ASDV : std::uint8_t {
            ASDV_ASVOFF = 0 << Bit::ASDV, ///< The Automatic Sampling Delay Variation is disabled.
            ASDV_ASVON = 1 << Bit::ASDV, ///< The Automatic Sampling Delay Variation is enabled.
        };

        /**
         * \brief INITDLY.
         */
        enum INITDLY : std::uint8_t {
            INITDLY_DLY0   = 0x0 << Bit::INITDLY, ///< Delay 0 CLK_ADC cycles.
            INITDLY_DLY16  = 0x1 << Bit::INITDLY, ///< Delay 16 CLK_ADC cycles.
            INITDLY_DLY32  = 0x2 << Bit::INITDLY, ///< Delay 32 CLK_ADC cycles.
            INITDLY_DLY64  = 0x3 << Bit::INITDLY, ///< Delay 64 CLK_ADC cycles.
            INITDLY_DLY128 = 0x4 << Bit::INITDLY, ///< Delay 128 CLK_ADC cycles.
            INITDLY_DLY256 = 0x5 << Bit::INITDLY, ///< Delay 256 CLK_ADC cycles.
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
     * \brief Control E (CTRLE) register.
     *
     * This register has the following fields:
     * - Window Comparator Mode (WINCM)
     */
    class CTRLE : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto WINCM     = std::uint_fast8_t{ 3 }; ///< WINCM.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ 5 }; ///< RESERVED3.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto WINCM = std::uint_fast8_t{}; ///< WINCM.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ WINCM + Size::WINCM }; ///< RESERVED3.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto WINCM = mask<std::uint8_t>( Size::WINCM, Bit::WINCM ); ///< WINCM.
            static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
        };

        /**
         * \brief WINCM.
         */
        enum WINCM : std::uint8_t {
            WINCM_NONE    = 0x0 << Bit::WINCM, ///< No Window Comparison (default).
            WINCM_BELOW   = 0x1 << Bit::WINCM, ///< RESULT < WINLT.
            WINCM_ABOVE   = 0x2 << Bit::WINCM, ///< RESULT > WINHT.
            WINCM_INSIDE  = 0x3 << Bit::WINCM, ///< WINLT < RESULT < WINHT.
            WINCM_OUTSIDE = 0x4 << Bit::WINCM, ///< RESULT < WINLT or RESULT > WINHT.
        };

        CTRLE() = delete;

        CTRLE( CTRLE && ) = delete;

        CTRLE( CTRLE const & ) = delete;

        ~CTRLE() = delete;

        auto operator=( CTRLE && ) = delete;

        auto operator=( CTRLE const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Sample Control (SAMPCTRL) register.
     *
     * This register has the following fields:
     * - (SAMPLEN)
     */
    class SAMPCTRL : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto SAMPLEN   = std::uint_fast8_t{ 5 }; ///< SAMPLEN.
            static constexpr auto RESERVED5 = std::uint_fast8_t{ 3 }; ///< RESERVED5.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto SAMPLEN = std::uint_fast8_t{}; ///< SAMPLEN.
            static constexpr auto RESERVED5 = std::uint_fast8_t{ SAMPLEN + Size::SAMPLEN }; ///< RESERVED5.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto SAMPLEN = mask<std::uint8_t>( Size::SAMPLEN, Bit::SAMPLEN ); ///< SAMPLEN.
            static constexpr auto RESERVED5 = mask<std::uint8_t>( Size::RESERVED5, Bit::RESERVED5 ); ///< RESERVED5.
        };

        SAMPCTRL() = delete;

        SAMPCTRL( SAMPCTRL && ) = delete;

        SAMPCTRL( SAMPCTRL const & ) = delete;

        ~SAMPCTRL() = delete;

        auto operator=( SAMPCTRL && ) = delete;

        auto operator=( SAMPCTRL const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief MUXPOS (MUXPOS) register.
     *
     * This register has the following fields:
     * - MUXPOS (MUXPOS)
     */
    class MUXPOS : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto MUXPOS    = std::uint_fast8_t{ 5 }; ///< MUXPOS.
            static constexpr auto RESERVED5 = std::uint_fast8_t{ 3 }; ///< RESERVED5.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto MUXPOS = std::uint_fast8_t{}; ///< MUXPOS.
            static constexpr auto RESERVED5 = std::uint_fast8_t{ MUXPOS + Size::MUXPOS }; ///< RESERVED5.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto MUXPOS = mask<std::uint8_t>( Size::MUXPOS, Bit::MUXPOS ); ///< MUXPOS.
            static constexpr auto RESERVED5 = mask<std::uint8_t>( Size::RESERVED5, Bit::RESERVED5 ); ///< RESERVED5.
        };

        /**
         * \brief MUXPOS.
         *
         * \attention The name of this enum does not match the name of the field it is
         *            associated with to avoid the name collision that would occur due to
         *            the register and field having the same name.
         */
        enum MUXPOSITION : std::uint8_t {
            MUXPOS_AIN0      = 0x00 << Bit::MUXPOS, ///< ADC input pin 0.
            MUXPOS_AIN1      = 0x01 << Bit::MUXPOS, ///< ADC input pin 1.
            MUXPOS_AIN2      = 0x02 << Bit::MUXPOS, ///< ADC input pin 2.
            MUXPOS_AIN3      = 0x03 << Bit::MUXPOS, ///< ADC input pin 3.
            MUXPOS_AIN4      = 0x04 << Bit::MUXPOS, ///< ADC input pin 4.
            MUXPOS_AIN5      = 0x05 << Bit::MUXPOS, ///< ADC input pin 5.
            MUXPOS_AIN6      = 0x06 << Bit::MUXPOS, ///< ADC input pin 6.
            MUXPOS_AIN7      = 0x07 << Bit::MUXPOS, ///< ADC input pin 7.
            MUXPOS_AIN8      = 0x08 << Bit::MUXPOS, ///< ADC input pin 8.
            MUXPOS_AIN9      = 0x09 << Bit::MUXPOS, ///< ADC input pin 9.
            MUXPOS_AIN10     = 0x0A << Bit::MUXPOS, ///< ADC input pin 10.
            MUXPOS_AIN11     = 0x0B << Bit::MUXPOS, ///< ADC input pin 11.
            MUXPOS_AIN12     = 0x0C << Bit::MUXPOS, ///< ADC input pin 12.
            MUXPOS_AIN13     = 0x0D << Bit::MUXPOS, ///< ADC input pin 13.
            MUXPOS_AIN14     = 0x0E << Bit::MUXPOS, ///< ADC input pin 14.
            MUXPOS_AIN15     = 0x0F << Bit::MUXPOS, ///< ADC input pin 15.
            MUXPOS_DACREF0   = 0x1C << Bit::MUXPOS, ///< DAC reference in AC0.
            MUXPOS_TEMPSENSE = 0x1E << Bit::MUXPOS, ///< Temperature sensor.
            MUXPOS_GND       = 0x1F << Bit::MUXPOS, ///< GND.
        };

        MUXPOS() = delete;

        MUXPOS( MUXPOS && ) = delete;

        MUXPOS( MUXPOS const & ) = delete;

        ~MUXPOS() = delete;

        auto operator=( MUXPOS && ) = delete;

        auto operator=( MUXPOS const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Command (COMMAND) register.
     *
     * This register has the following fields:
     * - Start Conversion (STCONV)
     */
    class COMMAND : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto STCONV    = std::uint_fast8_t{ 1 }; ///< STCONV.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 7 }; ///< RESERVED1.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto STCONV = std::uint_fast8_t{}; ///< STCONV.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ STCONV + Size::STCONV }; ///< RESERVED1.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto STCONV = mask<std::uint8_t>( Size::STCONV, Bit::STCONV ); ///< STCONV.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
        };

        COMMAND() = delete;

        COMMAND( COMMAND && ) = delete;

        COMMAND( COMMAND const & ) = delete;

        ~COMMAND() = delete;

        auto operator=( COMMAND && ) = delete;

        auto operator=( COMMAND const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Event Control (EVCTRL) register.
     *
     * This register has the following fields:
     * - Start Event Input (STARTEI)
     */
    class EVCTRL : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto STARTEI   = std::uint_fast8_t{ 1 }; ///< STARTEI.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 7 }; ///< RESERVED1.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto STARTEI = std::uint_fast8_t{}; ///< STARTEI.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ STARTEI + Size::STARTEI }; ///< RESERVED1.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto STARTEI = mask<std::uint8_t>( Size::STARTEI, Bit::STARTEI ); ///< STARTEI.
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
     * \brief Interrupt Control (INTCTRL) register.
     *
     * This register has the following fields:
     * - Result Ready Interrupt Enable (RESRDY)
     * - Window Comparator Interrupt Enable (WCMP)
     */
    class INTCTRL : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto RESRDY    = std::uint_fast8_t{ 1 }; ///< RESRDY.
            static constexpr auto WCMP      = std::uint_fast8_t{ 1 }; ///< WCMP.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ 6 }; ///< RESERVED2.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto RESRDY = std::uint_fast8_t{}; ///< RESRDY.
            static constexpr auto WCMP = std::uint_fast8_t{ RESRDY + Size::RESRDY }; ///< WCMP.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ WCMP + Size::WCMP }; ///< RESERVED2.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto RESRDY = mask<std::uint8_t>( Size::RESRDY, Bit::RESRDY ); ///< RESRDY.
            static constexpr auto WCMP = mask<std::uint8_t>( Size::WCMP, Bit::WCMP ); ///< WCMP.
            static constexpr auto RESERVED2 = mask<std::uint8_t>( Size::RESERVED2, Bit::RESERVED2 ); ///< RESERVED2.
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
     * - Result Ready Interrupt Flag (RESRDY)
     * - Window Comparator Interrupt Flag (WCMP)
     */
    class INTFLAGS : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto RESRDY    = std::uint_fast8_t{ 1 }; ///< RESRDY.
            static constexpr auto WCMP      = std::uint_fast8_t{ 1 }; ///< WCMP.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ 6 }; ///< RESERVED2.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto RESRDY = std::uint_fast8_t{}; ///< RESRDY.
            static constexpr auto WCMP = std::uint_fast8_t{ RESRDY + Size::RESRDY }; ///< WCMP.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ WCMP + Size::WCMP }; ///< RESERVED2.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto RESRDY = mask<std::uint8_t>( Size::RESRDY, Bit::RESRDY ); ///< RESRDY.
            static constexpr auto WCMP = mask<std::uint8_t>( Size::WCMP, Bit::WCMP ); ///< WCMP.
            static constexpr auto RESERVED2 = mask<std::uint8_t>( Size::RESERVED2, Bit::RESERVED2 ); ///< RESERVED2.
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
     * \brief Debug Run (DBGCTRL) register.
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
     * \brief Calibration (CALIB) register.
     *
     * This register has the following fields:
     * - Duty Cycle (DUTYCYC)
     */
    class CALIB : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto DUTYCYC   = std::uint_fast8_t{ 1 }; ///< DUTYCYC.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 7 }; ///< RESERVED1.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto DUTYCYC = std::uint_fast8_t{}; ///< DUTYCYC.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ DUTYCYC + Size::DUTYCYC }; ///< RESERVED1.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto DUTYCYC = mask<std::uint8_t>( Size::DUTYCYC, Bit::DUTYCYC ); ///< DUTYCYC.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
        };

        CALIB() = delete;

        CALIB( CALIB && ) = delete;

        CALIB( CALIB const & ) = delete;

        ~CALIB() = delete;

        auto operator=( CALIB && ) = delete;

        auto operator=( CALIB const & ) = delete;

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
     * \brief CTRLC.
     */
    CTRLC ctrlc;

    /**
     * \brief CTRLD.
     */
    CTRLD ctrld;

    /**
     * \brief CTRLE.
     */
    CTRLE ctrle;

    /**
     * \brief SAMPCTRL.
     */
    SAMPCTRL sampctrl;

    /**
     * \brief MUXPOS.
     */
    MUXPOS muxpos;

    /**
     * \brief Reserved registers (offset 0x07-0x07).
     */
    Reserved_Register<std::uint8_t> const reserved_0x07_0x07[ ( 0x07 - 0x07 ) + 1 ];

    /**
     * \brief COMMAND.
     */
    COMMAND command;

    /**
     * \brief EVCTRL.
     */
    EVCTRL evctrl;

    /**
     * \brief INTCTRL.
     */
    INTCTRL intctrl;

    /**
     * \brief INTFLAGS.
     */
    INTFLAGS intflags;

    /**
     * \brief DBGCTRL.
     */
    DBGCTRL dbgctrl;

    /**
     * \brief Reserved registers (offset 0x0E-0x0F).
     */
    Reserved_Register<std::uint8_t> const reserved_0x0E_0x0F[ ( 0x0F - 0x0E ) + 1 ];

    /**
     * \brief Temporary (TEMP) register.
     */
    Register<std::uint8_t> temp;

    /**
     * \brief Result (RES) register.
     */
    Register<std::uint16_t> const res;

    /**
     * \brief Window Comparator Low Threshold (WINLT) register.
     */
    Register<std::uint16_t> winlt;

    /**
     * \brief Window Comparator High Threshold (WINHT) register.
     */
    Register<std::uint16_t> winht;

    /**
     * \brief CALIB.
     */
    CALIB calib;

    ADC() = delete;

    ADC( ADC && ) = delete;

    ADC( ADC const & ) = delete;

    ~ADC() = delete;

    auto operator=( ADC && ) = delete;

    auto operator=( ADC const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_ADC_H
