cmake_minimum_required(VERSION 3.15.0)

# ref: https://cmake.org/cmake/help/latest/prop_tgt/MSVC_RUNTIME_LIBRARY.html
if (POLICY CMP0091)
  cmake_policy(SET CMP0091 NEW)
endif (POLICY CMP0091)

project(ucrash VERSION 0.5.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(WIN32)
  if(MSVC)
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
  endif(MSVC)
endif(WIN32)

set(UCRASH_ENABLE_TESTER OFF)

add_subdirectory(third-party)

# ===================================================================
# ucrash dynamic link library

add_library(ucrash SHARED lib/ucrash.cpp)

target_compile_definitions(ucrash PUBLIC UCRASH_DLL=1)
target_include_directories(ucrash PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(ucrash
  client
)

install(TARGETS ucrash)

# ===================================================================
# tester executable

if (UCRASH_ENABLE_TESTER)
  add_executable(tester lib/tester.cpp)
  add_dependencies(tester handler_console)

  target_include_directories(tester PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
  target_link_libraries(tester ucrash)

  set(HANDLER_CONSOLE_PATH "${CMAKE_BINARY_DIR}/third-party/crashpad/handler/${CMAKE_BUILD_TYPE}/handler_console")
  if(WIN32)
    string(CONCAT HANDLER_CONSOLE_PATH ${HANDLER_CONSOLE_PATH} ".exe")
  endif(WIN32)

  install(TARGETS tester)
  install(FILES
    ${HANDLER_CONSOLE_PATH}
    DESTINATION ${CMAKE_INSTALL_PREFIX}
  )
endif(UCRASH_ENABLE_TESTER)
