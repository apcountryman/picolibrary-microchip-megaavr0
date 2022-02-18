/**
 * picolibrary-microchip-megaavr0
 *
 * Copyright 2021-2022, Andrew Countryman <apcountryman@gmail.com> and the
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
 * \brief picolibrary::Microchip::megaAVR0::Asynchronous_Serial interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_H

#include <cstdint>
#include <limits>
#include <type_traits>

#include "picolibrary/microchip/megaavr0/multiplexed_signals.h"
#include "picolibrary/microchip/megaavr0/peripheral/usart.h"

/**
 * \brief Microchip megaAVR 0-series asynchronous serial facilities.
 */
namespace picolibrary::Microchip::megaAVR0::Asynchronous_Serial {

/**
 * \brief USART data bits configuration.
 */
enum class USART_Data_Bits : std::uint8_t {
    _5 = Peripheral::USART::CTRLC::CHSIZE_5BIT,  ///< 5.
    _6 = Peripheral::USART::CTRLC::CHSIZE_6BIT,  ///< 6.
    _7 = Peripheral::USART::CTRLC::CHSIZE_7BIT,  ///< 7.
    _8 = Peripheral::USART::CTRLC::CHSIZE_8BIT,  ///< 8.
    _9 = Peripheral::USART::CTRLC::CHSIZE_9BITH, ///< 9.
};

/**
 * \brief USART parity configuration.
 */
enum class USART_Parity : std::uint8_t {
    NONE = Peripheral::USART::CTRLC::PMODE_DISABLED, ///< None.
    EVEN = Peripheral::USART::CTRLC::PMODE_EVEN,     ///< Even.
    ODD  = Peripheral::USART::CTRLC::PMODE_ODD,      ///< Odd.
};

/**
 * \brief USART stop bits configuration.
 */
enum class USART_Stop_Bits : std::uint8_t {
    _1 = 0b0 << Peripheral::USART::CTRLC::Bit::SBMODE, ///< 1.
    _2 = 0b1 << Peripheral::USART::CTRLC::Bit::SBMODE, ///< 2.
};

/**
 * \brief USART clock generator operating speed configuration.
 */
enum class USART_Clock_Generator_Operating_Speed : std::uint8_t {
    NORMAL = Peripheral::USART::CTRLB::RXMODE_NORMAL, ///< Normal.
    DOUBLE = Peripheral::USART::CTRLB::RXMODE_CLK2X,  ///< Double.
};

/**
 * \brief Basic transmitter.
 *
 * \tparam Data_Type The integral type used to hold the data to be transmitted (must be
 *         std::uint8_t or std::uint16_t).
 */
template<typename Data_Type>
class Basic_Transmitter {
  public:
    static_assert( std::is_same_v<Data_Type, std::uint8_t> or std::is_same_v<Data_Type, std::uint16_t> );

    /**
     * \brief The integral type used to hold the data to be transmitted.
     */
    using Data = Data_Type;

    /**
     * \brief Constructor.
     */
    constexpr Basic_Transmitter() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] usart The USART to be used by the transmitter.
     * \param[in] usart_data_bits The desired USART data bits configuration.
     * \param[in] usart_parity The desired USART parity configuration.
     * \param[in] usart_stop_bits The desired USART stop bits configuration.
     * \param[in] usart_clock_generator_operating_speed The desired USART clock generator
     *            operating speed configuration.
     * \param[in] usart_clock_generator_scaling_factor The desired USART clock generator
     *            scaling factor (BAUD register value).
     */
    Basic_Transmitter(
        Peripheral::USART &                   usart,
        USART_Data_Bits                       usart_data_bits,
        USART_Parity                          usart_parity,
        USART_Stop_Bits                       usart_stop_bits,
        USART_Clock_Generator_Operating_Speed usart_clock_generator_operating_speed,
        std::uint16_t usart_clock_generator_scaling_factor ) noexcept :
        m_usart{ &usart }
    {
        configure_transmitter(
            usart_data_bits, usart_parity, usart_stop_bits, usart_clock_generator_operating_speed, usart_clock_generator_scaling_factor );
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Basic_Transmitter( Basic_Transmitter && source ) noexcept :
        m_usart{ source.m_usart }
    {
        source.m_usart = nullptr;
    }

    Basic_Transmitter( Basic_Transmitter const & ) = delete;

    /**
     * \brief Destructor.
     */
    ~Basic_Transmitter() noexcept
    {
        disable();
    }

    /**
     * \brief Assignment operator.
     *
     * \param[in] expression The expression to be assigned.
     *
     * \return The assigned to object.
     */
    constexpr auto & operator=( Basic_Transmitter && expression ) noexcept
    {
        if ( &expression != this ) {
            disable();

            m_usart = expression.m_usart;

            expression.m_usart = nullptr;
        } // if

        return *this;
    }

    /**
     * \brief Initialize the transmitter's hardware.
     */
    void initialize() noexcept
    {
        configure_txd_pin_as_output();

        enable_transmitter();
    }

    /**
     * \brief Transmit data.
     *
     * \param[in] data The data to transmit.
     */
    void transmit( Data data ) noexcept
    {
        while ( not transmit_buffer_is_empty() ) {} // while

        load_transmit_buffer( data );
    }

  private:
    /**
     * \brief The USART used by the transmitter.
     */
    Peripheral::USART * m_usart{};

    /**
     * \brief Disable the transmitter.
     */
    constexpr void disable() noexcept
    {
        if ( m_usart ) {
            disable_transmitter();
        } // if
    }

    /**
     * Configure the transmitter.
     *
     * \param[in] usart_data_bits The desired USART data bits configuration.
     * \param[in] usart_parity The desired USART parity configuration.
     * \param[in] usart_stop_bits The desired USART stop bits configuration.
     * \param[in] usart_clock_generator_operating_speed The desired USART clock generator
     *            operating speed configuration.
     * \param[in] usart_clock_generator_scaling_factor The desired USART clock generator
     *            scaling factor (BAUD register value).
     */
    void configure_transmitter(
        USART_Data_Bits                       usart_data_bits,
        USART_Parity                          usart_parity,
        USART_Stop_Bits                       usart_stop_bits,
        USART_Clock_Generator_Operating_Speed usart_clock_generator_operating_speed,
        std::uint16_t usart_clock_generator_scaling_factor ) noexcept
    {
        m_usart->ctrlb = static_cast<std::uint8_t>( usart_clock_generator_operating_speed );
        m_usart->ctrla = 0;
        m_usart->ctrlc = Peripheral::USART::CTRLC::CMODE_ASYNCHRONOUS
                         | static_cast<std::uint8_t>( usart_data_bits )
                         | static_cast<std::uint8_t>( usart_parity )
                         | static_cast<std::uint8_t>( usart_stop_bits );
        m_usart->status = Peripheral::USART::STATUS::Mask::TXCIF
                          | Peripheral::USART::STATUS::Mask::RXSIF
                          | Peripheral::USART::STATUS::Mask::ISFIF
                          | Peripheral::USART::STATUS::Mask::BDF;
        m_usart->baud = usart_clock_generator_scaling_factor;
    }

    /**
     * \brief Disable the transmitter.
     */
    void disable_transmitter() noexcept
    {
        m_usart->ctrlb &= ~Peripheral::USART::CTRLB::Mask::TXEN;

        // Silicon errata workaround ("TXD Pin Override Not Released When Disabling the
        // Transmitter")
        m_usart->status = 0;
    }

    /**
     * \brief Configure the TXD pin to act as an output.
     */
    void configure_txd_pin_as_output() noexcept
    {
        Multiplexed_Signals::txd_port( *m_usart ).dirset = Multiplexed_Signals::txd_mask( *m_usart );
    }

    /**
     * \brief Enable the transmitter.
     */
    void enable_transmitter() noexcept
    {
        m_usart->ctrlb |= Peripheral::USART::CTRLB::Mask::TXEN;
    }

    /**
     * \brief Check if the transmit buffer is empty.
     *
     * \return true if the transmit buffer is empty.
     * \return false if the transmit buffer is not empty.
     */
    auto transmit_buffer_is_empty() const noexcept -> bool
    {
        return m_usart->status & Peripheral::USART::STATUS::Mask::DREIF;
    }

    /**
     * \brief Load data into the transmit buffer.
     *
     * \param[in] data The data to load into the transmit buffer.
     */
    void load_transmit_buffer( std::uint8_t data ) noexcept
    {
        m_usart->txdatal = data;
    }

    /**
     * \brief Load data into the transmit buffer.
     *
     * \param[in] data The data to load into the transmit buffer.
     */
    void load_transmit_buffer( std::uint16_t data ) noexcept
    {
        m_usart->txdatah = data >> std::numeric_limits<std::uint8_t>::digits;
        m_usart->txdatal = data;
    }
};

} // namespace picolibrary::Microchip::megaAVR0::Asynchronous_Serial

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_H
