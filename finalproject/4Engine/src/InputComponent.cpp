#include "InputComponent.hpp"
#include "GameEntity.hpp"
#include "Projectile.hpp"

/**
 * @brief Default constructor for InputComponent
 */
InputComponent::InputComponent(){
}

/**
 * @brief Destructor for InputComponent
 */
InputComponent::~InputComponent(){

}

/**
 * @brief Get the ComponentType of this InputComponent
 * @return ComponentType::InputComponent
 */
ComponentType InputComponent::GetType() {
    return ComponentType::InputComponent;
}

/**
 * @brief Handle input for this InputComponent
 * @param deltaTime The time since the last frame
 */
void InputComponent::Input(float deltaTime) {
    const Uint8* state = SDL_GetKeyboardState(nullptr);
    auto ge  = GetGameEntity();
    auto transform = ge->GetComponent<TransformComponent>(ComponentType::TransformComponent);

    float newX = transform->GetX();
    float newY = transform->GetY();

    if(state[SDL_SCANCODE_LEFT]){
        newX -= mSpeed*deltaTime;
    }else if(state[SDL_SCANCODE_RIGHT]){
        newX += mSpeed*deltaTime;
    }else if(state[SDL_SCANCODE_UP]){
        newY -= mSpeed*deltaTime;
    } else if(state[SDL_SCANCODE_DOWN]){
        newY += mSpeed*deltaTime;
    } 

    // Check if the new position is outside the window
    if (newX < 0) newX = 0;
    if (newY < 0) newY = 0;
    if (newX > windowWidth - objectSize) newX = windowWidth - objectSize;
    if (newY > windowHeight - objectSize) newY = windowHeight - objectSize;

    // Set the new position
    transform->SetX(newX);
    transform->SetY(newY);
}

/**
 * @brief Update this InputComponent
 * @param deltaTime The time since the last frame
 */
void InputComponent::Update(float deltaTime) {

}

/**
 * @brief Render this InputComponent
 * @param renderer The SDL_Renderer to use for rendering
 */
void InputComponent::Render(SDL_Renderer* renderer) {

}