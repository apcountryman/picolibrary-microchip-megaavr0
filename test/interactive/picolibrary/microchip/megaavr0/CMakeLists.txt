# picolibrary-microchip-megaavr0
#
# Copyright 2021-2023, Andrew Countryman <apcountryman@gmail.com> and the
# picolibrary-microchip-megaavr0 contributors
#
# Licensed under the Apache License, Version 2.0 (the "License"); you may not use this
# file except in compliance with the License. You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software distributed under
# the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied. See the License for the specific language governing
# permissions and limitations under the License.

# Description: picolibrary::Microchip::megaAVR0 interactive tests CMake rules.

# build the picolibrary::Microchip::megaAVR0::Asynchronous_Serial interactive tests
add_subdirectory( asynchronous_serial )

# build the picolibrary::Microchip::megaAVR0::Device_Info interactive tests
add_subdirectory( device_info )

# build the picolibrary::Microchip::megaAVR0::GPIO interactive tests
add_subdirectory( gpio )

# build the picolibrary::Microchip::megaAVR0::I2C interactive tests
add_subdirectory( i2c )

# build the picolibrary::Microchip::megaAVR0::SPI interactive tests
add_subdirectory( spi )
