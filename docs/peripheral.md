# Peripheral Facilities

## Table of Contents
1. [Peripherals](#peripherals)
    1. [BOD](#bod)
    1. [CLKCTRL](#clkctrl)
    1. [CPUINT](#cpuint)
    1. [CRCSCAN](#crcscan)
    1. [PORT](#port)
    1. [PORTMUX](#portmux)
    1. [RSTCTRL](#rstctrl)
    1. [SIGROW](#sigrow)
    1. [SLPCTRL](#slpctrl)
    1. [SPI](#spi)
    1. [SYSCFG](#syscfg)
    1. [TWI](#twi)
    1. [USART](#usart)
    1. [VPORT](#vport)
    1. [VREF](#vref)
    1. [WDT](#wdt)
1. [Peripheral Instances](#peripheral-instances)

## Peripherals
The layout of each Microchip megaAVR 0-series peripheral's registers is defined by the
class named after the peripheral (e.g. the layout of the SPI peripheral's registers is
defined by the `::picolibrary::Microchip::megaAVR0::Peripheral::SPI` class).
Peripheral registers are accessed via the member variables named after the registers (e.g.
the SPI peripheral's CTRLA register is accessed via the
`::picolibrary::Microchip::megaAVR0::Peripheral::SPI::ctrla` member variable).
Peripheral register information is defined in member classes named after the registers
(e.g. SPI peripheral CTRLA register information is defined in the
`::picolibrary::Microchip::megaAVR0::Peripheral::SPI::CTRLA` member class).
Peripheral register field constants are defined in the following member structures:
- `Size`: field sizes (e.g. the size of the ENABLE field of the SPI peripheral's CTRLA
  register is defined by the
  `::picolibrary::Microchip::megaAVR0::Peripheral::SPI::CTRLA::Size::ENABLE` constant)
- `Bit`: field bit positions (e.g. the position of the ENABLE field of the SPI
  peripheral's CTRLA register is defined by the
  `::picolibrary::Microchip::megaAVR0::Peripheral::SPI::CTRLA::Bit::ENABLE` constant)
- `Mask`: field bit masks (e.g. the mask for the ENABLE field of the SPI peripheral's
  CTRLA register is defined by the
  `::picolibrary::Microchip::megaAVR0::Peripheral::SPI::CTRLA::Mask::ENABLE` constant)

### BOD
The `::picolibrary::Microchip::megaAVR0::Peripheral::BOD` class defines the layout of the
Microchip megaAVR 0-series BOD peripheral and information about its registers.
The `::picolibrary::Microchip::megaAVR0::Peripheral::BOD` class is defined in the
[`include/picolibrary/microchip/megaavr0/peripheral/bod.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/peripheral/bod.h)/[`source/picolibrary/microchip/megaavr0/peripheral/bod.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/peripheral/bod.cc)
header/source file pair.

### CLKCTRL
The `::picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL` class defines the layout of
the Microchip megaAVR 0-series CLKCTRL peripheral and information about its registers.
The `::picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL` class is defined in the
[`include/picolibrary/microchip/megaavr0/peripheral/clkctrl.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/peripheral/clkctrl.h)/[`source/picolibrary/microchip/megaavr0/peripheral/clkctrl.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/peripheral/clkctrl.cc)
header/source file pair.

### CPUINT
The `::picolibrary::Microchip::megaAVR0::Peripheral::CPUINT` class defines the layout of
the Microchip megaAVR 0-series CPUINT peripheral and information about its registers.
The `::picolibrary::Microchip::megaAVR0::Peripheral::CPUINT` class is defined in the
[`include/picolibrary/microchip/megaavr0/peripheral/cpuint.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/peripheral/cpuint.h)/[`source/picolibrary/microchip/megaavr0/peripheral/cpuint.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/peripheral/cpuint.cc)
header/source file pair.

### CRCSCAN
The `::picolibrary::Microchip::megaAVR0::Peripheral::CRCSCAN` class defines the layout of
the Microchip megaAVR 0-series CRCSCAN peripheral and information about its registers.
The `::picolibrary::Microchip::megaAVR0::Peripheral::CRCSCAN` class is defined in the
[`include/picolibrary/microchip/megaavr0/peripheral/crcscan.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/peripheral/crcscan.h)/[`source/picolibrary/microchip/megaavr0/peripheral/crcscan.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/peripheral/crcscan.cc)
header/source file pair.

### PORT
The `::picolibrary::Microchip::megaAVR0::Peripheral::PORT` class defines the layout of the
Microchip megaAVR 0-series PORT peripheral and information about its registers.
The `::picolibrary::Microchip::megaAVR0::Peripheral::PORT` class is defined in the
[`include/picolibrary/microchip/megaavr0/peripheral/port.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/peripheral/port.h)/[`source/picolibrary/microchip/megaavr0/peripheral/port.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/peripheral/port.cc)
header/source file pair.

### PORTMUX
The `::picolibrary::Microchip::megaAVR0::Peripheral::PORTMUX` class defines the layout of
the Microchip megaAVR 0-series PORTMUX peripheral and information about its registers.
The `::picolibrary::Microchip::megaAVR0::Peripheral::PORTMUX` class is defined in the
[`include/picolibrary/microchip/megaavr0/peripheral/portmux.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/peripheral/portmux.h)/[`source/picolibrary/microchip/megaavr0/peripheral/portmux.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/peripheral/portmux.cc)
header/source file pair.

### RSTCTRL
The `::picolibrary::Microchip::megaAVR0::Peripheral::RSTCTRL` class defines the layout of
the Microchip megaAVR 0-series RSTCTRL peripheral and information about its registers.
The `::picolibrary::Microchip::megaAVR0::Peripheral::RSTCTRL` class is defined in the
[`include/picolibrary/microchip/megaavr0/peripheral/rstctrl.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/peripheral/rstctrl.h)/[`source/picolibrary/microchip/megaavr0/peripheral/rstctrl.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/peripheral/rstctrl.cc)
header/source file pair.

### SIGROW
The `::picolibrary::Microchip::megaAVR0::Peripheral::SIGROW` class defines the layout of
the Microchip megaAVR 0-series SIGROW peripheral and information about its registers.
The `::picolibrary::Microchip::megaAVR0::Peripheral::SIGROW` class is defined in the
[`include/picolibrary/microchip/megaavr0/peripheral/sigrow.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/peripheral/sigrow.h)/[`source/picolibrary/microchip/megaavr0/peripheral/sigrow.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/peripheral/sigrow.cc)
header/source file pair.

### SLPCTRL
The `::picolibrary::Microchip::megaAVR0::Peripheral::SLPCTRL` class defines the layout of
the Microchip megaAVR 0-series SLPCTRL peripheral and information about its registers.
The `::picolibrary::Microchip::megaAVR0::Peripheral::SLPCTRL` class is defined in the
[`include/picolibrary/microchip/megaavr0/peripheral/slpctrl.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/peripheral/slpctrl.h)/[`source/picolibrary/microchip/megaavr0/peripheral/slpctrl.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/peripheral/slpctrl.cc)
header/source file pair.

### SPI
The `::picolibrary::Microchip::megaAVR0::Peripheral::SPI` class defines the layout of the
Microchip megaAVR 0-series SPI peripheral and information about its registers.
The `::picolibrary::Microchip::megaAVR0::Peripheral::SPI` class is defined in the
[`include/picolibrary/microchip/megaavr0/peripheral/spi.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/peripheral/spi.h)/[`source/picolibrary/microchip/megaavr0/peripheral/spi.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/peripheral/spi.cc)
header/source file pair.

### SYSCFG
The `::picolibrary::Microchip::megaAVR0::Peripheral::SYSCFG` class defines the layout of
the Microchip megaAVR 0-series SYSCFG peripheral and information about its registers.
The `::picolibrary::Microchip::megaAVR0::Peripheral::SYSCFG` class is defined in the
[`include/picolibrary/microchip/megaavr0/peripheral/syscfg.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/peripheral/syscfg.h)/[`source/picolibrary/microchip/megaavr0/peripheral/syscfg.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/peripheral/syscfg.cc)
header/source file pair.

### TWI
The `::picolibrary::Microchip::megaAVR0::Peripheral::TWI` class defines the layout of the
Microchip megaAVR 0-series TWI peripheral and information about its registers.
The `::picolibrary::Microchip::megaAVR0::Peripheral::TWI` class is defined in the
[`include/picolibrary/microchip/megaavr0/peripheral/twi.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/peripheral/twi.h)/[`source/picolibrary/microchip/megaavr0/peripheral/twi.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/peripheral/twi.cc)
header/source file pair.

### USART
The `::picolibrary::Microchip::megaAVR0::Peripheral::USART` class defines the layout of
the Microchip megaAVR 0-series USART peripheral and information about its registers.
The `::picolibrary::Microchip::megaAVR0::Peripheral::USART` class is defined in the
[`include/picolibrary/microchip/megaavr0/peripheral/usart.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/peripheral/usart.h)/[`source/picolibrary/microchip/megaavr0/peripheral/usart.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/peripheral/usart.cc)
header/source file pair.

### VPORT
The `::picolibrary::Microchip::megaAVR0::Peripheral::VPORT` class defines the layout of
the Microchip megaAVR 0-series VPORT peripheral.
The `::picolibrary::Microchip::megaAVR0::Peripheral::VPORT` class is defined in the
[`include/picolibrary/microchip/megaavr0/peripheral/vport.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/peripheral/vport.h)/[`source/picolibrary/microchip/megaavr0/peripheral/vport.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/peripheral/vport.cc)
header/source file pair.

### VREF
The `::picolibrary::Microchip::megaAVR0::Peripheral::VREF` class defines the layout of the
Microchip megaAVR 0-series VREF peripheral and information about its registers.
The `::picolibrary::Microchip::megaAVR0::Peripheral::VREF` class is defined in the
[`include/picolibrary/microchip/megaavr0/peripheral/vref.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/peripheral/vref.h)/[`source/picolibrary/microchip/megaavr0/peripheral/vref.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/peripheral/vref.cc)
header/source file pair.

### WDT
The `::picolibrary::Microchip::megaAVR0::Peripheral::WDT` class defines the layout of the
Microchip megaAVR 0-series WDT peripheral and information about its registers.
The `::picolibrary::Microchip::megaAVR0::Peripheral::WDT` class is defined in the
[`include/picolibrary/microchip/megaavr0/peripheral/wdt.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/peripheral/wdt.h)/[`source/picolibrary/microchip/megaavr0/peripheral/wdt.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/peripheral/wdt.cc)
header/source file pair.

## Peripheral Instances
The `::picolibrary::Microchip::megaAVR0::Peripheral::Instance` template class is used to
define Microchip megaAVR 0-series peripheral instances.
The `::picolibrary::Microchip::megaAVR0::Peripheral::Instance` template class is defined
in the
[`include/picolibrary/microchip/megaavr0/peripheral/instance.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/peripheral/instance.h)/[`source/picolibrary/microchip/megaavr0/peripheral/instance.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/peripheral/instance.cc)
header/source file pair.
- To access a peripheral instance, use the
  `::picolibrary::Microchip::megaAVR0::Peripheral::Instance::instance()` static member
  function.

Microchip megaAVR 0-series peripheral instances are defined in the
[`include/picolibrary/microchip/megaavr0/peripheral.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/peripheral.h)/[`source/picolibrary/microchip/megaavr0/peripheral.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/peripheral.cc)
header/source file pair.
Peripheral instance names are based on the names used in the "Peripheral Module Address
Map" table of the datasheets with the following change: a `0` is added to the end of the
name of peripherals that only have a single instance to differentiate the peripheral name
and the instance name.
The following peripheral instances are defined (listed alphabetically):
- `::picolibrary::Microchip::megaAVR0::Peripheral::BOD0`
- `::picolibrary::Microchip::megaAVR0::Peripheral::CLKCTRL0`
- `::picolibrary::Microchip::megaAVR0::Peripheral::CPUINT0`
- `::picolibrary::Microchip::megaAVR0::Peripheral::CRCSCAN0`
- `::picolibrary::Microchip::megaAVR0::Peripheral::PORTA`
- `::picolibrary::Microchip::megaAVR0::Peripheral::PORTB`
- `::picolibrary::Microchip::megaAVR0::Peripheral::PORTC`
- `::picolibrary::Microchip::megaAVR0::Peripheral::PORTD`
- `::picolibrary::Microchip::megaAVR0::Peripheral::PORTE`
- `::picolibrary::Microchip::megaAVR0::Peripheral::PORTF`
- `::picolibrary::Microchip::megaAVR0::Peripheral::PORTMUX0`
- `::picolibrary::Microchip::megaAVR0::Peripheral::RSTCTRL0`
- `::picolibrary::Microchip::megaAVR0::Peripheral::SIGROW0`
- `::picolibrary::Microchip::megaAVR0::Peripheral::SLPCTRL0`
- `::picolibrary::Microchip::megaAVR0::Peripheral::SPI0`
- `::picolibrary::Microchip::megaAVR0::Peripheral::SYSCFG0`
- `::picolibrary::Microchip::megaAVR0::Peripheral::TWI0`
- `::picolibrary::Microchip::megaAVR0::Peripheral::USART0`
- `::picolibrary::Microchip::megaAVR0::Peripheral::USART1`
- `::picolibrary::Microchip::megaAVR0::Peripheral::USART2`
- `::picolibrary::Microchip::megaAVR0::Peripheral::USART3`
- `::picolibrary::Microchip::megaAVR0::Peripheral::VPORTA`
- `::picolibrary::Microchip::megaAVR0::Peripheral::VPORTB`
- `::picolibrary::Microchip::megaAVR0::Peripheral::VPORTC`
- `::picolibrary::Microchip::megaAVR0::Peripheral::VPORTD`
- `::picolibrary::Microchip::megaAVR0::Peripheral::VPORTE`
- `::picolibrary::Microchip::megaAVR0::Peripheral::VPORTF`
- `::picolibrary::Microchip::megaAVR0::Peripheral::VREF0`
- `::picolibrary::Microchip::megaAVR0::Peripheral::WDT0`

The availability of these Microchip megaAVR 0-series peripheral instance definitions
depends on the specific Microchip megaAVR 0-series microcontroller used.
