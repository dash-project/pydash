
#include <pybind11/pybind11.h>
#include <pybind11/operators.h>

#include <dash/Init.h>
#include <dash/Types.h>
#include <dash/Array.h>

#include <memory>
#include <stdexcept>

#include "logged_val.h"

namespace py = pybind11;

namespace {

  template <typename T>
  static void bind_type_glob_ref(
    py::module        & mod,
    std::string const & suffix) {
    using dash_glob_ref_t   = dash::GlobRef<T>;
    using pydash_glob_ref_t = py::class_<dash_glob_ref_t>;

    pydash_glob_ref_t py_glob_ref(mod, ("GlobRef" + suffix).c_str());

    py_glob_ref.def(py::init<dart_gptr_t>());
    py_glob_ref.def(
        "get",
        [](const dash::GlobRef<T> & gref) {
            return static_cast<const T>(gref);
        },
        py::is_operator());
    py_glob_ref.def(
        "set",
        [](dash::GlobRef<T> & gref, const T & val) {
            gref.set(val);
        },
        py::is_operator());
 // py_glob_ref.def(
 //     "assign",
 //     [](dash::GlobRef<T> & gref, const T & val) {
 //         gref.set(val);
 //     },
 //     py::is_operator());
  }

  template <typename T>
  static void bind_type_array(
    py::module        & mod,
    std::string const & suffix) {
    using dash_array_t   = dash::Array<T>;
    using pydash_array_t = py::class_<
                             dash_array_t,
                             std::shared_ptr<dash_array_t> >;
    using iterator_t     = typename dash_array_t::iterator;

    typedef typename dash_array_t::index_type     index_t;
    typedef typename dash_array_t::size_type      extent_t;
    typedef typename dash_array_t::pattern_type   pattern_t;

    pydash_array_t py_array(mod, ("Array" + suffix).c_str());

    py_array.def(py::init<int>());

    // Usage:
    //   array.unit_at(<global index>) -> unit Id
    py_array.def("unit_at",
       [](dash_array_t & arr, index_t gidx) {
         return arr.pattern().unit_at(gidx).id;
       }
    );

    // Usage:
    //   array[<global index>] = <new value>
    py_array.def("__setitem__",
       [](dash_array_t & arr, index_t gidx, const T & val) {
         if (gidx >= arr.size()) {
           throw std::out_of_range("pydash.Array: index out of bounds");
         }
         arr[gidx] = val;
       }
    );

    // Usage:
    //   val = array[<global index>]
    py_array.def("__getitem__",
       [](dash_array_t & arr, index_t gidx) -> T {
         if (gidx >= arr.size()) {
           throw std::out_of_range("pydash.Array: index out of bounds");
         }
         return arr[gidx].get();
       },
       // ref + keepalive
       py::return_value_policy::reference_internal
    );

    py_array.def("__iter__",
       [](dash_array_t & arr) {
         return py::make_iterator<
                  py::return_value_policy::reference_internal,
                  iterator_t, iterator_t, dash::GlobRef<T> /* T & */
                >(arr.begin(), arr.end());
       },
       // Essential: keep list alive while iterator exists
       py::keep_alive<0, 1>()
    );


    // Usage:
    //   array.at(<global index>) -> GlobRef<T>
    py_array.def("at",
       (dash::GlobRef<T> (dash_array_t::*)(long unsigned int))
       (&dash_array_t::at)
    );
    // Usage:
    //   array.set(<global index>, <new value>)
    py_array.def("set",
       [](dash_array_t & arr, long idx, const T & val) {
            arr[idx] = val;
       }
    );
    // Usage:
    //   array.get(<global index>) -> T
    py_array.def("get",
       [](dash_array_t & arr, long idx) {
            return static_cast<T>(arr[idx]);
       }
    );
  }

}

PYBIND11_PLUGIN(pydash) {
  py::module m("pydash", "DASH Python Binding");

  // ---------------------------------------------------------------------
  // Type: dash::global_unit_t
  //
  py::class_<dash::global_unit_t> global_unit_t_py(m, "global_unit");
  global_unit_t_py
    .def(py::init<int>())
    .def("id",
         [](const dash::global_unit_t & gu) { return static_cast<int>(gu); },
         py::is_operator());

  py::implicitly_convertible<int, dash::global_unit_t>();
      
  // ---------------------------------------------------------------------
  // DASH Runtime Interface
  //
  m.def("initialize",
        (void (*)(int *, char*)) &(dash::init),
        "Initalize DASH runtime");

  m.def("finalize",
        (void (*)(void)) &(dash::finalize),
        "Finalize the DASH library and the underlying runtime system.");

  m.def("is_initialized",
        (bool (*)(void)) &(dash::is_initialized),
        "Check whether DASH has been initialized.");

  m.def("is_multithreaded",
        (bool (*)(void)) &(dash::is_multithreaded),
        "Check whether DASH supports multi-threaded access.");

  m.def("myid",
        &(dash::myid),
        "Shortcut to query the global unit ID of the calling unit.");

  m.def("nunits",
        (ssize_t (*)(void)) &(dash::size),
        "Number of units in the global team.");

  m.def("barrier",
        (void (*)(void)) &(dash::barrier),
        "A global barrier involving all units.");
	// ---------------------------------------------------------------------
  // pydash::logged_val
  //
	py::class_<pydash::logged_val> logged_val_py(m, "LV");
  logged_val_py
          .def(py::init<>())
			    .def(py::init<int, const std::string &>())
					.def(py::init<const pydash::logged_val &>())
					.def("value", &pydash::logged_val::value)
					.def("set_value", &pydash::logged_val::set_value)
					.def("name", &pydash::logged_val::name);
	// ---------------------------------------------------------------------
  // pydash::return_logged_val_by_val und
  // pydash::accept_logged_val_by_val
	//
	m.def("return_logged_val_by_val", &pydash::return_logged_val_by_val,
	       "Return logged_val by Value");
				
	m.def("accept_logged_val_by_val",
			 &pydash::accept_logged_val_by_val,
			 "Accept logged_val by Value");

  // ---------------------------------------------------------------------
  // dash::GlobRef<T>
  //
  bind_type_glob_ref<int   >(m, "Int");
  bind_type_glob_ref<float >(m, "Float");
  bind_type_glob_ref<double>(m, "Double");
  bind_type_glob_ref<pydash::logged_val>(m, "LV");

  // ---------------------------------------------------------------------
  // dash::Array<T>
  //
  bind_type_array<int   >(m, "Int");
  bind_type_array<float >(m, "Float");
  bind_type_array<double>(m, "Double");
  bind_type_array<pydash::logged_val>(m, "LV");

	return m.ptr();
}

