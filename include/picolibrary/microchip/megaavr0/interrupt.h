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
 * \brief picolibrary::Microchip::megaAVR0::Interrupt interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_INTERRUPT_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_INTERRUPT_H

#include <avr-libcpp/interrupt>
#include <cstdint>

/**
 * \brief Microchip megaAVR 0-series interrupt facilities.
 */
namespace picolibrary::Microchip::megaAVR0::Interrupt {

/**
 * \brief Controller.
 */
class Controller {
  public:
    /**
     * \brief Interrupts enable state.
     */
    using Interrupt_Enable_State = std::uint8_t;

    /**
     * \brief Constructor.
     */
    constexpr Controller() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Controller( Controller && source ) noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] original The original to copy.
     */
    constexpr Controller( Controller const & original ) noexcept = default;

    /**
     * \brief Destructor.
     */
    ~Controller() noexcept = default;

    /**
     * \brief Assignment operator.
     *
     * \param[in] expression The expression to be assigned.
     *
     * \return The assigned to object.
     */
    constexpr auto operator=( Controller && expression ) noexcept -> Controller & = default;

    /**
     * \brief Assignment operator.
     *
     * \param[in] expression The expression to be assigned.
     *
     * \return The assigned to object.
     */
    constexpr auto operator=( Controller const & expression ) noexcept -> Controller & = default;

    /**
     * \brief Disable interrupts.
     */
    void disable_interrupt() noexcept
    {
        cli();
    }

    /**
     * \brief Enable interrupts.
     */
    void enable_interrupt() noexcept
    {
        sei();
    }

    /**
     * \brief Save the current interrupts enable state.
     *
     * \return The current interrupts enable state.
     */
    auto save_interrupt_enable_state() const noexcept -> Interrupt_Enable_State
    {
        return *reinterpret_cast<std::uint8_t const volatile *>( CPU_SREG_ADDRESS );
    }

    /**
     * \brief Restore the previously saved interrupts enable state.
     *
     * \param[in] interrupt_enable_state The previously saved interrupts enable state.
     */
    void restore_interrupt_enable_state( Interrupt_Enable_State interrupt_enable_state ) noexcept
    {
        *reinterpret_cast<std::uint8_t volatile *>( CPU_SREG_ADDRESS ) = interrupt_enable_state;

        asm volatile( "" ::: "memory" );
    }

  private:
    /**
     * \brief CPU peripheral address.
     */
    static constexpr auto CPU_ADDRESS = std::uintptr_t{ 0x0030 };

    /**
     * \brief CPU peripheral SREG register offset.
     */
    static constexpr auto CPU_SREG_OFFSET = std::uint8_t{ 0x0F };

    /**
     * \brief CPU peripheral SREG register address.
     */
    static constexpr auto CPU_SREG_ADDRESS = std::uintptr_t{ CPU_ADDRESS + CPU_SREG_OFFSET };
};

} // namespace picolibrary::Microchip::megaAVR0::Interrupt

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_INTERRUPT_H
