
#include "logged_val.h"

#include <iostream>
#include <sstream>


namespace pydash {

std::ostream & operator<<(
  std::ostream     & os,
  const logged_val & lv) {
  std::ostringstream ss;
  ss << "logged_val(" << lv.name() << ":" << lv.value() << ")";
  return operator<<(os, ss.str());l
}

} // namespace pydash

