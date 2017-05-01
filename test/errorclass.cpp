<%
setup_pybind11(cfg)
%>
	
#include <pybind11/pybind11.h>

#include <iostream>
#include <string>

namespace ec {
class error_class{
public:
	error_class(int i){
		this.i = i;
	}
	int i;
		
	void g() {
	  /*wait 30sec*/
	  std::cout << i << std::endl;
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
		
		py::class_<ec::error_class> error_class(m, "error_class");
		
		error_class.def(py::init<>());
		error_class.def("f", &ec::error_class::f);

		return m.ptr();
		
}
