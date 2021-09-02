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
 * \brief picolibrary::Microchip::megaAVR0::Reset_Controller interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_RESET_CONTROLLER_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_RESET_CONTROLLER_H

#include <cstdint>

#include "picolibrary/microchip/megaavr0/peripheral.h"
#include "picolibrary/microchip/megaavr0/peripheral/rstctrl.h"

/**
 * \brief Microchip megaAVR 0-series reset controller facilities.
 */
namespace picolibrary::Microchip::megaAVR0::Reset_Controller {

/**
 * \brief Reset source masks.
 */
using Reset_Source = Peripheral::RSTCTRL::Reset_Source;

/**
 * \brief Get the source of a reset or the source(s) of a series of resets.
 *
 * \return A mask identifying the source of the reset or the source(s) of the series of
 *         resets.
 */
inline auto reset_sources() noexcept
{
    return Peripheral::RSTCTRL0::instance().reset_sources();
}

/**
 * \brief Clear the source of a reset or the source(s) of a series of resets.
 *
 * \param[in] reset_sources The mask identifying the reset source(s) to clear.
 */
inline void clear_reset_sources( std::uint8_t reset_sources = Reset_Source::ALL ) noexcept
{
    Peripheral::RSTCTRL0::instance().clear_reset_sources( reset_sources );
}

/**
 * \brief Perform a software reset.
 */
[[noreturn]] inline void reset() noexcept
{
    Peripheral::RSTCTRL0::instance().reset();
}

} // namespace picolibrary::Microchip::megaAVR0::Reset_Controller

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_RESET_CONTROLLER_H
