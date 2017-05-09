#include <pybind11/pybind11.h>

#include <string>
#include "macro.h"
#include "array_wrapper.h"
#include "array_maker.h"

namespace py = pybind11;


PYBIND11_PLUGIN(ArrayWrapper) {
    py::module m("ArrayWrapper", "Wrapper for Arrays");
		
		py::class_<ArrayWrapper<int>> arrayW(m, "ArrayWrapper");
		
		arrayW.def(py::init<>());
		arrayW.def(py::init<int, std::string>());
		//arrayW.def(py::init<ArrayWrapper<int>&&>());
		arrayW.def(py::init<const ArrayWrapper<int>&>());
		
		arrayW.def("size", &ArrayWrapper<int>::size);
	
			
		arrayW.def("__iter__", [](ArrayWrapper<int> &v)
		{
			return py::make_iterator(v.begin(), v.end());
		}, py::keep_alive<0, 1>());
		
		m.def("return_array_by_value", &return_array_by_value, py::return_value_policy::copy);
		m.def("accept_array_by_value", &accept_array_by_value, py::return_value_policy::copy);
		
		return m.ptr();
		
}