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
 * \brief picolibrary::Microchip::megaAVR0::Asynchronous_Serial interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_H

#include <cstdint>

#include "picolibrary/microchip/megaavr0/peripheral/usart.h"

/**
 * \brief Microchip megaAVR 0-series asynchronous serial facilities.
 */
namespace picolibrary::Microchip::megaAVR0::Asynchronous_Serial {

/**
 * \brief USART data bits configuration.
 */
enum class USART_Data_Bits : std::uint8_t {
    _5 = Peripheral::USART::CTRLC::CHSIZE_5BIT,  ///< 5.
    _6 = Peripheral::USART::CTRLC::CHSIZE_6BIT,  ///< 6.
    _7 = Peripheral::USART::CTRLC::CHSIZE_7BIT,  ///< 7.
    _8 = Peripheral::USART::CTRLC::CHSIZE_8BIT,  ///< 8.
    _9 = Peripheral::USART::CTRLC::CHSIZE_9BITH, ///< 9.
};

} // namespace picolibrary::Microchip::megaAVR0::Asynchronous_Serial

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_ASYNCHRONOUS_SERIAL_H
