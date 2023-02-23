# Device Info Facilities
Microchip megaAVR 0-series device info facilities are defined in the
[`include/picolibrary/microchip/megaavr0/device_info.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/device_info.h)/[`source/picolibrary/microchip/megaavr0/device_info.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/device_info.cc)
header/source file pair.

## Table of Contents
1. [Device Type](#device-type)
1. [Device Revision](#device-revision)
1. [Device Serial Number](#device-serial-number)
1. [Print Interactive Test Helper](#print-interactive-test-helper)

## Device Type
The `::picolibrary::Microchip::megaAVR0::Device_Info::Device_Type` enum class is used to
identify a Microchip megaAVR 0-series device type.
- To get the device type, use the
  `::picolibrary::Microchip::megaAVR0::Device_Info::device_type()` function.

`::picolibrary::Output_Formatter` is specialized for
`::picolibrary::Microchip::megaAVR0::Device_Info::Device_Type`.
The
`::picolibrary::Output_Formatter<::picolibrary::Microchip::megaAVR0::Device_Info::Device_Type>`
specialization does not support user formatting configuration.

## Device Revision
The `::picolibrary::Microchip::megaAVR0::Device_Info::Device_Revision` class is used to
store a Microchip megaAVR 0-series device revision.
- To get a device revision in its unsigned integer representation, use the
  `::picolibrary::Microchip::megaAVR0::Device_Info::Device_Revision::as_unsigned_integer()`
  member function.
- To get a device revision in its printable character representation, use the
  `::picolibrary::Microchip::megaAVR0::Device_Info::Device_Revision::as_printable_character()`
  member function.
- Direct comparison is supported.
- To get the device revision, use the
  `::picolibrary::Microchip::megaAVR0::Device_Info::device_revision()` function.

`::picolibrary::Output_Formatter` is specialized for
`::picolibrary::Microchip::megaAVR0::Device_Info::Device_Revision`.
The
`::picolibrary::Output_Formatter<::picolibrary::Microchip::megaAVR0::Device_Info::Device_Revision>`
specialization does not support user formatting configuration.

## Device Serial Number
The `::picolibrary::Microchip::megaAVR0::Device_Info::Device_Serial_Number` class is used
to store a Microchip megaAVR 0-series device serial number.
- To get a device serial number in its array representation, use the
  `::picolibrary::Microchip::megaAVR0::Device_Info::Device_Serial_Number::as_array()`
  member function.
- Direct comparison for equality or inequality is supported.
- To get the device serial number, use the
  `::picolibrary::Microchip::megaAVR0::Device_Info::device_serial_number()` function.

`::picolibrary::Output_Formatter` is specialized for
`::picolibrary::Microchip::megaAVR0::Device_Info::Device_Serial_Number`.
The
`::picolibrary::Output_Formatter<::picolibrary::Microchip::megaAVR0::Device_Info::Device_Serial_Number>`
specialization does not support user formatting configuration.

## Print Interactive Test Helper
The `::picolibrary::Testing::Interactive::Microchip::megaAVR0::Device_Info::print()` print
interactive test helper is available if the
`PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING` project configuration option
is `ON`.
The interactive test helper is defined in the
[`include/picolibrary/testing/interactive/microchip/megaavr0/device_info.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/testing/interactive/microchip/megaavr0/device_info.h)/[`source/picolibrary/testing/interactive/microchip/megaavr0/device_info.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/testing/interactive/microchip/megaavr0/device_info.cc)
header/source file pair.
