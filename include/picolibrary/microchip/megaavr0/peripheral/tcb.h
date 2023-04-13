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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::TCB interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_TCB_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_TCB_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr0/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series 16-Bit Timer/Counter Type B (TCB) peripheral.
 */
class TCB {
  public:
    /**
     * \brief Control A (CTRLA) register.
     *
     * This register has the following fields:
     * - Enable (ENABLE)
     * - Clock Select (CLKSEL)
     * - Synchronize Update (SYNCUPD)
     * - Run in Standby (RUNSTDBY)
     */
    class CTRLA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto ENABLE    = std::uint_fast8_t{ 1 }; ///< ENABLE.
            static constexpr auto CLKSEL    = std::uint_fast8_t{ 2 }; ///< CLKSEL.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ 1 }; ///< RESERVED3.
            static constexpr auto SYNCUPD   = std::uint_fast8_t{ 1 }; ///< SYNCUPD.
            static constexpr auto RESERVED5 = std::uint_fast8_t{ 1 }; ///< RESERVED5.
            static constexpr auto RUNSTDBY  = std::uint_fast8_t{ 1 }; ///< RUNSTDBY.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ 1 }; ///< RESERVED7.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto ENABLE = std::uint_fast8_t{}; ///< ENABLE.
            static constexpr auto CLKSEL = std::uint_fast8_t{ ENABLE + Size::ENABLE }; ///< CLKSEL.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ CLKSEL + Size::CLKSEL }; ///< RESERVED3.
            static constexpr auto SYNCUPD = std::uint_fast8_t{ RESERVED3 + Size::RESERVED3 }; ///< SYNCUPD.
            static constexpr auto RESERVED5 = std::uint_fast8_t{ SYNCUPD + Size::SYNCUPD }; ///< RESERVED5.
            static constexpr auto RUNSTDBY = std::uint_fast8_t{ RESERVED5 + Size::RESERVED5 }; ///< RUNSTDBY.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ RUNSTDBY + Size::RUNSTDBY }; ///< RESERVED7.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto ENABLE = mask<std::uint8_t>( Size::ENABLE, Bit::ENABLE ); ///< ENABLE.
            static constexpr auto CLKSEL = mask<std::uint8_t>( Size::CLKSEL, Bit::CLKSEL ); ///< CLKSEL.
            static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
            static constexpr auto SYNCUPD = mask<std::uint8_t>( Size::SYNCUPD, Bit::SYNCUPD ); ///< SYNCUPD.
            static constexpr auto RESERVED5 = mask<std::uint8_t>( Size::RESERVED5, Bit::RESERVED5 ); ///< RESERVED5.
            static constexpr auto RUNSTDBY = mask<std::uint8_t>( Size::RUNSTDBY, Bit::RUNSTDBY ); ///< RUNSTDBY.
            static constexpr auto RESERVED7 = mask<std::uint8_t>( Size::RESERVED7, Bit::RESERVED7 ); ///< RESERVED7.
        };

        /**
         * \brief CLKSEL.
         */
        enum CLKSEL : std::uint8_t {
            CLKSEL_CLKDIV1 = 0x0 << Bit::CLKSEL, ///< CLK_PER.
            CLKSEL_CLKDIV2 = 0x1 << Bit::CLKSEL, ///< CLK_PER/2.
            CLKSEL_CLKTCA  = 0x2 << Bit::CLKSEL, ///< Use CLK_TCA from TCA0.
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
     * - Timer Mode (CNTMODE)
     * - Compare/Capture Output Enable (CCMPEN)
     * - Compare/Capture Pin Initial Value (CCMPINIT)
     * - Asynchronous Enable (ASYNC)
     */
    class CTRLB : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto CNTMODE   = std::uint_fast8_t{ 3 }; ///< CNTMODE.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ 1 }; ///< RESERVED3.
            static constexpr auto CCMPEN    = std::uint_fast8_t{ 1 }; ///< CCMPEN.
            static constexpr auto CCMPINIT  = std::uint_fast8_t{ 1 }; ///< CCMPINIT.
            static constexpr auto ASYNC     = std::uint_fast8_t{ 1 }; ///< ASYNC.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ 1 }; ///< RESERVED7.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto CNTMODE = std::uint_fast8_t{}; ///< CNTMODE.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ CNTMODE + Size::CNTMODE }; ///< RESERVED3.
            static constexpr auto CCMPEN = std::uint_fast8_t{ RESERVED3 + Size::RESERVED3 }; ///< CCMPEN.
            static constexpr auto CCMPINIT = std::uint_fast8_t{ CCMPEN + Size::CCMPEN }; ///< CCMPINIT.
            static constexpr auto ASYNC = std::uint_fast8_t{ CCMPINIT + Size::CCMPINIT }; ///< ASYNC.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ ASYNC + Size::ASYNC }; ///< RESERVED7.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto CNTMODE = mask<std::uint8_t>( Size::CNTMODE, Bit::CNTMODE ); ///< CNTMODE.
            static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
            static constexpr auto CCMPEN = mask<std::uint8_t>( Size::CCMPEN, Bit::CCMPEN ); ///< CCMPEN.
            static constexpr auto CCMPINIT = mask<std::uint8_t>( Size::CCMPINIT, Bit::CCMPINIT ); ///< CCMPINIT.
            static constexpr auto ASYNC = mask<std::uint8_t>( Size::ASYNC, Bit::ASYNC ); ///< ASYNC.
            static constexpr auto RESERVED7 = mask<std::uint8_t>( Size::RESERVED7, Bit::RESERVED7 ); ///< RESERVED7.
        };

        /**
         * \brief CNTMODE.
         */
        enum CNTMODE : std::uint8_t {
            CNTMODE_INT     = 0x0 << Bit::CNTMODE, ///< Periodic interrupt mode.
            CNTMODE_TIMEOUT = 0x1 << Bit::CNTMODE, ///< Time-out check mode.
            CNTMODE_CAPT    = 0x2 << Bit::CNTMODE, ///< Input capture on event mode.
            CNTMODE_FRQ = 0x3 << Bit::CNTMODE, ///< Input capture frequency measurement mode.
            CNTMODE_PW = 0x4 << Bit::CNTMODE, ///< Input capture pulse-width measurement mode.
            CNTMODE_FRQPW  = 0x5 << Bit::CNTMODE, ///< Input capture frequency and pulse-width measurement mode.
            CNTMODE_SINGLE = 0x6 << Bit::CNTMODE, ///< Single-shot mode.
            CNTMODE_PWM8   = 0x7 << Bit::CNTMODE, ///< 8-bit PWM mode.
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
     * \brief Event Control (EVCTRL) register.
     *
     * This register has the following fields:
     * - Capture Event Input Enable (CAPTEI)
     * - Event Edge (EDGE)
     * - Input Capture Noise Cancellation Filter (FILTER)
     */
    class EVCTRL : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto CAPTEI    = std::uint_fast8_t{ 1 }; ///< CAPTEI.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 3 }; ///< RESERVED1.
            static constexpr auto EDGE      = std::uint_fast8_t{ 1 }; ///< EDGE.
            static constexpr auto RESERVED5 = std::uint_fast8_t{ 1 }; ///< RESERVED5.
            static constexpr auto FILTER    = std::uint_fast8_t{ 1 }; ///< FILTER.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ 1 }; ///< RESERVED7.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto CAPTEI = std::uint_fast8_t{}; ///< CAPTEI.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ CAPTEI + Size::CAPTEI }; ///< RESERVED1.
            static constexpr auto EDGE = std::uint_fast8_t{ RESERVED1 + Size::RESERVED1 }; ///< EDGE.
            static constexpr auto RESERVED5 = std::uint_fast8_t{ EDGE + Size::EDGE }; ///< RESERVED5.
            static constexpr auto FILTER = std::uint_fast8_t{ RESERVED5 + Size::RESERVED5 }; ///< FILTER.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ FILTER + Size::FILTER }; ///< RESERVED7.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto CAPTEI = mask<std::uint8_t>( Size::CAPTEI, Bit::CAPTEI ); ///< CAPTEI.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
            static constexpr auto EDGE = mask<std::uint8_t>( Size::EDGE, Bit::EDGE ); ///< EDGE.
            static constexpr auto RESERVED5 = mask<std::uint8_t>( Size::RESERVED5, Bit::RESERVED5 ); ///< RESERVED5.
            static constexpr auto FILTER = mask<std::uint8_t>( Size::FILTER, Bit::FILTER ); ///< FILTER.
            static constexpr auto RESERVED7 = mask<std::uint8_t>( Size::RESERVED7, Bit::RESERVED7 ); ///< RESERVED7.
        };

        EVCTRL() = delete;

        EVCTRL( EVCTRL && ) = delete;

        EVCTRL( EVCTRL const & ) = delete;

        ~EVCTRL() = delete;

        auto operator=( EVCTRL && ) = delete;

        auto operator=( EVCTRL const & ) = delete;

        using Register<std::uint8_t>::operator=;
    };

    /**
     * \brief Interrupt Control (INTCTRL) register.
     *
     * This register has the following fields:
     * - Capture Interrupt Enable (CAPT)
     */
    class INTCTRL : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto CAPT      = std::uint_fast8_t{ 1 }; ///< CAPT.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 7 }; ///< RESERVED1.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto CAPT = std::uint_fast8_t{}; ///< CAPT.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ CAPT + Size::CAPT }; ///< RESERVED1.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto CAPT = mask<std::uint8_t>( Size::CAPT, Bit::CAPT ); ///< CAPT.
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
     * - Capture Interrupt Flag (CAPT)
     */
    class INTFLAGS : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto CAPT      = std::uint_fast8_t{ 1 }; ///< CAPT.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 7 }; ///< RESERVED1.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto CAPT = std::uint_fast8_t{}; ///< CAPT.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ CAPT + Size::CAPT }; ///< RESERVED1.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto CAPT = mask<std::uint8_t>( Size::CAPT, Bit::CAPT ); ///< CAPT.
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
     * \brief Status (STATUS) register.
     *
     * This register has the following fields:
     * - Run (RUN)
     */
    class STATUS : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto RUN       = std::uint_fast8_t{ 1 }; ///< RUN.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 7 }; ///< RESERVED1.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto RUN = std::uint_fast8_t{}; ///< RUN.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ RUN + Size::RUN }; ///< RESERVED1.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto RUN = mask<std::uint8_t>( Size::RUN, Bit::RUN ); ///< RUN.
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
     * \brief (DBGCTRL) register.
     *
     * This register has the following fields:
     * - Debug Run (DBGRUN)
     */
    class DBGCTRL : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto DBGRUN    = std::uint_fast8_t{ 1 }; ///< DBGRUN.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 7 }; ///< RESERVED1.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto DBGRUN = std::uint_fast8_t{}; ///< DBGRUN.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ DBGRUN + Size::DBGRUN }; ///< RESERVED1.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto DBGRUN = mask<std::uint8_t>( Size::DBGRUN, Bit::DBGRUN ); ///< DBGRUN.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
        };

        DBGCTRL() = delete;

        DBGCTRL( DBGCTRL && ) = delete;

        DBGCTRL( DBGCTRL const & ) = delete;

        ~DBGCTRL() = delete;

        auto operator=( DBGCTRL && ) = delete;

        auto operator=( DBGCTRL const & ) = delete;

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
     * \brief Reserved registers (offset 0x02-0x03).
     */
    Reserved_Register<std::uint8_t> const reserved_0x02_0x03[ ( 0x03 - 0x02 ) + 1 ];

    /**
     * \brief EVCTRL.
     */
    EVCTRL evctrl;

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

    /**
     * \brief DBGCTRL.
     */
    DBGCTRL dbgctrl;

    /**
     * \brief Temporary (TEMP) register.
     */
    Register<std::uint8_t> temp;

    /**
     * \brief Count (CNT) register.
     */
    Register<std::uint16_t> cnt;

    /**
     * \brief Capture/Compare (CCMP) register.
     */
    Register<std::uint16_t> ccmp;

    TCB() = delete;

    TCB( TCB && ) = delete;

    TCB( TCB const & ) = delete;

    ~TCB() = delete;

    auto operator=( TCB && ) = delete;

    auto operator=( TCB const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_TCB_H
