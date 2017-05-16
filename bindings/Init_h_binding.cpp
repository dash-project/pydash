
#include <pybind11/pybind11.h>

#include <dash/Init.h>
#include <dash/Types.h>


namespace py = pybind11;

PYBIND11_PLUGIN(DASH) {
    py::module m("dash", "DASH Binding");
				
		m.def("init",
          (void (*)(int*, char*))          &dash::init,
          "Initalize DASH runtime");

		m.def("finalize",
          (void (*)(void))                 &dash::finalize,
          "Finalize the DASH library and the underlying runtime system.");

		m.def("is_initialized",
          (bool (*)(void))                 &dash::is_initialized,
          "Check whether DASH has been initialized already.");

//	m.def("is_multithreaded",
//	      (bool (*)(void))                 &dash::is_multithreaded,
//	      "Check whether DASH supports multi-threaded access.");

		m.def("myid",
          (dash::global_unit_t (*)(void))  &dash::myid,
          "Shortcut to query the global unit ID of the calling unit.");

		m.def("size",
          (ssize_t (*)(void))              &dash::size,
          "Return the number of units in the global team.");

		m.def("barrier",
          (void (*)(void))                 &dash::barrier,
          "A global barrier involving all units.");
				
		return m.ptr();
		
}
