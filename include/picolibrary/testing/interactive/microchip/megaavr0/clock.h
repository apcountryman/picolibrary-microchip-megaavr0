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
 * \brief picolibrary::Testing::Interactive::Microchip::megaAVR0::Clock interface.
 */

#ifndef PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_CLOCK_H
#define PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_CLOCK_H

#include "picolibrary/microchip/megaavr0/clock.h"

namespace picolibrary::Testing::Interactive::Microchip::megaAVR0 {

/**
 * \brief Configure the clock to use the internal 16/20 MHz oscillator with the provided
 *        clock prescaler settings.
 *
 * \param[in] value The desired clock prescaler value.
 * \param[in] configuration The desired clock prescaler configuration.
 */
inline void configure_clock(
    ::picolibrary::Microchip::megaAVR0::Clock::Prescaler_Value value,
    ::picolibrary::Microchip::megaAVR0::Clock::Prescaler       configuration ) noexcept
{
    ::picolibrary::Microchip::megaAVR0::Clock::set_source(
        ::picolibrary::Microchip::megaAVR0::Clock::Source::INTERNAL_16_20_MHZ_OSCILLATOR );
    ::picolibrary::Microchip::megaAVR0::Clock::configure_prescaler( value, configuration );

    while ( ::picolibrary::Microchip::megaAVR0::Clock::source_changing() ) {} // while
}

} // namespace picolibrary::Testing::Interactive::Microchip::megaAVR0

#endif // PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_CLOCK_H
