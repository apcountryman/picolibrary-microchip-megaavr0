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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::PORTMUX implementation.
 */

#include "picolibrary/microchip/megaavr0/peripheral/portmux.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

static_assert( sizeof( PORTMUX ) == 0x05 + 1 );
static_assert( PORTMUX::EVSYSROUTEA::Bit::RESERVED6 == 6 );
static_assert( PORTMUX::CCLROUTEA::Bit::RESERVED4 == 4 );
static_assert( PORTMUX::USARTROUTEA::Bit::USART3 == 6 );
static_assert( PORTMUX::TWISPIROUTEA::Bit::RESERVED6 == 6 );
static_assert( PORTMUX::TCAROUTEA::Bit::RESERVED3 == 3 );
static_assert( PORTMUX::TCBROUTEA::Bit::RESERVED4 == 4 );

} // namespace picolibrary::Microchip::megaAVR0::Peripheral
