#include "InputComponent.hpp"
#include "GameEntity.hpp"
#include "Projectile.hpp"

InputComponent::InputComponent(){
}

InputComponent::~InputComponent(){

}

ComponentType InputComponent::GetType() {
    return ComponentType::InputComponent;
}


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

    // // Check if the new position is outside the window
    // if (newX < 0) newX = 0;
    // if (newY < 0) newY = 0;
    // if (newX > 600 - 32) newX = 600 - 32;
    // if (newY > 480 - 32) newY = 480 - 32;

    // Check if the new position is outside the window
    if (newX < 0) newX = 0;
    if (newY < 0) newY = 0;
    if (newX > windowWidth - objectSize) newX = windowWidth - objectSize;
    if (newY > windowHeight - objectSize) newY = windowHeight - objectSize;

    // Set the new position
    transform->SetX(newX);
    transform->SetY(newY);

    // Removing hero launching projectile capacbilities for now
    // if(state[SDL_SCANCODE_Z]){
    // // if(state[SDL_SCANCODE_UP]){
    //     SDL_Log("Launching!");
    //     std::shared_ptr<Projectile> projectile = dynamic_pointer_cast<Projectile>(ge->GetChildGameEntityAtIndex(0));
    //     projectile->Launch(transform->GetX(),transform->GetY(),true);
    // }
}


// void InputComponent::Input(float deltaTime) {
//     const Uint8* state = SDL_GetKeyboardState(nullptr);
//     // For now -- keep a reference to our first sprite
// 	auto ge  = GetGameEntity();
//     auto transform = ge->GetComponent<TransformComponent>(ComponentType::TransformComponent);

//     if(state[SDL_SCANCODE_LEFT]){
//         transform->SetX(transform->GetX() - mSpeed*deltaTime);
// 		// SDL_Log("Did something");
//     }else if(state[SDL_SCANCODE_RIGHT]){
//         transform->SetX(transform->GetX() + mSpeed*deltaTime);
//     }else if(state[SDL_SCANCODE_UP]){
//         transform->SetY(transform->GetY() - mSpeed*deltaTime);
//     } else if(state[SDL_SCANCODE_DOWN]){
//         transform->SetY(transform->GetY() + mSpeed*deltaTime);
//     } 

//     // Removing hero launching projectile capacbilities for now
//     // if(state[SDL_SCANCODE_Z]){
//     // // if(state[SDL_SCANCODE_UP]){
//     //     SDL_Log("Launching!");
//     //     std::shared_ptr<Projectile> projectile = dynamic_pointer_cast<Projectile>(ge->GetChildGameEntityAtIndex(0));
//     //     projectile->Launch(transform->GetX(),transform->GetY(),true);
//     // }

// }

void InputComponent::Update(float deltaTime) {

}

void InputComponent::Render(SDL_Renderer* renderer) {

}
