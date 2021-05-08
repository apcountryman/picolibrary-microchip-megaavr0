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
 * \brief picolibrary::Microchip::megaAVR0::GPIO interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_H

#include <cstdint>
#include <type_traits>

#include "picolibrary/gpio.h"
#include "picolibrary/microchip/megaavr0/peripheral/port.h"
#include "picolibrary/microchip/megaavr0/peripheral/vport.h"
#include "picolibrary/result.h"
#include "picolibrary/void.h"

/**
 * \brief Microchip megaAVR 0-series General Purpose Input/Output (GPIO) facilities.
 */
namespace picolibrary::Microchip::megaAVR0::GPIO {

/**
 * \brief Input pin.
 *
 * \tparam Peripheral The type of peripheral used to implement input pin functionality
 *         (must be picolibrary::Microchip::megaAVR0::Peripheral::PORT or
 *         picolibrary::Microchip::megaAVR0::Peripheral::VPORT).
 */
template<typename Peripheral>
class Input_Pin {
  public:
    static_assert(
        std::is_same_v<Peripheral, ::picolibrary::Microchip::megaAVR0::Peripheral::PORT> or std::is_same_v<Peripheral, ::picolibrary::Microchip::megaAVR0::Peripheral::VPORT> );

    /**
     * \brief Constructor.
     */
    constexpr Input_Pin() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] port The GPIO port the pin is a member of.
     * \param[in] mask The mask identifying the pin.
     */
    constexpr Input_Pin( Peripheral & port, std::uint8_t mask ) noexcept :
        m_port{ &port },
        m_mask{ mask }
    {
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Input_Pin( Input_Pin && source ) noexcept :
        m_port{ source.m_port },
        m_mask{ source.m_mask }
    {
        source.m_port = nullptr;
        source.m_mask = 0;
    }

    Input_Pin( Input_Pin const & ) = delete;

    /**
     * \brief Destructor.
     */
    ~Input_Pin() noexcept = default;

    /**
     * \brief Assignment operator.
     *
     * \param[in] expression The expression to be assigned.
     *
     * \return The assigned to object.
     */
    constexpr auto & operator=( Input_Pin && expression ) noexcept
    {
        if ( &expression != this ) {
            m_port = expression.m_port;
            m_mask = expression.m_mask;

            expression.m_port = nullptr;
            expression.m_mask = 0;
        } // if

        return *this;
    }

    auto operator=( Input_Pin const & ) = delete;

    /**
     * \brief Initialize the pin's hardware.
     *
     * \return Success.
     */
    auto initialize() noexcept -> Result<Void, Void>
    {
        m_port->configure_pin_as_input( m_mask );

        return {};
    }

    /**
     * \brief Get the state of the pin.
     *
     * \return High if the pin is high.
     * \return Low if the pin is low.
     */
    auto state() const noexcept -> Result<::picolibrary::GPIO::Pin_State, Void>
    {
        return static_cast<bool>( m_port->state( m_mask ) );
    }

  private:
    /**
     * \brief The GPIO port the pin is a member of.
     */
    Peripheral * m_port{};

    /**
     * \brief The mask identifying the pin.
     */
    std::uint8_t m_mask{};
};

} // namespace picolibrary::Microchip::megaAVR0::GPIO

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_H
