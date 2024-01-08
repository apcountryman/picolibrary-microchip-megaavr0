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
 * \brief picolibrary::Testing::Interactive::Microchip::megaAVR0 clock interface.
 */

#ifndef PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_CLOCK_H
#define PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_CLOCK_H

#include "picolibrary/microchip/megaavr0/clock.h"

namespace picolibrary::Testing::Interactive::Microchip::megaAVR0 {

/**
 * \brief Configure the clock to use the internal 16/20 MHz oscillator with the provided
 *        clock prescaler settings.
 *
 * \param[in] clock_prescaler_value The desired clock prescaler value.
 * \param[in] clock_prescaler_configuration The desired clock prescaler configuration.
 */
inline void configure_clock(
    ::picolibrary::Microchip::megaAVR0::Clock::Prescaler_Value clock_prescaler_value,
    ::picolibrary::Microchip::megaAVR0::Clock::Prescaler clock_prescaler_configuration ) noexcept
{
    ::picolibrary::Microchip::megaAVR0::Clock::set_source(
        ::picolibrary::Microchip::megaAVR0::Clock::Source::INTERNAL_16_20_MHz_OSCILLATOR );
    ::picolibrary::Microchip::megaAVR0::Clock::configure_prescaler(
        clock_prescaler_value, clock_prescaler_configuration );

    while ( ::picolibrary::Microchip::megaAVR0::Clock::source_changing() ) {} // while
}

#if defined( PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_CONFIGURE_CLOCK_CLOCK_PRESCALER_VALUE ) \
    && defined( PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_CONFIGURE_CLOCK_CLOCK_PRESCALER_CONFIGURATION )
/**
 * \brief Configure the clock to use the internal 16/20 MHz oscillator with the
 *        pre-provided clock prescaler settings.
 */
inline void configure_clock() noexcept
{
    configure_clock(
        ::picolibrary::Microchip::megaAVR0::Clock::Prescaler_Value::PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_CONFIGURE_CLOCK_CLOCK_PRESCALER_VALUE,
        ::picolibrary::Microchip::megaAVR0::Clock::Prescaler::PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_CONFIGURE_CLOCK_CLOCK_PRESCALER_CONFIGURATION );
}
#endif // defined( PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_CONFIGURE_CLOCK_CLOCK_PRESCALER_VALUE
       // ) && defined( PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_CONFIGURE_CLOCK_CLOCK_PRESCALER_CONFIGURATION )

} // namespace picolibrary::Testing::Interactive::Microchip::megaAVR0

#endif // PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_CLOCK_H
