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
 * \brief picolibrary::Microchip::megaAVR0::Device_Info interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_DEVICE_INFO_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_DEVICE_INFO_H

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <limits>

#include "picolibrary/array.h"
#include "picolibrary/error.h"
#include "picolibrary/microchip/megaavr0/peripheral.h"
#include "picolibrary/microchip/megaavr0/peripheral/sigrow.h"
#include "picolibrary/result.h"
#include "picolibrary/stream.h"

/**
 * \brief Microchip megaAVR 0-series watchdog timer facilities.
 */
namespace picolibrary::Microchip::megaAVR0::Device_Info {

/**
 * \brief Device type.
 */
enum class Device_Type : std::uint24_t {
    ATMEGA808  = 0x1E9326, ///< ATmega808.
    ATMEGA809  = 0x1E932A, ///< ATmega809.
    ATMEGA1608 = 0x1E9427, ///< ATmega1608.
    ATMEGA1609 = 0x1E9426, ///< ATmega1609.
    ATMEGA3208 = 0x1E9530, ///< ATmega3208.
    ATMEGA3209 = 0x1E9531, ///< ATmega3209.
    ATMEGA4808 = 0x1E9650, ///< ATmega4808.
    ATMEGA4809 = 0x1E9651, ///< ATmega4809.
};

/**
 * \brief Device revision.
 */
class Device_Revision {
  public:
    /**
     * \brief Device revision unsigned integer representation.
     */
    using Unsigned_Integer = std::uint8_t;

    /**
     * \brief Device revision printable character representation.
     */
    using Printable_Character = char;

    /**
     * \brief Constructor.
     */
    constexpr Device_Revision() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] device_revision The device revision.
     */
    constexpr Device_Revision( Unsigned_Integer device_revision ) noexcept :
        m_device_revision{ device_revision }
    {
    }

    /**
     * \brief Constructor.
     *
     * \param[in] device_revision The device revision.
     */
    constexpr Device_Revision( Printable_Character device_revision ) noexcept :
        m_device_revision{ static_cast<Unsigned_Integer>( device_revision - 'A' ) }
    {
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Device_Revision( Device_Revision && source ) noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] original The original to copy.
     */
    constexpr Device_Revision( Device_Revision const & original ) noexcept = default;

    /**
     * \brief Destructor.
     */
    ~Device_Revision() noexcept = default;

    /**
     * \brief Assignment operator.
     *
     * \param[in] expression The expression to be assigned.
     *
     * \return The assigned to object.
     */
    constexpr auto operator=( Device_Revision && expression ) noexcept -> Device_Revision & = default;

    /**
     * \brief Assignment operator.
     *
     * \param[in] expression The expression to be assigned.
     *
     * \return The assigned to object.
     */
    constexpr auto operator  =( Device_Revision const & expression ) noexcept
        -> Device_Revision & = default;

    /**
     * \brief Get the device revision in its unsigned integer representation.
     *
     * \return The device revision in its unsigned integer representation.
     */
    constexpr auto as_unsigned_integer() const noexcept -> Unsigned_Integer
    {
        return m_device_revision;
    }

    /**
     * \brief Get the device revision in its printable character representation.
     *
     * \return The device revision in its printable character representation.
     */
    constexpr auto as_printable_character() const noexcept -> Printable_Character
    {
        return m_device_revision + 'A';
    }

  private:
    /**
     * \brief The device revision.
     */
    Unsigned_Integer m_device_revision{ 0 };
};

/**
 * \brief Equality operator.
 *
 * \relatedalso picolibrary::Microchip::megaAVR0::Device_Info::Device_Revision
 *
 * \param[in] lhs The left hand side of the comparison.
 * \param[in] rhs The right hand side of the comparison.
 *
 * \return true if lhs is equal to rhs.
 * \return false if lhs is not equal to rhs.
 */
constexpr auto operator==( Device_Revision lhs, Device_Revision rhs ) noexcept -> bool
{
    return lhs.as_unsigned_integer() == rhs.as_unsigned_integer();
}

/**
 * \brief Equality operator.
 *
 * \relatedalso picolibrary::Microchip::megaAVR0::Device_Info::Device_Revision
 *
 * \param[in] lhs The left hand side of the comparison.
 * \param[in] rhs The right hand side of the comparison.
 *
 * \return true if lhs is not equal to rhs.
 * \return false if lhs is equal to rhs.
 */
constexpr auto operator!=( Device_Revision lhs, Device_Revision rhs ) noexcept -> bool
{
    return not( lhs == rhs );
}

/**
 * \brief Less than operator.
 *
 * \relatedalso picolibrary::Microchip::megaAVR0::Device_Info::Device_Revision
 *
 * \param[in] lhs The left hand side of the comparison.
 * \param[in] rhs The right hand side of the comparison.
 *
 * \return true if lhs is less than rhs.
 * \return false if lhs is not less than rhs.
 */
constexpr auto operator<( Device_Revision lhs, Device_Revision rhs ) noexcept -> bool
{
    return lhs.as_unsigned_integer() < rhs.as_unsigned_integer();
}

/**
 * \brief Greater than operator.
 *
 * \relatedalso picolibrary::Microchip::megaAVR0::Device_Info::Device_Revision
 *
 * \param[in] lhs The left hand side of the comparison.
 * \param[in] rhs The right hand side of the comparison.
 *
 * \return true if lhs is greater than rhs.
 * \return false if lhs is not greater than rhs.
 */
constexpr auto operator>( Device_Revision lhs, Device_Revision rhs ) noexcept -> bool
{
    return rhs < lhs;
}

/**
 * \brief Less than or equal to operator.
 *
 * \relatedalso picolibrary::Microchip::megaAVR0::Device_Info::Device_Revision
 *
 * \param[in] lhs The left hand side of the comparison.
 * \param[in] rhs The right hand side of the comparison.
 *
 * \return true if lhs is less than or equal to rhs.
 * \return false if lhs is not less than or equal to rhs.
 */
constexpr auto operator<=( Device_Revision lhs, Device_Revision rhs ) noexcept -> bool
{
    return not( lhs > rhs );
}

/**
 * \brief Greater than or equal to operator.
 *
 * \relatedalso picolibrary::Microchip::megaAVR0::Device_Info::Device_Revision
 *
 * \param[in] lhs The left hand side of the comparison.
 * \param[in] rhs The right hand side of the comparison.
 *
 * \return true if lhs is greater than or equal to rhs.
 * \return false if lhs is not greater than or equal to rhs.
 */
constexpr auto operator>=( Device_Revision lhs, Device_Revision rhs ) noexcept -> bool
{
    return not( lhs < rhs );
}

/**
 * \brief Device revision.
 */
class Device_Serial_Number {
  public:
    /**
     * \brief Device serial number array representation.
     */
    using Array = ::picolibrary::Array<std::uint8_t, sizeof( Peripheral::SIGROW::sernum )>;

    /**
     * \brief Constructor.
     */
    constexpr Device_Serial_Number() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] serial_number The device serial number.
     */
    constexpr Device_Serial_Number( Array const & serial_number ) noexcept :
        m_serial_number{ serial_number }
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
     * \brief Get the device serial number in its array representation.
     *
     * \return The device serial number in its array representation.
     */
    constexpr auto as_array() const noexcept -> Array
    {
        return m_serial_number;
    }

  private:
    /**
     * \brief The device serial number.
     */
    Array m_serial_number{};
};

/**
 * \brief Equality operator.
 *
 * \relatedalso picolibrary::Microchip::megaAVR0::Device_Info::Device_Serial_Number
 *
 * \param[in] lhs The left hand side of the comparison.
 * \param[in] rhs The right hand side of the comparison.
 *
 * \return true if lhs is equal to rhs.
 * \return false if lhs is not equal to rhs.
 */
constexpr auto operator==( Device_Serial_Number const & lhs, Device_Serial_Number const & rhs ) noexcept
    -> bool
{
    return lhs.as_array() == rhs.as_array();
}

/**
 * \brief Equality operator.
 *
 * \relatedalso picolibrary::Microchip::megaAVR0::Device_Info::Device_Serial_Number
 *
 * \param[in] lhs The left hand side of the comparison.
 * \param[in] rhs The right hand side of the comparison.
 *
 * \return true if lhs is not equal to rhs.
 * \return false if lhs is equal to rhs.
 */
constexpr auto operator!=( Device_Serial_Number const & lhs, Device_Serial_Number const & rhs ) noexcept
    -> bool
{
    return not( lhs == rhs );
}

/**
 * \brief Get the device type.
 *
 * \return The device type.
 */
inline auto device_type() noexcept -> Device_Type
{
    auto const & sigrow = Peripheral::SIGROW0::instance();

    return static_cast<Device_Type>(
        ( static_cast<std::uint24_t>( sigrow.deviceid[ 0 ] )
          << ( 2 * std::numeric_limits<std::uint8_t>::digits ) )
        | ( static_cast<std::uint24_t>( sigrow.deviceid[ 1 ] )
            << ( 1 * std::numeric_limits<std::uint8_t>::digits ) )
        | ( static_cast<std::uint24_t>( sigrow.deviceid[ 2 ] )
            << ( 0 * std::numeric_limits<std::uint8_t>::digits ) ) );
}

/**
 * \brief Get the device revision.
 *
 * \return The device revision.
 */
inline auto device_revision() noexcept -> Device_Revision
{
    return Device_Revision{ Peripheral::SYSCFG0::instance().revid };
}

/**
 * \brief Get the device serial number.
 *
 * \return The device serial number.
 */
inline auto device_serial_number() noexcept -> Device_Serial_Number
{
    auto const & sigrow = Peripheral::SIGROW0::instance();

    return Device_Serial_Number{ Device_Serial_Number::Array{
        sigrow.sernum[ 0 ],
        sigrow.sernum[ 1 ],
        sigrow.sernum[ 2 ],
        sigrow.sernum[ 3 ],
        sigrow.sernum[ 4 ],
        sigrow.sernum[ 5 ],
        sigrow.sernum[ 6 ],
        sigrow.sernum[ 7 ],
        sigrow.sernum[ 8 ],
        sigrow.sernum[ 9 ],
    } };
}

} // namespace picolibrary::Microchip::megaAVR0::Device_Info

namespace picolibrary {

/**
 * \brief picolibrary::Microchip::megaAVR0::Device_Info::Device_Type output formatter.
 *
 * picolibrary::Microchip::megaAVR0::Device_Info::Device_Type only supports the default
 * format specification ("{}").
 */
template<>
class Output_Formatter<Microchip::megaAVR0::Device_Info::Device_Type> {
  public:
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

    auto operator=( Output_Formatter && ) = delete;

    auto operator=( Output_Formatter const & ) = delete;

    /**
     * \brief Parse the format specification for the
     *        picolibrary::Microchip::megaAVR0::Device_Info::Device_Type to be formatted.
     *
     * \param[in] format The format specification for the
     *            picolibrary::Microchip::megaAVR0::Device_Info::Device_Type to be
     *            formatted.
     *
     * \return format
     */
    constexpr auto parse( char const * format ) noexcept -> char const *
    {
        return format;
    }

    /**
     * \brief Write the formatted
     *        picolibrary::Microchip::megaAVR0::Device_Info::Device_Type to the stream.
     *
     * \param[in] stream The stream to write the formatted
     *            picolibrary::Microchip::megaAVR0::Device_Info::Device_Type to.
     * \param[in] device_type The
     *            picolibrary::Microchip::megaAVR0::Device_Info::Device_Type to format.
     *
     * \return The number of characters written to the stream if the write succeeded.
     * \return An error code if the write failed.
     */
    auto print( Output_Stream & stream, Microchip::megaAVR0::Device_Info::Device_Type const & device_type ) noexcept
        -> Result<std::size_t, Error_Code>
    {
        auto const device_type_as_string = to_string( device_type );

        auto result = stream.put( device_type_as_string );
        if ( result.is_error() ) {
            return result.error();
        } // if

        return std::strlen( device_type_as_string );
    }

  private:
    /**
     * \brief Convert a picolibrary::Microchip::megaAVR0::Device_Info::Device_Type to a
     *        null-terminated string.
     *
     * \param[in] device_type The
     *            picolibrary::Microchip::megaAVR0::Device_Info::Device_Type to convert.
     *
     * \return The picolibrary::Microchip::megaAVR0::Device_Info::Device_Type converted to
     *         a null-terminated string.
     */
    static constexpr auto to_string( Microchip::megaAVR0::Device_Info::Device_Type const & device_type ) noexcept
        -> char const *
    {
        switch ( device_type ) {
            case Microchip::megaAVR0::Device_Info::Device_Type::ATMEGA808:
                return "ATmega808";
            case Microchip::megaAVR0::Device_Info::Device_Type::ATMEGA809:
                return "ATmega809";
            case Microchip::megaAVR0::Device_Info::Device_Type::ATMEGA1608:
                return "ATmega1608";
            case Microchip::megaAVR0::Device_Info::Device_Type::ATMEGA1609:
                return "ATmega1609";
            case Microchip::megaAVR0::Device_Info::Device_Type::ATMEGA3208:
                return "ATmega3208";
            case Microchip::megaAVR0::Device_Info::Device_Type::ATMEGA3209:
                return "ATmega3209";
            case Microchip::megaAVR0::Device_Info::Device_Type::ATMEGA4808:
                return "ATmega4808";
            case Microchip::megaAVR0::Device_Info::Device_Type::ATMEGA4809:
                return "ATmega4809";
        } // switch

        return "UNKNOWN";
    }
};

/**
 * \brief picolibrary::Microchip::megaAVR0::Device_Info::Device_Revision output formatter.
 *
 * picolibrary::Microchip::megaAVR0::Device_Info::Device_Revision only supports the
 * default format specification ("{}").
 */
template<>
class Output_Formatter<Microchip::megaAVR0::Device_Info::Device_Revision> {
  public:
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

    auto operator=( Output_Formatter && ) = delete;

    auto operator=( Output_Formatter const & ) = delete;

    /**
     * \brief Parse the format specification for the
     *        picolibrary::Microchip::megaAVR0::Device_Info::Device_Revision to be
     *        formatted.
     *
     * \param[in] format The format specification for the
     *            picolibrary::Microchip::megaAVR0::Device_Info::Device_Revision to be
     *            formatted.
     *
     * \return format
     */
    constexpr auto parse( char const * format ) noexcept -> char const *
    {
        return format;
    }

    /**
     * \brief Write the formatted
     *        picolibrary::Microchip::megaAVR0::Device_Info::Device_Revision to the
     *        stream.
     *
     * \param[in] stream The stream to write the formatted
     *            picolibrary::Microchip::megaAVR0::Device_Info::Device_Revision to.
     * \param[in] device_revision The
     *            picolibrary::Microchip::megaAVR0::Device_Info::Device_Revision to
     *            format.
     *
     * \return The number of characters written to the stream if the write succeeded.
     * \return An error code if the write failed.
     */
    auto print( Output_Stream & stream, Microchip::megaAVR0::Device_Info::Device_Revision device_revision ) noexcept
        -> Result<std::size_t, Error_Code>
    {
        auto result = stream.put( device_revision.as_printable_character() );
        if ( result.is_error() ) {
            return result.error();
        } // if

        return std::size_t{ 1 };
    }
};

/**
 * \brief picolibrary::Microchip::megaAVR0::Device_Info::Device_Serial_Number output
 *        formatter.
 *
 * picolibrary::Microchip::megaAVR0::Device_Info::Device_Serial_Number only supports the
 * default format specification ("{}").
 */
template<>
class Output_Formatter<Microchip::megaAVR0::Device_Info::Device_Serial_Number> {
  public:
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

    auto operator=( Output_Formatter && ) = delete;

    auto operator=( Output_Formatter const & ) = delete;

    /**
     * \brief Parse the format specification for the
     *        picolibrary::Microchip::megaAVR0::Device_Info::Device_Serial_Number to be
     *        formatted.
     *
     * \param[in] format The format specification for the
     *            picolibrary::Microchip::megaAVR0::Device_Info::Device_Serial_Number to
     *            be formatted.
     *
     * \return format
     */
    constexpr auto parse( char const * format ) noexcept -> char const *
    {
        return format;
    }

    /**
     * \brief Write the formatted
     *        picolibrary::Microchip::megaAVR0::Device_Info::Device_Serial_Number to the
     *        stream.
     *
     * \param[in] stream The stream to write the formatted
     *            picolibrary::Microchip::megaAVR0::Device_Info::Device_Serial_Number to.
     * \param[in] device_type The
     *            picolibrary::Microchip::megaAVR0::Device_Info::Device_Serial_Number to
     *            format.
     *
     * \return The number of characters written to the stream if the write succeeded.
     * \return An error code if the write failed.
     */
    auto print( Output_Stream & stream, Microchip::megaAVR0::Device_Info::Device_Serial_Number const & device_serial_number ) noexcept
        -> Result<std::size_t, Error_Code>
    {
        // #lizard forgives the length

        constexpr auto bytes = array_size_v<Microchip::megaAVR0::Device_Info::Device_Serial_Number::Array>;

        constexpr auto byte_nibbles =
            std::numeric_limits<Microchip::megaAVR0::Device_Info::Device_Serial_Number::Array::Value>::digits
            / 4;

        Array<char, 2 + bytes * byte_nibbles> hexadecimal;

        auto i = hexadecimal.rbegin();
        for ( auto byte : device_serial_number.as_array() ) {
            for ( auto byte_nibble = 0; byte_nibble < byte_nibbles; ++byte_nibble ) {
                auto const n = byte & 0x0F;

                *i = n < 0xA ? '0' + n : 'A' + ( n - 0xA );

                ++i;
                byte >>= 4;
            } // for
        }     // for
        *i = 'x';
        ++i;
        *i = '0';

        auto result = stream.put( hexadecimal.begin(), hexadecimal.end() );
        if ( result.is_error() ) {
            return result.error();
        } // if

        return hexadecimal.size();
    }
};

} // namespace picolibrary

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_DEVICE_INFO_H
