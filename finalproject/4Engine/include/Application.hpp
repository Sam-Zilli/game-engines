/**
 * @file Application.hpp
 * @brief This file contains the definition of the Application struct.
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
#include "Scene.hpp"

/**
 * @struct Application
 * @brief A struct that represents the application.
 * @details This struct contains methods for logging, startup, shutdown, input, update, render, and loop.
 */
struct Application{
    /**
     * @brief Constructor for the Application struct.
     * @param params The parameters for the Application.
     */
    Application(const std::map<std::string, std::string>& params);

    /**
     * @brief Destructor for the Application struct.
     */
    ~Application();

    /**
     * @brief Logs a message.
     * @param message The message to log.
     */
    void Log(const char* message);

    /**
     * @brief Starts up the Application.
     * @param gameName The name of the game.
     * @param windowWidth The width of the window.
     * @param windowHeight The height of the window.
     * @param speedOfProjectile The speed of the projectile.
     */
    void StartUp(const std::string& gameName, int windowWidth, int windowHeight, float speedOfProjectile);

    /**
     * @brief Shuts down the Application.
     */
    void Shutdown();

    /**
     * @brief Handles input for the Application.
     * @param deltaTime The time since the last frame.
     */
    void Input(float deltaTime);

    /**
     * @brief Updates the Application.
     * @param deltaTime The time since the last frame.
     */
    void Update(float deltaTime);

    /**
     * @brief Renders the Application.
     * @param r The red component of the color.
     * @param g The green component of the color.
     * @param b The blue component of the color.
     */
    void Render(int r, int g, int b); // Modified Render function

    /**
     * @brief Runs the main loop of the Application.
     * @param targetFPS The target frames per second.
     * @param r The red component of the color.
     * @param g The green component of the color.
     * @param b The blue component of the color.
     */
    void Loop(float targetFPS, int r, int g, int b);

    private:
       /**
        * @brief The scene of the Application.
        * @details For now, let's just have 1 scene. Also consider, if this should be a pointer.
        *          Consider -- if this should be a vector or a linked list type container.
        */
       Scene mScene;

       /**
        * @brief The window of the Application.
        */
       SDL_Window* mWindow;

       /**
        * @brief The renderer of the Application.
        */
       SDL_Renderer* mRenderer;
};