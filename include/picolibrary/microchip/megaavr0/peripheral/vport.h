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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::VPORT interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_VPORT_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_VPORT_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr0/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series I/O Pin Configuration (PORT) Virtual PORT (VPORT)
 *        peripheral.
 */
class VPORT {
  public:
    /**
     * \brief Data Direction (DIR) register.
     */
    Register<std::uint8_t> dir;

    /**
     * \brief Output Value (OUT) register.
     */
    Register<std::uint8_t> out;

    /**
     * \brief Input Value (IN) register.
     */
    Register<std::uint8_t> in;

    /**
     * \brief Interrupt Flags (INTFLAGS) register.
     */
    Register<std::uint8_t> intflags;

    VPORT() = delete;

    VPORT( VPORT && ) = delete;

    VPORT( VPORT const & ) = delete;

    ~VPORT() = delete;

    auto operator=( VPORT && ) = delete;

    auto operator=( VPORT const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_VPORT_H
