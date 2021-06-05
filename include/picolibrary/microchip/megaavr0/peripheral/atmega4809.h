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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral::ATmega4809 interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_ATMEGA4809_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_ATMEGA4809_H

#include "picolibrary/microchip/megaavr0/peripheral/clkctrl.h"
#include "picolibrary/microchip/megaavr0/peripheral/port.h"
#include "picolibrary/microchip/megaavr0/peripheral/portmux.h"
#include "picolibrary/microchip/megaavr0/peripheral/spi.h"
#include "picolibrary/microchip/megaavr0/peripheral/usart.h"
#include "picolibrary/microchip/megaavr0/peripheral/vport.h"

/**
 * \brief Microchip megaAVR 0-series ATmega4809 peripherals.
 *
 * \attention The contents of this namespace should never be used directly. Instead, set
 *            the `-mmcu` compiler flag to `atmega4809` and use them through the
 *            picolibrary::Microchip::megaAVR0::Peripheral namespace.
 */
namespace picolibrary::Microchip::megaAVR0::Peripheral::ATmega4809 {

/**
 * \brief VPORTA.
 *
 * \attention This type should never be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega4809` and use
 *            picolibrary::Microchip::megaAVR0::Peripheral::VPORTA.
 */
using VPORTA = VPORT_Instance<0x0000>;

/**
 * \brief VPORTB.
 *
 * \attention This type should never be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega4809` and use
 *            picolibrary::Microchip::megaAVR0::Peripheral::VPORTB.
 */
using VPORTB = VPORT_Instance<0x0004>;

/**
 * \brief VPORTC.
 *
 * \attention This type should never be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega4809` and use
 *            picolibrary::Microchip::megaAVR0::Peripheral::VPORTC.
 */
using VPORTC = VPORT_Instance<0x0008>;

/**
 * \brief VPORTD.
 *
 * \attention This type should never be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega4809` and use
 *            picolibrary::Microchip::megaAVR0::Peripheral::VPORTD.
 */
using VPORTD = VPORT_Instance<0x000C>;

/**
 * \brief VPORTE.
 *
 * \attention This type should never be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega4809` and use
 *            picolibrary::Microchip::megaAVR0::Peripheral::VPORTE.
 */
using VPORTE = VPORT_Instance<0x0010>;

/**
 * \brief VPORTF.
 *
 * \attention This type should never be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega4809` and use
 *            picolibrary::Microchip::megaAVR0::Peripheral::VPORTF.
 */
using VPORTF = VPORT_Instance<0x0014>;

/**
 * \brief CLKCTRL0.
 *
 * \attention This type should never be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega4809` and use
 *            picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL0.
 */
using CLKCTRL0 = CLKCTRL_Instance<0x0060>;

/**
 * \brief PORTA.
 *
 * \attention This type should never be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega4809` and use
 *            picolibrary::Microchip::megaAVR0::Peripheral::PORTA.
 */
using PORTA = PORT_Instance<0x0400>;

/**
 * \brief PORTB.
 *
 * \attention This type should never be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega4809` and use
 *            picolibrary::Microchip::megaAVR0::Peripheral::PORTB.
 */
using PORTB = PORT_Instance<0x0420>;

/**
 * \brief PORTC.
 *
 * \attention This type should never be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega4809` and use
 *            picolibrary::Microchip::megaAVR0::Peripheral::PORTC.
 */
using PORTC = PORT_Instance<0x0440>;

/**
 * \brief PORTD.
 *
 * \attention This type should never be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega4809` and use
 *            picolibrary::Microchip::megaAVR0::Peripheral::PORTD.
 */
using PORTD = PORT_Instance<0x0460>;

/**
 * \brief PORTE.
 *
 * \attention This type should never be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega4809` and use
 *            picolibrary::Microchip::megaAVR0::Peripheral::PORTE.
 */
using PORTE = PORT_Instance<0x0480>;

/**
 * \brief PORTF.
 *
 * \attention This type should never be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega4809` and use
 *            picolibrary::Microchip::megaAVR0::Peripheral::PORTF.
 */
using PORTF = PORT_Instance<0x04A0>;

/**
 * \brief PORTMUX0.
 *
 * \attention This type should never be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega4809` and use
 *            picolibrary::Microchip::megaAVR0::Peripheral::PORTMUX0.
 */
using PORTMUX0 = PORTMUX_Instance<0x05E0>;

/**
 * \brief USART0.
 *
 * \attention This type should never be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega4809` and use
 *            picolibrary::Microchip::megaAVR0::Peripheral::USART0.
 */
using USART0 = USART_Instance<0x0800>;

/**
 * \brief USART1.
 *
 * \attention This type should never be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega4809` and use
 *            picolibrary::Microchip::megaAVR0::Peripheral::USART1.
 */
using USART1 = USART_Instance<0x0820>;

/**
 * \brief USART2.
 *
 * \attention This type should never be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega4809` and use
 *            picolibrary::Microchip::megaAVR0::Peripheral::USART2.
 */
using USART2 = USART_Instance<0x0840>;

/**
 * \brief USART3.
 *
 * \attention This type should never be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega4809` and use
 *            picolibrary::Microchip::megaAVR0::Peripheral::USART3.
 */
using USART3 = USART_Instance<0x0860>;

/**
 * \brief SPI0.
 *
 * \attention This type should never be used directly. Instead, set the `-mmcu` compiler
 *            flag to `atmega4809` and use
 *            picolibrary::Microchip::megaAVR0::Peripheral::SPI0.
 */
using SPI0 = SPI_Instance<0x08C0>;

} // namespace picolibrary::Microchip::megaAVR0::Peripheral::ATmega4809

namespace picolibrary::Microchip::megaAVR0::Peripheral {

#ifdef __AVR_ATmega4809__
using namespace ATmega4809;
#endif // __AVR_ATmega4809__

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_ATMEGA4809_H
