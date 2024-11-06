#include "ucrash/ucrash.h"

int main() {
  if (!ucrash::setConsoleHandler())
    return -1;

  ucrash::crashTest();

  return 0;
}
