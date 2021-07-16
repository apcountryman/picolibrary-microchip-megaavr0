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
 * \brief picolibrary::Microchip::megaAVR0::Multiplexed_Signals::ATmega4809::TWI
 *        interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_MULTIPLEXED_SIGNALS_ATMEGA4809_TWI_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_MULTIPLEXED_SIGNALS_ATMEGA4809_TWI_H

#include <cstdint>

#include "picolibrary/microchip/megaavr0/peripheral/atmega4809.h"
#include "picolibrary/microchip/megaavr0/peripheral/port.h"
#include "picolibrary/microchip/megaavr0/peripheral/portmux.h"
#include "picolibrary/microchip/megaavr0/peripheral/twi.h"
#include "picolibrary/microchip/megaavr0/peripheral/vport.h"

namespace picolibrary::Microchip::megaAVR0::Multiplexed_Signals::ATmega4809 {

/**
 * \brief TWI routing configuration.
 */
using TWI_Route = Peripheral::PORTMUX::TWI_Route;

/**
 * \brief Set a TWI peripheral's routing configuration.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::set_twi_route().
 *
 * \param[in] twi The TWI peripheral whose routing configuration will be set.
 * \param[in] route The desired TWI peripheral routing configuration.
 */
inline void set_twi_route( Peripheral::TWI const & twi, TWI_Route route ) noexcept
{
    static_cast<void>( twi );

    Peripheral::ATmega4809::PORTMUX0::instance().set_twi0_route( route );
}

/**
 * \brief Lookup a TWI peripheral's SCL pin number.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::scl_number().
 *
 * \param[in] twi The TWI peripheral whose SCL pin number is to be looked up.
 *
 * \return The TWI peripheral's SCL pin number.
 */
constexpr auto scl_number( Peripheral::TWI const & twi ) noexcept -> std::uint_fast8_t
{
    static_cast<void>( twi );

    return 3;
}

/**
 * \brief Lookup a TWI peripheral's SCL pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::scl_mask().
 *
 * \param[in] twi The TWI peripheral whose SCL pin mask is to be looked up.
 *
 * \return The TWI peripheral's SCL pin mask.
 */
constexpr auto scl_mask( Peripheral::TWI const & twi ) noexcept -> std::uint8_t
{
    return 1 << scl_number( twi );
}

/**
 * \brief Lookup a TWI peripheral's SDA pin number.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::sda_number().
 *
 * \param[in] twi The TWI peripheral whose SDA pin number is to be looked up.
 *
 * \return The TWI peripheral's SDA pin number.
 */
constexpr auto sda_number( Peripheral::TWI const & twi ) noexcept -> std::uint_fast8_t
{
    static_cast<void>( twi );

    return 2;
}

/**
 * \brief Lookup a TWI peripheral's SDA pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::sda_mask().
 *
 * \param[in] twi The TWI peripheral whose SDA pin mask is to be looked up.
 *
 * \return The TWI peripheral's SDA pin mask.
 */
constexpr auto sda_mask( Peripheral::TWI const & twi ) noexcept -> std::uint8_t
{
    return 1 << sda_number( twi );
}

/**
 * \brief Lookup a TWI peripheral's controller pins port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::twi_controller_port().
 *
 * \param[in] twi The TWI peripheral whose controller pins port is to be looked up.
 *
 * \return The TWI peripheral's controller pins port.
 */
inline auto twi_controller_port( Peripheral::TWI const & twi ) noexcept -> Peripheral::PORT &
{
    static_cast<void>( twi );

    switch ( Peripheral::ATmega4809::PORTMUX0::instance().twi0_route() ) {
        case TWI_Route::DEFAULT: return Peripheral::ATmega4809::PORTA::instance();
        case TWI_Route::ALTERNATE_1: return Peripheral::ATmega4809::PORTA::instance();
        case TWI_Route::ALTERNATE_2: return Peripheral::ATmega4809::PORTC::instance();
    } // switch

    return *static_cast<Peripheral::PORT *>( nullptr );
}

/**
 * \brief Lookup a TWI peripheral's controller pins virtual port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::twi_controller_vport().
 *
 * \param[in] twi The TWI peripheral whose controller pins virtual port is to be looked
 *            up.
 *
 * \return The TWI peripheral's controller pins virtual port.
 */
inline auto twi_controller_vport( Peripheral::TWI const & twi ) noexcept -> Peripheral::VPORT &
{
    static_cast<void>( twi );

    switch ( Peripheral::ATmega4809::PORTMUX0::instance().twi0_route() ) {
        case TWI_Route::DEFAULT: return Peripheral::ATmega4809::VPORTA::instance();
        case TWI_Route::ALTERNATE_1: return Peripheral::ATmega4809::VPORTA::instance();
        case TWI_Route::ALTERNATE_2: return Peripheral::ATmega4809::VPORTC::instance();
    } // switch

    return *static_cast<Peripheral::VPORT *>( nullptr );
}

/**
 * \brief Lookup a TWI peripheral's controller SCL pin port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::controller_scl_port().
 *
 * \param[in] twi The TWI peripheral whose controller SCL pin port is to be looked up.
 *
 * \return The TWI peripheral's controller SCL pin port.
 */
inline auto & controller_scl_port( Peripheral::TWI const & twi ) noexcept
{
    return twi_controller_port( twi );
}

/**
 * \brief Lookup a TWI peripheral's controller SCL pin virtual port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::controller_scl_vport().
 *
 * \param[in] twi The TWI peripheral whose controller SCL pin virtual port is to be looked
 *            up.
 *
 * \return The TWI peripheral's controller SCL pin virtual port.
 */
inline auto & controller_scl_vport( Peripheral::TWI const & twi ) noexcept
{
    return twi_controller_vport( twi );
}

/**
 * \brief Lookup a TWI peripheral's controller SCL pin number.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::controller_scl_number().
 *
 * \param[in] twi The TWI peripheral whose controller SCL pin number is to be looked up.
 *
 * \return The TWI peripheral's controller SCL pin number.
 */
constexpr auto controller_scl_number( Peripheral::TWI const & twi ) noexcept
{
    return scl_number( twi );
}

/**
 * \brief Lookup a TWI peripheral's controller SCL pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::controller_scl_mask().
 *
 * \param[in] twi The TWI peripheral whose controller SCL pin mask is to be looked up.
 *
 * \return The TWI peripheral's controller SCL pin mask.
 */
constexpr auto controller_scl_mask( Peripheral::TWI const & twi ) noexcept
{
    return scl_mask( twi );
}

/**
 * \brief Lookup a TWI peripheral's controller SDA pin port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::controller_sda_port().
 *
 * \param[in] twi The TWI peripheral whose controller SDA pin port is to be looked up.
 *
 * \return The TWI peripheral's controller SDA pin port.
 */
inline auto & controller_sda_port( Peripheral::TWI const & twi ) noexcept
{
    return twi_controller_port( twi );
}

/**
 * \brief Lookup a TWI peripheral's controller SDA pin virtual port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::controller_sda_vport().
 *
 * \param[in] twi The TWI peripheral whose controller SDA pin virtual port is to be looked
 *            up.
 *
 * \return The TWI peripheral's controller SDA pin virtual port.
 */
inline auto & controller_sda_vport( Peripheral::TWI const & twi ) noexcept
{
    return twi_controller_vport( twi );
}

/**
 * \brief Lookup a TWI peripheral's controller SDA pin number.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::controller_sda_number().
 *
 * \param[in] twi The TWI peripheral whose controller SDA pin number is to be looked up.
 *
 * \return The TWI peripheral's controller SDA pin number.
 */
constexpr auto controller_sda_number( Peripheral::TWI const & twi ) noexcept
{
    return sda_number( twi );
}

/**
 * \brief Lookup a TWI peripheral's controller SDA pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::controller_sda_mask().
 *
 * \param[in] twi The TWI peripheral whose controller SDA pin mask is to be looked up.
 *
 * \return The TWI peripheral's controller SDA pin mask.
 */
constexpr auto controller_sda_mask( Peripheral::TWI const & twi ) noexcept
{
    return sda_mask( twi );
}

/**
 * \brief Lookup a TWI peripheral's device pins port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::twi_device_port().
 *
 * \param[in] twi The TWI peripheral whose device pins port is to be looked up.
 *
 * \return The TWI peripheral's device pins port.
 */
inline auto twi_device_port( Peripheral::TWI const & twi ) noexcept -> Peripheral::PORT &
{
    static_cast<void>( twi );

    switch ( Peripheral::ATmega4809::PORTMUX0::instance().twi0_route() ) {
        case TWI_Route::DEFAULT: return Peripheral::ATmega4809::PORTC::instance();
        case TWI_Route::ALTERNATE_1: return Peripheral::ATmega4809::PORTF::instance();
        case TWI_Route::ALTERNATE_2: return Peripheral::ATmega4809::PORTF::instance();
    } // switch

    return *static_cast<Peripheral::PORT *>( nullptr );
}

/**
 * \brief Lookup a TWI peripheral's device pins virtual port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::twi_device_vport().
 *
 * \param[in] twi The TWI peripheral whose device pins virtual port is to be looked up.
 *
 * \return The TWI peripheral's device pins virtual port.
 */
inline auto twi_device_vport( Peripheral::TWI const & twi ) noexcept -> Peripheral::VPORT &
{
    static_cast<void>( twi );

    switch ( Peripheral::ATmega4809::PORTMUX0::instance().twi0_route() ) {
        case TWI_Route::DEFAULT: return Peripheral::ATmega4809::VPORTC::instance();
        case TWI_Route::ALTERNATE_1: return Peripheral::ATmega4809::VPORTF::instance();
        case TWI_Route::ALTERNATE_2: return Peripheral::ATmega4809::VPORTF::instance();
    } // switch

    return *static_cast<Peripheral::VPORT *>( nullptr );
}

/**
 * \brief Lookup a TWI peripheral's device SCL pin port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::device_scl_port().
 *
 * \param[in] twi The TWI peripheral whose device SCL pin port is to be looked up.
 *
 * \return The TWI peripheral's device SCL pin port.
 */
inline auto & device_scl_port( Peripheral::TWI const & twi ) noexcept
{
    return twi_device_port( twi );
}

/**
 * \brief Lookup a TWI peripheral's device SCL pin virtual port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::device_scl_vport().
 *
 * \param[in] twi The TWI peripheral whose device SCL pin virtual port is to be looked up.
 *
 * \return The TWI peripheral's device SCL pin virtual port.
 */
inline auto & device_scl_vport( Peripheral::TWI const & twi ) noexcept
{
    return twi_device_vport( twi );
}

/**
 * \brief Lookup a TWI peripheral's device SCL pin number.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::device_scl_number().
 *
 * \param[in] twi The TWI peripheral whose device SCL pin number is to be looked up.
 *
 * \return The TWI peripheral's device SCL pin number.
 */
constexpr auto device_scl_number( Peripheral::TWI const & twi ) noexcept
{
    return scl_number( twi );
}

/**
 * \brief Lookup a TWI peripheral's device SCL pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::device_scl_mask().
 *
 * \param[in] twi The TWI peripheral whose device SCL pin mask is to be looked up.
 *
 * \return The TWI peripheral's device SCL pin mask.
 */
constexpr auto device_scl_mask( Peripheral::TWI const & twi ) noexcept
{
    return scl_mask( twi );
}

/**
 * \brief Lookup a TWI peripheral's device SDA pin port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::device_sda_port().
 *
 * \param[in] twi The TWI peripheral whose device SDA pin port is to be looked up.
 *
 * \return The TWI peripheral's device SDA pin port.
 */
inline auto & device_sda_port( Peripheral::TWI const & twi ) noexcept
{
    return twi_device_port( twi );
}

/**
 * \brief Lookup a TWI peripheral's device SDA pin virtual port.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::device_sda_vport().
 *
 * \param[in] twi The TWI peripheral whose device SDA pin virtual port is to be looked up.
 *
 * \return The TWI peripheral's device SDA pin virtual port.
 */
inline auto & device_sda_vport( Peripheral::TWI const & twi ) noexcept
{
    return twi_device_vport( twi );
}

/**
 * \brief Lookup a TWI peripheral's device SDA pin number.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::device_sda_number().
 *
 * \param[in] twi The TWI peripheral whose device SDA pin number is to be looked up.
 *
 * \return The TWI peripheral's device SDA pin number.
 */
constexpr auto device_sda_number( Peripheral::TWI const & twi ) noexcept
{
    return sda_number( twi );
}

/**
 * \brief Lookup a TWI peripheral's device SDA pin mask.
 *
 * \attention This function should never be called directly. Instead, set the `-mmcu`
 *            compiler flag to `atmega4809` and call
 *            picolibrary::Microchip::megaAVR0::Multiplexed_Signals::device_sda_mask().
 *
 * \param[in] twi The TWI peripheral whose device SDA pin mask is to be looked up.
 *
 * \return The TWI peripheral's device SDA pin mask.
 */
constexpr auto device_sda_mask( Peripheral::TWI const & twi ) noexcept
{
    return sda_mask( twi );
}

} // namespace picolibrary::Microchip::megaAVR0::Multiplexed_Signals::ATmega4809

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_MULTIPLEXED_SIGNALS_ATMEGA4809_TWI_H
