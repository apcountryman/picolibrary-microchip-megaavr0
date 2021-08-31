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
 * \brief picolibrary::Microchip::megaAVR0::Multiplexed_Signals::USART interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_MULTIPLEXED_SIGNALS_USART_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_MULTIPLEXED_SIGNALS_USART_H

#include <cstdint>

#include "picolibrary/fatal_error.h"
#include "picolibrary/microchip/megaavr0/peripheral.h"
#include "picolibrary/microchip/megaavr0/peripheral/port.h"
#include "picolibrary/microchip/megaavr0/peripheral/portmux.h"
#include "picolibrary/microchip/megaavr0/peripheral/usart.h"
#include "picolibrary/microchip/megaavr0/peripheral/vport.h"

namespace picolibrary::Microchip::megaAVR0::Multiplexed_Signals {

/**
 * \brief USART routing configuration.
 */
using USART_Route = Peripheral::PORTMUX::USART_Route;

/**
 * \brief Set a USART peripheral's routing configuration.
 *
 * \param[in] usart The USART peripheral whose routing configuration will be set.
 * \param[in] route The desired USART peripheral routing configuration.
 */
inline void set_usart_route( Peripheral::USART const & usart, USART_Route route ) noexcept
{
    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::USART0::ADDRESS:
            Peripheral::PORTMUX0::instance().set_usart0_route( route );
            return;
        case Peripheral::USART1::ADDRESS:
            Peripheral::PORTMUX0::instance().set_usart1_route( route );
            return;
        case Peripheral::USART2::ADDRESS:
            Peripheral::PORTMUX0::instance().set_usart2_route( route );
            return;
#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
        case Peripheral::USART3::ADDRESS:
            Peripheral::PORTMUX0::instance().set_usart3_route( route );
            return;
#endif // defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
    }  // switch

    trap_fatal_error();
}

/**
 * \brief Lookup a USART peripheral's pins port.
 *
 * \param[in] usart The USART peripheral whose pins port is to be looked up.
 *
 * \return The USART peripheral's pins port.
 */
inline auto usart_port( Peripheral::USART const & usart ) noexcept -> Peripheral::PORT &
{
    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::USART0::ADDRESS: return Peripheral::PORTA::instance();
        case Peripheral::USART1::ADDRESS: return Peripheral::PORTC::instance();
        case Peripheral::USART2::ADDRESS: return Peripheral::PORTF::instance();
#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
        case Peripheral::USART3::ADDRESS: return Peripheral::PORTB::instance();
#endif // defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
    }  // switch

    trap_fatal_error();
}

/**
 * \brief Lookup a USART peripheral's pins virtual port.
 *
 * \param[in] usart The USART peripheral whose pins virtual port is to be looked up.
 *
 * \return The USART peripheral's pins virtual port.
 */
inline auto usart_vport( Peripheral::USART const & usart ) noexcept -> Peripheral::VPORT &
{
    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::USART0::ADDRESS: return Peripheral::VPORTA::instance();
        case Peripheral::USART1::ADDRESS: return Peripheral::VPORTC::instance();
        case Peripheral::USART2::ADDRESS: return Peripheral::VPORTF::instance();
#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
        case Peripheral::USART3::ADDRESS: return Peripheral::VPORTB::instance();
#endif // defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
    }  // switch

    trap_fatal_error();
}

/**
 * \brief Lookup a USART peripheral's XCK pin port.
 *
 * \param[in] usart The USART peripheral whose XCK pin port is to be looked up.
 *
 * \return The USART peripheral's XCK pin port.
 */
inline auto & xck_port( Peripheral::USART const & usart ) noexcept
{
    return usart_port( usart );
}

/**
 * \brief Lookup a USART peripheral's XCK pin virtual port.
 *
 * \param[in] usart The USART peripheral whose XCK pin virtual port is to be looked up.
 *
 * \return The USART peripheral's XCK pin virtual port.
 */
inline auto & xck_vport( Peripheral::USART const & usart ) noexcept
{
    return usart_vport( usart );
}

/**
 * \brief Lookup a USART peripheral's XCK pin number.
 *
 * \param[in] usart The USART peripheral whose XCK pin number is to be looked up.
 *
 * \return The USART peripheral's XCK pin number.
 */
inline auto xck_number( Peripheral::USART const & usart ) noexcept -> std::uint_fast8_t
{
    // #lizard forgives the length

    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::USART0::ADDRESS:
            switch ( Peripheral::PORTMUX0::instance().usart0_route() ) {
                case USART_Route::DEFAULT: return 2;
                case USART_Route::ALTERNATE: return 6;
                case USART_Route::NONE: break;
            } // switch
            break;
        case Peripheral::USART1::ADDRESS:
            switch ( Peripheral::PORTMUX0::instance().usart1_route() ) {
                case USART_Route::DEFAULT: return 2;
                case USART_Route::ALTERNATE: return 6;
                case USART_Route::NONE: break;
            } // switch
            break;
        case Peripheral::USART2::ADDRESS:
            switch ( Peripheral::PORTMUX0::instance().usart2_route() ) {
                case USART_Route::DEFAULT: return 2;
                case USART_Route::ALTERNATE: return 6;
                case USART_Route::NONE: break;
            } // switch
            break;
#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
        case Peripheral::USART3::ADDRESS:
            switch ( Peripheral::PORTMUX0::instance().usart3_route() ) {
                case USART_Route::DEFAULT: return 2;
                case USART_Route::ALTERNATE: return 2;
                case USART_Route::NONE: break;
            } // switch
            break;
#endif // defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
    }  // switch

    trap_fatal_error();
}

/**
 * \brief Lookup a USART peripheral's XCK pin mask.
 *
 * \param[in] usart The USART peripheral whose XCK pin mask is to be looked up.
 *
 * \return The USART peripheral's XCK pin mask.
 */
inline auto xck_mask( Peripheral::USART const & usart ) noexcept -> std::uint8_t
{
    return 1 << xck_number( usart );
}

/**
 * \brief Lookup a USART peripheral's XDIR pin port.
 *
 * \param[in] usart The USART peripheral whose XDIR pin port is to be looked up.
 *
 * \return The USART peripheral's XDIR pin port.
 */
inline auto & xdir_port( Peripheral::USART const & usart ) noexcept
{
    return usart_port( usart );
}

/**
 * \brief Lookup a USART peripheral's XDIR pin virtual port.
 *
 * \param[in] usart The USART peripheral whose XDIR pin virtual port is to be looked up.
 *
 * \return The USART peripheral's XDIR pin virtual port.
 */
inline auto & xdir_vport( Peripheral::USART const & usart ) noexcept
{
    return usart_vport( usart );
}

/**
 * \brief Lookup a USART peripheral's XDIR pin number.
 *
 * \param[in] usart The USART peripheral whose XDIR pin number is to be looked up.
 *
 * \return The USART peripheral's XDIR pin number.
 */
inline auto xdir_number( Peripheral::USART const & usart ) noexcept -> std::uint_fast8_t
{
    // #lizard forgives the length

    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::USART0::ADDRESS:
            switch ( Peripheral::PORTMUX0::instance().usart0_route() ) {
                case USART_Route::DEFAULT: return 3;
                case USART_Route::ALTERNATE: return 7;
                case USART_Route::NONE: break;
            } // switch
            break;
        case Peripheral::USART1::ADDRESS:
            switch ( Peripheral::PORTMUX0::instance().usart1_route() ) {
                case USART_Route::DEFAULT: return 3;
                case USART_Route::ALTERNATE: return 7;
                case USART_Route::NONE: break;
            } // switch
            break;
        case Peripheral::USART2::ADDRESS:
            switch ( Peripheral::PORTMUX0::instance().usart2_route() ) {
                case USART_Route::DEFAULT: return 3;
                case USART_Route::ALTERNATE: return 3;
                case USART_Route::NONE: break;
            } // switch
            break;
#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
        case Peripheral::USART3::ADDRESS:
            switch ( Peripheral::PORTMUX0::instance().usart3_route() ) {
                case USART_Route::DEFAULT: return 3;
                case USART_Route::ALTERNATE: return 3;
                case USART_Route::NONE: break;
            } // switch
            break;
#endif // defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
    }  // switch

    trap_fatal_error();
}

/**
 * \brief Lookup a USART peripheral's XDIR pin mask.
 *
 * \param[in] usart The USART peripheral whose XDIR pin mask is to be looked up.
 *
 * \return The USART peripheral's XDIR pin mask.
 */
inline auto xdir_mask( Peripheral::USART const & usart ) noexcept -> std::uint8_t
{
    return 1 << xdir_number( usart );
}

/**
 * \brief Lookup a USART peripheral's TXD pin port.
 *
 * \param[in] usart The USART peripheral whose TXD pin port is to be looked up.
 *
 * \return The USART peripheral's TXD pin port.
 */
inline auto & txd_port( Peripheral::USART const & usart ) noexcept
{
    return usart_port( usart );
}

/**
 * \brief Lookup a USART peripheral's TXD pin virtual port.
 *
 * \param[in] usart The USART peripheral whose TXD pin virtual port is to be looked up.
 *
 * \return The USART peripheral's TXD pin virtual port.
 */
inline auto & txd_vport( Peripheral::USART const & usart ) noexcept
{
    return usart_vport( usart );
}

/**
 * \brief Lookup a USART peripheral's TXD pin number.
 *
 * \param[in] usart The USART peripheral whose TXD pin number is to be looked up.
 *
 * \return The USART peripheral's TXD pin number.
 */
inline auto txd_number( Peripheral::USART const & usart ) noexcept -> std::uint_fast8_t
{
    // #lizard forgives the length

    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::USART0::ADDRESS:
            switch ( Peripheral::PORTMUX0::instance().usart0_route() ) {
                case USART_Route::DEFAULT: return 0;
                case USART_Route::ALTERNATE: return 4;
                case USART_Route::NONE: break;
            } // switch
            break;
        case Peripheral::USART1::ADDRESS:
            switch ( Peripheral::PORTMUX0::instance().usart1_route() ) {
                case USART_Route::DEFAULT: return 0;
                case USART_Route::ALTERNATE: return 4;
                case USART_Route::NONE: break;
            } // switch
            break;
        case Peripheral::USART2::ADDRESS:
            switch ( Peripheral::PORTMUX0::instance().usart2_route() ) {
                case USART_Route::DEFAULT: return 0;
                case USART_Route::ALTERNATE: return 4;
                case USART_Route::NONE: break;
            } // switch
            break;
#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
        case Peripheral::USART3::ADDRESS:
            switch ( Peripheral::PORTMUX0::instance().usart3_route() ) {
                case USART_Route::DEFAULT: return 0;
                case USART_Route::ALTERNATE: return 4;
                case USART_Route::NONE: break;
            } // switch
            break;
#endif // defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
    }  // switch

    trap_fatal_error();
}

/**
 * \brief Lookup a USART peripheral's TXD pin mask.
 *
 * \param[in] usart The USART peripheral whose TXD pin mask is to be looked up.
 *
 * \return The USART peripheral's TXD pin mask.
 */
inline auto txd_mask( Peripheral::USART const & usart ) noexcept -> std::uint8_t
{
    return 1 << txd_number( usart );
}

/**
 * \brief Lookup a USART peripheral's RXD pin port.
 *
 * \param[in] usart The USART peripheral whose RXD pin port is to be looked up.
 *
 * \return The USART peripheral's RXD pin port.
 */
inline auto & rxd_port( Peripheral::USART const & usart ) noexcept
{
    return usart_port( usart );
}

/**
 * \brief Lookup a USART peripheral's RXD pin virtual port.
 *
 * \param[in] usart The USART peripheral whose RXD pin virtual port is to be looked up.
 *
 * \return The USART peripheral's RXD pin virtual port.
 */
inline auto & rxd_vport( Peripheral::USART const & usart ) noexcept
{
    return usart_vport( usart );
}

/**
 * \brief Lookup a USART peripheral's RXD pin number.
 *
 * \param[in] usart The USART peripheral whose RXD pin number is to be looked up.
 *
 * \return The USART peripheral's RXD pin number.
 */
inline auto rxd_number( Peripheral::USART const & usart ) noexcept -> std::uint_fast8_t
{
    // #lizard forgives the length

    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::USART0::ADDRESS:
            switch ( Peripheral::PORTMUX0::instance().usart0_route() ) {
                case USART_Route::DEFAULT: return 1;
                case USART_Route::ALTERNATE: return 5;
                case USART_Route::NONE: break;
            } // switch
            break;
        case Peripheral::USART1::ADDRESS:
            switch ( Peripheral::PORTMUX0::instance().usart1_route() ) {
                case USART_Route::DEFAULT: return 1;
                case USART_Route::ALTERNATE: return 5;
                case USART_Route::NONE: break;
            } // switch
            break;
        case Peripheral::USART2::ADDRESS:
            switch ( Peripheral::PORTMUX0::instance().usart2_route() ) {
                case USART_Route::DEFAULT: return 1;
                case USART_Route::ALTERNATE: return 5;
                case USART_Route::NONE: break;
            } // switch
            break;
#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
        case Peripheral::USART3::ADDRESS:
            switch ( Peripheral::PORTMUX0::instance().usart3_route() ) {
                case USART_Route::DEFAULT: return 1;
                case USART_Route::ALTERNATE: return 5;
                case USART_Route::NONE: break;
            } // switch
            break;
#endif // defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
    }  // switch

    trap_fatal_error();
}

/**
 * \brief Lookup a USART peripheral's RXD pin mask.
 *
 * \param[in] usart The USART peripheral whose RXD pin mask is to be looked up.
 *
 * \return The USART peripheral's RXD pin mask.
 */
inline auto rxd_mask( Peripheral::USART const & usart ) noexcept -> std::uint8_t
{
    return 1 << rxd_number( usart );
}

} // namespace picolibrary::Microchip::megaAVR0::Multiplexed_Signals

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_MULTIPLEXED_SIGNALS_USART_H
