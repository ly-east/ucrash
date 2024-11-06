# About ucrash
A wrapper of `crashpad` based on modified crashpad cmake version [backtrace/crashpad](https://github.com/backtrace-labs/crashpad.git).

This project exports a dynamic link library that can be shared by different objects of your project.

Target C++ version is `C++17` to use `filesystem` library.

# Usage

## Introduce to Your Project

It is recommended to add this repository to your project as a submodule and place it into `third-party` folder.

Get repository by git:

``` sh
git submodule add https://github.com/ly-east/ucrash.git third-party/ucrash
git submodule update --init --recursive
```

...then add to your project as a dependency in CMakeLists.txt:

``` cmake
# if your target executable is a console application, then
add_dependencies(<TARGET> handler_console)
# else
add_dependencies(<TARGET> handler)

target_include_directories(<TARGET> ${CMAKE_SOURCE_DIR}/third-party/ucrash/include)
target_link_libraries(<TARGET> ucrash)

# replace `handler_console` by `handler` if target is window application
set(HANDLER_CONSOLE_PATH "${CMAKE_BINARY_DIR}/third-party/ucrash/third-party/crashpad/handler/${CMAKE_BUILD_TYPE}/handler_console")
if(WIN32)
  string(CONCAT HANDLER_CONSOLE_PATH ${HANDLER_CONSOLE_PATH} ".exe")
endif(WIN32)

install(TARGETS <TARGET>)
install(FILES
  ${HANDLER_CONSOLE_PATH}
  DESTINATION ${CMAKE_INSTALL_PREFIX}
)
```

...and include header file `ucrash.h` where you should write log.

``` cpp
#include "ucrash/ucrash.h"

ucrash::setConsoleHandler();  // for console application
ucrash::setWindowHandler();   // for window application
```

## Demo Program

A simple program `tester` demostrating the basic usage of ucrash is shipped with ucrash, though it won't be built by default.

You may flip the switch(set to `ON`) of cmake variable `UCRASH_ENABLE_TESTER` in root CMake file to build it.
