#include "Projectile.hpp"

Projectile::Projectile() {
    timeSinceLastLaunch = SDL_GetTicks();
    mRenderable=false;
}

void Projectile::Launch(float x, float y, bool yDirectionIsUp, int minlaunchtime){
    if(SDL_GetTicks() - timeSinceLastLaunch > minlaunchtime){
        timeSinceLastLaunch = SDL_GetTicks();
        mIsFiring=true;        
        mYDirectionUp = yDirectionIsUp;
        mSprite.Move(x,y);
    }
}

void Projectile::Input(float deltaTime){
    for(auto& c : mComponents) {
        c->Input(deltaTime);
    }
}




void Projectile::Update(float deltaTime) {
    if(mIsFiring){
        mRenderable = true;
        if(true == mYDirectionUp){
            mSprite.SetY(mSprite.GetY() - mSpeed * deltaTime);
        }else{
            mSprite.SetY(mSprite.GetY() + mSpeed * deltaTime);
        }
    }else{
        mRenderable=false;
    }

    if(mSprite.GetY() < 0.0f || mSpeed > 480.0f){
        mIsFiring=false;
    }
    for(auto& c : mComponents) {
        c->Update(deltaTime);
    }
}

void Projectile::Render(SDL_Renderer* renderer) {
    if(mRenderable){
        mSprite.Render(renderer);
    }else{
        // Do nothing;
    }
    for(auto& c : mComponents) {
        c->Render(renderer);
    }
}
