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
 * \brief picolibrary::Microchip::megaAVR0::I2C interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_I2C_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_I2C_H

#include <cstdint>

#include "picolibrary/error.h"
#include "picolibrary/i2c.h"
#include "picolibrary/microchip/megaavr0/peripheral/twi.h"
#include "picolibrary/postcondition.h"

/**
 * \brief Microchip megaAVR 0-series Inter-Integrated Circuit (I2C) facilities.
 */
namespace picolibrary::Microchip::megaAVR0::I2C {

/**
 * \brief TWI SDA hold time.
 */
enum class TWI_SDA_Hold_Time : std::uint8_t {
    OFF     = Peripheral::TWI::CTRLA::SDAHOLD_OFF,  ///< Off.
    _50_NS  = Peripheral::TWI::CTRLA::SDAHOLD_50NS, ///< 50 ns (short hold time).
    _300_NS = Peripheral::TWI::CTRLA::SDAHOLD_300NS, ///< 300 ns (meets the SMBus 2.0 specifications under typical conditions).
    _500_NS = Peripheral::TWI::CTRLA::SDAHOLD_500NS, ///< 500 ns (meets the SMBus 2.0 specifications across all corners).
};

/**
 * \brief TWI bus speed configuration.
 */
enum class TWI_Bus_Speed : std::uint8_t {
    STANDARD  = 0b0 << Peripheral::TWI::CTRLA::Bit::FMPEN, ///< Standard mode.
    FAST      = 0b0 << Peripheral::TWI::CTRLA::Bit::FMPEN, ///< Fast mode.
    FAST_PLUS = 0b1 << Peripheral::TWI::CTRLA::Bit::FMPEN, ///< Fast mode plus.
};

/**
 * \brief TWI inactive bus time-out.
 */
enum class TWI_Inactive_Bus_Time_Out : std::uint8_t {
    DISABLED = Peripheral::TWI::MCTRLA::TIMEOUT_DISABLED, ///< Disabled.
    _50_US   = Peripheral::TWI::MCTRLA::TIMEOUT_50US, ///< 50 us (SMBus, assumes clock frequency is set to 100 kHz).
    _100_US  = Peripheral::TWI::MCTRLA::TIMEOUT_100US, ///< 100 us (assumes clock frequency is set to 100 kHz).
    _200_US  = Peripheral::TWI::MCTRLA::TIMEOUT_200US, ///< 200 us (assumes clock frequency is set to 100 kHz).
};

/**
 * \brief Basic controller.
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
     * \param[in] twi The TWI to be used by the controller.
     * \param[in] twi_sda_hold_time The desired TWI SDA hold time.
     * \param[in] twi_bus_speed The desired TWI bus speed configuration.
     * \param[in] twi_clock_generator_scaling_factor The desired TWI clock generator
     *            scaling factor (MBAUD register value).
     * \param[in] twi_inactive_bus_time_out The desired TWI inactive bus time-out.
     */
    Basic_Controller(
        Peripheral::TWI &         twi,
        TWI_SDA_Hold_Time         twi_sda_hold_time,
        TWI_Bus_Speed             twi_bus_speed,
        std::uint8_t              twi_clock_generator_scaling_factor,
        TWI_Inactive_Bus_Time_Out twi_inactive_bus_time_out ) noexcept :
        m_twi{ &twi }
    {
        configure_controller(
            twi_sda_hold_time, twi_bus_speed, twi_clock_generator_scaling_factor, twi_inactive_bus_time_out );
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

    Basic_Controller( Basic_Controller const & ) = delete;

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
    constexpr auto & operator=( Basic_Controller && expression ) noexcept
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
     */
    void initialize() noexcept
    {
        enable_controller();

        force_bus_state_to_idle();
    }

    /**
     * \brief Check if a bus error is present.
     *
     * \return true if a bus error is present.
     * \return false if a bus error is not present.
     */
    auto bus_error_present() const noexcept
    {
        return controller_bus_error_present();
    }

    /**
     * \brief Transmit a start condition.
     */
    void start() noexcept
    {
    }

    /**
     * \brief Transmit a repeated start condition.
     */
    void repeated_start() noexcept
    {
    }

    /**
     * \brief Transmit a stop condition.
     */
    void stop() noexcept
    {
        transmit_stop();
    }

    /**
     * \brief Address a device.
     *
     * \param[in] address The address of the device to address.
     * \param[in] operation The operation that will be performed once the device has been
     *            addressed.
     *
     * \post the device has been addressed and a response has been received
     *
     * \return picolibrary::I2C::Response::ACK if an ACK response is received.
     * \return picolibrary::I2C::Response::NACK if a NACK response is received.
     */
    auto address( ::picolibrary::I2C::Address_Transmitted address, ::picolibrary::I2C::Operation operation ) noexcept
    {
        initiate_addressing( address, operation );

        while ( not addressing_complete() ) {} // while

        ensure( not controller_bus_error_present(), Generic_Error::BUS_ERROR );

        ensure( not arbitration_lost(), Generic_Error::ARBITRATION_LOST );

        return nack_received() ? ::picolibrary::I2C::Response::NACK
                               : ::picolibrary::I2C::Response::ACK;
    }

    /**
     * \brief Read data from a device.
     *
     * \param[in] response The response to transmit once the data has been read.
     *
     * \post data has been transmitted and a response has been received
     *
     * \return The data read from the device.
     */
    auto read( ::picolibrary::I2C::Response response ) noexcept
    {
        configure_read_response( response );

        while ( not read_complete() ) {} // while

        return data();
    }

    /**
     * \brief Write data to a device.
     *
     * \param[in] data The data to write to the device.
     *
     * \return picolibrary::I2C::Response::ACK if an ACK response is received.
     * \return picolibrary::I2C::Response::NACK if a NACK response is received.
     */
    auto write( std::uint8_t data ) noexcept
    {
        initiate_write( data );

        while ( not write_complete() ) {} // if

        ensure( not controller_bus_error_present(), Generic_Error::BUS_ERROR );

        ensure( not arbitration_lost(), Generic_Error::ARBITRATION_LOST );

        return nack_received() ? ::picolibrary::I2C::Response::NACK
                               : ::picolibrary::I2C::Response::ACK;
    }

  private:
    /**
     * \brief The TWI used by the controller.
     */
    Peripheral::TWI * m_twi{};

    /**
     * \brief Disable the controller.
     */
    constexpr void disable() noexcept
    {
        if ( m_twi ) {
            disable_controller();
        } // if
    }

    /**
     * \brief Configure the controller.
     *
     * \param[in] twi_sda_hold_time The desired TWI SDA hold time.
     * \param[in] twi_bus_speed The desired TWI bus speed configuration.
     * \param[in] twi_clock_generator_scaling_factor The desired TWI clock generator
     *            scaling factor (MBAUD register value).
     * \param[in] twi_inactive_bus_time_out The desired TWI inactive bus time-out.
     */
    void configure_controller(
        TWI_SDA_Hold_Time         twi_sda_hold_time,
        TWI_Bus_Speed             twi_bus_speed,
        std::uint8_t              twi_clock_generator_scaling_factor,
        TWI_Inactive_Bus_Time_Out twi_inactive_bus_time_out ) noexcept
    {
        m_twi->mbaud  = twi_clock_generator_scaling_factor;
        m_twi->mctrla = static_cast<std::uint8_t>( twi_inactive_bus_time_out )
                        | Peripheral::TWI::MCTRLA::Mask::SMEN;
        m_twi->ctrla = static_cast<std::uint8_t>( twi_sda_hold_time )
                       | static_cast<std::uint8_t>( twi_bus_speed );
    }

    /**
     * \brief Disable the controller.
     */
    void disable_controller() noexcept
    {
        m_twi->mctrla = 0;
    }

    /**
     * \brief Enable the controller.
     */
    void enable_controller() noexcept
    {
        m_twi->mctrla |= Peripheral::TWI::MCTRLA::Mask::ENABLE;
    }

    /**
     * \brief Force the bus state to idle.
     */
    void force_bus_state_to_idle() noexcept
    {
        m_twi->mstatus = Peripheral::TWI::MSTATUS::BUSSTATE_IDLE;
    }

    /**
     * \brief Check if a bus error is present.
     *
     * \return true if a bus error is present.
     * \return false if a bus error is not present.
     */
    auto controller_bus_error_present() const noexcept -> bool
    {
        return m_twi->mstatus & Peripheral::TWI::MSTATUS::Mask::BUSERR;
    }

    /**
     * \brief Transmit a stop condition.
     */
    void transmit_stop() noexcept
    {
        m_twi->mctrlb = Peripheral::TWI::MCTRLB::MCMD_STOP;
    }

    /**
     * \brief Check if arbitration was lost.
     *
     * \return true if arbitration was lost.
     * \return false if arbitration was not lost.
     */
    auto arbitration_lost() const noexcept -> bool
    {
        return m_twi->mstatus & Peripheral::TWI::MSTATUS::Mask::ARBLOST;
    }

    /**
     * \brief Check if a NACK was received.
     *
     * \return true if a NACK was received.
     * \return false if a NACK was not received.
     */
    auto nack_received() const noexcept -> bool
    {
        return m_twi->mstatus & Peripheral::TWI::MSTATUS::Mask::RXACK;
    }

    /**
     * \brief Initiate addressing of a device.
     *
     * \param[in] address The address of the device to address.
     * \param[in] operation The operation that will be performed once the device has been
     *            addressed.
     */
    void initiate_addressing( ::picolibrary::I2C::Address_Transmitted address, ::picolibrary::I2C::Operation operation ) noexcept
    {
        m_twi->maddr = address.as_unsigned_integer() | static_cast<std::uint8_t>( operation );
    }

    /**
     * \brief Check if device addressing is complete.
     *
     * \return true if device addressing is complete.
     * \return false if device addressing is not complete.
     */
    auto addressing_complete() const noexcept -> bool
    {
        return m_twi->mstatus
               & ( Peripheral::TWI::MSTATUS::Mask::RIF | Peripheral::TWI::MSTATUS::Mask::WIF );
    }

    /**
     * \brief Configure the response to be transmitted once data has been read.
     *
     * \param[in] response The response to transmit once the data has been read.
     */
    void configure_read_response( ::picolibrary::I2C::Response response ) noexcept
    {
        m_twi->mctrlb = response == ::picolibrary::I2C::Response::ACK
                            ? Peripheral::TWI::MCTRLB::ACKACT_ACK
                            : Peripheral::TWI::MCTRLB::ACKACT_NACK;
    }

    /**
     * \brief Check if a read is complete.
     *
     * \return true if the read is complete.
     * \return false if the read is not complete.
     */
    auto read_complete() const noexcept -> bool
    {
        return m_twi->mstatus & Peripheral::TWI::MSTATUS::Mask::RIF;
    }

    /**
     * \brief Get data read from a device.
     *
     * \return The data read from a device.
     */
    auto data() noexcept -> std::uint8_t
    {
        return m_twi->mdata;
    }

    /**
     * \brief Initiate a write.
     *
     * \param[in] data The data to write to the device.
     */
    void initiate_write( std::uint8_t data ) noexcept
    {
        m_twi->mdata = data;
    }

    /**
     * \brief Check if a write is complete.
     *
     * \return true if the write is complete.
     * \return false if the write is not complete.
     */
    auto write_complete() const noexcept -> bool
    {
        return m_twi->mstatus & Peripheral::TWI::MSTATUS::Mask::WIF;
    }
};

} // namespace picolibrary::Microchip::megaAVR0::I2C

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_I2C_H
