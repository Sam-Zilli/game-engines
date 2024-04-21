// Scene.hpp
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

struct Scene{
    Scene();
    ~Scene();

    void StartUp(SDL_Renderer* renderer, float speedOfProjectile,int windowWidth, int windowHeight);
    void Shutdown();
    void Input(float deltaTime);
    void Update(float deltaTime);
    void Render(int r, int g, int b); // Modified Render function
    void SetSceneActiveStatus(bool status);
    bool IsSceneActive() const;

    private:
       // Enemy sprites
       std::vector<std::shared_ptr<EnemyGameEntity>> enemies;  
       // Main Character
       std::shared_ptr<GameEntity> mainCharacter;

       float       mPoints{0.0f};

       bool mSceneIsActive{false};
       SDL_Renderer* mRenderer;
};

