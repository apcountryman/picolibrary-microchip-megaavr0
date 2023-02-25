# Interactive Testing Utilities
Interactive testing utilities are available if the
`PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING` project configuration option
is `ON`.

## Table of Contents
1. [Fatal Error Trap](#fatal-error-trap)
1. [Log](#log)

## Fatal Error Trap
picolibrary-microchip-megaavr0 provides an implementation for
`::picolibrary::trap_fatal_error()` for use in interactive tests.
The implementation is defined in the
[`source/picolibrary/testing/interactive/microchip/megaavr0/fatal_error.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/testing/interactive/microchip/megaavr0/fatal_error.cc)
source file.
The `picolibrary-microchip-megaavr0` static library does not include this implementation.
To use this implementation, link with the
`picolibrary-microchip-megaavr0-testing-interactive-fatal_error` static library.

## Log
The `::picolibrary::Testing::Interactive::Microchip::megaAVR0::Log` class is a reliable
output stream for interacting with a Microchip megaAVR 0-series USART peripheral.
The `::picolibrary::Testing::Interactive::Microchip::megaAVR0::Log` class is defined in
the
[`include/picolibrary/testing/interactive/microchip/megaavr0/log.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/testing/interactive/microchip/megaavr0/log.h)/[`source/picolibrary/testing/interactive/microchip/megaavr0/log.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/testing/interactive/microchip/megaavr0/log.cc)
header/source file pair.
- To check if the log has been initialized, use the
  `::picolibrary::Testing::Interactive::Microchip::megaAVR0::Log::is_initialized()` static
  member function.
- To initialize the log, use the
  `::picolibrary::Testing::Interactive::Microchip::megaAVR0::Log::initialize()` static
  member functions.
- To report a fatal error, use the
  `::picolibrary::Testing::Interactive::Microchip::megaAVR0::Log::report_fatal_error()`
  static member functions.
- To get the log instance, use the
  `::picolibrary::Testing::Interactive::Microchip::megaAVR0::Log::instance()` static
  member functions.
