#include "Projectile.hpp"

Projectile::Projectile() {
    timeSinceLastLaunch = SDL_GetTicks();
    mRenderable=false;
}

void Projectile::Launch(float x, float y, bool yDirectionIsUp, int minlaunchtime){
    if(SDL_GetTicks() - timeSinceLastLaunch > minlaunchtime){
        auto ref = dynamic_pointer_cast<SpriteComponent>(mComponents[0]);
        ref->SetX(x);
        ref->SetY(y);
        timeSinceLastLaunch = SDL_GetTicks();
        mIsFiring=true;        
        mYDirectionUp = yDirectionIsUp;
        // mSprite.Move(x,y);
    }
}

void Projectile::Input(float deltaTime){
    for(auto& c : mComponents) {
        c->Input(deltaTime);
    }
}




void Projectile::Update(float deltaTime) {
    auto ref = dynamic_pointer_cast<SpriteComponent>(mComponents[0]);
    if(mIsFiring){
        mRenderable = true;
        if(true == mYDirectionUp){
            ref->SetY(ref->GetY() - mSpeed * deltaTime);
        }else{
            ref->SetY(ref->GetY() + mSpeed * deltaTime);
        }
    }else{
        mRenderable=false;
    }

    if(ref->GetY() < 0.0f || ref->GetY() > 480.0f){
        mIsFiring=false;
    }
    // for(auto& c : mComponents) {
    //     c->Update(deltaTime);
    // }
}

void Projectile::Render(SDL_Renderer* renderer) {
    if(mRenderable){
        for(auto& c : mComponents) {
            c->Render(renderer);
        }
    }else{
        // Do nothing;
    }

}
