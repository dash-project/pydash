#include "array_wrapper.h"
#include "array_maker.h"


ArrayWrapper<int>
return_array_by_value(
  int         size,
  std::string name)
{
  if (size % 2 == 0) {
    return ArrayWrapper<int>(size / 2, name);
  } else {
    return ArrayWrapper<int>(size * 2, name);
  }
}

int
accept_array_by_value(
  ArrayWrapper<int> a)
{
  ArrayWrapper<int> mine(std::move(a));

  mine.begin()[0] = 345;

  return mine.begin()[0];
}


amespace py = pybind11;

PYBIND11_PLUGIN(ArrayWrapper) {
    py::module m("ArrayWrapper", "Wrapper for Arrays");
		
		py::class_<ArrayWrapper<int>> arrayW(m, "ArrayWrapper");
		
		arrayW.def(py::init<>());
		arrayW.def("return_array_by_value", &ArrayWrapper<int>::return_array_by_value);
		arrayW.def("return_array_by_value", &ArrayWrapper<int>::return_array_by_value);
	
			
		arrayW.def("__iter__", [](ArrayWrapper<int> &v)
		{
			return py::make_iterator(v.begin(), v.end());
		}, py::keep_alive<0, 1>());
		
		return m.ptr();
		
}