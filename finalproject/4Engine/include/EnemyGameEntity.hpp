/**
 * @file EnemyGameEntity.hpp
 * @brief This file contains the definition of the EnemyGameEntity struct.
 */

#pragma once

#include <SDL3/SDL.h>
#include <memory>

#include "GameEntity.hpp"
#include "Projectile.hpp"
#include "TextureComponent.hpp"

/**
 * @struct EnemyGameEntity
 * @brief A struct that represents an enemy game entity.
 * @details This struct inherits from the GameEntity struct and overrides its methods.
 */
struct EnemyGameEntity : public GameEntity {

    /**
     * @brief Constructor for the EnemyGameEntity struct.
     * @param renderer The SDL_Renderer to use.
     */
    EnemyGameEntity(SDL_Renderer* renderer);

    /**
     * @brief Destructor for the EnemyGameEntity struct.
     */
    virtual ~EnemyGameEntity();

    /**
     * @brief Handles input for the EnemyGameEntity.
     * @param deltaTime The time since the last frame.
     */
    virtual void Input(float deltaTime) override;

    /**
     * @brief Updates the EnemyGameEntity.
     * @param deltaTime The time since the last frame.
     */
    virtual void Update(float deltaTime) override;

    /**
     * @brief Renders the EnemyGameEntity.
     * @param renderer The SDL_Renderer to use.
     */
    virtual void Render(SDL_Renderer* renderer) override;

    private:
        /**
         * @brief Whether the EnemyGameEntity is moving in the positive x direction.
         */
        bool xPositiveDirection{true};

        /**
         * @brief The offset of the EnemyGameEntity.
         */
        float offset{0.0f};

        /**
         * @brief The minimum time between launches.
         */
        float mMinLaunchTime{2000.0f};
};