#include "GameEntity.hpp"

GameEntity::GameEntity(SpriteComponent sprite){
    mSprite = sprite;
}

GameEntity::~GameEntity(){
}

void GameEntity::Input(float deltaTime){
}

void GameEntity::Update(float deltaTime){
}

void GameEntity::Render(SDL_Renderer* renderer){
}

void GameEntity::SetRenderable(bool value){
    mRenderable = value;
}

bool GameEntity::IsRenderable() const{
    return mRenderable;
}

bool GameEntity::Intersects(std::shared_ptr<GameEntity> e){
    SDL_FRect source = e->mSprite.GetRectangle();
    SDL_FRect us     = mSprite.GetRectangle();
    SDL_FRect result;
    return SDL_GetRectIntersectionFloat(&source,&us,&result);
}
