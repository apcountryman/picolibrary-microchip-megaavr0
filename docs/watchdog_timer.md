# Watchdog Timer Facilities
Microchip megaAVR 0-series watchdog timer facilities are defined in the
[`include/picolibrary/microchip/megaavr0/watchdog_timer.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/watchdog_timer.h)/[`source/picolibrary/microchip/megaavr0/watchdog_timer.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/watchdog_timer.cc)
header/source file pair.

## Table of Contents
1. [Configuration](#configuration)
1. [Reset](#reset)

## Configuration
The following Microchip megaAVR 0-series watchdog timer configuration operations are
supported:
- To enable the watchdog timer, use the
  `::picolibrary::Microchip::megaAVR0::Watchdog_Timer::enable()` functions.
- To get the watchdog timer time-out period, use the
  `::picolibrary::Microchip::megaAVR0::Watchdog_Timer::period()` function.
- To get the watchdog timer window closed period, use the
  `::picolibrary::Microchip::megaAVR0::Watchdog_Timer::closed_period()` function.
- To get the watchdog timer window open period, use the
  `::picolibrary::Microchip::megaAVR0::Watchdog_Timer::open_period()` function.
- To check if a watchdog timer configuration change is in progress, use the
  `::picolibrary::Microchip::megaAVR0::Watchdog_Timer::configuration_change_in_progress()`
  function.
- To check if the watchdog timer configuration is locked, use the
  `::picolibrary::Microchip::megaAVR0::Watchdog_Timer::configuration_locked()` function.
- To lock the watchdog timer configuration, use the
  `::picolibrary::Microchip::megaAVR0::Watchdog_Timer::lock_configuration()` function.

## Reset
The following Microchip megaAVR 0-series watchdog timer reset operations are supported:
- To reset the watchdog timer, use the
  `::picolibrary::Microchip::megaAVR0::Watchdog_Timer::reset()` function.
