#include "Scene.hpp"
#include "InputComponent.hpp"

// -------------------------- GAME 1 ---------------------- //



Scene::Scene(){

}

Scene::~Scene(){
    Shutdown();
}

void Scene::StartUp(SDL_Renderer* renderer, float speedOfProjectile){

    if (renderer == nullptr) {
        SDL_Log("Renderer is null");
        return;
    }
    SDL_Log("Scene::StartUp 1");
    mRenderer = renderer;
    SDL_Log("Scene::StartUp 2");
    int row=1;
    int column=1;
    SDL_Log("Scene::StartUp 3");
    for(int i=0; i<36; i++){
        std::shared_ptr<EnemyGameEntity> e = std::make_shared<EnemyGameEntity>(mRenderer);
        if (e == nullptr) {
            SDL_Log("Failed to create EnemyGameEntity");
            return;
        }
        SDL_Log("Scene::StartUp 4");
        e->AddDefaultTransform();
        SDL_Log("Scene::StartUp 5");
        // Add a texture component to our enemy
        std::shared_ptr<TextureComponent> tex = std::make_shared<TextureComponent>();
        SDL_Log("Scene::StartUp 6");
        if (tex == nullptr) {
            SDL_Log("TextureComponent is null");
            return;
        }

        if (mRenderer == nullptr) {
            SDL_Log("Renderer is null");
            return;
        }
        SDL_Log("Scene::StartUp 6.1");
        tex->CreateTextureComponent(mRenderer,"../assets/enemy.bmp");
        SDL_Log("Scene::StartUp 7");
        e->AddComponent(tex);
        SDL_Log("Scene::StartUp 8");
        std::shared_ptr<Collision2DComponent> col = std::make_shared<Collision2DComponent>();
        SDL_Log("Scene::StartUp 9");
        if (col == nullptr) {
            SDL_Log("Failed to create Collision2DComponent");
            return;
        }
        SDL_Log("Scene::StartUp 10");
        e->AddComponent(col); 
        SDL_Log("Scene::StartUp 11");
        if(i%12==0){
            ++row;
            column=0;
        }
        SDL_Log("Scene::StartUp 12");
        column++;
        SDL_Log("Scene::StartUp 13");
        e->GetTransform()->SetXY(column*40+80,row*40);
        SDL_Log("Scene::StartUp 14");

        // Add a child game object to our enemies
        // Create a texture
        std::shared_ptr<TextureComponent> projectile_texture=std::make_shared<TextureComponent>();
        projectile_texture->CreateTextureComponent(renderer,"../assets/rocket.bmp");
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
        // NOTE: Yes, I know these comments are obvious..but I can scan them very quickly in my code editor.
        enemies.push_back(std::move(e));
    }

    mainCharacter = std::make_shared<GameEntity>();
    mainCharacter->AddDefaultTransform();

    std::shared_ptr<TextureComponent> characterTexture = std::make_shared<TextureComponent>();
    characterTexture->CreateTextureComponent(mRenderer,"../assets/hero.bmp");
    mainCharacter->AddComponent(characterTexture);

    mainCharacter->GetTransform()->SetXY(640/2 - (32/2),440);

	std::shared_ptr<InputComponent> inputController = std::make_shared<InputComponent>();
	mainCharacter->AddComponent(inputController);

    std::shared_ptr<Collision2DComponent> col = std::make_shared<Collision2DComponent>();
    mainCharacter->AddComponent(col); 

    /// For our main character, add one child component
    // Create a texture
    std::shared_ptr<TextureComponent> mainCharacterProjectileTexture=std::make_shared<TextureComponent>();
    mainCharacterProjectileTexture->CreateTextureComponent(renderer,"../assets/rocket.bmp");
    // Create a collider for our projectile
    std::shared_ptr<Collision2DComponent> mainCharacterProjectileCollider = std::make_shared<Collision2DComponent>();

    std::shared_ptr<Projectile> mainCharacterProjectile = std::make_shared<Projectile>();
    mainCharacterProjectile->AddDefaultTransform();
    mainCharacterProjectile->GetTransform()->SetW(24.0f);

    mainCharacterProjectile->AddComponent(mainCharacterProjectileTexture);
    mainCharacterProjectile->AddComponent(mainCharacterProjectileCollider);

    mainCharacter->AddChildGameEntity(mainCharacterProjectile);
}

void Scene::Shutdown(){
}

void Scene::Input(float deltaTime){
    // Handle SDL_GetKeyboardState after -- your SDL_PollEvent
    mainCharacter->Input(deltaTime);
}

void Scene::Update(float deltaTime){
    // Update our main character
    mainCharacter->Update(deltaTime);

    // Updating all of our enemies
    for(int i=0; i < enemies.size(); i++){
        enemies[i]->Update(deltaTime);
    
        std::shared_ptr<Projectile> enemyProjectile = dynamic_pointer_cast<Projectile>(enemies[i]->GetChildGameEntityAtIndex(0));

        bool enemyIsHit= enemies[i]->Intersects(mainCharacter->GetChildGameEntityAtIndex(0));

        bool GameOver = false;

        if(true==enemyIsHit && enemies[i]->IsRenderable()==true){
            enemies[i]->SetRenderable(false);
            mPoints += 10.0f;
            SDL_Log("Your score is %f",mPoints);
            SDL_Log("Enemy was %i was removed",i);
        }
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

        if(mPoints >= enemies.size()*10.0f){
            SDL_Log("You win!");
            mSceneIsActive = false;
        }
    }
}

void Scene::Render(){
    SDL_SetRenderDrawColor(mRenderer, 32, 32, 64, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(mRenderer);

    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    // Render our enemies
    for(int i=0; i < enemies.size(); i++){
        enemies[i]->Render(mRenderer);
    }
    // Render our main character
    mainCharacter->Render(mRenderer);

    SDL_RenderPresent(mRenderer);
}

void Scene::SetSceneActiveStatus(bool status){
    mSceneIsActive = status;
}

bool Scene::IsSceneActive() const{
    return mSceneIsActive;
}










// -------------------------- GAME 2 ---------------------- //

