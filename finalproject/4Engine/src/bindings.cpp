#include <pybind11/pybind11.h>
#include <pybind11/stl.h> // Add this line to include the stl.h header
#include "Application.hpp"

namespace py = pybind11;

// Create bindings for the Application class
PYBIND11_MODULE(mygameengine, m) {
    m.doc() = "Our game engine as a library"; 

    py::class_<Application>(m, "Application")
        .def(py::init<const std::map<std::string, std::string>&>()) // Constructor with dictionary
        .def("Loop", &Application::Loop, py::arg("duration"), py::arg("r"), py::arg("g"), py::arg("b"))
        .def("Log", &Application::Log, py::arg("message"))
        ;       
}