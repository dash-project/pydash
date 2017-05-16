#include <pybind11/pybind11.h>

#include <dash/GlobPtr.h>

namespace py = pybind11;

PYBIND11_PLUGIN(DASH) {
  py::module m("dash", "DASH Binding");

  py::class_<dash::GlobPtr> GlobPtr(m, "GlobPtr");

  GlobPtr.def(py::init<>());
  GlobPtr.def(py::init<const MemorySpace *, dart_gptr_t, index_type>());
  GlobPtr.def(py::init<const MemorySpace *, dart_gptr_t>());
  GlobPtr.def(py::init<const GlobPtr<T, MemSpaceT> &>());

  GlobPtr.def(py::init<self_t &&>());

  // Operatoren abbilden ?, z.B.:
  GlobPtr.def("deref",
              ((GlobRef<value_type>) (*) (GlobPtr< ? >)) &dash::GlobPtr::*,
              "Dereference operator.");

  GlobPtr.def("local",
              ((value_type *)(*)) & dash::GlobPtr::local,
              "Conversion to local pointer.");

  GlobPtr.def("set_unit",
              (void(*) team_unit_it) &dash::GlobPtr::set_unit,
              "Set the global pointer's associated unit.");

  GlobPtr.def("is_local",
              (bool(*)) &dash::GlobPtr::is_local,
              "Check whether the global pointer is in the local "
              "address space the pointer's associated unit.");

  return m.ptr();
}
