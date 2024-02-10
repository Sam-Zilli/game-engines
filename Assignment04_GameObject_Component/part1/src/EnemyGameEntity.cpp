#include "EnemyGameEntity.hpp"

EnemyGameEntity::EnemyGameEntity(SDL_Renderer* renderer){
    SpriteComponent sp;
    sp.CreateSpriteComponent(renderer,"./assets/rocket.bmp");
    sp.SetW(24.0f);
    mProjectile = std::make_shared<Projectile>(sp);

    // Set a random launch time for the enemies
    mMinLaunchTime += std::rand() % 10000;
}

EnemyGameEntity::~EnemyGameEntity(){
}

void EnemyGameEntity::Input(float deltaTime) {
    for(auto& c : mComponents) {
        c->Input(deltaTime);
    }
}

void EnemyGameEntity::Update(float deltaTime) {
    mProjectile->Update(deltaTime);
    if(offset>80){
        xPositiveDirection=false;
    }
    if(offset<-80){
        xPositiveDirection=true;
    }

    if(xPositiveDirection){
        mSprite.SetX(mSprite.GetX() + mSpeed*deltaTime);
        offset += mSpeed * deltaTime;
    }else{
        mSprite.SetX(mSprite.GetX() - mSpeed*deltaTime);
        offset -= mSpeed * deltaTime;
    }

    if(mRenderable){
        mProjectile->Launch(mSprite.GetX(),mSprite.GetY(),false,mMinLaunchTime);
    }
    for(auto& c: mComponents){
        c->Update(deltaTime);
    }
}

void EnemyGameEntity::Render(SDL_Renderer* renderer){
    if(mRenderable){
        mProjectile->Render(renderer);
        mSprite.Render(renderer);
    }else{
        // Do nothing;
    }
    for(auto&c : mComponents) {
        c->Render(renderer);
    }
}

std::shared_ptr<Projectile> EnemyGameEntity::GetProjectile() const{
    return mProjectile;
}
