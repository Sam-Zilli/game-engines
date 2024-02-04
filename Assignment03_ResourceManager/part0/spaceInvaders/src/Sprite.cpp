#include "Sprite.hpp"
#include "ResourceManager.hpp"

Sprite::Sprite(){

}

void Sprite::CreateSprite(SDL_Renderer* renderer, std::string filepath){
    mTexture = ResourceManager::Instance().LoadTexture(renderer,filepath);
}

Sprite::~Sprite(){
}

void Sprite::Update(float deltaTime){
}
void Sprite::Render(SDL_Renderer* renderer){
    if(nullptr==mTexture){
        SDL_RenderRect(renderer, &mRectangle);
    }else{
        SDL_RenderTexture(renderer,mTexture.get(),nullptr,&mRectangle);
    }
}

void Sprite::SetW(float w){
    mRectangle.w = w;
}

void Sprite::SetX(float x){
    mRectangle.x = x;
}
void Sprite::SetY(float y){
    mRectangle.y = y;
}

float Sprite::GetX() const{
    return mRectangle.x;
}
float Sprite::GetY() const{
    return mRectangle.y;
}

void Sprite::Move(float x, float y){
    mRectangle.x = x;
    mRectangle.y = y;
}

SDL_FRect Sprite::GetRectangle() const{
    return mRectangle;
}
