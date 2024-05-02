//
// Created by Jakob on 02.05.24.
//

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
// #include <pybind11/numpy.h>
// #include <pybind11/operators.h>

#include "eis_lib/eis.h"

namespace py = pybind11;

PYBIND11_MODULE(eis_library, eis_handle) {
    eis_handle.doc() = "Class to simulate bit flips";

    py::class_<eis>(eis_handle, "eis")

            // constructor
            //-------------------------------
            .def(py::init<unsigned long, unsigned long>())
            //-------------------------------

            // properties
            //-------------------------------
            .def_property("sign", &eis::getSign, &eis::setSign)
            .def_property("exponent", &eis::getExponent, &eis::setExponent)
            .def_property("mantissa", &eis::getMantissa, &eis::setMantissa)

            .def_property("value", &eis::getValue, &eis::setValue)

            .def_property_readonly("bit_array", &eis::getBitArray)
            .def_property_readonly("to_string", &eis::toString)

            .def_property_readonly("exponent_length", &eis::getExponentLength)
            .def_property_readonly("mantissa_length", &eis::getMantissa)

            .def_property_readonly("is_NaN", &eis::isNaN)
            .def_property_readonly("is_inf", &eis::isInf)
            .def_property_readonly("is_zero", &eis::isZero)
            .def_property_readonly("is_positive", &eis::isPositive)
            //-------------------------------

            // setting special values
            //-------------------------------
            .def("set_NaN", &eis::setNaN)
            .def("set_inf", &eis::setInf)
            .def("set_zero", &eis::setZero)
            //-------------------------------

            // flippers
            //-------------------------------
            .def("flip_sing", &eis::flipSign)
            .def("flip_exponent", &eis::flipExponent)
            .def("flip_mantissa", &eis::flipMantissa)
            //-------------------------------

            ;
}