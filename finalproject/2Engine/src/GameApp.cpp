#include "GameApp.hpp"
#include "GameObject.hpp"
#include <fstream>
#include <string>

GameApp::GameApp(int width, int height, const std::string& gameName)
    : graphicsProgram(width, height, gameName.c_str()) {
    // Constructor implementation
}

GameApp::~GameApp() {
    // Destructor implementation
}


// void GameApp::ShutDown() {
//     // Perform shutdown operations if needed
// }

// void GameApp::CreateGameObject(const std::string name, const std::string scriptfilename) {
//     GameObject go(name);
//     // Load the script for the game object
//     go.mScript.LoadScript(scriptfilename);
//     // Assume ownership on the C++ vector collection
//     gameObjects.push_back(go);
// }

// void GameApp::Input() {
//     for(auto& go : gameObjects) {
//         go.Input();
//     }
// }

// void GameApp::Update() {
//     for(auto& go : gameObjects) {
//         go.Update();
//     }
// }

// void GameApp::Render() {
//     // Call graphics rendering functions from SDLGraphicsProgram
//     graphicsProgram.clear(); // Clear screen
//     // Render game objects using SDLGraphicsProgram's methods
//     // Example: graphicsProgram.DrawRectangle(/* parameters */);
//     // Other rendering operations
//     // graphicsProgram.flip(); // Update screen
// }

// void GameApp::Loop() {
//     // For demonstration purposes, the game loop 
//     // only runs a finite number of times.
//     size_t i=0;
//     while(i < 5) {
//         std::cout << "===== Simulating game loop frame " << i << " =====" << std::endl;
//         Input();
//         Update();
//         Render();
//         i++;
//     }
// }


void GameApp::Clear() {
    graphicsProgram.clear();
}


void GameApp::Poll() {
    graphicsProgram.poll(); // Call the poll function on the graphics program
}


void GameApp::Delay(int milliseconds) {
    graphicsProgram.delay(milliseconds);
}

void GameApp::SetBackgroundColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    graphicsProgram.setBackgroundColor(r,g,b,a);
}


void GameApp::Flip() {
    graphicsProgram.flip();
}

bool GameApp::GetQuit() {
    quit = graphicsProgram.getQuit();
    return quit;
}

void GameApp::DrawRectangle(int x, int y, int w, int h) {
    graphicsProgram.DrawRectangle(x, y, w, h);
}

bool GameApp::getRightArrowDown() {
    return rightArrowDown;
}

bool GameApp::getRightArrowUp() {
    return rightArrowUp;
}

bool GameApp::getLeftArrowDown() {
    return leftArrowDown;
}

bool GameApp::getLeftArrowUp() {
    return leftArrowUp;
}