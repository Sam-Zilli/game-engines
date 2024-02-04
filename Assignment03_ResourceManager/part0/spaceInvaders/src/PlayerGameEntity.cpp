#include "PlayerGameEntity.hpp"

PlayerGameEntity::PlayerGameEntity(SDL_Renderer* renderer, Sprite sprite) : GameEntity(sprite){

    Sprite sp;
    sp.CreateSprite(renderer,"./assets/rocket.bmp");
    sp.SetW(24.0f);
    mProjectile = std::make_shared<Projectile>(sp);
}

PlayerGameEntity::~PlayerGameEntity(){
}

void PlayerGameEntity::Input(float deltaTime) {
    const Uint8* state = SDL_GetKeyboardState(nullptr);
    if(state[SDL_SCANCODE_LEFT]){
        mSprite.SetX(mSprite.GetX() - mSpeed*deltaTime);
    }else if(state[SDL_SCANCODE_RIGHT]){
        mSprite.SetX(mSprite.GetX() + mSpeed*deltaTime);
    }

    if(state[SDL_SCANCODE_UP]){
        SDL_Log("Launching!");
        mProjectile->Launch(mSprite.GetX(),mSprite.GetY(),true);
    }
}

void PlayerGameEntity::Update(float deltaTime) {
    mProjectile->Update(deltaTime);
}

void PlayerGameEntity::Render(SDL_Renderer* renderer){
    mProjectile->Render(renderer);
    mSprite.Render(renderer);
}

std::shared_ptr<Projectile> PlayerGameEntity::GetProjectile() const{
    return mProjectile;
}
