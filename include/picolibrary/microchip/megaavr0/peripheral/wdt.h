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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::WDT interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_WDT_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_WDT_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr0/peripheral/instance.h"
#include "picolibrary/microchip/megaavr0/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series Watchdog Timer (WDT) peripheral.
 */
class WDT {
  public:
    enum class Period : std::uint8_t;

    enum class Closed_Period : std::uint8_t;

    enum class Open_Period : std::uint8_t;

    /**
     * \brief Control A (CTRLA) register.
     *
     * This register has the following fields:
     * - Period (PERIOD)
     * - Window (WINDOW)
     */
    class CTRLA : public Protected_Register<std::uint8_t> {
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

        CTRLA() = delete;

        CTRLA( CTRLA && ) = delete;

        CTRLA( CTRLA const & ) = delete;

        ~CTRLA() = delete;

        auto operator=( CTRLA && ) = delete;

        auto operator=( CTRLA const & ) = delete;

        using Protected_Register<std::uint8_t>::operator=;

        /**
         * \brief Enable the watchdog timer in normal mode.
         *
         * \param[in] period The watchdog timer period.
         */
        void enable( Period period ) noexcept
        {
            *this = static_cast<std::uint8_t>( period );
        }

        /**
         * \brief Enable the watchdog timer in window mode.
         *
         * \param[in] closed_period The watchdog timer closed period.
         * \param[in] open_period The watchdog timer open period.
         */
        void enable( Closed_Period closed_period, Open_Period open_period ) noexcept
        {
            *this = static_cast<std::uint8_t>( closed_period )
                    | static_cast<std::uint8_t>( open_period );
        }

        /**
         * \brief Disable the watchdog timer.
         */
        void disable() noexcept
        {
            *this = 0;
        }
    };

    /**
     * \brief Status (STATUS) register.
     *
     * This register has the following fields:
     * - Synchronization Busy (SYNCBUSY)
     * - Lock (LOCK)
     */
    class STATUS : public Protected_Register<std::uint8_t> {
      public:
        /**
         * \brief Field sizes.
         */
        struct Size {
            static constexpr auto SYNCBUSY  = std::uint_fast8_t{ 1 }; ///< SYNCBUSY.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 6 }; ///< RESERVED1.
            static constexpr auto LOCK      = std::uint_fast8_t{ 1 }; ///< LOCK.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto SYNCBUSY = std::uint_fast8_t{}; ///< SYNCBUSY.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ SYNCBUSY + Size::SYNCBUSY }; ///< RESERVED1.
            static constexpr auto LOCK = std::uint_fast8_t{ RESERVED1 + Size::RESERVED1 }; ///< LOCK.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto SYNCBUSY = mask<std::uint8_t>( Size::SYNCBUSY, Bit::SYNCBUSY ); ///< SYNCBUSY.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
            static constexpr auto LOCK = mask<std::uint8_t>( Size::LOCK, Bit::LOCK ); ///< LOCK.
        };

        STATUS() = delete;

        STATUS( STATUS && ) = delete;

        STATUS( STATUS const & ) = delete;

        ~STATUS() = delete;

        auto operator=( STATUS && ) = delete;

        auto operator=( STATUS const & ) = delete;

        using Protected_Register<std::uint8_t>::operator=;

        /**
         * \brief Check if a configuration change is in progress.
         *
         * \return true if a configuration change is in progress.
         * \return false if a configuration change is in not progress.
         */
        auto configuration_change_in_progress() const noexcept
        {
            return static_cast<bool>( *this & Mask::SYNCBUSY );
        }

        /**
         * \brief Lock the watchdog timer configuration.
         */
        void lock_configuration() noexcept
        {
            *this = Mask::LOCK;
        }
    };

    /**
     * \brief Normal mode time-out period.
     */
    enum class Period : std::uint8_t {
        _8_CLK_PERIODS = 0x1 << CTRLA::Bit::PERIOD, ///< 8 1.024 kHz clock periods (8 ms).
        _16_CLK_PERIODS = 0x2 << CTRLA::Bit::PERIOD, ///< 16 1.024 kHz clock periods (16 ms).
        _32_CLK_PERIODS = 0x3 << CTRLA::Bit::PERIOD, ///< 32 1.024 kHz clock periods (31 ms).
        _64_CLK_PERIODS = 0x4 << CTRLA::Bit::PERIOD, ///< 64 1.024 kHz clock periods (63 ms).
        _128_CLK_PERIODS = 0x5 << CTRLA::Bit::PERIOD, ///< 128 1.024 kHz clock periods (125 ms).
        _256_CLK_PERIODS = 0x6 << CTRLA::Bit::PERIOD, ///< 256 1.024 kHz clock periods (250 ms).
        _512_CLK_PERIODS = 0x7 << CTRLA::Bit::PERIOD, ///< 512 1.024 kHz clock periods (500 ms).
        _1K_CLK_PERIODS = 0x8 << CTRLA::Bit::PERIOD, ///< 1k 1.024 kHz clock periods (1 s).
        _2K_CLK_PERIODS = 0x9 << CTRLA::Bit::PERIOD, ///< 2k 1.024 kHz clock periods (2 s).
        _4K_CLK_PERIODS = 0xA << CTRLA::Bit::PERIOD, ///< 4k 1.024 kHz clock periods (4 s).
        _8K_CLK_PERIODS = 0xB << CTRLA::Bit::PERIOD, ///< 8k 1.024 kHz clock periods (8 s).
        _8_MS   = 0x1 << CTRLA::Bit::PERIOD, ///< 8 1.024 kHz clock periods (8 ms).
        _16_MS  = 0x2 << CTRLA::Bit::PERIOD, ///< 16 1.024 kHz clock periods (16 ms).
        _31_MS  = 0x3 << CTRLA::Bit::PERIOD, ///< 32 1.024 kHz clock periods (31 ms).
        _63_MS  = 0x4 << CTRLA::Bit::PERIOD, ///< 64 1.024 kHz clock periods (63 ms).
        _125_MS = 0x5 << CTRLA::Bit::PERIOD, ///< 128 1.024 kHz clock periods (125 ms).
        _250_MS = 0x6 << CTRLA::Bit::PERIOD, ///< 256 1.024 kHz clock periods (250 ms).
        _500_MS = 0x7 << CTRLA::Bit::PERIOD, ///< 512 1.024 kHz clock periods (500 ms).
        _1_S    = 0x8 << CTRLA::Bit::PERIOD, ///< 1k 1.024 kHz clock periods (1 s).
        _2_S    = 0x9 << CTRLA::Bit::PERIOD, ///< 2k 1.024 kHz clock periods (2 s).
        _4_S    = 0xA << CTRLA::Bit::PERIOD, ///< 4k 1.024 kHz clock periods (4 s).
        _8_S    = 0xB << CTRLA::Bit::PERIOD, ///< 8k 1.024 kHz clock periods (8 s).
    };

    /**
     * \brief Window mode closed period.
     */
    enum class Closed_Period : std::uint8_t {
        _8_CLK_PERIODS = 0x1 << CTRLA::Bit::WINDOW, ///< 8 1.024 kHz clock periods (8 ms).
        _16_CLK_PERIODS = 0x2 << CTRLA::Bit::WINDOW, ///< 16 1.024 kHz clock periods (16 ms).
        _32_CLK_PERIODS = 0x3 << CTRLA::Bit::WINDOW, ///< 32 1.024 kHz clock periods (31 ms).
        _64_CLK_PERIODS = 0x4 << CTRLA::Bit::WINDOW, ///< 64 1.024 kHz clock periods (63 ms).
        _128_CLK_PERIODS = 0x5 << CTRLA::Bit::WINDOW, ///< 128 1.024 kHz clock periods (125 ms).
        _256_CLK_PERIODS = 0x6 << CTRLA::Bit::WINDOW, ///< 256 1.024 kHz clock periods (250 ms).
        _512_CLK_PERIODS = 0x7 << CTRLA::Bit::WINDOW, ///< 512 1.024 kHz clock periods (500 ms).
        _1K_CLK_PERIODS = 0x8 << CTRLA::Bit::WINDOW, ///< 1k 1.024 kHz clock periods (1 s).
        _2K_CLK_PERIODS = 0x9 << CTRLA::Bit::WINDOW, ///< 2k 1.024 kHz clock periods (2 s).
        _4K_CLK_PERIODS = 0xA << CTRLA::Bit::WINDOW, ///< 4k 1.024 kHz clock periods (4 s).
        _8K_CLK_PERIODS = 0xB << CTRLA::Bit::WINDOW, ///< 8k 1.024 kHz clock periods (8 s).
        _8_MS   = 0x1 << CTRLA::Bit::WINDOW, ///< 8 1.024 kHz clock periods (8 ms).
        _16_MS  = 0x2 << CTRLA::Bit::WINDOW, ///< 16 1.024 kHz clock periods (16 ms).
        _31_MS  = 0x3 << CTRLA::Bit::WINDOW, ///< 32 1.024 kHz clock periods (31 ms).
        _63_MS  = 0x4 << CTRLA::Bit::WINDOW, ///< 64 1.024 kHz clock periods (63 ms).
        _125_MS = 0x5 << CTRLA::Bit::WINDOW, ///< 128 1.024 kHz clock periods (125 ms).
        _250_MS = 0x6 << CTRLA::Bit::WINDOW, ///< 256 1.024 kHz clock periods (250 ms).
        _500_MS = 0x7 << CTRLA::Bit::WINDOW, ///< 512 1.024 kHz clock periods (500 ms).
        _1_S    = 0x8 << CTRLA::Bit::WINDOW, ///< 1k 1.024 kHz clock periods (1 s).
        _2_S    = 0x9 << CTRLA::Bit::WINDOW, ///< 2k 1.024 kHz clock periods (2 s).
        _4_S    = 0xA << CTRLA::Bit::WINDOW, ///< 4k 1.024 kHz clock periods (4 s).
        _8_S    = 0xB << CTRLA::Bit::WINDOW, ///< 8k 1.024 kHz clock periods (8 s).
    };

    /**
     * \brief Window mode open period.
     */
    enum class Open_Period : std::uint8_t {
        _8_CLK_PERIODS = 0x1 << CTRLA::Bit::PERIOD, ///< 8 1.024 kHz clock periods (8 ms).
        _16_CLK_PERIODS = 0x2 << CTRLA::Bit::PERIOD, ///< 16 1.024 kHz clock periods (16 ms).
        _32_CLK_PERIODS = 0x3 << CTRLA::Bit::PERIOD, ///< 32 1.024 kHz clock periods (31 ms).
        _64_CLK_PERIODS = 0x4 << CTRLA::Bit::PERIOD, ///< 64 1.024 kHz clock periods (63 ms).
        _128_CLK_PERIODS = 0x5 << CTRLA::Bit::PERIOD, ///< 128 1.024 kHz clock periods (125 ms).
        _256_CLK_PERIODS = 0x6 << CTRLA::Bit::PERIOD, ///< 256 1.024 kHz clock periods (250 ms).
        _512_CLK_PERIODS = 0x7 << CTRLA::Bit::PERIOD, ///< 512 1.024 kHz clock periods (500 ms).
        _1K_CLK_PERIODS = 0x8 << CTRLA::Bit::PERIOD, ///< 1k 1.024 kHz clock periods (1 s).
        _2K_CLK_PERIODS = 0x9 << CTRLA::Bit::PERIOD, ///< 2k 1.024 kHz clock periods (2 s).
        _4K_CLK_PERIODS = 0xA << CTRLA::Bit::PERIOD, ///< 4k 1.024 kHz clock periods (4 s).
        _8K_CLK_PERIODS = 0xB << CTRLA::Bit::PERIOD, ///< 8k 1.024 kHz clock periods (8 s).
        _8_MS   = 0x1 << CTRLA::Bit::PERIOD, ///< 8 1.024 kHz clock periods (8 ms).
        _16_MS  = 0x2 << CTRLA::Bit::PERIOD, ///< 16 1.024 kHz clock periods (16 ms).
        _31_MS  = 0x3 << CTRLA::Bit::PERIOD, ///< 32 1.024 kHz clock periods (31 ms).
        _63_MS  = 0x4 << CTRLA::Bit::PERIOD, ///< 64 1.024 kHz clock periods (63 ms).
        _125_MS = 0x5 << CTRLA::Bit::PERIOD, ///< 128 1.024 kHz clock periods (125 ms).
        _250_MS = 0x6 << CTRLA::Bit::PERIOD, ///< 256 1.024 kHz clock periods (250 ms).
        _500_MS = 0x7 << CTRLA::Bit::PERIOD, ///< 512 1.024 kHz clock periods (500 ms).
        _1_S    = 0x8 << CTRLA::Bit::PERIOD, ///< 1k 1.024 kHz clock periods (1 s).
        _2_S    = 0x9 << CTRLA::Bit::PERIOD, ///< 2k 1.024 kHz clock periods (2 s).
        _4_S    = 0xA << CTRLA::Bit::PERIOD, ///< 4k 1.024 kHz clock periods (4 s).
        _8_S    = 0xB << CTRLA::Bit::PERIOD, ///< 8k 1.024 kHz clock periods (8 s).
    };

    /**
     * \brief CTRLA.
     */
    CTRLA ctrla;

    /**
     * \brief Status.
     */
    STATUS status;

    WDT() = delete;

    WDT( WDT && ) = delete;

    WDT( WDT const & ) = delete;

    ~WDT() = delete;

    auto operator=( WDT && ) = delete;

    auto operator=( WDT const & ) = delete;

    /**
     * \brief Enable the watchdog timer in normal mode.
     *
     * \param[in] period The watchdog timer period.
     */
    void enable( Period period ) noexcept
    {
        ctrla.enable( period );
    }

    /**
     * \brief Enable the watchdog timer in window mode.
     *
     * \param[in] closed_period The watchdog timer closed period.
     * \param[in] open_period The watchdog timer open period.
     */
    void enable( Closed_Period closed_period, Open_Period open_period ) noexcept
    {
        ctrla.enable( closed_period, open_period );
    }

    /**
     * \brief Disable the watchdog timer.
     */
    void disable() noexcept
    {
        ctrla.disable();
    }

    /**
     * \brief Check if a configuration change is in progress.
     *
     * \return true if a configuration change is in progress.
     * \return false if a configuration change is in not progress.
     */
    auto configuration_change_in_progress() const noexcept
    {
        return status.configuration_change_in_progress();
    }

    /**
     * \brief Lock the watchdog timer configuration.
     */
    void lock_configuration() noexcept
    {
        status.lock_configuration();
    }
};

/**
 * \brief Microchip megaAVR 0-series Watchdog Timer (WDT) peripheral instance.
 *
 * \tparam INSTANCE_ADDRESS The address of the WDT instance.
 */
template<std::uintptr_t INSTANCE_ADDRESS>
using WDT_Instance = Instance<WDT, INSTANCE_ADDRESS>;

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_WDT_H
