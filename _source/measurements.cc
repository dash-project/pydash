<%
setup_pybind11(cfg)
%>
#include <pybind11/pybind11.h>
#include <pybind11/operators.h>
#include <pybind11/stl.h>

#include <vector>
#include <cmath>

#include <algorithm>
#include <numeric>

namespace cpppc {

template <typename T>
class Measurements
{

  typedef Measurements<T>                                   self_t;
  typedef T                                                value_t;

  typedef       T &                                      reference;
  typedef const T &                                const_reference;
  typedef typename std::vector<T>::iterator               iterator;
  typedef typename std::vector<T>::const_iterator   const_iterator;

public:

  iterator begin() { return _values.begin(); }
	
  // const_iterator begin() const { return _values.begin(); }

  iterator   end() { return _values.end(); }

  // const_iterator end() const { return _values.end();}

  reference front()       { return _values[0];                }
  reference back()        { return _values[_values.size()-1]; }
  bool      empty() const { return _values.empty();           }
	size_t    size()  const { return _values.size();            }
	
  reference operator[](size_t x) { return _values[x];         }

  // const_reference operator[](size_t x) const { return _values[x];}

  void clear() { return _values.clear();}

	// void insert(const_reference ref) { _values.push_back(ref); };

  void insert(iterator begin, iterator end) { std::copy(begin, end, std::back_inserter(_values)); }

  bool operator==(const self_t rhs) const {
		
    if (size()!= rhs.size()){
      return false;
    }
    for (int i = 0; i < size(); i++)
		  if (_values[i] != rhs._values[i]) {
        return false;
      }
    return true;
  }

  T median() const {
    if (empty()) {
      return 0;
    }
    std::vector<T> v= _values;
    std::sort(v.begin(), v.end());
    return v[v.size()/2];
  }

  // Funktionen gemaess Wikipedia implementiert
  double mean() const {
    if(empty()) {
      return 0;
    }
    auto   divident = std::accumulate(_values.begin(), _values.end(), 0);
    double divisor  = (double) _values.size();
    return divident / divisor;
  }

  double variance() const {
    auto divident = std::accumulate(
                      _values.begin(),
                      _values.end(),
                      0.0,
                      [=](double E, double x)
                      {
                        return E + (x - mean()) * (x - mean());
                      });
    return divident / ((double) (size()));
  }

  double sigma() const { return (std::sqrt(variance())); }

private:
  std::vector<T> _values;

};


} // namespace cpppc

namespace py = pybind11;

PYBIND11_PLUGIN(measurements) {
    py::module m("measurements", "measurements custom container binding");
		
		py::class_<cpppc::Measurements<int>> measurements(m, "Measurements");
		
		measurements.def(py::init<>());
		measurements.def("begin",    &cpppc::Measurements<int>::begin   );
		measurements.def("end",      &cpppc::Measurements<int>::end     );
		measurements.def("front",    &cpppc::Measurements<int>::front   );
		measurements.def("back",     &cpppc::Measurements<int>::back    );
		measurements.def("empty",    &cpppc::Measurements<int>::empty   );
		measurements.def("clear",    &cpppc::Measurements<int>::clear   );
		measurements.def("insert",   &cpppc::Measurements<int>::insert  );
		measurements.def("median",   &cpppc::Measurements<int>::median  );
		measurements.def("mean",     &cpppc::Measurements<int>::mean    );
		measurements.def("variance", &cpppc::Measurements<int>::variance);
		measurements.def("sigma",    &cpppc::Measurements<int>::sigma   );
			
		measurements.def("__iter__", [](cpppc::Measurements<int> &v) {
			return py::make_iterator(v.begin(), v.end());
		}, py::keep_alive<0, 1>());
		
		return m.ptr();
		
}
