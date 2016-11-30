#ifndef CXXDASH__INIT_HXX__INCLUDED
#define CXXDASH__INIT_HXX__INCLUDED

#include <CXX/Extensions.hxx>

#include <cxxdash/Defines.hxx>

#include <libdash.h>


class DASHInit : public Py::PythonExtension<DASHInit> {

public:

  static void init_type(void); // announce properties and methods

  Py::Object repr()
  {
    std::string s;
    std::ostringstream s_out;
    s_out << "DASHInit ()";
    return Py::String(s_out.str());
  }

  inline static void init() {
    dash::init(); // TODO: pass argc, argv
  }

  inline static void finalize() {
    dash::finalize();
  }

  inline static int myid() {
    return dash::myid();
  }

  inline static bool is_initialized() {
    return dash::is_initialized();
  }

};

#endif // CXXDASH__INIT_HXX__INCLUDED
