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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_CLKCTRL_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_CLKCTRL_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr0/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series Clock Controller (CLKCTRL) peripheral.
 */
class CLKCTRL {
  public:
    /**
     * \brief Main Clock Control A (MCLKCTRLA) register.
     *
     * This register has the following fields:
     * - Clock Select (CLKSEL)
     * - System Clock Out (CLKOUT)
     */
    class MCLKCTRLA : public Protected_Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto CLKSEL    = std::uint_fast8_t{ 2 }; ///< CLKSEL.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ 5 }; ///< RESERVED2.
            static constexpr auto CLKOUT    = std::uint_fast8_t{ 1 }; ///< CLKOUT.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto CLKSEL = std::uint_fast8_t{}; ///< CLKSEL.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ CLKSEL + Size::CLKSEL }; ///< RESERVED2.
            static constexpr auto CLKOUT = std::uint_fast8_t{ RESERVED2 + Size::RESERVED2 }; ///< CLKOUT.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto CLKSEL = mask<std::uint8_t>( Size::CLKSEL, Bit::CLKSEL ); ///< CLKSEL.
            static constexpr auto RESERVED2 = mask<std::uint8_t>( Size::RESERVED2, Bit::RESERVED2 ); ///< RESERVED2.
            static constexpr auto CLKOUT = mask<std::uint8_t>( Size::CLKOUT, Bit::CLKOUT ); ///< CLKOUT.
        };

        MCLKCTRLA() = delete;

        MCLKCTRLA( MCLKCTRLA && ) = delete;

        MCLKCTRLA( MCLKCTRLA const & ) = delete;

        ~MCLKCTRLA() = delete;

        auto operator=( MCLKCTRLA && ) = delete;

        auto operator=( MCLKCTRLA const & ) = delete;

        using Protected_Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Main Clock Control B (MCLKCTRLB) register.
     *
     * This register has the following fields:
     * - Prescaler Enable (PEN)
     * - Prescaler Division (PDIV)
     */
    class MCLKCTRLB : public Protected_Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto PEN       = std::uint_fast8_t{ 1 }; ///< PEN.
            static constexpr auto PDIV      = std::uint_fast8_t{ 4 }; ///< PDIV.
            static constexpr auto RESERVED5 = std::uint_fast8_t{ 3 }; ///< RESERVED5.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto PEN  = std::uint_fast8_t{};                  ///< PEN.
            static constexpr auto PDIV = std::uint_fast8_t{ PEN + Size::PEN }; ///< PDIV.
            static constexpr auto RESERVED5 = std::uint_fast8_t{ PDIV + Size::PDIV }; ///< RESERVED5.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto PEN = mask<std::uint8_t>( Size::PEN, Bit::PEN ); ///< PEN.
            static constexpr auto PDIV = mask<std::uint8_t>( Size::PDIV, Bit::PDIV ); ///< PDIV.
            static constexpr auto RESERVED5 = mask<std::uint8_t>( Size::RESERVED5, Bit::RESERVED5 ); ///< RESERVED5.
        };

        MCLKCTRLB() = delete;

        MCLKCTRLB( MCLKCTRLB && ) = delete;

        MCLKCTRLB( MCLKCTRLB const & ) = delete;

        ~MCLKCTRLB() = delete;

        auto operator=( MCLKCTRLB && ) = delete;

        auto operator=( MCLKCTRLB const & ) = delete;

        using Protected_Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Main Clock Lock (MCLKLOCK) register.
     *
     * This register has the following fields:
     * - Lock Enable (LOCKEN)
     */
    class MCLKLOCK : public Protected_Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto LOCKEN    = std::uint_fast8_t{ 1 }; ///< LOCKEN.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 7 }; ///< RESERVED1.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto LOCKEN = std::uint_fast8_t{}; ///< LOCKEN.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ LOCKEN + Size::LOCKEN }; ///< RESERVED1.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto LOCKEN = mask<std::uint8_t>( Size::LOCKEN, Bit::LOCKEN ); ///< LOCKEN.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
        };

        MCLKLOCK() = delete;

        MCLKLOCK( MCLKLOCK && ) = delete;

        MCLKLOCK( MCLKLOCK const & ) = delete;

        ~MCLKLOCK() = delete;

        auto operator=( MCLKLOCK && ) = delete;

        auto operator=( MCLKLOCK const & ) = delete;

        using Protected_Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Main Clock Status (MCLKSTATUS) register.
     *
     * This register has the following fields:
     * - Main Clock Oscillator Changing (SOSC)
     * - OSC20M Status (OSC20MS)
     * - OSCULP32K Status (OSC32KS)
     * - XOSC32K Status (OSC32KS)
     * - External Clock Status (EXTS)
     */
    class MCLKSTATUS : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto SOSC      = std::uint_fast8_t{ 1 }; ///< SOSC.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 3 }; ///< RESERVED1.
            static constexpr auto OSC20MS   = std::uint_fast8_t{ 1 }; ///< OSC20MS.
            static constexpr auto OSC32KS   = std::uint_fast8_t{ 1 }; ///< OSC32KS.
            static constexpr auto XOSC32KS  = std::uint_fast8_t{ 1 }; ///< XOSC32KS.
            static constexpr auto EXTS      = std::uint_fast8_t{ 1 }; ///< EXTS.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto SOSC = std::uint_fast8_t{}; ///< SOSC.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ SOSC + Size::SOSC }; ///< RESERVED1.
            static constexpr auto OSC20MS = std::uint_fast8_t{ RESERVED1 + Size::RESERVED1 }; ///< OSC20MS.
            static constexpr auto OSC32KS = std::uint_fast8_t{ OSC20MS + Size::OSC20MS }; ///< OSC32KS.
            static constexpr auto XOSC32KS = std::uint_fast8_t{ OSC32KS + Size::OSC32KS }; ///< XOSC32KS.
            static constexpr auto EXTS = std::uint_fast8_t{ XOSC32KS + Size::XOSC32KS }; ///< EXTS.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto SOSC = mask<std::uint8_t>( Size::SOSC, Bit::SOSC ); ///< SOSC.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
            static constexpr auto OSC20MS = mask<std::uint8_t>( Size::OSC20MS, Bit::OSC20MS ); ///< OSC20MS.
            static constexpr auto OSC32KS = mask<std::uint8_t>( Size::OSC32KS, Bit::OSC32KS ); ///< OSC32KS.
            static constexpr auto XOSC32KS = mask<std::uint8_t>( Size::XOSC32KS, Bit::XOSC32KS ); ///< XOSC32KS.
            static constexpr auto EXTS = mask<std::uint8_t>( Size::EXTS, Bit::EXTS ); ///< EXTS.
        };

        MCLKSTATUS() = delete;

        MCLKSTATUS( MCLKSTATUS && ) = delete;

        MCLKSTATUS( MCLKSTATUS const & ) = delete;

        ~MCLKSTATUS() = delete;

        auto operator=( MCLKSTATUS && ) = delete;

        auto operator=( MCLKSTATUS const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief 16/20 MHz Oscillator Control A (OSC20MCTRLA) register.
     *
     * This register has the following fields:
     * - Run Standby (RUNSTDBY)
     */
    class OSC20MCTRLA : public Protected_Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto RESERVED0 = std::uint_fast8_t{ 1 }; ///< RESERVED0.
            static constexpr auto RUNSTDBY  = std::uint_fast8_t{ 1 }; ///< RUNSTDBY.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ 6 }; ///< RESERVED2.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto RESERVED0 = std::uint_fast8_t{}; ///< RESERVED0.
            static constexpr auto RUNSTDBY = std::uint_fast8_t{ RESERVED0 + Size::RESERVED0 }; ///< RUNSTDBY.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ RUNSTDBY + Size::RUNSTDBY }; ///< RESERVED2.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto RESERVED0 = mask<std::uint8_t>( Size::RESERVED0, Bit::RESERVED0 ); ///< RESERVED0.
            static constexpr auto RUNSTDBY = mask<std::uint8_t>( Size::RUNSTDBY, Bit::RUNSTDBY ); ///< RUNSTDBY.
            static constexpr auto RESERVED2 = mask<std::uint8_t>( Size::RESERVED2, Bit::RESERVED2 ); ///< RESERVED2.
        };

        OSC20MCTRLA() = delete;

        OSC20MCTRLA( OSC20MCTRLA && ) = delete;

        OSC20MCTRLA( OSC20MCTRLA const & ) = delete;

        ~OSC20MCTRLA() = delete;

        auto operator=( OSC20MCTRLA && ) = delete;

        auto operator=( OSC20MCTRLA const & ) = delete;

        using Protected_Register<std::uint8_t>::operator=;
    };

    /**
     * \brief 16/20 MHz Oscillator Calibration A (OSC20MCALIBA) register.
     *
     * This register has the following fields:
     * - Calibration (CAL20M)
     */
    class OSC20MCALIBA : public Protected_Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto CAL20M    = std::uint_fast8_t{ 7 }; ///< CAL20M.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ 1 }; ///< RESERVED7.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto CAL20M = std::uint_fast8_t{}; ///< CAL20M.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ CAL20M + Size::CAL20M }; ///< RESERVED7.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto CAL20M = mask<std::uint8_t>( Size::CAL20M, Bit::CAL20M ); ///< CAL20M.
            static constexpr auto RESERVED7 = mask<std::uint8_t>( Size::RESERVED7, Bit::RESERVED7 ); ///< RESERVED7.
        };

        OSC20MCALIBA() = delete;

        OSC20MCALIBA( OSC20MCALIBA && ) = delete;

        OSC20MCALIBA( OSC20MCALIBA const & ) = delete;

        ~OSC20MCALIBA() = delete;

        auto operator=( OSC20MCALIBA && ) = delete;

        auto operator=( OSC20MCALIBA const & ) = delete;

        using Protected_Register<std::uint8_t>::operator=;
    };

    /**
     * \brief 16/20 MHz Oscillator Calibration B (OSC20MCALIBB) register.
     *
     * This register has the following fields:
     * - Oscillator Temperature Coefficient Calibration (TEMPCAL20M)
     * - Oscillator Calibration Locked by Fuse (LOCK)
     */
    class OSC20MCALIBB : public Protected_Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto TEMPCAL20M = std::uint_fast8_t{ 4 }; ///< TEMPCAL20M.
            static constexpr auto RESERVED4  = std::uint_fast8_t{ 3 }; ///< RESERVED4.
            static constexpr auto LOCK       = std::uint_fast8_t{ 1 }; ///< LOCK.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto TEMPCAL20M = std::uint_fast8_t{}; ///< TEMPCAL20M.
            static constexpr auto RESERVED4 = std::uint_fast8_t{ TEMPCAL20M + Size::TEMPCAL20M }; ///< RESERVED4.
            static constexpr auto LOCK = std::uint_fast8_t{ RESERVED4 + Size::RESERVED4 }; ///< LOCK.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto TEMPCAL20M = mask<std::uint8_t>( Size::TEMPCAL20M, Bit::TEMPCAL20M ); ///< TEMPCAL20M.
            static constexpr auto RESERVED4 = mask<std::uint8_t>( Size::RESERVED4, Bit::RESERVED4 ); ///< RESERVED4.
            static constexpr auto LOCK = mask<std::uint8_t>( Size::LOCK, Bit::LOCK ); ///< LOCK.
        };

        OSC20MCALIBB() = delete;

        OSC20MCALIBB( OSC20MCALIBB && ) = delete;

        OSC20MCALIBB( OSC20MCALIBB const & ) = delete;

        ~OSC20MCALIBB() = delete;

        auto operator=( OSC20MCALIBB && ) = delete;

        auto operator=( OSC20MCALIBB const & ) = delete;

        using Protected_Register<std::uint8_t>::operator=;
    };

    /**
     * \brief 32.768 kHz Oscillator Control A (OSC32KCTRLA) register.
     *
     * This register has the following fields:
     * - Run Standby (RUNSTBY)
     */
    class OSC32KCTRLA : public Protected_Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto RESERVED0 = std::uint_fast8_t{ 1 }; ///< RESERVED0.
            static constexpr auto RUNSTDBY  = std::uint_fast8_t{ 1 }; ///< RUNSTDBY.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ 6 }; ///< RESERVED2.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto RESERVED0 = std::uint_fast8_t{}; ///< RESERVED0.
            static constexpr auto RUNSTDBY = std::uint_fast8_t{ RESERVED0 + Size::RESERVED0 }; ///< RUNSTDBY.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ RUNSTDBY + Size::RUNSTDBY }; ///< RESERVED2.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto RESERVED0 = mask<std::uint8_t>( Size::RESERVED0, Bit::RESERVED0 ); ///< RESERVED0.
            static constexpr auto RUNSTDBY = mask<std::uint8_t>( Size::RUNSTDBY, Bit::RUNSTDBY ); ///< RUNSTDBY.
            static constexpr auto RESERVED2 = mask<std::uint8_t>( Size::RESERVED2, Bit::RESERVED2 ); ///< RESERVED2.
        };

        OSC32KCTRLA() = delete;

        OSC32KCTRLA( OSC32KCTRLA && ) = delete;

        OSC32KCTRLA( OSC32KCTRLA const & ) = delete;

        ~OSC32KCTRLA() = delete;

        auto operator=( OSC32KCTRLA && ) = delete;

        auto operator=( OSC32KCTRLA const & ) = delete;

        using Protected_Register<std::uint8_t>::operator=;
    };

    /**
     * \brief 32.768 kHz Crystal Oscillator Control A (XOSC32KCTRLA) register.
     *
     * This register has the following fields:
     * - Enable (ENABLE)
     * - Run Standby (RUNSTDBY)
     * - Source Select (SEL)
     * - Crystal Start-Up Time (CSUT)
     */
    class XOSC32KCTRLA : public Protected_Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto ENABLE    = std::uint_fast8_t{ 1 }; ///< ENABLE.
            static constexpr auto RUNSTDBY  = std::uint_fast8_t{ 1 }; ///< RUNSTDBY.
            static constexpr auto SEL       = std::uint_fast8_t{ 1 }; ///< SEL.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ 1 }; ///< RESERVED3.
            static constexpr auto CSUT      = std::uint_fast8_t{ 2 }; ///< CSUT.
            static constexpr auto RESERVED6 = std::uint_fast8_t{ 2 }; ///< RESERVED6.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto ENABLE = std::uint_fast8_t{}; ///< ENABLE.
            static constexpr auto RUNSTDBY = std::uint_fast8_t{ ENABLE + Size::ENABLE }; ///< RUNSTDBY.
            static constexpr auto SEL = std::uint_fast8_t{ RUNSTDBY + Size::RUNSTDBY }; ///< SEL.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ SEL + Size::SEL }; ///< RESERVED3.
            static constexpr auto CSUT = std::uint_fast8_t{ RESERVED3 + Size::RESERVED3 }; ///< CSUT.
            static constexpr auto RESERVED6 = std::uint_fast8_t{ CSUT + Size::CSUT }; ///< RESERVED6.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto ENABLE = mask<std::uint8_t>( Size::ENABLE, Bit::ENABLE ); ///< ENABLE.
            static constexpr auto RUNSTDBY = mask<std::uint8_t>( Size::RUNSTDBY, Bit::RUNSTDBY ); ///< RUNSTDBY.
            static constexpr auto SEL = mask<std::uint8_t>( Size::SEL, Bit::SEL ); ///< SEL.
            static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
            static constexpr auto CSUT = mask<std::uint8_t>( Size::CSUT, Bit::CSUT ); ///< CSUT.
            static constexpr auto RESERVED6 = mask<std::uint8_t>( Size::RESERVED6, Bit::RESERVED6 ); ///< RESERVED6.
        };

        XOSC32KCTRLA() = delete;

        XOSC32KCTRLA( XOSC32KCTRLA && ) = delete;

        XOSC32KCTRLA( XOSC32KCTRLA const & ) = delete;

        ~XOSC32KCTRLA() = delete;

        auto operator=( XOSC32KCTRLA && ) = delete;

        auto operator=( XOSC32KCTRLA const & ) = delete;

        using Protected_Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Clock source.
     */
    enum class Source : std::uint8_t {
        INTERNAL_16_20_MHZ_OSCILLATOR = 0x0 << MCLKCTRLA::Bit::CLKSEL, ///< Internal 16/20 MHz oscillator.
        INTERNAL_32_768_KHZ_ULTRA_LOW_POWER_OSCILLATOR = 0x1 << MCLKCTRLA::Bit::CLKSEL, ///< Internal 32.768 kHz ultra low-power oscillator.
        EXTERNAL_32_768_KHZ_CRYSTAL_OSCILLATOR = 0x2 << MCLKCTRLA::Bit::CLKSEL, ///< External 32.768 kHz crystal oscillator.
        EXTERNAL_CLOCK = 0x3 << MCLKCTRLA::Bit::CLKSEL, ///< External clock.
    };

    /**
     * \brief Clock prescaler configuration.
     */
    enum class Prescaler : std::uint8_t {
        DISABLED = 0b0 << MCLKCTRLB::Bit::PEN, ///< Disabled.
        ENABLED  = 0b1 << MCLKCTRLB::Bit::PEN, ///< Enabled.
    };

    /**
     * \brief Clock prescaler value.
     */
    enum class Prescaler_Value : std::uint8_t {
        _2  = 0x0 << MCLKCTRLB::Bit::PDIV, ///< 2.
        _4  = 0x1 << MCLKCTRLB::Bit::PDIV, ///< 4.
        _6  = 0x8 << MCLKCTRLB::Bit::PDIV, ///< 6.
        _8  = 0x2 << MCLKCTRLB::Bit::PDIV, ///< 8.
        _10 = 0x9 << MCLKCTRLB::Bit::PDIV, ///< 10.
        _12 = 0xA << MCLKCTRLB::Bit::PDIV, ///< 12.
        _16 = 0x3 << MCLKCTRLB::Bit::PDIV, ///< 16.
        _24 = 0xB << MCLKCTRLB::Bit::PDIV, ///< 24.
        _32 = 0x4 << MCLKCTRLB::Bit::PDIV, ///< 32.
        _48 = 0xC << MCLKCTRLB::Bit::PDIV, ///< 48.
        _64 = 0x5 << MCLKCTRLB::Bit::PDIV, ///< 64.
    };

    /**
     * \brief Internal 16/20 MHz oscillator mode.
     */
    enum class Internal_16_20_MHz_Oscillator_Mode : std::uint8_t {
        NORMAL    = 0b0 << OSC20MCTRLA::Bit::RUNSTDBY, ///< Normal.
        FORCED_ON = 0b1 << OSC20MCTRLA::Bit::RUNSTDBY, ///< Forced on.
    };

    /**
     * \brief Internal 32.768 kHz ultra low-power oscillator mode.
     */
    enum class Internal_32_768_kHz_Ultra_Low_Power_Oscillator_Mode : std::uint8_t {
        NORMAL    = 0b0 << OSC32KCTRLA::Bit::RUNSTDBY, ///< Normal.
        FORCED_ON = 0b1 << OSC32KCTRLA::Bit::RUNSTDBY, ///< Forced on.
    };

    /**
     * \brief External 32.768 kHz crystal oscillator source.
     */
    enum class External_32_768_kHz_Crystal_Oscillator_Source : std::uint8_t {
        CRYSTAL = 0b0 << XOSC32KCTRLA::Bit::SEL, ///< Crystal.
        CLOCK   = 0b1 << XOSC32KCTRLA::Bit::SEL, ///< Clock.
    };

    /**
     * \brief External 32.768 kHz crystal oscillator start-up time.
     */
    enum class External_32_768_kHz_Crystal_Oscillator_Start_Up_Time : std::uint8_t {
        _1K  = 0x0 << XOSC32KCTRLA::Bit::CSUT, ///< 1k cycles.
        _16K = 0x1 << XOSC32KCTRLA::Bit::CSUT, ///< 16k cycles.
        _32K = 0x2 << XOSC32KCTRLA::Bit::CSUT, ///< 32k cycles.
        _64K = 0x3 << XOSC32KCTRLA::Bit::CSUT, ///< 64k cycles.
    };

    /**
     * \brief External 32.768 kHz crystal oscillator mode.
     */
    enum class External_32_768_kHz_Crystal_Oscillator_Mode : std::uint8_t {
        NORMAL    = 0b0 << XOSC32KCTRLA::Bit::RUNSTDBY, ///< Normal.
        FORCED_ON = 0b1 << XOSC32KCTRLA::Bit::RUNSTDBY, ///< Forced on.
    };

    /**
     * \brief MCLKCTRLA.
     */
    MCLKCTRLA mclkctrla;

    /**
     * \brief MCLKCTRLB.
     */
    MCLKCTRLB mclkctrlb;

    /**
     * \brief MCLKLOCK.
     */
    MCLKLOCK mclklock;

    /**
     * \brief MCLKSTATUS.
     */
    MCLKSTATUS const mclkstatus;

    /**
     * \brief Reserved registers (offset 0x04-0x0F).
     */
    Reserved_Register<std::uint8_t> const reserved_0x04_0x0F[ ( 0x0F - 0x04 ) + 1 ];

    /**
     * \brief OSC20MCTRLA.
     */
    OSC20MCTRLA osc20mctrla;

    /**
     * \brief OSC20MCALIBA.
     */
    OSC20MCALIBA osc20mcaliba;

    /**
     * \brief OSC20MCALIBB.
     */
    OSC20MCALIBB osc20mcalibb;

    /**
     * \brief Reserved registers (offset 0x13-0x17).
     */
    Reserved_Register<std::uint8_t> const reserved_0x13_0x17[ ( 0x17 - 0x13 ) + 1 ];

    /**
     * \brief OSC32KCTRLA.
     */
    OSC32KCTRLA osc32kctrla;

    /**
     * \brief Reserved registers (offset 0x19-0x1B).
     */
    Reserved_Register<std::uint8_t> const reserved_0x19_0x1B[ ( 0x1B - 0x19 ) + 1 ];

    /**
     * \brief XOSC32KCTRLA.
     */
    XOSC32KCTRLA xosc32kctrla;

    CLKCTRL() = delete;

    CLKCTRL( CLKCTRL && ) = delete;

    CLKCTRL( CLKCTRL const & ) = delete;

    ~CLKCTRL() = delete;

    auto operator=( CLKCTRL && ) = delete;

    auto operator=( CLKCTRL const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_CLKCTRL_H
