# picolibrary-microchip-megaavr0
[![CI](https://github.com/apcountryman/picolibrary-microchip-megaavr0/actions/workflows/ci.yml/badge.svg)](https://github.com/apcountryman/picolibrary-microchip-megaavr0/actions/workflows/ci.yml)
[![Contributor Covenant](https://img.shields.io/badge/Contributor%20Covenant-2.0-4baaaa.svg)](CODE_OF_CONDUCT.md)

[`picolibrary`](https://github.com/apcountryman/picolibrary) Hardware Interface Layer
(HIL) for Microchip megaAVR 0-series microcontrollers.

## Obtaining the Source Code
HTTPS:
```shell
git clone --recurse-submodules https://github.com/apcountryman/picolibrary-microchip-megaavr0.git
```
SSH:
```shell
git clone --recurse-submodules git@github.com:apcountryman/picolibrary-microchip-megaavr0.git
```

## Usage (Dependency)
To use this library as a dependency, simply add the subdirectory containing this
repository to a CMake build, and link with the `picolibrary-microchip-megaavr0` static
library.
```cmake
add_subdirectory( picolibrary-microchip-megaavr0 )
```
```cmake
target_link_libraries(
    foo
    picolibrary-microchip-megaavr0
)
```

## Usage (Development)
This repository's Git `pre-commit` hook script is the simplest way to configure, and build
this project during development.
See the `pre-commit` script's help text for usage details.
```shell
./git/hooks/pre-commit --help
```

Additional checks, such as static analysis, are performed by this project's GitHub Actions
CI workflow.

## Versioning
`picolibrary-microchip-megaavr0` follows the [Abseil Live at Head
philosophy](https://abseil.io/about/philosophy).

## Workflow
`picolibrary-microchip-megaavr0` uses the [GitHub
flow](https://guides.github.com/introduction/flow/) workflow.

## Git Hooks
To install this repository's Git hooks, execute the `install` script located in the
`git/hooks` directory.
See the `install` script's help text for usage details.
```shell
./git/hooks/install --help
```

## Code of Conduct
`picolibrary-microchip-megaavr0` has adopted the Contributor Covenant 2.0 code of conduct.
For more information, [see the `CODE_OF_CONDUCT.md` file in this
repository](CODE_OF_CONDUCT.md).

## Contributing
If you are interested in contributing to `picolibrary-microchip-megaavr0`, please [read
the `CONTRIBUTING.md` file in this repository](CONTRIBUTING.md).

## Authors
- Andrew Countryman

## License
`picolibrary-microchip-megaavr0` is licensed under the Apache License, Version 2.0.
For more information, [see the `LICENSE` file in this repository](LICENSE).
