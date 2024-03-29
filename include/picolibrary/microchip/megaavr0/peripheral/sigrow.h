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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::SIGROW interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_SIGROW_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_SIGROW_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series Signature Row (SIGROW) peripheral.
 */
class SIGROW {
  public:
    /**
     * \brief OSC16 Calibration Byte (OSCCAL16M0) register.
     *
     * This register has the following fields:
     * - OSC16 Calibration (OSCCAL16M)
     */
    class OSCCAL16M0 : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto OSCCAL16M = std::uint_fast8_t{ 7 }; ///< OSCCAL16M.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ 1 }; ///< RESERVED7.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto OSCCAL16M = std::uint_fast8_t{}; ///< OSCCAL16M.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ OSCCAL16M + Size::OSCCAL16M }; ///< RESERVED7.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto OSCCAL16M = mask<std::uint8_t>( Size::OSCCAL16M, Bit::OSCCAL16M ); ///< OSCCAL16M.
            static constexpr auto RESERVED7 = mask<std::uint8_t>( Size::RESERVED7, Bit::RESERVED7 ); ///< RESERVED7.
        };

        OSCCAL16M0() = delete;

        OSCCAL16M0( OSCCAL16M0 && ) = delete;

        OSCCAL16M0( OSCCAL16M0 const & ) = delete;

        ~OSCCAL16M0() = delete;

        auto operator=( OSCCAL16M0 && ) = delete;

        auto operator=( OSCCAL16M0 const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief OSC16 Temperature Calibration Byte (OSCCAL16M1) register.
     *
     * This register has the following fields:
     * - OSC16 Temperature Calibration (OSCCAL16MTCAL)
     */
    class OSCCAL16M1 : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto OSCCAL16MTCAL = std::uint_fast8_t{ 4 }; ///< OSCCAL16MTCAL.
            static constexpr auto RESERVED4     = std::uint_fast8_t{ 4 }; ///< RESERVED4.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto OSCCAL16MTCAL = std::uint_fast8_t{}; ///< OSCCAL16MTCAL.
            static constexpr auto RESERVED4 = std::uint_fast8_t{ OSCCAL16MTCAL + Size::OSCCAL16MTCAL }; ///< RESERVED4.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto OSCCAL16MTCAL = mask<std::uint8_t>(
                Size::OSCCAL16MTCAL,
                Bit::OSCCAL16MTCAL ); ///< OSCCAL16MTCAL.
            static constexpr auto RESERVED4 = mask<std::uint8_t>( Size::RESERVED4, Bit::RESERVED4 ); ///< RESERVED4.
        };

        OSCCAL16M1() = delete;

        OSCCAL16M1( OSCCAL16M1 && ) = delete;

        OSCCAL16M1( OSCCAL16M1 const & ) = delete;

        ~OSCCAL16M1() = delete;

        auto operator=( OSCCAL16M1 && ) = delete;

        auto operator=( OSCCAL16M1 const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief OSC20 Calibration Byte (OSCCAL20M0) register.
     *
     * This register has the following fields:
     * - OSC20 Calibration (OSCCAL20M)
     */
    class OSCCAL20M0 : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto OSCCAL20M = std::uint_fast8_t{ 7 }; ///< OSCCAL20M.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ 1 }; ///< RESERVED7.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto OSCCAL20M = std::uint_fast8_t{}; ///< OSCCAL20M.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ OSCCAL20M + Size::OSCCAL20M }; ///< RESERVED7.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto OSCCAL20M = mask<std::uint8_t>( Size::OSCCAL20M, Bit::OSCCAL20M ); ///< OSCCAL20M.
            static constexpr auto RESERVED7 = mask<std::uint8_t>( Size::RESERVED7, Bit::RESERVED7 ); ///< RESERVED7.
        };

        OSCCAL20M0() = delete;

        OSCCAL20M0( OSCCAL20M0 && ) = delete;

        OSCCAL20M0( OSCCAL20M0 const & ) = delete;

        ~OSCCAL20M0() = delete;

        auto operator=( OSCCAL20M0 && ) = delete;

        auto operator=( OSCCAL20M0 const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief OSC20 Temperature Calibration Byte (OSCCAL20M1) register.
     *
     * This register has the following fields:
     * - OSC20 Temperature Calibration (OSCCAL20MTCAL)
     */
    class OSCCAL20M1 : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto OSCCAL20MTCAL = std::uint_fast8_t{ 4 }; ///< OSCCAL20MTCAL.
            static constexpr auto RESERVED4     = std::uint_fast8_t{ 4 }; ///< RESERVED4.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto OSCCAL20MTCAL = std::uint_fast8_t{}; ///< OSCCAL20MTCAL.
            static constexpr auto RESERVED4 = std::uint_fast8_t{ OSCCAL20MTCAL + Size::OSCCAL20MTCAL }; ///< RESERVED4.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto OSCCAL20MTCAL = mask<std::uint8_t>(
                Size::OSCCAL20MTCAL,
                Bit::OSCCAL20MTCAL ); ///< OSCCAL20MTCAL.
            static constexpr auto RESERVED4 = mask<std::uint8_t>( Size::RESERVED4, Bit::RESERVED4 ); ///< RESERVED4.
        };

        OSCCAL20M1() = delete;

        OSCCAL20M1( OSCCAL20M1 && ) = delete;

        OSCCAL20M1( OSCCAL20M1 const & ) = delete;

        ~OSCCAL20M1() = delete;

        auto operator=( OSCCAL20M1 && ) = delete;

        auto operator=( OSCCAL20M1 const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Device ID (DEVICEID) register.
     */
    Register<std::uint8_t> const deviceid[ ( 0x02 - 0x00 ) + 1 ];

    /**
     * \brief Serial Number (SERNUM) register.
     */
    Register<std::uint8_t> const sernum[ ( 0x0C - 0x03 ) + 1 ];

    /**
     * \brief Reserved registers (offset 0x0D-0x17).
     */
    Reserved_Register<std::uint8_t> const reserved_0x0D_0x17[ ( 0x17 - 0x0D ) + 1 ];

    /**
     * \brief OSCCAL16M0.
     */
    OSCCAL16M0 const osccal16m0;

    /**
     * \brief OSCCAL16M1.
     */
    OSCCAL16M1 const osccal16m1;

    /**
     * \brief OSCCAL20M0.
     */
    OSCCAL20M0 const osccal20m0;

    /**
     * \brief OSCCAL20M1.
     */
    OSCCAL20M1 const osccal20m1;

    /**
     * \brief Reserved registers (offset 0x1C-0x1F).
     */
    Reserved_Register<std::uint8_t> const reserved_0x1C_0x1F[ ( 0x1F - 0x1C ) + 1 ];

    /**
     * \brief Temperature Sensor Calibration (TEMPSENSE) register.
     */
    Register<std::uint8_t> const tempsense[ ( 0x21 - 0x20 ) + 1 ];

    /**
     * \brief OSC16 Error At 3V (OSC16ERR3V) register.
     */
    Register<std::uint8_t> const osc16err3v;

    /**
     * \brief OSC16 Error At 5V (OSC16ERR5V) register.
     */
    Register<std::uint8_t> const osc16err5v;

    /**
     * \brief OSC20 Error At 3V (OSC20ERR3V) register.
     */
    Register<std::uint8_t> const osc20err3v;

    /**
     * \brief OSC20 Error At 5V (OSC20ERR5V) register.
     */
    Register<std::uint8_t> const osc20err5v;

    SIGROW() = delete;

    SIGROW( SIGROW && ) = delete;

    SIGROW( SIGROW const & ) = delete;

    ~SIGROW() = delete;

    auto operator=( SIGROW && ) = delete;

    auto operator=( SIGROW const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_SIGROW_H
