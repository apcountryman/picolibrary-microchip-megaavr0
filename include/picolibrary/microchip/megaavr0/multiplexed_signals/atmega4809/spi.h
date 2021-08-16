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
 * \brief picolibrary::Microchip::megaAVR0::Multiplexed_Signals::ATmega4809::SPI
 *        interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_MULTIPLEXED_SIGNALS_ATMEGA4809_SPI_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_MULTIPLEXED_SIGNALS_ATMEGA4809_SPI_H

#include <cstdint>

#include "picolibrary/fatal_error.h"
#include "picolibrary/microchip/megaavr0/peripheral/atmega4809.h"
#include "picolibrary/microchip/megaavr0/peripheral/port.h"
#include "picolibrary/microchip/megaavr0/peripheral/portmux.h"
#include "picolibrary/microchip/megaavr0/peripheral/spi.h"
#include "picolibrary/microchip/megaavr0/peripheral/vport.h"

namespace picolibrary::Microchip::megaAVR0::Multiplexed_Signals::ATmega4809 {

/**
 * \brief SPI routing configuration.
 */
using SPI_Route = Peripheral::PORTMUX::SPI_Route;

/**
 * \brief Set an SPI peripheral's routing configuration.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::set_spi_route().
 *
 * \param[in] spi The SPI peripheral whose routing configuration will be set.
 * \param[in] route The desired SPI peripheral routing configuration.
 */
inline void set_spi_route( Peripheral::SPI const & spi, SPI_Route route ) noexcept
{
    switch ( reinterpret_cast<std::uintptr_t>( &spi ) ) {
        case Peripheral::ATmega4809::SPI0::ADDRESS:
            Peripheral::ATmega4809::PORTMUX0::instance().set_spi0_route( route );
            return;
    } // switch

    trap_fatal_error();
}

/**
 * \brief Lookup an SPI peripheral's pins port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::spi_port().
 *
 * \param[in] spi The SPI peripheral whose pins port is to be looked up.
 *
 * \return The SPI peripheral's pins port.
 */
inline auto spi_port( Peripheral::SPI const & spi ) noexcept -> Peripheral::PORT &
{
    switch ( reinterpret_cast<std::uintptr_t>( &spi ) ) {
        case Peripheral::ATmega4809::SPI0::ADDRESS:
            switch ( Peripheral::ATmega4809::PORTMUX0::instance().spi0_route() ) {
                case SPI_Route::DEFAULT: return Peripheral::ATmega4809::PORTA::instance();
                case SPI_Route::ALTERNATE_1:
                    return Peripheral::ATmega4809::PORTC::instance();
                case SPI_Route::ALTERNATE_2:
                    return Peripheral::ATmega4809::PORTE::instance();
                case SPI_Route::NONE: break;
            } // switch
            break;
    } // switch

    trap_fatal_error();
}

/**
 * \brief Lookup an SPI peripheral's pins virtual port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::spi_vport().
 *
 * \param[in] spi The SPI peripheral whose pins virtual port is to be looked up.
 *
 * \return The SPI peripheral's pins virtual port.
 */
inline auto spi_vport( Peripheral::SPI const & spi ) noexcept -> Peripheral::VPORT &
{
    switch ( reinterpret_cast<std::uintptr_t>( &spi ) ) {
        case Peripheral::ATmega4809::SPI0::ADDRESS:
            switch ( Peripheral::ATmega4809::PORTMUX0::instance().spi0_route() ) {
                case SPI_Route::DEFAULT:
                    return Peripheral::ATmega4809::VPORTA::instance();
                case SPI_Route::ALTERNATE_1:
                    return Peripheral::ATmega4809::VPORTC::instance();
                case SPI_Route::ALTERNATE_2:
                    return Peripheral::ATmega4809::VPORTE::instance();
                case SPI_Route::NONE: break;
            } // switch
            break;
    } // switch

    trap_fatal_error();
}

/**
 * \brief Lookup an SPI peripheral's DS pin port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::ds_port().
 *
 * \param[in] spi The SPI peripheral whose DS pin port is to be looked up.
 *
 * \return The SPI peripheral's DS pin port.
 */
inline auto & ds_port( Peripheral::SPI const & spi ) noexcept
{
    return spi_port( spi );
}

/**
 * \brief Lookup an SPI peripheral's DS pin virtual port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::ds_vport().
 *
 * \param[in] spi The SPI peripheral whose DS pin virtual port is to be looked up.
 *
 * \return The SPI peripheral's DS pin virtual port.
 */
inline auto & ds_vport( Peripheral::SPI const & spi ) noexcept
{
    return spi_vport( spi );
}

/**
 * \brief Lookup an SPI peripheral's DS pin number.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::ds_number().
 *
 * \param[in] spi The SPI peripheral whose DS pin number is to be looked up.
 *
 * \return The SPI peripheral's DS pin number.
 */
inline auto ds_number( Peripheral::SPI const & spi ) noexcept -> std::uint_fast8_t
{
    switch ( reinterpret_cast<std::uintptr_t>( &spi ) ) {
        case Peripheral::ATmega4809::SPI0::ADDRESS:
            switch ( Peripheral::ATmega4809::PORTMUX0::instance().spi0_route() ) {
                case SPI_Route::DEFAULT: return 7;
                case SPI_Route::ALTERNATE_1: return 3;
                case SPI_Route::ALTERNATE_2: return 3;
                case SPI_Route::NONE: break;
            } // switch
            break;
    } // switch

    trap_fatal_error();
}

/**
 * \brief Lookup an SPI peripheral's DS pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::ds_mask().
 *
 * \param[in] spi The SPI peripheral whose DS pin mask is to be looked up.
 *
 * \return The SPI peripheral's DS pin mask.
 */
inline auto ds_mask( Peripheral::SPI const & spi ) noexcept -> std::uint8_t
{
    return 1 << ds_number( spi );
}

/**
 * \brief Lookup an SPI peripheral's SCK pin port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::sck_port().
 *
 * \param[in] spi The SPI peripheral whose SCK pin port is to be looked up.
 *
 * \return The SPI peripheral's SCK pin port.
 */
inline auto & sck_port( Peripheral::SPI const & spi ) noexcept
{
    return spi_port( spi );
}

/**
 * \brief Lookup an SPI peripheral's SCK pin virtual port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::sck_vport().
 *
 * \param[in] spi The SPI peripheral whose SCK pin virtual port is to be looked up.
 *
 * \return The SPI peripheral's SCK pin virtual port.
 */
inline auto & sck_vport( Peripheral::SPI const & spi ) noexcept
{
    return spi_vport( spi );
}

/**
 * \brief Lookup an SPI peripheral's SCK pin number.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::sck_number().
 *
 * \param[in] spi The SPI peripheral whose SCK pin number is to be looked up.
 *
 * \return The SPI peripheral's SCK pin number.
 */
inline auto sck_number( Peripheral::SPI const & spi ) noexcept -> std::uint_fast8_t
{
    switch ( reinterpret_cast<std::uintptr_t>( &spi ) ) {
        case Peripheral::ATmega4809::SPI0::ADDRESS:
            switch ( Peripheral::ATmega4809::PORTMUX0::instance().spi0_route() ) {
                case SPI_Route::DEFAULT: return 6;
                case SPI_Route::ALTERNATE_1: return 2;
                case SPI_Route::ALTERNATE_2: return 2;
                case SPI_Route::NONE: break;
            } // switch
            break;
    } // switch

    trap_fatal_error();
}

/**
 * \brief Lookup an SPI peripheral's SCK pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::sck_mask().
 *
 * \param[in] spi The SPI peripheral whose SCK pin mask is to be looked up.
 *
 * \return The SPI peripheral's SCK pin mask.
 */
inline auto sck_mask( Peripheral::SPI const & spi ) noexcept -> std::uint8_t
{
    return 1 << sck_number( spi );
}

/**
 * \brief Lookup an SPI peripheral's CODI pin port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::codi_port().
 *
 * \param[in] spi The SPI peripheral whose CODI pin port is to be looked up.
 *
 * \return The SPI peripheral's CODI pin port.
 */
inline auto & codi_port( Peripheral::SPI const & spi ) noexcept
{
    return spi_port( spi );
}

/**
 * \brief Lookup an SPI peripheral's CODI pin virtual port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::codi_vport().
 *
 * \param[in] spi The SPI peripheral whose CODI pin virtual port is to be looked up.
 *
 * \return The SPI peripheral's CODI pin virtual port.
 */
inline auto & codi_vport( Peripheral::SPI const & spi ) noexcept
{
    return spi_vport( spi );
}

/**
 * \brief Lookup an SPI peripheral's CODI pin number.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::codi_number().
 *
 * \param[in] spi The SPI peripheral whose CODI pin number is to be looked up.
 *
 * \return The SPI peripheral's CODI pin number.
 */
inline auto codi_number( Peripheral::SPI const & spi ) noexcept -> std::uint_fast8_t
{
    switch ( reinterpret_cast<std::uintptr_t>( &spi ) ) {
        case Peripheral::ATmega4809::SPI0::ADDRESS:
            switch ( Peripheral::ATmega4809::PORTMUX0::instance().spi0_route() ) {
                case SPI_Route::DEFAULT: return 4;
                case SPI_Route::ALTERNATE_1: return 0;
                case SPI_Route::ALTERNATE_2: return 0;
                case SPI_Route::NONE: break;
            } // switch
            break;
    } // switch

    trap_fatal_error();
}

/**
 * \brief Lookup an SPI peripheral's CODI pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::codi_mask().
 *
 * \param[in] spi The SPI peripheral whose CODI pin mask is to be looked up.
 *
 * \return The SPI peripheral's CODI pin mask.
 */
inline auto codi_mask( Peripheral::SPI const & spi ) noexcept -> std::uint8_t
{
    return 1 << codi_number( spi );
}

/**
 * \brief Lookup an SPI peripheral's CIDO pin port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::cido_port().
 *
 * \param[in] spi The SPI peripheral whose CIDO pin port is to be looked up.
 *
 * \return The SPI peripheral's CIDO pin port.
 */
inline auto & cido_port( Peripheral::SPI const & spi ) noexcept
{
    return spi_port( spi );
}

/**
 * \brief Lookup an SPI peripheral's CIDO pin virtual port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::cido_vport().
 *
 * \param[in] spi The SPI peripheral whose CIDO pin virtual port is to be looked up.
 *
 * \return The SPI peripheral's CIDO pin virtual port.
 */
inline auto & cido_vport( Peripheral::SPI const & spi ) noexcept
{
    return spi_vport( spi );
}

/**
 * \brief Lookup an SPI peripheral's CIDO pin number.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::cido_number().
 *
 * \param[in] spi The SPI peripheral whose CIDO pin number is to be looked up.
 *
 * \return The SPI peripheral's CIDO pin number.
 */
inline auto cido_number( Peripheral::SPI const & spi ) noexcept -> std::uint_fast8_t
{
    switch ( reinterpret_cast<std::uintptr_t>( &spi ) ) {
        case Peripheral::ATmega4809::SPI0::ADDRESS:
            switch ( Peripheral::ATmega4809::PORTMUX0::instance().spi0_route() ) {
                case SPI_Route::DEFAULT: return 5;
                case SPI_Route::ALTERNATE_1: return 1;
                case SPI_Route::ALTERNATE_2: return 1;
                case SPI_Route::NONE: break;
            } // switch
            break;
    } // switch

    trap_fatal_error();
}

/**
 * \brief Lookup an SPI peripheral's CIDO pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::cido_mask().
 *
 * \param[in] spi The SPI peripheral whose CIDO pin mask is to be looked up.
 *
 * \return The SPI peripheral's CIDO pin mask.
 */
inline auto cido_mask( Peripheral::SPI const & spi ) noexcept -> std::uint8_t
{
    return 1 << cido_number( spi );
}

} // namespace picolibrary::Microchip::megaAVR0::Multiplexed_Signals::ATmega4809

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_MULTIPLEXED_SIGNALS_ATMEGA4809_SPI_H
