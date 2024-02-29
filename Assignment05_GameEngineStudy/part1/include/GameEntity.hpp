#pragma once

#include <SDL3/SDL.h>
#include <memory>
#include <map>

#include "Component.hpp"
#include "TextureComponent.hpp"
#include "InputComponent.hpp"
#include "TransformComponent.hpp"
#include "Collision2DComponent.hpp"

struct GameEntity : public std::enable_shared_from_this<GameEntity>{

    GameEntity();

    virtual ~GameEntity();

    std::shared_ptr<GameEntity> GetThisPtr()
    {
        return shared_from_this();
    }

    virtual void Input(float deltaTime);

    virtual void Update(float deltaTime);

    virtual void Render(SDL_Renderer* renderer);

    template <typename T>
    void AddComponent(std::shared_ptr<T> c);

    template <typename T>
    std::shared_ptr<T> GetComponent(ComponentType type);
        
    void AddDefaultTransform();
    /// NOTE: Could make const
    /// This is a special case of 'GetComponent' because
    //  every GameEntity will have a 'TransformComponent'
    std::shared_ptr<TransformComponent> GetTransform();

    void SetRenderable(bool value);

    bool IsRenderable() const;

    bool Intersects(std::shared_ptr<GameEntity> e);
    // TODO: Remove 'Intersects'

    // TODO: 
    //  - Try to get rid of 'Projectile'
    //    - The challenge will be -- how do we get, new behaviors in our system 

    protected:
        // Could use unordered_map or multi_map, etc. if needed
        // For now, assume one component per GameEntity
        std::map< ComponentType, std::shared_ptr<Component>> mComponents;
        bool mRenderable{true};
};




