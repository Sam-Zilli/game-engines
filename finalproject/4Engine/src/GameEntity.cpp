#include "GameEntity.hpp"

GameEntity::GameEntity(){
}

GameEntity::~GameEntity(){
}

void GameEntity::Input(float deltaTime){
    for(auto& [key,value] : mComponents){
        mComponents[key]->Input(deltaTime);
    }

    for(auto& children: mGameEntities){
        children->Input(deltaTime);
    }
}

// void GameEntity::Update(float deltaTime){
//     for(auto& [key,value] : mComponents){
//         mComponents[key]->Update(deltaTime);
//     }

//     for(auto& children: mGameEntities){
//         children->Update(deltaTime);
//     }
// }


void GameEntity::Update(float deltaTime){
    for(auto& [key,value] : mComponents){
        mComponents[key]->Update(deltaTime);
        
        // Check if the component is a TransformComponent
        if (key == ComponentType::TransformComponent) {
            auto transform = dynamic_pointer_cast<TransformComponent>(value);

            // Modify the Y position of the transform
            // Replace "speed" with the actual speed of your game entity
            // Replace "direction" with 1 for moving down, -1 for moving up
            // float newY = transform->GetY() + speed * direction * deltaTime;
            float newY = transform->GetY() + 20 * 1 * deltaTime;
            transform->SetY(newY);
        }
    }

    for(auto& children: mGameEntities){
        children->Update(deltaTime);
    }
}

void GameEntity::Render(SDL_Renderer* renderer){
    for(auto& [key,value] : mComponents){
        mComponents[key]->Render(renderer);
    }

    for(auto& children: mGameEntities){
        children->Render(renderer);
    }
}

template <typename T>
void GameEntity::AddComponent(std::shared_ptr<T> c){
   // NOTE: You could use the template information to get
   //       the exact component type
   mComponents[c->GetType()]= c;
   c->SetGameEntity(GetThisPtr());
}


// NOTE: Could move this out of header eventually
template <typename T>
std::shared_ptr<T> GameEntity::GetComponent(ComponentType type){
    auto found = mComponents.find(type);
    if(found != mComponents.end()){
        return dynamic_pointer_cast<T>(found->second);
    }

    // For now -- our way of handling a component that does not exist.
    // NOTE: It might be useful to 'log' this as an error.
    // NOTE: This is somewhere, you *could* use an exception -- with caution.
    // NOTE: Better error messages -- don't show the user this.
    SDL_Log("ERROR: The component you searched for is not found -- returning nullptr (This might segfault)");
    return nullptr;
}

void GameEntity::AddDefaultTransform(){
   std::shared_ptr<TransformComponent> t = std::make_shared<TransformComponent>();
   AddComponent<TransformComponent>(t);
}

std::shared_ptr<TransformComponent> GameEntity::GetTransform(){
    return GetComponent<TransformComponent>(ComponentType::TransformComponent);
}

void GameEntity::AddChildGameEntity(std::shared_ptr<GameEntity> child){
   mGameEntities.push_back(child); 
}

std::shared_ptr<GameEntity> GameEntity::GetChildGameEntityAtIndex(size_t index){
   return  mGameEntities.at(index); 
}

void GameEntity::SetRenderable(bool value){
    mRenderable = value;
}

bool GameEntity::IsRenderable() const{
    return mRenderable;
}

bool GameEntity::Intersects(std::shared_ptr<GameEntity> e){
    auto source = e->GetComponent<Collision2DComponent>(ComponentType::Collision2DComponent)->GetRectangle();
    auto us     =    GetComponent<Collision2DComponent>(ComponentType::Collision2DComponent)->GetRectangle();
    /*
    SDL_FRect source = e->mSprite.GetRectangle();
    SDL_FRect us     = mSprite.GetRectangle();
    */
    SDL_FRect result;
    return SDL_GetRectIntersectionFloat(&source,&us,&result);
}

// Explicit template instantiations
template void GameEntity::AddComponent<TextureComponent>(std::shared_ptr<TextureComponent> C);
template void GameEntity::AddComponent<TransformComponent>(std::shared_ptr<TransformComponent> C);
template void GameEntity::AddComponent<Collision2DComponent>(std::shared_ptr<Collision2DComponent> C);
template void GameEntity::AddComponent<InputComponent>(std::shared_ptr<InputComponent> C);

template std::shared_ptr<TextureComponent> GameEntity::GetComponent<TextureComponent>(ComponentType type);
template std::shared_ptr<TransformComponent> GameEntity::GetComponent<TransformComponent>(ComponentType type);
template std::shared_ptr<Collision2DComponent> GameEntity::GetComponent<Collision2DComponent>(ComponentType type);
template std::shared_ptr<InputComponent> GameEntity::GetComponent<InputComponent>(ComponentType type);

