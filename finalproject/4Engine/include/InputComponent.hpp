/**
 * @file InputComponent.hpp
 * @brief This file contains the definition of the InputComponent struct.
 */

#pragma once

#include <SDL3/SDL.h>
#include <memory>
#include <string>

#include "Component.hpp"

/**
 * @struct InputComponent
 * @brief A struct that represents an input component in the game.
 * @details This struct inherits from the Component struct and overrides its methods.
 */
struct InputComponent : public Component{
    /**
     * @brief Default constructor for the InputComponent struct.
     */
    InputComponent();

    /**
     * @brief Destructor for the InputComponent struct.
     */
    ~InputComponent();

    /**
     * @brief Gets the type of the Component.
     * @return The type of the Component.
     */
    ComponentType GetType() override;

    /**
     * @brief Handles input for the InputComponent.
     * @param deltaTime The time since the last frame.
     */
    void Input(float deltaTime) override;

    /**
     * @brief Updates the InputComponent.
     * @param deltaTime The time since the last frame.
     */
    void Update(float deltaTime) override;

    /**
     * @brief Renders the InputComponent.
     * @param renderer The SDL_Renderer to use.
     */
    void Render(SDL_Renderer* renderer) override;

    private:
        /**
         * @brief The speed of the InputComponent.
         */
        float mSpeed{150.0f};

        /**
         * @brief The width of the window.
         */
        int windowWidth = 600;

        /**
         * @brief The height of the window.
         */
        int windowHeight = 1000;

        /**
         * @brief The size of the object.
         */
        int objectSize = 32;
};