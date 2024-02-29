#include "EnemyGameEntity.hpp"

EnemyGameEntity::EnemyGameEntity(SDL_Renderer* renderer) {

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

    // Set a random launch time for the enemies
    mMinLaunchTime += std::rand() % 10000;
}

EnemyGameEntity::~EnemyGameEntity(){
}

void EnemyGameEntity::Input(float deltaTime) {
    for(auto& [key,value] : mComponents){
        mComponents[key]->Input(deltaTime);
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

    // Keeping track of our projectile game logic
    auto transform = GetComponent<TransformComponent>(ComponentType::TransformComponent);

    if(xPositiveDirection){
        transform->SetX(transform->GetX() + mSpeed*deltaTime);
        offset += mSpeed * deltaTime;
    }else{
        transform->SetX(transform->GetX() - mSpeed*deltaTime);
        offset -= mSpeed * deltaTime;
    }

    if(mRenderable){
        mProjectile->Launch(transform->GetX(),transform->GetY(),false,mMinLaunchTime);
    }

    for(auto& [key,value] : mComponents){
        mComponents[key]->Update(deltaTime);
    }
}

void EnemyGameEntity::Render(SDL_Renderer* renderer){
    if(mRenderable){
        mProjectile->Render(renderer);
    }else{
        // Do nothing;
        mProjectile->SetRenderable(false);
        return;
    }
    for(auto& [key,value] : mComponents){
        mComponents[key]->Render(renderer);
    }
}

std::shared_ptr<Projectile> EnemyGameEntity::GetProjectile() const{
    return mProjectile;
}
