/**
 * @file EnemyGameEntity.hpp
 * @brief Contains the definition of the EnemyGameEntity class.
 */

#include "EnemyGameEntity.hpp"

/**
 * @brief Constructor for EnemyGameEntity.
 * @param renderer The SDL_Renderer to use for rendering.
 */
EnemyGameEntity::EnemyGameEntity(SDL_Renderer* renderer) {
    // First launch has shorter delay
    static bool isFirstLaunch = true;
    if (isFirstLaunch) {
        mMinLaunchTime = 1000.0f;
        isFirstLaunch = false;
    } else {
        mMinLaunchTime = 2000.0f;
        mMinLaunchTime += std::rand() % 5000;
    }
}

/**
 * @brief Destructor for EnemyGameEntity.
 */
EnemyGameEntity::~EnemyGameEntity(){
}

/**
 * @brief Handles input for the EnemyGameEntity.
 * @param deltaTime Time since the last frame.
 */
void EnemyGameEntity::Input(float deltaTime) {
    for(auto& [key,value] : mComponents){
        mComponents[key]->Input(deltaTime);
    }

    for(auto& children: mGameEntities){
        children->Input(deltaTime);
    }
}

/**
 * @brief Updates the EnemyGameEntity.
 * @param deltaTime Time since the last frame.
 */
void EnemyGameEntity::Update(float deltaTime) {
    std::shared_ptr<Projectile> mProjectile = dynamic_pointer_cast<Projectile>(GetChildGameEntityAtIndex(0));

    auto transform = GetComponent<TransformComponent>(ComponentType::TransformComponent);
    if (transform) {
        transform->SetX(0);
    }

    if(offset>80){
        // xPositiveDirection=false;
    }
    if(offset<-80){
        // xPositiveDirection=true;
    }

    if(xPositiveDirection){
        // transform->SetX(transform->GetX() + mSpeed*deltaTime);
        // offset += mSpeed * deltaTime;
    }else{
        // transform->SetX(transform->GetX() - mSpeed*deltaTime);
        // offset -= mSpeed * deltaTime;
    }

    if(mRenderable){
        mProjectile->Launch(transform->GetX(),transform->GetY(),false,mMinLaunchTime);
    }

    for(auto& [key,value] : mComponents){
        mComponents[key]->Update(deltaTime);
    }

    for(auto& children: mGameEntities){
        children->Update(deltaTime);
    }
}

/**
 * @brief Renders the EnemyGameEntity.
 * @param renderer The SDL_Renderer to use for rendering.
 */
void EnemyGameEntity::Render(SDL_Renderer* renderer) {
    std::shared_ptr<Projectile> mProjectile = dynamic_pointer_cast<Projectile>(GetChildGameEntityAtIndex(0));

    if(mRenderable){
        mProjectile->Render(renderer);
    }else{
        mProjectile->SetRenderable(false);
        return;
    }

    for(auto& [key,value] : mComponents){
        mComponents[key]->Render(renderer);
    }
    for(auto& children: mGameEntities){
        children->Render(renderer);
    }
}