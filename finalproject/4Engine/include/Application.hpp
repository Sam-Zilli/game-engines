// Application.hpp
#pragma once

#include <SDL3/SDL.h>
#include <cstdlib>
#include <vector>
#include <memory>

#include "GameEntity.hpp"
#include "EnemyGameEntity.hpp"
#include "Projectile.hpp"
#include "ComponentType.hpp"
#include "Component.hpp"
#include "Scene.hpp"

struct Application{
    Application(const std::string& gameName, int windowWidth, int windowHeight);
    ~Application();

    void Log(const char* message);
    void StartUp(const std::string& gameName, int windowWidth, int windowHeight);
    void Shutdown();
    void Input(float deltaTime);
    void Update(float deltaTime);
    void Render();
    void Loop(float targetFPS);

    private:
       /// NOTE: For now, let's just have 1 scene.
       //        Also consider, if this should be a pointer.
       //        Consider -- if this should be a vector
       //        or a linked list type container.
       Scene mScene;

       SDL_Window* mWindow;
       SDL_Renderer* mRenderer;
};
