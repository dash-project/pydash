
#include <cdash/GlobPtr.h>

#include <dash/GlobPtr.h>

CGlobPtr cdash__glob_ptr__new(dart_gptr_t gptr)
{
  return reinterpret_cast<CGlobPtr>(
           new dash::GlobPtr<CGlobPtr_value_type>(gptr));
}

CGlobPtr cdash__glob_ptr__inc(CGlobPtr _this)
{
  /* Implementing prefix increment only for now */
  return reinterpret_cast<CGlobPtr>(++this);
}


