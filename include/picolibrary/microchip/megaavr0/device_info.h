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

#include <cstdint>
#include <limits>

#include "picolibrary/array.h"
#include "picolibrary/microchip/megaavr0/peripheral.h"
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

/**
 * \brief Get the device type.
 *
 * \return The device type.
 */
inline auto device_type() noexcept
{
    return Peripheral::SIGROW0::instance().device_type();
}

/**
 * \brief Get the device revision.
 *
 * \return The device revision.
 */
inline auto device_revision() noexcept
{
    return Peripheral::SYSCFG0::instance().device_revision();
}

/**
 * \brief Device serial number.
 */
class Device_Serial_Number {
  public:
    /**
     * \brief Device serial number array.
     */
    using Array = Peripheral::SIGROW::Device_Serial_Number;

    /**
     * \brief Constructor.
     */
    constexpr Device_Serial_Number() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] array The device serial number array.
     */
    constexpr Device_Serial_Number( Array const & array ) noexcept : m_array{ array }
    {
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Device_Serial_Number( Device_Serial_Number && source ) noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] original The original to copy.
     */
    constexpr Device_Serial_Number( Device_Serial_Number const & original ) noexcept = default;

    /**
     * \brief Destructor.
     */
    ~Device_Serial_Number() noexcept = default;

    /**
     * \brief Assignment operator.
     *
     * \param[in] expression The expression to be assigned.
     *
     * \return The assigned to object.
     */
    constexpr auto operator       =( Device_Serial_Number && expression ) noexcept
        -> Device_Serial_Number & = default;

    /**
     * \brief Assignment operator.
     *
     * \param[in] expression The expression to be assigned.
     *
     * \return The assigned to object.
     */
    constexpr auto operator       =( Device_Serial_Number const & expression ) noexcept
        -> Device_Serial_Number & = default;

    /**
     * \brief Access the device serial number array.
     *
     * \return The device serial number array.
     */
    auto const & array() const noexcept
    {
        return m_array;
    }

  private:
    /**
     * \brief The device serial number array.
     */
    Array m_array{};
};

/**
 * \brief Get the device serial number.
 *
 * \return The device serial number.
 */
inline auto device_serial_number() noexcept
{
    return Device_Serial_Number{ Peripheral::SIGROW0::instance().device_serial_number() };
}

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

/**
 * \brief Microchip megaAVR 0-series device serial number output formatter.
 *
 * Microchip megaAVR 0-series device serial numbers only support the default format
 * specification ("{}").
 */
template<>
class Output_Formatter<Microchip::megaAVR0::Device_Info::Device_Serial_Number> {
  public:
    /**
     * \brief Device serial number.
     */
    using Device_Serial_Number = Microchip::megaAVR0::Device_Info::Device_Serial_Number;

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
     * \brief Parse the format specification for the device serial number to be formatted.
     *
     * \param[in] format The format specification for the device serial number to be
     *            formatted.
     *
     * \return format.
     */
    constexpr auto parse( char const * format ) noexcept -> Result<char const *, Void>
    {
        return format;
    }

    /**
     * \brief Write the device serial number to the stream.
     *
     * \param[in] stream The stream to write the device serial number to.
     * \param[in] device_type The device serial number to write to the stream.
     *
     * \return Nothing if the write succeeded.
     * \return An error code if the write failed.
     */
    auto print( Output_Stream & stream, Device_Serial_Number const & device_serial_number ) noexcept
    {
        constexpr auto byte_nibbles = std::numeric_limits<Device_Serial_Number::Array::Value>::digits / 4;
        constexpr auto device_serial_number_nibbles = array_size_v<Device_Serial_Number::Array> * byte_nibbles;

        Array<char, 2 + device_serial_number_nibbles> hexadecimal;

        auto i = hexadecimal.rbegin();
        for ( auto byte : device_serial_number.array() ) {
            for ( auto byte_nibble = 0; byte_nibble < byte_nibbles; ++byte_nibble ) {
                auto const n = byte & 0x0F;

                *i = n < 0xA ? n + '0' : n - 0xA + 'A';

                ++i;
                byte >>= 4;
            } // for
        }     // for
        *i = 'x';
        ++i;
        *i = '0';

        return stream.put( hexadecimal.begin(), hexadecimal.end() );
    }
};

} // namespace picolibrary

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_DEVICE_INFO_H
