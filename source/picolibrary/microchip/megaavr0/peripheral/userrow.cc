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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::USERROW implementation.
 */

#include "picolibrary/microchip/megaavr0/peripheral/userrow.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

#if defined( __AVR_ATmega808__ ) || defined( __AVR_ATmega809__ ) \
    || defined( __AVR_ATmega1608__ ) || defined( __AVR_ATmega1609__ )
static_assert( sizeof( USERROW ) == 32 );
#endif // defined( __AVR_ATmega808__ ) || defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1608__ ) || defined( __AVR_ATmega1609__ )

#if defined( __AVR_ATmega3208__ ) || defined( __AVR_ATmega3209__ ) \
    || defined( __AVR_ATmega4808__ ) || defined( __AVR_ATmega4809__ )
static_assert( sizeof( USERROW ) == 64 );
#endif // defined( __AVR_ATmega3208__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4808__ ) || defined( __AVR_ATmega4809__ )

} // namespace picolibrary::Microchip::megaAVR0::Peripheral
