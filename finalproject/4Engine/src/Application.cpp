#include "Application.hpp"
#include "InputComponent.hpp"

Application::Application(const std::string& gameName, int windowWidth, int windowHeight){
    StartUp(gameName, windowWidth, windowHeight);
}
Application::~Application(){
    Shutdown();
}

void Application::Log(const char* message){
    SDL_Log("%s",message);
}

void Application::StartUp(const std::string& gameName, int windowWidth, int windowHeight){
    const char* title = gameName.c_str();
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)!=0){
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    }
    // Create our window
    SDL_Window* mWindow = SDL_CreateWindow(title,windowWidth,windowHeight,
            SDL_WINDOW_OPENGL);
    mRenderer = SDL_CreateRenderer(mWindow, NULL, SDL_RENDERER_ACCELERATED);
    if(nullptr == mRenderer){
        Log("Application::StartUp Error Creating Renderer");
    }
    // Start setting up our scene with appropriate renderer
    mScene.StartUp(mRenderer);
    mScene.SetSceneActiveStatus(true);
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
            mScene.SetSceneActiveStatus(false);
        }
        else if(event.type== SDL_EVENT_KEY_DOWN){
                           SDL_Log("Some key was pressed down------------------");
                           SDL_Log("%u",event.key.keysym.sym);
                           if(event.key.keysym.sym == SDLK_0){
                               SDL_Log("0 was pressed");
                           }
        }
    }

    // Handle SDL_GetKeyboardState after -- your SDL_PollEvent
    mScene.Input(deltaTime);
}

void Application::Update(float deltaTime){
    mScene.Update(deltaTime);
}

void Application::Render(){
    mScene.Render();
}

void Application::Loop(float targetFPS){
    // Our infinite game/application loop

    Uint64 lastTime, currentTime;

    // Record our 'starting time'
    lastTime = SDL_GetTicks();
    Uint64 framesElapsed=0;
    float deltaTime = 1.0f/targetFPS;
    while(mScene.IsSceneActive()){
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
