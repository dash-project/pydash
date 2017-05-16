#include <pybind11/pybind11.h>

#include "dash/dash/include/dash/GlobPtr.h"

namespace py = pybind11;

PYBIND11_PLUGIN(DASH) {
    py::module m("dash", "DASH Binding");
		
		py::class_<dash::GlobPtr> GlobPtr(m, "error_class");
		
		GlobPtr.def(py::init<>());
		GlobPtr.def(py::init<const MemorySpace *, dart_gptr_t, index_type>());
		GlobPtr.def(py::init<const MemorySpace *, dart_gptr_t>());
		GlobPtr.def(py::init<const GlobPtr<T, MemSpaceT> &>());
		
		GlobPtr.def(py::init<self_t &&>());
		
		
		
		GlobPtr.def("init",							&dash::init);
		
				
		return m.ptr();
		
}

.def(py::init<float, float>())
.def(py::self + py::self)
.def(py::self + float())
.def(py::self - py::self)
.def(py::self - float())
.def(py::self * float())
.def(py::self / float())
.def(py::self += py::self)
.def(py::self -= py::self)
.def(py::self *= float())
.def(py::self /= float())
.def(float() + py::self)
.def(float() - py::self)
.def(float() * py::self)
.def(float() / py::self)