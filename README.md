# About ucrash
A wrapper of `crashpad` to address issue caused by static variable among DLLs/EXEs/SOs/DYLIBs...

This project exports a dynamic link library that can be shared by different objects of your project.

Target spdlog version is `v1.14.1`.

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
target_include_directories(<YOUR-PROJECT-NAME> ${CMAKE_SOURCE_DIR}/third-party/ucrash/include)
target_link_libraries(<YOUR-PROJECT-NAME> ucrash)
```

...and include header file `ucrash.h` where you should write log.

``` cpp
#include "ucrash/ucrash.h"

ul::error("hello, {}", "there");  // "hello, there"
```

Usage of log functions is just same to spdlog. Only thing you should notice is to replace `spdlog` by `ul`.

## Demo Program

A simple program `tester` demostrating the basic usage of ucrash is shipped with ucrash, though it won't be built by default.

You may flip the switch(set to `ON`) of cmake variable `UCRASH_ENABLE_TESTER` in root CMake file to build it.
