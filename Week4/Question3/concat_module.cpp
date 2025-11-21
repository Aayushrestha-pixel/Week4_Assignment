#include <pybind11/pybind11.h>
#include <string>

// function to concatenate two strings
std::string concatenate(std::string str1, std::string str2) {
    return str1 + str2;
}

// pybind11 module definition
PYBIND11_MODULE(concat_module, m) {
    m.def("concatenate", &concatenate, "Concatenates two strings");
}