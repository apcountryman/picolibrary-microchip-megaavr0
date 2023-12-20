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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::FUSE interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_FUSE_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_FUSE_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series Fuses (FUSE) peripheral.
 */
class FUSE {
  public:
    /**
     * \brief Watchdog Configuration (WDTCFG) register.
     *
     * This register has the following fields:
     * - Watchdog Time-Out Period (PERIOD)
     * - Watchdog Window Time-Out Period (WINDOW)
     */
    class WDTCFG : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto PERIOD = std::uint_fast8_t{ 4 }; ///< PERIOD.
            static constexpr auto WINDOW = std::uint_fast8_t{ 4 }; ///< WINDOW.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto PERIOD = std::uint_fast8_t{}; ///< PERIOD.
            static constexpr auto WINDOW = std::uint_fast8_t{ PERIOD + Size::PERIOD }; ///< WINDOW.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto PERIOD = mask<std::uint8_t>( Size::PERIOD, Bit::PERIOD ); ///< PERIOD.
            static constexpr auto WINDOW = mask<std::uint8_t>( Size::WINDOW, Bit::WINDOW ); ///< WINDOW.
        };

        WDTCFG() = delete;

        WDTCFG( WDTCFG && ) = delete;

        WDTCFG( WDTCFG const & ) = delete;

        ~WDTCFG() = delete;

        auto operator=( WDTCFG && ) = delete;

        auto operator=( WDTCFG const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief BOD Configuration (BODCFG) register.
     *
     * This register has the following fields:
     * - BOD Operation Mode in Sleep (SLEEP)
     * - BOD Operation Mode in Active and Idle (ACTIVE)
     * - BOD Sample Frequency (SAMPFREQ)
     * - BOD Level (LVL)
     */
    class BODCFG : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto SLEEP    = std::uint_fast8_t{ 2 }; ///< SLEEP.
            static constexpr auto ACTIVE   = std::uint_fast8_t{ 2 }; ///< ACTIVE.
            static constexpr auto SAMPFREQ = std::uint_fast8_t{ 1 }; ///< SAMPFREQ.
            static constexpr auto LVL      = std::uint_fast8_t{ 3 }; ///< LVL.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto SLEEP = std::uint_fast8_t{}; ///< SLEEP.
            static constexpr auto ACTIVE = std::uint_fast8_t{ SLEEP + Size::SLEEP }; ///< ACTIVE.
            static constexpr auto SAMPFREQ = std::uint_fast8_t{ ACTIVE + Size::ACTIVE }; ///< SAMPFREQ.
            static constexpr auto LVL = std::uint_fast8_t{ SAMPFREQ + Size::SAMPFREQ }; ///< LVL.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto SLEEP = mask<std::uint8_t>( Size::SLEEP, Bit::SLEEP ); ///< SLEEP.
            static constexpr auto ACTIVE = mask<std::uint8_t>( Size::ACTIVE, Bit::ACTIVE ); ///< ACTIVE.
            static constexpr auto SAMPFREQ = mask<std::uint8_t>( Size::SAMPFREQ, Bit::SAMPFREQ ); ///< SAMPFREQ.
            static constexpr auto LVL = mask<std::uint8_t>( Size::LVL, Bit::LVL ); ///< LVL.
        };

        /**
         * \brief LVL.
         */
        enum LVL : std::uint8_t {
            LVL_BODLEVEL0 = 0x0 << Bit::LVL, ///< 1.8 V.
            LVL_BODLEVEL2 = 0x2 << Bit::LVL, ///< 2.6 V.
            LVL_BODLEVEL7 = 0x7 << Bit::LVL, ///< 4.3 V.
        };

        BODCFG() = delete;

        BODCFG( BODCFG && ) = delete;

        BODCFG( BODCFG const & ) = delete;

        ~BODCFG() = delete;

        auto operator=( BODCFG && ) = delete;

        auto operator=( BODCFG const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Oscillator Configuration (OSCCFG) register.
     *
     * This register has the following fields:
     * - Frequency Select (FREQSEL)
     * - Oscillator Lock (OSCLOCK)
     */
    class OSCCFG : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto FREQSEL   = std::uint_fast8_t{ 2 }; ///< FREQSEL.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ 5 }; ///< RESERVED2.
            static constexpr auto OSCLOCK   = std::uint_fast8_t{ 1 }; ///< OSCLOCK.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto FREQSEL = std::uint_fast8_t{}; ///< FREQSEL.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ FREQSEL + Size::FREQSEL }; ///< RESERVED2.
            static constexpr auto OSCLOCK = std::uint_fast8_t{ RESERVED2 + Size::RESERVED2 }; ///< OSCLOCK.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto FREQSEL = mask<std::uint8_t>( Size::FREQSEL, Bit::FREQSEL ); ///< FREQSEL.
            static constexpr auto RESERVED2 = mask<std::uint8_t>( Size::RESERVED2, Bit::RESERVED2 ); ///< RESERVED2.
            static constexpr auto OSCLOCK = mask<std::uint8_t>( Size::OSCLOCK, Bit::OSCLOCK ); ///< OSCLOCK.
        };

        OSCCFG() = delete;

        OSCCFG( OSCCFG && ) = delete;

        OSCCFG( OSCCFG const & ) = delete;

        ~OSCCFG() = delete;

        auto operator=( OSCCFG && ) = delete;

        auto operator=( OSCCFG const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief System Configuration 0 (SYSCFG0) register.
     *
     * This register has the following fields:
     * - EEPROM Save During Chip Erase (EESAVE)
     * - Reset Pin Configuration (RSTPINCFG)
     * - CRC Source (CRCSRC)
     */
    class SYSCFG0 : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto EESAVE    = std::uint_fast8_t{ 1 }; ///< EESAVE.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 2 }; ///< RESERVED1.
            static constexpr auto RSTPINCFG = std::uint_fast8_t{ 1 }; ///< RSTPINCFG.
            static constexpr auto RESERVED4 = std::uint_fast8_t{ 2 }; ///< RESERVED4.
            static constexpr auto CRCSRC    = std::uint_fast8_t{ 2 }; ///< CRCSRC.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto EESAVE = std::uint_fast8_t{}; ///< EESAVE.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ EESAVE + Size::EESAVE }; ///< RESERVED1.
            static constexpr auto RSTPINCFG = std::uint_fast8_t{ RESERVED1 + Size::RESERVED1 }; ///< RSTPINCFG.
            static constexpr auto RESERVED4 = std::uint_fast8_t{ RSTPINCFG + Size::RSTPINCFG }; ///< RESERVED4.
            static constexpr auto CRCSRC = std::uint_fast8_t{ RESERVED4 + Size::RESERVED4 }; ///< CRCSRC.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto EESAVE = mask<std::uint8_t>( Size::EESAVE, Bit::EESAVE ); ///< EESAVE.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
            static constexpr auto RSTPINCFG = mask<std::uint8_t>( Size::RSTPINCFG, Bit::RSTPINCFG ); ///< RSTPINCFG.
            static constexpr auto RESERVED4 = mask<std::uint8_t>( Size::RESERVED4, Bit::RESERVED4 ); ///< RESERVED4.
            static constexpr auto CRCSRC = mask<std::uint8_t>( Size::CRCSRC, Bit::CRCSRC ); ///< CRCSRC.
        };

        /**
         * \brief CRCSRC.
         */
        enum CRCSRC : std::uint8_t {
            CRCSRC_FLASH = 0x0 << Bit::CRCSRC, ///< CRC of full Flash (boot, application code, and application data).
            CRCSRC_BOOT  = 0x1 << Bit::CRCSRC, ///< CRC of boot section.
            CRCSRC_BOOTAPP = 0x2 << Bit::CRCSRC, ///< CRC of application code and boot sections.
            CRCSRC_NOCRC = 0x3 << Bit::CRCSRC, ///< No CRC.
        };

        SYSCFG0() = delete;

        SYSCFG0( SYSCFG0 && ) = delete;

        SYSCFG0( SYSCFG0 const & ) = delete;

        ~SYSCFG0() = delete;

        auto operator=( SYSCFG0 && ) = delete;

        auto operator=( SYSCFG0 const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief System Configuration 1 (SYSCFG1) register.
     *
     * This register has the following fields:
     * - Start-Up Time Setting (SUT)
     */
    class SYSCFG1 : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto SUT       = std::uint_fast8_t{ 3 }; ///< SUT.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ 6 }; ///< RESERVED3.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto SUT = std::uint_fast8_t{}; ///< SUT.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ SUT + Size::SUT }; ///< RESERVED3.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto SUT = mask<std::uint8_t>( Size::SUT, Bit::SUT ); ///< SUT.
            static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
        };

        SYSCFG1() = delete;

        SYSCFG1( SYSCFG1 && ) = delete;

        SYSCFG1( SYSCFG1 const & ) = delete;

        ~SYSCFG1() = delete;

        auto operator=( SYSCFG1 && ) = delete;

        auto operator=( SYSCFG1 const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief WDTCFG.
     */
    WDTCFG const wdtcfg;

    /**
     * \brief BODCFG.
     */
    BODCFG const bodcfg;

    /**
     * \brief OSCCFG.
     */
    OSCCFG const osccfg;

    /**
     * brief Reserved registers (offset 0x03-0x04).
     */
    Reserved_Register<std::uint8_t> const reserved_0x03_0x04[ ( 0x04 - 0x03 ) + 1 ];

    /**
     * \brief SYSCFG0.
     */
    SYSCFG0 const syscfg0;

    /**
     * \brief SYSCFG1.
     */
    SYSCFG1 const syscfg1;

    /**
     * \brief Application Code End (APPEND) register.
     */
    Register<std::uint8_t> const append;

    /**
     * \brief Boot End (BOOTEND) register.
     */
    Register<std::uint8_t> const bootend;

    /**
     * brief Reserved registers (offset 0x09-0x09).
     */
    Reserved_Register<std::uint8_t> const reserved_0x09_0x09[ ( 0x09 - 0x09 ) + 1 ];

    /**
     * \brief Lockbits (LOCKBIT) register.
     */
    Register<std::uint8_t> const lockbit;

    FUSE() = delete;

    FUSE( FUSE && ) = delete;

    FUSE( FUSE const & ) = delete;

    ~FUSE() = delete;

    auto operator=( FUSE && ) = delete;

    auto operator=( FUSE const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_FUSE_H
