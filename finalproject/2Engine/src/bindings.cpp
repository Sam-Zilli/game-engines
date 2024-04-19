// --------------------- PYBIND ------------------- //
// Include the pybindings
#include <pybind11/pybind11.h>
#include "SDLGraphicsProgram.hpp"

namespace py = pybind11;

// Creates a macro function that will be called
// whenever the module is imported into python
// 'mygameengine' is what we 'import' into python.
// 'm' is the interface (creates a py::module object)
//      for which the bindings are created.
//  The magic here is in 'template metaprogramming'
PYBIND11_MODULE(mygameengine, m){
    m.doc() = "our game engine as a library"; // Optional docstring

    py::class_<SDLGraphicsProgram>(m, "SDLGraphicsProgram")
            .def(py::init<int, int, const char*>(), py::arg("width"), py::arg("height"), py::arg("game_name"))   // our constructor
            .def("clear", &SDLGraphicsProgram::clear) // Expose member methods
            .def("delay", &SDLGraphicsProgram::delay) 
            .def("flip", &SDLGraphicsProgram::flip) 
            // .def("loop", &SDLGraphicsProgram::loop) 
            .def("DrawRectangle", &SDLGraphicsProgram::DrawRectangle)
            .def("poll", &SDLGraphicsProgram::poll)
            .def("getQuit", &SDLGraphicsProgram::getQuit)
            .def("getRightPaddleUp", &SDLGraphicsProgram::getRightPaddleUp)
            .def("getRightPaddleDown", &SDLGraphicsProgram::getRightPaddleDown)
            .def("getLeftPaddleUp", &SDLGraphicsProgram::getLeftPaddleUp)
            .def("getLeftPaddleDown", &SDLGraphicsProgram::getLeftPaddleDown)
            .def("setBackgroundColor", &SDLGraphicsProgram::setBackgroundColor);
}