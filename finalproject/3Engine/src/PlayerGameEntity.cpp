#include "PlayerGameEntity.hpp"

PlayerGameEntity::PlayerGameEntity(SDL_Renderer* renderer) {

    std::shared_ptr<SpriteComponent> sp = std::make_shared<SpriteComponent>();
    sp->CreateSpriteComponent(renderer,"../assets/rocket.bmp");
    sp->SetW(24.0f);

    mProjectile = std::make_shared<Projectile>();
    mProjectile->AddComponent(sp);
}

PlayerGameEntity::~PlayerGameEntity(){
}

void PlayerGameEntity::Input(float deltaTime) {
    const Uint8* state = SDL_GetKeyboardState(nullptr);
    // reference to first sprite (49 minutes into Component-Based-Refactoring)
    auto ref = dynamic_pointer_cast<SpriteComponent>(mComponents[0]);


    if(state[SDL_SCANCODE_LEFT]){
        ref->SetX(ref->GetX() - mSpeed*deltaTime);
    }else if(state[SDL_SCANCODE_RIGHT]){
        ref->SetX(ref->GetX() + mSpeed*deltaTime);
    }

    if(state[SDL_SCANCODE_UP]){
        SDL_Log("Launching!");
        mProjectile->Launch(ref->GetX(),ref->GetY(),true);
    }
}

void PlayerGameEntity::Update(float deltaTime) {
    mProjectile->Update(deltaTime);
    for(auto& c : mComponents) {
        c->Update(deltaTime);
    }
}

void PlayerGameEntity::Render(SDL_Renderer* renderer){
    mProjectile->Render(renderer);
    // mSprite.Render(renderer);
    for(auto& c : mComponents) {
        c->Render(renderer);
    }
}

std::shared_ptr<Projectile> PlayerGameEntity::GetProjectile() const{
    return mProjectile;
}
