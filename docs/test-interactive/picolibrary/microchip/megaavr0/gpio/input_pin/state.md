# `::picolibrary::Microchip::megaAVR0::GPIO::Input_Pin` state interactive test

## Test Configuration Options
The `::picolibrary::Microchip::megaAVR0::GPIO::Input_Pin` state interactive test supports
the following configuration options:
- `PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INPUT_PIN_ENABLE_STATE_INTERACTIVE_TEST` (defaults
  to `OFF`): enable the `::picolibrary::Microchip::megaAVR0::GPIO::Input_Pin` state
  interactive test
    - The following configuration options are available if
      `PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INPUT_PIN_ENABLE_STATE_INTERACTIVE_TEST` is
      `ON`:
        - `PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INPUT_PIN_STATE_INTERACTIVE_TEST_PIN_PORT`:
          `::picolibrary::Microchip::megaAVR0::GPIO::Input_Pin` state interactive test pin
          PORT
        - `PICOLIBRARY_MICROCHIP_MEGAAVR0_GPIO_INPUT_PIN_STATE_INTERACTIVE_TEST_PIN_MASK`:
          `::picolibrary::Microchip::megaAVR0::GPIO::Input_Pin` state interactive test pin
          mask

## Test Executable Names
- `test-interactive-picolibrary-microchip-megaavr0-gpio-input_pin-port-state`
- `test-interactive-picolibrary-microchip-megaavr0-gpio-input_pin-vport-state`
