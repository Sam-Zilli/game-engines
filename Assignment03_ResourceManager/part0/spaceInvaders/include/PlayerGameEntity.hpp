#pragma once

#include <SDL3/SDL.h>
#include <memory>

#include "GameEntity.hpp"
#include "Projectile.hpp"

struct PlayerGameEntity : public GameEntity{

    PlayerGameEntity(SDL_Renderer* renderer, Sprite sprite);

    virtual ~PlayerGameEntity();

    virtual void Input(float deltaTime) override;

    virtual void Update(float deltaTime) override;

    virtual void Render(SDL_Renderer* renderer) override;

    virtual std::shared_ptr<Projectile> GetProjectile() const;

    private:
        float mSpeed{150.0f};
        std::shared_ptr<Projectile> mProjectile;
};
