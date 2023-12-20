/**
 * picolibrary-microchip-megaavr0
 *
 * Copyright 2021-2023, Andrew Countryman <apcountryman@gmail.com> and the
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
 * \brief picolibrary::Microchip::megaAVR0 register interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_REGISTER_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_REGISTER_H

#include <cstdint>
#include <type_traits>

#include "picolibrary/utility.h"

namespace picolibrary::Microchip::megaAVR0 {

/**
 * \brief Microchip megaAVR 0-series CPU peripheral CCP register key.
 */
enum class CPU_CCP_Key : std::uint8_t {
    SPM   = 0x9D, ///< Allow self-programming.
    IOREG = 0xD8, ///< Unlock protected I/O registers.
};

/**
 * \brief A Microchip megaAVR 0-series protected register.
 *
 * \tparam T The protected register's underlying integral type (must be std::uint8_t).
 * \tparam CPU_CCP_KEY The protected register's CPU peripheral CCP register key.
 */
template<typename T, CPU_CCP_Key CPU_CCP_KEY>
class Protected_Register {
  public:
    static_assert( std::is_same_v<T, std::uint8_t> );

    /**
     * \brief The protected register's underlying integral type.
     */
    using Type = T;

    Protected_Register() = delete;

    Protected_Register( Protected_Register && ) = delete;

    Protected_Register( Protected_Register const & ) = delete;

    ~Protected_Register() = delete;

    auto operator=( Protected_Register && ) = delete;

    auto operator=( Protected_Register const & ) = delete;

    /**
     * \brief Read the protected register.
     *
     * \return The protected register contents.
     */
    operator Type() const noexcept
    {
        return m_protected_register;
    }

    /**
     * \brief Assignment operator.
     *
     * \param[in] expression The expression to assign to the protected register.
     *
     * \return The assigned to object.
     */
    auto operator=( Type expression ) noexcept -> Protected_Register &
    {
        write( expression );

        return *this;
    }

    /**
     * \brief Bitwise AND assignment operator.
     *
     * \param[in] expression The expression to bitwise AND into the protected register.
     *
     * \return The assigned to object.
     */
    auto operator&=( Type expression ) noexcept -> Protected_Register &
    {
        write( m_protected_register & expression );

        return *this;
    }

    /**
     * \brief Bitwise OR assignment operator.
     *
     * \param[in] expression The expression to bitwise OR into the protected register.
     *
     * \return The assigned to object.
     */
    auto operator|=( Type expression ) noexcept -> Protected_Register &
    {
        write( m_protected_register | expression );

        return *this;
    }

    /**
     * \brief Bitwise XOR assignment operator.
     *
     * \param[in] expression The expression to bitwise XOR into the protected register.
     *
     * \return The assigned to object.
     */
    auto operator^=( Type expression ) noexcept -> Protected_Register &
    {
        write( m_protected_register ^ expression );

        return *this;
    }

  private:
    /**
     * \brief CPU peripheral address.
     */
    static constexpr auto CPU_ADDRESS = std::uintptr_t{ 0x0030 };

    /**
     * \brief CPU peripheral CCP register offset.
     */
    static constexpr auto CPU_CCP_OFFSET = std::uint8_t{ 0x04 };

    /**
     * \brief CPU peripheral CCP register address.
     */
    static constexpr auto CPU_CCP_ADDRESS = std::uintptr_t{ CPU_ADDRESS + CPU_CCP_OFFSET };

    /**
     * \brief The protected register.
     */
    Type volatile m_protected_register;

    /**
     * \brief Write to the protected register.
     *
     * \param[in] data The data to write to the protected register.
     */
    void write( Type data ) noexcept
    {
        asm volatile(
            "out %[cpu_ccp_address], %[cpu_ccp_unlock_protected_io_registers] \n\t"
            "sts %[protected_register_address], %[protected_register_data]"
            :
            : [ cpu_ccp_address ] "I"( CPU_CCP_ADDRESS ),
              [ cpu_ccp_unlock_protected_io_registers ] "d"( to_underlying( CPU_CCP_KEY ) ),
              [ protected_register_address ] "n"( &m_protected_register ),
              [ protected_register_data ] "r"( data ) );
    }
};

} // namespace picolibrary::Microchip::megaAVR0

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_REGISTER_H
