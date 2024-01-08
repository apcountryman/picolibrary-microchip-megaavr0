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
 * \brief picolibrary::Microchip::megaAVR0::Clock interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_CLOCK_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_CLOCK_H

#include <cstdint>

#include "picolibrary/microchip/megaavr0/peripheral.h"
#include "picolibrary/microchip/megaavr0/peripheral/clkctrl.h"
#include "picolibrary/utility.h"

/**
 * \brief Microchip megaAVR 0-series clock facilities
 */
namespace picolibrary::Microchip::megaAVR0::Clock {

/**
 * \brief Clock source.
 */
enum class Source : std::uint8_t {
    INTERNAL_16_20_MHz_OSCILLATOR                  = Peripheral::CLKCTRL::MCLKCTRLA::CLKSEL_OSC20M, ///< Internal 16/20 MHz oscillator.
    INTERNAL_32_768_kHz_ULTRA_LOW_POWER_OSCILLATOR = Peripheral::CLKCTRL::MCLKCTRLA::CLKSEL_OSCULP32K, ///< Internal 32.768 kHz ultra low-power oscillator.
    EXTERNAL_32_768_kHz_CRYSTAL_OSCILLATOR         = Peripheral::CLKCTRL::MCLKCTRLA::CLKSEL_XOSC32K, ///< External 32.768 kHz crystal oscillator.
    EXTERNAL_CLOCK = Peripheral::CLKCTRL::MCLKCTRLA::CLKSEL_EXTCLK, ///< External clock.
};

/**
 * \brief Check if the clock source is changing.
 *
 * \return true if the clock source is changing.
 * \return false if the clock source is not changing.
 */
inline auto source_changing() noexcept -> bool
{
    auto const & clkctrl = Peripheral::CLKCTRL0::instance();

    return clkctrl.mclkstatus & Peripheral::CLKCTRL::MCLKSTATUS::Mask::SOSC;
}

/**
 * \brief Get the clock source.
 *
 * \return The clock source.
 */
inline auto source() noexcept -> Source
{
    auto const & clkctrl = Peripheral::CLKCTRL0::instance();

    return static_cast<Source>( clkctrl.mclkctrla & Peripheral::CLKCTRL::MCLKCTRLA::Mask::CLKSEL );
}

/**
 * \brief Set the clock source.
 *
 * \param[in] source The desired clock source.
 */
inline void set_source( Source source ) noexcept
{
    auto & clkctrl = Peripheral::CLKCTRL0::instance();

    clkctrl.mclkctrla = ( clkctrl.mclkctrla & ~Peripheral::CLKCTRL::MCLKCTRLA::Mask::CLKSEL )
                        | to_underlying( source );
}

/**
 * \brief Check if clock output is enabled.
 *
 * \return true if clock output is enabled.
 * \return false if clock output is not enabled.
 */
inline auto output_enabled() noexcept -> bool
{
    auto const & clkctrl = Peripheral::CLKCTRL0::instance();

    return clkctrl.mclkctrla & Peripheral::CLKCTRL::MCLKCTRLA::Mask::CLKOUT;
}

/**
 * \brief Enable clock output.
 */
inline void enable_output() noexcept
{
    auto & clkctrl = Peripheral::CLKCTRL0::instance();

    clkctrl.mclkctrla |= Peripheral::CLKCTRL::MCLKCTRLA::Mask::CLKOUT;
}

/**
 * \brief Disable clock output.
 */
inline void disable_output() noexcept
{
    auto & clkctrl = Peripheral::CLKCTRL0::instance();

    clkctrl.mclkctrla &= static_cast<std::uint8_t>( ~Peripheral::CLKCTRL::MCLKCTRLA::Mask::CLKOUT );
}

/**
 * \brief Clock prescaler configuration.
 */
enum class Prescaler : std::uint8_t {
    DISABLED = 0b0 << Peripheral::CLKCTRL::MCLKCTRLB::Bit::PEN, ///< Disabled.
    ENABLED  = 0b1 << Peripheral::CLKCTRL::MCLKCTRLB::Bit::PEN, ///< Enabled.
};

/**
 * \brief Clock prescaler value.
 */
enum class Prescaler_Value : std::uint8_t {
    _2  = Peripheral::CLKCTRL::MCLKCTRLB::PDIV_DIV2,  ///< 2.
    _4  = Peripheral::CLKCTRL::MCLKCTRLB::PDIV_DIV4,  ///< 4.
    _6  = Peripheral::CLKCTRL::MCLKCTRLB::PDIV_DIV6,  ///< 6.
    _8  = Peripheral::CLKCTRL::MCLKCTRLB::PDIV_DIV8,  ///< 8.
    _10 = Peripheral::CLKCTRL::MCLKCTRLB::PDIV_DIV10, ///< 10.
    _12 = Peripheral::CLKCTRL::MCLKCTRLB::PDIV_DIV12, ///< 12.
    _16 = Peripheral::CLKCTRL::MCLKCTRLB::PDIV_DIV16, ///< 16.
    _24 = Peripheral::CLKCTRL::MCLKCTRLB::PDIV_DIV24, ///< 24.
    _32 = Peripheral::CLKCTRL::MCLKCTRLB::PDIV_DIV32, ///< 32.
    _48 = Peripheral::CLKCTRL::MCLKCTRLB::PDIV_DIV48, ///< 48.
    _64 = Peripheral::CLKCTRL::MCLKCTRLB::PDIV_DIV64, ///< 64.
};

/**
 * \brief Check if the clock prescaler is enabled.
 *
 * \return true if the clock prescaler is enabled.
 * \return false if the clock prescaler is not enabled.
 */
inline auto prescaler_enabled() noexcept -> bool
{
    auto const & clkctrl = Peripheral::CLKCTRL0::instance();

    return clkctrl.mclkctrlb & Peripheral::CLKCTRL::MCLKCTRLB::Mask::PEN;
}

/**
 * \brief Get the clock prescaler configuration.
 *
 * \return The clock prescaler configuration.
 */
inline auto prescaler_configuration() noexcept -> Prescaler
{
    auto const & clkctrl = Peripheral::CLKCTRL0::instance();

    return static_cast<Prescaler>( clkctrl.mclkctrlb & Peripheral::CLKCTRL::MCLKCTRLB::Mask::PEN );
}

/**
 * \brief Get the clock prescaler value.
 *
 * \return The clock prescaler value.
 */
inline auto prescaler_value() noexcept -> Prescaler_Value
{
    auto const & clkctrl = Peripheral::CLKCTRL0::instance();

    return static_cast<Prescaler_Value>( clkctrl.mclkctrlb & Peripheral::CLKCTRL::MCLKCTRLB::Mask::PDIV );
}

/**
 * \brief Configure the clock prescaler.
 *
 * \param[in] value The desired clock prescaler value.
 * \param[in] configuration The desired clock prescaler configuration.
 */
inline void configure_prescaler( Prescaler_Value value, Prescaler configuration ) noexcept
{
    auto & clkctrl = Peripheral::CLKCTRL0::instance();

    clkctrl.mclkctrlb = to_underlying( value ) | to_underlying( configuration );
}

/**
 * \brief Enable the clock prescaler.
 */
inline void enable_prescaler() noexcept
{
    auto & clkctrl = Peripheral::CLKCTRL0::instance();

    clkctrl.mclkctrlb |= Peripheral::CLKCTRL::MCLKCTRLB::Mask::PEN;
}

/**
 * \brief Disable the clock prescaler.
 */
inline void disable_prescaler() noexcept
{
    auto & clkctrl = Peripheral::CLKCTRL0::instance();

    clkctrl.mclkctrlb &= ~Peripheral::CLKCTRL::MCLKCTRLB::Mask::PEN;
}

/**
 * \brief Check if the clock configuration is locked.
 *
 * \return true if the clock configuration is locked.
 * \return false if the clock configuration is not locked.
 */
inline auto configuration_locked() noexcept -> bool
{
    auto const & clkctrl = Peripheral::CLKCTRL0::instance();

    return clkctrl.mclklock & Peripheral::CLKCTRL::MCLKLOCK::Mask::LOCKEN;
}

/**
 * \brief Lock the clock configuration.
 */
inline void lock_configuration() noexcept
{
    auto & clkctrl = Peripheral::CLKCTRL0::instance();

    clkctrl.mclklock = Peripheral::CLKCTRL::MCLKLOCK::Mask::LOCKEN;
}

/**
 * \brief Internal 16/20 MHz oscillator mode.
 */
enum class Internal_16_20_MHz_Oscillator_Mode : std::uint8_t {
    NORMAL    = 0b0 << Peripheral::CLKCTRL::OSC20MCTRLA::Bit::RUNSTDBY, ///< Normal.
    FORCED_ON = 0b1 << Peripheral::CLKCTRL::OSC20MCTRLA::Bit::RUNSTDBY, ///< Forced on.
};

/**
 * \brief Check if the internal 16/20 MHz oscillator is stable.
 *
 * \return true if the internal 16/20 MHz oscillator is stable.
 * \return false if the internal 16/20 MHz oscillator is not stable.
 */
inline auto internal_16_20_MHz_oscillator_stable() noexcept -> bool
{
    auto const & clkctrl = Peripheral::CLKCTRL0::instance();

    return clkctrl.mclkstatus & Peripheral::CLKCTRL::MCLKSTATUS::Mask::OSC20MS;
}

/**
 * \brief Get the internal 16/20 MHz oscillator mode.
 *
 * \return The internal 16/20 MHz oscillator mode.
 */
inline auto internal_16_20_MHz_oscillator_mode() noexcept -> Internal_16_20_MHz_Oscillator_Mode
{
    auto const & clkctrl = Peripheral::CLKCTRL0::instance();

    return static_cast<Internal_16_20_MHz_Oscillator_Mode>(
        clkctrl.osc20mctrla & Peripheral::CLKCTRL::OSC20MCTRLA::Mask::RUNSTDBY );
}

/**
 * \brief Set the internal 16/20 MHz oscillator mode.
 *
 * \param[in] mode The desired internal 16/20 MHz oscillator mode.
 */
inline void set_internal_16_20_MHz_oscillator_mode( Internal_16_20_MHz_Oscillator_Mode mode ) noexcept
{
    auto & clkctrl = Peripheral::CLKCTRL0::instance();

    clkctrl.osc20mctrla = to_underlying( mode );
}

/**
 * \brief Check if the internal 16/20 MHz oscillator calibration is locked.
 *
 * \return true if the internal 16/20 MHz oscillator calibration is locked.
 * \return false if the internal 16/20 MHz oscillator calibration is not locked.
 */
inline auto internal_16_20_MHz_oscillator_calibration_locked() noexcept -> bool
{
    auto const & clkctrl = Peripheral::CLKCTRL0::instance();

    return clkctrl.osc20mcalibb & Peripheral::CLKCTRL::OSC20MCALIBB::Mask::LOCK;
}

/**
 * \brief Calibrate the internal 16/20 MHz oscillator.
 *
 * \param[in] value The desired 16/20 MHz oscillator calibration value (value to be
 *            written to the CLKCTRL.OSC20MCALIBA register's CAL20M field).
 * \param[in] temperature_coefficient The desired internal 16/20 MHz oscillator
 *            temperature coefficient (value to be written to the CLKCTRL.OSC20MCALIBB
 *            register's TEMPCAL20M field).
 */
inline void calibrate_internal_16_20_MHz_oscillator( std::uint_fast8_t value, std::uint_fast8_t temperature_coefficient ) noexcept
{
    auto & clkctrl = Peripheral::CLKCTRL0::instance();

    clkctrl.osc20mcaliba = value & Peripheral::CLKCTRL::OSC20MCALIBA::Mask::CAL20M;
    clkctrl.osc20mcalibb = temperature_coefficient & Peripheral::CLKCTRL::OSC20MCALIBB::Mask::TEMPCAL20M;
}

/**
 * \brief Internal 32.768 kHz ultra low-power oscillator mode.
 */
enum class Internal_32_768_kHz_Ultra_Low_Power_Oscillator_Mode : std::uint8_t {
    NORMAL    = 0b0 << Peripheral::CLKCTRL::OSC32KCTRLA::Bit::RUNSTDBY, ///< Normal.
    FORCED_ON = 0b1 << Peripheral::CLKCTRL::OSC32KCTRLA::Bit::RUNSTDBY, ///< Forced on.
};

/**
 * \brief Check if the internal 32.768 kHz ultra low-power oscillator is stable.
 *
 * \return true if the internal 32.768 kHz ultra low-power oscillator is stable.
 * \return false if the internal 32.768 kHz ultra low-power oscillator is not stable.
 */
inline auto internal_32_768_kHz_ultra_low_power_oscillator_stable() noexcept -> bool
{
    auto const & clkctrl = Peripheral::CLKCTRL0::instance();

    return clkctrl.mclkstatus & Peripheral::CLKCTRL::MCLKSTATUS::Mask::OSC32KS;
}

/**
 * \brief Get the internal 32.768 kHz ultra low-power oscillator mode.
 *
 * \return The internal 32.768 kHz ultra low-power oscillator mode.
 */
inline auto internal_32_768_kHz_ultra_low_power_oscillator_mode() noexcept
    -> Internal_32_768_kHz_Ultra_Low_Power_Oscillator_Mode
{
    auto const & clkctrl = Peripheral::CLKCTRL0::instance();

    return static_cast<Internal_32_768_kHz_Ultra_Low_Power_Oscillator_Mode>(
        clkctrl.osc32kctrla & Peripheral::CLKCTRL::OSC32KCTRLA::Mask::RUNSTDBY );
}

/**
 * \brief Set the internal 32.768 kHz ultra low-power oscillator mode.
 *
 * \param[in] mode The desired internal 32.768 kHz ultra low-power oscillator mode.
 */
inline void set_internal_32_768_kHz_ultra_low_power_oscillator_mode( Internal_32_768_kHz_Ultra_Low_Power_Oscillator_Mode mode ) noexcept
{
    auto & clkctrl = Peripheral::CLKCTRL0::instance();

    clkctrl.osc32kctrla = to_underlying( mode );
}

/**
 * \brief External 32.768 kHz crystal oscillator source.
 */
enum class External_32_768_kHz_Crystal_Oscillator_Source : std::uint8_t {
    CRYSTAL = 0b0 << Peripheral::CLKCTRL::XOSC32KCTRLA::Bit::SEL, ///< Crystal.
    CLOCK   = 0b1 << Peripheral::CLKCTRL::XOSC32KCTRLA::Bit::SEL, ///< Clock.
};

/**
 * \brief External 32.768 kHz crystal oscillator start-up time.
 */
enum class External_32_768_kHz_Crystal_Oscillator_Start_Up_Time : std::uint8_t {
    _1k  = Peripheral::CLKCTRL::XOSC32KCTRLA::CSUT_1K,  ///< 1k cycles.
    _16k = Peripheral::CLKCTRL::XOSC32KCTRLA::CSUT_16K, ///< 16k cycles.
    _32k = Peripheral::CLKCTRL::XOSC32KCTRLA::CSUT_32K, ///< 32k cycles.
    _64k = Peripheral::CLKCTRL::XOSC32KCTRLA::CSUT_64K, ///< 64k cycles.
};

/**
 * \brief External 32.768 kHz crystal oscillator mode.
 */
enum class External_32_768_kHz_Crystal_Oscillator_Mode : std::uint8_t {
    NORMAL    = 0b0 << Peripheral::CLKCTRL::XOSC32KCTRLA::Bit::RUNSTDBY, ///< Normal.
    FORCED_ON = 0b1 << Peripheral::CLKCTRL::XOSC32KCTRLA::Bit::RUNSTDBY, ///< Forced on.
};

/**
 * \brief Check if the external 32.768 kHz crystal oscillator is stable.
 *
 * \return true if the external 32.768 kHz crystal oscillator is stable.
 * \return false if the external 32.768 kHz crystal oscillator is not stable.
 */
inline auto external_32_768_kHz_crystal_oscillator_stable() noexcept -> bool
{
    auto const & clkctrl = Peripheral::CLKCTRL0::instance();

    return clkctrl.mclkstatus & Peripheral::CLKCTRL::MCLKSTATUS::Mask::XOSC32KS;
}

/**
 * \brief Get the external 32.768 kHz crystal oscillator source.
 *
 * \return The external 32.768 kHz crystal oscillator source.
 */
inline auto external_32_768_kHz_crystal_oscillator_source() noexcept -> External_32_768_kHz_Crystal_Oscillator_Source
{
    auto const & clkctrl = Peripheral::CLKCTRL0::instance();

    return static_cast<External_32_768_kHz_Crystal_Oscillator_Source>(
        clkctrl.xosc32kctrla & Peripheral::CLKCTRL::XOSC32KCTRLA::Mask::SEL );
}

/**
 * \brief Get the external 32.768 kHz crystal oscillator start-up time.
 *
 * \return The external 32.768 kHz crystal oscillator start-up time.
 */
inline auto external_32_768_kHz_crystal_oscillator_start_up_time() noexcept
    -> External_32_768_kHz_Crystal_Oscillator_Start_Up_Time
{
    auto const & clkctrl = Peripheral::CLKCTRL0::instance();

    return static_cast<External_32_768_kHz_Crystal_Oscillator_Start_Up_Time>(
        clkctrl.xosc32kctrla & Peripheral::CLKCTRL::XOSC32KCTRLA::Mask::CSUT );
}

/**
 * \brief Get the external 32.768 kHz crystal oscillator mode.
 *
 * \return The external 32.768 kHz crystal oscillator mode.
 */
inline auto external_32_768_kHz_crystal_oscillator_mode() noexcept -> External_32_768_kHz_Crystal_Oscillator_Mode
{
    auto const & clkctrl = Peripheral::CLKCTRL0::instance();

    return static_cast<External_32_768_kHz_Crystal_Oscillator_Mode>(
        clkctrl.xosc32kctrla & Peripheral::CLKCTRL::XOSC32KCTRLA::Mask::RUNSTDBY );
}

/**
 * \brief Configure the external 32.768 kHz crystal oscillator.
 *
 * \param[in] source The desired external 32.768 kHz crystal oscillator source.
 * \param[in] start_up_time The external 32.768 kHz crystal oscillator start-up time.
 * \param[in] mode The desired external 32.768 kHz crystal oscillator mode.
 */
inline void configure_external_32_768_kHz_crystal_oscillator(
    External_32_768_kHz_Crystal_Oscillator_Source        source,
    External_32_768_kHz_Crystal_Oscillator_Start_Up_Time start_up_time,
    External_32_768_kHz_Crystal_Oscillator_Mode          mode ) noexcept
{
    auto & clkctrl = Peripheral::CLKCTRL0::instance();

    clkctrl.xosc32kctrla = to_underlying( source ) | to_underlying( start_up_time )
                           | to_underlying( mode );
}

/**
 * \brief Set the external 32.768 kHz crystal oscillator mode.
 *
 * \param[in] mode The desired external 32.768 kHz crystal oscillator mode.
 */
inline void set_external_32_768_kHz_crystal_oscillator_mode( External_32_768_kHz_Crystal_Oscillator_Mode mode ) noexcept
{
    auto & clkctrl = Peripheral::CLKCTRL0::instance();

    clkctrl.xosc32kctrla = ( clkctrl.xosc32kctrla & ~Peripheral::CLKCTRL::XOSC32KCTRLA::Mask::RUNSTDBY )
                           | to_underlying( mode );
}

/**
 * \brief Check if the external 32.768 kHz crystal oscillator is enabled.
 *
 * \return true if the external 32.768 kHz crystal oscillator is enabled.
 * \return false if the external 32.768 kHz crystal oscillator is not enabled.
 */
inline auto external_32_768_kHz_crystal_oscillator_enabled() noexcept -> bool
{
    auto const & clkctrl = Peripheral::CLKCTRL0::instance();

    return clkctrl.xosc32kctrla & Peripheral::CLKCTRL::XOSC32KCTRLA::Mask::ENABLE;
}

/**
 * \brief Enable the external 32.768 kHz crystal oscillator.
 */
inline void enable_external_32_768_kHz_crystal_oscillator() noexcept
{
    auto & clkctrl = Peripheral::CLKCTRL0::instance();

    clkctrl.xosc32kctrla |= Peripheral::CLKCTRL::XOSC32KCTRLA::Mask::ENABLE;
}

/**
 * \brief Disable the external 32.768 kHz crystal oscillator.
 */
inline void disable_external_32_768_kHz_crystal_oscillator() noexcept
{
    auto & clkctrl = Peripheral::CLKCTRL0::instance();

    clkctrl.xosc32kctrla &= ~Peripheral::CLKCTRL::XOSC32KCTRLA::Mask::ENABLE;
}

/**
 * \brief Check if the external clock is stable.
 *
 * \return true if the external clock is stable.
 * \return false if the external clock is not stable.
 */
inline auto external_clock_stable() noexcept -> bool
{
    auto const & clkctrl = Peripheral::CLKCTRL0::instance();

    return clkctrl.mclkstatus & Peripheral::CLKCTRL::MCLKSTATUS::Mask::EXTS;
}

} // namespace picolibrary::Microchip::megaAVR0::Clock

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_CLOCK_H
