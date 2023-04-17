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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::USERROW interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_USERROW_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_USERROW_H

#include <cstdint>

#include "picolibrary/microchip/megaavr0/register.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief Microchip megaAVR 0-series User Row (USERROW) peripheral.
 */
class USERROW {
  public:
#if defined( __AVR_ATmega808__ ) || defined( __AVR_ATmega809__ ) \
    || defined( __AVR_ATmega1608 ) || defined( __AVR_ATmega1609 )
    /**
     * \brief Data.
     */
    Register<std::uint8_t> data[ 32 ];
#endif // defined( __AVR_ATmega808__ ) || defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1608 ) || defined( __AVR_ATmega1609 )

#if defined( __AVR_ATmega3208__ ) || defined( __AVR_ATmega3209__ ) \
    || defined( __AVR_ATmega4808 ) || defined( __AVR_ATmega4809 )
    /**
     * \brief Data.
     */
    Register<std::uint8_t> data[ 64 ];
#endif // defined( __AVR_ATmega3208__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4808 ) || defined( __AVR_ATmega4809 )

    USERROW() = delete;

    USERROW( USERROW && ) = delete;

    USERROW( USERROW const & ) = delete;

    ~USERROW() = delete;

    auto operator=( USERROW && ) = delete;

    auto operator=( USERROW const & ) = delete;
};

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_USERROW_H
