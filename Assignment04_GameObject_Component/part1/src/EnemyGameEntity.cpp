#include "EnemyGameEntity.hpp"

EnemyGameEntity::EnemyGameEntity(SDL_Renderer* renderer){
    std::shared_ptr<SpriteComponent> sp = std::make_shared<SpriteComponent>();
    sp->CreateSpriteComponent(renderer,"./assets/rocket.bmp");
    sp->SetW(24.0f);

    mProjectile = std::make_shared<Projectile>();
    mProjectile->AddComponent(sp);

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

    auto ref = dynamic_pointer_cast<SpriteComponent>(mComponents[0]);

    if(xPositiveDirection){
        ref->SetX(ref->GetX() + mSpeed*deltaTime);
        offset += mSpeed * deltaTime;
    }else{
        ref->SetX(ref->GetX() - mSpeed*deltaTime);
        offset -= mSpeed * deltaTime;
    }

    if(mRenderable){
        mProjectile->Launch(ref->GetX(),ref->GetY(),false,mMinLaunchTime);
    }
    for(auto& c: mComponents){
        c->Update(deltaTime);
    }
}

void EnemyGameEntity::Render(SDL_Renderer* renderer){
    if(mRenderable){
        for(auto& c : mComponents) {
            c->Render(renderer);
        }
        mProjectile->Render(renderer);
        // mSprite.Render(renderer);
    }else{
        // Do nothing;
    }
}


std::shared_ptr<Projectile> EnemyGameEntity::GetProjectile() const{
    return mProjectile;
}
