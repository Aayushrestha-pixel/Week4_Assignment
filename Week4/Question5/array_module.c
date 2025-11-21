#include <Python.h>
#include <stdlib.h>

// struct to hold array data
typedef struct {
    int* data;
    int size;
} IntArray;

// global array pointer
static IntArray* arr = NULL;

// init function
static PyObject* init_array(PyObject* self, PyObject* args) {
    int size;
    int i;
    
    // get size from python
    if (!PyArg_ParseTuple(args, "i", &size)) {
        return NULL;
    }
    
    // allocate memory
    arr = (IntArray*)malloc(sizeof(IntArray));
    arr->data = (int*)malloc(size * sizeof(int));
    arr->size = size;
    
    // initialize to zero
    for (i = 0; i < size; i++) {
        arr->data[i] = 0;
    }
    
    Py_RETURN_NONE;
}

// set value at index
static PyObject* set_value(PyObject* self, PyObject* args) {
    int index, value;
    
    // get index and value
    if (!PyArg_ParseTuple(args, "ii", &index, &value)) {
        return NULL;
    }
    
    // check if array exists
    if (arr == NULL) {
        PyErr_SetString(PyExc_RuntimeError, "Array not initialized");
        return NULL;
    }
    
    // check bounds
    if (index < 0 || index >= arr->size) {
        PyErr_SetString(PyExc_IndexError, "Index out of range");
        return NULL;
    }
    
    // set value
    arr->data[index] = value;
    Py_RETURN_NONE;
}

// get value at index
static PyObject* get_value(PyObject* self, PyObject* args) {
    int index;
    
    // get index
    if (!PyArg_ParseTuple(args, "i", &index)) {
        return NULL;
    }
    
    // check if array exists
    if (arr == NULL) {
        PyErr_SetString(PyExc_RuntimeError, "Array not initialized");
        return NULL;
    }
    
    // check bounds
    if (index < 0 || index >= arr->size) {
        PyErr_SetString(PyExc_IndexError, "Index out of range");
        return NULL;
    }
    
    // return value
    return PyLong_FromLong(arr->data[index]);
}

// free array memory
static PyObject* free_array(PyObject* self, PyObject* args) {
    if (arr != NULL) {
        free(arr->data);
        free(arr);
        arr = NULL;
    }
    Py_RETURN_NONE;
}

// method definitions
static PyMethodDef ArrayMethods[] = {
    {"init_array", init_array, METH_VARARGS, "Initialize array"},
    {"set_value", set_value, METH_VARARGS, "Set value at index"},
    {"get_value", get_value, METH_VARARGS, "Get value at index"},
    {"free_array", free_array, METH_VARARGS, "Free array memory"},
    {NULL, NULL, 0, NULL}
};

// module definition
static struct PyModuleDef arraymodule = {
    PyModuleDef_HEAD_INIT,
    "array_module",
    "Integer array management",
    -1,
    ArrayMethods
};

// init function
PyMODINIT_FUNC PyInit_array_module(void) {
    return PyModule_Create(&arraymodule);
}