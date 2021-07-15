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
 * \brief picolibrary::Microchip::megaAVR0::I2C interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_I2C_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_I2C_H

#include <cstdint>

#include "picolibrary/error.h"
#include "picolibrary/i2c.h"
#include "picolibrary/microchip/megaavr0/peripheral/twi.h"
#include "picolibrary/result.h"
#include "picolibrary/void.h"

/**
 * \brief Microchip megaAVR 0-series Inter-Integrated Circuit (I2C) facilities.
 */
namespace picolibrary::Microchip::megaAVR0::I2C {

/**
 * \brief I2C basic controller.
 */
class Basic_Controller {
  public:
    /**
     * \brief Constructor.
     */
    constexpr Basic_Controller() noexcept = default;

    /**
     * \brief Constructor.
     *
     * \param[in] twi The TWI peripheral used by the I2C controller.
     * \param[in] sda_hold_time The desired SDA hold time configuration.
     * \param[in] fast_mode_plus The desired fast mode plus configuration.
     * \param[in] clock_scaling_factor The desired clock scaling factor.
     * \param[in] timeout The desired inactive bus timeout configuration.
     */
    Basic_Controller(
        Peripheral::TWI &               twi,
        Peripheral::TWI::SDA_Hold_Time  sda_hold_time,
        Peripheral::TWI::Fast_Mode_Plus fast_mode_plus,
        std::uint8_t                    clock_scaling_factor,
        Peripheral::TWI::Timeout        timeout ) noexcept :
        m_twi{ &twi }
    {
        m_twi->configure_as_i2c_controller(
            sda_hold_time, fast_mode_plus, clock_scaling_factor, timeout );
    }

    /**
     * \brief Constructor.
     *
     * \param[in] source The source of the move.
     */
    constexpr Basic_Controller( Basic_Controller && source ) noexcept :
        m_twi{ source.m_twi }
    {
        source.m_twi = nullptr;
    }

    Basic_Controller( Basic_Controller const & source ) = delete;

    /**
     * \brief Destructor.
     */
    ~Basic_Controller() noexcept
    {
        disable();
    }

    /**
     * \brief Assignment operator.
     *
     * \param[in] expression The expression to be assigned.
     *
     * \return The assigned to object.
     */
    auto & operator=( Basic_Controller && expression ) noexcept
    {
        if ( &expression != this ) {
            disable();

            m_twi = expression.m_twi;

            expression.m_twi = nullptr;
        } // if

        return *this;
    }

    auto operator=( Basic_Controller const & ) = delete;

    /**
     * \brief Initialize the controller's hardware.
     *
     * \return Success.
     */
    auto initialize() noexcept -> Result<Void, Void>
    {
        m_twi->enable();

        return {};
    }

    /**
     * \brief Transmit a start condition.
     *
     * \return Success.
     */
    constexpr auto start() noexcept -> Result<Void, Void>
    {
        return {};
    }

    /**
     * \brief Transmit a repeated start condition.
     *
     * \return Success.
     */
    constexpr auto repeated_start() noexcept -> Result<Void, Void>
    {
        return {};
    }

    /**
     * \brief Transmit a stop condition.
     *
     * \return Success.
     */
    auto stop() noexcept -> Result<Void, Void>
    {
        m_twi->stop();

        return {};
    }

    /**
     * \brief Address a device.
     *
     * \param[in] address The address of the device to address.
     * \param[in] operation The operation that will be performed once the device has been
     *            addressed.
     *
     * \return Nothing if addressing the device succeeded.
     * \return picolibrary::Generic_Error::BUS_ERROR if a bus error occurred.
     * \return picolibrary::Generic_Error::ARBITRATION_LOST if the controller lost
     *         arbitration while attempting to address the device.
     * \return picolibrary::Generic_Error::NONRESPONSIVE_DEVICE if the device did not
     *         respond when addressed.
     */
    auto address( ::picolibrary::I2C::Address address, ::picolibrary::I2C::Operation operation ) noexcept
        -> Result<Void, Error_Code>
    {
        m_twi->address( address.transmitted() | static_cast<std::uint8_t>( operation ) );

        while ( not m_twi->addressing_complete() ) {}

        if ( m_twi->bus_error() ) {
            return Generic_Error::BUS_ERROR;
        } // if

        if ( m_twi->arbitration_lost() ) {
            return Generic_Error::ARBITRATION_LOST;
        } // if

        if ( m_twi->nack_received() ) {
            return Generic_Error::NONRESPONSIVE_DEVICE;
        } // if

        return {};
    }

    /**
     * \brief Read data from a device.
     *
     * \param[in] response The response to send after the data is read.
     *
     * \return The read data if the read succeeded.
     * \return picolibrary::Generic_Error::BUS_ERROR if a bus error occurred.
     */
    auto read( ::picolibrary::I2C::Response response ) noexcept -> Result<std::uint8_t, Error_Code>
    {
        m_twi->configure_read_response(
            response == ::picolibrary::I2C::Response::ACK ? Peripheral::TWI::Response::ACK
                                                          : Peripheral::TWI::Response::NACK );

        while ( not m_twi->data_available() ) {}

        if ( m_twi->bus_error() ) {
            return Generic_Error::BUS_ERROR;
        } // if

        return m_twi->receive();
    }

    /**
     * \brief Write data to a device.
     *
     * \param[in] data The data to write.
     *
     * \return Nothing if the write succeeded.
     * \return picolibrary::Generic_Error::BUS_ERROR if a bus error occurred.
     * \return picolibrary::Generic_Error::ARBITRATION_LOST if the controller lost
     *         arbitration while attempting to address the device.
     * \return picolibrary::Generic_Error::NONRESPONSIVE_DEVICE if the device did not
     *         acknowledge the write.
     */
    auto write( std::uint8_t data ) noexcept -> Result<Void, Error_Code>
    {
        m_twi->transmit( data );

        while ( not m_twi->transmission_complete() ) {}

        if ( m_twi->bus_error() ) {
            return Generic_Error::BUS_ERROR;
        } // if

        if ( m_twi->arbitration_lost() ) {
            return Generic_Error::ARBITRATION_LOST;
        } // if

        if ( m_twi->nack_received() ) {
            return Generic_Error::NONRESPONSIVE_DEVICE;
        } // if

        return {};
    }

  private:
    /**
     * \brief The TWI peripheral used by the I2C controller.
     */
    Peripheral::TWI * m_twi{};

    /**
     * \brief Disable the TWI.
     */
    void disable() noexcept
    {
        if ( m_twi ) {
            m_twi->disable();
        } // if
    }
};

} // namespace picolibrary::Microchip::megaAVR0::I2C

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_I2C_H
