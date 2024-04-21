/**
 * @file TransformComponent.hpp
 * @brief This file contains the definition of the TransformComponent struct.
 */

#pragma once
#include <SDL3/SDL.h>
#include <memory>
#include <string>

#include "Component.hpp"

/**
 * @struct TransformComponent
 * @brief A struct that represents a transform component.
 * @details This struct inherits from the Component struct and overrides its methods.
 */
struct TransformComponent : public Component{
    /**
     * @brief Default constructor for the TransformComponent struct.
     */
    TransformComponent();

    /**
     * @brief Destructor for the TransformComponent struct.
     */
    ~TransformComponent();

    /**
     * @brief Gets the type of the component.
     * @return The type of the component.
     */
    ComponentType GetType() override;

    /**
     * @brief Handles input for the TransformComponent.
     * @param deltaTime The time since the last frame.
     */
    void Input(float deltaTime) override;

    /**
     * @brief Updates the TransformComponent.
     * @param deltaTime The time since the last frame.
     */
    void Update(float deltaTime) override;

    /**
     * @brief Renders the TransformComponent.
     * @param renderer The SDL_Renderer to use.
     */
    void Render(SDL_Renderer* renderer) override;

    /**
     * @brief Sets the width of the TransformComponent.
     * @param w The new width.
     */
    void SetW(float w);

    /**
     * @brief Sets the height of the TransformComponent.
     * @param h The new height.
     */
    void SetH(float h);

    /**
     * @brief Sets the width and height of the TransformComponent.
     * @param w The new width.
     * @param h The new height.
     */
    void SetWH(float w, float h);

    /**
     * @brief Gets the width of the TransformComponent.
     * @return The width of the TransformComponent.
     */
    float GetW() const;

    /**
     * @brief Gets the height of the TransformComponent.
     * @return The height of the TransformComponent.
     */
    float GetH() const;

    /**
     * @brief Sets the x-coordinate of the TransformComponent.
     * @param x The new x-coordinate.
     */
    void SetX(float x);

    /**
     * @brief Sets the y-coordinate of the TransformComponent.
     * @param y The new y-coordinate.
     */
    void SetY(float y);

    /**
     * @brief Sets the x and y coordinates of the TransformComponent.
     * @param x The new x-coordinate.
     * @param y The new y-coordinate.
     */
    void SetXY(float x, float y);

    /**
     * @brief Gets the x-coordinate of the TransformComponent.
     * @return The x-coordinate of the TransformComponent.
     */
    float GetX() const;

    /**
     * @brief Gets the y-coordinate of the TransformComponent.
     * @return The y-coordinate of the TransformComponent.
     */
    float GetY() const;

    /**
     * @brief Gets the rectangle of the TransformComponent.
     * @return The rectangle of the TransformComponent.
     */
    SDL_FRect GetRectangle() const;

    private:
        /**
         * @brief The rectangle of the TransformComponent.
         */
        SDL_FRect mRectangle{20.0f,20.0f,32.0f,32.0f};
};