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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::SPI interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_SPI_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_SPI_H

#include <cstdint>

#include "picolibrary/bit_manipulation.h"
#include "picolibrary/microchip/megaavr0/peripheral/instance.h"
#include "picolibrary/microchip/megaavr0/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series Serial Peripheral Interface (SPI) peripheral.
 */
class SPI {
  public:
    enum class Clock_Rate : std::uint8_t;

    enum class Clock_Polarity : std::uint8_t;

    enum class Clock_Phase : std::uint8_t;

    enum class Bit_Order : std::uint8_t;

    /**
     * \brief Control A (CTRLA) register.
     *
     * This register has the following fields:
     * - SPI Enable (ENABLE)
     * - Prescaler (PRESC)
     * - Clock Double (CLK2X)
     * - Host/Client Select (HOST)
     * - Data Order (DORD)
     */
    class CTRLA : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field Sizes.
         */
        struct Size {
            static constexpr auto ENABLE    = std::uint_fast8_t{ 1 }; ///< ENABLE.
            static constexpr auto PRESC     = std::uint_fast8_t{ 2 }; ///< PRESC.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ 1 }; ///< RESERVED3.
            static constexpr auto CLK2X     = std::uint_fast8_t{ 1 }; ///< CLK2X.
            static constexpr auto HOST      = std::uint_fast8_t{ 1 }; ///< HOST.
            static constexpr auto DORD      = std::uint_fast8_t{ 1 }; ///< DORD.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ 1 }; ///< RESERVED7.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto ENABLE = std::uint_fast8_t{}; ///< ENABLE.
            static constexpr auto PRESC = std::uint_fast8_t{ ENABLE + Size::ENABLE }; ///< PRESC.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ PRESC + Size::PRESC }; ///< RESERVED3.
            static constexpr auto CLK2X = std::uint_fast8_t{ RESERVED3 + Size::RESERVED3 }; ///< CLK2X.
            static constexpr auto HOST = std::uint_fast8_t{ CLK2X + Size::CLK2X }; ///< HOST.
            static constexpr auto DORD = std::uint_fast8_t{ HOST + Size::HOST }; ///< DORD.
            static constexpr auto RESERVED7 = std::uint_fast8_t{ DORD + Size::DORD }; ///< RESERVED7.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto ENABLE = mask<std::uint8_t>( Size::ENABLE, Bit::ENABLE ); ///< ENABLE.
            static constexpr auto PRESC = mask<std::uint8_t>( Size::PRESC, Bit::PRESC ); ///< PRESC.
            static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
            static constexpr auto CLK2X = mask<std::uint8_t>( Size::CLK2X, Bit::CLK2X ); ///< CLK2X.
            static constexpr auto HOST = mask<std::uint8_t>( Size::HOST, Bit::HOST ); ///< HOST.
            static constexpr auto DORD = mask<std::uint8_t>( Size::DORD, Bit::DORD ); ///< DORD.
            static constexpr auto RESERVED7 = mask<std::uint8_t>( Size::RESERVED7, Bit::RESERVED7 ); ///< RESERVED7.
        };

        CTRLA() = delete;

        CTRLA( CTRLA && ) = delete;

        CTRLA( CTRLA const & ) = delete;

        ~CTRLA() = delete;

        auto operator=( CTRLA && ) = delete;

        auto operator=( CTRLA const & ) = delete;

        using Register<std::uint8_t>::operator=;

        /**
         * \brief Configure the SPI for use as an unbuffered SPI controller.
         */
        void configure_as_unbuffered_spi_controller() noexcept
        {
            *this = Mask::HOST;
        }

        /**
         * \brief Enable the SPI.
         */
        void enable() noexcept
        {
            *this |= Mask::ENABLE;
        }

        /**
         * \brief Disable the SPI.
         */
        void disable() noexcept
        {
            *this &= ~Mask::ENABLE;
        }

        /**
         * \brief Configure SPI data exchange.
         *
         * \param[in] clock_rate The desired clock rate.
         * \param[in] bit_order The desired data exchange bit order.
         */
        void configure( Clock_Rate clock_rate, Bit_Order bit_order ) noexcept
        {
            *this = ( *this & ~( Mask::PRESC | Mask::CLK2X | Mask::DORD ) )
                    | static_cast<std::uint8_t>( clock_rate )
                    | static_cast<std::uint8_t>( bit_order );
        }
    };

    /**
     * \brief Control B (CTRLB) register.
     *
     * This register has the following fields:
     * - Mode (MODE)
     * - Client Select Disable (CSD)
     * - Buffer Mode Wait for Receive (BUFWR)
     * - Buffer Mode Enable (BUFEN)
     */
    class CTRLB : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field Sizes.
         */
        struct Size {
            static constexpr auto MODE      = std::uint_fast8_t{ 2 }; ///< MODE.
            static constexpr auto CSD       = std::uint_fast8_t{ 1 }; ///< CSD.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ 3 }; ///< RESERVED3.
            static constexpr auto BUFWR     = std::uint_fast8_t{ 1 }; ///< BUFWR.
            static constexpr auto BUFEN     = std::uint_fast8_t{ 1 }; ///< BUFEN.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto MODE = std::uint_fast8_t{}; ///< MODE.
            static constexpr auto CSD  = std::uint_fast8_t{ MODE + Size::MODE }; ///< CSD.
            static constexpr auto RESERVED3 = std::uint_fast8_t{ CSD + Size::CSD }; ///< RESERVED3.
            static constexpr auto BUFWR = std::uint_fast8_t{ RESERVED3 + Size::RESERVED3 }; ///< BUFWR.
            static constexpr auto BUFEN = std::uint_fast8_t{ BUFWR + Size::BUFWR }; ///< BUFEN.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto MODE = mask<std::uint8_t>( Size::MODE, Bit::MODE ); ///< MODE.
            static constexpr auto CSD = mask<std::uint8_t>( Size::CSD, Bit::CSD ); ///< CSD.
            static constexpr auto RESERVED3 = mask<std::uint8_t>( Size::RESERVED3, Bit::RESERVED3 ); ///< RESERVED3.
            static constexpr auto BUFWR = mask<std::uint8_t>( Size::BUFWR, Bit::BUFWR ); ///< BUFWR.
            static constexpr auto BUFEN = mask<std::uint8_t>( Size::BUFEN, Bit::BUFEN ); ///< BUFEN.
        };

        CTRLB() = delete;

        CTRLB( CTRLB && ) = delete;

        CTRLB( CTRLB const & ) = delete;

        ~CTRLB() = delete;

        auto operator=( CTRLB && ) = delete;

        auto operator=( CTRLB const & ) = delete;

        using Register<std::uint8_t>::operator=;

        /**
         * \brief Configure the SPI for use as an unbuffered SPI controller.
         */
        void configure_as_unbuffered_spi_controller() noexcept
        {
            *this = Mask::CSD;
        }

        /**
         * \brief Configure SPI data exchange.
         *
         * \param[in] clock_polarity The desired clock polarity.
         * \param[in] clock_phase The desired clock phase.
         */
        void configure( Clock_Polarity clock_polarity, Clock_Phase clock_phase ) noexcept
        {
            *this = ( *this & ~Mask::MODE ) | static_cast<std::uint8_t>( clock_polarity )
                    | static_cast<std::uint8_t>( clock_phase );
        }
    };

    /**
     * \brief Interrupt Control (INTCTRL) register.
     *
     * This register has the following fields:
     * - Interrupt Enable (IE)
     * - Client Select Trigger Interrupt Enable (CSIE)
     * - Data Register Empty Interrupt Enable (DREIE)
     * - Transfer Complete Interrupt Enable (TXCIE)
     * - Receive Complete Interrupt Enable (RXCIE)
     */
    class INTCTRL : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field Sizes.
         */
        struct Size {
            static constexpr auto IE        = std::uint_fast8_t{ 1 }; ///< IE.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 3 }; ///< RESERVED1.
            static constexpr auto CSIE      = std::uint_fast8_t{ 1 }; ///< CSIE.
            static constexpr auto DREIE     = std::uint_fast8_t{ 1 }; ///< DREIE.
            static constexpr auto TXCIE     = std::uint_fast8_t{ 1 }; ///< TXCIE.
            static constexpr auto RXCIE     = std::uint_fast8_t{ 1 }; ///< RXCIE.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto IE        = std::uint_fast8_t{};                ///< IE.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ IE + Size::IE }; ///< RESERVED1.
            static constexpr auto CSIE = std::uint_fast8_t{ RESERVED1 + Size::RESERVED1 }; ///< CSIE.
            static constexpr auto DREIE = std::uint_fast8_t{ CSIE + Size::CSIE }; ///< DREIE.
            static constexpr auto TXCIE = std::uint_fast8_t{ DREIE + Size::DREIE }; ///< TXCIE.
            static constexpr auto RXCIE = std::uint_fast8_t{ TXCIE + Size::TXCIE }; ///< RXCIE.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto IE = mask<std::uint8_t>( Size::IE, Bit::IE ); ///< IE.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
            static constexpr auto CSIE = mask<std::uint8_t>( Size::CSIE, Bit::CSIE ); ///< CSIE.
            static constexpr auto DREIE = mask<std::uint8_t>( Size::DREIE, Bit::DREIE ); ///< DREIE.
            static constexpr auto TXCIE = mask<std::uint8_t>( Size::TXCIE, Bit::TXCIE ); ///< TXCIE.
            static constexpr auto RXCIE = mask<std::uint8_t>( Size::RXCIE, Bit::RXCIE ); ///< RXCIE.
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
     * - Write Collision (WRCOL)
     * - Interrupt Flag (IF)
     * - Buffer Overflow (BUFOVF)
     * - Client Select Trigger Interrupt Flag (CSIF)
     * - Data Register Empty Interrupt Flag (DREIF)
     * - Transfer Complete Interrupt Flag (TXCIF)
     * - Receive Complete Interrupt Flag (RXCIE)
     */
    class INTFLAGS : public Register<std::uint8_t> {
      public:
        /**
         * \brief Field Sizes.
         */
        struct Size {
            static constexpr auto RESERVED0 = std::uint_fast8_t{ 6 }; ///< RESERVED0.
            static constexpr auto WRCOL     = std::uint_fast8_t{ 1 }; ///< WRCOL.
            static constexpr auto IF        = std::uint_fast8_t{ 1 }; ///< IF.

            static constexpr auto BUFOVF    = std::uint_fast8_t{ 1 }; ///< BUFOVF.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ 3 }; ///< RESERVED1.
            static constexpr auto CSIF      = std::uint_fast8_t{ 1 }; ///< CSIF.
            static constexpr auto DREIF     = std::uint_fast8_t{ 1 }; ///< DREIF.
            static constexpr auto TXCIF     = std::uint_fast8_t{ 1 }; ///< TXCIF.
            static constexpr auto RXCIF     = std::uint_fast8_t{ 1 }; ///< RXCIF.
        };

        /**
         * \brief Field bit positions.
         */
        struct Bit {
            static constexpr auto RESERVED0 = std::uint_fast8_t{}; ///< RESERVED0.
            static constexpr auto WRCOL = std::uint_fast8_t{ RESERVED0 + Size::RESERVED0 }; ///< WRCOL.
            static constexpr auto IF = std::uint_fast8_t{ WRCOL + Size::WRCOL }; ///< IF.

            static constexpr auto BUFOVF = std::uint_fast8_t{}; ///< BUFOVF.
            static constexpr auto RESERVED1 = std::uint_fast8_t{ BUFOVF + Size::BUFOVF }; ///< RESERVED1.
            static constexpr auto CSIF = std::uint_fast8_t{ RESERVED1 + Size::RESERVED1 }; ///< CSIF.
            static constexpr auto DREIF = std::uint_fast8_t{ CSIF + Size::CSIF }; ///< DREIF.
            static constexpr auto TXCIF = std::uint_fast8_t{ DREIF + Size::DREIF }; ///< TXCIF.
            static constexpr auto RXCIF = std::uint_fast8_t{ TXCIF + Size::TXCIF }; ///< RXCIF.
        };

        /**
         * \brief Field bit masks.
         */
        struct Mask {
            static constexpr auto RESERVED0 = mask<std::uint8_t>( Size::RESERVED0, Bit::RESERVED0 ); ///< RESERVED0.
            static constexpr auto WRCOL = mask<std::uint8_t>( Size::WRCOL, Bit::WRCOL ); ///< WRCOL.
            static constexpr auto IF = mask<std::uint8_t>( Size::IF, Bit::IF ); ///< IF.

            static constexpr auto BUFOVF = mask<std::uint8_t>( Size::BUFOVF, Bit::BUFOVF ); ///< BUFOVF.
            static constexpr auto RESERVED1 = mask<std::uint8_t>( Size::RESERVED1, Bit::RESERVED1 ); ///< RESERVED1.
            static constexpr auto CSIF = mask<std::uint8_t>( Size::CSIF, Bit::CSIF ); ///< CSIF.
            static constexpr auto DREIF = mask<std::uint8_t>( Size::DREIF, Bit::DREIF ); ///< DREIF.
            static constexpr auto TXCIF = mask<std::uint8_t>( Size::TXCIF, Bit::TXCIF ); ///< TXCIF.
            static constexpr auto RXCIF = mask<std::uint8_t>( Size::RXCIF, Bit::RXCIF ); ///< RXCIF.
        };

        INTFLAGS() = delete;

        INTFLAGS( INTFLAGS && ) = delete;

        INTFLAGS( INTFLAGS const & ) = delete;

        ~INTFLAGS() = delete;

        auto operator=( INTFLAGS && ) = delete;

        auto operator=( INTFLAGS const & ) = delete;

        using Register<std::uint8_t>::operator=;

        /**
         * \brief Check if data exchange is complete.
         *
         * \return true if data exchange is complete.
         * \return false if data exchange is not complete.
         */
        auto data_exchange_complete() const noexcept -> bool
        {
            return *this & Mask::IF;
        }
    };

    /**
     * \brief Clock rate.
     */
    enum class Clock_Rate : std::uint8_t {
        FCLK_PER_2   = ( 0b1 << CTRLA::Bit::CLK2X ) | ( 0x0 << CTRLA::Bit::PRESC ), ///< Peripheral clock frequency / 2.
        FCLK_PER_4   = ( 0b0 << CTRLA::Bit::CLK2X ) | ( 0x0 << CTRLA::Bit::PRESC ), ///< Peripheral clock frequency / 4.
        FCLK_PER_8   = ( 0b1 << CTRLA::Bit::CLK2X ) | ( 0x1 << CTRLA::Bit::PRESC ), ///< Peripheral clock frequency / 8.
        FCLK_PER_16  = ( 0b0 << CTRLA::Bit::CLK2X ) | ( 0x1 << CTRLA::Bit::PRESC ), ///< Peripheral clock frequency / 16.
        FCLK_PER_32  = ( 0b1 << CTRLA::Bit::CLK2X ) | ( 0x2 << CTRLA::Bit::PRESC ), ///< Peripheral clock frequency / 32.
        FCLK_PER_64  = ( 0b0 << CTRLA::Bit::CLK2X ) | ( 0x2 << CTRLA::Bit::PRESC ), ///< Peripheral clock frequency / 64.
        FCLK_PER_128 = ( 0b0 << CTRLA::Bit::CLK2X ) | ( 0x3 << CTRLA::Bit::PRESC ), ///< Peripheral clock frequency / 128.
    };

    /**
     * \brief Clock polarity.
     */
    enum class Clock_Polarity : std::uint8_t {
        IDLE_LOW  = 0b00 << CTRLB::Bit::MODE, ///< Idle low.
        IDLE_HIGH = 0b10 << CTRLB::Bit::MODE, ///< Idle high.
    };

    /**
     * \brief Clock phase.
     */
    enum class Clock_Phase : std::uint8_t {
        CAPTURE_IDLE_TO_ACTIVE = 0b00 << CTRLB::Bit::MODE, ///< Capture data on the idle-to-active clock transition.
        CAPTURE_ACTIVE_TO_IDLE = 0b01 << CTRLB::Bit::MODE, ///< Capture data on the active-to-idle clock transition.
    };

    /**
     * \brief Data exchange bit order.
     */
    enum class Bit_Order : std::uint8_t {
        MSB_FIRST = 0b0 << CTRLA::Bit::DORD, ///< Exchange data MSB first.
        LSB_FIRST = 0b1 << CTRLA::Bit::DORD, ///< Exchange data LSB first.
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
     * \brief INTCTRL.
     */
    INTCTRL intctrl;

    /**
     * \brief INTFLAGS.
     */
    INTFLAGS intflags;

    /**
     * \brief Data (DATA) register.
     */
    Register<std::uint8_t> data;

    SPI() = delete;

    SPI( SPI && ) = delete;

    SPI( SPI const & ) = delete;

    ~SPI() = delete;

    auto operator=( SPI && ) = delete;

    auto operator=( SPI const & ) = delete;

    /**
     * \brief Configure the SPI for use as an unbuffered SPI controller.
     */
    void configure_as_unbuffered_spi_controller() noexcept
    {
        ctrlb.configure_as_unbuffered_spi_controller();
        ctrla.configure_as_unbuffered_spi_controller();
    }

    /**
     * \brief Enable the SPI.
     */
    void enable() noexcept
    {
        ctrla.enable();
    }

    /**
     * \brief Disable the SPI.
     */
    void disable() noexcept
    {
        ctrla.disable();
    }

    /**
     * \brief Configure SPI data exchange.
     *
     * \param[in] clock_rate The desired clock rate.
     * \param[in] clock_polarity The desired clock polarity.
     * \param[in] clock_phase The desired clock phase.
     * \param[in] bit_order The desired data exchange bit order.
     */
    void configure( Clock_Rate clock_rate, Clock_Polarity clock_polarity, Clock_Phase clock_phase, Bit_Order bit_order ) noexcept
    {
        ctrla.configure( clock_rate, bit_order );
        ctrlb.configure( clock_polarity, clock_phase );
    }

    /**
     * \brief Check if data exchange is complete.
     *
     * \return true if data exchange is complete.
     * \return false if data exchange is not complete.
     */
    auto data_exchange_complete() const noexcept
    {
        return intflags.data_exchange_complete();
    }

    /**
     * \brief Write data to the transmit buffer.
     *
     * \param[in] data_ The data to write to the transmit buffer.
     */
    void transmit( std::uint8_t data_ ) noexcept
    {
        data = data_;
    }

    /**
     * \brief Read data from the receive buffer.
     *
     * \return The data read from the receive buffer.
     */
    auto receive() noexcept -> std::uint8_t
    {
        return data;
    }
};

/**
 * \brief Microchip megaAVR 0-series Serial Peripheral Interface (SPI) peripheral
 *        instance.
 *
 * \tparam INSTANCE_ADDRESS The address of the SPI instance.
 */
template<std::uintptr_t INSTANCE_ADDRESS>
using SPI_Instance = Instance<SPI, INSTANCE_ADDRESS>;

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_SPI_H
