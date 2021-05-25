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
 * \brief picolibrary::Microchip::megaAVR0::Register interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_REGISTER_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_REGISTER_H

#include <cstdint>
#include <type_traits>

namespace picolibrary::Microchip::megaAVR0 {

/**
 * \brief A Microchip megaAVR 0-series register.
 *
 * \tparam T The register's underlying integral type.
 */
template<typename T>
class Register {
  public:
    /**
     * \brief The register's underlying integral type.
     */
    using Type = T;

    Register() = delete;

    Register( Register && ) = delete;

    Register( Register const & ) = delete;

    ~Register() = delete;

    auto operator=( Register && ) = delete;

    auto operator=( Register const & ) = delete;

    /**
     * \brief Read the register.
     *
     * \return The register contents.
     */
    operator Type() const noexcept
    {
        return m_register;
    }

    /**
     * \brief Assignment operator.
     *
     * \param[in] expression The expression to assign to the register.
     *
     * \return The assigned to object.
     */
    auto & operator=( Type expression ) noexcept
    {
        m_register = expression;

        return *this;
    }

    /**
     * \brief Bitwise AND assignment operator.
     *
     * \param[in] expression The expression to bitwise AND into the register.
     *
     * \return The assigned to object.
     */
    auto & operator&=( Type expression ) noexcept
    {
        m_register &= expression;

        return *this;
    }

    /**
     * \brief Bitwise OR assignment operator.
     *
     * \param[in] expression The expression to bitwise OR into the register.
     *
     * \return The assigned to object.
     */
    auto & operator|=( Type expression ) noexcept
    {
        m_register |= expression;

        return *this;
    }

    /**
     * \brief Bitwise XOR assignment operator.
     *
     * \param[in] expression The expression to bitwise XOR into the register.
     *
     * \return The assigned to object.
     */
    auto & operator^=( Type expression ) noexcept
    {
        m_register ^= expression;

        return *this;
    }

  private:
    /**
     * \brief The register.
     */
    Type volatile m_register;
};

/**
 * \brief A Microchip megaAVR 0-series reserved register.
 *
 * \tparam T The reserved register's underlying integral type.
 */
template<typename T>
class Reserved_Register {
  public:
    /**
     * \brief The reserved register's underlying integral type.
     */
    using Type = T;

    Reserved_Register() = delete;

    Reserved_Register( Reserved_Register && ) = delete;

    Reserved_Register( Reserved_Register const & ) = delete;

    ~Reserved_Register() = delete;

    auto operator=( Reserved_Register && ) = delete;

    auto operator=( Reserved_Register const & ) = delete;

  private:
    /**
     * \brief The reserved register.
     */
    Type volatile m_reserved_register;
};

/**
 * \brief A Microchip megaAVR 0-series protected register.
 *
 * \tparam T The protected register's underlying integral type (must be std::uint8_t).
 */
template<typename T>
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
    auto & operator=( Type expression ) noexcept
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
    auto & operator&=( Type expression ) noexcept
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
    auto & operator|=( Type expression ) noexcept
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
    auto & operator^=( Type expression ) noexcept
    {
        write( m_protected_register ^ expression );

        return *this;
    }

  private:
    /**
     * \brief CPU peripheral address.
     */
    static constexpr auto CPU_ADDRESS = std::uint16_t{ 0x0030 };

    /**
     * \brief CPU peripheral CCP register offset.
     */
    static constexpr auto CPU_CCP_OFFSET = std::uint8_t{ 0x04 };

    /**
     * \brief CPU peripheral CCP register address.
     */
    static constexpr auto CPU_CCP_ADDRESS = std::uint16_t{ CPU_ADDRESS + CPU_CCP_OFFSET };

    /**
     * \brief CPU peripheral CCP register unlock protected I/O registers signature.
     */
    static constexpr auto CPU_CCP_UNLOCK_PROTECTED_IO_REGISTERS = std::uint8_t{ 0xD8 };

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
              [ cpu_ccp_unlock_protected_io_registers ] "d"( CPU_CCP_UNLOCK_PROTECTED_IO_REGISTERS ),
              [ protected_register_address ] "n"( &m_protected_register ),
              [ protected_register_data ] "r"( data ) );
    }
};

} // namespace picolibrary::Microchip::megaAVR0

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_REGISTER_H
