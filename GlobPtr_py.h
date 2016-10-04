/*
 * GlobPtr_py.h wraps GlobPtr.h as to expose the class
 * GlobPtr to Python.
 *
 * In this implementation, we use boost/python to support
 * us.
 */

#include "../dash-feat-stlalgos/dash/include/dash/GlobPtr.h"

#include <boost/python/class.hpp>
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <boost/python/operators.hpp>

BOOST_PYTHON_MODULE(GlobPtr) {

  using namespace boost::python;
  class_<GlobPtr>("GlobPtr")
    .def(init<ElementType, PatternType>())
    .def(str(self)) //__str__ in Python for << exposition


:w

