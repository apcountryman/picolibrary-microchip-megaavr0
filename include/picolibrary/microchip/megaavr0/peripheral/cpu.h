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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::CPU interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_CPU_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_CPU_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr0/peripheral/instance.h"
#include "picolibrary/microchip/megaavr0/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series CPU peripheral.
 */
class CPU {
  public:
    /**
     * \brief Status (SREG) register.
     *
     * This register has the following fields:
     * - Carry Flag (C)
     * - Zero Flag (Z)
     * - Negative Flag (N)
     * - Two's Complement Overflow Flag (V)
     * - Sign Flag (S)
     * - Half Carry Flag (H)
     * - Transfer Bit (T)
     * - Global Interrupt Enable Bit (I)
     */
    class SREG : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto C = std::uint_fast8_t{ 1 }; ///< C.
            static constexpr auto Z = std::uint_fast8_t{ 1 }; ///< Z.
            static constexpr auto N = std::uint_fast8_t{ 1 }; ///< N.
            static constexpr auto V = std::uint_fast8_t{ 1 }; ///< V.
            static constexpr auto S = std::uint_fast8_t{ 1 }; ///< S.
            static constexpr auto H = std::uint_fast8_t{ 1 }; ///< H.
            static constexpr auto T = std::uint_fast8_t{ 1 }; ///< T.
            static constexpr auto I = std::uint_fast8_t{ 1 }; ///< I.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto C = std::uint_fast8_t{};              ///< C.
            static constexpr auto Z = std::uint_fast8_t{ C + Size::C }; ///< Z.
            static constexpr auto N = std::uint_fast8_t{ Z + Size::Z }; ///< N.
            static constexpr auto V = std::uint_fast8_t{ N + Size::N }; ///< V.
            static constexpr auto S = std::uint_fast8_t{ V + Size::V }; ///< S.
            static constexpr auto H = std::uint_fast8_t{ S + Size::S }; ///< H.
            static constexpr auto T = std::uint_fast8_t{ H + Size::H }; ///< T.
            static constexpr auto I = std::uint_fast8_t{ T + Size::T }; ///< I.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto C = mask<std::uint8_t>( Size::C, Bit::C ); ///< C.
            static constexpr auto Z = mask<std::uint8_t>( Size::Z, Bit::Z ); ///< Z.
            static constexpr auto N = mask<std::uint8_t>( Size::N, Bit::N ); ///< N.
            static constexpr auto V = mask<std::uint8_t>( Size::V, Bit::V ); ///< V.
            static constexpr auto S = mask<std::uint8_t>( Size::S, Bit::S ); ///< S.
            static constexpr auto H = mask<std::uint8_t>( Size::H, Bit::H ); ///< H.
            static constexpr auto T = mask<std::uint8_t>( Size::T, Bit::T ); ///< T.
            static constexpr auto I = mask<std::uint8_t>( Size::I, Bit::I ); ///< I.
        };

        SREG() = delete;

        SREG( SREG && ) = delete;

        SREG( SREG const & ) = delete;

        ~SREG() = delete;

        auto operator=( SREG && ) = delete;

        auto operator=( SREG const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Reserved registers (offset 0x00-0x03).
     */
    Reserved_Register<std::uint8_t> const reserved_0x00_0x03[ ( 0x03 - 0x00 ) + 1 ];

    /**
     * \brief Configuration Change Protection (CCP) register.
     */
    Register<std::uint8_t> ccp;

    /**
     * \brief Reserved registers (offset 0x05-0x0C).
     */
    Reserved_Register<std::uint8_t> const reserved_0x05_0x0C[ ( 0x0C - 0x05 ) + 1 ];

    /**
     * \brief Stack Pointer (SP) register.
     */
    Register<std::uint16_t> sp;

    /**
     * \brief SREG.
     */
    SREG sreg;

    CPU() = delete;

    CPU( CPU && ) = delete;

    CPU( CPU const & ) = delete;

    ~CPU() = delete;

    auto operator=( CPU && ) = delete;

    auto operator=( CPU const & ) = delete;
};

/**
 * \brief Microchip megaAVR 0-series CPU peripheral instance.
 *
 * \tparam INSTANCE_ADDRESS The address of the CPU instance.
 */
template<std::uintptr_t INSTANCE_ADDRESS>
using CPU_Instance = Instance<CPU, INSTANCE_ADDRESS>;

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_CPU_H
