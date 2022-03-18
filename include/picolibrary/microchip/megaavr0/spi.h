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
 * \brief picolibrary::Microchip::megaAVR0::SPI interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_SPI_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_SPI_H

#include <cstdint>
#include <utility>

#include "picolibrary/microchip/megaavr0/gpio.h"
#include "picolibrary/microchip/megaavr0/multiplexed_signals.h"
#include "picolibrary/microchip/megaavr0/peripheral/port.h"
#include "picolibrary/microchip/megaavr0/peripheral/spi.h"
#include "picolibrary/microchip/megaavr0/peripheral/usart.h"
#include "picolibrary/spi.h"

/**
 * \brief Microchip megaAVR 0-series Serial Peripheral Interface (SPI) facilities.
 */
namespace picolibrary::Microchip::megaAVR0::SPI {

/**
 * \brief SPI clock rate.
 */
enum class SPI_Clock_Rate : std::uint8_t {
    CLK_PER_2 = ( 0b1 << Peripheral::SPI::CTRLA::Bit::CLK2X )
                | Peripheral::SPI::CTRLA::PRESC_DIV4, ///< Peripheral clock frequency / 2.
    CLK_PER_4 = ( 0b0 << Peripheral::SPI::CTRLA::Bit::CLK2X )
                | Peripheral::SPI::CTRLA::PRESC_DIV4, ///< Peripheral clock frequency / 4.
    CLK_PER_8 = ( 0b1 << Peripheral::SPI::CTRLA::Bit::CLK2X )
                | Peripheral::SPI::CTRLA::PRESC_DIV16, ///< Peripheral clock frequency / 8.
    CLK_PER_16 = ( 0b0 << Peripheral::SPI::CTRLA::Bit::CLK2X )
                 | Peripheral::SPI::CTRLA::PRESC_DIV16, ///< Peripheral clock frequency / 16.
    CLK_PER_32 = ( 0b1 << Peripheral::SPI::CTRLA::Bit::CLK2X )
                 | Peripheral::SPI::CTRLA::PRESC_DIV64, ///< Peripheral clock frequency / 32.
    CLK_PER_64 = ( 0b0 << Peripheral::SPI::CTRLA::Bit::CLK2X )
                 | Peripheral::SPI::CTRLA::PRESC_DIV64, ///< Peripheral clock frequency / 64.
    CLK_PER_128 = ( 0b0 << Peripheral::SPI::CTRLA::Bit::CLK2X )
                  | Peripheral::SPI::CTRLA::PRESC_DIV128, ///< Peripheral clock frequency / 128.
};

/**
 * \brief SPI clock polarity.
 */
enum class SPI_Clock_Polarity : std::uint8_t {
    IDLE_LOW  = 0b00 << Peripheral::SPI::CTRLB::Bit::MODE, ///< Idle low.
    IDLE_HIGH = 0b10 << Peripheral::SPI::CTRLB::Bit::MODE, ///< Idle high.
};

/**
 * \brief SPI clock phase.
 */
enum class SPI_Clock_Phase : std::uint8_t {
    CAPTURE_IDLE_TO_ACTIVE = 0b00 << Peripheral::SPI::CTRLB::Bit::MODE, ///< Capture data on the idle-to-active clock transition.
    CAPTURE_ACTIVE_TO_IDLE = 0b01 << Peripheral::SPI::CTRLB::Bit::MODE, ///< Capture data on the active-to-idle clock transition.
};

/**
 * \brief SPI bit order.
 */
enum class SPI_Bit_Order : std::uint8_t {
    MSB_FIRST = 0b0 << Peripheral::SPI::CTRLA::Bit::DORD, ///< MSB first.
    LSB_FIRST = 0b1 << Peripheral::SPI::CTRLA::Bit::DORD, ///< LSB first.
};

/**
 * \brief USART clock polarity.
 */
enum class USART_Clock_Polarity : std::uint8_t {
    IDLE_LOW  = 0b0 << Peripheral::PORT::PINCTRL::Bit::INVEN, ///< Idle low.
    IDLE_HIGH = 0b1 << Peripheral::PORT::PINCTRL::Bit::INVEN, ///< Idle high.
};

/**
 * \brief USART clock phase.
 */
enum class USART_Clock_Phase : std::uint8_t {
    CAPTURE_IDLE_TO_ACTIVE = 0b0 << Peripheral::USART::CTRLC::Bit::UCPHA, ///< Capture data on the idle-to-active clock transition.
    CAPTURE_ACTIVE_TO_IDLE = 0b1 << Peripheral::USART::CTRLC::Bit::UCPHA, ///< Capture data on the active-to-idle clock transition.
};

/**
 * \brief USART bit order.
 */
enum class USART_Bit_Order : std::uint8_t {
    MSB_FIRST = 0b0 << Peripheral::USART::CTRLC::Bit::UDORD, ///< MSB first.
    LSB_FIRST = 0b1 << Peripheral::USART::CTRLC::Bit::UDORD, ///< LSB first.
};

/**
 * \brief Fixed configuration basic controller.
 *
 * \tparam Peripheral The type of peripheral used to implement fixed configuration
 *         controller functionality.
 */
template<typename Peripheral>
class Fixed_Configuration_Basic_Controller;

/**
 * \brief Fixed configuration controller.
 *
 * \tparam Peripheral The type of peripheral used to implement fixed configuration
 *         controller functionality.
 */
template<typename Peripheral>
using Fixed_Configuration_Controller =
    ::picolibrary::SPI::Controller<Fixed_Configuration_Basic_Controller<Peripheral>>;

/**
 * \brief SPI peripheral based fixed configuration basic controller.
 */
template<>
class Fixed_Configuration_Basic_Controller<Peripheral::SPI> {
  public:
    /**
     * \brief Clock (frequency, polarity, and phase) and data exchange bit order
     *        configuration.
     */
    struct Configuration {
    };

    /**
     * \brief Constructor.
     */
    constexpr Fixed_Configuration_Basic_Controller() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] spi The SPI to be used by the controller.
     * \param[in] spi_clock_rate The desired SPI clock rate.
     * \param[in] spi_clock_polarity The desired SPI clock polarity.
     * \param[in] spi_clock_phase The desired SPI clock phase.
     * \param[in] spi_bit_order The desired SPI bit order.
     */
    Fixed_Configuration_Basic_Controller(
        Peripheral::SPI &  spi,
        SPI_Clock_Rate     spi_clock_rate,
        SPI_Clock_Polarity spi_clock_polarity,
        SPI_Clock_Phase    spi_clock_phase,
        SPI_Bit_Order      spi_bit_order ) noexcept :
        m_spi{ &spi },
        m_spi_sck_mosi{ Multiplexed_Signals::spi_port( spi ),
                        static_cast<std::uint8_t>(
                            Multiplexed_Signals::sck_mask( spi ) | Multiplexed_Signals::mosi_mask( spi ) ) }
    {
        configure_controller( spi_clock_rate, spi_clock_polarity, spi_clock_phase, spi_bit_order );
    }

    /**
     * \brief Constructor.
     *
     * \param[in] spi The SPI to be used by the controller.
     * \param[in] spi_clock_rate The desired SPI clock rate.
     * \param[in] spi_clock_polarity The desired SPI clock polarity.
     * \param[in] spi_clock_phase The desired SPI clock phase.
     * \param[in] spi_bit_order The desired SPI bit order.
     * \param[in] spi_route The SPI's routing configuration.
     */
    Fixed_Configuration_Basic_Controller(
        Peripheral::SPI &              spi,
        SPI_Clock_Rate                 spi_clock_rate,
        SPI_Clock_Polarity             spi_clock_polarity,
        SPI_Clock_Phase                spi_clock_phase,
        SPI_Bit_Order                  spi_bit_order,
        Multiplexed_Signals::SPI_Route spi_route ) noexcept :
        m_spi{ &spi },
        m_spi_sck_mosi{ Multiplexed_Signals::spi_port( spi, spi_route ),
                        static_cast<std::uint8_t>(
                            Multiplexed_Signals::sck_mask( spi, spi_route )
                            | Multiplexed_Signals::mosi_mask( spi, spi_route ) ) }
    {
        configure_controller( spi_clock_rate, spi_clock_polarity, spi_clock_phase, spi_bit_order );
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Fixed_Configuration_Basic_Controller( Fixed_Configuration_Basic_Controller && source ) noexcept :
        m_spi{ source.m_spi },
        m_spi_sck_mosi{ std::move( source.m_spi_sck_mosi ) }
    {
        source.m_spi = nullptr;
    }

    Fixed_Configuration_Basic_Controller( Fixed_Configuration_Basic_Controller const & ) = delete;

    /**
     * \brief Destructor.
     */
    ~Fixed_Configuration_Basic_Controller() noexcept
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
    constexpr auto & operator=( Fixed_Configuration_Basic_Controller && expression ) noexcept
    {
        if ( &expression != this ) {
            disable();

            m_spi          = expression.m_spi;
            m_spi_sck_mosi = std::move( expression.m_spi_sck_mosi );

            expression.m_spi = nullptr;
        } // if

        return *this;
    }

    auto operator=( Fixed_Configuration_Basic_Controller const & ) = delete;

    /**
     * \brief Initialize the controller's hardware.
     */
    void initialize() noexcept
    {
        m_spi_sck_mosi.initialize();

        enable_controller();
    }

    /**
     * \brief Configure the controller's clock and data exchange bit order to meet a
     *        specific device's communication requirements.
     *
     * \param[in] configuration The clock and data exchange bit order configuration that
     *            meets the device's communication requirements.
     */
    void configure( Configuration configuration ) noexcept
    {
        static_cast<void>( configuration );
    }

    /**
     * \brief Exchange data with a device.
     *
     * \param[in] data The data to transmit to the device.
     *
     * \return The data received from the device.
     */
    auto exchange( std::uint8_t data ) noexcept
    {
        initiate_exchange( data );

        while ( not exchange_complete() ) {} // while

        return finish_exchange();
    }

  private:
    /**
     * \brief The SPI used by the controller.
     */
    Peripheral::SPI * m_spi{};

    /**
     * \brief The SPI's SCK and MOSI pins.
     */
    GPIO::Push_Pull_IO_Pin<Peripheral::PORT> m_spi_sck_mosi{};

    /**
     * \brief Disable the controller.
     */
    constexpr void disable() noexcept
    {
        if ( m_spi ) {
            disable_controller();
        } // if
    }

    /**
     * \brief Configure the controller.
     *
     * \param[in] spi_clock_rate The desired SPI clock rate.
     * \param[in] spi_clock_polarity The desired SPI clock polarity.
     * \param[in] spi_clock_phase The desired SPI clock phase.
     * \param[in] spi_bit_order The desired SPI bit order.
     */
    void configure_controller(
        SPI_Clock_Rate     spi_clock_rate,
        SPI_Clock_Polarity spi_clock_polarity,
        SPI_Clock_Phase    spi_clock_phase,
        SPI_Bit_Order      spi_bit_order ) noexcept
    {
        m_spi->ctrla = Peripheral::SPI::CTRLA::Mask::MASTER
                       | static_cast<std::uint8_t>( spi_clock_rate )
                       | static_cast<std::uint8_t>( spi_bit_order );
        m_spi->ctrlb = Peripheral::SPI::CTRLB::Mask::SSD
                       | static_cast<std::uint8_t>( spi_clock_polarity )
                       | static_cast<std::uint8_t>( spi_clock_phase );
        m_spi->intctrl = 0;
    }

    /**
     * \brief Disable the controller.
     */
    void disable_controller() noexcept
    {
        m_spi->ctrla = 0;
    }

    /**
     * \brief Enable the controller.
     */
    void enable_controller() noexcept
    {
        m_spi->ctrla |= Peripheral::SPI::CTRLA::Mask::ENABLE;
    }

    /**
     * \brief Initiate a data exchange.
     *
     * \param[in] data The data to transmit.
     */
    void initiate_exchange( std::uint8_t data ) noexcept
    {
        m_spi->data = data;
    }

    /**
     * \brief Check if a data exchange is complete.
     *
     * \return true if the data exchange is complete.
     * \return false if the data exchange is not complete.
     */
    auto exchange_complete() const noexcept -> bool
    {
        return m_spi->intflags & Peripheral::SPI::INTFLAGS::Mask::IF;
    }

    /**
     * \brief Finish a data exchange.
     *
     * \return The received data.
     */
    auto finish_exchange() noexcept -> std::uint8_t
    {
        return m_spi->data;
    }
};

} // namespace picolibrary::Microchip::megaAVR0::SPI

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_SPI_H
