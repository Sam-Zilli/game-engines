/**
 * @file Collision2DComponent.hpp
 * @brief Contains the definition of the Collision2DComponent class.
 */
#include "Collision2DComponent.hpp"
#include "GameEntity.hpp"

/**
 * @brief Default constructor for Collision2DComponent.
 */
Collision2DComponent::Collision2DComponent(){
}

/**
 * @brief Destructor for Collision2DComponent.
 */
Collision2DComponent::~Collision2DComponent(){
}

/**
 * @brief Handles input for the Collision2DComponent.
 * @param deltaTime Time since the last frame.
 */
void Collision2DComponent::Input(float deltaTime){
}

/**
 * @brief Updates the Collision2DComponent.
 * @param deltaTime Time since the last frame.
 */
void Collision2DComponent::Update(float deltaTime){
    auto transform = GetGameEntity()->GetTransform();
    SetWH(transform->GetW(),transform->GetH());
    SetXY(transform->GetX(),transform->GetY());
}

/**
 * @brief Renders the Collision2DComponent.
 * @param renderer The SDL_Renderer to use for rendering.
 */
void Collision2DComponent::Render(SDL_Renderer* renderer){
    SDL_RenderRect(renderer, &mRectangle);
}

/**
 * @brief Gets the type of the component.
 * @return The type of the component.
 */
ComponentType Collision2DComponent::GetType(){
    return ComponentType::Collision2DComponent;
}

/**
 * @brief Sets the width of the Collision2DComponent.
 * @param w The new width.
 */
void Collision2DComponent::SetW(float w){
    mRectangle.w = w;
}

/**
 * @brief Sets the height of the Collision2DComponent.
 * @param h The new height.
 */
void Collision2DComponent::SetH(float h){
    mRectangle.h = h;
}

/**
 * @brief Sets the width and height of the Collision2DComponent.
 * @param w The new width.
 * @param h The new height.
 */
void Collision2DComponent::SetWH(float w, float h){
    mRectangle.w = w;
    mRectangle.h = h;
}

/**
 * @brief Gets the width of the Collision2DComponent.
 * @return The width of the Collision2DComponent.
 */
float Collision2DComponent::GetW() const{
    return mRectangle.w;
}

/**
 * @brief Gets the height of the Collision2DComponent.
 * @return The height of the Collision2DComponent.
 */
float Collision2DComponent::GetH() const{
    return mRectangle.h;
}

/**
 * @brief Sets the x position of the Collision2DComponent.
 * @param x The new x position.
 */
void Collision2DComponent::SetX(float x){
    mRectangle.x = x;
}

/**
 * @brief Sets the y position of the Collision2DComponent.
 * @param y The new y position.
 */
void Collision2DComponent::SetY(float y){
    mRectangle.y = y;
}


/**
 * @brief Sets the x and y position of the Collision2DComponent.
 * @param x The new x position.
 * @param y The new y position.
 */
void Collision2DComponent::SetXY(float x, float y){
    mRectangle.x = x;
    mRectangle.y = y;
}


/**
 * @brief Gets the x position of the Collision2DComponent.
 * @return The x position of the Collision2DComponent.
 */
float Collision2DComponent::GetX() const{
    return mRectangle.x;
}


/**
 * @brief Gets the y position of the Collision2DComponent.
 * @return The y position of the Collision2DComponent.
 */
float Collision2DComponent::GetY() const{
    return mRectangle.y;
}


/**
 * @brief Gets the rectangle representing the Collision2DComponent.
 * @return The rectangle representing the Collision2DComponent.
 */
SDL_FRect Collision2DComponent::GetRectangle() const{
    return mRectangle;
}
