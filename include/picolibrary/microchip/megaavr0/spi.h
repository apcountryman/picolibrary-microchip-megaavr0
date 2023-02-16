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
#include "picolibrary/utility.h"

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
        // #lizard forgives the parameter count

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
    constexpr auto operator=( Fixed_Configuration_Basic_Controller && expression ) noexcept
        -> Fixed_Configuration_Basic_Controller &
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
    auto exchange( std::uint8_t data ) noexcept -> std::uint8_t
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
                       | to_underlying( spi_clock_rate ) | to_underlying( spi_bit_order );
        m_spi->ctrlb = Peripheral::SPI::CTRLB::Mask::SSD | to_underlying( spi_clock_polarity )
                       | to_underlying( spi_clock_phase );
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

/**
 * \brief USART peripheral based fixed configuration basic controller.
 */
template<>
class Fixed_Configuration_Basic_Controller<Peripheral::USART> {
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
     * \param[in] usart The USART to be used by the controller.
     * \param[in] usart_clock_generator_scaling_factor The desired USART clock generator
     *            scaling factor (BAUD register value).
     * \param[in] usart_clock_polarity The desired USART clock polarity.
     * \param[in] usart_clock_phase The desired USART clock phase.
     * \param[in] usart_bit_order The desired USART bit order.
     */
    Fixed_Configuration_Basic_Controller(
        Peripheral::USART &  usart,
        std::uint16_t        usart_clock_generator_scaling_factor,
        USART_Clock_Polarity usart_clock_polarity,
        USART_Clock_Phase    usart_clock_phase,
        USART_Bit_Order      usart_bit_order ) noexcept :
        m_usart{ &usart },
        m_usart_xck_txd_port{ &Multiplexed_Signals::usart_port( usart ) },
        m_usart_xck_txd_mask{ static_cast<std::uint8_t>(
            Multiplexed_Signals::xck_mask( usart ) | Multiplexed_Signals::txd_mask( usart ) ) },
        m_usart_xck_number{ Multiplexed_Signals::xck_number( usart ) }
    {
        configure_controller(
            usart_clock_generator_scaling_factor, usart_clock_polarity, usart_clock_phase, usart_bit_order );
    }

    /**
     * \brief Constructor.
     *
     * \param[in] usart The USART to be used by the controller.
     * \param[in] usart_clock_generator_scaling_factor The desired USART clock generator
     *            scaling factor (BAUD register value).
     * \param[in] usart_clock_polarity The desired USART clock polarity.
     * \param[in] usart_clock_phase The desired USART clock phase.
     * \param[in] usart_bit_order The desired USART bit order.
     * \param[in] usart_route The USART's routing configuration.
     */
    Fixed_Configuration_Basic_Controller(
        Peripheral::USART &              usart,
        std::uint16_t                    usart_clock_generator_scaling_factor,
        USART_Clock_Polarity             usart_clock_polarity,
        USART_Clock_Phase                usart_clock_phase,
        USART_Bit_Order                  usart_bit_order,
        Multiplexed_Signals::USART_Route usart_route ) noexcept :
        m_usart{ &usart },
        m_usart_xck_txd_port{ &Multiplexed_Signals::usart_port( usart, usart_route ) },
        m_usart_xck_txd_mask{ static_cast<std::uint8_t>(
            Multiplexed_Signals::xck_mask( usart, usart_route )
            | Multiplexed_Signals::txd_mask( usart, usart_route ) ) },
        m_usart_xck_number{ Multiplexed_Signals::xck_number( usart, usart_route ) }
    {
        // #lizard forgives the parameter count

        configure_controller(
            usart_clock_generator_scaling_factor, usart_clock_polarity, usart_clock_phase, usart_bit_order );
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Fixed_Configuration_Basic_Controller( Fixed_Configuration_Basic_Controller && source ) noexcept :
        m_usart{ source.m_usart },
        m_usart_xck_txd_port{ source.m_usart_xck_txd_port },
        m_usart_xck_txd_mask{ source.m_usart_xck_txd_mask },
        m_usart_xck_number{ source.m_usart_xck_number }
    {
        source.m_usart              = nullptr;
        source.m_usart_xck_txd_port = nullptr;
        source.m_usart_xck_txd_mask = 0;
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
    constexpr auto operator=( Fixed_Configuration_Basic_Controller && expression ) noexcept
        -> Fixed_Configuration_Basic_Controller &
    {
        if ( &expression != this ) {
            disable();

            m_usart              = expression.m_usart;
            m_usart_xck_txd_port = expression.m_usart_xck_txd_port;
            m_usart_xck_txd_mask = expression.m_usart_xck_txd_mask;
            m_usart_xck_number   = expression.m_usart_xck_number;

            expression.m_usart              = nullptr;
            expression.m_usart_xck_txd_port = nullptr;
            expression.m_usart_xck_txd_mask = 0;
        } // if

        return *this;
    }

    auto operator=( Fixed_Configuration_Basic_Controller const & ) = delete;

    /**
     * \brief Initialize the controller's hardware.
     */
    void initialize() noexcept
    {
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
    auto exchange( std::uint8_t data ) noexcept -> std::uint8_t
    {
        while ( not transmit_buffer_is_empty() ) {} // while

        load_transmit_buffer( data );

        while ( not received_data_is_available() ) {} // while

        return read_receive_buffer();
    }

  private:
    /**
     * \brief The USART used by the controller.
     */
    Peripheral::USART * m_usart{};

    /**
     * \brief The USART's XCK and TXD pins PORT.
     */
    Peripheral::PORT * m_usart_xck_txd_port{};

    /**
     * \brief The USART's XCK and TXD pins mask.
     */
    std::uint8_t m_usart_xck_txd_mask{};

    /**
     * \brief The USART's XCK pin number.
     */
    std::uint_fast8_t m_usart_xck_number{};

    /**
     * \brief Disable the controller.
     */
    constexpr void disable() noexcept
    {
        if ( m_usart ) {
            disable_controller();
        } // if
    }

    /**
     * \brief Configure the controller.
     *
     * \param[in] usart_clock_generator_scaling_factor The desired USART clock generator
     *            scaling factor (BAUD register value).
     * \param[in] usart_clock_polarity The desired USART clock polarity.
     * \param[in] usart_clock_phase The desired USART clock phase.
     * \param[in] usart_bit_order The desired USART bit order.
     */
    void configure_controller(
        std::uint16_t        usart_clock_generator_scaling_factor,
        USART_Clock_Polarity usart_clock_polarity,
        USART_Clock_Phase    usart_clock_phase,
        USART_Bit_Order      usart_bit_order ) noexcept
    {
        m_usart->ctrlb = 0;
        m_usart->ctrla = 0;
        m_usart->ctrlc = Peripheral::USART::CTRLC::CMODE_MSPI | to_underlying( usart_clock_phase )
                         | to_underlying( usart_bit_order );
        m_usart->baud = usart_clock_generator_scaling_factor;

        m_usart_xck_txd_port->pinctrl[ m_usart_xck_number ] =
            ( m_usart_xck_txd_port->pinctrl[ m_usart_xck_number ]
              & ~Peripheral::PORT::PINCTRL::Mask::INVEN )
            | to_underlying( usart_clock_polarity );
    }

    /**
     * \brief Disable the controller.
     */
    void disable_controller() noexcept
    {
        m_usart->ctrlb = 0;

        // Silicon errata workaround ("TXD Pin Override Not Released When Disabling the
        // Transmitter")
        m_usart->status = 0;

        m_usart_xck_txd_port->dirclr = m_usart_xck_txd_mask;
        m_usart_xck_txd_port->pinctrl[ m_usart_xck_number ] &= static_cast<std::uint8_t>(
            ~Peripheral::PORT::PINCTRL::Mask::INVEN );
    }

    /**
     * \brief Enable the controller.
     */
    void enable_controller() noexcept
    {
        m_usart_xck_txd_port->dirset = m_usart_xck_txd_mask;

        m_usart->ctrlb = Peripheral::USART::CTRLB::Mask::TXEN | Peripheral::USART::CTRLB::Mask::RXEN;
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
     * \brief Check if received data is available.
     *
     * \return true if received data is available.
     * \return false if received data is not available.
     */
    auto received_data_is_available() const noexcept -> bool
    {
        return m_usart->status & Peripheral::USART::STATUS::Mask::RXCIF;
    }

    /**
     * \brief Read data from the receive buffer.
     *
     * \return The data read from the receive buffer.
     */
    auto read_receive_buffer() noexcept -> std::uint8_t
    {
        return m_usart->rxdatal;
    }
};

/**
 * \brief Variable configuration basic controller.
 *
 * \tparam Peripheral The type of peripheral used to implement variable configuration
 *         controller functionality.
 */
template<typename Peripheral>
class Variable_Configuration_Basic_Controller;

/**
 * \brief Variable configuration controller.
 *
 * \tparam Peripheral The type of peripheral used to implement variable configuration
 *         controller functionality.
 */
template<typename Peripheral>
using Variable_Configuration_Controller =
    ::picolibrary::SPI::Controller<Variable_Configuration_Basic_Controller<Peripheral>>;

/**
 * \brief SPI peripheral based variable configuration basic controller.
 */
template<>
class Variable_Configuration_Basic_Controller<Peripheral::SPI> {
  public:
    /**
     * \brief Clock (frequency, polarity, and phase) and data exchange bit order
     *        configuration.
     */
    class Configuration {
      public:
        /**
         * \brief Constructor.
         */
        constexpr Configuration() noexcept :
            Configuration{ SPI_Clock_Rate::CLK_PER_2,
                           SPI_Clock_Polarity::IDLE_LOW,
                           SPI_Clock_Phase::CAPTURE_IDLE_TO_ACTIVE,
                           SPI_Bit_Order::MSB_FIRST }
        {
        }

        /**
         * \brief Constructor.
         *
         * \param[in] spi_clock_rate The desired SPI clock rate.
         * \param[in] spi_clock_polarity The desired SPI clock polarity.
         * \param[in] spi_clock_phase The desired SPI clock phase.
         * \param[in] spi_bit_order The desired SPI bit order.
         */
        constexpr Configuration(
            SPI_Clock_Rate     spi_clock_rate,
            SPI_Clock_Polarity spi_clock_polarity,
            SPI_Clock_Phase    spi_clock_phase,
            SPI_Bit_Order      spi_bit_order ) noexcept :
            m_ctrla{ static_cast<std::uint8_t>(
                Peripheral::SPI::CTRLA::Mask::MASTER | Peripheral::SPI::CTRLA::Mask::ENABLE
                | to_underlying( spi_clock_rate ) | to_underlying( spi_bit_order ) ) },
            m_ctrlb{ static_cast<std::uint8_t>(
                Peripheral::SPI::CTRLB::Mask::SSD | to_underlying( spi_clock_polarity )
                | to_underlying( spi_clock_phase ) ) }
        {
        }

        /**
         * \brief Constructor.
         *
         * \param[in] source The source of the move.
         */
        constexpr Configuration( Configuration && source ) noexcept = default;

        /**
         * \brief Constructor.
         *
         * \param[in] original The original to copy.
         */
        constexpr Configuration( Configuration const & original ) noexcept = default;

        /**
         * \brief Destructor.
         */
        ~Configuration() noexcept = default;

        /**
         * \brief Assignment operator.
         *
         * \param[in] expression The expression to be assigned.
         *
         * \return The assigned to object.
         */
        constexpr auto operator=( Configuration && expression ) noexcept -> Configuration & = default;

        /**
         * \brief Assignment operator.
         *
         * \param[in] expression The expression to be assigned.
         *
         * \return The assigned to object.
         */
        constexpr auto operator=( Configuration const & expression ) noexcept
            -> Configuration & = default;

        /**
         * \brief Get the configuration's CTRLA register value.
         *
         * \return The configuration's CTRLA register value.
         */
        constexpr auto ctrla() const noexcept -> std::uint8_t
        {
            return m_ctrla;
        }

        /**
         * \brief Get the configuration's CTRLB register value.
         *
         * \return The configuration's CTRLB register value.
         */
        constexpr auto ctrlb() const noexcept -> std::uint8_t
        {
            return m_ctrlb;
        }

      private:
        /**
         * \brief The configuration's CTRLA register value.
         */
        std::uint8_t m_ctrla{};

        /**
         * \brief The configuration's CTRLB register value.
         */
        std::uint8_t m_ctrlb{};
    };

    /**
     * \brief Constructor.
     */
    constexpr Variable_Configuration_Basic_Controller() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] spi The SPI to be used by the controller.
     */
    Variable_Configuration_Basic_Controller( Peripheral::SPI & spi ) noexcept :
        m_spi{ &spi },
        m_spi_sck_mosi{ Multiplexed_Signals::spi_port( spi ),
                        static_cast<std::uint8_t>(
                            Multiplexed_Signals::sck_mask( spi ) | Multiplexed_Signals::mosi_mask( spi ) ) }
    {
    }

    /**
     * \brief Constructor.
     *
     * \param[in] spi The SPI to be used by the controller.
     * \param[in] spi_route The SPI's routing configuration.
     */
    Variable_Configuration_Basic_Controller( Peripheral::SPI & spi, Multiplexed_Signals::SPI_Route spi_route ) noexcept
        :
        m_spi{ &spi },
        m_spi_sck_mosi{ Multiplexed_Signals::spi_port( spi, spi_route ),
                        static_cast<std::uint8_t>(
                            Multiplexed_Signals::sck_mask( spi, spi_route )
                            | Multiplexed_Signals::mosi_mask( spi, spi_route ) ) }
    {
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Variable_Configuration_Basic_Controller( Variable_Configuration_Basic_Controller && source ) noexcept
        :
        m_spi{ source.m_spi },
        m_spi_sck_mosi{ std::move( source.m_spi_sck_mosi ) }
    {
        source.m_spi = nullptr;
    }

    Variable_Configuration_Basic_Controller( Variable_Configuration_Basic_Controller const & ) = delete;

    /**
     * \brief Destructor.
     */
    ~Variable_Configuration_Basic_Controller() noexcept
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
    constexpr auto operator=( Variable_Configuration_Basic_Controller && expression ) noexcept
        -> Variable_Configuration_Basic_Controller &
    {
        if ( &expression != this ) {
            disable();

            m_spi          = expression.m_spi;
            m_spi_sck_mosi = std::move( expression.m_spi_sck_mosi );

            expression.m_spi = nullptr;
        } // if

        return *this;
    }

    auto operator=( Variable_Configuration_Basic_Controller const & ) = delete;

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
        configure_controller( configuration.ctrla(), configuration.ctrlb() );
    }

    /**
     * \brief Exchange data with a device.
     *
     * \param[in] data The data to transmit to the device.
     *
     * \return The data received from the device.
     */
    auto exchange( std::uint8_t data ) noexcept -> std::uint8_t
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
        m_spi->ctrlb   = Peripheral::SPI::CTRLB::Mask::SSD;
        m_spi->intctrl = 0;
        m_spi->ctrla = Peripheral::SPI::CTRLA::Mask::MASTER | Peripheral::SPI::CTRLA::Mask::ENABLE;
    }

    /**
     * \brief Configure the controller.
     *
     * \param[in] ctrla The desired CTRLA register value.
     * \param[in] ctrlb The desired CTRLB register value.
     */
    void configure_controller( std::uint8_t ctrla, std::uint8_t ctrlb ) noexcept
    {
        m_spi->ctrla = ctrla;
        m_spi->ctrlb = ctrlb;
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

/**
 * \brief USART peripheral based fixed configuration basic controller.
 */
template<>
class Variable_Configuration_Basic_Controller<Peripheral::USART> {
  public:
    /**
     * \brief Clock (frequency, polarity, and phase) and data exchange bit order
     *        configuration.
     */
    class Configuration {
      public:
        /**
         * \brief Constructor.
         */
        constexpr Configuration() noexcept :
            Configuration{ 64,
                           USART_Clock_Polarity::IDLE_LOW,
                           USART_Clock_Phase::CAPTURE_IDLE_TO_ACTIVE,
                           USART_Bit_Order::MSB_FIRST }
        {
        }

        /**
         * \brief Constructor.
         *
         * \param[in] usart_clock_generator_scaling_factor The desired USART clock
         *            generator scaling factor (BAUD register value).
         * \param[in] usart_clock_polarity The desired USART clock polarity.
         * \param[in] usart_clock_phase The desired USART clock phase.
         * \param[in] usart_bit_order The desired USART bit order.
         */
        constexpr Configuration(
            std::uint16_t        usart_clock_generator_scaling_factor,
            USART_Clock_Polarity usart_clock_polarity,
            USART_Clock_Phase    usart_clock_phase,
            USART_Bit_Order      usart_bit_order ) noexcept :
            m_port_pinctrl_inven{ to_underlying( usart_clock_polarity ) },
            m_usart_ctrlc{ static_cast<std::uint8_t>(
                Peripheral::USART::CTRLC::CMODE_MSPI | to_underlying( usart_clock_phase )
                | to_underlying( usart_bit_order ) ) },
            m_usart_baud{ usart_clock_generator_scaling_factor }
        {
        }

        /**
         * \brief Constructor.
         *
         * \param[in] source The source of the move.
         */
        constexpr Configuration( Configuration && source ) noexcept = default;

        /**
         * \brief Constructor.
         *
         * \param[in] original The original to copy.
         */
        constexpr Configuration( Configuration const & original ) noexcept = default;

        /**
         * \brief Destructor.
         */
        ~Configuration() noexcept = default;

        /**
         * \brief Assignment operator.
         *
         * \param[in] expression The expression to be assigned.
         *
         * \return The assigned to object.
         */
        constexpr auto operator=( Configuration && expression ) noexcept -> Configuration & = default;

        /**
         * \brief Assignment operator.
         *
         * \param[in] expression The expression to be assigned.
         *
         * \return The assigned to object.
         */
        constexpr auto operator=( Configuration const & expression ) noexcept
            -> Configuration & = default;

        /**
         * \brief Get the configuration's PORT.PINCTRL register INVEN field value.
         *
         * \return The configuration's PORT.PINCTRL register INVEN field value.
         */
        constexpr auto port_pinctrl_inven() const noexcept -> std::uint8_t
        {
            return m_port_pinctrl_inven;
        }

        /**
         * \brief Get the configuration's USART.CTRLC register value.
         *
         * \return The configuration's USART.CTRLC register value.
         */
        constexpr auto usart_ctrlc() const noexcept -> std::uint8_t
        {
            return m_usart_ctrlc;
        }

        /**
         * \brief Get the configuration's USART.BAUD register value.
         *
         * \return The configuration's USART.BAUD register value.
         */
        constexpr auto usart_baud() const noexcept -> std::uint16_t
        {
            return m_usart_baud;
        }

      private:
        /**
         * \brief The configuration's PORT.PINCTRL register INVEN field value.
         */
        std::uint8_t m_port_pinctrl_inven{};

        /**
         * \brief The configuration's USART.CTRLC register value.
         */
        std::uint8_t m_usart_ctrlc{};

        /**
         * \brief The configuration's USART.BAUD register value.
         */
        std::uint16_t m_usart_baud{};
    };

    /**
     * \brief Constructor.
     */
    constexpr Variable_Configuration_Basic_Controller() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] usart The USART to be used by the controller.
     */
    Variable_Configuration_Basic_Controller( Peripheral::USART & usart ) noexcept :
        m_usart{ &usart },
        m_usart_xck_txd_port{ &Multiplexed_Signals::usart_port( usart ) },
        m_usart_xck_txd_mask{ static_cast<std::uint8_t>(
            Multiplexed_Signals::xck_mask( usart ) | Multiplexed_Signals::txd_mask( usart ) ) },
        m_usart_xck_number{ Multiplexed_Signals::xck_number( usart ) }
    {
    }

    /**
     * \brief Constructor.
     *
     * \param[in] usart The USART to be used by the controller.
     * \param[in] usart_route The USART's routing configuration.
     */
    Variable_Configuration_Basic_Controller( Peripheral::USART & usart, Multiplexed_Signals::USART_Route usart_route ) noexcept
        :
        m_usart{ &usart },
        m_usart_xck_txd_port{ &Multiplexed_Signals::usart_port( usart, usart_route ) },
        m_usart_xck_txd_mask{ static_cast<std::uint8_t>(
            Multiplexed_Signals::xck_mask( usart, usart_route )
            | Multiplexed_Signals::txd_mask( usart, usart_route ) ) },
        m_usart_xck_number{ Multiplexed_Signals::xck_number( usart, usart_route ) }
    {
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Variable_Configuration_Basic_Controller( Variable_Configuration_Basic_Controller && source ) noexcept
        :
        m_usart{ source.m_usart },
        m_usart_xck_txd_port{ source.m_usart_xck_txd_port },
        m_usart_xck_txd_mask{ source.m_usart_xck_txd_mask },
        m_usart_xck_number{ source.m_usart_xck_number }
    {
        source.m_usart              = nullptr;
        source.m_usart_xck_txd_port = nullptr;
        source.m_usart_xck_txd_mask = 0;
    }

    Variable_Configuration_Basic_Controller( Variable_Configuration_Basic_Controller const & ) = delete;

    /**
     * \brief Destructor.
     */
    ~Variable_Configuration_Basic_Controller() noexcept
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
    constexpr auto operator=( Variable_Configuration_Basic_Controller && expression ) noexcept
        -> Variable_Configuration_Basic_Controller &
    {
        if ( &expression != this ) {
            disable();

            m_usart              = expression.m_usart;
            m_usart_xck_txd_port = expression.m_usart_xck_txd_port;
            m_usart_xck_txd_mask = expression.m_usart_xck_txd_mask;
            m_usart_xck_number   = expression.m_usart_xck_number;

            expression.m_usart              = nullptr;
            expression.m_usart_xck_txd_port = nullptr;
            expression.m_usart_xck_txd_mask = 0;
        } // if

        return *this;
    }

    auto operator=( Variable_Configuration_Basic_Controller const & ) = delete;

    /**
     * \brief Initialize the controller's hardware.
     */
    void initialize() noexcept
    {
        enable_controller();
    }

    /**
     * \brief Configure the controller's clock and data exchange bit order to meet a
     *        specific device's communication requirements.
     *
     * \param[in] configuration The clock and data exchange bit order configuration that
     *            meets the device's communication requirements.
     */
    void configure( Configuration const & configuration ) noexcept
    {
        configure_controller(
            configuration.port_pinctrl_inven(), configuration.usart_ctrlc(), configuration.usart_baud() );
    }

    /**
     * \brief Exchange data with a device.
     *
     * \param[in] data The data to transmit to the device.
     *
     * \return The data received from the device.
     */
    auto exchange( std::uint8_t data ) noexcept -> std::uint8_t
    {
        while ( not transmit_buffer_is_empty() ) {} // while

        load_transmit_buffer( data );

        while ( not received_data_is_available() ) {} // while

        return read_receive_buffer();
    }

  private:
    /**
     * \brief The USART used by the controller.
     */
    Peripheral::USART * m_usart{};

    /**
     * \brief The USART's XCK and TXD pins PORT.
     */
    Peripheral::PORT * m_usart_xck_txd_port{};

    /**
     * \brief The USART's XCK and TXD pins mask.
     */
    std::uint8_t m_usart_xck_txd_mask{};

    /**
     * \brief The USART's XCK pin number.
     */
    std::uint_fast8_t m_usart_xck_number{};

    /**
     * \brief Disable the controller.
     */
    constexpr void disable() noexcept
    {
        if ( m_usart ) {
            disable_controller();
        } // if
    }

    /**
     * \brief Disable the controller.
     */
    void disable_controller() noexcept
    {
        m_usart->ctrlb = 0;

        // Silicon errata workaround ("TXD Pin Override Not Released When Disabling the
        // Transmitter")
        m_usart->status = 0;

        m_usart_xck_txd_port->dirclr = m_usart_xck_txd_mask;
        m_usart_xck_txd_port->pinctrl[ m_usart_xck_number ] &= static_cast<std::uint8_t>(
            ~Peripheral::PORT::PINCTRL::Mask::INVEN );
    }

    /**
     * \brief Enable the controller.
     */
    void enable_controller() noexcept
    {
        m_usart_xck_txd_port->dirset = m_usart_xck_txd_mask;

        m_usart->ctrla = 0;
        m_usart->ctrlc = Peripheral::USART::CTRLC::CMODE_MSPI;
        m_usart->baud  = 64;
        m_usart->ctrlb = Peripheral::USART::CTRLB::Mask::TXEN | Peripheral::USART::CTRLB::Mask::RXEN;
    }

    /**
     * \brief Configure the controller.
     *
     * \param[in] port_pinctrl_inven The desired PORT.PINCTRL register INVEN field value.
     * \param[in] usart_ctrlc The desired USART.CTRLC register value.
     * \param[in] usart_baud The desired USART.BAUD register value.
     */
    void configure_controller( std::uint8_t port_pinctrl_inven, std::uint8_t usart_ctrlc, std::uint16_t usart_baud ) noexcept
    {
        m_usart_xck_txd_port->pinctrl[ m_usart_xck_number ] = ( m_usart_xck_txd_port->pinctrl[ m_usart_xck_number ]
                                                                & ~Peripheral::PORT::PINCTRL::Mask::INVEN )
                                                              | port_pinctrl_inven;

        m_usart->ctrlc = usart_ctrlc;
        m_usart->baud  = usart_baud;
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
     * \brief Check if received data is available.
     *
     * \return true if received data is available.
     * \return false if received data is not available.
     */
    auto received_data_is_available() const noexcept -> bool
    {
        return m_usart->status & Peripheral::USART::STATUS::Mask::RXCIF;
    }

    /**
     * \brief Read data from the receive buffer.
     *
     * \return The data read from the receive buffer.
     */
    auto read_receive_buffer() noexcept -> std::uint8_t
    {
        return m_usart->rxdatal;
    }
};

} // namespace picolibrary::Microchip::megaAVR0::SPI

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_SPI_H
