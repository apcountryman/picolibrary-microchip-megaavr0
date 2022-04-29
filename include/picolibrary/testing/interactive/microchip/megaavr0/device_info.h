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
 * \brief picolibrary::Testing::Interactive::Microchip::megaAVR0::Device_Info interface.
 */

#ifndef PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_DEVICE_INFO_H
#define PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_DEVICE_INFO_H

#include "picolibrary/microchip/megaavr0/device_info.h"
#include "picolibrary/precondition.h"
#include "picolibrary/stream.h"

/**
 * \brief Microchip megaAVR 0-series device info interactive testing facilities.
 */
namespace picolibrary::Testing::Interactive::Microchip::megaAVR0::Device_Info {

/**
 * \brief Print interactive test helper.
 *
 * \param[in] stream The output stream to write the device info to.
 *
 * \pre writing to the stream succeeds
 */
inline void print( Output_Stream & stream ) noexcept
{
    auto const result = stream.print(
        "{} (revision {}), serial number {}\n",
        ::picolibrary::Microchip::megaAVR0::Device_Info::device_type(),
        ::picolibrary::Microchip::megaAVR0::Device_Info::device_revision(),
        ::picolibrary::Microchip::megaAVR0::Device_Info::device_serial_number() );
    expect( not result.is_error(), result.error() );
}

} // namespace picolibrary::Testing::Interactive::Microchip::megaAVR0::Device_Info

#endif // PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_DEVICE_INFO_H
