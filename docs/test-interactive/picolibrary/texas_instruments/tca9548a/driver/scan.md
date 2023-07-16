# `::picolibrary::Texas_Instruments::TCA9548A::Driver` scan interactive test

## Table of Contents
1. [Test Configuration Options](#test-configuration-options)
1. [Test Executable Name](#test-executable-name)

## Test Configuration Options
The `::picolibrary::Texas_Instruments::TCA9548A::Driver` scan interactive test supports
the following configuration options:
- `PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_ENABLE_SCAN_INTERACTIVE_TEST` (defaults
  to `OFF`): enable the `::picolibrary::Texas_Instruments::TCA9548A::Driver` scan
  interactive test
    - The following configuration options are available if
      `PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_ENABLE_SCAN_INTERACTIVE_TEST` is
      `ON`:
        - `PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI`:
          `::picolibrary::Texas_Instruments::TCA9548A::Driver` scan interactive test
          controller TWI
        - `PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_SDA_HOLD_TIME`:
          `::picolibrary::Texas_Instruments::TCA9548A::Driver` scan interactive test
          controller TWI SDA hold time
        - `PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_BUS_SPEED`:
          `::picolibrary::Texas_Instruments::TCA9548A::Driver` scan interactive test
          controller TWI bus speed
        - `PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_CLOCK_GENERATOR_SCALING_FACTOR`:
          `::picolibrary::Texas_Instruments::TCA9548A::Driver` scan interactive test
          controller TWI clock generator scaling factor
        - `PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_INACTIVE_BUS_TIME_OUT`:
          `::picolibrary::Texas_Instruments::TCA9548A::Driver` scan interactive test
          controller TWI inactive bus time-out
        - `PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_SCAN_INTERACTIVE_TEST_CONTROLLER_TWI_ROUTE`:
          `::picolibrary::Texas_Instruments::TCA9548A::Driver` scan interactive test
          controller TWI route
        - `PICOLIBRARY_TEXAS_INSTRUMENTS_TCA9548A_DRIVER_SCAN_INTERACTIVE_TEST_TCA9548A_ADDRESS`
          (defaults to `Address_Numeric{ 0b1110'000 }`):
          `::picolibrary::Texas_Instruments::TCA9548A::Driver` scan interactive test
          TCA9548A address

## Test Executable Name
`test-interactive-picolibrary-texas_instruments-tca9548a-driver-scan`
