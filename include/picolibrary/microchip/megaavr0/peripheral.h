/**
 * picolibrary-microchip-megaavr0
 *
 * Copyright 2021-2023, Andrew Countryman <apcountryman@gmail.com> and the
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

#include "picolibrary/microchip/megaavr0/peripheral/ac.h"
#include "picolibrary/microchip/megaavr0/peripheral/adc.h"
#include "picolibrary/microchip/megaavr0/peripheral/bod.h"
#include "picolibrary/microchip/megaavr0/peripheral/ccl.h"
#include "picolibrary/microchip/megaavr0/peripheral/clkctrl.h"
#include "picolibrary/microchip/megaavr0/peripheral/cpuint.h"
#include "picolibrary/microchip/megaavr0/peripheral/crcscan.h"
#include "picolibrary/microchip/megaavr0/peripheral/evsys.h"
#include "picolibrary/microchip/megaavr0/peripheral/fuse.h"
#include "picolibrary/microchip/megaavr0/peripheral/nvmctrl.h"
#include "picolibrary/microchip/megaavr0/peripheral/port.h"
#include "picolibrary/microchip/megaavr0/peripheral/portmux.h"
#include "picolibrary/microchip/megaavr0/peripheral/rstctrl.h"
#include "picolibrary/microchip/megaavr0/peripheral/rtc.h"
#include "picolibrary/microchip/megaavr0/peripheral/sigrow.h"
#include "picolibrary/microchip/megaavr0/peripheral/slpctrl.h"
#include "picolibrary/microchip/megaavr0/peripheral/spi.h"
#include "picolibrary/microchip/megaavr0/peripheral/syscfg.h"
#include "picolibrary/microchip/megaavr0/peripheral/tca.h"
#include "picolibrary/microchip/megaavr0/peripheral/tcb.h"
#include "picolibrary/microchip/megaavr0/peripheral/twi.h"
#include "picolibrary/microchip/megaavr0/peripheral/usart.h"
#include "picolibrary/microchip/megaavr0/peripheral/userrow.h"
#include "picolibrary/microchip/megaavr0/peripheral/vport.h"
#include "picolibrary/microchip/megaavr0/peripheral/vref.h"
#include "picolibrary/microchip/megaavr0/peripheral/wdt.h"
#include "picolibrary/peripheral.h"

/**
 * \brief Microchip megaAVR 0-series peripheral facilities.
 */
namespace picolibrary::Microchip::megaAVR0::Peripheral {

/**
 * \brief VPORTA.
 */
using VPORTA = ::picolibrary::Peripheral::Instance<VPORT, 0x0000>;

#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
/**
 * \brief VPORTB.
 */
using VPORTB = ::picolibrary::Peripheral::Instance<VPORT, 0x0004>;
#endif // defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )

/**
 * \brief VPORTC.
 */
using VPORTC = ::picolibrary::Peripheral::Instance<VPORT, 0x0008>;

/**
 * \brief VPORTD.
 */
using VPORTD = ::picolibrary::Peripheral::Instance<VPORT, 0x000C>;

#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
/**
 * \brief VPORTE.
 */
using VPORTE = ::picolibrary::Peripheral::Instance<VPORT, 0x0010>;
#endif // defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )

/**
 * \brief VPORTF.
 */
using VPORTF = ::picolibrary::Peripheral::Instance<VPORT, 0x0014>;

/**
 * \brief RSTCTRL0.
 */
using RSTCTRL0 = ::picolibrary::Peripheral::Instance<RSTCTRL, 0x0040>;

/**
 * \brief SLPCTRL0.
 */
using SLPCTRL0 = ::picolibrary::Peripheral::Instance<SLPCTRL, 0x0050>;

/**
 * \brief CLKCTRL0.
 */
using CLKCTRL0 = ::picolibrary::Peripheral::Instance<CLKCTRL, 0x0060>;

/**
 * \brief BOD0.
 */
using BOD0 = ::picolibrary::Peripheral::Instance<BOD, 0x0080>;

/**
 * \brief VREF0.
 */
using VREF0 = ::picolibrary::Peripheral::Instance<VREF, 0x00A0>;

/**
 * \brief WDT0.
 */
using WDT0 = ::picolibrary::Peripheral::Instance<WDT, 0x0100>;

/**
 * \brief CPUINT0.
 */
using CPUINT0 = ::picolibrary::Peripheral::Instance<CPUINT, 0x0110>;

/**
 * \brief CRCSCAN0.
 */
using CRCSCAN0 = ::picolibrary::Peripheral::Instance<CRCSCAN, 0x0120>;

/**
 * \brief RTC0.
 */
using RTC0 = ::picolibrary::Peripheral::Instance<RTC, 0x0140>;

/**
 * \brief EVSYS0.
 */
using EVSYS0 = ::picolibrary::Peripheral::Instance<EVSYS, 0x0180>;

/**
 * \brief CCL0.
 */
using CCL0 = ::picolibrary::Peripheral::Instance<CCL, 0x01C0>;

/**
 * \brief PORTA.
 */
using PORTA = ::picolibrary::Peripheral::Instance<PORT, 0x0400>;

#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
/**
 * \brief PORTB.
 */
using PORTB = ::picolibrary::Peripheral::Instance<PORT, 0x0420>;
#endif // defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )

/**
 * \brief PORTC.
 */
using PORTC = ::picolibrary::Peripheral::Instance<PORT, 0x0440>;

/**
 * \brief PORTD.
 */
using PORTD = ::picolibrary::Peripheral::Instance<PORT, 0x0460>;

#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
/**
 * \brief PORTE.
 */
using PORTE = ::picolibrary::Peripheral::Instance<PORT, 0x0480>;
#endif // defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )

/**
 * \brief PORTF.
 */
using PORTF = ::picolibrary::Peripheral::Instance<PORT, 0x04A0>;

/**
 * \brief PORTMUX0.
 */
using PORTMUX0 = ::picolibrary::Peripheral::Instance<PORTMUX, 0x05E0>;

/**
 * \brief ADC0.
 */
using ADC0 = ::picolibrary::Peripheral::Instance<ADC, 0x0600>;

/**
 * \brief AC0.
 */
using AC0 = ::picolibrary::Peripheral::Instance<AC, 0x0680>;

/**
 * \brief USART0.
 */
using USART0 = ::picolibrary::Peripheral::Instance<USART, 0x800>;

/**
 * \brief USART1.
 */
using USART1 = ::picolibrary::Peripheral::Instance<USART, 0x820>;

/**
 * \brief USART2.
 */
using USART2 = ::picolibrary::Peripheral::Instance<USART, 0x840>;

#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
/**
 * \brief USART3.
 */
using USART3 = ::picolibrary::Peripheral::Instance<USART, 0x860>;
#endif // defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )

/**
 * \brief TWI0.
 */
using TWI0 = ::picolibrary::Peripheral::Instance<TWI, 0x08A0>;

/**
 * \brief SPI0.
 */
using SPI0 = ::picolibrary::Peripheral::Instance<SPI, 0x08C0>;

/**
 * \brief TCA0.
 */
using TCA0 = ::picolibrary::Peripheral::Instance<TCA, 0x0A00>;

/**
 * \brief TCB0.
 */
using TCB0 = ::picolibrary::Peripheral::Instance<TCB, 0x0A80>;

/**
 * \brief TCB1.
 */
using TCB1 = ::picolibrary::Peripheral::Instance<TCB, 0x0A90>;

/**
 * \brief TCB2.
 */
using TCB2 = ::picolibrary::Peripheral::Instance<TCB, 0x0AA0>;

#if defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) \
    || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )
/**
 * \brief TCB3.
 */
using TCB3 = ::picolibrary::Peripheral::Instance<TCB, 0x0AB0>;
#endif // defined( __AVR_ATmega809__ ) || defined( __AVR_ATmega1609__ ) || defined( __AVR_ATmega3209__ ) || defined( __AVR_ATmega4809__ )

/**
 * \brief SYSCFG0.
 */
using SYSCFG0 = ::picolibrary::Peripheral::Instance<SYSCFG, 0x0F00>;

/**
 * \brief NVMCTRL0.
 */
using NVMCTRL0 = ::picolibrary::Peripheral::Instance<NVMCTRL, 0x1000>;

/**
 * \brief SIGROW0.
 */
using SIGROW0 = ::picolibrary::Peripheral::Instance<SIGROW, 0x1100>;

/**
 * \brief FUSE0.
 */
using FUSE0 = ::picolibrary::Peripheral::Instance<FUSE, 0x1280>;

/**
 * \brief USERROW0.
 */
using USERROW0 = ::picolibrary::Peripheral::Instance<USERROW, 0x1300>;

} // namespace picolibrary::Microchip::megaAVR0::Peripheral

#endif // PICOLIBRARY_MICROCHIP_MEGAAVR0_PERIPHERAL_H
