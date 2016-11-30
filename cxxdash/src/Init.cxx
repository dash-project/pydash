
#include <cxxdash/Defines.hxx>

#include <libdash.h>
#include <CXX/Objects.hxx>


class DASHInitModule : public Py::ExtensionModule<DASHInitModule> {
public:
  DASHInitModule() : Py::ExtensionModule<DASHInitModule>("DASHInit")
  {
    DASHInit::init_type();
    add_noargs_method("DASHInit", &DASHInitModule::new_DASHInit,
                      "DASHInit()");
    initialize("DASHInitModule documentation"); // register with Python
  }

  virtual ~DASHInitModule() {}

private:

  Py::Object new_DASHInit()
  {
    return Py::asObject(new DASHInit());
  }
};


extern "C" EXPORT_SYMBOL PyObject * PyInit_DASHInit()
{
  // the following constructor call registers our extension module
  // with the Python runtime system
  static DASHInitModule * mod = new DASHInitModule;

  return mod->module().ptr();
}

