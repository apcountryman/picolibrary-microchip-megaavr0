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
 * \brief picolibrary::Microchip::megaAVR0::Multiplexed_Signals SPI interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_MULTIPLEXED_SIGNALS_SPI_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_MULTIPLEXED_SIGNALS_SPI_H

#include <cstdint>

#include "picolibrary/error.h"
#include "picolibrary/microchip/megaavr0/peripheral.h"
#include "picolibrary/microchip/megaavr0/peripheral/port.h"
#include "picolibrary/microchip/megaavr0/peripheral/portmux.h"
#include "picolibrary/microchip/megaavr0/peripheral/spi.h"
#include "picolibrary/microchip/megaavr0/peripheral/vport.h"
#include "picolibrary/precondition.h"
#include "picolibrary/utility.h"

namespace picolibrary::Microchip::megaAVR0::Multiplexed_Signals {

/**
 * \brief SPI peripheral routing configuration.
 */
enum class SPI_Route : std::uint8_t {
    DEFAULT     = Peripheral::PORTMUX::TWISPIROUTEA::SPI0_DEFAULT, ///< Default route (SPI on PA[7:4]).
    ALTERNATE_1 = Peripheral::PORTMUX::TWISPIROUTEA::SPI0_ALT1, ///< Alternate route 1 (SPI on PC[3:0]).
#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
    ALTERNATE_2 = Peripheral::PORTMUX::TWISPIROUTEA::SPI0_ALT2, ///< Alternate route 2 (SPI on PE[3:0]).
#endif // defined ( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
    NONE = Peripheral::PORTMUX::TWISPIROUTEA::SPI0_NONE, ///< Not routed.
};

/**
 * \brief Get an SPI peripheral's routing configuration.
 *
 * \param[in] spi The SPI peripheral whose routing configuration is to be gotten.
 *
 * \return The SPI peripheral's routing configuration.
 */
inline auto spi_route( Peripheral::SPI const & spi ) noexcept -> SPI_Route
{
    auto const & portmux = Peripheral::PORTMUX0::instance();

    switch ( reinterpret_cast<std::uintptr_t>( &spi ) ) {
        case Peripheral::SPI0::ADDRESS:
            return static_cast<SPI_Route>(
                portmux.twispiroutea & Peripheral::PORTMUX::TWISPIROUTEA::Mask::SPI0 );
    } // switch

    expect( false, Generic_Error::INVALID_ARGUMENT );

    return SPI_Route::NONE; // unreachable
}

/**
 * \brief Set an SPI peripheral's routing configuration.
 *
 * \param[in] spi The SPI peripheral whose routing configuration is to be set.
 * \param[in] route The desired SPI peripheral routing configuration.
 */
inline void set_spi_route( Peripheral::SPI const & spi, SPI_Route route ) noexcept
{
    auto & portmux = Peripheral::PORTMUX0::instance();

    switch ( reinterpret_cast<std::uintptr_t>( &spi ) ) {
        case Peripheral::SPI0::ADDRESS:
            portmux.twispiroutea = ( portmux.twispiroutea
                                     & ~Peripheral::PORTMUX::TWISPIROUTEA::Mask::SPI0 )
                                   | to_underlying( route );
            return;
    } // switch

    expect( false, Generic_Error::INVALID_ARGUMENT );
}

/**
 * \brief Lookup an SPI peripheral's pins PORT peripheral address.
 *
 * \param[in] spi_address The address of the SPI peripheral whose pins PORT peripheral
 *            address is to be looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's pins PORT peripheral address.
 */
constexpr auto spi_port_address( std::uintptr_t spi_address, SPI_Route route ) noexcept -> std::uintptr_t
{
    switch ( spi_address ) {
        case Peripheral::SPI0::ADDRESS:
            switch ( route ) {
                case SPI_Route::DEFAULT: return Peripheral::PORTA::ADDRESS;
                case SPI_Route::ALTERNATE_1: return Peripheral::PORTC::ADDRESS;
#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
                case SPI_Route::ALTERNATE_2: return Peripheral::PORTE::ADDRESS;
#endif // defined ( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
                case SPI_Route::NONE: break;
            } // switch
            break;
    };

    expect( false, Generic_Error::INVALID_ARGUMENT );

    return 0; // unreachable
}

/**
 * \brief Lookup an SPI peripheral's pins PORT peripheral.
 *
 * \param[in] spi The SPI peripheral whose pins PORT peripheral is to be looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's pins PORT peripheral.
 */
inline auto & spi_port( Peripheral::SPI const & spi, SPI_Route route ) noexcept
{
    return *reinterpret_cast<Peripheral::PORT *>(
        spi_port_address( reinterpret_cast<std::uintptr_t>( &spi ), route ) );
}

/**
 * \brief Lookup an SPI peripheral's pins PORT peripheral.
 *
 * \param[in] spi The SPI peripheral whose pins PORT peripheral is to be looked up.
 *
 * \return The SPI peripheral's pins PORT peripheral.
 */
inline auto & spi_port( Peripheral::SPI const & spi ) noexcept
{
    return spi_port( spi, spi_route( spi ) );
}

/**
 * \brief Lookup an SPI peripheral's pins VPORT peripheral address.
 *
 * \param[in] spi_address The address of the SPI peripheral whose pins VPORT peripheral
 *            address is to be looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's pins VPORT peripheral address.
 */
constexpr auto spi_vport_address( std::uintptr_t spi_address, SPI_Route route ) noexcept -> std::uintptr_t
{
    switch ( spi_address ) {
        case Peripheral::SPI0::ADDRESS:
            switch ( route ) {
                case SPI_Route::DEFAULT: return Peripheral::VPORTA::ADDRESS;
                case SPI_Route::ALTERNATE_1: return Peripheral::VPORTC::ADDRESS;
#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
                case SPI_Route::ALTERNATE_2: return Peripheral::VPORTE::ADDRESS;
#endif // defined ( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
                case SPI_Route::NONE: break;
            } // switch
            break;
    };

    expect( false, Generic_Error::INVALID_ARGUMENT );

    return 0; // unreachable
}

/**
 * \brief Lookup an SPI peripheral's pins VPORT peripheral.
 *
 * \param[in] spi The SPI peripheral whose pins VPORT peripheral is to be looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's pins VPORT peripheral.
 */
inline auto & spi_vport( Peripheral::SPI const & spi, SPI_Route route ) noexcept
{
    return *reinterpret_cast<Peripheral::VPORT *>(
        spi_vport_address( reinterpret_cast<std::uintptr_t>( &spi ), route ) );
}

/**
 * \brief Lookup an SPI peripheral's pins VPORT peripheral.
 *
 * \param[in] spi The SPI peripheral whose pins VPORT peripheral is to be looked up.
 *
 * \return The SPI peripheral's pins VPORT peripheral.
 */
inline auto & spi_vport( Peripheral::SPI const & spi ) noexcept
{
    return spi_vport( spi, spi_route( spi ) );
}

/**
 * \brief Lookup an SPI peripheral's SS pin PORT peripheral address.
 *
 * \param[in] spi_address The address of the SPI peripheral whose SS pin PORT peripheral
 *            address is to be looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's SS pin PORT peripheral address.
 */
constexpr auto ss_port_address( std::uintptr_t spi_address, SPI_Route route ) noexcept
{
    return spi_port_address( spi_address, route );
}

/**
 * \brief Lookup an SPI peripheral's SS pin PORT peripheral.
 *
 * \param[in] spi The SPI peripheral whose SS pin PORT peripheral is to be looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's SS pin PORT peripheral.
 */
inline auto & ss_port( Peripheral::SPI const & spi, SPI_Route route ) noexcept
{
    return spi_port( spi, route );
}

/**
 * \brief Lookup an SPI peripheral's SS pin PORT peripheral.
 *
 * \param[in] spi The SPI peripheral whose SS pin PORT peripheral is to be looked up.
 *
 * \return The SPI peripheral's SS pin PORT peripheral.
 */
inline auto & ss_port( Peripheral::SPI const & spi ) noexcept
{
    return spi_port( spi );
}

/**
 * \brief Lookup an SPI peripheral's SS pin VPORT peripheral address.
 *
 * \param[in] spi_address The address of the SPI peripheral whose SS pin VPORT peripheral
 *            address is to be looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's SS pin VPORT peripheral address.
 */
constexpr auto ss_vport_address( std::uintptr_t spi_address, SPI_Route route ) noexcept
{
    return spi_vport_address( spi_address, route );
}

/**
 * \brief Lookup an SPI peripheral's SS pin VPORT peripheral.
 *
 * \param[in] spi The SPI peripheral whose SS pin VPORT peripheral is to be looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's SS pin VPORT peripheral.
 */
inline auto & ss_vport( Peripheral::SPI const & spi, SPI_Route route ) noexcept
{
    return spi_vport( spi, route );
}

/**
 * \brief Lookup an SPI peripheral's SS pin VPORT peripheral.
 *
 * \param[in] spi The SPI peripheral whose SS pin VPORT peripheral is to be looked up.
 *
 * \return The SPI peripheral's SS pin VPORT peripheral.
 */
inline auto & ss_vport( Peripheral::SPI const & spi ) noexcept
{
    return spi_vport( spi );
}

/**
 * \brief Lookup an SPI peripheral's SS pin number.
 *
 * \param[in] spi_address The address of the SPI peripheral whose SS pin number is to be
 *            looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's SS pin number.
 */
constexpr auto ss_number( std::uintptr_t spi_address, SPI_Route route ) noexcept -> std::uint_fast8_t
{
    switch ( spi_address ) {
        case Peripheral::SPI0::ADDRESS:
            switch ( route ) {
                case SPI_Route::DEFAULT: return 7;
                case SPI_Route::ALTERNATE_1: return 3;
#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
                case SPI_Route::ALTERNATE_2: return 3;
#endif // defined ( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
                case SPI_Route::NONE: break;
            } // switch
            break;
    } // switch

    expect( false, Generic_Error::INVALID_ARGUMENT );

    return 0; // unreachable
}

/**
 * \brief Lookup an SPI peripheral's SS pin number.
 *
 * \param[in] spi The SPI peripheral whose SS pin number is to be looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's SS pin number.
 */
inline auto ss_number( Peripheral::SPI const & spi, SPI_Route route ) noexcept
{
    return ss_number( reinterpret_cast<std::uintptr_t>( &spi ), route );
}

/**
 * \brief Lookup an SPI peripheral's SS pin number.
 *
 * \param[in] spi The SPI peripheral whose SS pin number is to be looked up.
 *
 * \return The SPI peripheral's SS pin number.
 */
inline auto ss_number( Peripheral::SPI const & spi ) noexcept
{
    return ss_number( spi, spi_route( spi ) );
}

/**
 * \brief Lookup an SPI peripheral's SS pin mask.
 *
 * \param[in] spi_address The address of the SPI peripheral whose SS pin mask is to be
 *            looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's SS pin mask.
 */
constexpr auto ss_mask( std::uintptr_t spi_address, SPI_Route route ) noexcept -> std::uint8_t
{
    return 1 << ss_number( spi_address, route );
}

/**
 * \brief Lookup an SPI peripheral's SS pin mask.
 *
 * \param[in] spi The SPI peripheral whose SS pin mask is to be looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's SS pin mask.
 */
inline auto ss_mask( Peripheral::SPI const & spi, SPI_Route route ) noexcept
{
    return ss_mask( reinterpret_cast<std::uintptr_t>( &spi ), route );
}

/**
 * \brief Lookup an SPI peripheral's SS pin mask.
 *
 * \param[in] spi The SPI peripheral whose SS pin mask is to be looked up.
 *
 * \return The SPI peripheral's SS pin mask.
 */
inline auto ss_mask( Peripheral::SPI const & spi ) noexcept
{
    return ss_mask( spi, spi_route( spi ) );
}

/**
 * \brief Lookup an SPI peripheral's SCK pin PORT peripheral address.
 *
 * \param[in] spi_address The address of the SPI peripheral whose SCK pin PORT peripheral
 *            address is to be looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's SCK pin PORT peripheral address.
 */
constexpr auto sck_port_address( std::uintptr_t spi_address, SPI_Route route ) noexcept
{
    return spi_port_address( spi_address, route );
}

/**
 * \brief Lookup an SPI peripheral's SCK pin PORT peripheral.
 *
 * \param[in] spi The SPI peripheral whose SCK pin PORT peripheral is to be looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's SCK pin PORT peripheral.
 */
inline auto & sck_port( Peripheral::SPI const & spi, SPI_Route route ) noexcept
{
    return spi_port( spi, route );
}

/**
 * \brief Lookup an SPI peripheral's SCK pin PORT peripheral.
 *
 * \param[in] spi The SPI peripheral whose SCK pin PORT peripheral is to be looked up.
 *
 * \return The SPI peripheral's SCK pin PORT peripheral.
 */
inline auto & sck_port( Peripheral::SPI const & spi ) noexcept
{
    return spi_port( spi );
}

/**
 * \brief Lookup an SPI peripheral's SCK pin VPORT peripheral address.
 *
 * \param[in] spi_address The address of the SPI peripheral whose SCK pin VPORT peripheral
 *            address is to be looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's SCK pin VPORT peripheral address.
 */
constexpr auto sck_vport_address( std::uintptr_t spi_address, SPI_Route route ) noexcept
{
    return spi_vport_address( spi_address, route );
}

/**
 * \brief Lookup an SPI peripheral's SCK pin VPORT peripheral.
 *
 * \param[in] spi The SPI peripheral whose SCK pin VPORT peripheral is to be looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's SCK pin VPORT peripheral.
 */
inline auto & sck_vport( Peripheral::SPI const & spi, SPI_Route route ) noexcept
{
    return spi_vport( spi, route );
}

/**
 * \brief Lookup an SPI peripheral's SCK pin VPORT peripheral.
 *
 * \param[in] spi The SPI peripheral whose SCK pin VPORT peripheral is to be looked up.
 *
 * \return The SPI peripheral's SCK pin VPORT peripheral.
 */
inline auto & sck_vport( Peripheral::SPI const & spi ) noexcept
{
    return spi_vport( spi );
}

/**
 * \brief Lookup an SPI peripheral's SCK pin number.
 *
 * \param[in] spi_address The address of the SPI peripheral whose SCK pin number is to be
 *            looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's SCK pin number.
 */
constexpr auto sck_number( std::uintptr_t spi_address, SPI_Route route ) noexcept -> std::uint_fast8_t
{
    switch ( spi_address ) {
        case Peripheral::SPI0::ADDRESS:
            switch ( route ) {
                case SPI_Route::DEFAULT: return 6;
                case SPI_Route::ALTERNATE_1: return 2;
#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
                case SPI_Route::ALTERNATE_2: return 2;
#endif // defined ( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
                case SPI_Route::NONE: break;
            } // switch
            break;
    } // switch

    expect( false, Generic_Error::INVALID_ARGUMENT );

    return 0; // unreachable
}

/**
 * \brief Lookup an SPI peripheral's SCK pin number.
 *
 * \param[in] spi The SPI peripheral whose SCK pin number is to be looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's SCK pin number.
 */
inline auto sck_number( Peripheral::SPI const & spi, SPI_Route route ) noexcept
{
    return sck_number( reinterpret_cast<std::uintptr_t>( &spi ), route );
}

/**
 * \brief Lookup an SPI peripheral's SCK pin number.
 *
 * \param[in] spi The SPI peripheral whose SCK pin number is to be looked up.
 *
 * \return The SPI peripheral's SCK pin number.
 */
inline auto sck_number( Peripheral::SPI const & spi ) noexcept
{
    return sck_number( spi, spi_route( spi ) );
}

/**
 * \brief Lookup an SPI peripheral's SCK pin mask.
 *
 * \param[in] spi_address The address of the SPI peripheral whose SCK pin mask is to be
 *            looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's SCK pin mask.
 */
constexpr auto sck_mask( std::uintptr_t spi_address, SPI_Route route ) noexcept -> std::uint8_t
{
    return 1 << sck_number( spi_address, route );
}

/**
 * \brief Lookup an SPI peripheral's SCK pin mask.
 *
 * \param[in] spi The SPI peripheral whose SCK pin mask is to be looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's SCK pin mask.
 */
inline auto sck_mask( Peripheral::SPI const & spi, SPI_Route route ) noexcept
{
    return sck_mask( reinterpret_cast<std::uintptr_t>( &spi ), route );
}

/**
 * \brief Lookup an SPI peripheral's SCK pin mask.
 *
 * \param[in] spi The SPI peripheral whose SCK pin mask is to be looked up.
 *
 * \return The SPI peripheral's SCK pin mask.
 */
inline auto sck_mask( Peripheral::SPI const & spi ) noexcept
{
    return sck_mask( spi, spi_route( spi ) );
}

/**
 * \brief Lookup an SPI peripheral's MOSI pin PORT peripheral address.
 *
 * \param[in] spi_address The address of the SPI peripheral whose MOSI pin PORT peripheral
 *            address is to be looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's MOSI pin PORT peripheral address.
 */
constexpr auto mosi_port_address( std::uintptr_t spi_address, SPI_Route route ) noexcept
{
    return spi_port_address( spi_address, route );
}

/**
 * \brief Lookup an SPI peripheral's MOSI pin PORT peripheral.
 *
 * \param[in] spi The SPI peripheral whose MOSI pin PORT peripheral is to be looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's MOSI pin PORT peripheral.
 */
inline auto & mosi_port( Peripheral::SPI const & spi, SPI_Route route ) noexcept
{
    return spi_port( spi, route );
}

/**
 * \brief Lookup an SPI peripheral's MOSI pin PORT peripheral.
 *
 * \param[in] spi The SPI peripheral whose MOSI pin PORT peripheral is to be looked up.
 *
 * \return The SPI peripheral's MOSI pin PORT peripheral.
 */
inline auto & mosi_port( Peripheral::SPI const & spi ) noexcept
{
    return spi_port( spi );
}

/**
 * \brief Lookup an SPI peripheral's MOSI pin VPORT peripheral address.
 *
 * \param[in] spi_address The address of the SPI peripheral whose MOSI pin VPORT
 *            peripheral address is to be looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's MOSI pin VPORT peripheral address.
 */
constexpr auto mosi_vport_address( std::uintptr_t spi_address, SPI_Route route ) noexcept
{
    return spi_vport_address( spi_address, route );
}

/**
 * \brief Lookup an SPI peripheral's MOSI pin VPORT peripheral.
 *
 * \param[in] spi The SPI peripheral whose MOSI pin VPORT peripheral is to be looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's MOSI pin VPORT peripheral.
 */
inline auto & mosi_vport( Peripheral::SPI const & spi, SPI_Route route ) noexcept
{
    return spi_vport( spi, route );
}

/**
 * \brief Lookup an SPI peripheral's MOSI pin VPORT peripheral.
 *
 * \param[in] spi The SPI peripheral whose MOSI pin VPORT peripheral is to be looked up.
 *
 * \return The SPI peripheral's MOSI pin VPORT peripheral.
 */
inline auto & mosi_vport( Peripheral::SPI const & spi ) noexcept
{
    return spi_vport( spi );
}

/**
 * \brief Lookup an SPI peripheral's MOSI pin number.
 *
 * \param[in] spi_address The address of the SPI peripheral whose MOSI pin number is to be
 *            looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's MOSI pin number.
 */
constexpr auto mosi_number( std::uintptr_t spi_address, SPI_Route route ) noexcept -> std::uint_fast8_t
{
    switch ( spi_address ) {
        case Peripheral::SPI0::ADDRESS:
            switch ( route ) {
                case SPI_Route::DEFAULT: return 4;
                case SPI_Route::ALTERNATE_1: return 0;
#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
                case SPI_Route::ALTERNATE_2: return 0;
#endif // defined ( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
                case SPI_Route::NONE: break;
            } // switch
            break;
    } // switch

    expect( false, Generic_Error::INVALID_ARGUMENT );

    return 0; // unreachable
}

/**
 * \brief Lookup an SPI peripheral's MOSI pin number.
 *
 * \param[in] spi The SPI peripheral whose MOSI pin number is to be looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's MOSI pin number.
 */
inline auto mosi_number( Peripheral::SPI const & spi, SPI_Route route ) noexcept
{
    return mosi_number( reinterpret_cast<std::uintptr_t>( &spi ), route );
}

/**
 * \brief Lookup an SPI peripheral's MOSI pin number.
 *
 * \param[in] spi The SPI peripheral whose MOSI pin number is to be looked up.
 *
 * \return The SPI peripheral's MOSI pin number.
 */
inline auto mosi_number( Peripheral::SPI const & spi ) noexcept
{
    return mosi_number( spi, spi_route( spi ) );
}

/**
 * \brief Lookup an SPI peripheral's MOSI pin mask.
 *
 * \param[in] spi_address The address of the SPI peripheral whose MOSI pin mask is to be
 *            looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's MOSI pin mask.
 */
constexpr auto mosi_mask( std::uintptr_t spi_address, SPI_Route route ) noexcept -> std::uint8_t
{
    return 1 << mosi_number( spi_address, route );
}

/**
 * \brief Lookup an SPI peripheral's MOSI pin mask.
 *
 * \param[in] spi The SPI peripheral whose MOSI pin mask is to be looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's MOSI pin mask.
 */
inline auto mosi_mask( Peripheral::SPI const & spi, SPI_Route route ) noexcept
{
    return mosi_mask( reinterpret_cast<std::uintptr_t>( &spi ), route );
}

/**
 * \brief Lookup an SPI peripheral's MOSI pin mask.
 *
 * \param[in] spi The SPI peripheral whose MOSI pin mask is to be looked up.
 *
 * \return The SPI peripheral's MOSI pin mask.
 */
inline auto mosi_mask( Peripheral::SPI const & spi ) noexcept
{
    return mosi_mask( spi, spi_route( spi ) );
}

/**
 * \brief Lookup an SPI peripheral's MISO pin PORT peripheral address.
 *
 * \param[in] spi_address The address of the SPI peripheral whose MISO pin PORT peripheral
 *            address is to be looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's MISO pin PORT peripheral address.
 */
constexpr auto miso_port_address( std::uintptr_t spi_address, SPI_Route route ) noexcept
{
    return spi_port_address( spi_address, route );
}

/**
 * \brief Lookup an SPI peripheral's MISO pin PORT peripheral.
 *
 * \param[in] spi The SPI peripheral whose MISO pin PORT peripheral is to be looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's MISO pin PORT peripheral.
 */
inline auto & miso_port( Peripheral::SPI const & spi, SPI_Route route ) noexcept
{
    return spi_port( spi, route );
}

/**
 * \brief Lookup an SPI peripheral's MISO pin PORT peripheral.
 *
 * \param[in] spi The SPI peripheral whose MISO pin PORT peripheral is to be looked up.
 *
 * \return The SPI peripheral's MISO pin PORT peripheral.
 */
inline auto & miso_port( Peripheral::SPI const & spi ) noexcept
{
    return spi_port( spi );
}

/**
 * \brief Lookup an SPI peripheral's MISO pin VPORT peripheral address.
 *
 * \param[in] spi_address The address of the SPI peripheral whose MISO pin VPORT
 *            peripheral address is to be looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's MISO pin VPORT peripheral address.
 */
constexpr auto miso_vport_address( std::uintptr_t spi_address, SPI_Route route ) noexcept
{
    return spi_vport_address( spi_address, route );
}

/**
 * \brief Lookup an SPI peripheral's MISO pin VPORT peripheral.
 *
 * \param[in] spi The SPI peripheral whose MISO pin VPORT peripheral is to be looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's MISO pin VPORT peripheral.
 */
inline auto & miso_vport( Peripheral::SPI const & spi, SPI_Route route ) noexcept
{
    return spi_vport( spi, route );
}

/**
 * \brief Lookup an SPI peripheral's MISO pin VPORT peripheral.
 *
 * \param[in] spi The SPI peripheral whose MISO pin VPORT peripheral is to be looked up.
 *
 * \return The SPI peripheral's MISO pin VPORT peripheral.
 */
inline auto & miso_vport( Peripheral::SPI const & spi ) noexcept
{
    return spi_vport( spi );
}

/**
 * \brief Lookup an SPI peripheral's MISO pin number.
 *
 * \param[in] spi_address The address of the SPI peripheral whose MISO pin number is to be
 *            looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's MISO pin number.
 */
constexpr auto miso_number( std::uintptr_t spi_address, SPI_Route route ) noexcept -> std::uint_fast8_t
{
    switch ( spi_address ) {
        case Peripheral::SPI0::ADDRESS:
            switch ( route ) {
                case SPI_Route::DEFAULT: return 5;
                case SPI_Route::ALTERNATE_1: return 1;
#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
                case SPI_Route::ALTERNATE_2: return 1;
#endif // defined ( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
                case SPI_Route::NONE: break;
            } // switch
            break;
    } // switch

    expect( false, Generic_Error::INVALID_ARGUMENT );

    return 0; // unreachable
}

/**
 * \brief Lookup an SPI peripheral's MISO pin number.
 *
 * \param[in] spi The SPI peripheral whose MISO pin number is to be looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's MISO pin number.
 */
inline auto miso_number( Peripheral::SPI const & spi, SPI_Route route ) noexcept
{
    return miso_number( reinterpret_cast<std::uintptr_t>( &spi ), route );
}

/**
 * \brief Lookup an SPI peripheral's MISO pin number.
 *
 * \param[in] spi The SPI peripheral whose MISO pin number is to be looked up.
 *
 * \return The SPI peripheral's MISO pin number.
 */
inline auto miso_number( Peripheral::SPI const & spi ) noexcept
{
    return miso_number( spi, spi_route( spi ) );
}

/**
 * \brief Lookup an SPI peripheral's MISO pin mask.
 *
 * \param[in] spi_address The address of the SPI peripheral whose MISO pin mask is to be
 *            looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's MISO pin mask.
 */
constexpr auto miso_mask( std::uintptr_t spi_address, SPI_Route route ) noexcept -> std::uint8_t
{
    return 1 << miso_number( spi_address, route );
}

/**
 * \brief Lookup an SPI peripheral's MISO pin mask.
 *
 * \param[in] spi The SPI peripheral whose MISO pin mask is to be looked up.
 * \param[in] route The SPI peripheral's routing configuration.
 *
 * \return The SPI peripheral's MISO pin mask.
 */
inline auto miso_mask( Peripheral::SPI const & spi, SPI_Route route ) noexcept
{
    return miso_mask( reinterpret_cast<std::uintptr_t>( &spi ), route );
}

/**
 * \brief Lookup an SPI peripheral's MISO pin mask.
 *
 * \param[in] spi The SPI peripheral whose MISO pin mask is to be looked up.
 *
 * \return The SPI peripheral's MISO pin mask.
 */
inline auto miso_mask( Peripheral::SPI const & spi ) noexcept
{
    return miso_mask( spi, spi_route( spi ) );
}

} // namespace picolibrary::Microchip::megaAVR0::Multiplexed_Signals

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_MULTIPLEXED_SIGNALS_SPI_H
