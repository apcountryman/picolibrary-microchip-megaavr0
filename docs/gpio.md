# GPIO Facilities
Microchip megaAVR 0-series GPIO facilities are defined in the
[`include/picolibrary/microchip/megaavr0/gpio.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/gpio.h)/[`source/picolibrary/microchip/megaavr0/gpio.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/gpio.cc)
header/source file pair.

## Table of Contents
1. [Pin](#pin)
1. [Input Pin](#input-pin)
1. [Internally Pulled-Up Input Pin](#internally-pulled-up-input-pin)
1. [Open-Drain I/O Pin](#open-drain-io-pin)
1. [Push-Pull I/O Pin](#push-pull-io-pin)

## Pin
`::picolibrary::Microchip::megaAVR0::GPIO::Pin` template class specializations provide a
mostly common interface for interacting with a Microchip megaAVR 0-series microcontroller
pin using either a PORT peripheral or a VPORT peripheral.
The
`::picolibrary::Microchip::megaAVR0::GPIO::Pin<::picolibrary::Microchip::megaAVR0::Peripheral::PORT>`
specialization implements this interface using a PORT peripheral.
The
`::picolibrary::Microchip::megaAVR0::GPIO::Pin<::picolibrary::Microchip::megaAVR0::Peripheral::VPORT>`
specialization implements this interface using a VPORT peripheral.
- To check if a pin is associated with a GPIO port or virtual port, use the `bool`
  conversion operator.
- To configure a pin to act as an input, use the
  `::picolibrary::Microchip::megaAVR0::GPIO::Pin::configure_pin_as_input()` member
  function.
- To configure a pin to act as an internally pulled-up input, use the
  `::picolibrary::Microchip::megaAVR0::GPIO::Pin<::picolibrary::Microchip::megaAVR0::Peripheral::PORT>::configure_pin_as_internally_pulled_up_input()`
  member function.
- To configure a pin to act as an open-drain I/O pin, use the
  `::picolibrary::Microchip::megaAVR0::GPIO::Pin::configure_pin_as_open_drain_io()` member
  function.
- To configure a pin to act as a push-pull I/O pin, use the
  `::picolibrary::Microchip::megaAVR0::GPIO::Pin::configure_pin_as_push_pull_io()` member
  function.
- To check if an internally pulled-up input pin's internal pull-up resistor is disabled,
  use the
  `::picolibrary::Microchip::megaAVR0::GPIO::Pin<::picolibrary::Microchip::megaAVR0::Peripheral::PORT>::pull_up_is_disabled()`
  member function.
- To check if an internally pulled-up input pin's internal pull-up resistor is enabled,
  use the
  `::picolibrary::Microchip::megaAVR0::GPIO::Pin<::picolibrary::Microchip::megaAVR0::Peripheral::PORT>::pull_up_is_enabled()`
  member function.
- To disable an internally pulled-up input pin's internal pull-up resistor, use the
  `::picolibrary::Microchip::megaAVR0::GPIO::Pin<::picolibrary::Microchip::megaAVR0::Peripheral::PORT>::disable_pull_up()`
  member function.
- To enable an internally pulled-up input pin's internal pull-up resistor, use the
  `::picolibrary::Microchip::megaAVR0::GPIO::Pin<::picolibrary::Microchip::megaAVR0::Peripheral::PORT>::enable_pull_up()`
  member function.
- To check if a pin is in the low state, use the
  `::picolibrary::Microchip::megaAVR0::GPIO::Pin::is_low()` member function.
- To check if a pin is in the high state, use the
  `::picolibrary::Microchip::megaAVR0::GPIO::Pin::is_high()` member function.
- To transition an open-drain I/O pin to the low state, use the
  `::picolibrary::Microchip::megaAVR0::GPIO::Pin::transition_open_drain_io_to_low()`
  member function.
- To transition a push-pull I/O pin to the low state, use the
  `::picolibrary::Microchip::megaAVR0::GPIO::Pin::transition_push_pull_io_to_low()` member
  function.
- To transition an open-drain I/O pin to the high state, use the
  `::picolibrary::Microchip::megaAVR0::GPIO::Pin::transition_open_drain_io_to_high()`
  member function.
- To transition a push-pull I/O pin to the high state, use the
  `::picolibrary::Microchip::megaAVR0::GPIO::Pin::transition_push_pull_io_to_high()`
  member function.
- To toggle the state of an open-drain I/O pin, use the
  `::picolibrary::Microchip::megaAVR0::GPIO::Pin::toggle_open_drain_io()` member function.
- To toggle the state of a push-pull I/O pin, use the
  `::picolibrary::Microchip::megaAVR0::GPIO::Pin::toggle_push_pull_io()` member function.

## Input Pin
The `::picolibrary::Microchip::megaAVR0::GPIO::Input_Pin` template class implements a GPIO
input pin interface for interacting with a Microchip megaAVR 0-series microcontroller pin.
See the [`::picolibrary::GPIO::Input_Pin_Concept`
documentation](https://apcountryman.github.io/picolibrary/gpio.html#input-pin) for more
information.
The `::picolibrary::Microchip::megaAVR0::GPIO::Input_Pin` state interactive test is
defined in the
[`test/interactive/picolibrary/microchip/megaavr0/gpio/input_pin/state/main.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/test/interactive/picolibrary/microchip/megaavr0/gpio/input_pin/state/main.cc)
source file.

## Internally Pulled-Up Input Pin
The `::picolibrary::Microchip::megaAVR0::GPIO::Internally_Pulled_Up_Input_Pin` template
class implements a GPIO internally pulled-up input pin interface for interacting with a
Microchip megaAVR 0-series microcontroller pin.
See the [`::picolibrary::GPIO::Internally_Pulled_Up_Input_Pin_Concept`
documentation](https://apcountryman.github.io/picolibrary/gpio.html#internally-pulled-up-input-pin)
for more information.
The `::picolibrary::Microchip::megaAVR0::GPIO::Internally_Pulled_Up_Input_Pin` state
interactive test is defined in the
[`test/interactive/picolibrary/microchip/megaavr0/gpio/internally_pulled_up_input_pin/state/main.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/test/interactive/picolibrary/microchip/megaavr0/gpio/internally_pulled_up_input_pin/state/main.cc)
source file.

## Open-Drain I/O Pin
The `::picolibrary::Microchip::megaAVR0::GPIO::Open_Drain_IO_Pin` template class
implements a GPIO open-drain I/O pin interface for interacting with a Microchip megaAVR
0-series microcontroller pin.
See the [`::picolibrary::GPIO::IO_Pin_Concept`
documentation](https://apcountryman.github.io/picolibrary/gpio.html#io-pin) for more
information.
The `::picolibrary::Microchip::megaAVR0::GPIO::Open_Drain_IO_Pin` toggle interactive test
is defined in the
[`test/interactive/picolibrary/microchip/megaavr0/gpio/open_drain_io_pin/toggle/main.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/test/interactive/picolibrary/microchip/megaavr0/gpio/open_drain_io_pin/toggle/main.cc)
source file.

## Push-Pull I/O Pin
The `::picolibrary::Microchip::megaAVR0::GPIO::Push_Pull_IO_Pin` template class implements
a GPIO push-pull I/O pin interface for interacting with a Microchip megaAVR 0-series
microcontroller pin.
See the [`::picolibrary::GPIO::IO_Pin_Concept`
documentation](https://apcountryman.github.io/picolibrary/gpio.html#io-pin) for more
information.
The `::picolibrary::Microchip::megaAVR0::GPIO::Push_Pull_IO_Pin` toggle interactive test
is defined in the
[`test/interactive/picolibrary/microchip/megaavr0/gpio/push_pull_io_pin/toggle/main.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/test/interactive/picolibrary/microchip/megaavr0/gpio/push_pull_io_pin/toggle/main.cc)
source file.
