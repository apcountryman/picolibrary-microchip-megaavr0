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

} // namespace picolibrary::Microchip::megaAVR0

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_REGISTER_H
