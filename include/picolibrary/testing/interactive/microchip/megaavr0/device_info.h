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
 * \brief picolibrary::Testing::Interactive::Microchip::megaAVR0::Device_Info interface.
 */

#ifndef PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_DEVICE_INFO_H
#define PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_DEVICE_INFO_H

#include <utility>

#include "picolibrary/fatal_error.h"
#include "picolibrary/microchip/megaavr0/device_info.h"
#include "picolibrary/stream.h"

/**
 * \brief Microchip megaAVR 0-series device info interactive testing facilities.
 */
namespace picolibrary::Testing::Interactive::Microchip::megaAVR0::Device_Info {

/**
 * \brief Microchip megaAVR 0-series device info print interactive test helper.
 *
 * \param[in] stream The output stream to use to output information to the user.
 */
inline void print( Output_Stream & stream ) noexcept
{
    auto const print_result = stream.print(
        "{} (revision {}), serial number {}\n",
        ::picolibrary::Microchip::megaAVR0::Device_Info::device_type(),
        ::picolibrary::Microchip::megaAVR0::Device_Info::device_revision(),
        ::picolibrary::Microchip::megaAVR0::Device_Info::device_serial_number() );
    if ( print_result.is_error() ) {
        trap_fatal_error( print_result.error() );
    } // if
}

/**
 * \brief Microchip megaAVR 0-series device info print interactive test helper.
 *
 * \tparam Output_Stream The type of asynchronous serial output stream to use to output
 *         information to the user.
 * \tparam Transmitter The type of asynchronous serial transmitter to use to transmit
 *         information to the user.
 *
 * \param[in] transmitter The asynchronous serial transmitter to use to transmit
 *            information to the user.
 */
template<template<typename> typename Output_Stream, typename Transmitter>
inline void print( Transmitter transmitter ) noexcept
{
    auto stream = Output_Stream{ std::move( transmitter ) };

    {
        auto const result = stream.initialize();
        if ( result.is_error() ) {
            trap_fatal_error( result.error() );
        } // if
    }

    print( stream );
}

} // namespace picolibrary::Testing::Interactive::Microchip::megaAVR0::Device_Info

#endif // PICOLIBRARY_TESTING_INTERACTIVE_MICROCHIP_MEGAAVR0_DEVICE_INFO_H
