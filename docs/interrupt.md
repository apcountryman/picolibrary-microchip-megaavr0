# Interrupt Facilities
Microchip megaAVR 0-series interrupt facilities are defined in the
[`include/picolibrary/microchip/megaavr0/interrupt.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/interrupt.h)/[`source/picolibrary/microchip/megaavr0/interrupt.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/interrupt.cc)
header/source file pair.

## Table of Contents
1. [Controller](#controller)

## Controller
The `::picolibrary::Microchip::megaAVR0::Interrupt::Controller` class implements an
interrupt controller interface for interacting with the Microchip megaAVR 0-series global
interrupt enable.
See the [`::picolibrary::Interrupt::Controller_Concept`
documentation](https://apcountryman.github.io/picolibrary/interrupt.html#controller) for
more information.
