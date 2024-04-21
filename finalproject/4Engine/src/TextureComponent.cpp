/**
 * @file TextureComponent.cpp
 * @brief This file contains the implementation of the TextureComponent class.
 */

#include "TextureComponent.hpp"
#include "ResourceManager.hpp"
#include "TransformComponent.hpp"
#include "GameEntity.hpp"

/**
 * @brief Default constructor for the TextureComponent class.
 */
TextureComponent::TextureComponent(){

}


/**
 * @brief Creates a texture component.
 * @param renderer The SDL_Renderer to use.
 * @param filepath The path to the texture file.
 */
void TextureComponent::CreateTextureComponent(SDL_Renderer* renderer, std::string filepath){
    mTexture = ResourceManager::Instance().LoadTexture(renderer,filepath);
}

/**
 * @brief Destructor for the TextureComponent class.
 */
TextureComponent::~TextureComponent(){
}


/**
 * @brief Gets the type of the component.
 * @return The type of the component.
 */
ComponentType TextureComponent::GetType(){
    return ComponentType::TextureComponent;
}


/**
 * @brief Handles input for the TextureComponent.
 * @param deltaTime The time since the last frame.
 */
void TextureComponent::Input(float deltaTime){
}

/**
 * @brief Updates the TextureComponent.
 * @param deltaTime The time since the last frame.
 */
void TextureComponent::Update(float deltaTime){
}

/**
 * @brief Renders the TextureComponent.
 * @param renderer The SDL_Renderer to use.
 */
void TextureComponent::Render(SDL_Renderer* renderer){
    if(nullptr==mTexture){
        auto ge = GetGameEntity();
        auto transform  = ge->GetTransform()->GetRectangle();
        SDL_RenderRect(renderer, &transform);
    }else{
        auto ge = GetGameEntity();
        auto transform  = ge->GetTransform()->GetRectangle();

        SDL_RenderTexture(renderer,mTexture.get(),nullptr,&transform);
    }
}


