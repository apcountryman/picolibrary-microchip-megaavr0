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
 * \brief picolibrary::Microchip::megaAVR0::SPI interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_SPI_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_SPI_H

#include <cstdint>

#include "picolibrary/microchip/megaavr0/peripheral/port.h"
#include "picolibrary/microchip/megaavr0/peripheral/spi.h"
#include "picolibrary/microchip/megaavr0/peripheral/usart.h"

/**
 * \brief Microchip megaAVR 0-series Serial Peripheral Interface (SPI) facilities.
 */
namespace picolibrary::Microchip::megaAVR0::SPI {

/**
 * \brief SPI clock rate.
 */
enum class SPI_Clock_Rate : std::uint8_t {
    CLK_PER_2 = ( 0b1 << Peripheral::SPI::CTRLA::Bit::CLK2X )
                | Peripheral::SPI::CTRLA::PRESC_DIV4, ///< Peripheral clock frequency / 2.
    CLK_PER_4 = ( 0b0 << Peripheral::SPI::CTRLA::Bit::CLK2X )
                | Peripheral::SPI::CTRLA::PRESC_DIV4, ///< Peripheral clock frequency / 4.
    CLK_PER_8 = ( 0b1 << Peripheral::SPI::CTRLA::Bit::CLK2X )
                | Peripheral::SPI::CTRLA::PRESC_DIV16, ///< Peripheral clock frequency / 8.
    CLK_PER_16 = ( 0b0 << Peripheral::SPI::CTRLA::Bit::CLK2X )
                 | Peripheral::SPI::CTRLA::PRESC_DIV16, ///< Peripheral clock frequency / 16.
    CLK_PER_32 = ( 0b1 << Peripheral::SPI::CTRLA::Bit::CLK2X )
                 | Peripheral::SPI::CTRLA::PRESC_DIV64, ///< Peripheral clock frequency / 32.
    CLK_PER_64 = ( 0b0 << Peripheral::SPI::CTRLA::Bit::CLK2X )
                 | Peripheral::SPI::CTRLA::PRESC_DIV64, ///< Peripheral clock frequency / 64.
    CLK_PER_128 = ( 0b0 << Peripheral::SPI::CTRLA::Bit::CLK2X )
                  | Peripheral::SPI::CTRLA::PRESC_DIV128, ///< Peripheral clock frequency / 128.
};

/**
 * \brief SPI clock polarity.
 */
enum class SPI_Clock_Polarity : std::uint8_t {
    IDLE_LOW  = 0b00 << Peripheral::SPI::CTRLB::Bit::MODE, ///< Idle low.
    IDLE_HIGH = 0b10 << Peripheral::SPI::CTRLB::Bit::MODE, ///< Idle high.
};

/**
 * \brief SPI clock phase.
 */
enum class SPI_Clock_Phase : std::uint8_t {
    CAPTURE_IDLE_TO_ACTIVE = 0b00 << Peripheral::SPI::CTRLB::Bit::MODE, ///< Capture data on the idle-to-active clock transition.
    CAPTURE_ACTIVE_TO_IDLE = 0b01 << Peripheral::SPI::CTRLB::Bit::MODE, ///< Capture data on the active-to-idle clock transition.
};

/**
 * \brief SPI bit order.
 */
enum class SPI_Bit_Order : std::uint8_t {
    MSB_FIRST = 0b0 << Peripheral::SPI::CTRLA::Bit::DORD, ///< MSB first.
    LSB_FIRST = 0b1 << Peripheral::SPI::CTRLA::Bit::DORD, ///< LSB first.
};

/**
 * \brief USART clock polarity.
 */
enum class USART_Clock_Polarity : std::uint8_t {
    IDLE_LOW  = 0b0 << Peripheral::PORT::PINCTRL::Bit::INVEN, ///< Idle low.
    IDLE_HIGH = 0b1 << Peripheral::PORT::PINCTRL::Bit::INVEN, ///< Idle high.
};

/**
 * \brief USART clock phase.
 */
enum class USART_Clock_Phase : std::uint8_t {
    CAPTURE_IDLE_TO_ACTIVE = 0b0 << Peripheral::USART::CTRLC::Bit::UCPHA, ///< Capture data on the idle-to-active clock transition.
    CAPTURE_ACTIVE_TO_IDLE = 0b1 << Peripheral::USART::CTRLC::Bit::UCPHA, ///< Capture data on the active-to-idle clock transition.
};

/**
 * \brief USART bit order.
 */
enum class USART_Bit_Order : std::uint8_t {
    MSB_FIRST = 0b0 << Peripheral::USART::CTRLC::Bit::UDORD, ///< MSB first.
    LSB_FIRST = 0b1 << Peripheral::USART::CTRLC::Bit::UDORD, ///< LSB first.
};

/**
 * \brief Fixed configuration basic controller.
 *
 * \tparam Peripheral The type of peripheral used to implement fixed configuration
 *         controller functionality.
 */
template<typename Peripheral>
class Fixed_Configuration_Basic_Controller;

} // namespace picolibrary::Microchip::megaAVR0::SPI

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_SPI_H
