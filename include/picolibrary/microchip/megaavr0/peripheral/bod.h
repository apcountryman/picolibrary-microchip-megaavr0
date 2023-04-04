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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::BOD interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_BOD_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_BOD_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr0/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series Brown-Out Detector (BOD) peripheral.
 */
class BOD {
  public:
    /**
     * \brief Control A (CTRLA) register.
     *
     * This register has the following fields:
     * - Sleep (SLEEP)
     * - Active (ACTIVE)
     * - Sample Frequency (SAMPFREQ)
     */
    class CTRLA : public Protected_Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto SLEEP     = std::uint_fast8_t{ 2 }; ///< SLEEP.
            static constexpr auto ACTIVE    = std::uint_fast8_t{ 2 }; ///< ACTIVE.
            static constexpr auto SAMPFREQ  = std::uint_fast8_t{ 1 }; ///< SAMPFREQ.
            static constexpr auto RESERVED5 = std::uint_fast8_t{ 3 }; ///< RESERVED5.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto SLEEP = std::uint_fast8_t{}; ///< SLEEP.
            static constexpr auto ACTIVE = std::uint_fast8_t{ SLEEP + Size::SLEEP }; ///< ACTIVE.
            static constexpr auto SAMPFREQ = std::uint_fast8_t{ ACTIVE + Size::ACTIVE }; ///< SAMPFREQ.
            static constexpr auto RESERVED5 = std::uint_fast8_t{ SAMPFREQ + Size::SAMPFREQ }; ///< RESERVED5.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto SLEEP = mask<std::uint8_t>( Size::SLEEP, Bit::SLEEP ); ///< SLEEP.
            static constexpr auto ACTIVE = mask<std::uint8_t>( Size::ACTIVE, Bit::ACTIVE ); ///< ACTIVE.
            static constexpr auto SAMPFREQ = mask<std::uint8_t>( Size::SAMPFREQ, Bit::SAMPFREQ ); ///< SAMPFREQ.
            static constexpr auto RESERVED5 = mask<std::uint8_t>( Size::RESERVED5, Bit::RESERVED5 ); ///< RESERVED5.
        };

        /**
         * \brief SLEEP.
         */
        enum SLEEP : std::uint8_t {
            SLEEP_DIS     = 0x0 << Bit::SLEEP, ///< Disabled.
            SLEEP_ENABLED = 0x1 << Bit::SLEEP, ///< Enabled in continuous mode.
            SLEEP_SAMPLED = 0x2 << Bit::SLEEP, ///< Enabled in sampled mode.
        };

        /**
         * \brief ACTIVE.
         */
        enum ACTIVE : std::uint8_t {
            ACTIVE_DIS     = 0x0 << Bit::ACTIVE, ///< Disabled.
            ACTIVE_ENABLED = 0x1 << Bit::ACTIVE, ///< Enabled in continuous mode.
            ACTIVE_SAMPLED = 0x2 << Bit::ACTIVE, ///< Enabled in sampled mode.
            ACTIVE_ENWAKE  = 0x3 << Bit::ACTIVE, ///< Enabled in continuous mode. Execution is halted at wake-up until BOD is running.
        };

        CTRLA() = delete;

        CTRLA( CTRLA && ) = delete;

        CTRLA( CTRLA const & ) = delete;

        ~CTRLA() = delete;

        auto operator=( CTRLA && ) = delete;

        auto operator=( CTRLA const & ) = delete;

        using Protected_Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Control B (CTRLB) register.
     *
     * This register has the following fields:
     * - BOD Level (LVL)
     */
    class CTRLB : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto LVL       = std::uint_fast8_t{ 3 }; ///< LVL.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ 5 }; ///< RESERVED3.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto LVL = std::uint_fast8_t{}; ///< LVL.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ LVL + Size::LVL }; ///< RESERVED3.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto LVL = mask<std::uint8_t>( Size::LVL, Bit::LVL ); ///< LVL.
            static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
        };

        /**
         * \brief LVL.
         */
        enum LVL : std::uint8_t {
            LVL_BODLEVEL0 = 0x0 << Bit::LVL, ///< 1.8 V.
            LVL_BODLEVEL2 = 0x2 << Bit::LVL, ///< 2.6 V.
            LVL_BODLEVEL7 = 0x7 << Bit::LVL, ///< 4.2 V.
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
     * \brief VLM Control A (VLMCTRLA) register.
     *
     * This register has the following fields:
     * - VLM Level (VLMLVL)
     */
    class VLMCTRLA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto VLMLVL    = std::uint_fast8_t{ 2 }; ///< VLMLVL.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ 6 }; ///< RESERVED2.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto VLMLVL = std::uint_fast8_t{}; ///< VLMLVL.
            static constexpr auto RESERVED2 = std::uint_fast8_t{ VLMLVL + Size::VLMLVL }; ///< RESERVED2.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto VLMLVL = mask<std::uint8_t>( Size::VLMLVL, Bit::VLMLVL ); ///< VLMLVL.
            static constexpr auto RESERVED2 = mask<std::uint8_t>( Size::RESERVED2, Bit::RESERVED2 ); ///< RESERVED2.
        };

        VLMCTRLA() = delete;

        VLMCTRLA( VLMCTRLA && ) = delete;

        VLMCTRLA( VLMCTRLA const & ) = delete;

        ~VLMCTRLA() = delete;

        auto operator=( VLMCTRLA && ) = delete;

        auto operator=( VLMCTRLA const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Interrupt Control (INTCTRL) register.
     *
     * This register has the following fields:
     * - VLM Interrupt Enable (VLMIE)
     * - VLM Configuration (VLMCFG)
     */
    class INTCTRL : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto VLMIE     = std::uint_fast8_t{ 1 }; ///< VLMIE.
            static constexpr auto VLMCFG    = std::uint_fast8_t{ 2 }; ///< VLMCFG.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ 5 }; ///< RESERVED3.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto VLMIE = std::uint_fast8_t{}; ///< VLMIE.
            static constexpr auto VLMCFG = std::uint_fast8_t{ VLMIE + Size::VLMIE }; ///< VLMCFG.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ VLMCFG + Size::VLMCFG }; ///< RESERVED3.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto VLMIE = mask<std::uint8_t>( Size::VLMIE, Bit::VLMIE ); ///< VLMIE.
            static constexpr auto VLMCFG = mask<std::uint8_t>( Size::VLMCFG, Bit::VLMCFG ); ///< VLMCFG.
            static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
        };

        /**
         * \brief VLMCFG.
         */
        enum VLMCFG : std::uint8_t {
            VLMCFG_BELOW = 0x0 << Bit::VLMCFG, ///< VDD falls below VLM threshold.
            VLMCFG_ABOVE = 0x1 << Bit::VLMCFG, ///< VDD rises above VLM threshold.
            VLMCFG_CROSS = 0x2 << Bit::VLMCFG, ///< VDD crosses VLM threshold.
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
     * \brief VLM Interrupt Flags (INTFLAGS) register.
     *
     * This register has the following fields:
     * - VLM Interrupt Flag (VLMIF)
     */
    class INTFLAGS : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto VLMIF     = std::uint_fast8_t{ 1 }; ///< VLMIF.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 7 }; ///< RESERVED1.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto VLMIF = std::uint_fast8_t{}; ///< VLMIF.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ VLMIF + Size::VLMIF }; ///< RESERVED1.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto VLMIF = mask<std::uint8_t>( Size::VLMIF, Bit::VLMIF ); ///< VLMIF.
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
     * \brief VLM Status (STATUS) register.
     *
     * This register has the following fields:
     * - VLM Status (VLMS)
     */
    class STATUS : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto VLMS      = std::uint_fast8_t{ 1 }; ///< VLMS.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 7 }; ///< RESERVED1.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto VLMS = std::uint_fast8_t{}; ///< VLMS.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ VLMS + Size::VLMS }; ///< RESERVED1.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto VLMS = mask<std::uint8_t>( Size::VLMS, Bit::VLMS ); ///< VLMS.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
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
    CTRLB const ctrlb;

    /**
     * \brief Reserved registers (offset 0x02-0x07).
     */
    Reserved_Register<std::uint8_t> const reserved_0x02_0x07[ ( 0x07 - 0x02 ) + 1 ];

    /**
     * \brief VLMCTRLA.
     */
    VLMCTRLA vlmctrla;

    /**
     * \brief INTCTRL.
     */
    INTCTRL intctrl;

    /**
     * \brief INTFLAGS.
     */
    INTFLAGS intflags;

    /**
     * \brief STATUS.
     */
    STATUS const status;

    BOD() = delete;

    BOD( BOD && ) = delete;

    BOD( BOD const & ) = delete;

    ~BOD() = delete;

    auto operator=( BOD && ) = delete;

    auto operator=( BOD const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_BOD_H
