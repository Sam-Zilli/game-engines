/**
 * @file Collision2DComponent.hpp
 * @brief This file contains the definition of the Collision2DComponent struct.
 */

#pragma once

#include <SDL3/SDL.h>
#include <memory>
#include <string>

#include "Component.hpp"

/**
 * @struct Collision2DComponent
 * @brief A struct that represents a 2D collision component.
 * @details This struct inherits from the Component struct and overrides its methods.
 */
struct Collision2DComponent : public Component{
    /**
     * @brief Constructor for the Collision2DComponent struct.
     */
    Collision2DComponent();

    /**
     * @brief Destructor for the Collision2DComponent struct.
     */
    ~Collision2DComponent();

    /**
     * @brief Gets the type of the Component.
     * @return The type of the Component.
     */
    ComponentType GetType() override;

    /**
     * @brief Handles input for the Collision2DComponent.
     * @param deltaTime The time since the last frame.
     */
    void Input(float deltaTime) override;

    /**
     * @brief Updates the Collision2DComponent.
     * @param deltaTime The time since the last frame.
     */
    void Update(float deltaTime) override;

    /**
     * @brief Renders the Collision2DComponent.
     * @param renderer The SDL_Renderer to use.
     */
    void Render(SDL_Renderer* renderer) override;

    /**
     * @brief Sets the width of the Collision2DComponent.
     * @param w The width to set.
     */
    void SetW(float w);

    /**
     * @brief Sets the height of the Collision2DComponent.
     * @param h The height to set.
     */
    void SetH(float h);

    /**
     * @brief Sets the width and height of the Collision2DComponent.
     * @param w The width to set.
     * @param h The height to set.
     */
    void SetWH(float w, float h);

    /**
     * @brief Gets the width of the Collision2DComponent.
     * @return The width of the Collision2DComponent.
     */
    float GetW() const;

    /**
     * @brief Gets the height of the Collision2DComponent.
     * @return The height of the Collision2DComponent.
     */
    float GetH() const;

    /**
     * @brief Sets the x-coordinate of the Collision2DComponent.
     * @param x The x-coordinate to set.
     */
    void SetX(float x);

    /**
     * @brief Sets the y-coordinate of the Collision2DComponent.
     * @param y The y-coordinate to set.
     */
    void SetY(float y);

    /**
     * @brief Sets the x and y coordinates of the Collision2DComponent.
     * @param x The x-coordinate to set.
     * @param y The y-coordinate to set.
     */
    void SetXY(float x, float y);

    /**
     * @brief Gets the x-coordinate of the Collision2DComponent.
     * @return The x-coordinate of the Collision2DComponent.
     */
    float GetX() const;

    /**
     * @brief Gets the y-coordinate of the Collision2DComponent.
     * @return The y-coordinate of the Collision2DComponent.
     */
    float GetY() const;

    /**
     * @brief Gets the rectangle representing the Collision2DComponent.
     * @return The rectangle representing the Collision2DComponent.
     */
    SDL_FRect GetRectangle() const;

    private:
        /**
         * @brief The rectangle representing the Collision2DComponent.
         */
        SDL_FRect mRectangle{20.0f,20.0f,32.0f,32.0f};
};