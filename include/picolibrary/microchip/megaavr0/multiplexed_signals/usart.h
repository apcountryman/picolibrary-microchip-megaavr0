/**
 * picolibrary-microchip-megaavr0
 *
 * Copyright 2021-2024, Andrew Countryman <apcountryman@gmail.com> and the
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
 * \brief picolibrary::Microchip::megaAVR0::Multiplexed_Signals USART interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_MULTIPLEXED_SIGNALS_USART_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_MULTIPLEXED_SIGNALS_USART_H

#include <cstdint>

#include "picolibrary/error.h"
#include "picolibrary/microchip/megaavr0/peripheral.h"
#include "picolibrary/microchip/megaavr0/peripheral/port.h"
#include "picolibrary/microchip/megaavr0/peripheral/portmux.h"
#include "picolibrary/microchip/megaavr0/peripheral/usart.h"
#include "picolibrary/microchip/megaavr0/peripheral/vport.h"
#include "picolibrary/precondition.h"
#include "picolibrary/utility.h"

namespace picolibrary::Microchip::megaAVR0::Multiplexed_Signals {

/**
 * \brief USART peripheral routing configuration.
 */
enum class USART_Route : std::uint_fast8_t {
    DEFAULT   = 0x0, ///< Default route.
    ALTERNATE = 0x1, ///< Alternate route.
    NONE      = 0x3, ///< Not routed.
};

/**
 * \brief Get a USART peripheral's routing configuration.
 *
 * \param[in] usart The USART peripheral whose routing configuration is to be gotten.
 *
 * \return The USART peripheral's routing configuration.
 */
inline auto usart_route( Peripheral::USART const & usart ) noexcept -> USART_Route
{
    // #lizard forgives the length

    auto const & portmux = Peripheral::PORTMUX0::instance();

    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::USART0::ADDRESS:
            return static_cast<USART_Route>(
                ( portmux.usartroutea & Peripheral::PORTMUX::USARTROUTEA::Mask::USART0 )
                >> Peripheral::PORTMUX::USARTROUTEA::Bit::USART0 );
        case Peripheral::USART1::ADDRESS:
            return static_cast<USART_Route>(
                ( portmux.usartroutea & Peripheral::PORTMUX::USARTROUTEA::Mask::USART1 )
                >> Peripheral::PORTMUX::USARTROUTEA::Bit::USART1 );
        case Peripheral::USART2::ADDRESS:
            return static_cast<USART_Route>(
                ( portmux.usartroutea & Peripheral::PORTMUX::USARTROUTEA::Mask::USART2 )
                >> Peripheral::PORTMUX::USARTROUTEA::Bit::USART2 );
#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
        case Peripheral::USART3::ADDRESS:
            return static_cast<USART_Route>(
                ( portmux.usartroutea & Peripheral::PORTMUX::USARTROUTEA::Mask::USART3 )
                >> Peripheral::PORTMUX::USARTROUTEA::Bit::USART3 );
#endif // defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
    }  // switch

    PICOLIBRARY_EXPECTATION_NOT_MET( Generic_Error::INVALID_ARGUMENT );
}

/**
 * \brief Set a USART peripheral's routing configuration.
 *
 * \param[in] usart The USART peripheral whose routing configuration is to be set.
 * \param[in] route The desired USART peripheral routing configuration.
 */
inline void set_usart_route( Peripheral::USART const & usart, USART_Route route ) noexcept
{
    // #lizard forgives the length

    auto & portmux = Peripheral::PORTMUX0::instance();

    switch ( reinterpret_cast<std::uintptr_t>( &usart ) ) {
        case Peripheral::USART0::ADDRESS:
            portmux.usartroutea = ( portmux.usartroutea & ~Peripheral::PORTMUX::USARTROUTEA::Mask::USART0 )
                                  | ( to_underlying( route )
                                      << Peripheral::PORTMUX::USARTROUTEA::Bit::USART0 );
            return;
        case Peripheral::USART1::ADDRESS:
            portmux.usartroutea = ( portmux.usartroutea & ~Peripheral::PORTMUX::USARTROUTEA::Mask::USART1 )
                                  | ( to_underlying( route )
                                      << Peripheral::PORTMUX::USARTROUTEA::Bit::USART1 );
            return;
        case Peripheral::USART2::ADDRESS:
            portmux.usartroutea = ( portmux.usartroutea & ~Peripheral::PORTMUX::USARTROUTEA::Mask::USART2 )
                                  | ( to_underlying( route )
                                      << Peripheral::PORTMUX::USARTROUTEA::Bit::USART2 );
            return;
#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
        case Peripheral::USART3::ADDRESS:
            portmux.usartroutea = ( portmux.usartroutea & ~Peripheral::PORTMUX::USARTROUTEA::Mask::USART3 )
                                  | ( to_underlying( route )
                                      << Peripheral::PORTMUX::USARTROUTEA::Bit::USART3 );
            return;
#endif // defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
    }  // switch

    PICOLIBRARY_EXPECTATION_NOT_MET( Generic_Error::INVALID_ARGUMENT );
}

/**
 * \brief Lookup a USART peripheral's pins PORT peripheral address.
 *
 * \param[in] usart_address The address of the USART peripheral whose pins PORT peripheral
 *            address is to be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's pins PORT peripheral address.
 */
constexpr auto usart_port_address( std::uintptr_t usart_address, USART_Route route ) noexcept
    -> std::uintptr_t
{
    // #lizard forgives the length

    switch ( usart_address ) {
        case Peripheral::USART0::ADDRESS:
            switch ( route ) {
                case USART_Route::DEFAULT: return Peripheral::PORTA::ADDRESS;
                case USART_Route::ALTERNATE: return Peripheral::PORTA::ADDRESS;
                case USART_Route::NONE: break;
            } // switch
            break;
        case Peripheral::USART1::ADDRESS:
            switch ( route ) {
                case USART_Route::DEFAULT: return Peripheral::PORTC::ADDRESS;
                case USART_Route::ALTERNATE: return Peripheral::PORTC::ADDRESS;
                case USART_Route::NONE: break;
            } // switch
            break;
        case Peripheral::USART2::ADDRESS:
            switch ( route ) {
                case USART_Route::DEFAULT: return Peripheral::PORTF::ADDRESS;
                case USART_Route::ALTERNATE: return Peripheral::PORTF::ADDRESS;
                case USART_Route::NONE: break;
            } // switch
            break;
#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
        case Peripheral::USART3::ADDRESS:
            switch ( route ) {
                case USART_Route::DEFAULT: return Peripheral::PORTB::ADDRESS;
                case USART_Route::ALTERNATE: return Peripheral::PORTB::ADDRESS;
                case USART_Route::NONE: break;
            } // switch
            break;
#endif // defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
    };

    PICOLIBRARY_EXPECTATION_NOT_MET( Generic_Error::INVALID_ARGUMENT );
}

/**
 * \brief Lookup a USART peripheral's pins PORT peripheral.
 *
 * \param[in] usart The USART peripheral whose pins PORT peripheral is to be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's pins PORT peripheral.
 */
inline auto usart_port( Peripheral::USART const & usart, USART_Route route ) noexcept
    -> Peripheral::PORT &
{
    return *reinterpret_cast<Peripheral::PORT *>(
        usart_port_address( reinterpret_cast<std::uintptr_t>( &usart ), route ) );
}

/**
 * \brief Lookup a USART peripheral's pins PORT peripheral.
 *
 * \param[in] usart The USART peripheral whose pins PORT peripheral is to be looked up.
 *
 * \return The USART peripheral's pins PORT peripheral.
 */
inline auto usart_port( Peripheral::USART const & usart ) noexcept -> Peripheral::PORT &
{
    return usart_port( usart, usart_route( usart ) );
}

/**
 * \brief Lookup a USART peripheral's pins VPORT peripheral address.
 *
 * \param[in] usart_address The address of the USART peripheral whose pins VPORT
 *            peripheral address is to be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's pins VPORT peripheral address.
 */
constexpr auto usart_vport_address( std::uintptr_t usart_address, USART_Route route ) noexcept
    -> std::uintptr_t
{
    // #lizard forgives the length

    switch ( usart_address ) {
        case Peripheral::USART0::ADDRESS:
            switch ( route ) {
                case USART_Route::DEFAULT: return Peripheral::VPORTA::ADDRESS;
                case USART_Route::ALTERNATE: return Peripheral::VPORTA::ADDRESS;
                case USART_Route::NONE: break;
            } // switch
            break;
        case Peripheral::USART1::ADDRESS:
            switch ( route ) {
                case USART_Route::DEFAULT: return Peripheral::VPORTC::ADDRESS;
                case USART_Route::ALTERNATE: return Peripheral::VPORTC::ADDRESS;
                case USART_Route::NONE: break;
            } // switch
            break;
        case Peripheral::USART2::ADDRESS:
            switch ( route ) {
                case USART_Route::DEFAULT: return Peripheral::VPORTF::ADDRESS;
                case USART_Route::ALTERNATE: return Peripheral::VPORTF::ADDRESS;
                case USART_Route::NONE: break;
            } // switch
            break;
#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
        case Peripheral::USART3::ADDRESS:
            switch ( route ) {
                case USART_Route::DEFAULT: return Peripheral::VPORTB::ADDRESS;
                case USART_Route::ALTERNATE: return Peripheral::VPORTB::ADDRESS;
                case USART_Route::NONE: break;
            } // switch
            break;
#endif // defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
    };

    PICOLIBRARY_EXPECTATION_NOT_MET( Generic_Error::INVALID_ARGUMENT );
}

/**
 * \brief Lookup a USART peripheral's pins VPORT peripheral.
 *
 * \param[in] usart The USART peripheral whose pins VPORT peripheral is to be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's pins VPORT peripheral.
 */
inline auto usart_vport( Peripheral::USART const & usart, USART_Route route ) noexcept
    -> Peripheral::VPORT &
{
    return *reinterpret_cast<Peripheral::VPORT *>(
        usart_vport_address( reinterpret_cast<std::uintptr_t>( &usart ), route ) );
}

/**
 * \brief Lookup a USART peripheral's pins VPORT peripheral.
 *
 * \param[in] usart The USART peripheral whose pins VPORT peripheral is to be looked up.
 *
 * \return The USART peripheral's pins VPORT peripheral.
 */
inline auto usart_vport( Peripheral::USART const & usart ) noexcept -> Peripheral::VPORT &
{
    return usart_vport( usart, usart_route( usart ) );
}

/**
 * \brief Lookup a USART peripheral's XCK pin PORT peripheral address.
 *
 * \param[in] usart_address The address of the USART peripheral whose XCK pin PORT
 *            peripheral address is to be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's XCK pin PORT peripheral address.
 */
constexpr auto xck_port_address( std::uintptr_t usart_address, USART_Route route ) noexcept
    -> std::uintptr_t
{
    return usart_port_address( usart_address, route );
}

/**
 * \brief Lookup a USART peripheral's XCK pin PORT peripheral.
 *
 * \param[in] usart The USART peripheral whose XCK pin PORT peripheral is to be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's XCK pin PORT peripheral.
 */
inline auto xck_port( Peripheral::USART const & usart, USART_Route route ) noexcept
    -> Peripheral::PORT &
{
    return usart_port( usart, route );
}

/**
 * \brief Lookup a USART peripheral's XCK pin PORT peripheral.
 *
 * \param[in] usart The USART peripheral whose XCK pin PORT peripheral is to be looked up.
 *
 * \return The USART peripheral's XCK pin PORT peripheral.
 */
inline auto xck_port( Peripheral::USART const & usart ) noexcept -> Peripheral::PORT &
{
    return usart_port( usart );
}

/**
 * \brief Lookup a USART peripheral's XCK pin VPORT peripheral address.
 *
 * \param[in] usart_address The address of the USART peripheral whose XCK pin VPORT
 *            peripheral address is to be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's XCK pin VPORT peripheral address.
 */
constexpr auto xck_vport_address( std::uintptr_t usart_address, USART_Route route ) noexcept
    -> std::uintptr_t
{
    return usart_vport_address( usart_address, route );
}

/**
 * \brief Lookup a USART peripheral's XCK pin VPORT peripheral.
 *
 * \param[in] usart The USART peripheral whose XCK pin VPORT peripheral is to be looked
 *            up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's XCK pin VPORT peripheral.
 */
inline auto xck_vport( Peripheral::USART const & usart, USART_Route route ) noexcept
    -> Peripheral::VPORT &
{
    return usart_vport( usart, route );
}

/**
 * \brief Lookup a USART peripheral's XCK pin VPORT peripheral.
 *
 * \param[in] usart The USART peripheral whose XCK pin VPORT peripheral is to be looked
 *            up.
 *
 * \return The USART peripheral's XCK pin VPORT peripheral.
 */
inline auto xck_vport( Peripheral::USART const & usart ) noexcept -> Peripheral::VPORT &
{
    return usart_vport( usart );
}

/**
 * \brief Lookup a USART peripheral's XCK pin number.
 *
 * \param[in] usart_address The address of the USART peripheral whose XCK pin number is to
 *            be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's XCK pin number.
 */
constexpr auto xck_number( std::uintptr_t usart_address, USART_Route route ) noexcept -> std::uint_fast8_t
{
    // #lizard forgives the length

    switch ( usart_address ) {
        case Peripheral::USART0::ADDRESS:
            switch ( route ) {
                case USART_Route::DEFAULT: return 2;
                case USART_Route::ALTERNATE: return 6;
                case USART_Route::NONE: break;
            } // switch
            break;
        case Peripheral::USART1::ADDRESS:
            switch ( route ) {
                case USART_Route::DEFAULT: return 2;
                case USART_Route::ALTERNATE: return 6;
                case USART_Route::NONE: break;
            } // switch
            break;
        case Peripheral::USART2::ADDRESS:
            switch ( route ) {
                case USART_Route::DEFAULT: return 2;
                case USART_Route::ALTERNATE: return 6;
                case USART_Route::NONE: break;
            } // switch
            break;
#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
        case Peripheral::USART3::ADDRESS:
            switch ( route ) {
                case USART_Route::DEFAULT: return 2;
                case USART_Route::ALTERNATE: break;
                case USART_Route::NONE: break;
            } // switch
            break;
#endif // defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
    }  // switch

    PICOLIBRARY_EXPECTATION_NOT_MET( Generic_Error::INVALID_ARGUMENT );
}

/**
 * \brief Lookup a USART peripheral's XCK pin number.
 *
 * \param[in] usart The USART peripheral whose XCK pin number is to be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's XCK pin number.
 */
inline auto xck_number( Peripheral::USART const & usart, USART_Route route ) noexcept -> std::uint_fast8_t
{
    return xck_number( reinterpret_cast<std::uintptr_t>( &usart ), route );
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
    return xck_number( usart, usart_route( usart ) );
}

/**
 * \brief Lookup a USART peripheral's XCK pin mask.
 *
 * \param[in] usart_address The address of the USART peripheral whose XCK pin mask is to
 *            be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's XCK pin mask.
 */
constexpr auto xck_mask( std::uintptr_t usart_address, USART_Route route ) noexcept -> std::uint8_t
{
    return 1 << xck_number( usart_address, route );
}

/**
 * \brief Lookup a USART peripheral's XCK pin mask.
 *
 * \param[in] usart The USART peripheral whose XCK pin mask is to be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's XCK pin mask.
 */
inline auto xck_mask( Peripheral::USART const & usart, USART_Route route ) noexcept -> std::uint8_t
{
    return xck_mask( reinterpret_cast<std::uintptr_t>( &usart ), route );
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
    return xck_mask( usart, usart_route( usart ) );
}

/**
 * \brief Lookup a USART peripheral's XDIR pin PORT peripheral address.
 *
 * \param[in] usart_address The address of the USART peripheral whose XDIR pin PORT
 *            peripheral address is to be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's XDIR pin PORT peripheral address.
 */
constexpr auto xdir_port_address( std::uintptr_t usart_address, USART_Route route ) noexcept
    -> std::uintptr_t
{
    return usart_port_address( usart_address, route );
}

/**
 * \brief Lookup a USART peripheral's XDIR pin PORT peripheral.
 *
 * \param[in] usart The USART peripheral whose XDIR pin PORT peripheral is to be looked
 *            up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's XDIR pin PORT peripheral.
 */
inline auto xdir_port( Peripheral::USART const & usart, USART_Route route ) noexcept
    -> Peripheral::PORT &
{
    return usart_port( usart, route );
}

/**
 * \brief Lookup a USART peripheral's XDIR pin PORT peripheral.
 *
 * \param[in] usart The USART peripheral whose XDIR pin PORT peripheral is to be looked
 *            up.
 *
 * \return The USART peripheral's XDIR pin PORT peripheral.
 */
inline auto xdir_port( Peripheral::USART const & usart ) noexcept -> Peripheral::PORT &
{
    return usart_port( usart );
}

/**
 * \brief Lookup a USART peripheral's XDIR pin VPORT peripheral address.
 *
 * \param[in] usart_address The address of the USART peripheral whose XDIR pin VPORT
 *            peripheral address is to be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's XDIR pin VPORT peripheral address.
 */
constexpr auto xdir_vport_address( std::uintptr_t usart_address, USART_Route route ) noexcept
    -> std::uintptr_t
{
    return usart_vport_address( usart_address, route );
}

/**
 * \brief Lookup a USART peripheral's XDIR pin VPORT peripheral.
 *
 * \param[in] usart The USART peripheral whose XDIR pin VPORT peripheral is to be looked
 *            up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's XDIR pin VPORT peripheral.
 */
inline auto xdir_vport( Peripheral::USART const & usart, USART_Route route ) noexcept
    -> Peripheral::VPORT &
{
    return usart_vport( usart, route );
}

/**
 * \brief Lookup a USART peripheral's XDIR pin VPORT peripheral.
 *
 * \param[in] usart The USART peripheral whose XDIR pin VPORT peripheral is to be looked
 *            up.
 *
 * \return The USART peripheral's XDIR pin VPORT peripheral.
 */
inline auto xdir_vport( Peripheral::USART const & usart ) noexcept -> Peripheral::VPORT &
{
    return usart_vport( usart );
}

/**
 * \brief Lookup a USART peripheral's XDIR pin number.
 *
 * \param[in] usart_address The address of the USART peripheral whose XDIR pin number is
 *            to be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's XDIR pin number.
 */
constexpr auto xdir_number( std::uintptr_t usart_address, USART_Route route ) noexcept -> std::uint_fast8_t
{
    // #lizard forgives the length

    switch ( usart_address ) {
        case Peripheral::USART0::ADDRESS:
            switch ( route ) {
                case USART_Route::DEFAULT: return 3;
                case USART_Route::ALTERNATE: return 7;
                case USART_Route::NONE: break;
            } // switch
            break;
        case Peripheral::USART1::ADDRESS:
            switch ( route ) {
                case USART_Route::DEFAULT: return 3;
                case USART_Route::ALTERNATE: return 7;
                case USART_Route::NONE: break;
            } // switch
            break;
        case Peripheral::USART2::ADDRESS:
            switch ( route ) {
                case USART_Route::DEFAULT: return 3;
                case USART_Route::ALTERNATE: break;
                case USART_Route::NONE: break;
            } // switch
            break;
#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
        case Peripheral::USART3::ADDRESS:
            switch ( route ) {
                case USART_Route::DEFAULT: return 3;
                case USART_Route::ALTERNATE: break;
                case USART_Route::NONE: break;
            } // switch
            break;
#endif // defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
    }  // switch

    PICOLIBRARY_EXPECTATION_NOT_MET( Generic_Error::INVALID_ARGUMENT );
}

/**
 * \brief Lookup a USART peripheral's XDIR pin number.
 *
 * \param[in] usart The USART peripheral whose XDIR pin number is to be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's XDIR pin number.
 */
inline auto xdir_number( Peripheral::USART const & usart, USART_Route route ) noexcept -> std::uint_fast8_t
{
    return xdir_number( reinterpret_cast<std::uintptr_t>( &usart ), route );
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
    return xdir_number( usart, usart_route( usart ) );
}

/**
 * \brief Lookup a USART peripheral's XDIR pin mask.
 *
 * \param[in] usart_address The address of the USART peripheral whose XDIR pin mask is to
 *            be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's XDIR pin mask.
 */
constexpr auto xdir_mask( std::uintptr_t usart_address, USART_Route route ) noexcept -> std::uint8_t
{
    return 1 << xdir_number( usart_address, route );
}

/**
 * \brief Lookup a USART peripheral's XDIR pin mask.
 *
 * \param[in] usart The USART peripheral whose XDIR pin mask is to be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's XDIR pin mask.
 */
inline auto xdir_mask( Peripheral::USART const & usart, USART_Route route ) noexcept -> std::uint8_t
{
    return xdir_mask( reinterpret_cast<std::uintptr_t>( &usart ), route );
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
    return xdir_mask( usart, usart_route( usart ) );
}

/**
 * \brief Lookup a USART peripheral's TXD pin PORT peripheral address.
 *
 * \param[in] usart_address The address of the USART peripheral whose TXD pin PORT
 *            peripheral address is to be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's TXD pin PORT peripheral address.
 */
constexpr auto txd_port_address( std::uintptr_t usart_address, USART_Route route ) noexcept
    -> std::uintptr_t
{
    return usart_port_address( usart_address, route );
}

/**
 * \brief Lookup a USART peripheral's TXD pin PORT peripheral.
 *
 * \param[in] usart The USART peripheral whose TXD pin PORT peripheral is to be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's TXD pin PORT peripheral.
 */
inline auto txd_port( Peripheral::USART const & usart, USART_Route route ) noexcept
    -> Peripheral::PORT &
{
    return usart_port( usart, route );
}

/**
 * \brief Lookup a USART peripheral's TXD pin PORT peripheral.
 *
 * \param[in] usart The USART peripheral whose TXD pin PORT peripheral is to be looked up.
 *
 * \return The USART peripheral's TXD pin PORT peripheral.
 */
inline auto txd_port( Peripheral::USART const & usart ) noexcept -> Peripheral::PORT &
{
    return usart_port( usart );
}

/**
 * \brief Lookup a USART peripheral's TXD pin VPORT peripheral address.
 *
 * \param[in] usart_address The address of the USART peripheral whose TXD pin VPORT
 *            peripheral address is to be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's TXD pin VPORT peripheral address.
 */
constexpr auto txd_vport_address( std::uintptr_t usart_address, USART_Route route ) noexcept
    -> std::uintptr_t
{
    return usart_vport_address( usart_address, route );
}

/**
 * \brief Lookup a USART peripheral's TXD pin VPORT peripheral.
 *
 * \param[in] usart The USART peripheral whose TXD pin VPORT peripheral is to be looked
 *            up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's TXD pin VPORT peripheral.
 */
inline auto txd_vport( Peripheral::USART const & usart, USART_Route route ) noexcept
    -> Peripheral::VPORT &
{
    return usart_vport( usart, route );
}

/**
 * \brief Lookup a USART peripheral's TXD pin VPORT peripheral.
 *
 * \param[in] usart The USART peripheral whose TXD pin VPORT peripheral is to be looked
 *            up.
 *
 * \return The USART peripheral's TXD pin VPORT peripheral.
 */
inline auto txd_vport( Peripheral::USART const & usart ) noexcept -> Peripheral::VPORT &
{
    return usart_vport( usart );
}

/**
 * \brief Lookup a USART peripheral's TXD pin number.
 *
 * \param[in] usart_address The address of the USART peripheral whose TXD pin number is to
 *            be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's TXD pin number.
 */
constexpr auto txd_number( std::uintptr_t usart_address, USART_Route route ) noexcept -> std::uint_fast8_t
{
    // #lizard forgives the length

    switch ( usart_address ) {
        case Peripheral::USART0::ADDRESS:
            switch ( route ) {
                case USART_Route::DEFAULT: return 0;
                case USART_Route::ALTERNATE: return 4;
                case USART_Route::NONE: break;
            } // switch
            break;
        case Peripheral::USART1::ADDRESS:
            switch ( route ) {
                case USART_Route::DEFAULT: return 0;
                case USART_Route::ALTERNATE: return 4;
                case USART_Route::NONE: break;
            } // switch
            break;
        case Peripheral::USART2::ADDRESS:
            switch ( route ) {
                case USART_Route::DEFAULT: return 0;
                case USART_Route::ALTERNATE: return 4;
                case USART_Route::NONE: break;
            } // switch
            break;
#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
        case Peripheral::USART3::ADDRESS:
            switch ( route ) {
                case USART_Route::DEFAULT: return 0;
                case USART_Route::ALTERNATE: return 4;
                case USART_Route::NONE: break;
            } // switch
            break;
#endif // defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
    }  // switch

    PICOLIBRARY_EXPECTATION_NOT_MET( Generic_Error::INVALID_ARGUMENT );
}

/**
 * \brief Lookup a USART peripheral's TXD pin number.
 *
 * \param[in] usart The USART peripheral whose TXD pin number is to be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's TXD pin number.
 */
inline auto txd_number( Peripheral::USART const & usart, USART_Route route ) noexcept -> std::uint_fast8_t
{
    return txd_number( reinterpret_cast<std::uintptr_t>( &usart ), route );
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
    return txd_number( usart, usart_route( usart ) );
}

/**
 * \brief Lookup a USART peripheral's TXD pin mask.
 *
 * \param[in] usart_address The address of the USART peripheral whose TXD pin mask is to
 *            be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's TXD pin mask.
 */
constexpr auto txd_mask( std::uintptr_t usart_address, USART_Route route ) noexcept -> std::uint8_t
{
    return 1 << txd_number( usart_address, route );
}

/**
 * \brief Lookup a USART peripheral's TXD pin mask.
 *
 * \param[in] usart The USART peripheral whose TXD pin mask is to be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's TXD pin mask.
 */
inline auto txd_mask( Peripheral::USART const & usart, USART_Route route ) noexcept -> std::uint8_t
{
    return txd_mask( reinterpret_cast<std::uintptr_t>( &usart ), route );
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
    return txd_mask( usart, usart_route( usart ) );
}

/**
 * \brief Lookup a USART peripheral's RXD pin PORT peripheral address.
 *
 * \param[in] usart_address The address of the USART peripheral whose RXD pin PORT
 *            peripheral address is to be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's RXD pin PORT peripheral address.
 */
constexpr auto rxd_port_address( std::uintptr_t usart_address, USART_Route route ) noexcept
    -> std::uintptr_t
{
    return usart_port_address( usart_address, route );
}

/**
 * \brief Lookup a USART peripheral's RXD pin PORT peripheral.
 *
 * \param[in] usart The USART peripheral whose RXD pin PORT peripheral is to be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's RXD pin PORT peripheral.
 */
inline auto rxd_port( Peripheral::USART const & usart, USART_Route route ) noexcept
    -> Peripheral::PORT &
{
    return usart_port( usart, route );
}

/**
 * \brief Lookup a USART peripheral's RXD pin PORT peripheral.
 *
 * \param[in] usart The USART peripheral whose RXD pin PORT peripheral is to be looked up.
 *
 * \return The USART peripheral's RXD pin PORT peripheral.
 */
inline auto rxd_port( Peripheral::USART const & usart ) noexcept -> Peripheral::PORT &
{
    return usart_port( usart );
}

/**
 * \brief Lookup a USART peripheral's RXD pin VPORT peripheral address.
 *
 * \param[in] usart_address The address of the USART peripheral whose RXD pin VPORT
 *            peripheral address is to be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's RXD pin VPORT peripheral address.
 */
constexpr auto rxd_vport_address( std::uintptr_t usart_address, USART_Route route ) noexcept
    -> std::uintptr_t
{
    return usart_vport_address( usart_address, route );
}

/**
 * \brief Lookup a USART peripheral's RXD pin VPORT peripheral.
 *
 * \param[in] usart The USART peripheral whose RXD pin VPORT peripheral is to be looked
 *            up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's RXD pin VPORT peripheral.
 */
inline auto rxd_vport( Peripheral::USART const & usart, USART_Route route ) noexcept
    -> Peripheral::VPORT &
{
    return usart_vport( usart, route );
}

/**
 * \brief Lookup a USART peripheral's RXD pin VPORT peripheral.
 *
 * \param[in] usart The USART peripheral whose RXD pin VPORT peripheral is to be looked
 *            up.
 *
 * \return The USART peripheral's RXD pin VPORT peripheral.
 */
inline auto rxd_vport( Peripheral::USART const & usart ) noexcept -> Peripheral::VPORT &
{
    return usart_vport( usart );
}

/**
 * \brief Lookup a USART peripheral's RXD pin number.
 *
 * \param[in] usart_address The address of the USART peripheral whose RXD pin number is to
 *            be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's RXD pin number.
 */
constexpr auto rxd_number( std::uintptr_t usart_address, USART_Route route ) noexcept -> std::uint_fast8_t
{
    // #lizard forgives the length

    switch ( usart_address ) {
        case Peripheral::USART0::ADDRESS:
            switch ( route ) {
                case USART_Route::DEFAULT: return 1;
                case USART_Route::ALTERNATE: return 5;
                case USART_Route::NONE: break;
            } // switch
            break;
        case Peripheral::USART1::ADDRESS:
            switch ( route ) {
                case USART_Route::DEFAULT: return 1;
                case USART_Route::ALTERNATE: return 5;
                case USART_Route::NONE: break;
            } // switch
            break;
        case Peripheral::USART2::ADDRESS:
            switch ( route ) {
                case USART_Route::DEFAULT: return 1;
                case USART_Route::ALTERNATE: return 5;
                case USART_Route::NONE: break;
            } // switch
            break;
#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
        case Peripheral::USART3::ADDRESS:
            switch ( route ) {
                case USART_Route::DEFAULT: return 1;
                case USART_Route::ALTERNATE: return 5;
                case USART_Route::NONE: break;
            } // switch
            break;
#endif // defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
    }  // switch

    PICOLIBRARY_EXPECTATION_NOT_MET( Generic_Error::INVALID_ARGUMENT );
}

/**
 * \brief Lookup a USART peripheral's RXD pin number.
 *
 * \param[in] usart The USART peripheral whose RXD pin number is to be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's RXD pin number.
 */
inline auto rxd_number( Peripheral::USART const & usart, USART_Route route ) noexcept -> std::uint_fast8_t
{
    return rxd_number( reinterpret_cast<std::uintptr_t>( &usart ), route );
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
    return rxd_number( usart, usart_route( usart ) );
}

/**
 * \brief Lookup a USART peripheral's RXD pin mask.
 *
 * \param[in] usart_address The address of the USART peripheral whose RXD pin mask is to
 *            be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's RXD pin mask.
 */
constexpr auto rxd_mask( std::uintptr_t usart_address, USART_Route route ) noexcept -> std::uint8_t
{
    return 1 << rxd_number( usart_address, route );
}

/**
 * \brief Lookup a USART peripheral's RXD pin mask.
 *
 * \param[in] usart The USART peripheral whose RXD pin mask is to be looked up.
 * \param[in] route The USART peripheral's routing configuration.
 *
 * \return The USART peripheral's RXD pin mask.
 */
inline auto rxd_mask( Peripheral::USART const & usart, USART_Route route ) noexcept -> std::uint8_t
{
    return rxd_mask( reinterpret_cast<std::uintptr_t>( &usart ), route );
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
    return rxd_mask( usart, usart_route( usart ) );
}

} // namespace picolibrary::Microchip::megaAVR0::Multiplexed_Signals

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_MULTIPLEXED_SIGNALS_USART_H
