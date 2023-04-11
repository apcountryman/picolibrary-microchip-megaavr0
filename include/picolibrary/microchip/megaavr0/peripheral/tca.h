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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::TCA interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_TCA_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_TCA_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr0/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series 16-bit Timer/Counter Type A (TCA) peripheral.
 */
class TCA {
  public:
    /**
     * \brief Normal mode.
     */
    class Normal {
      public:
        /**
         * \brief Control A (CTRLA) register.
         *
         * This register has the following fields:
         * - Enable (ENABLE)
         * - Clock Select (CLKSEL)
         */
        class CTRLA : public Register<std::uint8_t> {
          public:
            /**
             * \brief Field sizes.
             */
            struct Size {
                static constexpr auto ENABLE    = std::uint_fast8_t{ 1 }; ///< ENABLE.
                static constexpr auto CLKSEL    = std::uint_fast8_t{ 3 }; ///< CLKSEL.
                static constexpr auto RESERVED4 = std::uint_fast8_t{ 4 }; ///< RESERVED4.
            };

            /**
             * \brief Field bit positions.
             */
            struct Bit {
                static constexpr auto ENABLE = std::uint_fast8_t{}; ///< ENABLE.
                static constexpr auto CLKSEL = std::uint_fast8_t{ ENABLE + Size::ENABLE }; ///< CLKSEL.
                static constexpr auto RESERVED4 = std::uint_fast8_t{ CLKSEL + Size::CLKSEL }; ///< RESERVED4.
            };

            /**
             * \brief Field bit masks.
             */
            struct Mask {
                static constexpr auto ENABLE = mask<std::uint8_t>( Size::ENABLE, Bit::ENABLE ); ///< ENABLE.
                static constexpr auto CLKSEL = mask<std::uint8_t>( Size::CLKSEL, Bit::CLKSEL ); ///< CLKSEL.
                static constexpr auto RESERVED4 = mask<std::uint8_t>( Size::RESERVED4, Bit::RESERVED4 ); ///< RESERVED4.
            };

            /**
             * \brief CLKSEL.
             */
            enum CLKSEL : std::uint8_t {
                CLKSEL_DIV1    = 0x0 << Bit::CLKSEL, ///< fTCA = fCLK_PER.
                CLKSEL_DIV2    = 0x1 << Bit::CLKSEL, ///< fTCA = fCLK_PER/2.
                CLKSEL_DIV4    = 0x2 << Bit::CLKSEL, ///< fTCA = fCLK_PER/4.
                CLKSEL_DIV8    = 0x3 << Bit::CLKSEL, ///< fTCA = fCLK_PER/8.
                CLKSEL_DIV16   = 0x4 << Bit::CLKSEL, ///< fTCA = fCLK_PER/16.
                CLKSEL_DIV64   = 0x5 << Bit::CLKSEL, ///< fTCA = fCLK_PER/64.
                CLKSEL_DIV256  = 0x6 << Bit::CLKSEL, ///< fTCA = fCLK_PER/256.
                CLKSEL_DIV1024 = 0x7 << Bit::CLKSEL, ///< fTCA = fCLK_PER/1024.
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
         * - Waveform Generation Mode (WGMODE)
         * - Auto-Lock Update (ALUPD)
         * - Compare 0 Enable (CMP0EN)
         * - Compare 1 Enable (CMP1EN)
         * - Compare 2 Enable (CMP2EN)
         */
        class CTRLB : public Register<std::uint8_t> {
          public:
            /**
             * \brief Field sizes.
             */
            struct Size {
                static constexpr auto WGMODE    = std::uint_fast8_t{ 3 }; ///< WGMODE.
                static constexpr auto ALUPD     = std::uint_fast8_t{ 1 }; ///< ALUPD.
                static constexpr auto CMP0EN    = std::uint_fast8_t{ 1 }; ///< CMP0EN.
                static constexpr auto CMP1EN    = std::uint_fast8_t{ 1 }; ///< CMP1EN.
                static constexpr auto CMP2EN    = std::uint_fast8_t{ 1 }; ///< CMP2EN.
                static constexpr auto RESERVED7 = std::uint_fast8_t{ 1 }; ///< RESERVED7.
            };

            /**
             * \brief Field bit positions.
             */
            struct Bit {
                static constexpr auto WGMODE = std::uint_fast8_t{}; ///< WGMODE.
                static constexpr auto ALUPD = std::uint_fast8_t{ WGMODE + Size::WGMODE }; ///< ALUPD.
                static constexpr auto CMP0EN = std::uint_fast8_t{ ALUPD + Size::ALUPD }; ///< CMP0EN.
                static constexpr auto CMP1EN = std::uint_fast8_t{ CMP0EN + Size::CMP0EN }; ///< CMP1EN.
                static constexpr auto CMP2EN = std::uint_fast8_t{ CMP1EN + Size::CMP1EN }; ///< CMP2EN.
                static constexpr auto RESERVED7 = std::uint_fast8_t{ CMP2EN + Size::CMP2EN }; ///< RESERVED7.
            };

            /**
             * \brief Field bit masks.
             */
            struct Mask {
                static constexpr auto WGMODE = mask<std::uint8_t>( Size::WGMODE, Bit::WGMODE ); ///< WGMODE.
                static constexpr auto ALUPD = mask<std::uint8_t>( Size::ALUPD, Bit::ALUPD ); ///< ALUPD.
                static constexpr auto CMP0EN = mask<std::uint8_t>( Size::CMP0EN, Bit::CMP0EN ); ///< CMP0EN.
                static constexpr auto CMP1EN = mask<std::uint8_t>( Size::CMP1EN, Bit::CMP1EN ); ///< CMP1EN.
                static constexpr auto CMP2EN = mask<std::uint8_t>( Size::CMP2EN, Bit::CMP2EN ); ///< CMP2EN.
                static constexpr auto RESERVED7 = mask<std::uint8_t>( Size::RESERVED7, Bit::RESERVED7 ); ///< RESERVED7.
            };

            /**
             * \brief WGMODE.
             */
            enum WGMODE : std::uint8_t {
                WGMODE_NORMAL = 0x0 << Bit::WGMODE, ///< Normal (PER, TOP, TOP).
                WGMODE_FRQ    = 0x1 << Bit::WGMODE, ///< Frequency (CMP0, TOP, TOP).
                WGMODE_SINGLESLOPE = 0x3 << Bit::WGMODE, ///< Single-slope PWM (PER, BOTTOM, BOTTOM).
                WGMODE_DSTOP = 0x5 << Bit::WGMODE, ///< Dual-slope PWM (PER, BOTTOM, TOP).
                WGMODE_DSBOTH = 0x6 << Bit::WGMODE, ///< Dual-slope PWM (PER, BOTTOM, TOP and BOTTOM).
                WGMODE_DSBOTTOM = 0x7 << Bit::WGMODE, ///< Dual-slope PWM (PER, BOTTOM, BOTTOM).
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
         * - Compare Output Value 0 (CMP0OV)
         * - Compare Output Value 1 (CMP1OV)
         * - Compare Output Value 2 (CMP2OV)
         */
        class CTRLC : public Register<std::uint8_t> {
          public:
            /**
             * \brief Field sizes.
             */
            struct Size {
                static constexpr auto CMP0OV    = std::uint_fast8_t{ 1 }; ///< CMP0OV.
                static constexpr auto CMP1OV    = std::uint_fast8_t{ 1 }; ///< CMP1OV.
                static constexpr auto CMP2OV    = std::uint_fast8_t{ 1 }; ///< CMP2OV.
                static constexpr auto RESERVED3 = std::uint_fast8_t{ 5 }; ///< RESERVED3.
            };

            /**
             * \brief Field bit positions.
             */
            struct Bit {
                static constexpr auto CMP0OV = std::uint_fast8_t{}; ///< CMP0OV.
                static constexpr auto CMP1OV = std::uint_fast8_t{ CMP0OV + Size::CMP0OV }; ///< CMP1OV.
                static constexpr auto CMP2OV = std::uint_fast8_t{ CMP1OV + Size::CMP1OV }; ///< CMP2OV.
                static constexpr auto RESERVED3 = std::uint_fast8_t{ CMP2OV + Size::CMP2OV }; ///< RESERVED3.
            };

            /**
             * \brief Field bit masks.
             */
            struct Mask {
                static constexpr auto CMP0OV = mask<std::uint8_t>( Size::CMP0OV, Bit::CMP0OV ); ///< CMP0OV.
                static constexpr auto CMP1OV = mask<std::uint8_t>( Size::CMP1OV, Bit::CMP1OV ); ///< CMP1OV.
                static constexpr auto CMP2OV = mask<std::uint8_t>( Size::CMP2OV, Bit::CMP2OV ); ///< CMP2OV.
                static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
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
         * - Enable Split Mode (SPLITM)
         */
        class CTRLD : public Register<std::uint8_t> {
          public:
            /**
             * \brief Field sizes.
             */
            struct Size {
                static constexpr auto SPLITM    = std::uint_fast8_t{ 1 }; ///< SPLITM.
                static constexpr auto RESERVED1 = std::uint_fast8_t{ 7 }; ///< RESERVED1.
            };

            /**
             * \brief Field bit positions.
             */
            struct Bit {
                static constexpr auto SPLITM = std::uint_fast8_t{}; ///< SPLITM.
                static constexpr auto RESERVED1 = std::uint_fast8_t{ SPLITM + Size::SPLITM }; ///< RESERVED1.
            };

            /**
             * \brief Field bit masks.
             */
            struct Mask {
                static constexpr auto SPLITM = mask<std::uint8_t>( Size::SPLITM, Bit::SPLITM ); ///< SPLITM.
                static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
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
         * \brief Control E Clear (CTRLECLR) register.
         *
         * This register has the following fields:
         * - Counter Direction (DIR)
         * - Lock Update (LUPD)
         * - Command (CMD)
         */
        class CTRLECLR : public Register<std::uint8_t> {
          public:
            /**
             * \brief Field sizes.
             */
            struct Size {
                static constexpr auto DIR       = std::uint_fast8_t{ 1 }; ///< DIR.
                static constexpr auto LUPD      = std::uint_fast8_t{ 1 }; ///< LUPD.
                static constexpr auto CMD       = std::uint_fast8_t{ 2 }; ///< CMD.
                static constexpr auto RESERVED4 = std::uint_fast8_t{ 4 }; ///< RESERVED4.
            };

            /**
             * \brief Field bit positions.
             */
            struct Bit {
                static constexpr auto DIR = std::uint_fast8_t{}; ///< DIR.
                static constexpr auto LUPD = std::uint_fast8_t{ DIR + Size::DIR }; ///< LUPD.
                static constexpr auto CMD = std::uint_fast8_t{ LUPD + Size::LUPD }; ///< CMD.
                static constexpr auto RESERVED4 = std::uint_fast8_t{ CMD + Size::CMD }; ///< RESERVED4.
            };

            /**
             * \brief Field bit masks.
             */
            struct Mask {
                static constexpr auto DIR = mask<std::uint8_t>( Size::DIR, Bit::DIR ); ///< DIR.
                static constexpr auto LUPD = mask<std::uint8_t>( Size::LUPD, Bit::LUPD ); ///< LUPD.
                static constexpr auto CMD = mask<std::uint8_t>( Size::CMD, Bit::CMD ); ///< CMD.
                static constexpr auto RESERVED4 = mask<std::uint8_t>( Size::RESERVED4, Bit::RESERVED4 ); ///< RESERVED4.
            };

            /**
             * \brief CMD.
             */
            enum CMD : std::uint8_t {
                CMD_NONE    = 0x0 << Bit::CMD, ///< No command.
                CMD_UPDATE  = 0x1 << Bit::CMD, ///< Force Update.
                CMD_RESTART = 0x2 << Bit::CMD, ///< Force restart.
                CMD_RESET   = 0x3 << Bit::CMD, ///< Force hard reset (ignored if the timer/counter is enabled).
            };

            CTRLECLR() = delete;

            CTRLECLR( CTRLECLR && ) = delete;

            CTRLECLR( CTRLECLR const & ) = delete;

            ~CTRLECLR() = delete;

            auto operator=( CTRLECLR && ) = delete;

            auto operator=( CTRLECLR const & ) = delete;

            using Register<std::uint8_t>::operator=;
        };

        /**
         * \brief Control E Set (CTRLESET) register.
         *
         * This register has the following fields:
         * - Counter Direction (DIR)
         * - Lock Update (LUPD)
         * - Command (CMD)
         */
        class CTRLESET : public Register<std::uint8_t> {
          public:
            /**
             * \brief Field sizes.
             */
            struct Size {
                static constexpr auto DIR       = std::uint_fast8_t{ 1 }; ///< DIR.
                static constexpr auto LUPD      = std::uint_fast8_t{ 1 }; ///< LUPD.
                static constexpr auto CMD       = std::uint_fast8_t{ 2 }; ///< CMD.
                static constexpr auto RESERVED4 = std::uint_fast8_t{ 4 }; ///< RESERVED4.
            };

            /**
             * \brief Field bit positions.
             */
            struct Bit {
                static constexpr auto DIR = std::uint_fast8_t{}; ///< DIR.
                static constexpr auto LUPD = std::uint_fast8_t{ DIR + Size::DIR }; ///< LUPD.
                static constexpr auto CMD = std::uint_fast8_t{ LUPD + Size::LUPD }; ///< CMD.
                static constexpr auto RESERVED4 = std::uint_fast8_t{ CMD + Size::CMD }; ///< RESERVED4.
            };

            /**
             * \brief Field bit masks.
             */
            struct Mask {
                static constexpr auto DIR = mask<std::uint8_t>( Size::DIR, Bit::DIR ); ///< DIR.
                static constexpr auto LUPD = mask<std::uint8_t>( Size::LUPD, Bit::LUPD ); ///< LUPD.
                static constexpr auto CMD = mask<std::uint8_t>( Size::CMD, Bit::CMD ); ///< CMD.
                static constexpr auto RESERVED4 = mask<std::uint8_t>( Size::RESERVED4, Bit::RESERVED4 ); ///< RESERVED4.
            };

            /**
             * \brief CMD.
             */
            enum CMD : std::uint8_t {
                CMD_NONE    = 0x0 << Bit::CMD, ///< No command.
                CMD_UPDATE  = 0x1 << Bit::CMD, ///< Force Update.
                CMD_RESTART = 0x2 << Bit::CMD, ///< Force restart.
                CMD_RESET   = 0x3 << Bit::CMD, ///< Force hard reset (ignored if the timer/counter is enabled).
            };

            CTRLESET() = delete;

            CTRLESET( CTRLESET && ) = delete;

            CTRLESET( CTRLESET const & ) = delete;

            ~CTRLESET() = delete;

            auto operator=( CTRLESET && ) = delete;

            auto operator=( CTRLESET const & ) = delete;

            using Register<std::uint8_t>::operator=;
        };

        /**
         * \brief Control F Clear (CTRLFCLR) register.
         *
         * This register has the following fields:
         * - Period Buffer Valid (PERBV)
         * - Compare 0 Buffer Valid (CMP0BV)
         * - Compare 1 Buffer Valid (CMP1BV)
         * - Compare 2 Buffer Valid (CMP2BV)
         */
        class CTRLFCLR : public Register<std::uint8_t> {
          public:
            /**
             * \brief Field sizes.
             */
            struct Size {
                static constexpr auto PERBV     = std::uint_fast8_t{ 1 }; ///< PERBV.
                static constexpr auto CMP0BV    = std::uint_fast8_t{ 1 }; ///< CMP0BV.
                static constexpr auto CMP1BV    = std::uint_fast8_t{ 1 }; ///< CMP1BV.
                static constexpr auto CMP2BV    = std::uint_fast8_t{ 1 }; ///< CMP2BV.
                static constexpr auto RESERVED4 = std::uint_fast8_t{ 4 }; ///< RESERVED4.
            };

            /**
             * \brief Field bit positions.
             */
            struct Bit {
                static constexpr auto PERBV = std::uint_fast8_t{}; ///< PERBV.
                static constexpr auto CMP0BV = std::uint_fast8_t{ PERBV + Size::PERBV }; ///< CMP0BV.
                static constexpr auto CMP1BV = std::uint_fast8_t{ CMP0BV + Size::CMP0BV }; ///< CMP1BV.
                static constexpr auto CMP2BV = std::uint_fast8_t{ CMP1BV + Size::CMP1BV }; ///< CMP2BV.
                static constexpr auto RESERVED4 = std::uint_fast8_t{ CMP2BV + Size::CMP2BV }; ///< RESERVED4.
            };

            /**
             * \brief Field bit masks.
             */
            struct Mask {
                static constexpr auto PERBV = mask<std::uint8_t>( Size::PERBV, Bit::PERBV ); ///< PERBV.
                static constexpr auto CMP0BV = mask<std::uint8_t>( Size::CMP0BV, Bit::CMP0BV ); ///< CMP0BV.
                static constexpr auto CMP1BV = mask<std::uint8_t>( Size::CMP1BV, Bit::CMP1BV ); ///< CMP1BV.
                static constexpr auto CMP2BV = mask<std::uint8_t>( Size::CMP2BV, Bit::CMP2BV ); ///< CMP2BV.
                static constexpr auto RESERVED4 = mask<std::uint8_t>( Size::RESERVED4, Bit::RESERVED4 ); ///< RESERVED4.
            };

            CTRLFCLR() = delete;

            CTRLFCLR( CTRLFCLR && ) = delete;

            CTRLFCLR( CTRLFCLR const & ) = delete;

            ~CTRLFCLR() = delete;

            auto operator=( CTRLFCLR && ) = delete;

            auto operator=( CTRLFCLR const & ) = delete;

            using Register<std::uint8_t>::operator=;
        };

        /**
         * \brief Control F Set (CTRLFSET) register.
         *
         * This register has the following fields:
         * - Period Buffer Valid (PERBV)
         * - Compare 0 Buffer Valid (CMP0BV)
         * - Compare 1 Buffer Valid (CMP1BV)
         * - Compare 2 Buffer Valid (CMP2BV)
         */
        class CTRLFSET : public Register<std::uint8_t> {
          public:
            /**
             * \brief Field sizes.
             */
            struct Size {
                static constexpr auto PERBV     = std::uint_fast8_t{ 1 }; ///< PERBV.
                static constexpr auto CMP0BV    = std::uint_fast8_t{ 1 }; ///< CMP0BV.
                static constexpr auto CMP1BV    = std::uint_fast8_t{ 1 }; ///< CMP1BV.
                static constexpr auto CMP2BV    = std::uint_fast8_t{ 1 }; ///< CMP2BV.
                static constexpr auto RESERVED4 = std::uint_fast8_t{ 4 }; ///< RESERVED4.
            };

            /**
             * \brief Field bit positions.
             */
            struct Bit {
                static constexpr auto PERBV = std::uint_fast8_t{}; ///< PERBV.
                static constexpr auto CMP0BV = std::uint_fast8_t{ PERBV + Size::PERBV }; ///< CMP0BV.
                static constexpr auto CMP1BV = std::uint_fast8_t{ CMP0BV + Size::CMP0BV }; ///< CMP1BV.
                static constexpr auto CMP2BV = std::uint_fast8_t{ CMP1BV + Size::CMP1BV }; ///< CMP2BV.
                static constexpr auto RESERVED4 = std::uint_fast8_t{ CMP2BV + Size::CMP2BV }; ///< RESERVED4.
            };

            /**
             * \brief Field bit masks.
             */
            struct Mask {
                static constexpr auto PERBV = mask<std::uint8_t>( Size::PERBV, Bit::PERBV ); ///< PERBV.
                static constexpr auto CMP0BV = mask<std::uint8_t>( Size::CMP0BV, Bit::CMP0BV ); ///< CMP0BV.
                static constexpr auto CMP1BV = mask<std::uint8_t>( Size::CMP1BV, Bit::CMP1BV ); ///< CMP1BV.
                static constexpr auto CMP2BV = mask<std::uint8_t>( Size::CMP2BV, Bit::CMP2BV ); ///< CMP2BV.
                static constexpr auto RESERVED4 = mask<std::uint8_t>( Size::RESERVED4, Bit::RESERVED4 ); ///< RESERVED4.
            };

            CTRLFSET() = delete;

            CTRLFSET( CTRLFSET && ) = delete;

            CTRLFSET( CTRLFSET const & ) = delete;

            ~CTRLFSET() = delete;

            auto operator=( CTRLFSET && ) = delete;

            auto operator=( CTRLFSET const & ) = delete;

            using Register<std::uint8_t>::operator=;
        };

        /**
         * \brief Event Control (EVCTRL) register.
         *
         * This register has the following fields:
         * - Enable Count on Event Input (CNTEI)
         * - Event Action (EVACT)
         */
        class EVCTRL : public Register<std::uint8_t> {
          public:
            /**
             * \brief Field sizes.
             */
            struct Size {
                static constexpr auto CNTEI     = std::uint_fast8_t{ 1 }; ///< CNTEI.
                static constexpr auto EVACT     = std::uint_fast8_t{ 3 }; ///< EVACT.
                static constexpr auto RESERVED4 = std::uint_fast8_t{ 4 }; ///< RESERVED4.
            };

            /**
             * \brief Field bit positions.
             */
            struct Bit {
                static constexpr auto CNTEI = std::uint_fast8_t{}; ///< CNTEI.
                static constexpr auto EVACT = std::uint_fast8_t{ CNTEI + Size::CNTEI }; ///< EVACT.
                static constexpr auto RESERVED4 = std::uint_fast8_t{ EVACT + Size::EVACT }; ///< RESERVED4.
            };

            /**
             * \brief Field bit masks.
             */
            struct Mask {
                static constexpr auto CNTEI = mask<std::uint8_t>( Size::CNTEI, Bit::CNTEI ); ///< CNTEI.
                static constexpr auto EVACT = mask<std::uint8_t>( Size::EVACT, Bit::EVACT ); ///< EVACT.
                static constexpr auto RESERVED4 = mask<std::uint8_t>( Size::RESERVED4, Bit::RESERVED4 ); ///< RESERVED4.
            };

            /**
             * \brief EVACT.
             */
            enum EVACT : std::uint8_t {
                /**
                 * Count on positive event edge.
                 */
                EVACT_POSEDGE = 0x0 << Bit::EVACT,

                /**
                 * Count on any event edge.
                 */
                EVACT_ANYEDGE = 0x1 << Bit::EVACT,

                /**
                 * Count prescaled clock cycles while the event signal is high.
                 */
                EVACT_HIGHLVL = 0x2 << Bit::EVACT,

                /**
                 * Count prescaled clock cycles. The event signal controls the count
                 * direction, up when low and down when high. The direction is latched
                 * when the counter counts.
                 */
                EVACT_UPDOWN = 0x3 << Bit::EVACT,
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
         * - Timer Overflow/Underflow Interrupt Enable (OVF)
         * - Compare Channel 0 Interrupt Enable (CMP0)
         * - Compare Channel 1 Interrupt Enable (CMP1)
         * - Compare Channel 2 Interrupt Enable (CMP2)
         */
        class INTCTRL : public Register<std::uint8_t> {
          public:
            /**
             * \brief Field sizes.
             */
            struct Size {
                static constexpr auto OVF       = std::uint_fast8_t{ 1 }; ///< OVF.
                static constexpr auto RESERVED1 = std::uint_fast8_t{ 3 }; ///< RESERVED1.
                static constexpr auto CMP0      = std::uint_fast8_t{ 1 }; ///< CMP0.
                static constexpr auto CMP1      = std::uint_fast8_t{ 1 }; ///< CMP1.
                static constexpr auto CMP2      = std::uint_fast8_t{ 1 }; ///< CMP2.
                static constexpr auto RESERVED7 = std::uint_fast8_t{ 1 }; ///< RESERVED7.
            };

            /**
             * \brief Field bit positions.
             */
            struct Bit {
                static constexpr auto OVF = std::uint_fast8_t{}; ///< OVF.
                static constexpr auto RESERVED1 = std::uint_fast8_t{ OVF + Size::OVF }; ///< RESERVED1.
                static constexpr auto CMP0 = std::uint_fast8_t{ RESERVED1 + Size::RESERVED1 }; ///< CMP0.
                static constexpr auto CMP1 = std::uint_fast8_t{ CMP0 + Size::CMP0 }; ///< CMP1.
                static constexpr auto CMP2 = std::uint_fast8_t{ CMP1 + Size::CMP1 }; ///< CMP2.
                static constexpr auto RESERVED7 = std::uint_fast8_t{ CMP2 + Size::CMP2 }; ///< RESERVED7.
            };

            /**
             * \brief Field bit masks.
             */
            struct Mask {
                static constexpr auto OVF = mask<std::uint8_t>( Size::OVF, Bit::OVF ); ///< OVF.
                static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
                static constexpr auto CMP0 = mask<std::uint8_t>( Size::CMP0, Bit::CMP0 ); ///< CMP0.
                static constexpr auto CMP1 = mask<std::uint8_t>( Size::CMP1, Bit::CMP1 ); ///< CMP1.
                static constexpr auto CMP2 = mask<std::uint8_t>( Size::CMP2, Bit::CMP2 ); ///< CMP2.
                static constexpr auto RESERVED7 = mask<std::uint8_t>( Size::RESERVED7, Bit::RESERVED7 ); ///< RESERVED7.
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
         * \brief Interrupt Flag (INTFLAGS) register.
         *
         * This register has the following fields:
         * - Overflow/Underflow Interrupt Flag (OVF)
         * - Compare Channel 0 Interrupt Flag (CMP0)
         * - Compare Channel 1 Interrupt Flag (CMP1)
         * - Compare Channel 2 Interrupt Flag (CMP2)
         */
        class INTFLAGS : public Register<std::uint8_t> {
          public:
            /**
             * \brief Field sizes.
             */
            struct Size {
                static constexpr auto OVF       = std::uint_fast8_t{ 1 }; ///< OVF.
                static constexpr auto RESERVED1 = std::uint_fast8_t{ 3 }; ///< RESERVED1.
                static constexpr auto CMP0      = std::uint_fast8_t{ 1 }; ///< CMP0.
                static constexpr auto CMP1      = std::uint_fast8_t{ 1 }; ///< CMP1.
                static constexpr auto CMP2      = std::uint_fast8_t{ 1 }; ///< CMP2.
                static constexpr auto RESERVED7 = std::uint_fast8_t{ 1 }; ///< RESERVED7.
            };

            /**
             * \brief Field bit positions.
             */
            struct Bit {
                static constexpr auto OVF = std::uint_fast8_t{}; ///< OVF.
                static constexpr auto RESERVED1 = std::uint_fast8_t{ OVF + Size::OVF }; ///< RESERVED1.
                static constexpr auto CMP0 = std::uint_fast8_t{ RESERVED1 + Size::RESERVED1 }; ///< CMP0.
                static constexpr auto CMP1 = std::uint_fast8_t{ CMP0 + Size::CMP0 }; ///< CMP1.
                static constexpr auto CMP2 = std::uint_fast8_t{ CMP1 + Size::CMP1 }; ///< CMP2.
                static constexpr auto RESERVED7 = std::uint_fast8_t{ CMP2 + Size::CMP2 }; ///< RESERVED7.
            };

            /**
             * \brief Field bit masks.
             */
            struct Mask {
                static constexpr auto OVF = mask<std::uint8_t>( Size::OVF, Bit::OVF ); ///< OVF.
                static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
                static constexpr auto CMP0 = mask<std::uint8_t>( Size::CMP0, Bit::CMP0 ); ///< CMP0.
                static constexpr auto CMP1 = mask<std::uint8_t>( Size::CMP1, Bit::CMP1 ); ///< CMP1.
                static constexpr auto CMP2 = mask<std::uint8_t>( Size::CMP2, Bit::CMP2 ); ///< CMP2.
                static constexpr auto RESERVED7 = mask<std::uint8_t>( Size::RESERVED7, Bit::RESERVED7 ); ///< RESERVED7.
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
         * \brief Debug Control (DBGCTRL) register.
         *
         * This register has the following fields:
         * - Run in Debug (DBGRUN)
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
         * \brief CTRLECLR.
         */
        CTRLECLR ctrleclr;

        /**
         * \brief CTRLESET.
         */
        CTRLESET ctrleset;

        /**
         * \brief CTRLFCLR.
         */
        CTRLFCLR ctrlfclr;

        /**
         * \brief CTRLFSET.
         */
        CTRLFSET ctrlfset;

        /**
         * \brief Reserved registers (offset 0x08-0x08).
         */
        Reserved_Register<std::uint8_t> const reserved_0x08_0x08[ ( 0x08 - 0x08 ) + 1 ];

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
         * \brief Reserved registers (offset 0x0C-0x0D).
         */
        Reserved_Register<std::uint8_t> const reserved_0x0C_0x0D[ ( 0x0D - 0x0C ) + 1 ];

        /**
         * \brief DBGCTRL.
         */
        DBGCTRL dbgctrl;

        /**
         * \brief Temporary (TEMP) register.
         */
        Register<std::uint8_t> temp;

        /**
         * \brief Reserved registers (offset 0x10-0x1F).
         */
        Reserved_Register<std::uint8_t> const reserved_0x10_0x1F[ ( 0x1F - 0x10 ) + 1 ];

        /**
         * \brief Counter (CNT) register.
         */
        Register<std::uint16_t> cnt;

        /**
         * \brief Reserved registers (offset 0x22-0x25).
         */
        Reserved_Register<std::uint8_t> const reserved_0x22_0x25[ ( 0x25 - 0x22 ) + 1 ];

        /**
         * \brief Period (PER) register.
         */
        Register<std::uint16_t> per;

        /**
         * \brief Compare 0 (CMP0) register.
         */
        Register<std::uint16_t> cmp0;

        /**
         * \brief Compare 1 (CMP1) register.
         */
        Register<std::uint16_t> cmp1;

        /**
         * \brief Compare 2 (CMP2) register.
         */
        Register<std::uint16_t> cmp2;

        /**
         * \brief Reserved registers (offset 0x2E-0x35).
         */
        Reserved_Register<std::uint8_t> const reserved_0x2E_0x35[ ( 0x35 - 0x2E ) + 1 ];

        /**
         * \brief Period Buffer (PERBUF) register.
         */
        Register<std::uint16_t> perbuf;

        /**
         * \brief Compare 0 Buffer (CMP0BUF) register.
         */
        Register<std::uint16_t> cmp0buf;

        /**
         * \brief Compare 1 Buffer (CMP1BUF) register.
         */
        Register<std::uint16_t> cmp1buf;

        /**
         * \brief Compare 2 Buffer (CMP2BUF) register.
         */
        Register<std::uint16_t> cmp2buf;

        Normal() = delete;

        Normal( Normal && ) = delete;

        Normal( Normal const & ) = delete;

        ~Normal() = delete;

        auto operator=( Normal && ) = delete;

        auto operator=( Normal const & ) = delete;
    };

    /**
     * \brief Split mode.
     */
    class Split {
      public:
        /**
         * \brief Control A (CTRLA) register.
         *
         * This register has the following fields:
         * - Enable (ENABLE)
         * - Clock Select (CLKSEL)
         */
        class CTRLA : public Register<std::uint8_t> {
          public:
            /**
             * \brief Field sizes.
             */
            struct Size {
                static constexpr auto ENABLE    = std::uint_fast8_t{ 1 }; ///< ENABLE.
                static constexpr auto CLKSEL    = std::uint_fast8_t{ 3 }; ///< CLKSEL.
                static constexpr auto RESERVED4 = std::uint_fast8_t{ 4 }; ///< RESERVED4.
            };

            /**
             * \brief Field bit positions.
             */
            struct Bit {
                static constexpr auto ENABLE = std::uint_fast8_t{}; ///< ENABLE.
                static constexpr auto CLKSEL = std::uint_fast8_t{ ENABLE + Size::ENABLE }; ///< CLKSEL.
                static constexpr auto RESERVED4 = std::uint_fast8_t{ CLKSEL + Size::CLKSEL }; ///< RESERVED4.
            };

            /**
             * \brief Field bit masks.
             */
            struct Mask {
                static constexpr auto ENABLE = mask<std::uint8_t>( Size::ENABLE, Bit::ENABLE ); ///< ENABLE.
                static constexpr auto CLKSEL = mask<std::uint8_t>( Size::CLKSEL, Bit::CLKSEL ); ///< CLKSEL.
                static constexpr auto RESERVED4 = mask<std::uint8_t>( Size::RESERVED4, Bit::RESERVED4 ); ///< RESERVED4.
            };

            /**
             * \brief CLKSEL.
             */
            enum CLKSEL : std::uint8_t {
                CLKSEL_DIV1    = 0x0 << Bit::CLKSEL, ///< fTCA = fCLK_PER.
                CLKSEL_DIV2    = 0x1 << Bit::CLKSEL, ///< fTCA = fCLK_PER/2.
                CLKSEL_DIV4    = 0x2 << Bit::CLKSEL, ///< fTCA = fCLK_PER/4.
                CLKSEL_DIV8    = 0x3 << Bit::CLKSEL, ///< fTCA = fCLK_PER/8.
                CLKSEL_DIV16   = 0x4 << Bit::CLKSEL, ///< fTCA = fCLK_PER/16.
                CLKSEL_DIV64   = 0x5 << Bit::CLKSEL, ///< fTCA = fCLK_PER/64.
                CLKSEL_DIV256  = 0x6 << Bit::CLKSEL, ///< fTCA = fCLK_PER/256.
                CLKSEL_DIV1024 = 0x7 << Bit::CLKSEL, ///< fTCA = fCLK_PER/1024.
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
         * - Low Byte Compare 0 Enable (LCMP0EN)
         * - Low Byte Compare 1 Enable (LCMP1EN)
         * - Low Byte Compare 2 Enable (LCMP2EN)
         * - High Byte Compare 0 Enable (HCMP0EN)
         * - High Byte Compare 1 Enable (HCMP1EN)
         * - High Byte Compare 2 Enable (HCMP2EN)
         */
        class CTRLB : public Register<std::uint8_t> {
          public:
            /**
             * \brief Field sizes.
             */
            struct Size {
                static constexpr auto LCMP0EN   = std::uint_fast8_t{ 1 }; ///< LCMP0EN.
                static constexpr auto LCMP1EN   = std::uint_fast8_t{ 1 }; ///< LCMP1EN.
                static constexpr auto LCMP2EN   = std::uint_fast8_t{ 1 }; ///< LCMP2EN.
                static constexpr auto RESERVED3 = std::uint_fast8_t{ 1 }; ///< RESERVED3.
                static constexpr auto HCMP0EN   = std::uint_fast8_t{ 1 }; ///< HCMP0EN.
                static constexpr auto HCMP1EN   = std::uint_fast8_t{ 1 }; ///< HCMP1EN.
                static constexpr auto HCMP2EN   = std::uint_fast8_t{ 1 }; ///< HCMP2EN.
                static constexpr auto RESERVED7 = std::uint_fast8_t{ 1 }; ///< RESERVED7.
            };

            /**
             * \brief Field bit positions.
             */
            struct Bit {
                static constexpr auto LCMP0EN = std::uint_fast8_t{}; ///< LCMP0EN.
                static constexpr auto LCMP1EN = std::uint_fast8_t{ LCMP0EN + Size::LCMP0EN }; ///< LCMP1EN.
                static constexpr auto LCMP2EN = std::uint_fast8_t{ LCMP1EN + Size::LCMP1EN }; ///< LCMP2EN.
                static constexpr auto RESERVED3 = std::uint_fast8_t{ LCMP2EN + Size::LCMP2EN }; ///< RESERVED3.
                static constexpr auto HCMP0EN = std::uint_fast8_t{ RESERVED3 + Size::RESERVED3 }; ///< HCMP0EN.
                static constexpr auto HCMP1EN = std::uint_fast8_t{ HCMP0EN + Size::HCMP0EN }; ///< HCMP1EN.
                static constexpr auto HCMP2EN = std::uint_fast8_t{ HCMP1EN + Size::HCMP1EN }; ///< HCMP2EN.
                static constexpr auto RESERVED7 = std::uint_fast8_t{ HCMP2EN + Size::HCMP2EN }; ///< RESERVED7.
            };

            /**
             * \brief Field bit masks.
             */
            struct Mask {
                static constexpr auto LCMP0EN = mask<std::uint8_t>( Size::LCMP0EN, Bit::LCMP0EN ); ///< LCMP0EN.
                static constexpr auto LCMP1EN = mask<std::uint8_t>( Size::LCMP1EN, Bit::LCMP1EN ); ///< LCMP1EN.
                static constexpr auto LCMP2EN = mask<std::uint8_t>( Size::LCMP2EN, Bit::LCMP2EN ); ///< LCMP2EN.
                static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
                static constexpr auto HCMP0EN = mask<std::uint8_t>( Size::HCMP0EN, Bit::HCMP0EN ); ///< HCMP0EN.
                static constexpr auto HCMP1EN = mask<std::uint8_t>( Size::HCMP1EN, Bit::HCMP1EN ); ///< HCMP1EN.
                static constexpr auto HCMP2EN = mask<std::uint8_t>( Size::HCMP2EN, Bit::HCMP2EN ); ///< HCMP2EN.
                static constexpr auto RESERVED7 = mask<std::uint8_t>( Size::RESERVED7, Bit::RESERVED7 ); ///< RESERVED7.
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
         * - Low Byte Compare 0 Output Value (LCMP0OV)
         * - Low Byte Compare 1 Output Value (LCMP1OV)
         * - Low Byte Compare 2 Output Value (LCMP2OV)
         * - High Byte Compare 0 Output Value (HCMP0OV)
         * - High Byte Compare 1 Output Value (HCMP1OV)
         * - High Byte Compare 2 Output Value (HCMP2OV)
         */
        class CTRLC : public Register<std::uint8_t> {
          public:
            /**
             * \brief Field sizes.
             */
            struct Size {
                static constexpr auto LCMP0OV   = std::uint_fast8_t{ 1 }; ///< LCMP0OV.
                static constexpr auto LCMP1OV   = std::uint_fast8_t{ 1 }; ///< LCMP1OV.
                static constexpr auto LCMP2OV   = std::uint_fast8_t{ 1 }; ///< LCMP2OV.
                static constexpr auto RESERVED3 = std::uint_fast8_t{ 1 }; ///< RESERVED3.
                static constexpr auto HCMP0OV   = std::uint_fast8_t{ 1 }; ///< HCMP0OV.
                static constexpr auto HCMP1OV   = std::uint_fast8_t{ 1 }; ///< HCMP1OV.
                static constexpr auto HCMP2OV   = std::uint_fast8_t{ 1 }; ///< HCMP2OV.
                static constexpr auto RESERVED7 = std::uint_fast8_t{ 1 }; ///< RESERVED7.
            };

            /**
             * \brief Field bit positions.
             */
            struct Bit {
                static constexpr auto LCMP0OV = std::uint_fast8_t{}; ///< LCMP0OV.
                static constexpr auto LCMP1OV = std::uint_fast8_t{ LCMP0OV + Size::LCMP0OV }; ///< LCMP1OV.
                static constexpr auto LCMP2OV = std::uint_fast8_t{ LCMP1OV + Size::LCMP1OV }; ///< LCMP2OV.
                static constexpr auto RESERVED3 = std::uint_fast8_t{ LCMP2OV + Size::LCMP2OV }; ///< RESERVED3.
                static constexpr auto HCMP0OV = std::uint_fast8_t{ RESERVED3 + Size::RESERVED3 }; ///< HCMP0OV.
                static constexpr auto HCMP1OV = std::uint_fast8_t{ HCMP0OV + Size::HCMP0OV }; ///< HCMP1OV.
                static constexpr auto HCMP2OV = std::uint_fast8_t{ HCMP1OV + Size::HCMP1OV }; ///< HCMP2OV.
                static constexpr auto RESERVED7 = std::uint_fast8_t{ HCMP2OV + Size::HCMP2OV }; ///< RESERVED7.
            };

            /**
             * \brief Field bit masks.
             */
            struct Mask {
                static constexpr auto LCMP0OV = mask<std::uint8_t>( Size::LCMP0OV, Bit::LCMP0OV ); ///< LCMP0OV.
                static constexpr auto LCMP1OV = mask<std::uint8_t>( Size::LCMP1OV, Bit::LCMP1OV ); ///< LCMP1OV.
                static constexpr auto LCMP2OV = mask<std::uint8_t>( Size::LCMP2OV, Bit::LCMP2OV ); ///< LCMP2OV.
                static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
                static constexpr auto HCMP0OV = mask<std::uint8_t>( Size::HCMP0OV, Bit::HCMP0OV ); ///< HCMP0OV.
                static constexpr auto HCMP1OV = mask<std::uint8_t>( Size::HCMP1OV, Bit::HCMP1OV ); ///< HCMP1OV.
                static constexpr auto HCMP2OV = mask<std::uint8_t>( Size::HCMP2OV, Bit::HCMP2OV ); ///< HCMP2OV.
                static constexpr auto RESERVED7 = mask<std::uint8_t>( Size::RESERVED7, Bit::RESERVED7 ); ///< RESERVED7.
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
         * - Enable Split Mode (SPLITM)
         */
        class CTRLD : public Register<std::uint8_t> {
          public:
            /**
             * \brief Field sizes.
             */
            struct Size {
                static constexpr auto SPLITM    = std::uint_fast8_t{ 1 }; ///< SPLITM.
                static constexpr auto RESERVED1 = std::uint_fast8_t{ 7 }; ///< RESERVED1.
            };

            /**
             * \brief Field bit positions.
             */
            struct Bit {
                static constexpr auto SPLITM = std::uint_fast8_t{}; ///< SPLITM.
                static constexpr auto RESERVED1 = std::uint_fast8_t{ SPLITM + Size::SPLITM }; ///< RESERVED1.
            };

            /**
             * \brief Field bit masks.
             */
            struct Mask {
                static constexpr auto SPLITM = mask<std::uint8_t>( Size::SPLITM, Bit::SPLITM ); ///< SPLITM.
                static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
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
         * \brief Control E Clear (CTRLECLR) register.
         *
         * This register has the following fields:
         * - Command Enable (CMDEN)
         * - Command (CMD)
         */
        class CTRLECLR : public Register<std::uint8_t> {
          public:
            /**
             * \brief Field sizes.
             */
            struct Size {
                static constexpr auto CMDEN     = std::uint_fast8_t{ 2 }; ///< CMDEN.
                static constexpr auto CMD       = std::uint_fast8_t{ 2 }; ///< CMD.
                static constexpr auto RESERVED4 = std::uint_fast8_t{ 4 }; ///< RESERVED4.
            };

            /**
             * \brief Field bit positions.
             */
            struct Bit {
                static constexpr auto CMDEN = std::uint_fast8_t{}; ///< CMDEN.
                static constexpr auto CMD = std::uint_fast8_t{ CMDEN + Size::CMDEN }; ///< CMD.
                static constexpr auto RESERVED4 = std::uint_fast8_t{ CMD + Size::CMD }; ///< RESERVED4.
            };

            /**
             * \brief Field bit masks.
             */
            struct Mask {
                static constexpr auto CMDEN = mask<std::uint8_t>( Size::CMDEN, Bit::CMDEN ); ///< CMDEN.
                static constexpr auto CMD = mask<std::uint8_t>( Size::CMD, Bit::CMD ); ///< CMD.
                static constexpr auto RESERVED4 = mask<std::uint8_t>( Size::RESERVED4, Bit::RESERVED4 ); ///< RESERVED4.
            };

            /**
             * \brief CMDEN.
             */
            enum CMDEN : std::uint8_t {
                CMDEN_NONE = 0x0 << Bit::CMDEN, ///< None.
                CMDEN_BOTH = 0x3 << Bit::CMDEN, ///< Command (CMD) will be applied to both low byte and high byte timer/counter.
            };

            /**
             * \brief CMD.
             */
            enum CMD : std::uint8_t {
                CMD_NONE    = 0x0 << Bit::CMD, ///< No command.
                CMD_RESTART = 0x2 << Bit::CMD, ///< Force restart.
                CMD_RESET   = 0x3 << Bit::CMD, ///< Force hard reset (ignored if the timer/counter is enabled).
            };

            CTRLECLR() = delete;

            CTRLECLR( CTRLECLR && ) = delete;

            CTRLECLR( CTRLECLR const & ) = delete;

            ~CTRLECLR() = delete;

            auto operator=( CTRLECLR && ) = delete;

            auto operator=( CTRLECLR const & ) = delete;

            using Register<std::uint8_t>::operator=;
        };

        /**
         * \brief Control E Set (CTRLESET) register.
         *
         * This register has the following fields:
         * - Command Enable (CMDEN)
         * - Command (CMD)
         */
        class CTRLESET : public Register<std::uint8_t> {
          public:
            /**
             * \brief Field sizes.
             */
            struct Size {
                static constexpr auto CMDEN     = std::uint_fast8_t{ 2 }; ///< CMDEN.
                static constexpr auto CMD       = std::uint_fast8_t{ 2 }; ///< CMD.
                static constexpr auto RESERVED4 = std::uint_fast8_t{ 4 }; ///< RESERVED4.
            };

            /**
             * \brief Field bit positions.
             */
            struct Bit {
                static constexpr auto CMDEN = std::uint_fast8_t{}; ///< CMDEN.
                static constexpr auto CMD = std::uint_fast8_t{ CMDEN + Size::CMDEN }; ///< CMD.
                static constexpr auto RESERVED4 = std::uint_fast8_t{ CMD + Size::CMD }; ///< RESERVED4.
            };

            /**
             * \brief Field bit masks.
             */
            struct Mask {
                static constexpr auto CMDEN = mask<std::uint8_t>( Size::CMDEN, Bit::CMDEN ); ///< CMDEN.
                static constexpr auto CMD = mask<std::uint8_t>( Size::CMD, Bit::CMD ); ///< CMD.
                static constexpr auto RESERVED4 = mask<std::uint8_t>( Size::RESERVED4, Bit::RESERVED4 ); ///< RESERVED4.
            };

            /**
             * \brief CMDEN.
             */
            enum CMDEN : std::uint8_t {
                CMDEN_NONE = 0x0 << Bit::CMDEN, ///< None.
                CMDEN_BOTH = 0x3 << Bit::CMDEN, ///< Command (CMD) will be applied to both low byte and high byte timer/counter.
            };

            /**
             * \brief CMD.
             */
            enum CMD : std::uint8_t {
                CMD_NONE    = 0x0 << Bit::CMD, ///< No command.
                CMD_RESTART = 0x2 << Bit::CMD, ///< Force restart.
                CMD_RESET   = 0x3 << Bit::CMD, ///< Force hard reset (ignored if the timer/counter is enabled).
            };

            CTRLESET() = delete;

            CTRLESET( CTRLESET && ) = delete;

            CTRLESET( CTRLESET const & ) = delete;

            ~CTRLESET() = delete;

            auto operator=( CTRLESET && ) = delete;

            auto operator=( CTRLESET const & ) = delete;

            using Register<std::uint8_t>::operator=;
        };

        /**
         * \brief Interrupt Control (INTCTRL) register.
         *
         * This register has the following fields:
         * - Low Byte Underflow Interrupt Enable (LUNF)
         * - High Byte Underflow Interrupt Enable (HUNF)
         * - Low Byte Compare Channel 0 Interrupt Enable (LCMP0)
         * - Low Byte Compare Channel 1 Interrupt Enable (LCMP1)
         * - Low Byte Compare Channel 2 Interrupt Enable (LCMP2)
         */
        class INTCTRL : public Register<std::uint8_t> {
          public:
            /**
             * \brief Field sizes.
             */
            struct Size {
                static constexpr auto LUNF      = std::uint_fast8_t{ 1 }; ///< LUNF.
                static constexpr auto HUNF      = std::uint_fast8_t{ 1 }; ///< HUNF.
                static constexpr auto RESERVED2 = std::uint_fast8_t{ 2 }; ///< RESERVED2.
                static constexpr auto LCMP0     = std::uint_fast8_t{ 1 }; ///< LCMP0.
                static constexpr auto LCMP1     = std::uint_fast8_t{ 1 }; ///< LCMP1.
                static constexpr auto LCMP2     = std::uint_fast8_t{ 1 }; ///< LCMP2.
                static constexpr auto RESERVED7 = std::uint_fast8_t{ 1 }; ///< RESERVED7.
            };

            /**
             * \brief Field bit positions.
             */
            struct Bit {
                static constexpr auto LUNF = std::uint_fast8_t{}; ///< LUNF.
                static constexpr auto HUNF = std::uint_fast8_t{ LUNF + Size::LUNF }; ///< HUNF.
                static constexpr auto RESERVED2 = std::uint_fast8_t{ HUNF + Size::HUNF }; ///< RESERVED2.
                static constexpr auto LCMP0 = std::uint_fast8_t{ RESERVED2 + Size::RESERVED2 }; ///< LCMP0.
                static constexpr auto LCMP1 = std::uint_fast8_t{ LCMP0 + Size::LCMP0 }; ///< LCMP1.
                static constexpr auto LCMP2 = std::uint_fast8_t{ LCMP1 + Size::LCMP1 }; ///< LCMP2.
                static constexpr auto RESERVED7 = std::uint_fast8_t{ LCMP2 + Size::LCMP2 }; ///< RESERVED7.
            };

            /**
             * \brief Field bit masks.
             */
            struct Mask {
                static constexpr auto LUNF = mask<std::uint8_t>( Size::LUNF, Bit::LUNF ); ///< LUNF.
                static constexpr auto HUNF = mask<std::uint8_t>( Size::HUNF, Bit::HUNF ); ///< HUNF.
                static constexpr auto RESERVED2 = mask<std::uint8_t>( Size::RESERVED2, Bit::RESERVED2 ); ///< RESERVED2.
                static constexpr auto LCMP0 = mask<std::uint8_t>( Size::LCMP0, Bit::LCMP0 ); ///< LCMP0.
                static constexpr auto LCMP1 = mask<std::uint8_t>( Size::LCMP1, Bit::LCMP1 ); ///< LCMP1.
                static constexpr auto LCMP2 = mask<std::uint8_t>( Size::LCMP2, Bit::LCMP2 ); ///< LCMP2.
                static constexpr auto RESERVED7 = mask<std::uint8_t>( Size::RESERVED7, Bit::RESERVED7 ); ///< RESERVED7.
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
         * \brief Interrupt Flag (INTFLAGS) register.
         *
         * This register has the following fields:
         * - Low Byte Underflow Interrupt Flag (LUNF)
         * - High Byte Underflow Interrupt Flag (HUNF)
         * - Low Byte Compare Channel 0 Interrupt Flag (LCMP0)
         * - Low Byte Compare Channel 1 Interrupt Flag (LCMP1)
         * - Low Byte Compare Channel 2 Interrupt Flag (LCMP2)
         */
        class INTFLAGS : public Register<std::uint8_t> {
          public:
            /**
             * \brief Field sizes.
             */
            struct Size {
                static constexpr auto LUNF      = std::uint_fast8_t{ 1 }; ///< LUNF.
                static constexpr auto HUNF      = std::uint_fast8_t{ 1 }; ///< HUNF.
                static constexpr auto RESERVED2 = std::uint_fast8_t{ 2 }; ///< RESERVED2.
                static constexpr auto LCMP0     = std::uint_fast8_t{ 1 }; ///< LCMP0.
                static constexpr auto LCMP1     = std::uint_fast8_t{ 1 }; ///< LCMP1.
                static constexpr auto LCMP2     = std::uint_fast8_t{ 1 }; ///< LCMP2.
                static constexpr auto RESERVED7 = std::uint_fast8_t{ 1 }; ///< RESERVED7.
            };

            /**
             * \brief Field bit positions.
             */
            struct Bit {
                static constexpr auto LUNF = std::uint_fast8_t{}; ///< LUNF.
                static constexpr auto HUNF = std::uint_fast8_t{ LUNF + Size::LUNF }; ///< HUNF.
                static constexpr auto RESERVED2 = std::uint_fast8_t{ HUNF + Size::HUNF }; ///< RESERVED2.
                static constexpr auto LCMP0 = std::uint_fast8_t{ RESERVED2 + Size::RESERVED2 }; ///< LCMP0.
                static constexpr auto LCMP1 = std::uint_fast8_t{ LCMP0 + Size::LCMP0 }; ///< LCMP1.
                static constexpr auto LCMP2 = std::uint_fast8_t{ LCMP1 + Size::LCMP1 }; ///< LCMP2.
                static constexpr auto RESERVED7 = std::uint_fast8_t{ LCMP2 + Size::LCMP2 }; ///< RESERVED7.
            };

            /**
             * \brief Field bit masks.
             */
            struct Mask {
                static constexpr auto LUNF = mask<std::uint8_t>( Size::LUNF, Bit::LUNF ); ///< LUNF.
                static constexpr auto HUNF = mask<std::uint8_t>( Size::HUNF, Bit::HUNF ); ///< HUNF.
                static constexpr auto RESERVED2 = mask<std::uint8_t>( Size::RESERVED2, Bit::RESERVED2 ); ///< RESERVED2.
                static constexpr auto LCMP0 = mask<std::uint8_t>( Size::LCMP0, Bit::LCMP0 ); ///< LCMP0.
                static constexpr auto LCMP1 = mask<std::uint8_t>( Size::LCMP1, Bit::LCMP1 ); ///< LCMP1.
                static constexpr auto LCMP2 = mask<std::uint8_t>( Size::LCMP2, Bit::LCMP2 ); ///< LCMP2.
                static constexpr auto RESERVED7 = mask<std::uint8_t>( Size::RESERVED7, Bit::RESERVED7 ); ///< RESERVED7.
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
         * \brief Debug Control (DBGCTRL) register.
         *
         * This register has the following fields:
         * - Run in Debug (DBGRUN)
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
         * \brief CTRLECLR.
         */
        CTRLECLR ctrleclr;

        /**
         * \brief CTRLESET.
         */
        CTRLESET ctrleset;

        /**
         * \brief Reserved registers (offset 0x06-0x09).
         */
        Reserved_Register<std::uint8_t> const reserved_0x06_0x09[ ( 0x09 - 0x06 ) + 1 ];

        /**
         * \brief INTCTRL.
         */
        INTCTRL intctrl;

        /**
         * \brief INTFLAGS.
         */
        INTFLAGS intflags;

        /**
         * \brief Reserved registers (offset 0x0C-0x0D).
         */
        Reserved_Register<std::uint8_t> const reserved_0x0C_0x0D[ ( 0x0D - 0x0C ) + 1 ];

        /**
         * \brief DBGCTRL.
         */
        DBGCTRL dbgctrl;

        /**
         * \brief Reserved registers (offset 0x0F-0x1F).
         */
        Reserved_Register<std::uint8_t> const reserved_0x0F_0x1F[ ( 0x1F - 0x0F ) + 1 ];

        /**
         * \brief Low Byte Timer Counter (LCNT) register.
         */
        Register<std::uint8_t> lcnt;

        /**
         * \brief High Byte Timer Counter (HCNT) register.
         */
        Register<std::uint8_t> hcnt;

        /**
         * \brief Reserved registers (offset 0x22-0x25).
         */
        Reserved_Register<std::uint8_t> const reserved_0x22_0x25[ ( 0x25 - 0x22 ) + 1 ];

        /**
         * \brief Low Byte Timer Period (LPER) register.
         */
        Register<std::uint8_t> lper;

        /**
         * \brief High Byte Timer Period (HPER) register.
         */
        Register<std::uint8_t> hper;

        /**
         * \brief Low Byte Timer Compare 0 (LCMP0) register.
         */
        Register<std::uint8_t> lcmp0;

        /**
         * \brief High Byte Timer Compare 0 (HCMP0) register.
         */
        Register<std::uint8_t> hcmp0;

        /**
         * \brief Low Byte Timer Compare 1 (LCMP1) register.
         */
        Register<std::uint8_t> lcmp1;

        /**
         * \brief High Byte Timer Compare 1 (HCMP1) register.
         */
        Register<std::uint8_t> hcmp1;

        /**
         * \brief Low Byte Timer Compare 2 (LCMP2) register.
         */
        Register<std::uint8_t> lcmp2;

        /**
         * \brief High Byte Timer Compare 2 (HCMP2) register.
         */
        Register<std::uint8_t> hcmp2;

        Split() = delete;

        Split( Split && ) = delete;

        Split( Split const & ) = delete;

        ~Split() = delete;

        auto operator=( Split && ) = delete;

        auto operator=( Split const & ) = delete;
    };

    union {
        /**
         * \brief Normal mode.
         */
        Normal normal;

        /**
         * \brief Split mode.
         */
        Split split;
    };

    TCA() = delete;

    TCA( TCA && ) = delete;

    TCA( TCA const & ) = delete;

    ~TCA() = delete;

    auto operator=( TCA && ) = delete;

    auto operator=( TCA const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_TCA_H
