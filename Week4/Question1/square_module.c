#include <Python.h>

// function to calculate square
static PyObject* square(PyObject* self, PyObject* args) {
    double num;
    
    // get number from python
    if (!PyArg_ParseTuple(args, "d", &num)) {
        return NULL;
    }
    
    // calculate and return result
    double result = num * num;
    return PyFloat_FromDouble(result);
}

// list of functions in module
static PyMethodDef SquareMethods[] = {
    {"square", square, METH_VARARGS, "Returns square of a number"},
    {NULL, NULL, 0, NULL}
};

// module definition
static struct PyModuleDef squaremodule = {
    PyModuleDef_HEAD_INIT,
    "square_module",
    "Module for squaring numbers",
    -1,
    SquareMethods
};

// init function
PyMODINIT_FUNC PyInit_square_module(void) {
    return PyModule_Create(&squaremodule);
}