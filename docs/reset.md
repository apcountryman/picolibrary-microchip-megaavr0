# Reset Facilities
Microchip megaAVR 0-series reset facilities are defined in the
[`include/picolibrary/microchip/megaavr0/reset.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/reset.h)/[`source/picolibrary/microchip/megaavr0/reset.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/reset.cc)
header/source file pair.

## Table of Contents
1. [Reset Source](#reset-source)
1. [Software Reset](#software-reset)

## Reset Source
The `::picolibrary::Microchip::megaAVR0::Reset::Source` class is used to store reset
sources.
- To check if a power-on reset occurred, use the
  `::picolibrary::Microchip::megaAVR0::Reset::Source::is_power_on_reset()` member
  function.
- To check if a brown-out reset occurred, use the
  `::picolibrary::Microchip::megaAVR0::Reset::Source::is_brown_out_reset()` member
  function.
- To check if an external reset occurred, use the
  `::picolibrary::Microchip::megaAVR0::Reset::Source::is_external_reset()` member
  function.
- To check if a watchdog reset occurred, use the
  `::picolibrary::Microchip::megaAVR0::Reset::Source::is_watchdog_reset()` member
  function.
- To check if a software reset occurred, use the
  `::picolibrary::Microchip::megaAVR0::Reset::Source::is_software_reset()` member
  function.
- To check if a UPDI reset occurred, use the
  `::picolibrary::Microchip::megaAVR0::Reset::Source::is_updi_reset()` member function.
- To get the reset source(s), use the
  `::picolibrary::Microchip::megaAVR0::Reset::source()` function.
- To clear the reset source(s), use the
  `::picolibrary::Microchip::megaAVR0::Reset::clear_reset_source()` function.

## Software Reset
The following Microchip megaAVR 0-series software reset operations are supported:
- To initiate a software reset, use the
  `::picolibrary::Microchip::megaAVR0::Reset::initiate_software_reset()` function.
