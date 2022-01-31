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
 * \brief picolibrary::Testing::Interactive::Microchip::megaAVR0::Log interface.
 */

#ifndef PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_CLOCK_LOG_H
#define PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_CLOCK_LOG_H

#include <cstdint>

#include "picolibrary/error.h"
#include "picolibrary/microchip/megaavr0/multiplexed_signals.h"
#include "picolibrary/microchip/megaavr0/peripheral.h"
#include "picolibrary/microchip/megaavr0/peripheral/usart.h"
#include "picolibrary/precondition.h"
#include "picolibrary/result.h"
#include "picolibrary/stream.h"
#include "picolibrary/void.h"

namespace picolibrary::Testing::Interactive::Microchip::megaAVR0 {

/**
 * \brief Log.
 */
class Log : public Output_Stream {
  public:
    /**
     * \brief USART clock generator operating speed.
     */
    enum class USART_Clock_Generator_Operating_Speed : std::uint8_t {
        NORMAL = 0x0 << ::picolibrary::Microchip::megaAVR0::Peripheral::USART::CTRLB::Bit::RXMODE, ///< Normal.
        DOUBLE = 0x1 << ::picolibrary::Microchip::megaAVR0::Peripheral::USART::CTRLB::Bit::RXMODE, ///< Double.
    };

    /**
     * \brief Check if the log has been initialized.
     *
     * \return true if the log has been initialized.
     * \return false if the log has not been initialized.
     */
    static auto is_initialized() noexcept -> bool
    {
        return USART;
    }

    /**
     * \brief Initialize the log.
     *
     * \pre not picolibrary::Testing::Interactive::Microchip::megaAVR0::Log::is_initialized()
     *
     * \param[in] usart The USART peripheral to be used by the log.
     * \param[in] usart_route The desired USART peripheral routing configuration.
     * \param[in] usart_clock_generator_operating_speed The desired USART peripheral clock
     *            generator operating speed.
     * \param[in] usart_clock_generator_scaling_factor The desired USART peripheral clock
     *            generator scaling factor.
     */
    static void initialize(
        ::picolibrary::Microchip::megaAVR0::Peripheral::USART &              usart,
        ::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::USART_Route usart_route,
        USART_Clock_Generator_Operating_Speed usart_clock_generator_operating_speed,
        std::uint16_t usart_clock_generator_scaling_factor ) noexcept
    {
        // #lizard forgives the length

        expect( not is_initialized(), Generic_Error::LOGIC_ERROR );

        ::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::set_usart_route( usart, usart_route );

        usart.ctrlb = static_cast<std::uint8_t>( usart_clock_generator_operating_speed );
        usart.ctrlc = ::picolibrary::Microchip::megaAVR0::Peripheral::USART::CTRLC::CMODE_ASYNCHRONOUS
                      | ::picolibrary::Microchip::megaAVR0::Peripheral::USART::CTRLC::PMODE_DISABLED
                      | ::picolibrary::Microchip::megaAVR0::Peripheral::USART::CTRLC::CHSIZE_8BIT;
        usart.ctrla = 0;
        usart.baud  = usart_clock_generator_scaling_factor;

        auto & txd_port = ::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::txd_port( usart );
        auto const txd_mask = ::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::txd_mask(
            usart, usart_route );

        txd_port.outset = txd_mask;
        txd_port.dirset = txd_mask;

        usart.ctrlb |= ::picolibrary::Microchip::megaAVR0::Peripheral::USART::CTRLB::Mask::TXEN;

        USART = &usart;
    }

#if defined( PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_LOG_USART )                                    \
    && defined( PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_LOG_USART_ROUTE )                           \
    && defined( PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_LOG_USART_CLOCK_GENERATOR_OPERATING_SPEED ) \
    && defined( PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_LOG_USART_CLOCK_GENERATOR_SCALING_FACTOR )
    /**
     * \brief Initialize the log.
     *
     * \pre not picolibrary::Testing::Interactive::Microchip::megaAVR0::Log::is_initialized()
     */
    static void initialize() noexcept
    {
        initialize(
            ::picolibrary::Microchip::megaAVR0::Peripheral::PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_LOG_USART::instance(),
            ::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::USART_Route::PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_LOG_USART_ROUTE,
            USART_Clock_Generator_Operating_Speed::PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_LOG_USART_CLOCK_GENERATOR_OPERATING_SPEED,
            PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_LOG_USART_CLOCK_GENERATOR_SCALING_FACTOR );
    }
#endif // defined( PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_LOG_USART ) && defined(
       // PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_LOG_USART_ROUTE ) && defined(
       // PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_LOG_USART_CLOCK_GENERATOR_OPERATING_SPEED
       // ) && defined( PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_LOG_USART_CLOCK_GENERATOR_SCALING_FACTOR )

    /**
     * \brief Report a fatal error.
     *
     * \param[in] error The fatal error.
     */
    static void report_fatal_error( Error_Code const & error ) noexcept
    {
        if ( is_initialized() ) {
            transmit( "fatal error: " );
            transmit( error.category().name() );
            transmit( "::" );
            transmit( error.description() );
            transmit( '\n' );
        } // if
    }

    /**
     * \brief Constructor.
     *
     * \pre picolibrary::Testing::Interactive::Microchip::megaAVR0::Log::is_initialized()
     */
    Log() noexcept
    {
        expect( is_initialized(), Generic_Error::LOGIC_ERROR );

        set_buffer( &BUFFER );
    }

    Log( Log && ) = delete;

    Log( Log const & ) = delete;

    /**
     * \brief Destructor.
     */
    ~Log() noexcept = default;

    auto operator=( Log && ) = delete;

    auto operator=( Log const & ) = delete;

  private:
    /**
     * \brief Buffer.
     */
    class Buffer final : public Stream_Buffer {
      public:
        /**
         * \brief Constructor.
         */
        constexpr Buffer() noexcept = default;

        Buffer( Buffer && ) = delete;

        Buffer( Buffer const & ) = delete;

        /**
         * \brief Destructor.
         */
        ~Buffer() noexcept = default;

        auto operator=( Buffer && ) = delete;

        auto operator=( Buffer const & ) = delete;

        /**
         * \brief Write a character to the put area of the buffer.
         *
         * \param[in] character The character to write to the put area of the buffer.
         *
         * \return Nothing.
         */
        virtual auto put( char character ) noexcept -> Result<Void, Error_Code> override final
        {
            transmit( character );

            return {};
        }

        /**
         * \brief Write an unsigned byte to the put area of the buffer.
         *
         * \param[in] value The unsigned byte to write to the put area of the buffer.
         *
         * \return Nothing.
         */
        virtual auto put( std::uint8_t value ) noexcept -> Result<Void, Error_Code> override final
        {
            transmit( value );

            return {};
        }

        /**
         * \brief Write a signed byte to the put area of the buffer.
         *
         * \param[in] value The signed byte to write to the put area of the buffer.
         *
         * \return Nothing.
         */
        virtual auto put( std::int8_t value ) noexcept -> Result<Void, Error_Code> override final
        {
            transmit( value );

            return {};
        }

        /**
         * \brief Write any data that is buffered in the put area of the buffer to the
         *        device.
         *
         * \return Nothing.
         */
        virtual auto flush() noexcept -> Result<Void, Error_Code> override final
        {
            return {};
        }
    };

    /**
     * \brief The USART peripheral used by the log.
     */
    static inline auto USART = static_cast<::picolibrary::Microchip::megaAVR0::Peripheral::USART *>( nullptr );

    /**
     * \brief The buffer.
     */
    static inline auto BUFFER = Buffer{};

    /**
     * \brief Transmit data.
     *
     * \param[in] data The data to transmit.
     */
    static void transmit( std::uint8_t data ) noexcept
    {
        while ( not( USART->status & ::picolibrary::Microchip::megaAVR0::Peripheral::USART::STATUS::Mask::DREIF ) ) {
        } // while

        USART->txdatal = data;
    }

    /**
     * \brief Transmit a null-terminated string.
     *
     * \param[in] string The null-terminated string to transmit.
     */
    static void transmit( char const * string ) noexcept
    {
        while ( auto const character = *string++ ) { transmit( character ); } // while
    }
};

} // namespace picolibrary::Testing::Interactive::Microchip::megaAVR0

#endif // PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_CLOCK_LOG_H
