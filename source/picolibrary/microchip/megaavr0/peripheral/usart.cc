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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::USART implementation.
 */

#include "picolibrary/microchip/megaavr0/peripheral/usart.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

static_assert( sizeof( USART ) == 0x0E + 1 );
static_assert( USART::RXDATAH::Bit::RXCIF == 7 );
static_assert( USART::TXDATAH::Bit::RESERVED == 1 );
static_assert( USART::STATUS::Bit::RXCIF == 7 );
static_assert( USART::CTRLA::Bit::RXCIE == 7 );
static_assert( USART::CTRLB::Bit::RXEN == 7 );
static_assert(
    USART::CTRLC::Bit::PMODE + USART::CTRLC::Size::PMODE
    == USART::CTRLC::Bit::RESERVED3 + USART::CTRLC::Size::RESERVED3 );
static_assert( USART::CTRLC::Bit::CMODE == 6 );
static_assert( USART::CTRLD::Bit::ABW == 6 );
static_assert( USART::DBGCTRL::Bit::RESERVED == 1 );
static_assert( USART::EVCTRL::Bit::RESERVED == 1 );
static_assert( USART::RXPLCTRL::Bit::RESERVED == 7 );

} // namespace picolibrary::Microchip::megaAVR0::Peripheral
