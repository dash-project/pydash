#include <pybind11/pybind11.h>

#include "dash/dash/include/dash/Init.h"

namespace py = pybind11;

PYBIND11_PLUGIN(DASH) {
    py::module m("dash", "DASH Binding");
		
		//y::class_<ec::error_class> error_class(m, "error_class");
		
		m.def("init",
        (void  (*)(int*, char***)) &dash::init, "Initalize DASH runtime");
		m.def("finalize", 				&dash::finalize);
		m.def("is_initialized", 	&dash::is_initialized);
		m.def("is_multithreaded", &dash::is_multithreaded);
		m.def("myid", 						&dash::myid);
		m.def("size", 						&dash::size);
		m.def("barrier", 					&dash::barrier);
				
		return m.ptr();
		
}
