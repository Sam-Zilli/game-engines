#include "SpriteComponent.hpp"
#include "ResourceManager.hpp"

SpriteComponent::SpriteComponent(){

}

void SpriteComponent::CreateSpriteComponent(SDL_Renderer* renderer, std::string filepath){
    mTexture = ResourceManager::Instance().LoadTexture(renderer,filepath);
}

SpriteComponent::~SpriteComponent(){
}

void SpriteComponent::Update(float deltaTime){
}
void SpriteComponent::Render(SDL_Renderer* renderer){
    if(nullptr==mTexture){
        SDL_RenderRect(renderer, &mRectangle);
    }else{
        SDL_RenderTexture(renderer,mTexture.get(),nullptr,&mRectangle);
    }
}

void SpriteComponent::SetW(float w){
    mRectangle.w = w;
}

void SpriteComponent::SetX(float x){
    mRectangle.x = x;
}
void SpriteComponent::SetY(float y){
    mRectangle.y = y;
}

float SpriteComponent::GetX() const{
    return mRectangle.x;
}
float SpriteComponent::GetY() const{
    return mRectangle.y;
}

void SpriteComponent::Move(float x, float y){
    mRectangle.x = x;
    mRectangle.y = y;
}

SDL_FRect SpriteComponent::GetRectangle() const{
    return mRectangle;
}
