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

#include "picolibrary/microchip/megaavr0/peripheral/twi.h"

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

} // namespace picolibrary::Microchip::megaAVR0::I2C

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_I2C_H
