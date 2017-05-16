#include <pybind11/pybind11.h>

#include <dash/Init.h>

namespace py = pybind11;

PYBIND11_PLUGIN(DASH) {
  py::module m("dash", "DASH Binding");

  m.def("init",             &dash::init);
  m.def("finalize",         &dash::finalize);
  m.def("is_initialized",   &dash::is_initialized);
  m.def("is_multithreaded", &dash::is_multithreaded);
  m.def("myid",             &dash::myid);
  m.def("size",             &dash::size);
  m.def("barrier",          &dash::barrier);

  return m.ptr();
}
