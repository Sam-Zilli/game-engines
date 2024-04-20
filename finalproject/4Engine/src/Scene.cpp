#include "Scene.hpp"
#include "InputComponent.hpp"

Scene::Scene(){
}
Scene::~Scene(){
    Shutdown();
}

void Scene::StartUp(SDL_Renderer* renderer){

    // Specify the renderer that we will use for drawing this scene.
    /// NOTE: Can add error handling...
    mRenderer = renderer;

    // Initialize all of the enemies
    int row=1;
    int column=1;
    for(int i=0; i<36; i++){
        std::shared_ptr<EnemyGameEntity> e = std::make_shared<EnemyGameEntity>(mRenderer);
        e->AddDefaultTransform();

        // Add a texture component to our enemy
        std::shared_ptr<TextureComponent> tex = std::make_shared<TextureComponent>();
        tex->CreateTextureComponent(mRenderer,"./assets/enemy.bmp");
        e->AddComponent(tex);

        std::shared_ptr<Collision2DComponent> col = std::make_shared<Collision2DComponent>();
        e->AddComponent(col); 
        
        // Calculate position for our enemy
        if(i%12==0){
            ++row;
            column=0;
        }
        column++;

        e->GetTransform()->SetXY(column*40+80,row*40);

        // Add a child game object to our enemies
        // Create a texture
        std::shared_ptr<TextureComponent> projectile_texture=std::make_shared<TextureComponent>();
        projectile_texture->CreateTextureComponent(renderer,"./assets/rocket.bmp");
        // Create a collider for our projectile
        std::shared_ptr<Collision2DComponent> projectile_col = std::make_shared<Collision2DComponent>();

        std::shared_ptr<Projectile> mProjectile = std::make_shared<Projectile>();
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
    characterTexture->CreateTextureComponent(mRenderer,"./assets/hero.bmp");
    mainCharacter->AddComponent(characterTexture);

    mainCharacter->GetTransform()->SetXY(640/2 - (32/2),440);

	std::shared_ptr<InputComponent> inputController = std::make_shared<InputComponent>();
	mainCharacter->AddComponent(inputController);

    std::shared_ptr<Collision2DComponent> col = std::make_shared<Collision2DComponent>();
    mainCharacter->AddComponent(col); 

    /// For our main character, add one child component
    // Create a texture
    std::shared_ptr<TextureComponent> mainCharacterProjectileTexture=std::make_shared<TextureComponent>();
    mainCharacterProjectileTexture->CreateTextureComponent(renderer,"./assets/rocket.bmp");
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
