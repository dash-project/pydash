
#include <pybind11/pybind11.h>

#include <dash/Init.h>
#include <dash/Types.h>


namespace py = pybind11;

using namespace dash;

PYBIND11_PLUGIN(pydash) {
    py::module m("pydash", "DASH Python Binding");
        
    m.def("initialize",
          ((void (*)(int *, char*)) (&init)),
          "Initalize DASH runtime");

    m.def("finalize",
          ((void (*)(void)) (&finalize)),
          "Finalize the DASH library and the underlying runtime system.");

    m.def("is_initialized",
          (bool (*)(void))                 &(dash::is_initialized),
          "Check whether DASH has been initialized.");

//  m.def("is_multithreaded",
//        (bool (*)(void))                 &dash::is_multithreaded,
//        "Check whether DASH supports multi-threaded access.");

//  m.def("myid",
//        &(myid),
//        "Shortcut to query the global unit ID of the calling unit.");
//
//  m.def("size",
//        &(size),
//        "Return the number of units in the global team.");

//  m.def("barrier",
//        (void (*)(void))                 &dash::barrier,
//        "A global barrier involving all units.");
        
    return m.ptr();
}

