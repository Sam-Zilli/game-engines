#include "GameApp.hpp"
#include "GameObject.hpp"
#include <fstream>
#include <string>

GameApp::GameApp() : graphicsProgram(400, 400, "Game Name Made in GameApp.cpp!") {
    // Constructor implementation
}


/// Setup the game objects for our system
void GameApp::StartUp(const std::string filename) { 
    std::ifstream script(filename);
    std::string line;j6tg6
    if(script.is_open()) {
        // Read each line at a time and execute
        while(std::getline(script, line)) {
            py::exec(line.c_str());
        } 
        script.close();
    }
}

void GameApp::ShutDown() {
    // Perform shutdown operations if needed
}

void GameApp::CreateGameObject(const std::string name, const std::string scriptfilename) {
    GameObject go(name);
    // Load the script for the game object
    go.mScript.LoadScript(scriptfilename);
    // Assume ownership on the C++ vector collection
    gameObjects.push_back(go);
}

void GameApp::Input() {
    for(auto& go : gameObjects) {
        go.Input();
    }
}

void GameApp::Update() {
    for(auto& go : gameObjects) {
        go.Update();
    }
}

void GameApp::Render() {
    // Call graphics rendering functions from SDLGraphicsProgram
    graphicsProgram.clear(); // Clear screen
    // Render game objects using SDLGraphicsProgram's methods
    // Example: graphicsProgram.DrawRectangle(/* parameters */);
    // Other rendering operations
    graphicsProgram.flip(); // Update screen
}

void GameApp::Loop() {
    // For demonstration purposes, the game loop 
    // only runs a finite number of times.
    size_t i=0;
    while(i < 5) {
        std::cout << "===== Simulating game loop frame " << i << " =====" << std::endl;
        Input();
        Update();
        Render();
        i++;
    }
}


void GameApp::Clear() {

}

void GameApp::Poll() {
    
}
