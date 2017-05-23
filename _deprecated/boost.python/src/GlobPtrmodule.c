#include <Python.h>

static PyObject *
GlobPtr_init(PyObject *self, PyObject *args)
{
  const char *command;
  int sts;
  
  if (!PyArg_ParseTuple(args, "s", &command))
    return NULL;
  // sts =
  return PyLong_FromLong(sts);
}


static PyMethodDef GlobPtrMethods[] = {
  {"init", GlobPtr_init, METH_VARARGS, "Create a Global Pointer"},
  {NULL, NULL, 0, NULL}
};

static struct PyModuleDef GlobPtrmodule = {
  PyModuleDef_HEAD_INIT,
  "GlobPtr", /* name of module */
  GlobPtr_doc, /* module documentation, may be NULL */
  -1, /* size of per-interpreter state of the module,
       *  or -1 if the module keeps state in global variables. */
  GlobPtrMethods
};

PyMODINIT_FUNC
PyInit_GlobPtr(void)
{
    return PyModule_Create(&GlobPtrmodule);
}

    
