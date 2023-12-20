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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::CPUINT interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_CPUINT_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_CPUINT_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr0/register.h"
#include "picolibrary/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series CPU Interrupt Controller (CPUINT) peripheral.
 */
class CPUINT {
  public:
    /**
     * \brief Control A (CTRLA) register.
     *
     * This register has the following fields:
     * - Round Robin Priority Enable (LVL0RR)
     * - Compact Vector Table (CVT)
     * - Interrupt Vector Select (IVSEL)
     */
    class CTRLA : public Protected_Register<std::uint8_t, CPU_CCP_Key::IOREG> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto LVL0RR    = std::uint_fast8_t{ 1 }; ///< LVL0RR.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 4 }; ///< RESERVED1.
            static constexpr auto CVT       = std::uint_fast8_t{ 1 }; ///< CVT.
            static constexpr auto IVSEL     = std::uint_fast8_t{ 1 }; ///< IVSEL.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ 1 }; ///< RESERVED7.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto LVL0RR = std::uint_fast8_t{}; ///< LVL0RR.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ LVL0RR + Size::LVL0RR }; ///< RESERVED1.
            static constexpr auto CVT = std::uint_fast8_t{ RESERVED1 + Size::RESERVED1 }; ///< CVT.
            static constexpr auto IVSEL = std::uint_fast8_t{ CVT + Size::CVT }; ///< IVSEL.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ IVSEL + Size::IVSEL }; ///< RESERVED7.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto LVL0RR = mask<std::uint8_t>( Size::LVL0RR, Bit::LVL0RR ); ///< LVL0RR.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
            static constexpr auto CVT = mask<std::uint8_t>( Size::CVT, Bit::CVT ); ///< CVT.
            static constexpr auto IVSEL = mask<std::uint8_t>( Size::IVSEL, Bit::IVSEL ); ///< IVSEL.
            static constexpr auto RESERVED7 = mask<std::uint8_t>( Size::RESERVED7, Bit::RESERVED7 ); ///< RESERVED7.
        };

        CTRLA() = delete;

        CTRLA( CTRLA && ) = delete;

        CTRLA( CTRLA const & ) = delete;

        ~CTRLA() = delete;

        auto operator=( CTRLA && ) = delete;

        auto operator=( CTRLA const & ) = delete;

        using Protected_Register<std::uint8_t, CPU_CCP_Key::IOREG>::operator=;
    };

    /**
     * \brief Status (STATUS) register.
     *
     * This register has the following fields:
     * - Level 0 Interrupt Executing (LVL0EX)
     * - Level 1 Interrupt Executing (LVL1EX)
     * - Non-Maskable Interrupt Executing (NMIEX)
     */
    class STATUS : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto LVL0EX    = std::uint_fast8_t{ 1 }; ///< LVL0EX.
            static constexpr auto LVL1EX    = std::uint_fast8_t{ 1 }; ///< LVL1EX.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ 5 }; ///< RESERVED2.
            static constexpr auto NMIEX     = std::uint_fast8_t{ 1 }; ///< NMIEX.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto LVL0EX = std::uint_fast8_t{}; ///< LVL0EX.
            static constexpr auto LVL1EX = std::uint_fast8_t{ LVL0EX + Size::LVL0EX }; ///< LVL1EX.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ LVL1EX + Size::LVL1EX }; ///< RESERVED2.
            static constexpr auto NMIEX = std::uint_fast8_t{ RESERVED2 + Size::RESERVED2 }; ///< NMIEX.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto LVL0EX = mask<std::uint8_t>( Size::LVL0EX, Bit::LVL0EX ); ///< LVL0EX.
            static constexpr auto LVL1EX = mask<std::uint8_t>( Size::LVL1EX, Bit::LVL1EX ); ///< LVL1EX.
            static constexpr auto RESERVED2 = mask<std::uint8_t>( Size::RESERVED2, Bit::RESERVED2 ); ///< RESERVED2.
            static constexpr auto NMIEX = mask<std::uint8_t>( Size::NMIEX, Bit::NMIEX ); ///< NMIEX.
        };

        STATUS() = delete;

        STATUS( STATUS && ) = delete;

        STATUS( STATUS const & ) = delete;

        ~STATUS() = delete;

        auto operator=( STATUS && ) = delete;

        auto operator=( STATUS const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief CTRLA.
     */
    CTRLA ctrla;

    /**
     * \brief STATUS.
     */
    STATUS const status;

    /**
     * \brief Interrupt Priority Level 0 (LVL0PRI) register.
     */
    Register<std::uint8_t> lvl0pri;

    /**
     * \brief Interrupt Vector with Priority Level 1 (LVL1VEC) register.
     */
    Register<std::uint8_t> lvl1vec;

    CPUINT() = delete;

    CPUINT( CPUINT && ) = delete;

    CPUINT( CPUINT const & ) = delete;

    ~CPUINT() = delete;

    auto operator=( CPUINT && ) = delete;

    auto operator=( CPUINT const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_CPUINT_H
