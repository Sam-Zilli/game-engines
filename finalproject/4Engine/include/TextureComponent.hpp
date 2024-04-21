/**
 * @file TextureComponent.hpp
 * @brief This file contains the definition of the TextureComponent struct.
 */

#pragma once
#include <SDL3/SDL.h>
#include <memory>
#include <string>

#include "Component.hpp"

/**
 * @struct TextureComponent
 * @brief A struct that represents a texture component.
 * @details This struct inherits from the Component struct and overrides its methods.
 */
struct TextureComponent : public Component{
    /**
     * @brief Default constructor for the TextureComponent struct.
     */
    TextureComponent();

    /**
     * @brief Creates a texture component.
     * @param renderer The SDL_Renderer to use.
     * @param filepath The path to the texture file.
     */
    void CreateTextureComponent(SDL_Renderer* renderer, std::string filepath);

    /**
     * @brief Destructor for the TextureComponent struct.
     */
    ~TextureComponent();

    /**
     * @brief Gets the type of the component.
     * @return The type of the component.
     */
    ComponentType GetType() override;

    /**
     * @brief Handles input for the TextureComponent.
     * @param deltaTime The time since the last frame.
     */
    void Input(float deltaTime) override;

    /**
     * @brief Updates the TextureComponent.
     * @param deltaTime The time since the last frame.
     */
    void Update(float deltaTime) override;

    /**
     * @brief Renders the TextureComponent.
     * @param renderer The SDL_Renderer to use.
     */
    void Render(SDL_Renderer* renderer) override;

    private:
        /**
         * @brief The texture of the TextureComponent.
         */
        std::shared_ptr<SDL_Texture> mTexture;
};