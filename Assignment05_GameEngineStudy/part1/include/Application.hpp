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
#include "ComponentType.hpp"
#include "Component.hpp"
#include "Scene.hpp"

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
       Scene mScene;

       bool        mRun{true};
       SDL_Window* mWindow;
       SDL_Renderer* mRenderer;
};
