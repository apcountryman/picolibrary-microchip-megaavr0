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
 * \brief picolibrary::Microchip::megaAVR0::Asynchronous_Serial interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_H

#include <cstdint>
#include <utility>

#include "picolibrary/asynchronous_serial.h"
#include "picolibrary/gpio.h"
#include "picolibrary/microchip/megaavr0/gpio.h"
#include "picolibrary/microchip/megaavr0/multiplexed_signals.h"
#include "picolibrary/microchip/megaavr0/peripheral/port.h"
#include "picolibrary/microchip/megaavr0/peripheral/usart.h"
#include "picolibrary/result.h"
#include "picolibrary/void.h"

/**
 * \brief Microchip megaAVR 0-series asynchronous serial facilities.
 */
namespace picolibrary::Microchip::megaAVR0::Asynchronous_Serial {

/**
 * \brief Microchip megaAVR 0-series asynchronous serial clock configuration.
 */
struct Clock_Configuration {
    /**
     * \brief The clock generator operating speed.
     */
    Peripheral::USART::Operating_Speed operating_speed;

    /**
     * \brief The clock generator scaling factor.
     */
    std::uint16_t scaling_factor;
};

/**
 * \brief Microchip megaAVR 0-series asynchronous serial basic transmitter.
 *
 * \tparam Data_Type The integral type used to hold the data to be transmitted.
 */
template<typename Data_Type>
class Basic_Transmitter {
  public:
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
     * \param[in] data_bits The desired number of data bits.
     * \param[in] parity The desired parity mode.
     * \param[in] stop_bits The desired number of stop bits.
     * \param[in] clock_configuration The desired clock generator configuration.
     */
    Basic_Transmitter(
        Peripheral::USART &          usart,
        Peripheral::USART::Data_Bits data_bits,
        Peripheral::USART::Parity    parity,
        Peripheral::USART::Stop_Bits stop_bits,
        Clock_Configuration const &  clock_configuration ) noexcept :
        m_usart{ &usart },
        m_txd{ Multiplexed_Signals::txd_port( usart ), Multiplexed_Signals::txd_mask( usart ) }
    {
        m_usart->configure_as_asynchronous_serial_usart(
            data_bits,
            parity,
            stop_bits,
            clock_configuration.operating_speed,
            clock_configuration.scaling_factor );
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Basic_Transmitter( Basic_Transmitter && source ) noexcept :
        m_usart{ source.m_usart },
        m_txd{ std::move( source.m_txd ) }
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
    auto & operator=( Basic_Transmitter && expression ) noexcept
    {
        if ( &expression != this ) {
            disable();

            m_usart = expression.m_usart;
            m_txd   = std::move( expression.m_txd );

            expression.m_usart = nullptr;
        } // if

        return *this;
    }

    auto operator=( Basic_Transmitter const & ) = delete;

    /**
     * \brief Initialize the transmitter's hardware.
     *
     * \return Success.
     */
    auto initialize() noexcept -> Result<Void, Void>
    {
        static_cast<void>( m_txd.initialize( ::picolibrary::GPIO::Initial_Pin_State::HIGH ) );

        m_usart->enable_transmitter();

        return {};
    }

    /**
     * \brief Transmit data.
     *
     * \param[in] data The data to transmit.
     *
     * \return Success.
     */
    auto transmit( Data data ) noexcept -> Result<Void, Void>
    {
        while ( not m_usart->transmit_buffer_empty() ) {}

        m_usart->transmit( data );

        return {};
    }

  private:
    /**
     * \brief The USART used by the transmitter.
     */
    Peripheral::USART * m_usart{};

    /**
     * \brief The USART's TXD pin.
     */
    GPIO::Push_Pull_IO_Pin<Peripheral::PORT> m_txd{};

    /**
     * \brief Disable the transmitter.
     */
    void disable() noexcept
    {
        if ( m_usart ) {
            m_usart->disable_transmitter();
        } // if
    }
};

/**
 * \brief Microchip megaAVR 0-series asynchronous serial transmitter.
 *
 * \tparam Data_Type The integral type used to hold the data to be transmitted.
 */
template<typename Data_Type>
class Transmitter :
    public ::picolibrary::Asynchronous_Serial::Transmitter<Basic_Transmitter<Data_Type>> {
  public:
    using ::picolibrary::Asynchronous_Serial::Transmitter<Basic_Transmitter<Data_Type>>::Transmitter;
};

} // namespace picolibrary::Microchip::megaAVR0::Asynchronous_Serial

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_H
