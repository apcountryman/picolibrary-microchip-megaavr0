# Library Version
To access the null-terminated library version string that is stored in ROM, link with the
`picolibrary-microchip-megaavr0-version` static library, include
[`picolibrary/microchip/megaavr0/version.h`](https://github.com/apcountryman/picolibrary-microchip-megaavr0/blob/main/include/picolibrary/microchip/megaavr0/version.h)
and use `::picolibrary::Microchip::megaAVR0::version()`:
```cmake
target_link_libraries(
    foo
    picolibrary-microchip-megaavr0
    picolibrary-microchip-megaavr0-version
)
```
```c++
#include "picolibrary/stream.h"
#include "picolibrary/microchip/megaavr0/version.h"

void foo( ::picolibrary::Reliable_Output_Stream & stream ) noexcept
{
    stream.put( ::picolibrary::Microchip::megaAVR0::version() );
}
```
The null-terminated library version string is populated with the output of the following
Git command:
```shell
git describe --match=none --always --dirty --broken
```
