# Multiplexed Signals Facilities
Microchip megaAVR 0-series multiplexed signals facilities are defined in the
[`include/picolibrary/microchip/megaavr0/multiplexed_signals.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/multiplexed_signals.h)/[`source/picolibrary/microchip/megaavr0/multiplexed_signals.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/multiplexed_signals.cc)
header/source file pair.

## Table of Contents
1. [SPI Peripheral](#spi-peripheral)
1. [TWI Peripheral](#twi-peripheral)
1. [USART Peripheral](#usart-peripheral)

## SPI Peripheral
Microchip megaAVR 0-series SPI peripheral multiplexed signals facilities are defined in
the
[`include/picolibrary/microchip/megaavr0/multiplexed_signals/spi.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/multiplexed_signals/spi.h)/[`source/picolibrary/microchip/megaavr0/multiplexed_signals/spi.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/multiplexed_signals/spi.cc)
header/source file pair.
These facilities are defined in these files for source code organization reasons.
Users should access these facilities via the
[`include/picolibrary/microchip/megaavr0/multiplexed_signals.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/multiplexed_signals.h)
header file.
- To get an SPI peripheral's routing configuration, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::spi_route()` function.
- To set an SPI peripheral's routing configuration, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::set_spi_route()` function.
- To lookup an SPI peripheral's pins PORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::spi_port_address()` function.
- To lookup an SPI peripheral's pins PORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::spi_port()` functions.
- To lookup an SPI peripheral's pins VPORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::spi_vport_address()` function.
- To lookup an SPI peripheral's pins VPORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::spi_vport()` functions.
- To lookup an SPI peripheral's SS pin PORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::ss_port_address()` function.
- To lookup an SPI peripheral's SS pin PORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::ss_port()` functions.
- To lookup an SPI peripheral's SS pin VPORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::ss_vport_address()` function.
- To lookup an SPI peripheral's SS pin VPORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::ss_vport()` functions.
- To lookup an SPI peripheral's SS pin number, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::ss_number()` functions.
- To lookup an SPI peripheral's SS pin mask, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::ss_mask()` functions.
- To lookup an SPI peripheral's SCK pin PORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::sck_port_address()` function.
- To lookup an SPI peripheral's SCK pin PORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::sck_port()` functions.
- To lookup an SPI peripheral's SCK pin VPORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::sck_vport_address()` function.
- To lookup an SPI peripheral's SCK pin VPORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::sck_vport()` functions.
- To lookup an SPI peripheral's SCK pin number, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::sck_number()` functions.
- To lookup an SPI peripheral's SCK pin mask, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::sck_mask()` functions.
- To lookup an SPI peripheral's MOSI pin PORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::mosi_port_address()` function.
- To lookup an SPI peripheral's MOSI pin PORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::mosi_port()` functions.
- To lookup an SPI peripheral's MOSI pin VPORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::mosi_vport_address()`
  function.
- To lookup an SPI peripheral's MOSI pin VPORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::mosi_vport()` functions.
- To lookup an SPI peripheral's MOSI pin number, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::mosi_number()` functions.
- To lookup an SPI peripheral's MOSI pin mask, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::mosi_mask()` functions.
- To lookup an SPI peripheral's MISO pin PORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::miso_port_address()` function.
- To lookup an SPI peripheral's MISO pin PORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::miso_port()` functions.
- To lookup an SPI peripheral's MISO pin VPORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::miso_vport_address()`
  function.
- To lookup an SPI peripheral's MISO pin VPORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::miso_vport()` functions.
- To lookup an SPI peripheral's MISO pin number, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::miso_number()` functions.
- To lookup an SPI peripheral's MISO pin mask, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::miso_mask()` functions.

## TWI Peripheral
Microchip megaAVR 0-series TWI peripheral multiplexed signals facilities are defined in
the
[`include/picolibrary/microchip/megaavr0/multiplexed_signals/twi.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/multiplexed_signals/twi.h)/[`source/picolibrary/microchip/megaavr0/multiplexed_signals/twi.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/multiplexed_signals/twi.cc)
header/source file pair.
These facilities are defined in these files for source code organization reasons.
Users should access these facilities via the
[`include/picolibrary/microchip/megaavr0/multiplexed_signals.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/multiplexed_signals.h)
header file.
- To get a TWI peripheral's routing configuration, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::twi_route()` function.
- To set a TWI peripheral's routing configuration, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::set_twi_route()` function.
- To lookup a TWI peripheral's SCL pin number, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::scl_number()` functions.
- To lookup a TWI peripheral's SCL pin mask, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::scl_mask()` functions.
- To lookup a TWI peripheral's SDA pin number, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::sda_number()` functions.
- To lookup a TWI peripheral's SDA pin mask, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::sda_mask()` functions.
- To lookup a TWI peripheral's controller pins PORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::twi_controller_port_address()`
  function.
- To lookup a TWI peripheral's controller pins PORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::twi_controller_port()`
  functions.
- To lookup a TWI peripheral's controller pins VPORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::twi_controller_vport_address()`
  function.
- To lookup a TWI peripheral's controller pins VPORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::twi_controller_vport()`
  functions.
- To lookup a TWI peripheral's controller SCL pin PORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::controller_scl_port_address()`
  function.
- To lookup a TWI peripheral's controller SCL pin PORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::controller_scl_port()`
  functions.
- To lookup a TWI peripheral's controller SCL pin VPORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::controller_scl_vport_address()`
  function.
- To lookup a TWI peripheral's controller SCL pin VPORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::controller_scl_vport()`
  functions.
- To lookup a TWI peripheral's controller SCL pin number, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::controller_scl_number()`
  functions.
- To lookup a TWI peripheral's controller SCL pin mask, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::controller_scl_mask()`
  functions.
- To lookup a TWI peripheral's controller SDA pin PORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::controller_sda_port_address()`
  function.
- To lookup a TWI peripheral's controller SDA pin PORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::controller_sda_port()`
  functions.
- To lookup a TWI peripheral's controller SDA pin VPORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::controller_sda_vport_address()`
  function.
- To lookup a TWI peripheral's controller SDA pin VPORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::controller_sda_vport()`
  functions.
- To lookup a TWI peripheral's controller SDA pin number, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::controller_sda_number()`
  functions.
- To lookup a TWI peripheral's controller SDA pin mask, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::controller_sda_mask()`
  functions.
- To lookup a TWI peripheral's device pins PORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::twi_device_port_address()`
  function.
- To lookup a TWI peripheral's device pins PORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::twi_device_port()` functions.
- To lookup a TWI peripheral's device pins VPORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::twi_device_vport_address()`
  function.
- To lookup a TWI peripheral's device pins VPORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::twi_device_vport()` functions.
- To lookup a TWI peripheral's device SCL pin PORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::device_scl_port_address()`
  function.
- To lookup a TWI peripheral's device SCL pin PORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::device_scl_port()` functions.
- To lookup a TWI peripheral's device SCL pin VPORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::device_scl_vport_address()`
  function.
- To lookup a TWI peripheral's device SCL pin VPORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::device_scl_vport()` functions.
- To lookup a TWI peripheral's device SCL pin number, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::device_scl_number()`
  functions.
- To lookup a TWI peripheral's device SCL pin mask, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::device_scl_mask()` functions.
- To lookup a TWI peripheral's device SDA pin PORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::device_sda_port_address()`
  function.
- To lookup a TWI peripheral's device SDA pin PORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::device_sda_port()` functions.
- To lookup a TWI peripheral's device SDA pin VPORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::device_sda_vport_address()`
  function.
- To lookup a TWI peripheral's device SDA pin VPORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::device_sda_vport()` functions.
- To lookup a TWI peripheral's device SDA pin number, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::device_sda_number()`
  functions.
- To lookup a TWI peripheral's device SDA pin mask, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::device_sda_mask()` functions.

## USART Peripheral
Microchip megaAVR 0-series USART peripheral multiplexed signals facilities are defined in
the
[`include/picolibrary/microchip/megaavr0/multiplexed_signals/usart.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/multiplexed_signals/usart.h)/[`source/picolibrary/microchip/megaavr0/multiplexed_signals/usart.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/multiplexed_signals/usart.cc)
header/source file pair.
These facilities are defined in these files for source code organization reasons.
Users should access these facilities via the
[`include/picolibrary/microchip/megaavr0/multiplexed_signals.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/multiplexed_signals.h)
header file.
- To get a USART peripheral's routing configuration, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::usart_route()` function.
- To set a USART peripheral's routing configuration, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::set_usart_route()` function.
- To lookup a USART peripheral's pins PORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::usart_port_address()`
  function.
- To lookup a USART peripheral's pins PORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::usart_port()` functions.
- To lookup a USART peripheral's pins VPORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::usart_vport_address()`
  function.
- To lookup a USART peripheral's pins VPORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::usart_vport()` functions.
- To lookup a USART peripheral's XCK pin PORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::xck_port_address()` function.
- To lookup a USART peripheral's XCK pin PORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::xck_port()` functions.
- To lookup a USART peripheral's XCK pin VPORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::xck_vport_address()` function.
- To lookup a USART peripheral's XCK pin VPORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::xck_vport()` functions.
- To lookup a USART peripheral's XCK pin number, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::xck_number()` functions.
- To lookup a USART peripheral's XCK pin mask, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::xck_mask()` functions.
- To lookup a USART peripheral's XDIR pin PORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::xdir_port_address()` function.
- To lookup a USART peripheral's XDIR pin PORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::xdir_port()` functions.
- To lookup a USART peripheral's XDIR pin VPORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::xdir_vport_address()`
  function.
- To lookup a USART peripheral's XDIR pin VPORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::xdir_vport()` functions.
- To lookup a USART peripheral's XDIR pin number, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::xdir_number()` functions.
- To lookup a USART peripheral's XDIR pin mask, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::xdir_mask()` functions.
- To lookup a USART peripheral's TXD pin PORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::txd_port_address()` function.
- To lookup a USART peripheral's TXD pin PORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::txd_port()` functions.
- To lookup a USART peripheral's TXD pin VPORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::txd_vport_address()` function.
- To lookup a USART peripheral's TXD pin VPORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::txd_vport()` functions.
- To lookup a USART peripheral's TXD pin number, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::txd_number()` functions.
- To lookup a USART peripheral's TXD pin mask, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::txd_mask()` functions.
- To lookup a USART peripheral's RXD pin PORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::rxd_port_address()` function.
- To lookup a USART peripheral's RXD pin PORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::rxd_port()` functions.
- To lookup a USART peripheral's RXD pin VPORT peripheral address, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::rxd_vport_address()` function.
- To lookup a USART peripheral's RXD pin VPORT peripheral, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::rxd_vport()` functions.
- To lookup a USART peripheral's RXD pin number, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::rxd_number()` functions.
- To lookup a USART peripheral's RXD pin mask, use the
  `::picolibrary::Microchip::megaAVR0::Multiplexed_Signals::rxd_mask()` functions.
