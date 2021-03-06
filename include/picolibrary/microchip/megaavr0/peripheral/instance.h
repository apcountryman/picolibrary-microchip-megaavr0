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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::Instance interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_INSTANCE_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_INSTANCE_H

#include <cstdint>

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series peripheral instance.
 *
 * \tparam T The peripheral type.
 * \tparam INSTANCE_ADDRESS The address of the peripheral instance.
 */
template<typename T, std::uintptr_t INSTANCE_ADDRESS>
class Instance {
  public:
    /**
     * \brief The peripheral type.
     */
    using Type = T;

    /**
     * \brief The address of the peripheral instance.
     */
    static constexpr auto ADDRESS = INSTANCE_ADDRESS;

    /**
     * \brief Access the peripheral instance.
     *
     * \return The peripheral instance.
     */
    static auto instance() noexcept -> Type &
    {
        return *reinterpret_cast<Type *>( ADDRESS );
    }

    Instance() = delete;

    Instance( Instance && ) = delete;

    Instance( Instance const & ) = delete;

    ~Instance() = delete;

    auto operator=( Instance && ) = delete;

    auto operator=( Instance const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_INSTANCE_H
