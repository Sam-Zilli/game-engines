/**
 * @file bindings.cpp
 * @brief Python bindings for the Application class of our game engine.
 * 
 * This file contains the implementation of Python bindings for the Application class
 * of our game engine. It uses the pybind11 library to expose the Application class
 * and its member functions to Python.
 */

#include <pybind11/pybind11.h>
#include <pybind11/stl.h> // Add this line to include the stl.h header
#include "Application.hpp"

namespace py = pybind11;

/**
 * @brief Creates Python bindings for the Application class.
 * 
 * This function is responsible for creating Python bindings for the Application class
 * using the pybind11 library. It defines the module name as "mygameengine" and exposes
 * the Application class and its member functions to Python.
 * 
 * @param m The pybind11 module object.
 */
PYBIND11_MODULE(mygameengine, m) {
    // Bindings for the Application class go here

    m.doc() = "Our game engine as a library"; 

    py::class_<Application>(m, "Application")
        .def(py::init<const std::map<std::string, std::string>&>()) // Constructor with dictionary
        .def("Loop", &Application::Loop, py::arg("duration"), py::arg("r"), py::arg("g"), py::arg("b"))
        .def("Log", &Application::Log, py::arg("message"))
        ;       
}