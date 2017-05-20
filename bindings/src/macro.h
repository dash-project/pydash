#include <iostream>
#include <iomanip>

#define wno_unused_(var) (void)(var)

#define LOG(scope, msg) do { \
  std::clog << "-- LOG | " << std::setw(27) << scope << " | " \
            << msg << std::endl; \
} while(0)