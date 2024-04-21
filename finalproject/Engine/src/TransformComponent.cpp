/**
 * @file TransformComponent.cpp
 * @brief This file contains the implementation of the TransformComponent class.
 */

#include "TransformComponent.hpp"

/**
 * @brief Default constructor for the TransformComponent class.
 */
TransformComponent::TransformComponent(){
}

/**
 * @brief Destructor for the TransformComponent class.
 */
TransformComponent::~TransformComponent(){
}

/**
 * @brief Handles input for the TransformComponent.
 * @param deltaTime The time since the last frame.
 */
void TransformComponent::Input(float deltaTime){
}

/**
 * @brief Updates the TransformComponent.
 * @param deltaTime The time since the last frame.
 */
void TransformComponent::Update(float deltaTime){
}

/**
 * @brief Renders the TransformComponent.
 * @param renderer The SDL_Renderer to use.
 */
void TransformComponent::Render(SDL_Renderer* renderer){
}

/**
 * @brief Gets the type of the component.
 * @return The type of the component.
 */
ComponentType TransformComponent::GetType(){
    return ComponentType::TransformComponent;
}

/**
 * @brief Sets the width of the TransformComponent.
 * @param w The new width.
 */
void TransformComponent::SetW(float w){
    mRectangle.w = w;
}

/**
 * @brief Sets the height of the TransformComponent.
 * @param h The new height.
 */
void TransformComponent::SetH(float h){
    mRectangle.h = h;
}

/**
 * @brief Sets the width and height of the TransformComponent.
 * @param w The new width.
 * @param h The new height.
 */
void TransformComponent::SetWH(float w, float h){
    mRectangle.w = w;
    mRectangle.h = h;
}

/**
 * @brief Gets the width of the TransformComponent.
 * @return The width of the TransformComponent.
 */
float TransformComponent::GetW() const{
    return mRectangle.w;
}

/**
 * @brief Gets the height of the TransformComponent.
 * @return The height of the TransformComponent.
 */
float TransformComponent::GetH() const{
    return mRectangle.h;
}

/**
 * @brief Sets the x-coordinate of the TransformComponent.
 * @param x The new x-coordinate.
 */
void TransformComponent::SetX(float x){
    mRectangle.x = x;
}

/**
 * @brief Sets the y-coordinate of the TransformComponent.
 * @param y The new y-coordinate.
 */
void TransformComponent::SetY(float y){
    mRectangle.y = y;
}

/**
 * @brief Sets the x and y coordinates of the TransformComponent.
 * @param x The new x-coordinate.
 * @param y The new y-coordinate.
 */
void TransformComponent::SetXY(float x, float y){
    mRectangle.x = x;
    mRectangle.y = y;
}

/**
 * @brief Gets the x-coordinate of the TransformComponent.
 * @return The x-coordinate of the TransformComponent.
 */
float TransformComponent::GetX() const{
    return mRectangle.x;
}

/**
 * @brief Gets the y-coordinate of the TransformComponent.
 * @return The y-coordinate of the TransformComponent.
 */
float TransformComponent::GetY() const{
    return mRectangle.y;
}

/**
 * @brief Gets the rectangle of the TransformComponent.
 * @return The rectangle of the TransformComponent.
 */
SDL_FRect TransformComponent::GetRectangle() const{
    return mRectangle;
}