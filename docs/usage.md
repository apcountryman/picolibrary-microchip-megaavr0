# Usage

## Dependency
To use picolibrary-microchip-megaavr0 as a dependency, simply add the subdirectory
containing the repository to a CMake build, and link with the
`picolibrary-microchip-megaavr0` static library.
```cmake
add_subdirectory( picolibrary-microchip-megaavr0 )
```
```cmake
target_link_libraries(
    foo
    picolibrary-microchip-megaavr0
)
```

The `picolibrary-microchip-megaavr0` static library does not include
`::picolibrary::Microchip::megaAVR0::version()`.
To use `::picolibrary::Microchip::megaAVR0::version()`, link with the
`picolibrary-microchip-megaavr0-version` static library.
```cmake
target_link_libraries(
    foo
    picolibrary-microchip-megaavr0
    picolibrary-microchip-megaavr0-version
)
```

### Configuration Options
picolibrary-microchip-megaavr0 supports the following project configuration options:
- `PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING` (defaults to `OFF`): enable
  interactive testing
    - The following project configuration options are available if
      `PICOLIBRARY_MICROCHIP_MEGAAVR0_ENABLE_INTERACTIVE_TESTING` is `ON`:
        - `PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_CONFIGURE_CLOCK_CLOCK_PRESCALER_VALUE`
          (optional):
          `::picolibrary::Testing::Interactive::Microchip::megaAVR0::configure_clock()`
          clock prescaler value (see
          [`include/picolibrary/testing/interactive/microchip/megaavr0/clock.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/testing/interactive/microchip/megaavr0/clock.h)
          for more information)
        - `PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_CONFIGURE_CLOCK_CLOCK_PRESCALER_CONFIGURATION`
          (optional):
          `::picolibrary::Testing::Interactive::Microchip::megaAVR0::configure_clock()`
          clock prescaler configuration (see
          [`include/picolibrary/testing/interactive/microchip/megaavr0/clock.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/testing/interactive/microchip/megaavr0/clock.h)
          for more information)
        - `PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_LOG_USART` (optional):
          `::picolibrary::Testing::Interactive::Microchip::megaAVR0::Log` USART (see
          [`include/picolibrary/testing/interactive/microchip/megaavr0/log.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/testing/interactive/microchip/megaavr0/log.h)
          for more information)
        - `PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_LOG_USART_ROUTE` (optional):
          `::picolibrary::Testing::Interactive::Microchip::megaAVR0::Log` USART route (see
          [`include/picolibrary/testing/interactive/microchip/megaavr0/log.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/testing/interactive/microchip/megaavr0/log.h)
          for more information)
        - `PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_LOG_USART_CLOCK_GENERATOR_OPERATING_SPEED`
          (optional): `::picolibrary::Testing::Interactive::Microchip::megaAVR0::Log`
          USART clock generator operating speed (see
          [`include/picolibrary/testing/interactive/microchip/megaavr0/log.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/testing/interactive/microchip/megaavr0/log.h)
          for more information)
        - `PICOLIBRARY_MICROCHIP_MEGAAVR0_TESTING_INTERACTIVE_LOG_USART_CLOCK_GENERATOR_SCALING_FACTOR`
          (optional): `::picolibrary::Testing::Interactive::Microchip::megaAVR0::Log`
          USART clock generator scaling factor (see
          [`include/picolibrary/testing/interactive/microchip/megaavr0/log.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/testing/interactive/microchip/megaavr0/log.h)
          for more information)
- `PICOLIBRARY_MICROCHIP_MEGAAVR0_USE_PARENT_PROJECT_BUILD_FLAGS` (defaults to `ON`): use
  parent project's build flags
    - The following project configuration options are available if
      `PICOLIBRARY_MICROCHIP_MEGAAVR0_USE_PARENT_PROJECT_BUILD_FLAGS` is `OFF`:
        - `PICOLIBRARY_MICROCHIP_MEGAAVR0_MCU`: MCU type
        - `PICOLIBRARY_MICROCHIP_MEGAAVR0_F_CPU`: CPU frequency, in Hz
- `PICOLIBRARY_MICROCHIP_MEGAAVR0_USE_PARENT_PROJECT_AVRLIBCPP` (defaults to `ON`): use
  parent project's avr-libcpp
- `PICOLIBRARY_MICROCHIP_MEGAAVR0_USE_PARENT_PROJECT_PICOLIBRARY` (defaults to `ON`): use
  parent project's picolibrary

## Development
The repository's Git `pre-commit` hook script is the simplest way to configure, and build
picolibrary-microchip-megaavr0 during development.
See the `pre-commit` script's help text for usage details.
```shell
./git/hooks/pre-commit --help
```

Additional checks, such as static analysis, are performed by the repository's GitHub
Actions CI workflow.
