#include <pybind11/pybind11.h>
#include "GameApp.hpp" // Include GameApp header

namespace py = pybind11;

// Create bindings for the GameApp class
PYBIND11_MODULE(mygameengine, m) {
    m.doc() = "Our game engine as a library"; // Optional docstring

    py::class_<GameApp>(m, "GameApp")
        .def(py::init<int, int, const char*>(), py::arg("width"), py::arg("height"), py::arg("game_name"))   // our constructor
        // .def("ShutDown", &GameApp::ShutDown)
        // .def("CreateGameObject", &GameApp::CreateGameObject)
        // .def("Input", &GameApp::Input)
        // .def("Update", &GameApp::Update)
        // .def("Render", &GameApp::Render)
        // .def("Loop", &GameApp::Loop)
        .def("Poll", &GameApp::Poll) 
        .def("Clear", &GameApp::Clear)
        .def("Flip", &GameApp::Flip)
        .def("SetBackgroundColor", &GameApp::SetBackgroundColor, py::arg("r"), py::arg("g"), py::arg("b"), py::arg("a"))
        .def("GetQuit", &GameApp::GetQuit)
        .def("Delay", &GameApp::Delay, py::arg("milliseconds"))
        .def("DrawRectangle", &GameApp::DrawRectangle, py::arg("x"), py::arg("y"), py::arg("w"), py::arg("h"))
        .def("getRightArrowUp", &GameApp::getRightArrowUp)
        .def("getRightArrowDown", &GameApp::getRightArrowDown)
        .def("getLeftArrowUp", &GameApp::getLeftArrowUp)
        .def("getLeftArrowDown", &GameApp::getLeftArrowDown)
        ;
}
