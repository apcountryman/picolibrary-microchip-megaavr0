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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL implementation.
 */

#include "picolibrary/microchip/megaavr0/peripheral/clkctrl.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

static_assert( sizeof( CLKCTRL ) == 0x1C + 1 );
static_assert( CLKCTRL::MCLKCTRLA::Bit::CLKOUT == 7 );
static_assert( CLKCTRL::MCLKCTRLB::Bit::RESERVED5 == 5 );
static_assert( CLKCTRL::MCLKLOCK::Bit::RESERVED1 == 1 );
static_assert( CLKCTRL::MCLKSTATUS::Bit::EXTS == 7 );
static_assert( CLKCTRL::OSC20MCTRLA::Bit::RESERVED2 == 2 );
static_assert( CLKCTRL::OSC20MCALIBA::Bit::RESERVED7 == 7 );
static_assert( CLKCTRL::OSC20MCALIBB::Bit::LOCK == 7 );
static_assert( CLKCTRL::OSC32KCTRLA::Bit::RESERVED2 == 2 );
static_assert( CLKCTRL::XOSC32KCTRLA::Bit::RESERVED6 == 6 );

} // namespace picolibrary::Microchip::megaAVR0::Peripheral
