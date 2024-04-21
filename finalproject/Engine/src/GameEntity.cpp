#include "GameEntity.hpp"

/** @brief Default constructor for GameEntity */
GameEntity::GameEntity(){

}

/** @brief Destructor for GameEntity */
GameEntity::~GameEntity(){
}

/** 
 * @brief Handles input for the GameEntity
 * @param deltaTime The time elapsed since the last frame
 */
void GameEntity::Input(float deltaTime){
    for(auto& [key,value] : mComponents){
        mComponents[key]->Input(deltaTime);
    }

    for(auto& children: mGameEntities){
        children->Input(deltaTime);
    }
}

/** 
 * @brief Updates the GameEntity
 * @param deltaTime The time elapsed since the last frame
 */
void GameEntity::Update(float deltaTime){
    for(auto& [key,value] : mComponents){
        mComponents[key]->Update(deltaTime);
    }

    for(auto& children: mGameEntities){
        children->Update(deltaTime);
    }
}

/** 
 * @brief Renders the GameEntity
 * @param renderer The SDL_Renderer to use for rendering
 */
void GameEntity::Render(SDL_Renderer* renderer){
    for(auto& [key,value] : mComponents){
        mComponents[key]->Render(renderer);
    }

    for(auto& children: mGameEntities){
        children->Render(renderer);
    }
}

/** 
 * @brief Adds a component to the GameEntity
 * @param c The component to add
 */
template <typename T>
void GameEntity::AddComponent(std::shared_ptr<T> c){
   mComponents[c->GetType()]= c;
   c->SetGameEntity(GetThisPtr());
}

/** 
 * @brief Gets a component from the GameEntity
 * @param type The type of the component to get
 * @return The component, or nullptr if it does not exist
 */
template <typename T>
std::shared_ptr<T> GameEntity::GetComponent(ComponentType type){
    auto found = mComponents.find(type);
    if(found != mComponents.end()){
        return dynamic_pointer_cast<T>(found->second);
    }

    SDL_Log("ERROR: The component you searched for is not found -- returning nullptr (This might segfault)");
    return nullptr;
}

/** @brief Adds a default TransformComponent to the GameEntity */
void GameEntity::AddDefaultTransform(){
   std::shared_ptr<TransformComponent> t = std::make_shared<TransformComponent>();
   AddComponent<TransformComponent>(t);
}

/** 
 * @brief Gets the TransformComponent of the GameEntity
 * @return The TransformComponent
 */
std::shared_ptr<TransformComponent> GameEntity::GetTransform(){
    return GetComponent<TransformComponent>(ComponentType::TransformComponent);
}

/** 
 * @brief Adds a child GameEntity
 * @param child The child GameEntity to add
 */
void GameEntity::AddChildGameEntity(std::shared_ptr<GameEntity> child){
   mGameEntities.push_back(child); 
}

/** 
 * @brief Gets a child GameEntity at a specific index
 * @param index The index of the child GameEntity to get
 * @return The child GameEntity
 */
std::shared_ptr<GameEntity> GameEntity::GetChildGameEntityAtIndex(size_t index){
   return  mGameEntities.at(index); 
}

/** 
 * @brief Sets whether the GameEntity is renderable
 * @param value Whether the GameEntity should be renderable
 */
void GameEntity::SetRenderable(bool value){
    mRenderable = value;
}

/** 
 * @brief Checks whether the GameEntity is renderable
 * @return Whether the GameEntity is renderable
 */
bool GameEntity::IsRenderable() const{
    return mRenderable;
}

/** 
 * @brief Checks whether the GameEntity intersects with another GameEntity
 * @param e The other GameEntity
 * @return Whether the GameEntities intersect
 */
bool GameEntity::Intersects(std::shared_ptr<GameEntity> e){
    auto source = e->GetComponent<Collision2DComponent>(ComponentType::Collision2DComponent)->GetRectangle();
    auto us     =    GetComponent<Collision2DComponent>(ComponentType::Collision2DComponent)->GetRectangle();
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