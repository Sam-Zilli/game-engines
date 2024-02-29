#include "PlayerGameEntity.hpp"

PlayerGameEntity::PlayerGameEntity(SDL_Renderer* renderer){

    // Create a texture
    std::shared_ptr<TextureComponent> texture=std::make_shared<TextureComponent>();
    texture->CreateTextureComponent(renderer,"./assets/rocket.bmp");
    // Create a collider for our projectile
    std::shared_ptr<Collision2DComponent> col = std::make_shared<Collision2DComponent>();

    mProjectile = std::make_shared<Projectile>();
    mProjectile->AddDefaultTransform();
    mProjectile->GetTransform()->SetW(24.0f);

    mProjectile->AddComponent(texture);
    mProjectile->AddComponent(col);
}

PlayerGameEntity::~PlayerGameEntity(){
}

void PlayerGameEntity::Input(float deltaTime) {
    for(auto& [key,value] : mComponents){
        mComponents[key]->Input(deltaTime);
    }
}

void PlayerGameEntity::Update(float deltaTime) {
    mProjectile->Update(deltaTime);
    for(auto& [key,value] : mComponents){
        mComponents[key]->Update(deltaTime);
    }
}

void PlayerGameEntity::Render(SDL_Renderer* renderer){
    mProjectile->Render(renderer);
    for(auto& [key,value] : mComponents){
        mComponents[key]->Render(renderer);
    }
}

std::shared_ptr<Projectile> PlayerGameEntity::GetProjectile() const{
    return mProjectile;
}
