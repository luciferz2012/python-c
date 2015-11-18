#include <Python.h>

int great_function(int a) {
    return a + 1;
}

static PyObject* _great_function(PyObject *self, PyObject *args) {
    int _a;
    int res;
    if (!PyArg_ParseTuple(args, "i", &_a))
    { return NULL; }
    res = great_function(_a);
    return PyLong_FromLong(res);
}

static PyMethodDef GreateModuleMethods[] = {
    {
        "great_function",
        _great_function,
        METH_VARARGS,
        ""
    },
    { NULL, NULL, 0, NULL }
};

static struct PyModuleDef great_module = {
    PyModuleDef_HEAD_INIT,
    "great_module",
    NULL,
    -1,
    GreateModuleMethods
};

PyMODINIT_FUNC PyInit_great_module(void) {
    return PyModule_Create(&great_module);
}