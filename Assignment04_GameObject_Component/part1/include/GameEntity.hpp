#pragma once

#include <SDL3/SDL.h>
#include <memory>

#include "SpriteComponent.hpp"

struct GameEntity{

    GameEntity(SpriteComponent sprite);

    virtual ~GameEntity();

    virtual void Input(float deltaTime);

    virtual void Update(float deltaTime);

    virtual void Render(SDL_Renderer* renderer);

    void AddComponent(std::shared_ptr<Component> c);

    void SetRenderable(bool value);

    bool IsRenderable() const;

    bool Intersects(std::shared_ptr<GameEntity> e);

    protected:
        std::vector<std::shared_ptr<Component>> mComponents;
        bool mRenderable{true};
};




