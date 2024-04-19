#include <pybind11/pybind11.h>
#include "GameApp.hpp" // Include GameApp header

namespace py = pybind11;

// Create bindings for the GameApp class
PYBIND11_MODULE(mygameengine, m) {
    m.doc() = "Our game engine as a library"; // Optional docstring

    py::class_<GameApp>(m, "GameApp")
        .def(py::init<>()) // Constructor
        .def("StartUp", &GameApp::StartUp) // Expose member methods
        .def("ShutDown", &GameApp::ShutDown)
        .def("CreateGameObject", &GameApp::CreateGameObject)
        .def("Input", &GameApp::Input)
        .def("Update", &GameApp::Update)
        .def("Render", &GameApp::Render)
        .def("Loop", &GameApp::Loop);
        .def("Poll", &GameApp::Poll) 
        .def("Clear", &GameApp::Clear);
}


// PYBIND11_MODULE(mygameengine, m){
//     m.doc() = "our game engine as a library"; // Optional docstring

//     py::class_<SDLGraphicsProgram>(m, "SDLGraphicsProgram")
//             .def(py::init<int, int, const char*>(), py::arg("width"), py::arg("height"), py::arg("game_name"))   // our constructor
//             .def("clear", &SDLGraphicsProgram::clear) // Expose member methods
//             .def("delay", &SDLGraphicsProgram::delay) 
//             .def("flip", &SDLGraphicsProgram::flip) 
//             // .def("loop", &SDLGraphicsProgram::loop) 
//             .def("DrawRectangle", &SDLGraphicsProgram::DrawRectangle)
//             .def("poll", &SDLGraphicsProgram::poll)
//             .def("getQuit", &SDLGraphicsProgram::getQuit)
//             .def("getRightPaddleUp", &SDLGraphicsProgram::getRightPaddleUp)
//             .def("getRightPaddleDown", &SDLGraphicsProgram::getRightPaddleDown)
//             .def("getLeftPaddleUp", &SDLGraphicsProgram::getLeftPaddleUp)
//             .def("getLeftPaddleDown", &SDLGraphicsProgram::getLeftPaddleDown)
//             .def("setBackgroundColor", &SDLGraphicsProgram::setBackgroundColor);
// }
 
// #endif