#include "EnemyGameEntity.hpp"

EnemyGameEntity::EnemyGameEntity(SDL_Renderer* renderer) {
    // Set a random launch time for the enemies
    // EDIT THIS LATER FOR LEVIL DIFFIULCLTY
    mMinLaunchTime += std::rand() % 5000;
}

EnemyGameEntity::~EnemyGameEntity(){
}

void EnemyGameEntity::Input(float deltaTime) {
    for(auto& [key,value] : mComponents){
        mComponents[key]->Input(deltaTime);
    }

    for(auto& children: mGameEntities){
        children->Input(deltaTime);
    }
}

void EnemyGameEntity::Update(float deltaTime) {
    // NOTE: 'zero' we happen to know is our projectile
    std::shared_ptr<Projectile> mProjectile = dynamic_pointer_cast<Projectile>(GetChildGameEntityAtIndex(0));

    // Get the TransformComponent and set the X position to 0
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

void EnemyGameEntity::Render(SDL_Renderer* renderer) {
    std::shared_ptr<Projectile> mProjectile = dynamic_pointer_cast<Projectile>(GetChildGameEntityAtIndex(0));

    if(mRenderable){
        mProjectile->Render(renderer);
    }else{
        // Do nothing;
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
