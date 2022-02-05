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
 * \brief picolibrary::Microchip::megaAVR0::GPIO interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_H

#include <cstdint>

#include "picolibrary/microchip/megaavr0/peripheral/port.h"
#include "picolibrary/microchip/megaavr0/peripheral/vport.h"

/**
 * \brief Microchip megaAVR 0-series General Purpose Input/Output (GPIO) facilities.
 */
namespace picolibrary::Microchip::megaAVR0::GPIO {

/**
 * \brief Pin.
 *
 * \tparam Peripheral The type of peripheral used to implement pin functionality (must be
 *         picolibrary::Microchip::megaAVR0::Peripheral::PORT or
 *         picolibrary::Microchip::megaAVR0::Peripheral::VPORT).
 */
template<typename Peripheral>
class Pin;

/**
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::PORT based pin.
 */
template<>
class Pin<Peripheral::PORT> {
  public:
    /**
     * \brief Constructor.
     */
    constexpr Pin() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] port The GPIO port the pin is a member of.
     * \param[in] mask The mask identifying the pin.
     */
    constexpr Pin( Peripheral::PORT & port, std::uint8_t mask ) noexcept :
        m_port{ &port },
        m_mask{ mask }
    {
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Pin( Pin && source ) noexcept :
        m_port{ source.m_port },
        m_mask{ source.m_mask }
    {
        source.m_port = nullptr;
        source.m_mask = 0;
    }

    Pin( Pin const & ) = delete;

    /**
     * \brief Destructor.
     */
    ~Pin() noexcept = default;

    /**
     * \brief Assignment operator.
     *
     * \param[in] expression The expression to be assigned.
     *
     * \return The assigned to object.
     */
    constexpr auto & operator=( Pin && expression ) noexcept
    {
        if ( &expression != this ) {
            m_port = expression.m_port;
            m_mask = expression.m_mask;

            expression.m_port = nullptr;
            expression.m_mask = 0;
        } // if

        return *this;
    }

    auto operator=( Pin const & ) = delete;

    /**
     * \brief Check if the pin is associated with a GPIO port.
     *
     * \return true if the pin is associated with a GPIO port.
     * \return false if the pin is not associated with a GPIO port.
     */
    constexpr explicit operator bool() const noexcept
    {
        return m_port;
    }

    /**
     * \brief Configure the pin to act as an input.
     */
    void configure_pin_as_input() noexcept
    {
        m_port->dirclr = m_mask;
    }

    /**
     * \brief Check if the pin is in the low state.
     *
     * \return true if the pin is in the low state.
     * \return false if the pin is not in the low state.
     */
    auto is_low() const noexcept
    {
        return not is_high();
    }

    /**
     * \brief Check if the pin is in the high state.
     *
     * \return true if the pin is in the high state.
     * \return false if the pin is not in the high state.
     */
    auto is_high() const noexcept -> bool
    {
        return m_port->in & m_mask;
    }

  private:
    /**
     * \brief The GPIO port the pin is a member of.
     */
    Peripheral::PORT * m_port{};

    /**
     * \brief The mask identifying the pin.
     */
    std::uint8_t m_mask{};
};

/**
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::VPORT based pin.
 */
template<>
class Pin<Peripheral::VPORT> {
  public:
    /**
     * \brief Constructor.
     */
    constexpr Pin() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] port The GPIO virtual port the pin is a member of.
     * \param[in] mask The mask identifying the pin.
     */
    constexpr Pin( Peripheral::VPORT & vport, std::uint8_t mask ) noexcept :
        m_vport{ &vport },
        m_mask{ mask }
    {
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Pin( Pin && source ) noexcept :
        m_vport{ source.m_vport },
        m_mask{ source.m_mask }
    {
        source.m_vport = nullptr;
        source.m_mask  = 0;
    }

    Pin( Pin const & ) = delete;

    /**
     * \brief Destructor.
     */
    ~Pin() noexcept = default;

    /**
     * \brief Assignment operator.
     *
     * \param[in] expression The expression to be assigned.
     *
     * \return The assigned to object.
     */
    constexpr auto & operator=( Pin && expression ) noexcept
    {
        if ( &expression != this ) {
            m_vport = expression.m_vport;
            m_mask  = expression.m_mask;

            expression.m_vport = nullptr;
            expression.m_mask  = 0;
        } // if

        return *this;
    }

    auto operator=( Pin const & ) = delete;

    /**
     * \brief Check if the pin is associated with a GPIO virtual port.
     *
     * \return true if the pin is associated with a GPIO virtual port.
     * \return false if the pin is not associated with a GPIO virtual port.
     */
    constexpr explicit operator bool() const noexcept
    {
        return m_vport;
    }

    /**
     * \brief Configure the pin to act as an input.
     */
    void configure_pin_as_input() noexcept
    {
        m_vport->dir &= ~m_mask;
    }

    /**
     * \brief Check if the pin is in the low state.
     *
     * \return true if the pin is in the low state.
     * \return false if the pin is not in the low state.
     */
    auto is_low() const noexcept
    {
        return not is_high();
    }

    /**
     * \brief Check if the pin is in the high state.
     *
     * \return true if the pin is in the high state.
     * \return false if the pin is not in the high state.
     */
    auto is_high() const noexcept -> bool
    {
        return m_vport->in & m_mask;
    }

  private:
    /**
     * \brief The GPIO virtual port the pin is a member of.
     */
    Peripheral::VPORT * m_vport{};

    /**
     * \brief The mask identifying the pin.
     */
    std::uint8_t m_mask{};
};

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
    /**
     * \brief Constructor.
     */
    constexpr Input_Pin() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] port The GPIO port or virtual port the pin is a member of.
     * \param[in] mask The mask identifying the pin.
     */
    constexpr Input_Pin( Peripheral & port, std::uint8_t mask ) noexcept :
        m_pin{ port, mask }
    {
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Input_Pin( Input_Pin && source ) noexcept = default;

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
    constexpr auto operator=( Input_Pin && expression ) noexcept -> Input_Pin & = default;

    auto operator=( Input_Pin const & ) = delete;

    /**
     * \brief Initialize the pin's hardware.
     */
    void initialize() noexcept
    {
        m_pin.configure_pin_as_input();
    }

    /**
     * \brief Check if the pin is in the low state.
     *
     * \return true if the pin is in the low state.
     * \return false if the pin is not in the low state.
     */
    auto is_low() const noexcept
    {
        return m_pin.is_low();
    }

    /**
     * \brief Check if the pin is in the high state.
     *
     * \return true if the pin is in the high state.
     * \return false if the pin is not in the high state.
     */
    auto is_high() const noexcept
    {
        return m_pin.is_high();
    }

  private:
    /**
     * \brief The pin.
     */
    Pin<Peripheral> m_pin{};
};

} // namespace picolibrary::Microchip::megaAVR0::GPIO

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_H
