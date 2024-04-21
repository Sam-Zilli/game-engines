#include "Projectile.hpp"

/**
 * @brief Default constructor for Projectile
 */
Projectile::Projectile(){
    timeSinceLastLaunch = SDL_GetTicks();
    mRenderable=false;
}

/**
 * @brief Launch the projectile
 * @param x The x-coordinate of the launch position
 * @param y The y-coordinate of the launch position
 * @param yDirectionIsUp The direction of the projectile
 * @param minlaunchtime The minimum time between launches
 */
void Projectile::Launch(float x, float y, bool yDirectionIsUp, int minlaunchtime){
    if(SDL_GetTicks() - timeSinceLastLaunch > minlaunchtime){
        SDL_Log("Lainching projectile INSIDE");
        auto transform = GetComponent<TransformComponent>(ComponentType::TransformComponent);
        auto col       = GetComponent<Collision2DComponent>(ComponentType::Collision2DComponent);
        transform->SetXY(x,y);
        col->SetXY(x,y);

        timeSinceLastLaunch = SDL_GetTicks();
        mIsFiring=true;        
        mYDirectionUp = yDirectionIsUp;
    }
}

/**
 * @brief Handle input for this Projectile
 * @param deltaTime The time since the last frame
 */
void Projectile::Input(float deltaTime) {
    for(auto& [key,value] : mComponents){
        mComponents[key]->Input(deltaTime);
    }
}

/**
 * @brief Update this Projectile
 * @param deltaTime The time since the last frame
 */
void Projectile::Update(float deltaTime) {
    auto transform = GetComponent<TransformComponent>(ComponentType::TransformComponent);

    if(mIsFiring){
        mRenderable = true;
        // Change the X position instead of the Y position
        transform->SetX(transform->GetX() + mSpeed * deltaTime);
    }else{
        mRenderable=false;
    }

    // Check if the projectile is out of the screen in the X direction instead of the Y direction
    if(transform->GetX() < 0.0f || transform->GetX() > 640.0f){ // Assuming screen width is 640
        mIsFiring=false;
    }

    for(auto& [key,value] : mComponents){
        mComponents[key]->Update(deltaTime);
    }
}

/**
 * @brief Render this Projectile
 * @param renderer The SDL_Renderer to use for rendering
 */
void Projectile::Render(SDL_Renderer* renderer) {
    if(mRenderable){
        for(auto& [key,value] : mComponents){
            mComponents[key]->Render(renderer);
        }
    }else{
        // Do nothing;
    }
}