#include "Application.hpp"
// changed li to llu

Application::Application(int argc, char* argv[]){
    StartUp();
}
Application::~Application(){
    Shutdown();
}

void Application::StartUp(){
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)!=0){
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    }
    // Create our window
    SDL_Window* mWindow = SDL_CreateWindow("An SDL3 Window",640,480,
            SDL_WINDOW_OPENGL);
    mRenderer = SDL_CreateRenderer(mWindow, NULL, SDL_RENDERER_ACCELERATED);
    if(nullptr == mRenderer){
        SDL_Log("Error creating renderer");
    }

    // Initialize all of the enemies
    int row=1;
    int column=1;
    for(int i=0; i<36; i++){
        SpriteComponent sp;
        sp.CreateSpriteComponent(mRenderer,"./assets/enemy.bmp");


        if(i%12==0){
            ++row;
            column=0;
        }
        sp.Move(column*40+80,row*40);
        column++;
        std::unique_ptr<EnemyGameEntity> e = std::make_unique<EnemyGameEntity>(mRenderer,sp);
        enemies.push_back(std::move(e));
    }

    SpriteComponent characterSprite;
    characterSprite.CreateSpriteComponent(mRenderer,"./assets/hero.bmp");
    characterSprite.Move(640/2 - (32/2),440);
    mainCharacter = std::make_unique<PlayerGameEntity>(mRenderer,characterSprite);
}
void Application::Shutdown(){
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

void Application::Input(float deltaTime){
    SDL_Event event;
    // Processing input
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_EVENT_QUIT){
            SDL_Log("Program quit %llu",event.quit.timestamp);
            mRun=false;
        }
        else if(event.type== SDL_EVENT_KEY_DOWN){
            //                SDL_Log("Some key was pressed down");
            //                SDL_Log("%u",event.key.keysym.sym);
            //                if(event.key.keysym.sym == SDLK_0){
            //                    SDL_Log("0 was pressed");
            //                }
        }
    }

    // Handle SDL_GetKeyboardState after -- your SDL_PollEvent
    mainCharacter->Input(deltaTime);
}

void Application::Update(float deltaTime){
    // Updating all of our enemies
    for(int i=0; i < enemies.size(); i++){
        enemies[i]->Update(deltaTime);

        bool enemyIsHit= enemies[i]->Intersects(mainCharacter->GetProjectile());

        bool GameOver = mainCharacter->Intersects(enemies[i]->GetProjectile());
        if(true==enemyIsHit && enemies[i]->IsRenderable()==true){
            enemies[i]->SetRenderable(false);
            mPoints += 10.0f;
            SDL_Log("Your score is %f",mPoints);
        }

        if(true==GameOver){
            SDL_Log("YOU LOOOOOOOOOSE!"); 
            SDL_Log("Your score is %f",mPoints);
            mRun = false;
        }
    }
    // Update our main character
    mainCharacter->Update(deltaTime);

}

void Application::Render(){
    SDL_SetRenderDrawColor(mRenderer, 0, 64, 255, SDL_ALPHA_OPAQUE);
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

void Application::Loop(float targetFPS){
    // Our infinite game/application loop

    Uint64 lastTime, currentTime;

    // Record our 'starting time'
    lastTime = SDL_GetTicks();
    Uint64 framesElapsed=0;
    float deltaTime = 1.0f/targetFPS;
    while(mRun){
        Uint64 startOfFrame=SDL_GetTicks();
        // We want, input/update/render to take 16ms
        Input(deltaTime);
        Update(deltaTime);
        Render();
        Uint64 elapsedTime=SDL_GetTicks()-startOfFrame;
        framesElapsed++;

        // Time keeping code - for frames elapsed
        currentTime = SDL_GetTicks();
        // Insert a 'frame cap' so that our program
        // does not run too fast.
        if(elapsedTime < (1000/targetFPS)){
            Uint64 delay = (1000/targetFPS)-elapsedTime;
            SDL_Delay(delay);
            //                SDL_Log("elaspedTime: %li",elapsedTime);
            //                SDL_Log("delaying by: %li",delay);
        }
        // If 1 second passes,              enemies[i]->report how many frames
        // have been executed.
        if(currentTime > lastTime+1000){
            SDL_Log("1 second has elapsed");
            SDL_Log("%llu",framesElapsed);
            deltaTime = 1.0f/framesElapsed;
            framesElapsed=0;
            lastTime=SDL_GetTicks();
        }

    }
}
