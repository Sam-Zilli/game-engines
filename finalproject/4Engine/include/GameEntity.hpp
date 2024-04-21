/**
 * @file GameEntity.hpp
 * @brief This file contains the definition of the GameEntity struct.
 */

#pragma once

#include <SDL3/SDL.h>
#include <memory>
#include <map>
#include <vector>

#include "Component.hpp"
#include "TextureComponent.hpp"
#include "InputComponent.hpp"
#include "TransformComponent.hpp"
#include "Collision2DComponent.hpp"

/**
 * @struct GameEntity
 * @brief A struct that represents a game entity.
 * @details This struct inherits from std::enable_shared_from_this to allow shared pointers to itself.
 */
struct GameEntity : public std::enable_shared_from_this<GameEntity>{

    /**
     * @brief Default constructor for the GameEntity struct.
     */
    GameEntity();

    /**
     * @brief Destructor for the GameEntity struct.
     */
    virtual ~GameEntity();

    /**
     * @brief Gets a shared pointer to this GameEntity.
     * @return A shared pointer to this GameEntity.
     */
    std::shared_ptr<GameEntity> GetThisPtr()
    {
        return shared_from_this();
    }

    /**
     * @brief Handles input for the GameEntity.
     * @param deltaTime The time since the last frame.
     */
    virtual void Input(float deltaTime);

    /**
     * @brief Updates the GameEntity.
     * @param deltaTime The time since the last frame.
     */
    virtual void Update(float deltaTime);

    /**
     * @brief Renders the GameEntity.
     * @param renderer The SDL_Renderer to use.
     */
    virtual void Render(SDL_Renderer* renderer);

    /**
     * @brief Adds a component to the GameEntity.
     * @param c The component to add.
     */
    template <typename T>
    void AddComponent(std::shared_ptr<T> c);

    /**
     * @brief Gets a component from the GameEntity.
     * @param type The type of the component to get.
     * @return The component.
     */
    template <typename T>
    std::shared_ptr<T> GetComponent(ComponentType type);
        
    /**
     * @brief Adds a default transform to the GameEntity.
     */
    void AddDefaultTransform();

    /**
     * @brief Gets the transform of the GameEntity.
     * @return The transform.
     */
    std::shared_ptr<TransformComponent> GetTransform();

    /**
     * @brief Adds a child GameEntity to this GameEntity.
     * @param child The child GameEntity to add.
     */
    void AddChildGameEntity(std::shared_ptr<GameEntity> child);

    /**
     * @brief Gets a child GameEntity at a specific index.
     * @param index The index of the child GameEntity to get.
     * @return The child GameEntity.
     */
    std::shared_ptr<GameEntity> GetChildGameEntityAtIndex(size_t index);

    /**
     * @brief Sets whether the GameEntity is renderable.
     * @param value Whether the GameEntity is renderable.
     */
    void SetRenderable(bool value);

    /**
     * @brief Checks whether the GameEntity is renderable.
     * @return Whether the GameEntity is renderable.
     */
    bool IsRenderable() const;

    /**
     * @brief Checks whether this GameEntity intersects with another GameEntity.
     * @param e The other GameEntity.
     * @return Whether this GameEntity intersects with the other GameEntity.
     */
    bool Intersects(std::shared_ptr<GameEntity> e);

    protected:
        /**
         * @brief The components of the GameEntity.
         */
        std::map< ComponentType, std::shared_ptr<Component>> mComponents;

        /**
         * @brief Whether the GameEntity is renderable.
         */
        bool mRenderable{true};

        /**
         * @brief The child GameEntities of this GameEntity.
         */
        std::vector<std::shared_ptr<GameEntity>> mGameEntities;

};