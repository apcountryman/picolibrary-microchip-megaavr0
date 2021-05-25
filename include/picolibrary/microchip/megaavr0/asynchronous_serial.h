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
 * \brief picolibrary::Microchip::megaAVR0::Asynchronous_Serial interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_H

#include <cstdint>

#include "picolibrary/microchip/megaavr0/peripheral/usart.h"

/**
 * \brief Microchip megaAVR 0-series asynchronous serial facilities.
 */
namespace picolibrary::Microchip::megaAVR0::Asynchronous_Serial {

/**
 * \brief Microchip megaAVR 0-series asynchronous serial clock configuration.
 */
struct Clock_Configuration {
    /**
     * \brief The clock generator operating speed.
     */
    Peripheral::USART::Operating_Speed operating_speed;

    /**
     * \brief The clock generator scaling factor.
     */
    std::uint16_t scaling_factor;
};

} // namespace picolibrary::Microchip::megaAVR0::Asynchronous_Serial

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_H
