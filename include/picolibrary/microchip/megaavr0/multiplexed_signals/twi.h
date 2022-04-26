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
 * \brief picolibrary::Microchip::megaAVR0::Multiplexed_Signals TWI interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_MULTIPLEXED_SIGNALS_TWI_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_MULTIPLEXED_SIGNALS_TWI_H

#include <cstdint>

#include "picolibrary/error.h"
#include "picolibrary/microchip/megaavr0/peripheral.h"
#include "picolibrary/microchip/megaavr0/peripheral/port.h"
#include "picolibrary/microchip/megaavr0/peripheral/portmux.h"
#include "picolibrary/microchip/megaavr0/peripheral/twi.h"
#include "picolibrary/microchip/megaavr0/peripheral/vport.h"
#include "picolibrary/precondition.h"
#include "picolibrary/utility.h"

namespace picolibrary::Microchip::megaAVR0::Multiplexed_Signals {

/**
 * \brief TWI peripheral routing configuration.
 */
enum class TWI_Route : std::uint8_t {
    DEFAULT     = Peripheral::PORTMUX::TWISPIROUTEA::TWI0_DEFAULT, ///< SCL/SDA on PA[3:2], client mode on PC[3:2] in dual TWI mode.
    ALTERNATE_1 = Peripheral::PORTMUX::TWISPIROUTEA::TWI0_ALT1, ///< SCL/SDA on PA[3:2], client mode on PF[3:2] in dual TWI mode.
    ALTERNATE_2 = Peripheral::PORTMUX::TWISPIROUTEA::TWI0_ALT2, ///< SCL/SDA on PC[3:2], client mode on PF[3:2] in dual TWI mode.
};

/**
 * \brief Get a TWI peripheral's routing configuration.
 *
 * \param[in] twi The TWI peripheral whose routing configuration is to be gotten.
 *
 * \return The TWI peripheral's routing configuration.
 */
inline auto twi_route( Peripheral::TWI const & twi ) noexcept -> TWI_Route
{
    auto const & portmux = Peripheral::PORTMUX0::instance();

    switch ( reinterpret_cast<std::uintptr_t>( &twi ) ) {
        case Peripheral::TWI0::ADDRESS:
            return static_cast<TWI_Route>(
                portmux.twispiroutea & Peripheral::PORTMUX::TWISPIROUTEA::Mask::TWI0 );
    } // switch

    expect( false, Generic_Error::INVALID_ARGUMENT );

    return TWI_Route::DEFAULT; // unreachable
}

/**
 * \brief Set a TWI peripheral's routing configuration.
 *
 * \param[in] twi The TWI peripheral whose routing configuration is to be set.
 * \param[in] route The desired TWI peripheral routing configuration.
 */
inline void set_twi_route( Peripheral::TWI const & twi, TWI_Route route ) noexcept
{
    auto & portmux = Peripheral::PORTMUX0::instance();

    switch ( reinterpret_cast<std::uintptr_t>( &twi ) ) {
        case Peripheral::TWI0::ADDRESS:
            portmux.twispiroutea = ( portmux.twispiroutea
                                     & ~Peripheral::PORTMUX::TWISPIROUTEA::Mask::TWI0 )
                                   | to_underlying( route );
            return;
    } // switch

    expect( false, Generic_Error::INVALID_ARGUMENT );
}

/**
 * \brief Lookup a TWI peripheral's SCL pin number.
 *
 * \param[in] twi_address The address of the TWI peripheral whose SCL pin number is to be
 *            looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's SCL pin number.
 */
constexpr auto scl_number( std::uintptr_t twi_address, TWI_Route route ) noexcept -> std::uint_fast8_t
{
    switch ( twi_address ) {
        case Peripheral::TWI0::ADDRESS:
            switch ( route ) {
                case TWI_Route::DEFAULT: return 3;
                case TWI_Route::ALTERNATE_1: return 3;
                case TWI_Route::ALTERNATE_2: return 3;
            } // switch
            break;
    } // switch

    expect( false, Generic_Error::INVALID_ARGUMENT );

    return 0; // unreachable
}

/**
 * \brief Lookup a TWI peripheral's SCL pin number.
 *
 * \param[in] twi The TWI peripheral whose SCL pin number is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's SCL pin number.
 */
inline auto scl_number( Peripheral::TWI const & twi, TWI_Route route ) noexcept -> std::uint_fast8_t
{
    return scl_number( reinterpret_cast<std::uintptr_t>( &twi ), route );
}

/**
 * \brief Lookup a TWI peripheral's SCL pin number.
 *
 * \param[in] twi The TWI peripheral whose SCL pin number is to be looked up.
 *
 * \return The TWI peripheral's SCL pin number.
 */
inline auto scl_number( Peripheral::TWI const & twi ) noexcept -> std::uint_fast8_t
{
    return scl_number( twi, twi_route( twi ) );
}

/**
 * \brief Lookup a TWI peripheral's SCL pin mask.
 *
 * \param[in] twi_address The address of the TWI peripheral whose SCL pin mask is to be
 *            looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's SCL pin mask.
 */
constexpr auto scl_mask( std::uintptr_t twi_address, TWI_Route route ) noexcept -> std::uint8_t
{
    return 1 << scl_number( twi_address, route );
}

/**
 * \brief Lookup a TWI peripheral's SCL pin mask.
 *
 * \param[in] twi The TWI peripheral whose SCL pin mask is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's SCL pin mask.
 */
inline auto scl_mask( Peripheral::TWI const & twi, TWI_Route route ) noexcept -> std::uint8_t
{
    return scl_mask( reinterpret_cast<std::uintptr_t>( &twi ), route );
}

/**
 * \brief Lookup a TWI peripheral's SCL pin mask.
 *
 * \param[in] twi The TWI peripheral whose SCL pin mask is to be looked up.
 *
 * \return The TWI peripheral's SCL pin mask.
 */
inline auto scl_mask( Peripheral::TWI const & twi ) noexcept -> std::uint8_t
{
    return scl_mask( twi, twi_route( twi ) );
}

/**
 * \brief Lookup a TWI peripheral's SDA pin number.
 *
 * \param[in] twi_address The address of the TWI peripheral whose SDA pin number is to be
 *            looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's SDA pin number.
 */
constexpr auto sda_number( std::uintptr_t twi_address, TWI_Route route ) noexcept -> std::uint_fast8_t
{
    switch ( twi_address ) {
        case Peripheral::TWI0::ADDRESS:
            switch ( route ) {
                case TWI_Route::DEFAULT: return 2;
                case TWI_Route::ALTERNATE_1: return 2;
                case TWI_Route::ALTERNATE_2: return 2;
            } // switch
            break;
    } // switch

    expect( false, Generic_Error::INVALID_ARGUMENT );

    return 0; // unreachable
}

/**
 * \brief Lookup a TWI peripheral's SDA pin number.
 *
 * \param[in] twi The TWI peripheral whose SDA pin number is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's SDA pin number.
 */
inline auto sda_number( Peripheral::TWI const & twi, TWI_Route route ) noexcept -> std::uint_fast8_t
{
    return sda_number( reinterpret_cast<std::uintptr_t>( &twi ), route );
}

/**
 * \brief Lookup a TWI peripheral's SDA pin number.
 *
 * \param[in] twi The TWI peripheral whose SDA pin number is to be looked up.
 *
 * \return The TWI peripheral's SDA pin number.
 */
inline auto sda_number( Peripheral::TWI const & twi ) noexcept -> std::uint_fast8_t
{
    return sda_number( twi, twi_route( twi ) );
}

/**
 * \brief Lookup a TWI peripheral's SDA pin mask.
 *
 * \param[in] twi_address The address of the TWI peripheral whose SDA pin mask is to be
 *            looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's SDA pin mask.
 */
constexpr auto sda_mask( std::uintptr_t twi_address, TWI_Route route ) noexcept -> std::uint8_t
{
    return 1 << sda_number( twi_address, route );
}

/**
 * \brief Lookup a TWI peripheral's SDA pin mask.
 *
 * \param[in] twi The TWI peripheral whose SDA pin mask is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's SDA pin mask.
 */
inline auto sda_mask( Peripheral::TWI const & twi, TWI_Route route ) noexcept -> std::uint8_t
{
    return sda_mask( reinterpret_cast<std::uintptr_t>( &twi ), route );
}

/**
 * \brief Lookup a TWI peripheral's SDA pin mask.
 *
 * \param[in] twi The TWI peripheral whose SDA pin mask is to be looked up.
 *
 * \return The TWI peripheral's SDA pin mask.
 */
inline auto sda_mask( Peripheral::TWI const & twi ) noexcept -> std::uint8_t
{
    return sda_mask( twi, twi_route( twi ) );
}

/**
 * \brief Lookup a TWI peripheral's controller pins PORT peripheral address.
 *
 * \param[in] twi_address The address of the TWI peripheral whose controller pins PORT
 *            peripheral address is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's controller pins PORT peripheral address.
 */
constexpr auto twi_controller_port_address( std::uintptr_t twi_address, TWI_Route route ) noexcept
    -> std::uintptr_t
{
    switch ( twi_address ) {
        case Peripheral::TWI0::ADDRESS:
            switch ( route ) {
                case TWI_Route::DEFAULT: return Peripheral::PORTA::ADDRESS;
                case TWI_Route::ALTERNATE_1: return Peripheral::PORTA::ADDRESS;
                case TWI_Route::ALTERNATE_2: return Peripheral::PORTC::ADDRESS;
            } // switch
            break;
    } // switch

    expect( false, Generic_Error::INVALID_ARGUMENT );

    return 0; // unreachable
}

/**
 * \brief Lookup a TWI peripheral's controller pins PORT peripheral.
 *
 * \param[in] twi The TWI peripheral whose controller pins PORT peripheral is to be looked
 *            up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's controller pins PORT peripheral.
 */
inline auto twi_controller_port( Peripheral::TWI const & twi, TWI_Route route ) noexcept
    -> Peripheral::PORT &
{
    return *reinterpret_cast<Peripheral::PORT *>(
        twi_controller_port_address( reinterpret_cast<std::uintptr_t>( &twi ), route ) );
}

/**
 * \brief Lookup a TWI peripheral's controller pins PORT peripheral.
 *
 * \param[in] twi The TWI peripheral whose controller pins PORT peripheral is to be looked
 *            up.
 *
 * \return The TWI peripheral's controller pins PORT peripheral.
 */
inline auto twi_controller_port( Peripheral::TWI const & twi ) noexcept -> Peripheral::PORT &
{
    return twi_controller_port( twi, twi_route( twi ) );
}

/**
 * \brief Lookup a TWI peripheral's controller pins VPORT peripheral address.
 *
 * \param[in] twi_address The address of the TWI peripheral whose controller pins VPORT
 *            peripheral address is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's controller pins VPORT peripheral address.
 */
constexpr auto twi_controller_vport_address( std::uintptr_t twi_address, TWI_Route route ) noexcept
    -> std::uintptr_t
{
    switch ( twi_address ) {
        case Peripheral::TWI0::ADDRESS:
            switch ( route ) {
                case TWI_Route::DEFAULT: return Peripheral::VPORTA::ADDRESS;
                case TWI_Route::ALTERNATE_1: return Peripheral::VPORTA::ADDRESS;
                case TWI_Route::ALTERNATE_2: return Peripheral::VPORTC::ADDRESS;
            } // switch
            break;
    } // switch

    expect( false, Generic_Error::INVALID_ARGUMENT );

    return 0; // unreachable
}

/**
 * \brief Lookup a TWI peripheral's controller pins VPORT peripheral.
 *
 * \param[in] twi The TWI peripheral whose controller pins VPORT peripheral is to be
 *            looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's controller pins VPORT peripheral.
 */
inline auto twi_controller_vport( Peripheral::TWI const & twi, TWI_Route route ) noexcept
    -> Peripheral::VPORT &
{
    return *reinterpret_cast<Peripheral::VPORT *>(
        twi_controller_vport_address( reinterpret_cast<std::uintptr_t>( &twi ), route ) );
}

/**
 * \brief Lookup a TWI peripheral's controller pins VPORT peripheral.
 *
 * \param[in] twi The TWI peripheral whose controller pins VPORT peripheral is to be
 *            looked up.
 *
 * \return The TWI peripheral's controller pins VPORT peripheral.
 */
inline auto twi_controller_vport( Peripheral::TWI const & twi ) noexcept -> Peripheral::VPORT &
{
    return twi_controller_vport( twi, twi_route( twi ) );
}

/**
 * \brief Lookup a TWI peripheral's controller SCL pin PORT peripheral address.
 *
 * \param[in] twi_address The address of the TWI peripheral whose controller SCL pin PORT
 *            peripheral address is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's controller SCL pin PORT peripheral address.
 */
constexpr auto controller_scl_port_address( std::uintptr_t twi_address, TWI_Route route ) noexcept
    -> std::uintptr_t
{
    return twi_controller_port_address( twi_address, route );
}

/**
 * \brief Lookup a TWI peripheral's controller SCL pin PORT peripheral.
 *
 * \param[in] twi The TWI peripheral whose controller SCL pin PORT peripheral is to be
 *            looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's controller SCL pin PORT peripheral.
 */
inline auto controller_scl_port( Peripheral::TWI const & twi, TWI_Route route ) noexcept
    -> Peripheral::PORT &
{
    return twi_controller_port( twi, route );
}

/**
 * \brief Lookup a TWI peripheral's controller SCL pin PORT peripheral.
 *
 * \param[in] twi The TWI peripheral whose controller SCL pin PORT peripheral is to be
 *            looked up.
 *
 * \return The TWI peripheral's controller SCL pin PORT peripheral.
 */
inline auto controller_scl_port( Peripheral::TWI const & twi ) noexcept -> Peripheral::PORT &
{
    return twi_controller_port( twi );
}

/**
 * \brief Lookup a TWI peripheral's controller SCL pin VPORT peripheral address.
 *
 * \param[in] twi_address The address of the TWI peripheral whose controller SCL pin VPORT
 *            peripheral address is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's controller SCL pin VPORT peripheral address.
 */
constexpr auto controller_scl_vport_address( std::uintptr_t twi_address, TWI_Route route ) noexcept
    -> std::uintptr_t
{
    return twi_controller_vport_address( twi_address, route );
}

/**
 * \brief Lookup a TWI peripheral's controller SCL pin VPORT peripheral.
 *
 * \param[in] twi The TWI peripheral whose controller SCL pin VPORT peripheral is to be
 *            looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's controller SCL pin VPORT peripheral.
 */
inline auto controller_scl_vport( Peripheral::TWI const & twi, TWI_Route route ) noexcept
    -> Peripheral::VPORT &
{
    return twi_controller_vport( twi, route );
}

/**
 * \brief Lookup a TWI peripheral's controller SCL pin VPORT peripheral.
 *
 * \param[in] twi The TWI peripheral whose controller SCL pin VPORT peripheral is to be
 *            looked up.
 *
 * \return The TWI peripheral's controller SCL pin VPORT peripheral.
 */
inline auto controller_scl_vport( Peripheral::TWI const & twi ) noexcept -> Peripheral::VPORT &
{
    return twi_controller_vport( twi );
}

/**
 * \brief Lookup a TWI peripheral's controller SCL pin number.
 *
 * \param[in] twi_address The address of the TWI peripheral whose controller SCL pin
 *            number is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's controller SCL pin number.
 */
constexpr auto controller_scl_number( std::uintptr_t twi_address, TWI_Route route ) noexcept
    -> std::uint_fast8_t
{
    return scl_number( twi_address, route );
}

/**
 * \brief Lookup a TWI peripheral's controller SCL pin number.
 *
 * \param[in] twi The TWI peripheral whose controller SCL pin number is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's controller SCL pin number.
 */
inline auto controller_scl_number( Peripheral::TWI const & twi, TWI_Route route ) noexcept
    -> std::uint_fast8_t
{
    return scl_number( twi, route );
}

/**
 * \brief Lookup a TWI peripheral's controller SCL pin number.
 *
 * \param[in] twi The TWI peripheral whose controller SCL pin number is to be looked up.
 *
 * \return The TWI peripheral's controller SCL pin number.
 */
inline auto controller_scl_number( Peripheral::TWI const & twi ) noexcept -> std::uint_fast8_t
{
    return scl_number( twi );
}

/**
 * \brief Lookup a TWI peripheral's controller SCL pin mask.
 *
 * \param[in] twi_address The address of the TWI peripheral whose controller SCL pin mask
 *            is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's controller SCL pin mask.
 */
constexpr auto controller_scl_mask( std::uintptr_t twi_address, TWI_Route route ) noexcept -> std::uint8_t
{
    return scl_mask( twi_address, route );
}

/**
 * \brief Lookup a TWI peripheral's controller SCL pin mask.
 *
 * \param[in] twi The TWI peripheral whose controller SCL pin mask is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's controller SCL pin mask.
 */
inline auto controller_scl_mask( Peripheral::TWI const & twi, TWI_Route route ) noexcept -> std::uint8_t
{
    return scl_mask( twi, route );
}

/**
 * \brief Lookup a TWI peripheral's controller SCL pin mask.
 *
 * \param[in] twi The TWI peripheral whose controller SCL pin mask is to be looked up.
 *
 * \return The TWI peripheral's controller SCL pin mask.
 */
inline auto controller_scl_mask( Peripheral::TWI const & twi ) noexcept -> std::uint8_t
{
    return scl_mask( twi );
}

/**
 * \brief Lookup a TWI peripheral's controller SDA pin PORT peripheral address.
 *
 * \param[in] twi_address The address of the TWI peripheral whose controller SDA pin PORT
 *            peripheral address is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's controller SDA pin PORT peripheral address.
 */
constexpr auto controller_sda_port_address( std::uintptr_t twi_address, TWI_Route route ) noexcept
    -> std::uintptr_t
{
    return twi_controller_port_address( twi_address, route );
}

/**
 * \brief Lookup a TWI peripheral's controller SDA pin PORT peripheral.
 *
 * \param[in] twi The TWI peripheral whose controller SDA pin PORT peripheral is to be
 *            looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's controller SDA pin PORT peripheral.
 */
inline auto controller_sda_port( Peripheral::TWI const & twi, TWI_Route route ) noexcept
    -> Peripheral::PORT &
{
    return twi_controller_port( twi, route );
}

/**
 * \brief Lookup a TWI peripheral's controller SDA pin PORT peripheral.
 *
 * \param[in] twi The TWI peripheral whose controller SDA pin PORT peripheral is to be
 *            looked up.
 *
 * \return The TWI peripheral's controller SDA pin PORT peripheral.
 */
inline auto controller_sda_port( Peripheral::TWI const & twi ) noexcept -> Peripheral::PORT &
{
    return twi_controller_port( twi );
}

/**
 * \brief Lookup a TWI peripheral's controller SDA pin VPORT peripheral address.
 *
 * \param[in] twi_address The address of the TWI peripheral whose controller SDA pin VPORT
 *            peripheral address is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's controller SDA pin VPORT peripheral address.
 */
constexpr auto controller_sda_vport_address( std::uintptr_t twi_address, TWI_Route route ) noexcept
    -> std::uintptr_t
{
    return twi_controller_vport_address( twi_address, route );
}

/**
 * \brief Lookup a TWI peripheral's controller SDA pin VPORT peripheral.
 *
 * \param[in] twi The TWI peripheral whose controller SDA pin VPORT peripheral is to be
 *            looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's controller SDA pin VPORT peripheral.
 */
inline auto controller_sda_vport( Peripheral::TWI const & twi, TWI_Route route ) noexcept
    -> Peripheral::VPORT &
{
    return twi_controller_vport( twi, route );
}

/**
 * \brief Lookup a TWI peripheral's controller SDA pin VPORT peripheral.
 *
 * \param[in] twi The TWI peripheral whose controller SDA pin VPORT peripheral is to be
 *            looked up.
 *
 * \return The TWI peripheral's controller SDA pin VPORT peripheral.
 */
inline auto controller_sda_vport( Peripheral::TWI const & twi ) noexcept -> Peripheral::VPORT &
{
    return twi_controller_vport( twi );
}

/**
 * \brief Lookup a TWI peripheral's controller SDA pin number.
 *
 * \param[in] twi_address The address of the TWI peripheral whose controller SDA pin
 *            number is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's controller SDA pin number.
 */
constexpr auto controller_sda_number( std::uintptr_t twi_address, TWI_Route route ) noexcept
    -> std::uint_fast8_t
{
    return sda_number( twi_address, route );
}

/**
 * \brief Lookup a TWI peripheral's controller SDA pin number.
 *
 * \param[in] twi The TWI peripheral whose controller SDA pin number is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's controller SDA pin number.
 */
inline auto controller_sda_number( Peripheral::TWI const & twi, TWI_Route route ) noexcept
    -> std::uint_fast8_t
{
    return sda_number( twi, route );
}

/**
 * \brief Lookup a TWI peripheral's controller SDA pin number.
 *
 * \param[in] twi The TWI peripheral whose controller SDA pin number is to be looked up.
 *
 * \return The TWI peripheral's controller SDA pin number.
 */
inline auto controller_sda_number( Peripheral::TWI const & twi ) noexcept -> std::uint_fast8_t
{
    return sda_number( twi );
}

/**
 * \brief Lookup a TWI peripheral's controller SDA pin mask.
 *
 * \param[in] twi_address The address of the TWI peripheral whose controller SDA pin mask
 *            is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's controller SDA pin mask.
 */
constexpr auto controller_sda_mask( std::uintptr_t twi_address, TWI_Route route ) noexcept -> std::uint8_t
{
    return sda_mask( twi_address, route );
}

/**
 * \brief Lookup a TWI peripheral's controller SDA pin mask.
 *
 * \param[in] twi The TWI peripheral whose controller SDA pin mask is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's controller SDA pin mask.
 */
inline auto controller_sda_mask( Peripheral::TWI const & twi, TWI_Route route ) noexcept -> std::uint8_t
{
    return sda_mask( twi, route );
}

/**
 * \brief Lookup a TWI peripheral's controller SDA pin mask.
 *
 * \param[in] twi The TWI peripheral whose controller SDA pin mask is to be looked up.
 *
 * \return The TWI peripheral's controller SDA pin mask.
 */
inline auto controller_sda_mask( Peripheral::TWI const & twi ) noexcept -> std::uint8_t
{
    return sda_mask( twi );
}

/**
 * \brief Lookup a TWI peripheral's device pins PORT peripheral address.
 *
 * \param[in] twi_address The address of the TWI peripheral whose device pins PORT
 *            peripheral address is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's device pins PORT peripheral address.
 */
constexpr auto twi_device_port_address( std::uintptr_t twi_address, TWI_Route route ) noexcept
    -> std::uintptr_t
{
    switch ( twi_address ) {
        case Peripheral::TWI0::ADDRESS:
            switch ( route ) {
                case TWI_Route::DEFAULT: return Peripheral::PORTC::ADDRESS;
                case TWI_Route::ALTERNATE_1: return Peripheral::PORTF::ADDRESS;
                case TWI_Route::ALTERNATE_2: return Peripheral::PORTF::ADDRESS;
            } // switch
            break;
    } // switch

    expect( false, Generic_Error::INVALID_ARGUMENT );

    return 0; // unreachable
}

/**
 * \brief Lookup a TWI peripheral's device pins PORT peripheral.
 *
 * \param[in] twi The TWI peripheral whose device pins PORT peripheral is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's device pins PORT peripheral.
 */
inline auto twi_device_port( Peripheral::TWI const & twi, TWI_Route route ) noexcept
    -> Peripheral::PORT &
{
    return *reinterpret_cast<Peripheral::PORT *>(
        twi_device_port_address( reinterpret_cast<std::uintptr_t>( &twi ), route ) );
}

/**
 * \brief Lookup a TWI peripheral's device pins PORT peripheral.
 *
 * \param[in] twi The TWI peripheral whose device pins PORT peripheral is to be looked up.
 *
 * \return The TWI peripheral's device pins PORT peripheral.
 */
inline auto twi_device_port( Peripheral::TWI const & twi ) noexcept -> Peripheral::PORT &
{
    return twi_device_port( twi, twi_route( twi ) );
}

/**
 * \brief Lookup a TWI peripheral's device pins VPORT peripheral address.
 *
 * \param[in] twi_address The address of the TWI peripheral whose device pins VPORT
 *            peripheral address is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's device pins VPORT peripheral address.
 */
constexpr auto twi_device_vport_address( std::uintptr_t twi_address, TWI_Route route ) noexcept
    -> std::uintptr_t
{
    switch ( twi_address ) {
        case Peripheral::TWI0::ADDRESS:
            switch ( route ) {
                case TWI_Route::DEFAULT: return Peripheral::VPORTC::ADDRESS;
                case TWI_Route::ALTERNATE_1: return Peripheral::VPORTF::ADDRESS;
                case TWI_Route::ALTERNATE_2: return Peripheral::VPORTF::ADDRESS;
            } // switch
            break;
    } // switch

    expect( false, Generic_Error::INVALID_ARGUMENT );

    return 0; // unreachable
}

/**
 * \brief Lookup a TWI peripheral's device pins VPORT peripheral.
 *
 * \param[in] twi The TWI peripheral whose device pins VPORT peripheral is to be looked
 *            up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's device pins VPORT peripheral.
 */
inline auto twi_device_vport( Peripheral::TWI const & twi, TWI_Route route ) noexcept
    -> Peripheral::VPORT &
{
    return *reinterpret_cast<Peripheral::VPORT *>(
        twi_device_vport_address( reinterpret_cast<std::uintptr_t>( &twi ), route ) );
}

/**
 * \brief Lookup a TWI peripheral's device pins VPORT peripheral.
 *
 * \param[in] twi The TWI peripheral whose device pins VPORT peripheral is to be looked
 *            up.
 *
 * \return The TWI peripheral's device pins VPORT peripheral.
 */
inline auto twi_device_vport( Peripheral::TWI const & twi ) noexcept -> Peripheral::VPORT &
{
    return twi_device_vport( twi, twi_route( twi ) );
}

/**
 * \brief Lookup a TWI peripheral's device SCL pin PORT peripheral address.
 *
 * \param[in] twi_address The address of the TWI peripheral whose device SCL pin PORT
 *            peripheral address is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's device SCL pin PORT peripheral address.
 */
constexpr auto device_scl_port_address( std::uintptr_t twi_address, TWI_Route route ) noexcept
    -> std::uintptr_t
{
    return twi_device_port_address( twi_address, route );
}

/**
 * \brief Lookup a TWI peripheral's device SCL pin PORT peripheral.
 *
 * \param[in] twi The TWI peripheral whose device SCL pin PORT peripheral is to be looked
 *            up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's device SCL pin PORT peripheral.
 */
inline auto device_scl_port( Peripheral::TWI const & twi, TWI_Route route ) noexcept
    -> Peripheral::PORT &
{
    return twi_device_port( twi, route );
}

/**
 * \brief Lookup a TWI peripheral's device SCL pin PORT peripheral.
 *
 * \param[in] twi The TWI peripheral whose device SCL pin PORT peripheral is to be looked
 *            up.
 *
 * \return The TWI peripheral's device SCL pin PORT peripheral.
 */
inline auto device_scl_port( Peripheral::TWI const & twi ) noexcept -> Peripheral::PORT &
{
    return twi_device_port( twi );
}

/**
 * \brief Lookup a TWI peripheral's device SCL pin VPORT peripheral address.
 *
 * \param[in] twi_address The address of the TWI peripheral whose device SCL pin VPORT
 *            peripheral address is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's device SCL pin VPORT peripheral address.
 */
constexpr auto device_scl_vport_address( std::uintptr_t twi_address, TWI_Route route ) noexcept
    -> std::uintptr_t
{
    return twi_device_vport_address( twi_address, route );
}

/**
 * \brief Lookup a TWI peripheral's device SCL pin VPORT peripheral.
 *
 * \param[in] twi The TWI peripheral whose device SCL pin VPORT peripheral is to be looked
 *            up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's device SCL pin VPORT peripheral.
 */
inline auto device_scl_vport( Peripheral::TWI const & twi, TWI_Route route ) noexcept
    -> Peripheral::VPORT &
{
    return twi_device_vport( twi, route );
}

/**
 * \brief Lookup a TWI peripheral's device SCL pin VPORT peripheral.
 *
 * \param[in] twi The TWI peripheral whose device SCL pin VPORT peripheral is to be looked
 *            up.
 *
 * \return The TWI peripheral's device SCL pin VPORT peripheral.
 */
inline auto device_scl_vport( Peripheral::TWI const & twi ) noexcept -> Peripheral::VPORT &
{
    return twi_device_vport( twi );
}

/**
 * \brief Lookup a TWI peripheral's device SCL pin number.
 *
 * \param[in] twi_address The address of the TWI peripheral whose device SCL pin number is
 *            to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's device SCL pin number.
 */
constexpr auto device_scl_number( std::uintptr_t twi_address, TWI_Route route ) noexcept -> std::uint_fast8_t
{
    return scl_number( twi_address, route );
}

/**
 * \brief Lookup a TWI peripheral's device SCL pin number.
 *
 * \param[in] twi The TWI peripheral whose device SCL pin number is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's device SCL pin number.
 */
inline auto device_scl_number( Peripheral::TWI const & twi, TWI_Route route ) noexcept -> std::uint_fast8_t
{
    return scl_number( twi, route );
}

/**
 * \brief Lookup a TWI peripheral's device SCL pin number.
 *
 * \param[in] twi The TWI peripheral whose device SCL pin number is to be looked up.
 *
 * \return The TWI peripheral's device SCL pin number.
 */
inline auto device_scl_number( Peripheral::TWI const & twi ) noexcept -> std::uint_fast8_t
{
    return scl_number( twi );
}

/**
 * \brief Lookup a TWI peripheral's device SCL pin mask.
 *
 * \param[in] twi_address The address of the TWI peripheral whose device SCL pin mask is
 *            to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's device SCL pin mask.
 */
constexpr auto device_scl_mask( std::uintptr_t twi_address, TWI_Route route ) noexcept -> std::uint8_t
{
    return scl_mask( twi_address, route );
}

/**
 * \brief Lookup a TWI peripheral's device SCL pin mask.
 *
 * \param[in] twi The TWI peripheral whose device SCL pin mask is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's device SCL pin mask.
 */
inline auto device_scl_mask( Peripheral::TWI const & twi, TWI_Route route ) noexcept -> std::uint8_t
{
    return scl_mask( twi, route );
}

/**
 * \brief Lookup a TWI peripheral's device SCL pin mask.
 *
 * \param[in] twi The TWI peripheral whose device SCL pin mask is to be looked up.
 *
 * \return The TWI peripheral's device SCL pin mask.
 */
inline auto device_scl_mask( Peripheral::TWI const & twi ) noexcept -> std::uint8_t
{
    return scl_mask( twi );
}

/**
 * \brief Lookup a TWI peripheral's device SDA pin PORT peripheral address.
 *
 * \param[in] twi_address The address of the TWI peripheral whose device SDA pin PORT
 *            peripheral address is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's device SDA pin PORT peripheral address.
 */
constexpr auto device_sda_port_address( std::uintptr_t twi_address, TWI_Route route ) noexcept
    -> std::uintptr_t
{
    return twi_device_port_address( twi_address, route );
}

/**
 * \brief Lookup a TWI peripheral's device SDA pin PORT peripheral.
 *
 * \param[in] twi The TWI peripheral whose device SDA pin PORT peripheral is to be looked
 *            up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's device SDA pin PORT peripheral.
 */
inline auto device_sda_port( Peripheral::TWI const & twi, TWI_Route route ) noexcept
    -> Peripheral::PORT &
{
    return twi_device_port( twi, route );
}

/**
 * \brief Lookup a TWI peripheral's device SDA pin PORT peripheral.
 *
 * \param[in] twi The TWI peripheral whose device SDA pin PORT peripheral is to be looked
 *            up.
 *
 * \return The TWI peripheral's device SDA pin PORT peripheral.
 */
inline auto device_sda_port( Peripheral::TWI const & twi ) noexcept -> Peripheral::PORT &
{
    return twi_device_port( twi );
}

/**
 * \brief Lookup a TWI peripheral's device SDA pin VPORT peripheral address.
 *
 * \param[in] twi_address The address of the TWI peripheral whose device SDA pin VPORT
 *            peripheral address is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's device SDA pin VPORT peripheral address.
 */
constexpr auto device_sda_vport_address( std::uintptr_t twi_address, TWI_Route route ) noexcept
    -> std::uintptr_t
{
    return twi_device_vport_address( twi_address, route );
}

/**
 * \brief Lookup a TWI peripheral's device SDA pin VPORT peripheral.
 *
 * \param[in] twi The TWI peripheral whose device SDA pin VPORT peripheral is to be looked
 *            up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's device SDA pin VPORT peripheral.
 */
inline auto device_sda_vport( Peripheral::TWI const & twi, TWI_Route route ) noexcept
    -> Peripheral::VPORT &
{
    return twi_device_vport( twi, route );
}

/**
 * \brief Lookup a TWI peripheral's device SDA pin VPORT peripheral.
 *
 * \param[in] twi The TWI peripheral whose device SDA pin VPORT peripheral is to be looked
 *            up.
 *
 * \return The TWI peripheral's device SDA pin VPORT peripheral.
 */
inline auto device_sda_vport( Peripheral::TWI const & twi ) noexcept -> Peripheral::VPORT &
{
    return twi_device_vport( twi );
}

/**
 * \brief Lookup a TWI peripheral's device SDA pin number.
 *
 * \param[in] twi_address The address of the TWI peripheral whose device SDA pin number is
 *            to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's device SDA pin number.
 */
constexpr auto device_sda_number( std::uintptr_t twi_address, TWI_Route route ) noexcept -> std::uint_fast8_t
{
    return sda_number( twi_address, route );
}

/**
 * \brief Lookup a TWI peripheral's device SDA pin number.
 *
 * \param[in] twi The TWI peripheral whose device SDA pin number is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's device SDA pin number.
 */
inline auto device_sda_number( Peripheral::TWI const & twi, TWI_Route route ) noexcept -> std::uint_fast8_t
{
    return sda_number( twi, route );
}

/**
 * \brief Lookup a TWI peripheral's device SDA pin number.
 *
 * \param[in] twi The TWI peripheral whose device SDA pin number is to be looked up.
 *
 * \return The TWI peripheral's device SDA pin number.
 */
inline auto device_sda_number( Peripheral::TWI const & twi ) noexcept -> std::uint_fast8_t
{
    return sda_number( twi );
}

/**
 * \brief Lookup a TWI peripheral's device SDA pin mask.
 *
 * \param[in] twi_address The address of the TWI peripheral whose device SDA pin mask is
 *            to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's device SDA pin mask.
 */
constexpr auto device_sda_mask( std::uintptr_t twi_address, TWI_Route route ) noexcept -> std::uint8_t
{
    return sda_mask( twi_address, route );
}

/**
 * \brief Lookup a TWI peripheral's device SDA pin mask.
 *
 * \param[in] twi The TWI peripheral whose device SDA pin mask is to be looked up.
 * \param[in] route The TWI peripheral's routing configuration.
 *
 * \return The TWI peripheral's device SDA pin mask.
 */
inline auto device_sda_mask( Peripheral::TWI const & twi, TWI_Route route ) noexcept -> std::uint8_t
{
    return sda_mask( twi, route );
}

/**
 * \brief Lookup a TWI peripheral's device SDA pin mask.
 *
 * \param[in] twi The TWI peripheral whose device SDA pin mask is to be looked up.
 *
 * \return The TWI peripheral's device SDA pin mask.
 */
inline auto device_sda_mask( Peripheral::TWI const & twi ) noexcept -> std::uint8_t
{
    return sda_mask( twi );
}

} // namespace picolibrary::Microchip::megaAVR0::Multiplexed_Signals

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_MULTIPLEXED_SIGNALS_TWI_H
