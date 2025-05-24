#define PY_SSIZE_T_CLEAN
#include <Python.h>

extern "C" {

static PyObject * foo_bar(PyObject *self, PyObject *args)
{
    const char *str;

    if (!PyArg_ParseTuple(args, "s", &str))
        return NULL;
    long sz = strlen(str);
    return PyLong_FromLong(sz);
}

static PyMethodDef foo_methods[] = 
{
    {"bar",  foo_bar, METH_VARARGS, "string length"},
    {NULL, NULL, 0, NULL}  // last entry sentinel
};

static struct PyModuleDef foo_module =
{
    PyModuleDef_HEAD_INIT,
    "foo",        // name of module
    NULL,         // module documentation, may be NULL
    -1,           // size of per-interpreter state of the module, or -1 if the module keeps state in global variables.
    foo_methods
};

PyMODINIT_FUNC PyInit_foo(void)
{
    return PyModule_Create(&foo_module);
}

} // extern "C"