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
