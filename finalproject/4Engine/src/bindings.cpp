#include <pybind11/pybind11.h>
#include "Application.hpp"

namespace py = pybind11;

// Create bindings for the Application class
PYBIND11_MODULE(mygameengine, m) {
    m.doc() = "Our game engine as a library"; 

    py::class_<Application>(m, "Application")
        .def(py::init<const std::string&, int, int>()) // Constructor with arguments
        .def("Loop", &Application::Loop, py::arg("duration"))
        .def("Log", &Application::Log, py::arg("message"))
        
        ;       
}