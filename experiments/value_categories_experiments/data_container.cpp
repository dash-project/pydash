#include <pybind11/pybind11.h>


namespace data_c {
struct data_container {

public: 

 data_container(int x): x(x)
{}
 ~data_container();
 
 int    get_data()          { return x;            }
 int &  get_data_ref()      { return &x;           }
 int && get_data_rval_ref() { return std::move(x); }
   
private:
  int x;
     

}}

namespace py = pybind11;

PYBIND11_PLUGIN(example) {
  
    py::module m("example", "pybind11 example plugin");
    
		py::class_<data_c::data_container> measurements(m, "Measurements");

    m.def("get_data", &data_container::get_data, "");
    m.def("get_data_ref", &data_container::get_data_ref, "");
    m.def("get_data_rval_ref", &data_container::get_data_rval_ref, "");

    return m.ptr();
}