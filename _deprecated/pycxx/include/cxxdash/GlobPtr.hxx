#ifndef CXXDASH__GLOB_PTR_HXX__INCLUDED
#define CXXDASH__GLOB_PTR_HXX__INCLUDED

#include <CXX/Extensions.hxx>

#include <cxxdash/Defines.hxx>

#include <libdash.h>

#include <iostream>
#include <sstream>
#include <string>


class GlobPtrCxx : public Py::PythonExtension<GlobPtrCxx> {

  dash::GlobPtr<int> _globptr;

public:

  static void init_type(void); // announce properties and methods

  GlobPtrCxx(dart_gptr_t gptr)
    : _globptr(gptr)
  {}

  Py::Object repr()
  {
    std::string s;
    std::ostringstream s_out;
    s_out << "GlobPtrCxx gptr(" << _globptr << ")";
    return Py::String(s_out.str());
  }

  Py::Object iter()
  {
    return Py::Object(this, false); // increment the refcount
  }

  PyObject * iternext()
  {
    _globptr++;
    return Py::Object(this, false); // increment the refcount

    /*
      result.increment_reference_count();
      return result.ptr();
    */
  }
};

#endif // CXXDASH__GLOB_PTR_HXX__INCLUDED
