# Register Facilities
Microchip megaAVR 0-series register facilities are defined in the
[`include/picolibrary/microchip/megaavr0/register.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/register.h)/[`source/picolibrary/microchip/megaavr0/register.cc`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/source/picolibrary/microchip/megaavr0/register.cc)
header/source file pair.

## Table of Contents
1. [Protected Register](#protected-register)

## Protected Register
The `::picolibrary::Microchip::megaAVR0::Protected_Register` class is used to declare a
Microchip megaAVR 0-series register that is under configuration change protection.
Register access is restricted to the following operations:
- Conversion to the underlying register type (reading the register)
- Assignment
- Bitwise AND assignment
- Bitwise OR assignment
- Bitwise XOR assignment
