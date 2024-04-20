#pragma once

#include <SDL3/SDL.h>
#include <memory>

#include "GameEntity.hpp"
#include "Projectile.hpp"
#include "TextureComponent.hpp"

struct EnemyGameEntity : public GameEntity{

    EnemyGameEntity(SDL_Renderer* renderer);

    virtual ~EnemyGameEntity();

    virtual void Input(float deltaTime) override;

    virtual void Update(float deltaTime) override;

    virtual void Render(SDL_Renderer* renderer) override;

    private:
		bool xPositiveDirection{true};
        float offset{0.0f};
        float mSpeed{100.0f};
        float mMinLaunchTime{5000.0f};
};
