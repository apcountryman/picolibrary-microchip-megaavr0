# Register Facilities
Microchip megaAVR 0-series register facilities are defined in the
[`include/picolibrary/microchip/megaavr0/register.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/register.h)/[`source/picolibrary/microchip/megaavr0/register.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/register.cc)
header/source file pair.

## Table of Contents
1. [Register](#register)
1. [Reserved Register](#reserved-register)
1. [Protected Register](#protected-register)

## Register
The `::picolibrary::Microchip::megaAVR0::Register` class is used to declare a Microchip
megaAVR 0-series register that is neither reserved nor protected.
Register access is restricted to the following operations:
- Conversion to the underlying register type (reading the register)
- Assignment
- Bitwise AND assignment
- Bitwise OR assignment
- Bitwise XOR assignment

## Reserved Register
The `::picolibrary::Microchip::megaAVR0::Reserved_Register` class is used to declare a
Microchip megaAVR 0-series reserved register.
A reserved register cannot be accessed.

## Protected Register
The `::picolibrary::Microchip::megaAVR0::Protected_Register` class is used to declare a
Microchip megaAVR 0-series protected register.
Register access is restricted to the following operations:
- Conversion to the underlying register type (reading the register)
- Assignment
- Bitwise AND assignment
- Bitwise OR assignment
- Bitwise XOR assignment
