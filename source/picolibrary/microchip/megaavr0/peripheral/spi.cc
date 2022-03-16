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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::SPI implementation.
 */

#include "picolibrary/microchip/megaavr0/peripheral/spi.h"

namespace picolibrary::Microchip::megaAVR0::Peripheral {

static_assert( sizeof( SPI ) == 0x04 + 1 );
static_assert( SPI::CTRLA::Bit::RESERVED7 == 7 );
static_assert( SPI::CTRLB::Bit::BUFEN == 7 );
static_assert( SPI::INTCTRL::Bit::RXCIE == 7 );
static_assert( SPI::INTFLAGS::Bit::IF == 7 );
static_assert( SPI::INTFLAGS::Bit::RXCIF == 7 );

} // namespace picolibrary::Microchip::megaAVR0::Peripheral
