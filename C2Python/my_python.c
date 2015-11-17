//my_python.c
#include <Python.h>

int main(int argc, char *argv[]) {
    Py_SetProgramName(argv[0]);
    Py_Initialize(); // xxx how to set python version?
    PyRun_SimpleString("print('Hello Python!')\n");
    Py_Finalize();
    system("pause");
    return 0;
}