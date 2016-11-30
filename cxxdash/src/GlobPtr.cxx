#include <cxxdash/GlobPtr.hxx>
#include <cxxdash/Defines.hxx>

#include <libdash.h>
#include <CXX/Objects.hxx>


void GlobPtrCxx::init_type()
{
  behaviors().name("GlobPtrCxx");
  behaviors().doc("GlobPtrCxx( ini_count )");
  // you must have overwritten the virtual functions
  // Py::Object iter() and Py::Object iternext()
  behaviors().supportIter(); // set entries in the Type Table
  behaviors().supportRepr();
  add_varargs_method("reversed", &GlobPtrCxx::reversed, "reversed()");
}

class GlobPtrModule : public Py::ExtensionModule<GlobPtrModule> {
public:
  GlobPtrModule() : Py::ExtensionModule<GlobPtrModule>("GlobPtrCxx")
  {
    GlobPtrCxx::init_type();
    add_varargs_method("GlobPtrCxx", &GlobPtrModule::new_GlobPtrCxx,
                       "GlobPtrCxx(from,last)");
    initialize("GlobPtrModule documentation"); // register with Python
  }

  virtual ~GlobPtrModule() {}

private:

  Py::Object new_GlobPtrCxx(const Py::Tuple & args)
  {
    if (args.length() != 2) {
      throw Py::RuntimeError("Incorrect # of args to GlobPtrCxx(from,to).");
    }
    return Py::asObject(
             new GlobPtrCxx(Py::Long(args[0]).as_long(),
                            Py::Long(args[1]).as_long()));
  }
};

extern "C" EXPORT_SYMBOL PyObject * PyInit_GlobPtrCxx()
{
  // the following constructor call registers our extension module
  // with the Python runtime system
  static GlobPtrModule * glob_ptr_module = new GlobPtrModule;

  return glob_ptr_module->module().ptr();
}
