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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::SYSCFG interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_SYSCFG_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_SYSCFG_H

#include <cstdint>

#include "picolibrary/microchip/megaavr0/peripheral/instance.h"
#include "picolibrary/microchip/megaavr0/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

#ifdef SYSCFG
#undef SYSCFG
#endif // SYSCFG

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
    Register<std::uint8_t> revid;

    SYSCFG() = delete;

    SYSCFG( SYSCFG && ) = delete;

    SYSCFG( SYSCFG const & ) = delete;

    ~SYSCFG() = delete;

    auto operator=( SYSCFG && ) = delete;

    auto operator=( SYSCFG const & ) = delete;

    /**
     * \brief Get the device revision.
     *
     * \return The device revision.
     */
    auto device_revision() const noexcept -> char
    {
        return 'A' + revid;
    }
};

/**
 * \brief Microchip megaAVR 0-series System Configuration (SYSCFG) peripheral instance.
 *
 * \tparam INSTANCE_ADDRESS The address of the SYSCFG instance.
 */
template<std::uintptr_t INSTANCE_ADDRESS>
using SYSCFG_Instance = Instance<SYSCFG, INSTANCE_ADDRESS>;

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_SYSCFG_H
