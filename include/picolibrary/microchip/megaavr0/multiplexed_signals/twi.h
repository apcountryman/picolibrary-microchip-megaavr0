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
 * \brief picolibrary::Microchip::megaAVR0::Multiplexed_Signals::TWI interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_MULTIPLEXED_SIGNALS_TWI_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_MULTIPLEXED_SIGNALS_TWI_H

#include <cstdint>

#include "picolibrary/fatal_error.h"
#include "picolibrary/microchip/megaavr0/peripheral.h"
#include "picolibrary/microchip/megaavr0/peripheral/port.h"
#include "picolibrary/microchip/megaavr0/peripheral/portmux.h"
#include "picolibrary/microchip/megaavr0/peripheral/twi.h"
#include "picolibrary/microchip/megaavr0/peripheral/vport.h"

namespace picolibrary::Microchip::megaAVR0::Multiplexed_Signals {

/**
 * \brief TWI routing configuration.
 */
using TWI_Route = Peripheral::PORTMUX::TWI_Route;

/**
 * \brief Set a TWI peripheral's routing configuration.
 *
 * \param[in] twi The TWI peripheral whose routing configuration will be set.
 * \param[in] route The desired TWI peripheral routing configuration.
 */
inline void set_twi_route( Peripheral::TWI const & twi, TWI_Route route ) noexcept
{
    switch ( reinterpret_cast<std::uintptr_t>( &twi ) ) {
        case Peripheral::TWI0::ADDRESS:
            Peripheral::PORTMUX0::instance().set_twi0_route( route );
            return;
    } // switch

    trap_fatal_error();
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
    switch ( reinterpret_cast<std::uintptr_t>( &twi ) ) {
        case Peripheral::TWI0::ADDRESS:
            switch ( Peripheral::PORTMUX0::instance().twi0_route() ) {
                case TWI_Route::DEFAULT: return 3;
                case TWI_Route::ALTERNATE_1: return 3;
                case TWI_Route::ALTERNATE_2: return 3;
            } // switch
            break;
    } // switch

    trap_fatal_error();
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
    return 1 << scl_number( twi );
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
    switch ( reinterpret_cast<std::uintptr_t>( &twi ) ) {
        case Peripheral::TWI0::ADDRESS:
            switch ( Peripheral::PORTMUX0::instance().twi0_route() ) {
                case TWI_Route::DEFAULT: return 2;
                case TWI_Route::ALTERNATE_1: return 2;
                case TWI_Route::ALTERNATE_2: return 2;
            } // switch
            break;
    } // switch

    trap_fatal_error();
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
    return 1 << sda_number( twi );
}

/**
 * \brief Lookup a TWI peripheral's controller pins port.
 *
 * \param[in] twi The TWI peripheral whose controller pins port is to be looked up.
 *
 * \return The TWI peripheral's controller pins port.
 */
inline auto twi_controller_port( Peripheral::TWI const & twi ) noexcept -> Peripheral::PORT &
{
    switch ( reinterpret_cast<std::uintptr_t>( &twi ) ) {
        case Peripheral::TWI0::ADDRESS:
            switch ( Peripheral::PORTMUX0::instance().twi0_route() ) {
                case TWI_Route::DEFAULT: return Peripheral::PORTA::instance();
                case TWI_Route::ALTERNATE_1: return Peripheral::PORTA::instance();
                case TWI_Route::ALTERNATE_2: return Peripheral::PORTC::instance();
            } // switch
            break;
    } // switch

    trap_fatal_error();
}

/**
 * \brief Lookup a TWI peripheral's controller pins virtual port.
 *
 * \param[in] twi The TWI peripheral whose controller pins virtual port is to be looked
 *            up.
 *
 * \return The TWI peripheral's controller pins virtual port.
 */
inline auto twi_controller_vport( Peripheral::TWI const & twi ) noexcept -> Peripheral::VPORT &
{
    switch ( reinterpret_cast<std::uintptr_t>( &twi ) ) {
        case Peripheral::TWI0::ADDRESS:
            switch ( Peripheral::PORTMUX0::instance().twi0_route() ) {
                case TWI_Route::DEFAULT: return Peripheral::VPORTA::instance();
                case TWI_Route::ALTERNATE_1: return Peripheral::VPORTA::instance();
                case TWI_Route::ALTERNATE_2: return Peripheral::VPORTC::instance();
            } // switch
            break;
    } // switch

    trap_fatal_error();
}

/**
 * \brief Lookup a TWI peripheral's controller SCL pin port.
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
 * \param[in] twi The TWI peripheral whose controller SCL pin number is to be looked up.
 *
 * \return The TWI peripheral's controller SCL pin number.
 */
inline auto controller_scl_number( Peripheral::TWI const & twi ) noexcept
{
    return scl_number( twi );
}

/**
 * \brief Lookup a TWI peripheral's controller SCL pin mask.
 *
 * \param[in] twi The TWI peripheral whose controller SCL pin mask is to be looked up.
 *
 * \return The TWI peripheral's controller SCL pin mask.
 */
inline auto controller_scl_mask( Peripheral::TWI const & twi ) noexcept
{
    return scl_mask( twi );
}

/**
 * \brief Lookup a TWI peripheral's controller SDA pin port.
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
 * \param[in] twi The TWI peripheral whose controller SDA pin number is to be looked up.
 *
 * \return The TWI peripheral's controller SDA pin number.
 */
inline auto controller_sda_number( Peripheral::TWI const & twi ) noexcept
{
    return sda_number( twi );
}

/**
 * \brief Lookup a TWI peripheral's controller SDA pin mask.
 *
 * \param[in] twi The TWI peripheral whose controller SDA pin mask is to be looked up.
 *
 * \return The TWI peripheral's controller SDA pin mask.
 */
inline auto controller_sda_mask( Peripheral::TWI const & twi ) noexcept
{
    return sda_mask( twi );
}

/**
 * \brief Lookup a TWI peripheral's device pins port.
 *
 * \param[in] twi The TWI peripheral whose device pins port is to be looked up.
 *
 * \return The TWI peripheral's device pins port.
 */
inline auto twi_device_port( Peripheral::TWI const & twi ) noexcept -> Peripheral::PORT &
{
    switch ( reinterpret_cast<std::uintptr_t>( &twi ) ) {
        case Peripheral::TWI0::ADDRESS:
            switch ( Peripheral::PORTMUX0::instance().twi0_route() ) {
                case TWI_Route::DEFAULT: return Peripheral::PORTC::instance();
                case TWI_Route::ALTERNATE_1: return Peripheral::PORTF::instance();
                case TWI_Route::ALTERNATE_2: return Peripheral::PORTF::instance();
            } // switch
            break;
    } // switch

    trap_fatal_error();
}

/**
 * \brief Lookup a TWI peripheral's device pins virtual port.
 *
 * \param[in] twi The TWI peripheral whose device pins virtual port is to be looked up.
 *
 * \return The TWI peripheral's device pins virtual port.
 */
inline auto twi_device_vport( Peripheral::TWI const & twi ) noexcept -> Peripheral::VPORT &
{
    switch ( reinterpret_cast<std::uintptr_t>( &twi ) ) {
        case Peripheral::TWI0::ADDRESS:
            switch ( Peripheral::PORTMUX0::instance().twi0_route() ) {
                case TWI_Route::DEFAULT: return Peripheral::VPORTC::instance();
                case TWI_Route::ALTERNATE_1: return Peripheral::VPORTF::instance();
                case TWI_Route::ALTERNATE_2: return Peripheral::VPORTF::instance();
            } // switch
            break;
    } // switch

    trap_fatal_error();
}

/**
 * \brief Lookup a TWI peripheral's device SCL pin port.
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
 * \param[in] twi The TWI peripheral whose device SCL pin number is to be looked up.
 *
 * \return The TWI peripheral's device SCL pin number.
 */
inline auto device_scl_number( Peripheral::TWI const & twi ) noexcept
{
    return scl_number( twi );
}

/**
 * \brief Lookup a TWI peripheral's device SCL pin mask.
 *
 * \param[in] twi The TWI peripheral whose device SCL pin mask is to be looked up.
 *
 * \return The TWI peripheral's device SCL pin mask.
 */
inline auto device_scl_mask( Peripheral::TWI const & twi ) noexcept
{
    return scl_mask( twi );
}

/**
 * \brief Lookup a TWI peripheral's device SDA pin port.
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
 * \param[in] twi The TWI peripheral whose device SDA pin number is to be looked up.
 *
 * \return The TWI peripheral's device SDA pin number.
 */
inline auto device_sda_number( Peripheral::TWI const & twi ) noexcept
{
    return sda_number( twi );
}

/**
 * \brief Lookup a TWI peripheral's device SDA pin mask.
 *
 * \param[in] twi The TWI peripheral whose device SDA pin mask is to be looked up.
 *
 * \return The TWI peripheral's device SDA pin mask.
 */
inline auto device_sda_mask( Peripheral::TWI const & twi ) noexcept
{
    return sda_mask( twi );
}

} // namespace picolibrary::Microchip::megaAVR0::Multiplexed_Signals

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_MULTIPLEXED_SIGNALS_TWI_H
