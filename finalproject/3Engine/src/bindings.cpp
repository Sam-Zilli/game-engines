#include <pybind11/pybind11.h>
#include "Application.hpp"

namespace py = pybind11;


// for debugging purposes! - ALSO UNCOMMENT ALL THE PYBIND
// #include <iostream>

// int main() {
//     std::cout << "Before app creation" << std::endl;
    
//     // Create an instance of Application
//     Application app;
    
//     std::cout << "Before running loop" << std::endl;
    
//     // Call the Loop method
//     app.Loop(120.0f);
    
//     std::cout << "End of game_builder_gui.cpp" << std::endl;
    
//     return 0;
// }
// End of debugging code



// Create bindings for the Application class
PYBIND11_MODULE(mygameengine, m) {
    m.doc() = "Our game engine as a library"; // Optional docstring

    py::class_<Application>(m, "Application")
        .def(py::init<>()) // Default constructor
        .def("Loop", &Application::Loop, py::arg("duration"));          // Loop method
}