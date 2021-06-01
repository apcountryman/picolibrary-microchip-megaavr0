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
 * \brief picolibrary::Microchip::megaAVR0::Clock interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_CLOCK_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_CLOCK_H

#include <cstdint>

#include "picolibrary/microchip/megaavr0/peripheral.h"
#include "picolibrary/microchip/megaavr0/peripheral/clkctrl.h"

/**
 * \brief Microchip megaAVR 0-series clock facilities.
 */
namespace picolibrary::Microchip::megaAVR0::Clock {

/**
 * \brief Clock source.
 */
using Source = Peripheral::CLKCTRL::Source;

/**
 * \brief Clock prescaler configuration.
 */
using Prescaler = Peripheral::CLKCTRL::Prescaler;

/**
 * \brief Clock prescaler value.
 */
using Prescaler_Value = Peripheral::CLKCTRL::Prescaler_Value;

/**
 * \brief Internal 16/20 MHz oscillator mode.
 */
using Internal_16_20_MHz_Oscillator_Mode = Peripheral::CLKCTRL::Internal_16_20_MHz_Oscillator_Mode;

/**
 * \brief Internal 32.768 kHz ultra low-power oscillator mode.
 */
using Internal_32_768_kHz_Ultra_Low_Power_Oscillator_Mode = Peripheral::CLKCTRL::Internal_32_768_kHz_Ultra_Low_Power_Oscillator_Mode;

/**
 * \brief External 32.768 kHz crystal oscillator source.
 */
using External_32_768_kHz_Crystal_Oscillator_Source = Peripheral::CLKCTRL::External_32_768_kHz_Crystal_Oscillator_Source;

/**
 * \brief External 32.768 kHz crystal oscillator start-up time.
 */
using External_32_768_kHz_Crystal_Oscillator_Start_Up_Time = Peripheral::CLKCTRL::External_32_768_kHz_Crystal_Oscillator_Start_Up_Time;

/**
 * \brief External 32.768 kHz crystal oscillator mode.
 */
using External_32_768_kHz_Crystal_Oscillator_Mode = Peripheral::CLKCTRL::External_32_768_kHz_Crystal_Oscillator_Mode;

/**
 * \brief Check if the clock source is changing.
 *
 * \return true if the clock source is changing.
 * \return false if the clock source is not changing.
 */
inline auto source_changing() noexcept
{
    return Peripheral::CLKCTRL0::instance().source_changing();
}

/**
 * \brief Get the clock source.
 *
 * \return The clock source.
 */
inline auto source() noexcept
{
    return Peripheral::CLKCTRL0::instance().source();
}

/**
 * \brief Set the clock source.
 *
 * \param[in] source The desired clock source.
 */
inline void set_source( Source source ) noexcept
{
    Peripheral::CLKCTRL0::instance().set_source( source );
}

/**
 * \brief Check if clock output is enabled.
 *
 * \return true if clock output is enabled.
 * \return false if clock output is not enabled.
 */
inline auto output_enabled() noexcept
{
    return Peripheral::CLKCTRL0::instance().output_enabled();
}

/**
 * \brief Enable clock output.
 */
inline void enable_output() noexcept
{
    Peripheral::CLKCTRL0::instance().enable_output();
}

/**
 * \brief Disable clock output.
 */
inline void disable_output() noexcept
{
    Peripheral::CLKCTRL0::instance().disable_output();
}

/**
 * \brief Check if the clock prescaler is enabled.
 *
 * \return true if the clock prescaler is enabled.
 * \return false if the clock prescaler is not enabled.
 */
inline auto prescaler_enabled() noexcept
{
    return Peripheral::CLKCTRL0::instance().prescaler_enabled();
}

/**
 * \brief Get the clock prescaler value.
 *
 * \return The clock prescaler value.
 */
inline auto prescaler_value() noexcept
{
    return Peripheral::CLKCTRL0::instance().prescaler_value();
}

/**
 * \brief Configure the clock prescaler.
 *
 * \param[in] value The desired clock prescaler value.
 * \param[in] configuration The desired clock prescaler configuration.
 */
inline void configure_prescaler( Prescaler_Value value, Prescaler configuration ) noexcept
{
    Peripheral::CLKCTRL0::instance().configure_prescaler( value, configuration );
}

/**
 * \brief Enable the clock prescaler.
 */
inline void enable_prescaler() noexcept
{
    Peripheral::CLKCTRL0::instance().enable_prescaler();
}

/**
 * \brief Disable the clock prescaler.
 */
inline void disable_prescaler() noexcept
{
    Peripheral::CLKCTRL0::instance().disable_prescaler();
}

/**
 * \brief Check if the clock configuration is locked.
 *
 * \return true if the clock configuration is locked.
 * \return false if the clock configuration is not locked.
 */
inline auto configuration_locked() noexcept
{
    return Peripheral::CLKCTRL0::instance().configuration_locked();
}

/**
 * \brief Lock the clock configuration.
 */
inline void lock_configuration() noexcept
{
    Peripheral::CLKCTRL0::instance().lock_configuration();
}

/**
 * \brief Check if the internal 16/20 MHz oscillator is stable.
 *
 * \return true if the internal 16/20 MHz oscillator is stable.
 * \return false if the internal 16/20 MHz oscillator is not stable.
 */
inline auto internal_16_20_mhz_oscillator_stable() noexcept
{
    return Peripheral::CLKCTRL0::instance().internal_16_20_mhz_oscillator_stable();
}

/**
 * \brief Get the internal 16/20 MHz oscillator mode.
 *
 * \return The internal 16/20 MHz oscillator mode.
 */
inline auto internal_16_20_mhz_oscillator_mode() noexcept
{
    return Peripheral::CLKCTRL0::instance().internal_16_20_mhz_oscillator_mode();
}

/**
 * \brief Set the internal 16/20 MHz oscillator mode.
 *
 * \param[in] mode The desired internal 16/20 MHz oscillator mode.
 */
inline void set_internal_16_20_mhz_oscillator_mode( Internal_16_20_MHz_Oscillator_Mode mode ) noexcept
{
    Peripheral::CLKCTRL0::instance().set_internal_16_20_mhz_oscillator_mode( mode );
}

/**
 * \brief Check if the internal 16/20 MHz oscillator calibration is locked.
 *
 * \return true if the internal 16/20 MHz oscillator calibration is locked.
 * \return false if the internal 16/20 MHz oscillator is not calibration_locked.
 */
inline auto internal_16_20_mhz_oscillator_calibration_locked() noexcept
{
    return Peripheral::CLKCTRL0::instance().internal_16_20_mhz_oscillator_calibration_locked();
}

/**
 * \brief Calibrate the internal 16/20 MHz oscillator.
 *
 * \param[in] value The desired 16/20 MHz oscillator calibration value.
 * \param[in] temperature_coefficient The desired internal 16/20 MHz oscillator
 *            temperature coefficient.
 */
inline void calibrate_internal_16_20_mhz_oscillator( std::uint_fast8_t value, std::uint_fast8_t temperature_coefficient ) noexcept
{
    Peripheral::CLKCTRL0::instance().calibrate_internal_16_20_mhz_oscillator(
        value, temperature_coefficient );
}

/**
 * \brief Check if the internal 32.768 kHz ultra low-power oscillator is stable.
 *
 * \return true if the internal 32.768 kHz ultra low-power oscillator is stable.
 * \return false if the internal 32.768 kHz ultra low-power oscillator is not stable.
 */
inline auto internal_32_768_khz_ultra_low_power_oscillator_stable() noexcept
{
    return Peripheral::CLKCTRL0::instance().internal_32_768_khz_ultra_low_power_oscillator_stable();
}

/**
 * \brief Get the internal 32.768 kHz ultra low-power oscillator mode.
 *
 * \return The internal 32.768 kHz ultra low-power oscillator mode.
 */
inline auto internal_32_768_khz_ultra_low_power_oscillator_mode() noexcept
{
    return Peripheral::CLKCTRL0::instance().internal_32_768_khz_ultra_low_power_oscillator_mode();
}

/**
 * \brief Set the internal 32.768 kHz ultra low-power oscillator mode.
 *
 * \param[in] mode The desired internal 32.768 kHz ultra low-power oscillator mode.
 */
inline void set_internal_32_768_khz_ultra_low_power_oscillator_mode( Internal_32_768_kHz_Ultra_Low_Power_Oscillator_Mode mode ) noexcept
{
    Peripheral::CLKCTRL0::instance().set_internal_32_768_khz_ultra_low_power_oscillator_mode( mode );
}

/**
 * \brief Check if the external 32.768 kHz crystal oscillator is stable.
 *
 * \return true if the external 32.768 kHz crystal oscillator is stable.
 * \return false if the external 32.768 kHz crystal oscillator is not stable.
 */
inline auto external_32_768_khz_crystal_oscillator_stable() noexcept
{
    return Peripheral::CLKCTRL0::instance().external_32_768_khz_crystal_oscillator_stable();
}

/**
 * \brief Get the external 32.768 kHz crystal oscillator source.
 *
 * \return The external 32.768 kHz crystal oscillator source.
 */
inline auto external_32_768_khz_crystal_oscillator_source() noexcept
{
    return Peripheral::CLKCTRL0::instance().external_32_768_khz_crystal_oscillator_source();
}

/**
 * \brief Get the external 32.768 kHz crystal oscillator start-up time.
 *
 * \return The external 32.768 kHz crystal oscillator start-up time.
 */
inline auto external_32_768_khz_crystal_oscillator_start_up_time() noexcept
{
    return Peripheral::CLKCTRL0::instance().external_32_768_khz_crystal_oscillator_start_up_time();
}

/**
 * \brief Get the external 32.768 kHz crystal oscillator mode.
 *
 * \return The external 32.768 kHz crystal oscillator mode.
 */
inline auto external_32_768_khz_crystal_oscillator_mode() noexcept
{
    return Peripheral::CLKCTRL0::instance().external_32_768_khz_crystal_oscillator_mode();
}

/**
 * \brief Configure the external 32.768 kHz crystal oscillator.
 *
 * \param[in] source The desired external 32.768 kHz crystal oscillator source.
 * \param[in] start_up_time The external 32.768 kHz crystal oscillator start-up time.
 * \param[in] mode The desired external 32.768 kHz crystal oscillator mode.
 */
inline void configure_external_32_768_khz_crystal_oscillator(
    External_32_768_kHz_Crystal_Oscillator_Source        source,
    External_32_768_kHz_Crystal_Oscillator_Start_Up_Time start_up_time,
    External_32_768_kHz_Crystal_Oscillator_Mode          mode ) noexcept
{
    Peripheral::CLKCTRL0::instance().configure_external_32_768_khz_crystal_oscillator(
        source, start_up_time, mode );
}

/**
 * \brief Set the external 32.768 kHz crystal oscillator mode.
 *
 * \param[in] mode The desired external 32.768 kHz crystal oscillator mode.
 */
inline void set_external_32_768_khz_crystal_oscillator_mode( External_32_768_kHz_Crystal_Oscillator_Mode mode ) noexcept
{
    Peripheral::CLKCTRL0::instance().set_external_32_768_khz_crystal_oscillator_mode( mode );
}

/**
 * \brief Check if the external 32.768 kHz crystal oscillator is enabled.
 *
 * \return true if the external 32.768 kHz crystal oscillator is enabled.
 * \return false if the external 32.768 kHz crystal oscillator is not enabled.
 */
inline auto external_32_768_khz_crystal_oscillator_enabled() noexcept
{
    return Peripheral::CLKCTRL0::instance().external_32_768_khz_crystal_oscillator_enabled();
}

/**
 * \brief Enable the external 32.768 kHz crystal oscillator.
 */
inline void enable_external_32_768_khz_crystal_oscillator() noexcept
{
    Peripheral::CLKCTRL0::instance().enable_external_32_768_khz_crystal_oscillator();
}

/**
 * \brief Disable the external 32.768 kHz crystal oscillator.
 */
inline void disable_external_32_768_khz_crystal_oscillator() noexcept
{
    Peripheral::CLKCTRL0::instance().disable_external_32_768_khz_crystal_oscillator();
}

/**
 * \brief Check if the external clock is stable.
 *
 * \return true if the external clock is stable.
 * \return false if the external clock is not stable.
 */
inline auto external_clock_stable() noexcept
{
    return Peripheral::CLKCTRL0::instance().external_clock_stable();
}

} // namespace picolibrary::Microchip::megaAVR0::Clock

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_CLOCK_H
