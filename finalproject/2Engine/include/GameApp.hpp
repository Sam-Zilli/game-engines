#ifndef GAMEAPP_HPP
#define GAMEAPP_HPP

#include <iostream>
#include <vector>
#include <string>
#include "SDLGraphicsProgram.hpp" // Include SDLGraphicsProgram header

// Forward declaration of GameObject class


/// Game app
class GameApp {
public:
    GameApp(int width, int height, const std::string& gameName);
    ~GameApp();
    // void ShutDown();
    // void CreateGameObject(const std::string name, const std::string scriptfilename);
    // void Input();
    // void Update();
    void Render();
    void Loop();
    void Poll();
    void Clear();
    void Delay(int milliseconds);
    void SetBackgroundColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    bool getQuit();
    void Flip();

private:
    // std::vector<GameObject> gameObjects;
    SDLGraphicsProgram graphicsProgram;
    bool isInitialized;
    bool quit;
};

#endif // GAMEAPP_HPP
