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
 * \brief picolibrary::Microchip::megaAVR0::Device_Info interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_DEVICE_INFO_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_DEVICE_INFO_H

#include "picolibrary/microchip/megaavr0/peripheral/sigrow.h"
#include "picolibrary/result.h"
#include "picolibrary/stream.h"
#include "picolibrary/void.h"

/**
 * \brief Microchip megaAVR 0-series device info facilities.
 */
namespace picolibrary::Microchip::megaAVR0::Device_Info {

/**
 * \brief Device type.
 */
using Device_Type = Peripheral::SIGROW::Device_Type;

} // namespace picolibrary::Microchip::megaAVR0::Device_Info

namespace picolibrary {

/**
 * \brief Microchip megaAVR 0-series device type output formatter.
 *
 * Microchip megaAVR 0-series device types only support the default format specification
 * ("{}").
 */
template<>
class Output_Formatter<Microchip::megaAVR0::Device_Info::Device_Type> {
  public:
    /**
     * \brief Device type.
     */
    using Device_Type = Microchip::megaAVR0::Device_Info::Device_Type;

    /**
     * \brief Constructor.
     */
    constexpr Output_Formatter() noexcept = default;

    Output_Formatter( Output_Formatter && ) = delete;

    Output_Formatter( Output_Formatter const & ) = delete;

    /**
     * \brief Destructor.
     */
    ~Output_Formatter() noexcept = default;

    /**
     * \brief Parse the format specification for the device type to be formatted.
     *
     * \param[in] format The format specification for the device type to be formatted.
     *
     * \return format.
     */
    constexpr auto parse( char const * format ) noexcept -> Result<char const *, Void>
    {
        return format;
    }

    /**
     * \brief Write the device type to the stream.
     *
     * \param[in] stream The stream to write the device type to.
     * \param[in] device_type The device type to write to the stream.
     *
     * \return Nothing if the write succeeded.
     * \return An error code if the write failed.
     */
    auto print( Output_Stream & stream, Device_Type const & device_type ) noexcept
    {
        return stream.put( device_type_as_string( device_type ) );
    }

  private:
    /**
     * \brief Get the string representation of a device type.
     *
     * \param[in] device_type The device type whose string representation is to be
     *            gotten.
     *
     * \return The string representation of the device type.
     */
    static constexpr auto device_type_as_string( Device_Type const & device_type ) noexcept
        -> char const *
    {
        switch ( device_type ) {
            case Device_Type::ATmega808: return "ATmega808";
            case Device_Type::ATmega809: return "ATmega809";
            case Device_Type::ATmega1608: return "ATmega1608";
            case Device_Type::ATmega1609: return "ATmega1609";
            case Device_Type::ATmega3208: return "ATmega3208";
            case Device_Type::ATmega3209: return "ATmega3209";
            case Device_Type::ATmega4808: return "ATmega4808";
            case Device_Type::ATmega4809: return "ATmega4809";
        } // switch

        return "unknown device type";
    }
};

} // namespace picolibrary

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_DEVICE_INFO_H
