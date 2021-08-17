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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::SIGROW interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_SIGROW_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_SIGROW_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr0/peripheral/instance.h"
#include "picolibrary/microchip/megaavr0/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series Signature Row (SIGROW) peripheral.
 */
class SIGROW {
  public:
    /**
     * \brief Device.
     */
    enum class Device : std::uint24_t {
        ATmega808  = 0x1E9326, ///< ATmega808.
        ATmega809  = 0x1E932A, ///< ATmega809.
        ATmega1608 = 0x1E9427, ///< ATmega1608.
        ATmega1609 = 0x1E9426, ///< ATmega1608.
        ATmega3208 = 0x1E9530, ///< ATmega3208.
        ATmega3209 = 0x1E9531, ///< ATmega3208.
        ATmega4808 = 0x1E9650, ///< ATmega4808.
        ATmega4809 = 0x1E9651, ///< ATmega4808.
    };

    /**
     * \brief 16 MHz Internal Oscillator Calibration (OSCCAL16M0) register.
     *
     * This register has the following fields:
     * - 16 MHz Internal Oscillator Calibration (OSCCAL16M)
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
     * \brief 16 MHz Internal Oscillator Temperature Calibration (OSCCAL16M1) register.
     *
     * This register has the following fields:
     * - 16 MHz Internal Oscillator Temperature Calibration (OSCCAL16MTCAL)
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
     * \brief 20 MHz Internal Oscillator Calibration (OSCCAL20M0) register.
     *
     * This register has the following fields:
     * - 20 MHz Internal Oscillator Calibration (OSCCAL20M)
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
     * \brief 20 MHz Internal Oscillator Temperature Calibration (OSCCAL20M1) register.
     *
     * This register has the following fields:
     * - 20 MHz Internal Oscillator Temperature Calibration (OSCCAL20MTCAL)
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
     * \brief 16 MHz Internal Oscillator Error at 3 V (OSC16ERR3V) register.
     */
    Register<std::uint8_t> const osc16err3v;

    /**
     * \brief 16 MHz Internal Oscillator Error at 5 V (OSC16ERR5V) register.
     */
    Register<std::uint8_t> const osc16err5v;

    /**
     * \brief 20 MHz Internal Oscillator Error at 3 V (OSC20ERR3V) register.
     */
    Register<std::uint8_t> const osc20err3v;

    /**
     * \brief 20 MHz Internal Oscillator Error at 5 V (OSC20ERR5V) register.
     */
    Register<std::uint8_t> const osc20err5v;

    SIGROW() = delete;

    SIGROW( SIGROW && ) = delete;

    SIGROW( SIGROW const & ) = delete;

    ~SIGROW() = delete;

    auto operator=( SIGROW && ) = delete;

    auto operator=( SIGROW const & ) = delete;

    /**
     * \brief Get the device.
     *
     * \return The device.
     */
    auto device() const noexcept
    {
        return static_cast<Device>(
            ( static_cast<std::uint24_t>( deviceid[ 0 ] )
              << ( 2 * std::numeric_limits<std::uint8_t>::digits ) )
            | ( static_cast<std::uint24_t>( deviceid[ 1 ] )
                << ( 1 * std::numeric_limits<std::uint8_t>::digits ) )
            | ( static_cast<std::uint24_t>( deviceid[ 2 ] )
                << ( 0 * std::numeric_limits<std::uint8_t>::digits ) ) );
    }
};

/**
 * \brief Microchip megaAVR 0-series Signature Row (SIGROW) peripheral instance.
 *
 * \tparam INSTANCE_ADDRESS The address of the SIGROW instance.
 */
template<std::uintptr_t INSTANCE_ADDRESS>
using SIGROW_Instance = Instance<SIGROW, INSTANCE_ADDRESS>;

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_SIGROW_H
