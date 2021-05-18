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
 * \brief picolibrary::Microchip::megaAVR0::Multiplexed_Signals::ATmega4809 interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_MULTIPLEXED_SIGNALS_ATMEGA4809_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_MULTIPLEXED_SIGNALS_ATMEGA4809_H

#include <cstdint>

#include "picolibrary/microchip/megaavr0/peripheral/atmega4809.h"
#include "picolibrary/microchip/megaavr0/peripheral/port.h"
#include "picolibrary/microchip/megaavr0/peripheral/portmux.h"
#include "picolibrary/microchip/megaavr0/peripheral/usart.h"
#include "picolibrary/microchip/megaavr0/peripheral/vport.h"

/**
 * \brief Microchip megaAVR 0-series ATmega4809 multiplexed signals facilities.
 *
 * \attention The contents of this namespace should never be used directly. Instead, set
 *            the `-mmcu` compiler flag to `atmega4809` and use them through the
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals namespace.
 */
namespace picolibrary::Microchip::megaAVR0::Multiplexed_Signals::ATmega4809 {

inline namespace USART {

/**
 * \brief Set a USART peripheral's routing configuration.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::set_usart_route().
 *
 * \param[in] usart The USART peripheral whose routing configuration will be set.
 * \param[in] route The desired USART peripheral routing configuration.
 */
inline void set_usart_route( Peripheral::USART const & usart, Peripheral::PORTMUX::USART_Route route ) noexcept
{
    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::ATmega4809::USART0::ADDRESS:
            Peripheral::ATmega4809::PORTMUX0::instance().set_usart0_route( route );
            break;
        case Peripheral::ATmega4809::USART1::ADDRESS:
            Peripheral::ATmega4809::PORTMUX0::instance().set_usart1_route( route );
            break;
        case Peripheral::ATmega4809::USART2::ADDRESS:
            Peripheral::ATmega4809::PORTMUX0::instance().set_usart2_route( route );
            break;
        case Peripheral::ATmega4809::USART3::ADDRESS:
            Peripheral::ATmega4809::PORTMUX0::instance().set_usart3_route( route );
            break;
    } // switch
}

/**
 * \brief Lookup a USART peripheral's pins port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::usart_port().
 *
 * \param[in] usart The USART peripheral whose pins port is to be looked up.
 *
 * \return The USART peripheral's pins port.
 */
inline auto usart_port( Peripheral::USART const & usart ) noexcept -> Peripheral::PORT &
{
    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::ATmega4809::USART0::ADDRESS:
            return Peripheral::ATmega4809::PORTA::instance();
        case Peripheral::ATmega4809::USART1::ADDRESS:
            return Peripheral::ATmega4809::PORTC::instance();
        case Peripheral::ATmega4809::USART2::ADDRESS:
            return Peripheral::ATmega4809::PORTF::instance();
        case Peripheral::ATmega4809::USART3::ADDRESS:
            return Peripheral::ATmega4809::PORTB::instance();
    } // switch

    return *static_cast<Peripheral::PORT *>( nullptr );
}

/**
 * \brief Lookup a USART peripheral's pins virtual port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::usart_vport().
 *
 * \param[in] usart The USART peripheral whose pins virtual port is to be looked up.
 *
 * \return The USART peripheral's pins virtual port.
 */
inline auto usart_vport( Peripheral::USART const & usart ) noexcept -> Peripheral::VPORT &
{
    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::ATmega4809::USART0::ADDRESS:
            return Peripheral::ATmega4809::VPORTA::instance();
        case Peripheral::ATmega4809::USART1::ADDRESS:
            return Peripheral::ATmega4809::VPORTC::instance();
        case Peripheral::ATmega4809::USART2::ADDRESS:
            return Peripheral::ATmega4809::VPORTF::instance();
        case Peripheral::ATmega4809::USART3::ADDRESS:
            return Peripheral::ATmega4809::VPORTB::instance();
    } // switch

    return *static_cast<Peripheral::VPORT *>( nullptr );
}

/**
 * \brief Lookup a USART peripheral's XCK pin port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::xck_port().
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
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::xck_vport().
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
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::xck_number().
 *
 * \param[in] usart The USART peripheral whose XCK pin number is to be looked up.
 *
 * \return The USART peripheral's XCK pin number.
 */
inline auto xck_number( Peripheral::USART const & usart ) noexcept -> std::uint_fast8_t
{
    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::ATmega4809::USART0::ADDRESS:
            switch ( Peripheral::ATmega4809::PORTMUX0::instance().usart0_route() ) {
                case Peripheral::PORTMUX::USART_Route::DEFAULT: return 2;
                case Peripheral::PORTMUX::USART_Route::ALTERNATE: return 6;
                default: break;
            } // switch
            break;
        case Peripheral::ATmega4809::USART1::ADDRESS:
            switch ( Peripheral::ATmega4809::PORTMUX0::instance().usart1_route() ) {
                case Peripheral::PORTMUX::USART_Route::DEFAULT: return 2;
                case Peripheral::PORTMUX::USART_Route::ALTERNATE: return 6;
                default: break;
            } // switch
            break;
        case Peripheral::ATmega4809::USART2::ADDRESS:
            switch ( Peripheral::ATmega4809::PORTMUX0::instance().usart2_route() ) {
                case Peripheral::PORTMUX::USART_Route::DEFAULT: return 2;
                case Peripheral::PORTMUX::USART_Route::ALTERNATE: return 6;
                default: break;
            } // switch
            break;
        case Peripheral::ATmega4809::USART3::ADDRESS:
            switch ( Peripheral::ATmega4809::PORTMUX0::instance().usart3_route() ) {
                case Peripheral::PORTMUX::USART_Route::DEFAULT: return 2;
                case Peripheral::PORTMUX::USART_Route::ALTERNATE: return 2;
                default: break;
            } // switch
            break;
    } // switch

    return 0;
}

/**
 * \brief Lookup a USART peripheral's XCK pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::xck_mask().
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
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::xdir_port().
 *
 * \param[in] usart The USART peripheral whose XDIR pin port is to be looked up.
 *
 * \return The USART peripheral's XDIR pin port.
 */
inline auto xdir_port( Peripheral::USART const & usart ) noexcept -> Peripheral::PORT &
{
    return usart_port( usart );
}

/**
 * \brief Lookup a USART peripheral's XDIR pin virtual port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::xdir_vport().
 *
 * \param[in] usart The USART peripheral whose XDIR pin virtual port is to be looked up.
 *
 * \return The USART peripheral's XDIR pin virtual port.
 */
inline auto xdir_vport( Peripheral::USART const & usart ) noexcept -> Peripheral::VPORT &
{
    return usart_vport( usart );
}

/**
 * \brief Lookup a USART peripheral's XDIR pin number.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::xdir_number().
 *
 * \param[in] usart The USART peripheral whose XDIR pin number is to be looked up.
 *
 * \return The USART peripheral's XDIR pin number.
 */
inline auto xdir_number( Peripheral::USART const & usart ) noexcept -> std::uint_fast8_t
{
    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::ATmega4809::USART0::ADDRESS:
            switch ( Peripheral::ATmega4809::PORTMUX0::instance().usart0_route() ) {
                case Peripheral::PORTMUX::USART_Route::DEFAULT: return 3;
                case Peripheral::PORTMUX::USART_Route::ALTERNATE: return 7;
                default: break;
            } // switch
            break;
        case Peripheral::ATmega4809::USART1::ADDRESS:
            switch ( Peripheral::ATmega4809::PORTMUX0::instance().usart1_route() ) {
                case Peripheral::PORTMUX::USART_Route::DEFAULT: return 3;
                case Peripheral::PORTMUX::USART_Route::ALTERNATE: return 7;
                default: break;
            } // switch
            break;
        case Peripheral::ATmega4809::USART2::ADDRESS:
            switch ( Peripheral::ATmega4809::PORTMUX0::instance().usart2_route() ) {
                case Peripheral::PORTMUX::USART_Route::DEFAULT: return 3;
                case Peripheral::PORTMUX::USART_Route::ALTERNATE: return 3;
                default: break;
            } // switch
            break;
        case Peripheral::ATmega4809::USART3::ADDRESS:
            switch ( Peripheral::ATmega4809::PORTMUX0::instance().usart3_route() ) {
                case Peripheral::PORTMUX::USART_Route::DEFAULT: return 3;
                case Peripheral::PORTMUX::USART_Route::ALTERNATE: return 3;
                default: break;
            } // switch
            break;
    } // switch

    return 0;
}

/**
 * \brief Lookup a USART peripheral's XDIR pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::xdir_mask().
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
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::txd_port().
 *
 * \param[in] usart The USART peripheral whose TXD pin port is to be looked up.
 *
 * \return The USART peripheral's TXD pin port.
 */
inline auto txd_port( Peripheral::USART const & usart ) noexcept -> Peripheral::PORT &
{
    return usart_port( usart );
}

/**
 * \brief Lookup a USART peripheral's TXD pin virtual port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::txd_vport().
 *
 * \param[in] usart The USART peripheral whose TXD pin virtual port is to be looked up.
 *
 * \return The USART peripheral's TXD pin virtual port.
 */
inline auto txd_vport( Peripheral::USART const & usart ) noexcept -> Peripheral::VPORT &
{
    return usart_vport( usart );
}

/**
 * \brief Lookup a USART peripheral's TXD pin number.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::txd_number().
 *
 * \param[in] usart The USART peripheral whose TXD pin number is to be looked up.
 *
 * \return The USART peripheral's TXD pin number.
 */
inline auto txd_number( Peripheral::USART const & usart ) noexcept -> std::uint_fast8_t
{
    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::ATmega4809::USART0::ADDRESS:
            switch ( Peripheral::ATmega4809::PORTMUX0::instance().usart0_route() ) {
                case Peripheral::PORTMUX::USART_Route::DEFAULT: return 0;
                case Peripheral::PORTMUX::USART_Route::ALTERNATE: return 4;
                default: break;
            } // switch
            break;
        case Peripheral::ATmega4809::USART1::ADDRESS:
            switch ( Peripheral::ATmega4809::PORTMUX0::instance().usart1_route() ) {
                case Peripheral::PORTMUX::USART_Route::DEFAULT: return 0;
                case Peripheral::PORTMUX::USART_Route::ALTERNATE: return 4;
                default: break;
            } // switch
            break;
        case Peripheral::ATmega4809::USART2::ADDRESS:
            switch ( Peripheral::ATmega4809::PORTMUX0::instance().usart2_route() ) {
                case Peripheral::PORTMUX::USART_Route::DEFAULT: return 0;
                case Peripheral::PORTMUX::USART_Route::ALTERNATE: return 4;
                default: break;
            } // switch
            break;
        case Peripheral::ATmega4809::USART3::ADDRESS:
            switch ( Peripheral::ATmega4809::PORTMUX0::instance().usart3_route() ) {
                case Peripheral::PORTMUX::USART_Route::DEFAULT: return 0;
                case Peripheral::PORTMUX::USART_Route::ALTERNATE: return 4;
                default: break;
            } // switch
            break;
    } // switch

    return 0;
}

/**
 * \brief Lookup a USART peripheral's TXD pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::txd_mask().
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
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::rxd_port().
 *
 * \param[in] usart The USART peripheral whose RXD pin port is to be looked up.
 *
 * \return The USART peripheral's RXD pin port.
 */
inline auto rxd_port( Peripheral::USART const & usart ) noexcept -> Peripheral::PORT &
{
    return usart_port( usart );
}

/**
 * \brief Lookup a USART peripheral's RXD pin virtual port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::rxd_vport().
 *
 * \param[in] usart The USART peripheral whose RXD pin virtual port is to be looked up.
 *
 * \return The USART peripheral's RXD pin virtual port.
 */
inline auto rxd_vport( Peripheral::USART const & usart ) noexcept -> Peripheral::VPORT &
{
    return usart_vport( usart );
}

/**
 * \brief Lookup a USART peripheral's RXD pin number.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::rxd_number().
 *
 * \param[in] usart The USART peripheral whose RXD pin number is to be looked up.
 *
 * \return The USART peripheral's RXD pin number.
 */
inline auto rxd_number( Peripheral::USART const & usart ) noexcept -> std::uint_fast8_t
{
    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::ATmega4809::USART0::ADDRESS:
            switch ( Peripheral::ATmega4809::PORTMUX0::instance().usart0_route() ) {
                case Peripheral::PORTMUX::USART_Route::DEFAULT: return 1;
                case Peripheral::PORTMUX::USART_Route::ALTERNATE: return 5;
                default: break;
            } // switch
            break;
        case Peripheral::ATmega4809::USART1::ADDRESS:
            switch ( Peripheral::ATmega4809::PORTMUX0::instance().usart1_route() ) {
                case Peripheral::PORTMUX::USART_Route::DEFAULT: return 1;
                case Peripheral::PORTMUX::USART_Route::ALTERNATE: return 5;
                default: break;
            } // switch
            break;
        case Peripheral::ATmega4809::USART2::ADDRESS:
            switch ( Peripheral::ATmega4809::PORTMUX0::instance().usart2_route() ) {
                case Peripheral::PORTMUX::USART_Route::DEFAULT: return 1;
                case Peripheral::PORTMUX::USART_Route::ALTERNATE: return 5;
                default: break;
            } // switch
            break;
        case Peripheral::ATmega4809::USART3::ADDRESS:
            switch ( Peripheral::ATmega4809::PORTMUX0::instance().usart3_route() ) {
                case Peripheral::PORTMUX::USART_Route::DEFAULT: return 1;
                case Peripheral::PORTMUX::USART_Route::ALTERNATE: return 5;
                default: break;
            } // switch
            break;
    } // switch

    return 0;
}

/**
 * \brief Lookup a USART peripheral's RXD pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::rxd_mask().
 *
 * \param[in] usart The USART peripheral whose RXD pin mask is to be looked up.
 *
 * \return The USART peripheral's RXD pin mask.
 */
inline auto rxd_mask( Peripheral::USART const & usart ) noexcept -> std::uint8_t
{
    return 1 << rxd_number( usart );
}

}} // namespace picolibrary::Microchip::megaAVR0::Multiplexed_Signals::ATmega4809::USART

namespace picolibrary::Microchip::megaAVR0::Multiplexed_Signals {

#ifdef __AVR_ATmega4809__
using namespace ATmega4809;
#endif // __AVR_ATmega4809__

} // namespace picolibrary::Microchip::megaAVR0::Multiplexed_Signals

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_MULTIPLEXED_SIGNALS_ATMEGA4809_H
