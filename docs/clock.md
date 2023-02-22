# Clock Facilities
Microchip megaAVR 0-series clock facilities are defined in the
[`include/picolibrary/microchip/megaavr0/clock.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/clock.h)/[`source/picolibrary/microchip/megaavr0/clock.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/clock.cc)
header/source file pair.

## Table of Contents
1. [Source](#source)
1. [Output](#output)
1. [Prescaler](#prescaler)
1. [Configuration Lock](#configuration-lock)
1. [Internal 16/20 MHz Oscillator](#internal-1620-mhz-oscillator)
1. [Internal 32.768 kHz Ultra Low-Power Oscillator](#internal-32768-khz-ultra-low-power-oscilaltor)
1. [External 32.768 kHz Crystal Oscillator](#external-32768-khz-crystal-oscillator)
1. [External Clock](#external-clock)
1. [Interactive Testing Clock Configuration](#interactive-testing-clock-configuration)

## Source
The following Microchip megaAVR 0-series clock source operations are supported:
- To check if the clock source is changing, use the
  `::picolibrary::Microchip::megaAVR0::Clock::source_changing()` function.
- To get the clock source, use the `::picolibrary::Microchip::megaAVR0::Clock::source()`
  function.
- To set the clock source, use the
  `::picolibrary::Microchip::megaAVR0::Clock::setsource()` function.

## Output
The following Microchip megaAVR 0-series clock output operations are supported:
- To check if clock output is enabled, use the
  `::picolibrary::Microchip::megaAVR0::Clock::output_enabled()` function.
- To enable clock output, use the
  `::picolibrary::Microchip::megaAVR0::Clock::enable_output()` function.
- To disable clock output, use the
  `::picolibrary::Microchip::megaAVR0::Clock::disable_output()` function.

## Prescaler
The following Microchip megaAVR 0-series clock prescaler operations are supported:
- To check if the clock prescaler is enabled, use the
  `::picolibrary::Microchip::megaAVR0::Clock::prescaler_enabled()` function.
- To get the clock prescaler configuration, use the
  `::picolibrary::Microchip::megaAVR0::Clock::prescaler_configuration()` function.
- To get the clock prescaler value, use the
  `::picolibrary::Microchip::megaAVR0::Clock::prescaler_value()` function.
- To configure the clock prescaler, use the
  `::picolibrary::Microchip::megaAVR0::Clock::configure_prescaler()` function.
- To enable the clock prescaler, use the
  `::picolibrary::Microchip::megaAVR0::Clock::enable_prescaler()` function.
- To disable the clock prescaler, use the
  `::picolibrary::Microchip::megaAVR0::Clock::disable_prescaler()` function.

## Configuration Lock
The following Microchip megaAVR 0-series clock configuration lock operations are
supported:
- To check if the clock configuration is locked, use the
  `::picolibrary::Microchip::megaAVR0::Clock::configuration_locked()` function.
- To lock the clock configuration, use the
  `::picolibrary::Microchip::megaAVR0::Clock::lock_configuration()` function.

## Internal 16/20 MHz Oscillator
The following Microchip megaAVR 0-series internal 16/20 MHz oscillator operations are
supported:
- To check if the internal 16/20 MHz oscillator is stable, use the
  `::picolibrary::Microchip::megaAVR0::Clock::internal_16_20_MHz_oscillator_stable()`
  function.
- To get the internal 16/20 MHz oscillator mode, use the
  `::picolibrary::Microchip::megaAVR0::Clock::internal_16_20_MHz_oscillator_mode()`
  function.
- To set the internal 16/20 MHz oscillator mode, use the
  `::picolibrary::Microchip::megaAVR0::Clock::set_internal_16_20_MHz_oscillator_mode()`
  function.
- To check if the internal 16/20 MHz oscillator calibration is locked, use the
  `::picolibrary::Microchip::megaAVR0::Clock::internal_16_20_MHz_oscillator_calibration_locked()`
  function.
- To calibrate the internal 16/20 MHz oscillator, use the
  `::picolibrary::Microchip::megaAVR0::Clock::calibrate_internal_16_20_MHz_oscillator()`
  function.

## Internal 32.768 kHz Ultra Low-Power Oscillator
The following Microchip megaAVR 0-series internal 32.768 kHz ultra low-power oscillator
operations are supported:
- To check if the internal 32.768 kHz ultra low-power oscillator is stable, use the
  `::picolibrary::Microchip::megaAVR0::Clock::internal_32_768_kHz_ultra_low_power_oscillator_stable()`
  function.
- To get the internal 32.768 kHz ultra low-power oscillator mode, use the
  `::picolibrary::Microchip::megaAVR0::Clock::internal_32_768_kHz_ultra_low_power_oscillator_mode()`
  function.
- To set the internal 32.768 kHz ultra low-power oscillator mode, use the
  `::picolibrary::Microchip::megaAVR0::Clock::set_internal_32_768_kHz_ultra_low_power_oscillator_mode()`
  function.

## External 32.768 kHz Crystal Oscillator
The following Microchip megaAVR 0-series external 32.768 kHz crystal oscillator operations
are supported:
- To check if the external 32.768 kHz crystal oscillator is stable, use the
  `::picolibrary::Microchip::megaAVR0::Clock::external_32_768_kHz_crystal_oscillator_stable()`
  function.
- To get the external 32.768 kHz crystal oscillator source, use the
  `::picolibrary::Microchip::megaAVR0::Clock::external_32_768_kHz_crystal_oscillator_source()`
  function.
- To get the external 32.768 kHz crystal oscillator start-up time, use the
  `::picolibrary::Microchip::megaAVR0::Clock::external_32_768_kHz_crystal_oscillator_start_up_time()`
  function.
- To get the external 32.768 kHz crystal oscillator mode, use the
  `::picolibrary::Microchip::megaAVR0::Clock::external_32_768_kHz_crystal_oscillator_mode()`
  function.
- To configure the external 32.768 kHz crystal oscillator, use the
  `::picolibrary::Microchip::megaAVR0::Clock::configure_external_32_768_kHz_crystal_oscillator()`
  function.
- To set the external 32.768 kHz crystal oscillator mode, use the
  `::picolibrary::Microchip::megaAVR0::Clock::set_external_32_768_kHz_crystal_oscillator_mode()`
  function.
- To check if the external 32.768 kHz crystal oscillator is enabled, use the
  `::picolibrary::Microchip::megaAVR0::Clock::external_32_768_kHz_crystal_oscillator_enabled()`
  function.
- To enable the external 32.768 kHz crystal oscillator, use the
  `::picolibrary::Microchip::megaAVR0::Clock::enable_external_32_768_kHz_crystal_oscillator()`
  function.
- To disable the external 32.768 kHz crystal oscillator, use the
  `::picolibrary::Microchip::megaAVR0::Clock::disable_external_32_768_kHz_crystal_oscillator()`
  function.

## External Clock
The following Microchip megaAVR 0-series external clock operations are supported:
- To check if the external clock is stable, use the
  `::picolibrary::Microchip::megaAVR0::Clock::external_clock_stable()` member function.

## Interactive Testing Clock Configuration
The `::picolibrary::Testing::Interactive::Microchip::megaAVR0::configure_clock()`
interactive testing clock configuration utilities are available if the
`PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING` project configuration option
is `ON`.
The utilities are defined in the
[`include/picolibrary/testing/interactive/microchip/megaavr0/clock.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/testing/interactive/microchip/megaavr0/clock.h)/[`source/picolibrary/testing/interactive/microchip/megaavr0/clock.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/testing/interactive/microchip/megaavr0/clock.cc)
header/source file pair.
