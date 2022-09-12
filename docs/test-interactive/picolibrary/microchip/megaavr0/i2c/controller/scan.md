# `::picolibrary::Microchip::megaAVR0::I2C::Controller` scan interactive test

## Test Configuration Options
The `::picolibrary::Microchip::megaAVR0::I2C::Controller` scan interactive test supports
the following configuration options:
- `PICOLIBRARY_MICROCHIP_MEGAAVR0_I2C_CONTROLLER_ENABLE_SCAN_INTERACTIVE_TEST` (defaults
  to `OFF`): enable the `::picolibrary::Microchip::megaAVR0::I2C::Controller` scan
  interactive test
    - The following configuration options are available if
      `PICOLIBRARY_MICROCHIP_MEGAAVR0_I2C_CONTROLLER_ENABLE_SCAN_INTERACTIVE_TEST` is
      `ON`:
        - `PICOLIBRARY_MICROCHIP_MEGAAVR0_I2C_CONTROLLER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI`:
          `::picolibrary::Microchip::megaAVR0::I2C::Controller` scan interactive test
          controller TWI
        - `PICOLIBRARY_MICROCHIP_MEGAAVR0_I2C_CONTROLLER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_SDA_HOLD_TIME`:
          `::picolibrary::Microchip::megaAVR0::I2C::Controller` scan interactive test
          controller TWI SDA hold time
        - `PICOLIBRARY_MICROCHIP_MEGAAVR0_I2C_CONTROLLER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_BUS_SPEED`:
          `::picolibrary::Microchip::megaAVR0::I2C::Controller` scan interactive test
          controller TWI bus speed
        - `PICOLIBRARY_MICROCHIP_MEGAAVR0_I2C_CONTROLLER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_CLOCK_GENERATOR_SCALING_FACTOR`:
          `::picolibrary::Microchip::megaAVR0::I2C::Controller` scan interactive test
          controller TWI clock generator scaling factor
        - `PICOLIBRARY_MICROCHIP_MEGAAVR0_I2C_CONTROLLER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_INACTIVE_BUS_TIME_OUT`:
          `::picolibrary::Microchip::megaAVR0::I2C::Controller` scan interactive test
          controller TWI inactive bus time-out
        - `PICOLIBRARY_MICROCHIP_MEGAAVR0_I2C_CONTROLLER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_ROUTE`:
          `::picolibrary::Microchip::megaAVR0::I2C::Controller` scan interactive test
          controller TWI route

## Test Executable Names
`test-interactive-picolibrary-microchip-megaavr0-i2c-controller-scan`
