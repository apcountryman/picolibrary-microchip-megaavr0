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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::CRCSCAN interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_CRCSCAN_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_CRCSCAN_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr0/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series CPU Interrupt Controller (CRCSCAN) peripheral.
 */
class CRCSCAN {
  public:
    /**
     * \brief Control A (CTRLA) register.
     *
     * This register has the following fields:
     * - Enable CRCSCAN (ENABLE)
     * - Enable NMI Trigger (NMIEN)
     * - Reset CRCSCAN (RESET)
     */
    class CTRLA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto ENABLE    = std::uint_fast8_t{ 1 }; ///< ENABLE.
            static constexpr auto NMIEN     = std::uint_fast8_t{ 1 }; ///< NMIEN.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ 5 }; ///< RESERVED2.
            static constexpr auto RESET     = std::uint_fast8_t{ 1 }; ///< RESET.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto ENABLE = std::uint_fast8_t{}; ///< ENABLE.
            static constexpr auto NMIEN = std::uint_fast8_t{ ENABLE + Size::ENABLE }; ///< NMIEN.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ NMIEN + Size::NMIEN }; ///< RESERVED2.
            static constexpr auto RESET = std::uint_fast8_t{ RESERVED2 + Size::RESERVED2 }; ///< RESET.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto ENABLE = mask<std::uint8_t>( Size::ENABLE, Bit::ENABLE ); ///< ENABLE.
            static constexpr auto NMIEN = mask<std::uint8_t>( Size::NMIEN, Bit::NMIEN ); ///< NMIEN.
            static constexpr auto RESERVED2 = mask<std::uint8_t>( Size::RESERVED2, Bit::RESERVED2 ); ///< RESERVED2.
            static constexpr auto RESET = mask<std::uint8_t>( Size::RESET, Bit::RESET ); ///< RESET.
        };

        CTRLA() = delete;

        CTRLA( CTRLA && ) = delete;

        CTRLA( CTRLA const & ) = delete;

        ~CTRLA() = delete;

        auto operator=( CTRLA && ) = delete;

        auto operator=( CTRLA const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Control B (CTRLB) register.
     *
     * This register has the following fields:
     * - CRC Source (SRC)
     * - CRC Flash Access Mode (MODE)
     */
    class CTRLB : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto SRC       = std::uint_fast8_t{ 2 }; ///< SRC.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ 2 }; ///< RESERVED2.
            static constexpr auto MODE      = std::uint_fast8_t{ 2 }; ///< MODE.
            static constexpr auto RESERVED6 = std::uint_fast8_t{ 2 }; ///< RESERVED6.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto SRC = std::uint_fast8_t{}; ///< SRC.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ SRC + Size::SRC }; ///< RESERVED2.
            static constexpr auto MODE = std::uint_fast8_t{ RESERVED2 + Size::RESERVED2 }; ///< MODE.
            static constexpr auto RESERVED6 = std::uint_fast8_t{ MODE + Size::MODE }; ///< RESERVED6.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto SRC = mask<std::uint8_t>( Size::SRC, Bit::SRC ); ///< SRC.
            static constexpr auto RESERVED2 = mask<std::uint8_t>( Size::RESERVED2, Bit::RESERVED2 ); ///< RESERVED2.
            static constexpr auto MODE = mask<std::uint8_t>( Size::MODE, Bit::MODE ); ///< MODE.
            static constexpr auto RESERVED6 = mask<std::uint8_t>( Size::RESERVED6, Bit::RESERVED6 ); ///< RESERVED6.
        };

        /**
         * \brief SRC.
         */
        enum SRC : std::uint8_t {
            SRC_FLASH   = 0x0 << Bit::SRC, ///< The CRC is performed on the entire Flash (boot, application code, and application data sections).
            SRC_BOOTAPP = 0x1 << Bit::SRC, ///< The CRC is performed on the boot and application code sections of Flash.
            SRC_BOOT = 0x2 << Bit::SRC, ///< The CRC is performed on the boot section of Flash.
        };

        /**
         * \brief MODE.
         */
        enum MODE : std::uint8_t {
            MODE_PRIORITY = 0x0 << Bit::MODE, ///< The CRC module runs a single check with priority to Flash. The CPU is halted until the CRC completes.
        };

        CTRLB() = delete;

        CTRLB( CTRLB && ) = delete;

        CTRLB( CTRLB const & ) = delete;

        ~CTRLB() = delete;

        auto operator=( CTRLB && ) = delete;

        auto operator=( CTRLB const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Status (STATUS) register.
     *
     * This register has the following fields:
     * - CRC Busy (BUSY)
     * - CRC OK (OK)
     */
    class STATUS : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto BUSY      = std::uint_fast8_t{ 1 }; ///< BUSY.
            static constexpr auto OK        = std::uint_fast8_t{ 1 }; ///< OK.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ 6 }; ///< RESERVED2.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto BUSY = std::uint_fast8_t{}; ///< BUSY.
            static constexpr auto OK   = std::uint_fast8_t{ BUSY + Size::BUSY }; ///< OK.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ OK + Size::OK }; ///< RESERVED2.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto BUSY = mask<std::uint8_t>( Size::BUSY, Bit::BUSY ); ///< BUSY.
            static constexpr auto OK = mask<std::uint8_t>( Size::OK, Bit::OK ); ///< OK.
            static constexpr auto RESERVED2 = mask<std::uint8_t>( Size::RESERVED2, Bit::RESERVED2 ); ///< RESERVED2.
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
     * \brief CTRLB.
     */
    CTRLB ctrlb;

    /**
     * \brief STATUS.
     */
    STATUS status;

    CRCSCAN() = delete;

    CRCSCAN( CRCSCAN && ) = delete;

    CRCSCAN( CRCSCAN const & ) = delete;

    ~CRCSCAN() = delete;

    auto operator=( CRCSCAN && ) = delete;

    auto operator=( CRCSCAN const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_CRCSCAN_H
