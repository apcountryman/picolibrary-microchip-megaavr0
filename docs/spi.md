# Serial Peripheral Interface (SPI) Facilities
Microchip megaAVR 0-series SPI facilities are defined in the
[`include/picolibrary/microchip/megaavr0/spi.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/spi.h)/[`source/picolibrary/microchip/megaavr0/spi.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/spi.cc)
header/source file pair.

## Table of Contents
1. [Controller](#controller)

## Controller
picolibrary-microchip-megaavr0 implements two types of SPI controllers: fixed
configuration and variable configuration.
Fixed configuration controllers should be used when all SPI devices that use a controller
use the same clock (frequency, polarity, and phase) and data exchange bit order
configuration.
Variable configuration controllers should be used when this is not the case.

`::picolibrary::Microchip::megaAVR0::SPI::Fixed_Configuration_Basic_Controller` template
class specializations implement an SPI fixed configuration basic controller interface for
interacting with Microchip megaAVR 0-series SPI and USART peripherals.
The
`::picolibrary::Microchip::megaAVR0::SPI::Fixed_Configuration_Basic_Controller<::picolibrary::Microchip::megaAVR0::Peripheral::SPI>`
specialization implements the interface for interacting with an SPI peripheral.
The
`::picolibrary::Microchip::megaAVR0::SPI::Fixed_Configuration_Basic_Controller<::picolibrary::Microchip::megaAVR0::Peripheral::USART>`
specialization implements the interface for interacting with a USART peripheral.
See the [`::picolibrary::SPI::Basic_Controller_Concept`
documentation](https://apcountryman.github.io/picolibrary/spi.html#controller) for more
information.

`::picolibrary::Microchip::megaAVR0::SPI::Variable_Configuration_Basic_Controller`
template class specializations implement an SPI variable configuration basic controller
interface for interacting with Microchip megaAVR 0-series SPI and USART peripherals.
The
`::picolibrary::Microchip::megaAVR0::SPI::Variable_Configuration_Basic_Controller<::picolibrary::Microchip::megaAVR0::Peripheral::SPI>`
specialization implements the interface for interacting with an SPI peripheral.
The
`::picolibrary::Microchip::megaAVR0::SPI::Variable_Configuration_Basic_Controller<::picolibrary::Microchip::megaAVR0::Peripheral::USART>`
specialization implements the interface for interacting with a USART peripheral.
See the [`::picolibrary::SPI::Basic_Controller_Concept`
documentation](https://apcountryman.github.io/picolibrary/spi.html#controller) for more
information.

The `::picolibrary::Microchip::megaAVR0::SPI::Fixed_Configuration_Controller` alias
template adds controller functionality to
`::picolibrary::Microchip::megaAVR0::SPI::Fixed_Configuration_Basic_Controller`.
See the [`::picolibrary::SPI::Controller_Concept`
documentation](https://apcountryman.github.io/picolibrary/spi.html#controller) for more
information.
The
`::picolibrary::Microchip::megaAVR0::SPI::Fixed_Configuration_Controller<::picolibrary::Microchip::megaAVR0::Peripheral::SPI>`
echo interactive test is defined in the
[`test/interactive/picolibrary/microchip/megaavr0/spi/fixed_configuration_controller-spi/echo/main.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/test/interactive/picolibrary/microchip/megaavr0/spi/fixed_configuration_controller-spi/echo/main.cc)
source file.
The
`::picolibrary::Microchip::megaAVR0::SPI::Fixed_Configuration_Controller<::picolibrary::Microchip::megaAVR0::Peripheral::USART>`
echo interactive test is defined in the
[`test/interactive/picolibrary/microchip/megaavr0/spi/fixed_configuration_controller-usart/echo/main.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/test/interactive/picolibrary/microchip/megaavr0/spi/fixed_configuration_controller-usart/echo/main.cc)
source file.

The `::picolibrary::Microchip::megaAVR0::SPI::Variable_Configuration_Controller` alias
template adds controller functionality to
`::picolibrary::Microchip::megaAVR0::SPI::Variable_Configuration_Basic_Controller`.
See the [`::picolibrary::SPI::Controller_Concept`
documentation](https://apcountryman.github.io/picolibrary/spi.html#controller) for more
information.
The
`::picolibrary::Microchip::megaAVR0::SPI::Variable_Configuration_Controller<::picolibrary::Microchip::megaAVR0::Peripheral::SPI>`
echo interactive test is defined in the
[`test/interactive/picolibrary/microchip/megaavr0/spi/variable_configuration_controller-spi/echo/main.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/test/interactive/picolibrary/microchip/megaavr0/spi/variable_configuration_controller-spi/echo/main.cc)
source file.
The
`::picolibrary::Microchip::megaAVR0::SPI::Variable_Configuration_Controller<::picolibrary::Microchip::megaAVR0::Peripheral::USART>`
echo interactive test is defined in the
[`test/interactive/picolibrary/microchip/megaavr0/spi/variable_configuration_controller-usart/echo/main.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/test/interactive/picolibrary/microchip/megaavr0/spi/variable_configuration_controller-usart/echo/main.cc)
source file.
