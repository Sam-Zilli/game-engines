// Application.hpp
#pragma once

#include <SDL3/SDL.h>
#include <cstdlib>
#include <vector>
#include <memory>

#include "GameEntity.hpp"
#include "PlayerGameEntity.hpp"
#include "EnemyGameEntity.hpp"
#include "Projectile.hpp"

struct Application{
    Application(int argc, char* argv[]);
    ~Application();

    void StartUp();
    void Shutdown();
    void Input(float deltaTime);
    void Update(float deltaTime);
    void Render();
    void Loop(float targetFPS);

    private:
       // Enemy sprites
       std::vector<std::unique_ptr<EnemyGameEntity>> enemies;  
       // Main Character
       std::unique_ptr<PlayerGameEntity> mainCharacter;

       bool        mRun{true};
       float       mPoints{0.0f};
       SDL_Window* mWindow;
       SDL_Renderer* mRenderer;
};
