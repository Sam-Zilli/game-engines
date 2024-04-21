/**
 * @file Scene.cpp
 * @brief This file contains the implementation of the Scene class.
 */

#include "Scene.hpp"
#include "InputComponent.hpp"
/**
 * @brief Default constructor for the Scene class.
 */
Scene::Scene(){

}

/**
 * @brief Destructor for the Scene class. Calls the Shutdown method.
 */
Scene::~Scene(){
    Shutdown();
}

/**
 * @brief Initializes the Scene.
 * @param renderer The SDL_Renderer to use.
 * @param speedOfProjectile The speed of the projectile.
 * @param windowWidth The width of the window.
 * @param windowHeight The height of the window.
 */
void Scene::StartUp(SDL_Renderer* renderer, float speedOfProjectile, int windowWidth, int windowHeight){
    int numEnemies = windowHeight / 32;
    if (renderer == nullptr) {
        SDL_Log("Renderer is null");
        return;
    }

    mRenderer = renderer;

    int row=0;
    int column=0;

    for(int i=0; i<numEnemies; i++){
        SDL_Log("Creating enemy %i",i);
        std::shared_ptr<EnemyGameEntity> e = std::make_shared<EnemyGameEntity>(mRenderer);
        if (e == nullptr) {
            SDL_Log("Failed to create EnemyGameEntity");
            return;
        }

        e->AddDefaultTransform();

        // Add a texture component to our enemy
        std::shared_ptr<TextureComponent> tex = std::make_shared<TextureComponent>();

        if (tex == nullptr) {
            SDL_Log("TextureComponent is null");
            return;
        }

        if (mRenderer == nullptr) {
            SDL_Log("Renderer is null");
            return;
        }

        tex->CreateTextureComponent(mRenderer,"../assets/street.bmp");

        e->AddComponent(tex);

        std::shared_ptr<Collision2DComponent> col = std::make_shared<Collision2DComponent>();

        if (col == nullptr) {
            SDL_Log("Failed to create Collision2DComponent");
            return;
        }

        e->AddComponent(col); 

    if(i%1==0 && i != 0){ // Skip incrementing row for the first enemy
        ++row;
        column=0;
    }

        column++;

        // original
        // e->GetTransform()->SetXY(column*40+80,row*40);
        e->GetTransform()->SetXY(column*32, row*32); 



        // Add a child game object to our enemies
        // Create a texture
        std::shared_ptr<TextureComponent> projectile_texture=std::make_shared<TextureComponent>();
        projectile_texture->CreateTextureComponent(renderer,"../assets/car.bmp");
        // Create a collider for our projectile
        std::shared_ptr<Collision2DComponent> projectile_col = std::make_shared<Collision2DComponent>();

        std::shared_ptr<Projectile> mProjectile = std::make_shared<Projectile>();
        mProjectile->SetSpeed(speedOfProjectile);
        mProjectile->AddDefaultTransform();
        mProjectile->GetTransform()->SetW(24.0f);

        mProjectile->AddComponent(projectile_texture);
        mProjectile->AddComponent(projectile_col);
        e->AddChildGameEntity(mProjectile);

        // Add to our collection of GameEntities
        enemies.push_back(std::move(e));
    }

    mainCharacter = std::make_shared<GameEntity>();
    mainCharacter->AddDefaultTransform();

    std::shared_ptr<TextureComponent> characterTexture = std::make_shared<TextureComponent>();
    characterTexture->CreateTextureComponent(mRenderer,"../assets/frog.bmp");
    mainCharacter->AddComponent(characterTexture);

    // mainCharacter->GetTransform()->SetXY(0,440);
    mainCharacter->GetTransform()->SetXY(windowWidth/2-(32/2),windowHeight+32);


	std::shared_ptr<InputComponent> inputController = std::make_shared<InputComponent>();
	mainCharacter->AddComponent(inputController);

    std::shared_ptr<Collision2DComponent> col = std::make_shared<Collision2DComponent>();
    mainCharacter->AddComponent(col); 

    /// For our main character, add one child component
    // Create a texture
    std::shared_ptr<TextureComponent> mainCharacterProjectileTexture=std::make_shared<TextureComponent>();
    mainCharacterProjectileTexture->CreateTextureComponent(renderer,"../assets/car.bmp");
    // Create a collider for our projectile
    std::shared_ptr<Collision2DComponent> mainCharacterProjectileCollider = std::make_shared<Collision2DComponent>();

    std::shared_ptr<Projectile> mainCharacterProjectile = std::make_shared<Projectile>();
    mainCharacterProjectile->AddDefaultTransform();
    mainCharacterProjectile->GetTransform()->SetW(24.0f);

    mainCharacterProjectile->AddComponent(mainCharacterProjectileTexture);
    mainCharacterProjectile->AddComponent(mainCharacterProjectileCollider);

    mainCharacter->AddChildGameEntity(mainCharacterProjectile);
}
/**
 * @brief Shuts down the Scene.
 */
void Scene::Shutdown(){
}
/**
 * @brief Handles input for the Scene.
 * @param deltaTime The time since the last frame.
 */
void Scene::Input(float deltaTime){
    // Handle SDL_GetKeyboardState after -- your SDL_PollEvent
    mainCharacter->Input(deltaTime);
}
/**
 * @brief Updates the Scene.
 * @param deltaTime The time since the last frame.
 */
void Scene::Update(float deltaTime){
    // Update our main character
    mainCharacter->Update(deltaTime);

    // Updating all of our enemies
    for(int i=0; i < enemies.size(); i++){
        enemies[i]->Update(deltaTime);
    
        std::shared_ptr<Projectile> enemyProjectile = dynamic_pointer_cast<Projectile>(enemies[i]->GetChildGameEntityAtIndex(0));

        // bool enemyIsHit= enemies[i]->Intersects(mainCharacter->GetChildGameEntityAtIndex(0));

        bool GameOver = false;

        // if(true==enemyIsHit && enemies[i]->IsRenderable()==true){
        //     enemies[i]->SetRenderable(false);
        //     mPoints += 10.0f;
        //     SDL_Log("Your score is %f",mPoints);
        //     SDL_Log("Enemy %i was removed",i);
        // }
        if(enemies[i]->IsRenderable()){
            GameOver = mainCharacter->Intersects(enemyProjectile);
        }

        if(true==GameOver){
            SDL_Log("YOU LOOOOOOOOOSE!"); 
            SDL_Log("Your score is %f",mPoints);
            SDL_Log("Enemy %i got you. enemy[i].IsRenderable()=%i | Projectile: %i",i,
                                                    enemies[i]->IsRenderable(),
                                                    enemyProjectile->IsRenderable());
            mSceneIsActive = false;
        }
        if (mainCharacter->GetTransform()->GetY() <= 0) {
            SDL_Log("You reached the top! You win!");
            mSceneIsActive = false;
        }
        // if(mPoints >= enemies.size()*10.0f){
        //     SDL_Log("You win!");
        //     mSceneIsActive = false;
        // }
    }
}
/**
 * @brief Renders the Scene.
 * @param r The red component of the color to clear the screen with.
 * @param g The green component of the color to clear the screen with.
 * @param b The blue component of the color to clear the screen with.
 */
void Scene::Render(int r, int g, int b){
    SDL_SetRenderDrawColor(mRenderer, r,g,b, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(mRenderer);

    SDL_SetRenderDrawColor(mRenderer, r,g,b, SDL_ALPHA_OPAQUE);

    // Render our enemies
    for(int i=0; i < enemies.size(); i++){
        enemies[i]->Render(mRenderer);
    }
    // Render our main character
    mainCharacter->Render(mRenderer);

    SDL_RenderPresent(mRenderer);
}

/**
 * @brief Sets the active status of the Scene.
 * @param status The new active status.
 */
void Scene::SetSceneActiveStatus(bool status){
    mSceneIsActive = status;
}

/**
 * @brief Checks if the Scene is active.
 * @return True if the Scene is active, false otherwise.
 */
bool Scene::IsSceneActive() const{
    return mSceneIsActive;
}




