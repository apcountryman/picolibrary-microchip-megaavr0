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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_CLKCTRL_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_CLKCTRL_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr0/peripheral/instance.h"
#include "picolibrary/microchip/megaavr0/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series Clock Controller (CLKCTRL) peripheral.
 */
class CLKCTRL {
  public:
    enum class Source : std::uint8_t;

    enum class Prescaler : std::uint8_t;

    enum class Prescaler_Value : std::uint8_t;

    enum class Internal_16_20_MHz_Oscillator_Mode : std::uint8_t;

    enum class Internal_32_768_kHz_Ultra_Low_Power_Oscillator_Mode : std::uint8_t;

    enum class External_32_768_kHz_Crystal_Oscillator_Source : std::uint8_t;

    enum class External_32_768_kHz_Crystal_Oscillator_Start_Up_Time : std::uint8_t;

    enum class External_32_768_kHz_Crystal_Oscillator_Mode : std::uint8_t;

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
            static constexpr auto CLKSEL   = std::uint_fast8_t{ 2 }; ///< CLKSEL.
            static constexpr auto RESERVED = std::uint_fast8_t{ 5 }; ///< Reserved.
            static constexpr auto CLKOUT   = std::uint_fast8_t{ 1 }; ///< CLKOUT.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto CLKSEL = std::uint_fast8_t{}; ///< CLKSEL.
            static constexpr auto RESERVED = std::uint_fast8_t{ CLKSEL + Size::CLKSEL }; ///< Reserved.
            static constexpr auto CLKOUT = std::uint_fast8_t{ RESERVED + Size::RESERVED }; ///< CLKOUT.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto CLKSEL = mask<std::uint8_t>( Size::CLKSEL, Bit::CLKSEL ); ///< CLKSEL.
            static constexpr auto RESERVED = mask<std::uint8_t>( Size::RESERVED, Bit::RESERVED ); ///< Reserved.
            static constexpr auto CLKOUT = mask<std::uint8_t>( Size::CLKOUT, Bit::CLKOUT ); ///< CLKOUT.
        };

        MCLKCTRLA() = delete;

        MCLKCTRLA( MCLKCTRLA && ) = delete;

        MCLKCTRLA( MCLKCTRLA const & ) = delete;

        ~MCLKCTRLA() = delete;

        auto operator=( MCLKCTRLA && ) = delete;

        auto operator=( MCLKCTRLA const & ) = delete;

        using Protected_Register<std::uint8_t>::operator=;

        /**
         * \brief Get the clock source.
         *
         * \return The clock source.
         */
        auto source() const noexcept
        {
            return static_cast<Source>( *this & Mask::CLKSEL );
        }

        /**
         * \brief Set the clock source.
         *
         * \param[in] source The desired clock source.
         */
        void set_source( Source source ) noexcept
        {
            *this = ( *this & ~Mask::CLKSEL ) | static_cast<std::uint8_t>( source );
        }

        /**
         * \brief Check if clock output is enabled.
         *
         * \return true if clock output is enabled.
         * \return false if clock output is not enabled.
         */
        auto output_enabled() const noexcept -> bool
        {
            return *this & Mask::CLKOUT;
        }

        /**
         * \brief Enable clock output.
         */
        void enable_output() noexcept
        {
            *this |= Mask::CLKOUT;
        }

        /**
         * \brief Disable clock output.
         */
        void disable_output() noexcept
        {
            *this &= static_cast<std::uint8_t>( ~Mask::CLKOUT );
        }
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
            static constexpr auto PEN      = std::uint_fast8_t{ 1 }; ///< PEN.
            static constexpr auto PDIV     = std::uint_fast8_t{ 4 }; ///< PDIV.
            static constexpr auto RESERVED = std::uint_fast8_t{ 3 }; ///< Reserved.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto PEN  = std::uint_fast8_t{};                  ///< PEN.
            static constexpr auto PDIV = std::uint_fast8_t{ PEN + Size::PEN }; ///< PDIV.
            static constexpr auto RESERVED = std::uint_fast8_t{ PDIV + Size::PDIV }; ///< Reserved.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto PEN = mask<std::uint8_t>( Size::PEN, Bit::PEN ); ///< PEN.
            static constexpr auto PDIV = mask<std::uint8_t>( Size::PDIV, Bit::PDIV ); ///< PDIV.
            static constexpr auto RESERVED = mask<std::uint8_t>( Size::RESERVED, Bit::RESERVED ); ///< Reserved.
        };

        MCLKCTRLB() = delete;

        MCLKCTRLB( MCLKCTRLB && ) = delete;

        MCLKCTRLB( MCLKCTRLB const & ) = delete;

        ~MCLKCTRLB() = delete;

        auto operator=( MCLKCTRLB && ) = delete;

        auto operator=( MCLKCTRLB const & ) = delete;

        using Protected_Register<std::uint8_t>::operator=;

        /**
         * \brief Check if the clock prescaler is enabled.
         *
         * \return true if the clock prescaler is enabled.
         * \return false if the clock prescaler is not enabled.
         */
        auto prescaler_enabled() const noexcept -> bool
        {
            return *this & Mask::PEN;
        }

        /**
         * \brief Get the clock prescaler value.
         *
         * \return The clock prescaler value.
         */
        auto prescaler_value() const noexcept
        {
            return static_cast<Prescaler_Value>( *this & Mask::PDIV );
        }

        /**
         * \brief Configure the clock prescaler.
         *
         * \param[in] value The desired clock prescaler value.
         * \param[in] configuration The desired clock prescaler configuration.
         */
        void configure_prescaler( Prescaler_Value value, Prescaler configuration ) noexcept
        {
            *this = static_cast<std::uint8_t>( value ) | static_cast<std::uint8_t>( configuration );
        }

        /**
         * \brief Enable the prescaler.
         */
        void enable_prescaler() noexcept
        {
            *this |= Mask::PEN;
        }

        /**
         * \brief Enable the prescaler.
         */
        void disable_prescaler() noexcept
        {
            *this &= ~Mask::PEN;
        }
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
            static constexpr auto LOCKEN   = std::uint_fast8_t{ 1 }; ///< LOCKEN.
            static constexpr auto RESERVED = std::uint_fast8_t{ 7 }; ///< Reserved.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto LOCKEN = std::uint_fast8_t{}; ///< LOCKEN.
            static constexpr auto RESERVED = std::uint_fast8_t{ LOCKEN + Size::LOCKEN }; ///< Reserved.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto LOCKEN = mask<std::uint8_t>( Size::LOCKEN, Bit::LOCKEN ); ///< LOCKEN.
            static constexpr auto RESERVED = mask<std::uint8_t>( Size::RESERVED, Bit::RESERVED ); ///< Reserved.
        };

        MCLKLOCK() = delete;

        MCLKLOCK( MCLKLOCK && ) = delete;

        MCLKLOCK( MCLKLOCK const & ) = delete;

        ~MCLKLOCK() = delete;

        auto operator=( MCLKLOCK && ) = delete;

        auto operator=( MCLKLOCK const & ) = delete;

        using Protected_Register<std::uint8_t>::operator=;

        /**
         * \brief Check if the clock configuration is locked.
         *
         * \return true if the clock configuration is locked.
         * \return false if the clock configuration is not locked.
         */
        auto configuration_locked() const noexcept -> bool
        {
            return *this & Mask::LOCKEN;
        }

        /**
         * \brief Lock the clock configuration.
         */
        void lock_configuration() noexcept
        {
            *this = Mask::LOCKEN;
        }
    };

    /**
     * \brief Main Clock Status (MCLKSTATUS) register.
     *
     * This register has the following fields:
     * - Main Clock Oscillator Changing (SOSC)
     * - OSC20M Status (OSC20MS)
     * - OSCULP32K Status (OSC32KS)
     * - XOSC32K Status (XOSC32KS)
     * - External Clock Status (EXTS)
     */
    class MCLKSTATUS : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto SOSC     = std::uint_fast8_t{ 1 }; ///< SOSC.
            static constexpr auto RESERVED = std::uint_fast8_t{ 3 }; ///< Reserved.
            static constexpr auto OSC20MS  = std::uint_fast8_t{ 1 }; ///< OSC20MS.
            static constexpr auto OSC32KS  = std::uint_fast8_t{ 1 }; ///< OSC32KS.
            static constexpr auto XOSC32KS = std::uint_fast8_t{ 1 }; ///< XOSC32KS.
            static constexpr auto EXTS     = std::uint_fast8_t{ 1 }; ///< EXTS.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto SOSC = std::uint_fast8_t{}; ///< SOSC.
            static constexpr auto RESERVED = std::uint_fast8_t{ SOSC + Size::SOSC }; ///< Reserved.
            static constexpr auto OSC20MS = std::uint_fast8_t{ RESERVED + Size::RESERVED }; ///< OSC20MS.
            static constexpr auto OSC32KS = std::uint_fast8_t{ OSC20MS + Size::OSC20MS }; ///< OSC32KS.
            static constexpr auto XOSC32KS = std::uint_fast8_t{ OSC32KS + Size::OSC32KS }; ///< XOSC32KS.
            static constexpr auto EXTS = std::uint_fast8_t{ XOSC32KS + Size::XOSC32KS }; ///< EXTS.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto SOSC = mask<std::uint8_t>( Size::SOSC, Bit::SOSC ); ///< SOSC.
            static constexpr auto RESERVED = mask<std::uint8_t>( Size::RESERVED, Bit::RESERVED ); ///< Reserved.
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

        /**
         * \brief Check if the clock source is changing.
         *
         * \return true if the clock source is changing.
         * \return false if the clock source is not changing.
         */
        auto source_changing() const noexcept -> bool
        {
            return *this & Mask::SOSC;
        }

        /**
         * \brief Check if the internal 16/20 MHz oscillator is stable.
         *
         * \return true if the internal 16/20 MHz oscillator is stable.
         * \return false if the internal 16/20 MHz oscillator is not stable.
         */
        auto internal_16_20_mhz_oscillator_stable() const noexcept -> bool
        {
            return *this & Mask::OSC20MS;
        }

        /**
         * \brief Check if the internal 32.768 kHz ultra low-power oscillator is stable.
         *
         * \return true if the internal 32.768 kHz ultra low-power oscillator is stable.
         * \return false if the internal 32.768 kHz ultra low-power oscillator is not
         *         stable.
         */
        auto internal_32_768_khz_ultra_low_power_oscillator_stable() const noexcept -> bool
        {
            return *this & Mask::OSC32KS;
        }

        /**
         * \brief Check if the external 32.768 kHz crystal oscillator is stable.
         *
         * \return true if the external 32.768 kHz crystal oscillator is stable.
         * \return false if the external 32.768 kHz crystal oscillator is not stable.
         */
        auto external_32_768_khz_crystal_oscillator_stable() const noexcept -> bool
        {
            return *this & Mask::XOSC32KS;
        }

        /**
         * \brief Check if the external clock is stable.
         *
         * \return true if the external clock is stable.
         * \return false if the external clock is not stable.
         */
        auto external_clock_stable() const noexcept -> bool
        {
            return *this & Mask::EXTS;
        }
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
            static constexpr auto RESERVED0 = std::uint_fast8_t{ 1 }; ///< Reserved.
            static constexpr auto RUNSTDBY  = std::uint_fast8_t{ 1 }; ///< RUNSTDBY.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ 6 }; ///< Reserved.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto RESERVED0 = std::uint_fast8_t{}; ///< Reserved.
            static constexpr auto RUNSTDBY = std::uint_fast8_t{ RESERVED0 + Size::RESERVED0 }; ///< RUNSTDBY.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ RUNSTDBY + Size::RUNSTDBY }; ///< Reserved.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto RESERVED0 = mask<std::uint8_t>( Size::RESERVED0, Bit::RESERVED0 ); ///< Reserved.
            static constexpr auto RUNSTDBY = mask<std::uint8_t>( Size::RUNSTDBY, Bit::RUNSTDBY ); ///< RUNSTDBY.
            static constexpr auto RESERVED2 = mask<std::uint8_t>( Size::RESERVED2, Bit::RESERVED2 ); ///< Reserved.
        };

        OSC20MCTRLA() = delete;

        OSC20MCTRLA( OSC20MCTRLA && ) = delete;

        OSC20MCTRLA( OSC20MCTRLA const & ) = delete;

        ~OSC20MCTRLA() = delete;

        auto operator=( OSC20MCTRLA && ) = delete;

        auto operator=( OSC20MCTRLA const & ) = delete;

        using Protected_Register<std::uint8_t>::operator=;

        /**
         * \brief Get the internal 16/20 MHz oscillator mode.
         *
         * \return The internal 16/20 MHz oscillator mode.
         */
        auto internal_16_20_mhz_oscillator_mode() const noexcept
        {
            return static_cast<Internal_16_20_MHz_Oscillator_Mode>( *this & Mask::RUNSTDBY );
        }

        /**
         * \brief Set the internal 16/20 MHz oscillator mode.
         *
         * \param[in] mode The desired internal 16/20 MHz oscillator mode.
         */
        void set_internal_16_20_mhz_oscillator_mode( Internal_16_20_MHz_Oscillator_Mode mode ) noexcept
        {
            *this = static_cast<std::uint8_t>( mode );
        }
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
            static constexpr auto CAL20M   = std::uint_fast8_t{ 7 }; ///< CAL20M.
            static constexpr auto RESERVED = std::uint_fast8_t{ 1 }; ///< Reserved.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto CAL20M = std::uint_fast8_t{}; ///< CAL20M.
            static constexpr auto RESERVED = std::uint_fast8_t{ CAL20M + Size::CAL20M }; ///< Reserved.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto CAL20M = mask<std::uint8_t>( Size::CAL20M, Bit::CAL20M ); ///< CAL20M.
            static constexpr auto RESERVED = mask<std::uint8_t>( Size::RESERVED, Bit::RESERVED ); ///< Reserved.
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
            static constexpr auto RESERVED   = std::uint_fast8_t{ 3 }; ///< Reserved.
            static constexpr auto LOCK       = std::uint_fast8_t{ 1 }; ///< LOCK.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto TEMPCAL20M = std::uint_fast8_t{}; ///< TEMPCAL20M.
            static constexpr auto RESERVED = std::uint_fast8_t{ TEMPCAL20M + Size::TEMPCAL20M }; ///< Reserved.
            static constexpr auto LOCK = std::uint_fast8_t{ RESERVED + Size::RESERVED }; ///< LOCK.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto TEMPCAL20M = mask<std::uint8_t>( Size::TEMPCAL20M, Bit::TEMPCAL20M ); ///< TEMPCAL20M.
            static constexpr auto RESERVED = mask<std::uint8_t>( Size::RESERVED, Bit::RESERVED ); ///< Reserved.
            static constexpr auto LOCK = mask<std::uint8_t>( Size::LOCK, Bit::LOCK ); ///< LOCK.
        };

        OSC20MCALIBB() = delete;

        OSC20MCALIBB( OSC20MCALIBB && ) = delete;

        OSC20MCALIBB( OSC20MCALIBB const & ) = delete;

        ~OSC20MCALIBB() = delete;

        auto operator=( OSC20MCALIBB && ) = delete;

        auto operator=( OSC20MCALIBB const & ) = delete;

        using Protected_Register<std::uint8_t>::operator=;

        /**
         * \brief Check if the internal 16/20 MHz oscillator calibration is locked.
         *
         * \return true if the internal 16/20 MHz oscillator calibration is locked.
         * \return false if the internal 16/20 MHz oscillator calibration is not locked.
         */
        auto internal_16_20_mhz_oscillator_calibration_locked() const noexcept -> bool
        {
            return *this & Mask::LOCK;
        }
    };

    /**
     * \brief 32.768 kHz Oscillator Control A (OSC32KCTRLA) register.
     *
     * This register has the following fields:
     * - Run Standby (RUNSTDBY)
     */
    class OSC32KCTRLA : public Protected_Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto RESERVED0 = std::uint_fast8_t{ 1 }; ///< Reserved.
            static constexpr auto RUNSTDBY  = std::uint_fast8_t{ 1 }; ///< RUNSTDBY.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ 6 }; ///< Reserved.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto RESERVED0 = std::uint_fast8_t{}; ///< Reserved.
            static constexpr auto RUNSTDBY = std::uint_fast8_t{ RESERVED0 + Size::RESERVED0 }; ///< RUNSTDBY.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ RUNSTDBY + Size::RUNSTDBY }; ///< Reserved.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto RESERVED0 = mask<std::uint8_t>( Size::RESERVED0, Bit::RESERVED0 ); ///< Reserved.
            static constexpr auto RUNSTDBY = mask<std::uint8_t>( Size::RUNSTDBY, Bit::RUNSTDBY ); ///< RUNSTDBY.
            static constexpr auto RESERVED2 = mask<std::uint8_t>( Size::RESERVED2, Bit::RESERVED2 ); ///< Reserved.
        };

        OSC32KCTRLA() = delete;

        OSC32KCTRLA( OSC32KCTRLA && ) = delete;

        OSC32KCTRLA( OSC32KCTRLA const & ) = delete;

        ~OSC32KCTRLA() = delete;

        auto operator=( OSC32KCTRLA && ) = delete;

        auto operator=( OSC32KCTRLA const & ) = delete;

        using Protected_Register<std::uint8_t>::operator=;

        /**
         * \brief Get the internal 32.768 kHz ultra low-power oscillator mode.
         *
         * \return The internal 32.768 kHz ultra low-power oscillator mode.
         */
        auto internal_32_768_khz_ultra_low_power_oscillator_mode() const noexcept
        {
            return static_cast<Internal_32_768_kHz_Ultra_Low_Power_Oscillator_Mode>( *this & Mask::RUNSTDBY );
        }

        /**
         * \brief Set the internal 32.768 kHz ultra low-power oscillator mode.
         *
         * \param[in] mode The desired internal 32.768 kHz ultra low-power oscillator
         *            mode.
         */
        void set_internal_32_768_khz_ultra_low_power_oscillator_mode( Internal_32_768_kHz_Ultra_Low_Power_Oscillator_Mode mode ) noexcept
        {
            *this = static_cast<std::uint8_t>( mode );
        }
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
            static constexpr auto RESERVED3 = std::uint_fast8_t{ 1 }; ///< Reserved.
            static constexpr auto CSUT      = std::uint_fast8_t{ 2 }; ///< CSUT.
            static constexpr auto RESERVED6 = std::uint_fast8_t{ 2 }; ///< Reserved.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto ENABLE = std::uint_fast8_t{}; ///< ENABLE.
            static constexpr auto RUNSTDBY = std::uint_fast8_t{ ENABLE + Size::ENABLE }; ///< RUNSTDBY.
            static constexpr auto SEL = std::uint_fast8_t{ RUNSTDBY + Size::RUNSTDBY }; ///< SEL.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ SEL + Size::SEL }; ///< Reserved.
            static constexpr auto CSUT = std::uint_fast8_t{ RESERVED3 + Size::RESERVED3 }; ///< CSUT.
            static constexpr auto RESERVED6 = std::uint_fast8_t{ CSUT + Size::CSUT }; ///< Reserved.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto ENABLE = mask<std::uint8_t>( Size::ENABLE, Bit::ENABLE ); ///< ENABLE.
            static constexpr auto RUNSTDBY = mask<std::uint8_t>( Size::RUNSTDBY, Bit::RUNSTDBY ); ///< RUNSTDBY.
            static constexpr auto SEL = mask<std::uint8_t>( Size::SEL, Bit::SEL ); ///< SEL.
            static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< Reserved.
            static constexpr auto CSUT = mask<std::uint8_t>( Size::CSUT, Bit::CSUT ); ///< CSUT.
            static constexpr auto RESERVED6 = mask<std::uint8_t>( Size::RESERVED6, Bit::RESERVED6 ); ///< Reserved.
        };

        XOSC32KCTRLA() = delete;

        XOSC32KCTRLA( XOSC32KCTRLA && ) = delete;

        XOSC32KCTRLA( XOSC32KCTRLA const & ) = delete;

        ~XOSC32KCTRLA() = delete;

        auto operator=( XOSC32KCTRLA && ) = delete;

        auto operator=( XOSC32KCTRLA const & ) = delete;

        using Protected_Register<std::uint8_t>::operator=;

        /**
         * \brief Get the external 32.768 kHz crystal oscillator source.
         *
         * \return The external 32.768 kHz crystal oscillator source.
         */
        auto external_32_768_khz_crystal_oscillator_source() const noexcept
        {
            return static_cast<External_32_768_kHz_Crystal_Oscillator_Source>( *this & Mask::SEL );
        }

        /**
         * \brief Get the external 32.768 kHz crystal oscillator start-up time.
         *
         * \return The external 32.768 kHz crystal oscillator start-up time.
         */
        auto external_32_768_khz_crystal_oscillator_start_up_time() const noexcept
        {
            return static_cast<External_32_768_kHz_Crystal_Oscillator_Start_Up_Time>( *this & Mask::CSUT );
        }

        /**
         * \brief Get the external 32.768 kHz crystal oscillator mode.
         *
         * \return The external 32.768 kHz crystal oscillator mode.
         */
        auto external_32_768_khz_crystal_oscillator_mode() const noexcept
        {
            return static_cast<External_32_768_kHz_Crystal_Oscillator_Mode>( *this & Mask::RUNSTDBY );
        }

        /**
         * \brief Configure the external 32.768 kHz crystal oscillator.
         *
         * \param[in] source The desired external 32.768 kHz crystal oscillator source.
         * \param[in] start_up_time The external 32.768 kHz crystal oscillator start-up
         *            time.
         * \param[in] mode The desired external 32.768 kHz crystal oscillator mode.
         */
        void configure_external_32_768_khz_crystal_oscillator(
            External_32_768_kHz_Crystal_Oscillator_Source        source,
            External_32_768_kHz_Crystal_Oscillator_Start_Up_Time start_up_time,
            External_32_768_kHz_Crystal_Oscillator_Mode          mode ) noexcept
        {
            *this = static_cast<std::uint8_t>( source ) | static_cast<std::uint8_t>( start_up_time )
                    | static_cast<std::uint8_t>( mode );
        }

        /**
         * \brief Set the external 32.768 kHz crystal oscillator mode.
         *
         * \param[in] mode The desired external 32.768 kHz crystal oscillator mode.
         */
        void set_external_32_768_khz_crystal_oscillator_mode( External_32_768_kHz_Crystal_Oscillator_Mode mode ) noexcept
        {
            *this = static_cast<std::uint8_t>( mode );
        }

        /**
         * \brief Check if the external 32.768 kHz crystal oscillator is enabled.
         *
         * \return true if the external 32.768 kHz crystal oscillator is enabled.
         * \return false if the external 32.768 kHz crystal oscillator is not enabled.
         */
        auto external_32_768_khz_crystal_oscillator_enabled() const noexcept -> bool
        {
            return *this & Mask::ENABLE;
        }

        /**
         * \brief Enable the external 32.768 kHz crystal oscillator.
         */
        void enable_external_32_768_khz_crystal_oscillator() noexcept
        {
            *this |= Mask::ENABLE;
        }

        /**
         * \brief Disable the external 32.768 kHz crystal oscillator.
         */
        void disable_external_32_768_khz_crystal_oscillator() noexcept
        {
            *this &= ~Mask::ENABLE;
        }
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
        _16k = 0x1 << XOSC32KCTRLA::Bit::CSUT, ///< 16k cycles.
        _32k = 0x2 << XOSC32KCTRLA::Bit::CSUT, ///< 32k cycles.
        _64k = 0x3 << XOSC32KCTRLA::Bit::CSUT, ///< 64k cycles.
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
    MCLKSTATUS mclkstatus;

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

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::MCLKCTRLA::source()
     */
    auto source() const noexcept
    {
        return mclkctrla.source();
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::MCLKCTRLA::set_source()
     */
    void set_source( Source source ) noexcept
    {
        mclkctrla.set_source( source );
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::MCLKCTRLA::output_enabled()
     */
    auto output_enabled() const noexcept
    {
        return mclkctrla.output_enabled();
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::MCLKCTRLA::enable_output()
     */
    void enable_output() noexcept
    {
        mclkctrla.enable_output();
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::MCLKCTRLA::disable_output()
     */
    void disable_output() noexcept
    {
        mclkctrla.disable_output();
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::MCLKCTRLB::prescaler_enabled()
     */
    auto prescaler_enabled() const noexcept
    {
        return mclkctrlb.prescaler_enabled();
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::MCLKCTRLB::prescaler_value()
     */
    auto prescaler_value() const noexcept
    {
        return mclkctrlb.prescaler_value();
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::MCLKCTRLB::configure_prescaler()
     */
    void configure_prescaler( Prescaler_Value value, Prescaler configuration ) noexcept
    {
        mclkctrlb.configure_prescaler( value, configuration );
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::MCLKCTRLB::enable_prescaler()
     */
    void enable_prescaler() noexcept
    {
        mclkctrlb.enable_prescaler();
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::MCLKCTRLB::disable_prescaler()
     */
    void disable_prescaler() noexcept
    {
        mclkctrlb.disable_prescaler();
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::MCLKLOCK::configuration_locked()
     */
    auto configuration_locked() const noexcept
    {
        return mclklock.configuration_locked();
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::MCLKLOCK::lock_configuration()
     */
    void lock_configuration() noexcept
    {
        mclklock.lock_configuration();
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::MCLKSTATUS::source_changing()
     */
    auto source_changing() const noexcept
    {
        return mclkstatus.source_changing();
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::MCLKSTATUS::internal_16_20_mhz_oscillator_stable()
     */
    auto internal_16_20_mhz_oscillator_stable() const noexcept
    {
        return mclkstatus.internal_16_20_mhz_oscillator_stable();
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::OSC20MCTRLA::internal_16_20_mhz_oscillator_mode()
     */
    auto internal_16_20_mhz_oscillator_mode() const noexcept
    {
        return osc20mctrla.internal_16_20_mhz_oscillator_mode();
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::OSC20MCTRLA::set_internal_16_20_mhz_oscillator_mode()
     */
    void set_internal_16_20_mhz_oscillator_mode( Internal_16_20_MHz_Oscillator_Mode mode ) noexcept
    {
        return osc20mctrla.set_internal_16_20_mhz_oscillator_mode( mode );
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::OSC20MCALIBB::internal_16_20_mhz_oscillator_calibration_locked()
     */
    auto internal_16_20_mhz_oscillator_calibration_locked() const noexcept
    {
        return osc20mcalibb.internal_16_20_mhz_oscillator_calibration_locked();
    }

    /**
     * \brief Calibrate the internal 16/20 MHz oscillator.
     *
     * \param[in] value The desired internal 16/20 MHz oscillator calibration value.
     * \param[in] temperature_coefficient The desired internal 16/20 MHz oscillator
     *            temperature coefficient.
     */
    void calibrate_internal_16_20_mhz_oscillator( std::uint_fast8_t value, std::uint_fast8_t temperature_coefficient ) noexcept
    {
        osc20mcaliba = value;
        osc20mcalibb = temperature_coefficient;
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::MCLKSTATUS::internal_32_768_khz_ultra_low_power_oscillator_stable()
     */
    auto internal_32_768_khz_ultra_low_power_oscillator_stable() const noexcept
    {
        return mclkstatus.internal_32_768_khz_ultra_low_power_oscillator_stable();
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::OSC32KCTRLA::internal_32_768_khz_ultra_low_power_oscillator_mode()
     */
    auto internal_32_768_khz_ultra_low_power_oscillator_mode() const noexcept
    {
        return osc32kctrla.internal_32_768_khz_ultra_low_power_oscillator_mode();
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::OSC32KCTRLA::set_internal_32_768_khz_ultra_low_power_oscillator_mode()
     */
    void set_internal_32_768_khz_ultra_low_power_oscillator_mode( Internal_32_768_kHz_Ultra_Low_Power_Oscillator_Mode mode ) noexcept
    {
        return osc32kctrla.set_internal_32_768_khz_ultra_low_power_oscillator_mode( mode );
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::MCLKSTATUS::external_32_768_khz_crystal_oscillator_stable()
     */
    auto external_32_768_khz_crystal_oscillator_stable() const noexcept
    {
        return mclkstatus.external_32_768_khz_crystal_oscillator_stable();
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::XOSC32KCTRLA::external_32_768_khz_crystal_oscillator_source()
     */
    auto external_32_768_khz_crystal_oscillator_source() const noexcept
    {
        return xosc32kctrla.external_32_768_khz_crystal_oscillator_source();
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::XOSC32KCTRLA::external_32_768_khz_crystal_oscillator_start_up_time()
     */
    auto external_32_768_khz_crystal_oscillator_start_up_time() const noexcept
    {
        return xosc32kctrla.external_32_768_khz_crystal_oscillator_start_up_time();
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::XOSC32KCTRLA::external_32_768_khz_crystal_oscillator_mode()
     */
    auto external_32_768_khz_crystal_oscillator_mode() const noexcept
    {
        return xosc32kctrla.external_32_768_khz_crystal_oscillator_mode();
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::XOSC32KCTRLA::configure_external_32_768_khz_crystal_oscillator()
     */
    void configure_external_32_768_khz_crystal_oscillator(
        External_32_768_kHz_Crystal_Oscillator_Source        source,
        External_32_768_kHz_Crystal_Oscillator_Start_Up_Time start_up_time,
        External_32_768_kHz_Crystal_Oscillator_Mode          mode ) noexcept
    {
        xosc32kctrla.configure_external_32_768_khz_crystal_oscillator( source, start_up_time, mode );
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::XOSC32KCTRLA::set_external_32_768_khz_crystal_oscillator_mode()
     */
    void set_external_32_768_khz_crystal_oscillator_mode( External_32_768_kHz_Crystal_Oscillator_Mode mode ) noexcept
    {
        return xosc32kctrla.set_external_32_768_khz_crystal_oscillator_mode( mode );
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::XOSC32KCTRLA::external_32_768_khz_crystal_oscillator_enabled()
     */
    auto external_32_768_khz_crystal_oscillator_enabled() const noexcept
    {
        return xosc32kctrla.external_32_768_khz_crystal_oscillator_enabled();
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::XOSC32KCTRLA::enable_external_32_768_khz_crystal_oscillator()
     */
    void enable_external_32_768_khz_crystal_oscillator() noexcept
    {
        return xosc32kctrla.enable_external_32_768_khz_crystal_oscillator();
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::XOSC32KCTRLA::disable_external_32_768_khz_crystal_oscillator()
     */
    void disable_external_32_768_khz_crystal_oscillator() noexcept
    {
        return xosc32kctrla.disable_external_32_768_khz_crystal_oscillator();
    }

    /**
     * \copydoc picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL::MCLKSTATUS::external_clock_stable()
     */
    auto external_clock_stable() const noexcept
    {
        return mclkstatus.external_clock_stable();
    }
};

/**
 * \brief Microchip megaAVR 0-series Clock Controller (CLKCTRL) peripheral instance.
 *
 * \tparam INSTANCE_ADDRESS The address of the CLKCTRL instance.
 */
template<std::uintptr_t INSTANCE_ADDRESS>
using CLKCTRL_Instance = Instance<CLKCTRL, INSTANCE_ADDRESS>;

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_CLKCTRL_H
