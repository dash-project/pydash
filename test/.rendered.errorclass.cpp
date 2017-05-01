
	
#include <pybind11/pybind11.h>

#include <iostream>
#include <string>

namespace cpppc {
class error_class{
public:
		
	void g() {
	  /*wait 30sec*/
	  std::cout << "Will this be printed?" << std::endl;
	}
	
	std::string f(){
	  g();
	  return "KABOOM";
  }
};
}

namespace py = pybind11;

PYBIND11_PLUGIN(error_class) {
    py::module m("error_class", "error_class");
		
		py::class_<cpppc::error_class> error_class(m, "error_class");
		
		error_class.def(py::init<>());
		error_class.def("f", &cpppc::error_class::f);

		return m.ptr();
		
}
