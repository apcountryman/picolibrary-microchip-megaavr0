# Interactive Tests

## Configuration Requirements
picolibrary-microchip-megaavr0 interactive tests have the following project configuration
requirements:
- `PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING` must be on
- `PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_CONFIGURE_CLOCK_CLOCK_PRESCALER_VALUE`
  must be configured
- `PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_CONFIGURE_CLOCK_CLOCK_PRESCALER_CONFIGURATION`
  must be configured
- `PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_LOG_USART` must be configured
- `PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_LOG_USART_ROUTE` must be configured
- `PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_LOG_USART_CLOCK_GENERATOR_OPERATING_SPEED`
  must be configured
- `PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_LOG_USART_CLOCK_GENERATOR_SCALING_FACTOR`
  must be configured

## avrdude Configuration Options
picolibrary-microchip-megaavr0 interactive tests support the following avrdude
configuration options:
- `PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_RESET_ENABLED` (defaults to `OFF`): reset AVR
  before executing avrdude
- `PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_CONFIGURATION_FILE` (optional): avrdude
  configuration file
- `PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_PORT`: avrdude port
- `PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_PROGRAM_FLASH`: flash programming avrdude
  arguments
- `PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_VERBOSITY` (defaults to `VERBOSE`): avrdude
  verbosity
- `PICOLIBRARY_MICROCHIP_MEGAAVR0_AVRDUDE_VERIFY_FLASH`: flash verification avrdude
  arguments

## Test Targets
Each picolibrary-microchip-megaavr0 interactive test has the following targets:
- `<test executable name>`: executable creation target
- `<test executable name>-hex-flash`: Flash programming/verification hex file creation
  target
- `<test executable name>-program-flash`: Flash programming target
- `<test executable name>-verify-flash`: Flash verification target

## Tests
