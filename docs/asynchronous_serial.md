# Asynchronous Serial Facilities
Microchip megaAVR 0-series asynchronous serial facilities are defined in the
[`include/picolibrary/microchip/megaavr0/asynchronous_serial.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/asynchronous_serial.h)/[`source/picolibrary/microchip/megaavr0/asynchronous_serial.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/asynchronous_serial.cc)
header/source file pair.

## Table of Contents
1. [Transmitter](#transmitter)

## Transmitter
The `::picolibrary::Microchip::megaAVR0::Asynchronous_Serial::Basic_Transmitter` template
class implements an asynchronous serial basic transmitter interface for interacting with a
Microchip megaAVR 0-series USART peripheral.
See the [`::picolibrary::Asynchronous_Serial::Basic_Transmitter_Concept`
documentation](https://apcountryman.github.io/picolibrary/asynchronous_serial.html#transmitter)
for more information.

The `::picolibrary::Microchip::megaAVR0::Asynchronous_Serial::Transmitter` alias template
adds asynchronous serial transmitter functionality to
`::picolibrary::Microchip::megaAVR0::Asynchronous_Serial::Basic_Transmitter`.
See the [`::picolibrary::Asynchronous_Serial::Transmitter_Concept`
documentation](https://apcountryman.github.io/picolibrary/asynchronous_serial.html#transmitter)
for more information.
The `::picolibrary::Microchip::megaAVR0::Asynchronous_Serial::Transmitter` hello world
interactive test is defined in the
[`test/interactive/picolibrary/microchip/megaavr0/asynchronous_serial/transmitter/hello_world/main.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/test/interactive/picolibrary/microchip/megaavr0/asynchronous_serial/transmitter/hello_world/main.cc)
source file.
