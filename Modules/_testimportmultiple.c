/*
 * C extensions module to test importing multiple modules from one compiled
 * file (issue16421). This file defines 3 modules (_testimportmodule,
 * foo, bar), only the first one is called the same as the compiled file.
 */
#include<Python.h>

static struct PyModuleDef _testimportmultiple = {
    PyModuleDef_HEAD_INIT,
    "_testimportmultiple",
    "_testimportmultiple doc",
    0,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC PyInit__testimportmultiple(void)
{
    return PyModuleDef_Init(&_testimportmultiple);
}

static struct PyModuleDef _foomodule = {
    PyModuleDef_HEAD_INIT,
    "_testimportmultiple_foo",
    "_testimportmultiple_foo doc",
    0,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC PyInit__testimportmultiple_foo(void)
{
    return PyModuleDef_Init(&_foomodule);
}

static struct PyModuleDef _barmodule = {
    PyModuleDef_HEAD_INIT,
    "_testimportmultiple_bar",
    "_testimportmultiple_bar doc",
    0,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

PyMODINIT_FUNC PyInit__testimportmultiple_bar(void){
    return PyModuleDef_Init(&_barmodule);
}

