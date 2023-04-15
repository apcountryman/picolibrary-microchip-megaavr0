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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::NVMCTRL interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_NVMCTRL_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_NVMCTRL_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr0/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series Nonvolatile Memory Controller (NVMCTRL) peripheral.
 */
class NVMCTRL {
  public:
    /**
     * \brief Control A (CTRLA) register.
     *
     * This register has the following fields:
     * - Command (CMD)
     */
    class CTRLA : public Protected_Register<std::uint8_t, CPU_CCP_Key::SPM> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto CMD       = std::uint_fast8_t{ 3 }; ///< CMD.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ 5 }; ///< RESERVED3.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto CMD = std::uint_fast8_t{}; ///< CMD.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ CMD + Size::CMD }; ///< RESERVED3.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto CMD = mask<std::uint8_t>( Size::CMD, Bit::CMD ); ///< CMD.
            static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
        };

        /**
         * \brief CMD.
         */
        enum CMD : std::uint8_t {
            CMD_NONE = 0x0 << Bit::CMD, ///< No command.
            CMD_WP   = 0x1 << Bit::CMD, ///< Write page buffer to memory (NVMCTRL.ADDR selects which memory).
            CMD_ER = 0x2 << Bit::CMD, ///< Erase page (NVMCTRL.ADDR selects which memory).
            CMD_ERWP = 0x3 << Bit::CMD, ///< Erase and write page (NVMCTRL.ADDR selects which memory).
            CMD_PBC  = 0x4 << Bit::CMD, ///< Page buffer clear.
            CMD_CHER = 0x5 << Bit::CMD, ///< Chip erase: erase Flash and EEPROM (unless EESAVE in FUSE.SYSCFG is '1').
            CMD_EEER = 0x6 << Bit::CMD, ///< EEPROM erase.
            CMD_WFU  = 0x7 << Bit::CMD, ///< Write fuse (only accessible through UPDI).
        };

        CTRLA() = delete;

        CTRLA( CTRLA && ) = delete;

        CTRLA( CTRLA const & ) = delete;

        ~CTRLA() = delete;

        auto operator=( CTRLA && ) = delete;

        auto operator=( CTRLA const & ) = delete;

        using Protected_Register<std::uint8_t, CPU_CCP_Key::SPM>::operator=;
    };

    /**
     * \brief Control B (CTRLB) register.
     *
     * This register has the following fields:
     * - Application Code Section Write Protection (APCWP)
     * - Boot Section Lock (BOOTLOCK)
     */
    class CTRLB : public Protected_Register<std::uint8_t, CPU_CCP_Key::IOREG> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto APCWP     = std::uint_fast8_t{ 1 }; ///< APCWP.
            static constexpr auto BOOTLOCK  = std::uint_fast8_t{ 1 }; ///< BOOTLOCK.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ 6 }; ///< RESERVED2.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto APCWP = std::uint_fast8_t{}; ///< APCWP.
            static constexpr auto BOOTLOCK = std::uint_fast8_t{ APCWP + Size::APCWP }; ///< BOOTLOCK.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ BOOTLOCK + Size::BOOTLOCK }; ///< RESERVED2.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto APCWP = mask<std::uint8_t>( Size::APCWP, Bit::APCWP ); ///< APCWP.
            static constexpr auto BOOTLOCK = mask<std::uint8_t>( Size::BOOTLOCK, Bit::BOOTLOCK ); ///< BOOTLOCK.
            static constexpr auto RESERVED2 = mask<std::uint8_t>( Size::RESERVED2, Bit::RESERVED2 ); ///< RESERVED2.
        };

        CTRLB() = delete;

        CTRLB( CTRLB && ) = delete;

        CTRLB( CTRLB const & ) = delete;

        ~CTRLB() = delete;

        auto operator=( CTRLB && ) = delete;

        auto operator=( CTRLB const & ) = delete;

        using Protected_Register<std::uint8_t, CPU_CCP_Key::IOREG>::operator=;
    };

    /**
     * \brief Status (STATUS) register.
     *
     * This register has the following fields:
     * - Flash Busy (FBUSY)
     * - EEPROM Busy (EEBUSY)
     * - Write Error (WRERROR)
     */
    class STATUS : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto FBUSY     = std::uint_fast8_t{ 1 }; ///< FBUSY.
            static constexpr auto EEBUSY    = std::uint_fast8_t{ 1 }; ///< EEBUSY.
            static constexpr auto WRERROR   = std::uint_fast8_t{ 1 }; ///< WRERROR.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ 5 }; ///< RESERVED3.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto FBUSY = std::uint_fast8_t{}; ///< FBUSY.
            static constexpr auto EEBUSY = std::uint_fast8_t{ FBUSY + Size::FBUSY }; ///< EEBUSY.
            static constexpr auto WRERROR = std::uint_fast8_t{ EEBUSY + Size::EEBUSY }; ///< WRERROR.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ WRERROR + Size::WRERROR }; ///< RESERVED3.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto FBUSY = mask<std::uint8_t>( Size::FBUSY, Bit::FBUSY ); ///< FBUSY.
            static constexpr auto EEBUSY = mask<std::uint8_t>( Size::EEBUSY, Bit::EEBUSY ); ///< EEBUSY.
            static constexpr auto WRERROR = mask<std::uint8_t>( Size::WRERROR, Bit::WRERROR ); ///< WRERROR.
            static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
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
     * \brief Interrupt Control (INTCTRL) register.
     *
     * This register has the following fields:
     * - EEPROM Ready Interrupt (EEREADY)
     */
    class INTCTRL : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto EEREADY   = std::uint_fast8_t{ 1 }; ///< EEREADY.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 7 }; ///< RESERVED1.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto EEREADY = std::uint_fast8_t{}; ///< EEREADY.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ EEREADY + Size::EEREADY }; ///< RESERVED1.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto EEREADY = mask<std::uint8_t>( Size::EEREADY, Bit::EEREADY ); ///< EEREADY.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
        };

        INTCTRL() = delete;

        INTCTRL( INTCTRL && ) = delete;

        INTCTRL( INTCTRL const & ) = delete;

        ~INTCTRL() = delete;

        auto operator=( INTCTRL && ) = delete;

        auto operator=( INTCTRL const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Interrupt Flags (INTFLAGS) register.
     *
     * This register has the following fields:
     * - EEREADY Interrupt Flag (EEREADY)
     */
    class INTFLAGS : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto EEREADY   = std::uint_fast8_t{ 1 }; ///< EEREADY.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 7 }; ///< RESERVED1.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto EEREADY = std::uint_fast8_t{}; ///< EEREADY.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ EEREADY + Size::EEREADY }; ///< RESERVED1.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto EEREADY = mask<std::uint8_t>( Size::EEREADY, Bit::EEREADY ); ///< EEREADY.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
        };

        INTFLAGS() = delete;

        INTFLAGS( INTFLAGS && ) = delete;

        INTFLAGS( INTFLAGS const & ) = delete;

        ~INTFLAGS() = delete;

        auto operator=( INTFLAGS && ) = delete;

        auto operator=( INTFLAGS const & ) = delete;

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
    STATUS const status;

    /**
     * \brief INTCTRL.
     */
    INTCTRL intctrl;

    /**
     * \brief INTFLAGS.
     */
    INTFLAGS intflags;

    /**
     * \brief Reserved registers (offset 0x05-0x05).
     */
    Reserved_Register<std::uint8_t> const reserved_0x05_0x05[ ( 0x05 - 0x05 ) + 1 ];

    union {
        /**
         * \brief Data (DATA) register.
         */
        Register<std::uint16_t> data;

        struct {
            /**
             * \brief Data Low Byte (DATAL) register.
             */
            Register<std::uint8_t> datal;

            /**
             * \brief Data High Byte (DATAH) register.
             */
            Register<std::uint8_t> datah;
        };
    };

    union {
        /**
         * \brief Address (ADDR) register.
         */
        Register<std::uint16_t> addr;

        struct {
            /**
             * \brief Address Low Byte (ADDRL) register.
             */
            Register<std::uint8_t> addrl;

            /**
             * \brief Address High Byte (ADDRH) register.
             */
            Register<std::uint8_t> addrh;
        };
    };

    NVMCTRL() = delete;

    NVMCTRL( NVMCTRL && ) = delete;

    NVMCTRL( NVMCTRL const & ) = delete;

    ~NVMCTRL() = delete;

    auto operator=( NVMCTRL && ) = delete;

    auto operator=( NVMCTRL const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_NVMCTRL_H
