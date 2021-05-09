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

#include "picolibrary/bit_manipulation.h"
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

/**
 * \brief Internally pulled-up input pin.
 */
class Internally_Pulled_Up_Input_Pin {
  public:
    /**
     * \brief Initial internal pull-up resistor state.
     */
    using Initial_Pull_Up_State = ::picolibrary::GPIO::Initial_Pull_Up_State;

    /**
     * \brief Constructor.
     */
    constexpr Internally_Pulled_Up_Input_Pin() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] port The GPIO port the pin is a member of.
     * \param[in] mask The mask identifying the pin.
     */
    constexpr Internally_Pulled_Up_Input_Pin( Peripheral::PORT & port, std::uint8_t mask ) noexcept :
        m_port{ &port },
        m_mask{ mask },
        m_n{ highest_bit_set( mask ) }
    {
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Internally_Pulled_Up_Input_Pin( Internally_Pulled_Up_Input_Pin && source ) noexcept :
        m_port{ source.m_port },
        m_mask{ source.m_mask },
        m_n{ source.m_n }
    {
        source.m_port = nullptr;
        source.m_mask = 0;
        source.m_n    = 0;
    }

    Internally_Pulled_Up_Input_Pin( Internally_Pulled_Up_Input_Pin const & ) = delete;

    /**
     * \brief Destructor.
     */
    ~Internally_Pulled_Up_Input_Pin() noexcept
    {
        disable();
    }

    /**
     * \brief Assignment operator.
     *
     * \param[in] expression The expression to be assigned.
     *
     * \return The assigned to object.
     */
    auto & operator=( Internally_Pulled_Up_Input_Pin && expression ) noexcept
    {
        if ( &expression != this ) {
            disable();

            m_port = expression.m_port;
            m_mask = expression.m_mask;
            m_n    = expression.m_n;

            expression.m_port = nullptr;
            expression.m_mask = 0;
            expression.m_n    = 0;
        } // if

        return *this;
    }

    auto operator=( Internally_Pulled_Up_Input_Pin const & ) = delete;

    /**
     * \brief Initialize the pin's hardware.
     *
     * \param[in] initial_pull_up_state The initial state of the pin's internal pull-up
     *            resistor.
     *
     * \return Success.
     */
    auto initialize( Initial_Pull_Up_State initial_pull_up_state = Initial_Pull_Up_State::DISABLED ) noexcept
        -> Result<Void, Void>
    {
        m_port->configure_pin_as_internally_pulled_up_input( m_mask );

        switch ( initial_pull_up_state ) {
            case Initial_Pull_Up_State::ENABLED: m_port->enable_pull_up( m_n ); break;
            case Initial_Pull_Up_State::DISABLED: m_port->disable_pull_up( m_n ); break;
        } // switch

        return {};
    }

    /**
     * \brief Enable the pin's internal pull-up resistor.
     *
     * \return Success.
     */
    auto enable_pull_up() noexcept -> Result<Void, Void>
    {
        m_port->enable_pull_up( m_n );

        return {};
    }

    /**
     * \brief Disable the pin's internal pull-up resistor.
     *
     * \return Success.
     */
    auto disable_pull_up() noexcept -> Result<Void, Void>
    {
        m_port->disable_pull_up( m_n );

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
    Peripheral::PORT * m_port{};

    /**
     * \brief The mask identifying the pin.
     */
    std::uint8_t m_mask{};

    /**
     * \brief The pin number.
     */
    std::uint_fast8_t m_n{};

    /**
     * \brief Disable the pin's internal pull-up resistor.
     */
    void disable() noexcept
    {
        if ( m_port ) {
            m_port->disable_pull_up( m_n );
        } // if
    }
};

/**
 * \brief Open-drain Input/Output (I/O) pin.
 *
 * \tparam Peripheral The type of peripheral used to implement open-drain I/O pin
 *         functionality (must be picolibrary::Microchip::megaAVR0::Peripheral::PORT or
 *         picolibrary::Microchip::megaAVR0::Peripheral::VPORT).
 */
template<typename Peripheral>
class Open_Drain_IO_Pin {
  public:
    static_assert(
        std::is_same_v<Peripheral, ::picolibrary::Microchip::megaAVR0::Peripheral::PORT> or std::is_same_v<Peripheral, ::picolibrary::Microchip::megaAVR0::Peripheral::VPORT> );

    /**
     * \brief Initial pin state.
     */
    using Initial_Pin_State = ::picolibrary::GPIO::Initial_Pin_State;

    /**
     * \brief Constructor.
     */
    constexpr Open_Drain_IO_Pin() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] port The GPIO port the pin is a member of.
     * \param[in] mask The mask identifying the pin.
     */
    constexpr Open_Drain_IO_Pin( Peripheral & port, std::uint8_t mask ) noexcept :
        m_port{ &port },
        m_mask{ mask }
    {
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Open_Drain_IO_Pin( Open_Drain_IO_Pin && source ) noexcept :
        m_port{ source.m_port },
        m_mask{ source.m_mask }
    {
        source.m_port = nullptr;
        source.m_mask = 0;
    }

    Open_Drain_IO_Pin( Open_Drain_IO_Pin const & ) = delete;

    /**
     * \brief Destructor.
     */
    ~Open_Drain_IO_Pin() noexcept
    {
        disable();
    }

    /**
     * \brief Assignment operator.
     *
     * \param[in] expression The expression to be assigned.
     *
     * \return The assigned to object.
     */
    auto & operator=( Open_Drain_IO_Pin && expression ) noexcept
    {
        if ( &expression != this ) {
            disable();

            m_port = expression.m_port;
            m_mask = expression.m_mask;

            expression.m_port = nullptr;
            expression.m_mask = 0;
        } // if

        return *this;
    }

    auto operator=( Open_Drain_IO_Pin const & ) = delete;

    /**
     * \brief Initialize the pin's hardware.
     *
     * \param[in] initial_pin_state The initial state of the pin.
     *
     * \return Success.
     */
    auto initialize( Initial_Pin_State initial_pin_state = Initial_Pin_State::LOW ) noexcept
        -> Result<Void, Void>
    {
        m_port->configure_pin_as_open_drain_io( m_mask );

        switch ( initial_pin_state ) {
            case Initial_Pin_State::HIGH:
                m_port->transition_open_drain_io_to_high( m_mask );
                break;
            case Initial_Pin_State::LOW:
                m_port->transition_open_drain_io_to_low( m_mask );
                break;
        } // switch

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

    /**
     * \brief Transition the pin to the high state.
     *
     * \return Success.
     */
    auto transition_to_high() noexcept -> Result<Void, Void>
    {
        m_port->transition_open_drain_io_to_high( m_mask );

        return {};
    }

    /**
     * \brief Transition the pin to the low state.
     *
     * \return Success.
     */
    auto transition_to_low() noexcept -> Result<Void, Void>
    {
        m_port->transition_open_drain_io_to_low( m_mask );

        return {};
    }

    /**
     * \brief Toggle the pin state.
     *
     * \return Success.
     */
    auto toggle() noexcept -> Result<Void, Void>
    {
        m_port->toggle_open_drain_io( m_mask );

        return {};
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

    /**
     * \brief Disable the pin.
     */
    void disable() noexcept
    {
        if ( m_port ) {
            m_port->configure_pin_as_input( m_mask );
        } // if
    }
};

/**
 * \brief Push-pull Input/Output (I/O) pin.
 *
 * \tparam Peripheral The type of peripheral used to implement push-pull I/O pin
 *         functionality (must be picolibrary::Microchip::megaAVR0::Peripheral::PORT or
 *         picolibrary::Microchip::megaAVR0::Peripheral::VPORT).
 */
template<typename Peripheral>
class Push_Pull_IO_Pin {
  public:
    static_assert(
        std::is_same_v<Peripheral, ::picolibrary::Microchip::megaAVR0::Peripheral::PORT> or std::is_same_v<Peripheral, ::picolibrary::Microchip::megaAVR0::Peripheral::VPORT> );

    /**
     * \brief Initial pin state.
     */
    using Initial_Pin_State = ::picolibrary::GPIO::Initial_Pin_State;

    /**
     * \brief Constructor.
     */
    constexpr Push_Pull_IO_Pin() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] port The GPIO port the pin is a member of.
     * \param[in] mask The mask identifying the pin.
     */
    constexpr Push_Pull_IO_Pin( Peripheral & port, std::uint8_t mask ) noexcept :
        m_port{ &port },
        m_mask{ mask }
    {
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Push_Pull_IO_Pin( Push_Pull_IO_Pin && source ) noexcept :
        m_port{ source.m_port },
        m_mask{ source.m_mask }
    {
        source.m_port = nullptr;
        source.m_mask = 0;
    }

    Push_Pull_IO_Pin( Push_Pull_IO_Pin const & ) = delete;

    /**
     * \brief Destructor.
     */
    ~Push_Pull_IO_Pin() noexcept
    {
        disable();
    }

    /**
     * \brief Assignment operator.
     *
     * \param[in] expression The expression to be assigned.
     *
     * \return The assigned to object.
     */
    auto & operator=( Push_Pull_IO_Pin && expression ) noexcept
    {
        if ( &expression != this ) {
            disable();

            m_port = expression.m_port;
            m_mask = expression.m_mask;

            expression.m_port = nullptr;
            expression.m_mask = 0;
        } // if

        return *this;
    }

    auto operator=( Push_Pull_IO_Pin const & ) = delete;

    /**
     * \brief Initialize the pin's hardware.
     *
     * \param[in] initial_pin_state The initial state of the pin.
     *
     * \return Success.
     */
    auto initialize( Initial_Pin_State initial_pin_state = Initial_Pin_State::LOW ) noexcept
        -> Result<Void, Void>
    {
        switch ( initial_pin_state ) {
            case Initial_Pin_State::HIGH:
                m_port->transition_push_pull_io_to_high( m_mask );
                break;
            case Initial_Pin_State::LOW:
                m_port->transition_push_pull_io_to_low( m_mask );
                break;
        } // switch

        m_port->configure_pin_as_push_pull_io( m_mask );

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

    /**
     * \brief Transition the pin to the high state.
     *
     * \return Success.
     */
    auto transition_to_high() noexcept -> Result<Void, Void>
    {
        m_port->transition_push_pull_io_to_high( m_mask );

        return {};
    }

    /**
     * \brief Transition the pin to the low state.
     *
     * \return Success.
     */
    auto transition_to_low() noexcept -> Result<Void, Void>
    {
        m_port->transition_push_pull_io_to_low( m_mask );

        return {};
    }

    /**
     * \brief Toggle the pin state.
     *
     * \return Success.
     */
    auto toggle() noexcept -> Result<Void, Void>
    {
        m_port->toggle_push_pull_io( m_mask );

        return {};
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

    /**
     * \brief Disable the pin.
     */
    void disable() noexcept
    {
        if ( m_port ) {
            m_port->configure_pin_as_input( m_mask );
        } // if
    }
};

} // namespace picolibrary::Microchip::megaAVR0::GPIO

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_H
