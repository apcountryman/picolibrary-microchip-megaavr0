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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::SYSCFG interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_SYSCFG_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_SYSCFG_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series System Configuration (SYSCFG) peripheral.
 */
class SYSCFG {
  public:
    /**
     * \brief Reserved registers (offset 0x00-0x00).
     */
    Reserved_Register<std::uint8_t> const reserved_0x00_0x00[ ( 0x00 - 0x00 ) + 1 ];

    /**
     * \brief Device Revision ID (REVID) register.
     */
    Register<std::uint8_t> const revid;

    SYSCFG() = delete;

    SYSCFG( SYSCFG && ) = delete;

    SYSCFG( SYSCFG const & ) = delete;

    ~SYSCFG() = delete;

    auto operator=( SYSCFG && ) = delete;

    auto operator=( SYSCFG const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_SYSCFG_H
