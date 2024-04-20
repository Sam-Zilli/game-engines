#include <pybind11/pybind11.h>
#include "Application.hpp"

namespace py = pybind11;

// Create bindings for the Application class
PYBIND11_MODULE(mygameengine, m) {
    m.doc() = "Our game engine as a library"; // Optional docstring

    py::class_<Application>(m, "Application")
        .def(py::init<>()) // Default constructor
        .def("Loop", &Application::Loop, py::arg("duration"));          // Loop method
}