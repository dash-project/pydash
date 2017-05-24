#include <iostream>
#include <sstream>
#include <iomanip>

#include <libdash.h>

#define wno_unused_(var) (void)(var)

#define LOG(scope, msg) do { \
  std::ostringstream ss; \
  ss << "-- LOG | " << std::setw(4) << dash::myid().id << " |" \
     << std::setw(27) << scope << " | " \
     << msg; \
  std::clog << ss.str() << std::endl; \
} while(0)

