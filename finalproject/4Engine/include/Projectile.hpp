/**
 * @file Projectile.hpp
 * @brief This file contains the definition of the Projectile struct.
 */

#pragma once
#include <SDL3/SDL.h>

#include "GameEntity.hpp"
#include "TextureComponent.hpp"

/**
 * @struct Projectile
 * @brief A struct that represents a projectile in the game.
 * @details This struct inherits from the GameEntity struct and overrides its methods.
 */
struct Projectile : public GameEntity{

    /**
     * @brief Default constructor for the Projectile struct.
     */
    Projectile();

    /**
     * @brief Launches the projectile.
     * @param x The x-coordinate of the launch position.
     * @param y The y-coordinate of the launch position.
     * @param yDirectionIsUp The direction of the launch.
     * @param minlaunchtime The minimum time between launches.
     */
    void Launch(float x, float y, bool yDirectionIsUp, int minlaunchtime=3000);

    /**
     * @brief Handles input for the Projectile.
     * @param deltaTime The time since the last frame.
     */
    void Input(float deltaTime) override;

    /**
     * @brief Updates the Projectile.
     * @param deltaTime The time since the last frame.
     */
    void Update(float deltaTime) override;

    /**
     * @brief Renders the Projectile.
     * @param renderer The SDL_Renderer to use.
     */
    void Render(SDL_Renderer* renderer) override;

    /**
     * @brief Sets the speed of the Projectile.
     * @param speed The new speed.
     */
    void SetSpeed(float speed) { mSpeed = speed; }

    private:
        /**
         * @brief The speed of the Projectile.
         */
        float mSpeed{100.0f};

        /**
         * @brief Whether the Projectile is firing.
         */
        bool mIsFiring{false};

        /**
         * @brief The direction of the Projectile.
         */
        bool mYDirectionUp{true};

        /**
         * @brief The time since the last launch.
         */
        Uint64 timeSinceLastLaunch;
};