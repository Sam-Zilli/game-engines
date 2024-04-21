// Scene.hpp
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

struct Scene{
    Scene();
    ~Scene();

    void StartUp(SDL_Renderer* renderer);
    void Shutdown();
    void Input(float deltaTime);
    void Update(float deltaTime);
    void Render();
    void SetSceneActiveStatus(bool status);
    bool IsSceneActive() const;

    private:
       // Enemy sprites
       std::vector<std::shared_ptr<EnemyGameEntity>> enemies;  
       // Main Character
       std::shared_ptr<PlayerGameEntity> mainCharacter;
       float       mPoints{0.0f};

       bool mSceneIsActive{false};
       SDL_Renderer* mRenderer;
};
