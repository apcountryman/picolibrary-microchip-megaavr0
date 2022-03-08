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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::TWI implementation.
 */

#include "picolibrary/microchip/megaavr0/peripheral/twi.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

static_assert( sizeof( TWI ) == 0x0E + 1 );
static_assert( TWI::CTRLA::Bit::RESERVED5 == 5 );
static_assert( TWI::DUALCTRL::Bit::RESERVED4 == 4 );
static_assert( TWI::DBGCTRL::Bit::RESERVED1 == 1 );
static_assert( TWI::MCTRLA::Bit::RIEN == 7 );
static_assert( TWI::MCTRLB::Bit::RESERVED4 == 4 );
static_assert( TWI::MSTATUS::Bit::RIF == 7 );
static_assert( TWI::SCTRLA::Bit::DIEN == 7 );
static_assert( TWI::SCTRLB::Bit::RESERVED3 == 3 );
static_assert( TWI::SSTATUS::Bit::DIF == 7 );
static_assert( TWI::SADDRMASK::Bit::ADDRMASK == 1 );

} // namespace picolibrary::Microchip::megaAVR0::Peripheral
