/**
 * @file Scene.hpp
 * @brief This file contains the definition of the Scene struct.
 */

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

/**
 * @struct Scene
 * @brief A struct that represents a scene in the game.
 * @details This struct contains methods for starting up, shutting down, input handling, updating, and rendering the scene.
 */
struct Scene{
    /**
     * @brief Default constructor for the Scene struct.
     */
    Scene();

    /**
     * @brief Destructor for the Scene struct.
     */
    ~Scene();

    /**
     * @brief Starts up the scene.
     * @param renderer The SDL_Renderer to use.
     * @param speedOfProjectile The speed of the projectile.
     * @param windowWidth The width of the window.
     * @param windowHeight The height of the window.
     */
    void StartUp(SDL_Renderer* renderer, float speedOfProjectile,int windowWidth, int windowHeight);

    /**
     * @brief Shuts down the scene.
     */
    void Shutdown();

    /**
     * @brief Handles input for the scene.
     * @param deltaTime The time since the last frame.
     */
    void Input(float deltaTime);

    /**
     * @brief Updates the scene.
     * @param deltaTime The time since the last frame.
     */
    void Update(float deltaTime);

    /**
     * @brief Renders the scene.
     * @param r The red component of the color.
     * @param g The green component of the color.
     * @param b The blue component of the color.
     */
    void Render(int r, int g, int b);

    /**
     * @brief Sets the active status of the scene.
     * @param status The new active status.
     */
    void SetSceneActiveStatus(bool status);

    /**
     * @brief Checks if the scene is active.
     * @return True if the scene is active, false otherwise.
     */
    bool IsSceneActive() const;

    private:
        /**
         * @brief The enemy sprites in the scene.
         */
       std::vector<std::shared_ptr<EnemyGameEntity>> enemies;

        /**
         * @brief The main character in the scene.
         */
       std::shared_ptr<GameEntity> mainCharacter;

        /**
         * @brief The points in the scene.
         */
       float mPoints{0.0f};

        /**
         * @brief The active status of the scene.
         */
       bool mSceneIsActive{false};

        /**
         * @brief The SDL_Renderer of the scene.
         */
       SDL_Renderer* mRenderer;
};