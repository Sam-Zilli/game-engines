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
    Application(const std::map<std::string, std::string>& params);
    ~Application();

    void Log(const char* message);
    void StartUp(const std::string& gameName, int windowWidth, int windowHeight, float speedOfProjectile);
    void Shutdown();
    void Input(float deltaTime);
    void Update(float deltaTime);
    void Render(int r, int g, int b); // Modified Render function
    void Loop(float targetFPS, int r, int g, int b);

    private:
       /// NOTE: For now, let's just have 1 scene.
       //        Also consider, if this should be a pointer.
       //        Consider -- if this should be a vector
       //        or a linked list type container.
       Scene mScene;

       SDL_Window* mWindow;
       SDL_Renderer* mRenderer;
};
