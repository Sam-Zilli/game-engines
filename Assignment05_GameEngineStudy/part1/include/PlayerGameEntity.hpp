#pragma once

#include <SDL3/SDL.h>
#include <memory>

#include "GameEntity.hpp"
#include "Projectile.hpp"
#include "TextureComponent.hpp"

struct PlayerGameEntity : public GameEntity{

    PlayerGameEntity(SDL_Renderer* renderer);

    virtual ~PlayerGameEntity();

    virtual void Input(float deltaTime) override;

    virtual void Update(float deltaTime) override;

    virtual void Render(SDL_Renderer* renderer) override;

    virtual std::shared_ptr<Projectile> GetProjectile() const;

    private:
        std::shared_ptr<Projectile> mProjectile;
};
