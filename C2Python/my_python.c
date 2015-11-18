#include <Python.h>

int great_function_from_python(int a) {
    int res;
    PyObject *pModule, *pFunc;
    PyObject *pArgs, *pValue;
    /* import */
    pModule = PyImport_Import(PyUnicode_FromString("great_module"));
    /* great_module.great_function */
    pFunc = PyObject_GetAttrString(pModule, "great_function");
    /* build args */
    pArgs = PyTuple_New(1);
    PyTuple_SetItem(pArgs, 0, PyLong_FromLong(a));
    /* call */
    pValue = PyObject_CallObject(pFunc, pArgs);
    res = PyLong_AsLong(pValue);
    return res;
}

int main(int argc, char *argv[]) {
    // Py_SetProgramName(argv[0]);
    // Py_SetPythonHome( ... );
    // Py_SetPath( ... );
    // Py_GetProgramFullPath( ... );
    Py_Initialize();
    printf("%d\n", great_function_from_python(0));
    Py_Finalize();
    system("pause");
    return 0;
}