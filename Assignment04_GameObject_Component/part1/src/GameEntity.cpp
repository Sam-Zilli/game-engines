#include "GameEntity.hpp"
#include <vector>

GameEntity::GameEntity() {
}

GameEntity::~GameEntity(){
}

void GameEntity::Input(float deltaTime){
    for(auto& c : mComponents) {
        c->Input(deltaTime);
    }
}

void GameEntity::Update(float deltaTime){
    for(auto& c : mComponents) {
        c->Update(deltaTime);
    }
}

void GameEntity::Render(SDL_Renderer* renderer){
    for(auto& c : mComponents) {
        c->Render(renderer);
    }
}

void GameEntity::AddComponent(std::shared_ptr<Component> c) {
    mComponents.push_back(c);
}

void GameEntity::SetRenderable(bool value){
    mRenderable = value;
}

bool GameEntity::IsRenderable() const{
    return mRenderable;
}

bool GameEntity::Intersects(std::shared_ptr<GameEntity> e){
    auto source = dynamic_pointer_cast<SpriteComponent>(e->mComponents[0])->GetRectangle();
    auto us = dynamic_pointer_cast<SpriteComponent>(mComponents[0])->GetRectangle();

    // SDL_FRect source = e->mSprite.GetRectangle();
    // SDL_FRect us     = mSprite.GetRectangle();
    SDL_FRect result;
    return SDL_GetRectIntersectionFloat(&source,&us,&result);

//    return false;
}
