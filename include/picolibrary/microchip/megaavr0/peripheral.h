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
 * \brief picolibrary::Microchip::megaAVR0::Peripheral interface.
 */

#ifndef PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_H
#define PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_H

#include "picolibrary/microchip/megaavr0/peripheral/clkctrl.h"
#include "picolibrary/microchip/megaavr0/peripheral/instance.h"
#include "picolibrary/microchip/megaavr0/peripheral/port.h"
#include "picolibrary/microchip/megaavr0/peripheral/portmux.h"
#include "picolibrary/microchip/megaavr0/peripheral/rstctrl.h"
#include "picolibrary/microchip/megaavr0/peripheral/sigrow.h"
#include "picolibrary/microchip/megaavr0/peripheral/spi.h"
#include "picolibrary/microchip/megaavr0/peripheral/syscfg.h"
#include "picolibrary/microchip/megaavr0/peripheral/twi.h"
#include "picolibrary/microchip/megaavr0/peripheral/usart.h"
#include "picolibrary/microchip/megaavr0/peripheral/vport.h"
#include "picolibrary/microchip/megaavr0/peripheral/wdt.h"

/**
 * \brief Microchip megaAVR 0-series peripheral facilities.
 */
namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief VPORTA.
 */
using VPORTA = Instance<VPORT, 0x0000>;

#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
/**
 * \brief VPORTB.
 */
using VPORTB = Instance<VPORT, 0x0004>;
#endif // defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )

/**
 * \brief VPORTC.
 */
using VPORTC = Instance<VPORT, 0x0008>;

/**
 * \brief VPORTD.
 */
using VPORTD = Instance<VPORT, 0x000C>;

#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
/**
 * \brief VPORTE.
 */
using VPORTE = Instance<VPORT, 0x0010>;
#endif // defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )

/**
 * \brief VPORTF.
 */
using VPORTF = Instance<VPORT, 0x0014>;

/**
 * \brief RSTCTRL0.
 */
using RSTCTRL0 = Instance<RSTCTRL, 0x0040>;

/**
 * \brief CLKCTRL0.
 */
using CLKCTRL0 = Instance<CLKCTRL, 0x0060>;

/**
 * \brief WDT0.
 */
using WDT0 = Instance<WDT, 0x0100>;

/**
 * \brief PORTA.
 */
using PORTA = Instance<PORT, 0x0400>;

#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
/**
 * \brief PORTB.
 */
using PORTB = Instance<PORT, 0x0420>;
#endif // defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )

/**
 * \brief PORTC.
 */
using PORTC = Instance<PORT, 0x0440>;

/**
 * \brief PORTD.
 */
using PORTD = Instance<PORT, 0x0460>;

#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
/**
 * \brief PORTE.
 */
using PORTE = Instance<PORT, 0x0480>;
#endif // defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )

/**
 * \brief PORTF.
 */
using PORTF = Instance<PORT, 0x04A0>;

/**
 * \brief PORTMUX0.
 */
using PORTMUX0 = Instance<PORTMUX, 0x05E0>;

/**
 * \brief USART0.
 */
using USART0 = Instance<USART, 0x800>;

/**
 * \brief USART1.
 */
using USART1 = Instance<USART, 0x820>;

/**
 * \brief USART2.
 */
using USART2 = Instance<USART, 0x840>;

#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
/**
 * \brief USART3.
 */
using USART3 = Instance<USART, 0x860>;
#endif // defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )

/**
 * \brief TWI0.
 */
using TWI0 = Instance<TWI, 0x08A0>;

/**
 * \brief SPI0.
 */
using SPI0 = Instance<SPI, 0x08C0>;

/**
 * \brief SYSCFG0.
 */
using SYSCFG0 = Instance<SYSCFG, 0x0F00>;

/**
 * \brief SIGROW0.
 */
using SIGROW0 = Instance<SIGROW, 0x1100>;

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_H
