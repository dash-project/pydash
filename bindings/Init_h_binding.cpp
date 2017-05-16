#include <pybind11/pybind11.h>

#include "~/workspaces/dash/dash/include/dash/Init.h"

namespace py = pybind11;

PYBIND11_PLUGIN(DASH) {
    py::module m("dash", "DASH Binding");
				
		m.def("init",             (void  (*)(int*, char***)) &dash::init,              "Initalize DASH runtime");
		m.def("finalize", 				(void)                     &dash::finalize,          "Finalize the DASH library and the underlying runtime system.");
		m.def("is_initialized", 	(bool)                     &dash::is_initialized,    "Check whether DASH has been initialized already.");
		m.def("is_multithreaded", (bool)                     &dash::is_multithreaded,  "Check whether DASH has been initialized with support for multi-threaded access.");
		m.def("myid", 						(global_unit_t)            &dash::myid,              "Shortcut to query the global unit ID of the calling unit.");
		m.def("size", 						(ssize_t)                  &dash::size,              "Return the number of units in the global team.");
		m.def("barrier", 					(void)                     &dash::barrier,           "A global barrier involving all units.");
				
		return m.ptr();
		
}
