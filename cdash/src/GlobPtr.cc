
#include <cdash/GlobPtr.h>

#include <dash/GlobPtr.h>

CGlobPtr cdash__glob_ptr__new(dart_gptr_t gptr)
{
  return reinterpret_cast<CGlobPtr>(
           new dash::GlobPtr<CGlobPtr_value_type>(gptr));

}

void cdash__glob_ptr__delete(dart_gptr_r gptr)
{
   // No destructor in GlobPtr.h
}

CGlobPtr cdash__glob_ptr__copy(CGlobPtr _this)
{
 return reinterpret_cast<CGlobPtr>GlobPtr(_this);
}

CGlobPtr cdash__glob_ptr__assign(CGlobPtr _this, CGlobPtr rhs)
{
  return reinterpret_cast<GlobPtr>(_this = rhs);
}

int cdash__glob_ptr__equals(CGlobPtr _this, CGlobPtr rhs)
{
  /* According to §4.7/4 Standard bool > int conversion is implicit to C++ */
  return (_this == rhs);
}

dart_gptr_t  cdash__glob_ptr__dart_gptr_t(CGlobPtr _this)
{
  return _this.dart_gptr_t();
}

CGlobPtr cdash__glob_ptr__inc(CGlobPtr _this)
{
  /* Implementing prefix increment only for now */
  return reinterpret_cast<CGlobPtr>(++this);
}

CGlobPtr cdash__glob_ptr__dec(CGlobPtr _this)
{
  return reinterpret_cast<CGlobPtr>(--this);
}

CGlobPtr cdash__glob_ptr__offset(CGlobPtr _this, int offset)
{
  return reinterpret_cast<CGlobPtr>(_this+=offset);
}
