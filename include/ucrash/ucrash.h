#ifndef UCRASH_H
#define UCRASH_H

#include "DllExport/DllExport.h"

#include <memory>
#include <string>

namespace ucrash {
// Sets crash handler for console application
DllExport bool setConsoleHandler();

// Sets crash handler for window application
DllExport bool setWindowHandler();

// Causes crash by writing data to memory address 0x4
DllExport void crashTest();
} // namespace ucrash

#endif // UCRASH_H
