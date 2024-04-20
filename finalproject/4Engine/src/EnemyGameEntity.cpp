#include "EnemyGameEntity.hpp"

EnemyGameEntity::EnemyGameEntity(SDL_Renderer* renderer) : isVisible(false) {
    // Set a random launch time for the enemies
    mMinLaunchTime += std::rand() % 10000;
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

    if(offset>80){
        xPositiveDirection=false;
    }
    if(offset<-80){
        xPositiveDirection=true;
    }

    // Keeping track of our projectile game logic
    auto transform = GetComponent<TransformComponent>(ComponentType::TransformComponent);

    if(xPositiveDirection){
        transform->SetX(transform->GetX() + mSpeed*deltaTime);
        offset += mSpeed * deltaTime;
    }else{
        transform->SetX(transform->GetX() - mSpeed*deltaTime);
        offset -= mSpeed * deltaTime;
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
    // AFTER MOVING ENEMIES SWITCH THIS BACK TO VISIBLE!
    if (this->!IsVisible()) {
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

}
