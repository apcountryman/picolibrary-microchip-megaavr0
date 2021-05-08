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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::PORTMUX interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_PORTMUX_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_PORTMUX_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr0/peripheral/instance.h"
#include "picolibrary/microchip/megaavr0/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series Port Multiplexer (PORTMUX) peripheral.
 */
class PORTMUX {
  public:
    /**
     * \brief PORTMUX Control for Event System (EVSYSROUTEA) register.
     *
     * This register has the following fields:
     * - Event Output A (EVOUTA)
     * - Event Output B (EVOUTB)
     * - Event Output C (EVOUTC)
     * - Event Output D (EVOUTD)
     * - Event Output E (EVOUTE)
     * - Event Output F (EVOUTF)
     */
    class EVSYSROUTEA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto EVOUTA   = std::uint_fast8_t{ 1 }; ///< EVOUTA.
            static constexpr auto EVOUTB   = std::uint_fast8_t{ 1 }; ///< EVOUTB.
            static constexpr auto EVOUTC   = std::uint_fast8_t{ 1 }; ///< EVOUTC.
            static constexpr auto EVOUTD   = std::uint_fast8_t{ 1 }; ///< EVOUTD.
            static constexpr auto EVOUTE   = std::uint_fast8_t{ 1 }; ///< EVOUTE.
            static constexpr auto EVOUTF   = std::uint_fast8_t{ 1 }; ///< EVOUTF.
            static constexpr auto RESERVED = std::uint_fast8_t{ 2 }; ///< Reserved.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto EVOUTA = std::uint_fast8_t{}; ///< EVOUTA.
            static constexpr auto EVOUTB = std::uint_fast8_t{ EVOUTA + Size::EVOUTA }; ///< EVOUTB.
            static constexpr auto EVOUTC = std::uint_fast8_t{ EVOUTB + Size::EVOUTB }; ///< EVOUTC.
            static constexpr auto EVOUTD = std::uint_fast8_t{ EVOUTC + Size::EVOUTC }; ///< EVOUTD.
            static constexpr auto EVOUTE = std::uint_fast8_t{ EVOUTD + Size::EVOUTD }; ///< EVOUTE.
            static constexpr auto EVOUTF = std::uint_fast8_t{ EVOUTE + Size::EVOUTE }; ///< EVOUTF.
            static constexpr auto RESERVED = std::uint_fast8_t{ EVOUTF + Size::EVOUTF }; ///< Reserved.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto EVOUTA = mask<std::uint8_t>( Size::EVOUTA, Bit::EVOUTA ); ///< EVOUTA.
            static constexpr auto EVOUTB = mask<std::uint8_t>( Size::EVOUTB, Bit::EVOUTB ); ///< EVOUTB.
            static constexpr auto EVOUTC = mask<std::uint8_t>( Size::EVOUTC, Bit::EVOUTC ); ///< EVOUTC.
            static constexpr auto EVOUTD = mask<std::uint8_t>( Size::EVOUTD, Bit::EVOUTD ); ///< EVOUTD.
            static constexpr auto EVOUTE = mask<std::uint8_t>( Size::EVOUTE, Bit::EVOUTE ); ///< EVOUTE.
            static constexpr auto EVOUTF = mask<std::uint8_t>( Size::EVOUTF, Bit::EVOUTF ); ///< EVOUTF.
            static constexpr auto RESERVED = mask<std::uint8_t>( Size::RESERVED, Bit::RESERVED ); ///< Reserved.
        };

        EVSYSROUTEA() = delete;

        EVSYSROUTEA( EVSYSROUTEA && ) = delete;

        EVSYSROUTEA( EVSYSROUTEA const & ) = delete;

        ~EVSYSROUTEA() = delete;

        auto operator=( EVSYSROUTEA && ) = delete;

        auto operator=( EVSYSROUTEA const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief PORTMUX Control for CCL (CCLROUTEA) register.
     *
     * This register has the following fields:
     * - CCL LUT 0 Output (LUT0)
     * - CCL LUT 1 Output (LUT1)
     * - CCL LUT 2 Output (LUT2)
     * - CCL LUT 3 Output (LUT3)
     */
    class CCLROUTEA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto LUT0     = std::uint_fast8_t{ 1 }; ///< LUT0.
            static constexpr auto LUT1     = std::uint_fast8_t{ 1 }; ///< LUT1.
            static constexpr auto LUT2     = std::uint_fast8_t{ 1 }; ///< LUT2.
            static constexpr auto LUT3     = std::uint_fast8_t{ 1 }; ///< LUT3.
            static constexpr auto RESERVED = std::uint_fast8_t{ 4 }; ///< Reserved.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto LUT0 = std::uint_fast8_t{}; ///< LUT0.
            static constexpr auto LUT1 = std::uint_fast8_t{ LUT0 + Size::LUT0 }; ///< LUT1.
            static constexpr auto LUT2 = std::uint_fast8_t{ LUT1 + Size::LUT1 }; ///< LUT2.
            static constexpr auto LUT3 = std::uint_fast8_t{ LUT2 + Size::LUT2 }; ///< LUT3.
            static constexpr auto RESERVED = std::uint_fast8_t{ LUT3 + Size::LUT3 }; ///< Reserved.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto LUT0 = mask<std::uint8_t>( Size::LUT0, Bit::LUT0 ); ///< LUT0.
            static constexpr auto LUT1 = mask<std::uint8_t>( Size::LUT1, Bit::LUT1 ); ///< LUT1.
            static constexpr auto LUT2 = mask<std::uint8_t>( Size::LUT2, Bit::LUT2 ); ///< LUT2.
            static constexpr auto LUT3 = mask<std::uint8_t>( Size::LUT3, Bit::LUT3 ); ///< LUT3.
            static constexpr auto RESERVED = mask<std::uint8_t>( Size::RESERVED, Bit::RESERVED ); ///< Reserved.
        };

        CCLROUTEA() = delete;

        CCLROUTEA( CCLROUTEA && ) = delete;

        CCLROUTEA( CCLROUTEA const & ) = delete;

        ~CCLROUTEA() = delete;

        auto operator=( CCLROUTEA && ) = delete;

        auto operator=( CCLROUTEA const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief PORTMUX Control for USART (USARTROUTEA) register.
     *
     * This register has the following fields:
     * - USART 0 Output (USART0)
     * - USART 1 Output (USART1)
     * - USART 2 Output (USART2)
     * - USART 3 Output (USART3)
     */
    class USARTROUTEA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto USART0 = std::uint_fast8_t{ 2 }; ///< USART0.
            static constexpr auto USART1 = std::uint_fast8_t{ 2 }; ///< USART1.
            static constexpr auto USART2 = std::uint_fast8_t{ 2 }; ///< USART2.
            static constexpr auto USART3 = std::uint_fast8_t{ 2 }; ///< USART3.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto USART0 = std::uint_fast8_t{}; ///< USART0.
            static constexpr auto USART1 = std::uint_fast8_t{ USART0 + Size::USART0 }; ///< USART1.
            static constexpr auto USART2 = std::uint_fast8_t{ USART1 + Size::USART1 }; ///< USART2.
            static constexpr auto USART3 = std::uint_fast8_t{ USART2 + Size::USART2 }; ///< USART3.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto USART0 = mask<std::uint8_t>( Size::USART0, Bit::USART0 ); ///< USART0.
            static constexpr auto USART1 = mask<std::uint8_t>( Size::USART1, Bit::USART1 ); ///< USART1.
            static constexpr auto USART2 = mask<std::uint8_t>( Size::USART2, Bit::USART2 ); ///< USART2.
            static constexpr auto USART3 = mask<std::uint8_t>( Size::USART3, Bit::USART3 ); ///< USART3.
        };

        USARTROUTEA() = delete;

        USARTROUTEA( USARTROUTEA && ) = delete;

        USARTROUTEA( USARTROUTEA const & ) = delete;

        ~USARTROUTEA() = delete;

        auto operator=( USARTROUTEA && ) = delete;

        auto operator=( USARTROUTEA const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief PORTMUX Control for TWI and SPI (TWISPIROUTEA) register.
     *
     * This register has the following fields:
     * - SPI 0 Communication (SPI0)
     * - TWI 0 Communication (TWI0)
     */
    class TWISPIROUTEA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto SPI0      = std::uint_fast8_t{ 2 }; ///< SPI0.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ 2 }; ///< Reserved.
            static constexpr auto TWI0      = std::uint_fast8_t{ 2 }; ///< TWI0.
            static constexpr auto RESERVED6 = std::uint_fast8_t{ 2 }; ///< Reserved.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto SPI0 = std::uint_fast8_t{}; ///< SPI0.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ SPI0 + Size::SPI0 }; ///< Reserved.
            static constexpr auto TWI0 = std::uint_fast8_t{ RESERVED2 + Size::RESERVED2 }; ///< TWI0.
            static constexpr auto RESERVED6 = std::uint_fast8_t{ TWI0 + Size::TWI0 }; ///< Reserved.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto SPI0 = mask<std::uint8_t>( Size::SPI0, Bit::SPI0 ); ///< SPI0.
            static constexpr auto RESERVED2 = mask<std::uint8_t>( Size::RESERVED2, Bit::RESERVED2 ); ///< Reserved.
            static constexpr auto TWI0 = mask<std::uint8_t>( Size::TWI0, Bit::TWI0 ); ///< TWI0.
            static constexpr auto RESERVED6 = mask<std::uint8_t>( Size::RESERVED6, Bit::RESERVED6 ); ///< Reserved.
        };

        TWISPIROUTEA() = delete;

        TWISPIROUTEA( TWISPIROUTEA && ) = delete;

        TWISPIROUTEA( TWISPIROUTEA const & ) = delete;

        ~TWISPIROUTEA() = delete;

        auto operator=( TWISPIROUTEA && ) = delete;

        auto operator=( TWISPIROUTEA const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief PORTMUX Control for TCA (TCAROUTEA) register.
     *
     * This register has the following fields:
     * - TCA0 Output (TCA0)
     */
    class TCAROUTEA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto TCA0     = std::uint_fast8_t{ 3 }; ///< TCA0.
            static constexpr auto RESERVED = std::uint_fast8_t{ 5 }; ///< Reserved.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto TCA0 = std::uint_fast8_t{}; ///< TCA0.
            static constexpr auto RESERVED = std::uint_fast8_t{ TCA0 + Size::TCA0 }; ///< Reserved.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto TCA0 = mask<std::uint8_t>( Size::TCA0, Bit::TCA0 ); ///< TCA0.
            static constexpr auto RESERVED = mask<std::uint8_t>( Size::RESERVED, Bit::RESERVED ); ///< Reserved.
        };

        TCAROUTEA() = delete;

        TCAROUTEA( TCAROUTEA && ) = delete;

        TCAROUTEA( TCAROUTEA const & ) = delete;

        ~TCAROUTEA() = delete;

        auto operator=( TCAROUTEA && ) = delete;

        auto operator=( TCAROUTEA const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief PORTMUX Control for TCB (TCBROUTEA) register.
     *
     * This register has the following fields:
     * - TCB0 Output (TCB0)
     * - TCB1 Output (TCB1)
     * - TCB2 Output (TCB2)
     * - TCB3 Output (TCB3)
     */
    class TCBROUTEA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto TCB0     = std::uint_fast8_t{ 1 }; ///< TCB0.
            static constexpr auto TCB1     = std::uint_fast8_t{ 1 }; ///< TCB1.
            static constexpr auto TCB2     = std::uint_fast8_t{ 1 }; ///< TCB2.
            static constexpr auto TCB3     = std::uint_fast8_t{ 1 }; ///< TCB3.
            static constexpr auto RESERVED = std::uint_fast8_t{ 4 }; ///< Reserved.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto TCB0 = std::uint_fast8_t{}; ///< TCB0.
            static constexpr auto TCB1 = std::uint_fast8_t{ TCB0 + Size::TCB0 }; ///< TCB1.
            static constexpr auto TCB2 = std::uint_fast8_t{ TCB1 + Size::TCB1 }; ///< TCB2.
            static constexpr auto TCB3 = std::uint_fast8_t{ TCB2 + Size::TCB2 }; ///< TCB3.
            static constexpr auto RESERVED = std::uint_fast8_t{ TCB3 + Size::TCB3 }; ///< Reserved.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto TCB0 = mask<std::uint8_t>( Size::TCB0, Bit::TCB0 ); ///< TCB0.
            static constexpr auto TCB1 = mask<std::uint8_t>( Size::TCB1, Bit::TCB1 ); ///< TCB1.
            static constexpr auto TCB2 = mask<std::uint8_t>( Size::TCB2, Bit::TCB2 ); ///< TCB2.
            static constexpr auto TCB3 = mask<std::uint8_t>( Size::TCB3, Bit::TCB3 ); ///< TCB3.
            static constexpr auto RESERVED = mask<std::uint8_t>( Size::RESERVED, Bit::RESERVED ); ///< Reserved.
        };

        TCBROUTEA() = delete;

        TCBROUTEA( TCBROUTEA && ) = delete;

        TCBROUTEA( TCBROUTEA const & ) = delete;

        ~TCBROUTEA() = delete;

        auto operator=( TCBROUTEA && ) = delete;

        auto operator=( TCBROUTEA const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief EVSYSROUTEA.
     */
    EVSYSROUTEA evsysroutea;

    /**
     * \brief CCLROUTEA.
     */
    CCLROUTEA cclroutea;

    /**
     * \brief USARTROUTEA.
     */
    USARTROUTEA usartroutea;

    /**
     * \brief TWISPIROUTEA.
     */
    TWISPIROUTEA twispiroutea;

    /**
     * \brief TCAROUTEA.
     */
    TCAROUTEA tcaroutea;

    /**
     * \brief TCBROUTEA.
     */
    TCBROUTEA tcbroutea;

    PORTMUX() = delete;

    PORTMUX( PORTMUX && ) = delete;

    PORTMUX( PORTMUX const & ) = delete;

    ~PORTMUX() = delete;

    auto operator=( PORTMUX && ) = delete;

    auto operator=( PORTMUX const & ) = delete;
};

/**
 * \brief Microchip megaAVR 0-series Port Multiplexer (PORTMUX) peripheral instance.
 *
 * \tparam INSTANCE_ADDRESS The address of the PORTMUX instance.
 */
template<std::uintptr_t INSTANCE_ADDRESS>
using PORTMUX_Instance = Instance<PORTMUX, INSTANCE_ADDRESS>;

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_PORTMUX_H