#ifndef GAMEAPP_HPP
#define GAMEAPP_HPP

#include <iostream>
#include <vector>
#include <string>
#include "SDLGraphicsProgram.hpp" // Include SDLGraphicsProgram header
#include "GameApp.hpp" // Include GameObject header
#include "GameObject.hpp"


/// Game app
class GameApp {
public:
    /// Default constructor
    GameApp();

    /// Setup the game objects for our system
    void StartUp(const std::string& gameName, const std::string& gameCreatorName);

    void ShutDown();

    // For demonstration purposes, assume ownership on the C++ vector collection
    void CreateGameObject(const std::string name, const std::string scriptfilename);

    void Input();

    void Update();

    void Render();

    void Loop();

    void Poll();

    void Clear();

    void Delay();

private:
    /// Data
    // Note: Ideally this is populated as a 'scene' and
    //       loaded from some configuration file.
    std::vector<GameObject> gameObjects;

    // SDLGraphicsProgram instance for graphics handling
    SDLGraphicsProgram graphicsProgram;
};

#endif // GAMEAPP_HPP
