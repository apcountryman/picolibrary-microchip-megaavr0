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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::RTC interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_RTC_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_RTC_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr0/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series Real-Time Counter (RTC) peripheral.
 */
class RTC {
  public:
    /**
     * \brief Control A (CTRLA) register.
     *
     * This register has the following fields:
     * - RTC Peripheral Enable (RTCEN)
     * - Frequency Correction Enable (CORREN)
     * - Prescaler (PRESCALER)
     * - Run in Standby (RUNSTDBY)
     */
    class CTRLA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto RTCEN     = std::uint_fast8_t{ 1 }; ///< RTCEN.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 1 }; ///< RESERVED1.
            static constexpr auto CORREN    = std::uint_fast8_t{ 1 }; ///< CORREN.
            static constexpr auto PRESCALER = std::uint_fast8_t{ 4 }; ///< PRESCALER.
            static constexpr auto RUNSTDBY  = std::uint_fast8_t{ 1 }; ///< RUNSTDBY.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto RTCEN = std::uint_fast8_t{}; ///< RTCEN.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ RTCEN + Size::RTCEN }; ///< RESERVED1.
            static constexpr auto CORREN = std::uint_fast8_t{ RESERVED1 + Size::RESERVED1 }; ///< CORREN.
            static constexpr auto PRESCALER = std::uint_fast8_t{ CORREN + Size::CORREN }; ///< PRESCALER.
            static constexpr auto RUNSTDBY = std::uint_fast8_t{ PRESCALER + Size::PRESCALER }; ///< RUNSTDBY.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto RTCEN = mask<std::uint8_t>( Size::RTCEN, Bit::RTCEN ); ///< RTCEN.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
            static constexpr auto CORREN = mask<std::uint8_t>( Size::CORREN, Bit::CORREN ); ///< CORREN.
            static constexpr auto PRESCALER = mask<std::uint8_t>( Size::PRESCALER, Bit::PRESCALER ); ///< PRESCALER.
            static constexpr auto RUNSTDBY = mask<std::uint8_t>( Size::RUNSTDBY, Bit::RUNSTDBY ); ///< RUNSTDBY.
        };

        /**
         * \brief PRESCALER.
         */
        enum PRESCALER : std::uint8_t {
            PRESCALER_DIV1     = 0x0 << Bit::PRESCALER, ///< RTC clock/1 (no prescaling).
            PRESCALER_DIV2     = 0x1 << Bit::PRESCALER, ///< RTC clock/2.
            PRESCALER_DIV4     = 0x2 << Bit::PRESCALER, ///< RTC clock/4.
            PRESCALER_DIV8     = 0x3 << Bit::PRESCALER, ///< RTC clock/8.
            PRESCALER_DIV16    = 0x4 << Bit::PRESCALER, ///< RTC clock/16.
            PRESCALER_DIV32    = 0x5 << Bit::PRESCALER, ///< RTC clock/32.
            PRESCALER_DIV64    = 0x6 << Bit::PRESCALER, ///< RTC clock/64.
            PRESCALER_DIV128   = 0x7 << Bit::PRESCALER, ///< RTC clock/128.
            PRESCALER_DIV256   = 0x8 << Bit::PRESCALER, ///< RTC clock/256.
            PRESCALER_DIV512   = 0x9 << Bit::PRESCALER, ///< RTC clock/512.
            PRESCALER_DIV1024  = 0xA << Bit::PRESCALER, ///< RTC clock/1024.
            PRESCALER_DIV2048  = 0xB << Bit::PRESCALER, ///< RTC clock/2048.
            PRESCALER_DIV4096  = 0xC << Bit::PRESCALER, ///< RTC clock/4096.
            PRESCALER_DIV8192  = 0xD << Bit::PRESCALER, ///< RTC clock/8192.
            PRESCALER_DIV16384 = 0xE << Bit::PRESCALER, ///< RTC clock/16384.
            PRESCALER_DIV32768 = 0xF << Bit::PRESCALER, ///< RTC clock/32768.
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
     * \brief Status (STATUS) register.
     *
     * This register has the following fields:
     * - Control A Synchronization Busy (CTRLABUSY)
     * - Counter Synchronization Busy (CNTBUSY)
     * - Period Synchronization Busy (PERBUSY)
     * - Compare Synchronization Busy (CMPBUSY)
     */
    class STATUS : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto CTRLABUSY = std::uint_fast8_t{ 1 }; ///< CTRLABUSY.
            static constexpr auto CNTBUSY   = std::uint_fast8_t{ 1 }; ///< CNTBUSY.
            static constexpr auto PERBUSY   = std::uint_fast8_t{ 1 }; ///< PERBUSY.
            static constexpr auto CMPBUSY   = std::uint_fast8_t{ 1 }; ///< CMPBUSY.
            static constexpr auto RESERVED4 = std::uint_fast8_t{ 4 }; ///< RESERVED4.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto CTRLABUSY = std::uint_fast8_t{}; ///< CTRLABUSY.
            static constexpr auto CNTBUSY = std::uint_fast8_t{ CTRLABUSY + Size::CTRLABUSY }; ///< CNTBUSY.
            static constexpr auto PERBUSY = std::uint_fast8_t{ CNTBUSY + Size::CNTBUSY }; ///< PERBUSY.
            static constexpr auto CMPBUSY = std::uint_fast8_t{ PERBUSY + Size::PERBUSY }; ///< CMPBUSY.
            static constexpr auto RESERVED4 = std::uint_fast8_t{ CMPBUSY + Size::CMPBUSY }; ///< RESERVED4.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto CTRLABUSY = mask<std::uint8_t>( Size::CTRLABUSY, Bit::CTRLABUSY ); ///< CTRLABUSY.
            static constexpr auto CNTBUSY = mask<std::uint8_t>( Size::CNTBUSY, Bit::CNTBUSY ); ///< CNTBUSY.
            static constexpr auto PERBUSY = mask<std::uint8_t>( Size::PERBUSY, Bit::PERBUSY ); ///< PERBUSY.
            static constexpr auto CMPBUSY = mask<std::uint8_t>( Size::CMPBUSY, Bit::CMPBUSY ); ///< CMPBUSY.
            static constexpr auto RESERVED4 = mask<std::uint8_t>( Size::RESERVED4, Bit::RESERVED4 ); ///< RESERVED4.
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
     * \brief Interrupt Control (INTCTRL) register.
     *
     * This register has the following fields:
     * - Overflow Interrupt Enable (OVF)
     * - Compare Match Interrupt Enable (CMP)
     */
    class INTCTRL : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto OVF       = std::uint_fast8_t{ 1 }; ///< OVF.
            static constexpr auto CMP       = std::uint_fast8_t{ 1 }; ///< CMP.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ 6 }; ///< RESERVED2.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto OVF = std::uint_fast8_t{};                  ///< OVF.
            static constexpr auto CMP = std::uint_fast8_t{ OVF + Size::OVF }; ///< CMP.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ CMP + Size::CMP }; ///< RESERVED2.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto OVF = mask<std::uint8_t>( Size::OVF, Bit::OVF ); ///< OVF.
            static constexpr auto CMP = mask<std::uint8_t>( Size::CMP, Bit::CMP ); ///< CMP.
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
     * \brief Interrupt Flag (INTFLAGS) register.
     *
     * This register has the following fields:
     * - Overflow Interrupt Flag (OVF)
     * - Compare Match Interrupt Flag (CMP)
     */
    class INTFLAGS : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto OVF       = std::uint_fast8_t{ 1 }; ///< OVF.
            static constexpr auto CMP       = std::uint_fast8_t{ 1 }; ///< CMP.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ 6 }; ///< RESERVED2.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto OVF = std::uint_fast8_t{};                  ///< OVF.
            static constexpr auto CMP = std::uint_fast8_t{ OVF + Size::OVF }; ///< CMP.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ CMP + Size::CMP }; ///< RESERVED2.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto OVF = mask<std::uint8_t>( Size::OVF, Bit::OVF ); ///< OVF.
            static constexpr auto CMP = mask<std::uint8_t>( Size::CMP, Bit::CMP ); ///< CMP.
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
     * \brief Crystal Frequency Calibration (CALIB) register.
     *
     * This register has the following fields:
     * - Error Correction Value (ERROR)
     * - Error Correction Sign Bit (SIGN)
     */
    class CALIB : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto ERROR = std::uint_fast8_t{ 7 }; ///< ERROR.
            static constexpr auto SIGN  = std::uint_fast8_t{ 1 }; ///< SIGN.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto ERROR = std::uint_fast8_t{}; ///< ERROR.
            static constexpr auto SIGN = std::uint_fast8_t{ ERROR + Size::ERROR }; ///< SIGN.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto ERROR = mask<std::uint8_t>( Size::ERROR, Bit::ERROR ); ///< ERROR.
            static constexpr auto SIGN = mask<std::uint8_t>( Size::SIGN, Bit::SIGN ); ///< SIGN.
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
     * \brief Clock Selection (CLKSEL) register.
     *
     * This register has the following fields:
     * - Clock Select (CLKSEL)
     */
    class CLKSEL : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto CLKSEL    = std::uint_fast8_t{ 2 }; ///< CLKSEL.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ 6 }; ///< RESERVED2.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto CLKSEL = std::uint_fast8_t{}; ///< CLKSEL.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ CLKSEL + Size::CLKSEL }; ///< RESERVED2.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto CLKSEL = mask<std::uint8_t>( Size::CLKSEL, Bit::CLKSEL ); ///< CLKSEL.
            static constexpr auto RESERVED2 = mask<std::uint8_t>( Size::RESERVED2, Bit::RESERVED2 ); ///< RESERVED2.
        };

        /**
         * \brief CLKSEL.
         *
         * \attention The name of this enum does not match the name of the field it is
         *            associated with to avoid the name collision that would occur due to
         *            the register and field having the same name.
         */
        enum CLKSELECT : std::uint8_t {
            CLKSEL_INT32K  = 0x0 << Bit::CLKSEL, ///< Internal 32.768 kHz oscillator.
            CLKSEL_INT1K   = 0x1 << Bit::CLKSEL, ///< Internal 1.024 kHz oscillator.
            CLKSEL_TOSC32K = 0x2 << Bit::CLKSEL, ///< 32.768 kHz crystal oscillator.
            CLKSEL_EXTCLK  = 0x3 << Bit::CLKSEL, ///< External clock from EXTCLK pin.
        };

        CLKSEL() = delete;

        CLKSEL( CLKSEL && ) = delete;

        CLKSEL( CLKSEL const & ) = delete;

        ~CLKSEL() = delete;

        auto operator=( CLKSEL && ) = delete;

        auto operator=( CLKSEL const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Periodic Interrupt Timer Control A (PITCTRLA) register.
     *
     * This register has the following fields:
     * - Periodic Interrupt Timer Enable (PITEN)
     * - Period (PERIOD)
     */
    class PITCTRLA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto PITEN     = std::uint_fast8_t{ 1 }; ///< PITEN.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 2 }; ///< RESERVED1.
            static constexpr auto PERIOD    = std::uint_fast8_t{ 4 }; ///< PERIOD.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ 1 }; ///< RESERVED7.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto PITEN = std::uint_fast8_t{}; ///< PITEN.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ PITEN + Size::PITEN }; ///< RESERVED1.
            static constexpr auto PERIOD = std::uint_fast8_t{ RESERVED1 + Size::RESERVED1 }; ///< PERIOD.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ PERIOD + Size::PERIOD }; ///< RESERVED7.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto PITEN = mask<std::uint8_t>( Size::PITEN, Bit::PITEN ); ///< PITEN.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
            static constexpr auto PERIOD = mask<std::uint8_t>( Size::PERIOD, Bit::PERIOD ); ///< PERIOD.
            static constexpr auto RESERVED7 = mask<std::uint8_t>( Size::RESERVED7, Bit::RESERVED7 ); ///< RESERVED7.
        };

        /**
         * \brief PERIOD.
         */
        enum PERIOD : std::uint8_t {
            PERIOD_OFF      = 0x0 << Bit::PERIOD, ///< No interrupt.
            PERIOD_CYC4     = 0x1 << Bit::PERIOD, ///< 4 cycles.
            PERIOD_CYC8     = 0x2 << Bit::PERIOD, ///< 8 cycles.
            PERIOD_CYC16    = 0x3 << Bit::PERIOD, ///< 16 cycles.
            PERIOD_CYC32    = 0x4 << Bit::PERIOD, ///< 32 cycles.
            PERIOD_CYC64    = 0x5 << Bit::PERIOD, ///< 64 cycles.
            PERIOD_CYC128   = 0x6 << Bit::PERIOD, ///< 128 cycles.
            PERIOD_CYC256   = 0x7 << Bit::PERIOD, ///< 256 cycles.
            PERIOD_CYC512   = 0x8 << Bit::PERIOD, ///< 512 cycles.
            PERIOD_CYC1024  = 0x9 << Bit::PERIOD, ///< 1024 cycles.
            PERIOD_CYC2048  = 0xA << Bit::PERIOD, ///< 2048 cycles.
            PERIOD_CYC4096  = 0xB << Bit::PERIOD, ///< 4096 cycles.
            PERIOD_CYC8192  = 0xC << Bit::PERIOD, ///< 8192 cycles.
            PERIOD_CYC16384 = 0xD << Bit::PERIOD, ///< 16384 cycles.
            PERIOD_CYC32768 = 0xE << Bit::PERIOD, ///< 32768 cycles.
        };

        PITCTRLA() = delete;

        PITCTRLA( PITCTRLA && ) = delete;

        PITCTRLA( PITCTRLA const & ) = delete;

        ~PITCTRLA() = delete;

        auto operator=( PITCTRLA && ) = delete;

        auto operator=( PITCTRLA const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Periodic Interrupt Timer Status (PITSTATUS) register.
     *
     * This register has the following fields:
     * - PITCTRLA Synchronization Busy (CTRLBUSY)
     */
    class PITSTATUS : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto CTRLBUSY  = std::uint_fast8_t{ 1 }; ///< CTRLBUSY.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 7 }; ///< RESERVED1.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto CTRLBUSY = std::uint_fast8_t{}; ///< CTRLBUSY.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ CTRLBUSY + Size::CTRLBUSY }; ///< RESERVED1.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto CTRLBUSY = mask<std::uint8_t>( Size::CTRLBUSY, Bit::CTRLBUSY ); ///< CTRLBUSY.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
        };

        PITSTATUS() = delete;

        PITSTATUS( PITSTATUS && ) = delete;

        PITSTATUS( PITSTATUS const & ) = delete;

        ~PITSTATUS() = delete;

        auto operator=( PITSTATUS && ) = delete;

        auto operator=( PITSTATUS const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief PIT Interrupt Control (PITINTCTRL) register.
     *
     * This register has the following fields:
     * - Periodic Interrupt (PI)
     */
    class PITINTCTRL : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto PI        = std::uint_fast8_t{ 1 }; ///< PI.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 7 }; ///< RESERVED1.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto PI        = std::uint_fast8_t{};                ///< PI.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ PI + Size::PI }; ///< RESERVED1.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto PI = mask<std::uint8_t>( Size::PI, Bit::PI ); ///< PI.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
        };

        PITINTCTRL() = delete;

        PITINTCTRL( PITINTCTRL && ) = delete;

        PITINTCTRL( PITINTCTRL const & ) = delete;

        ~PITINTCTRL() = delete;

        auto operator=( PITINTCTRL && ) = delete;

        auto operator=( PITINTCTRL const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief PIT Interrupt Flag (PITINTFLAGS) register.
     *
     * This register has the following fields:
     * - Periodic Interrupt Flag (PI)
     */
    class PITINTFLAGS : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto PI        = std::uint_fast8_t{ 1 }; ///< PI.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 7 }; ///< RESERVED1.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto PI        = std::uint_fast8_t{};                ///< PI.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ PI + Size::PI }; ///< RESERVED1.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto PI = mask<std::uint8_t>( Size::PI, Bit::PI ); ///< PI.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
        };

        PITINTFLAGS() = delete;

        PITINTFLAGS( PITINTFLAGS && ) = delete;

        PITINTFLAGS( PITINTFLAGS const & ) = delete;

        ~PITINTFLAGS() = delete;

        auto operator=( PITINTFLAGS && ) = delete;

        auto operator=( PITINTFLAGS const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Periodic Interrupt Timer Debug Control (PITDBGCTRL) register.
     *
     * This register has the following fields:
     * - Debug Run (DBGRUN)
     */
    class PITDBGCTRL : public Register<std::uint8_t> {
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

        PITDBGCTRL() = delete;

        PITDBGCTRL( PITDBGCTRL && ) = delete;

        PITDBGCTRL( PITDBGCTRL const & ) = delete;

        ~PITDBGCTRL() = delete;

        auto operator=( PITDBGCTRL && ) = delete;

        auto operator=( PITDBGCTRL const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief CTRLA.
     */
    CTRLA ctrla;

    /**
     * \brief STATUS.
     */
    STATUS const status;

    /**
     * \brief INTCTRL.
     */
    INTCTRL intctrl;

    /**
     * \brief INTFLAGS.
     */
    INTFLAGS intflags;

    /**
     * \brief Temporary (TEMP) register.
     */
    Register<std::uint8_t> temp;

    /**
     * \brief DBGCTRL.
     */
    DBGCTRL dbgctrl;

    /**
     * \brief CALIB.
     */
    CALIB calib;

    /**
     * \brief CLKSEL.
     */
    CLKSEL clksel;

    union {
        /**
         * \brief Count (CNT) register.
         */
        Register<std::uint16_t> cnt;

        struct {
            /**
             * \brief Count Low Byte (CNTL) register.
             */
            Register<std::uint8_t> cntl;

            /**
             * \brief Count High Byte (CNTH) register.
             */
            Register<std::uint8_t> cnth;
        };
    };

    union {
        /**
         * \brief Period (PER) register.
         */
        Register<std::uint16_t> per;

        struct {
            /**
             * \brief Period Low Byte (PERL) register.
             */
            Register<std::uint8_t> perl;

            /**
             * \brief Period High Byte (PERH) register.
             */
            Register<std::uint8_t> perh;
        };
    };

    union {
        /**
         * \brief Compare (CMP) register.
         */
        Register<std::uint16_t> cmp;

        struct {
            /**
             * \brief Compare Low Byte (CMPL) register.
             */
            Register<std::uint8_t> cmpl;

            /**
             * \brief Compare High Byte (CMPH) register.
             */
            Register<std::uint8_t> cmph;
        };
    };

    /**
     * \brief Reserved registers (offset 0x0E-0x0F).
     */
    Reserved_Register<std::uint8_t> const reserved_0x0E_0x0F[ ( 0x0F - 0x0E ) + 1 ];

    /**
     * \brief PITCTRLA.
     */
    PITCTRLA pitctrla;

    /**
     * \brief PITSTATUS.
     */
    PITSTATUS const pitstatus;

    /**
     * \brief PITINTCTRL.
     */
    PITINTCTRL pitintctrl;

    /**
     * \brief PITINTFLAGS.
     */
    PITINTFLAGS pitintflags;

    /**
     * \brief Reserved registers (offset 0x14-0x14).
     */
    Reserved_Register<std::uint8_t> const reserved_0x14_0x14[ ( 0x14 - 0x14 ) + 1 ];

    /**
     * \brief PITDBGCTRL.
     */
    PITDBGCTRL pitdbgctrl;

    RTC() = delete;

    RTC( RTC && ) = delete;

    RTC( RTC const & ) = delete;

    ~RTC() = delete;

    auto operator=( RTC && ) = delete;

    auto operator=( RTC const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_RTC_H
