#include "Application.hpp"
#include "InputComponent.hpp"



/**
 * @brief Constructs the Application object.
 * @param params A map of string key-value pairs for game parameters.
 */
Application::Application(const std::map<std::string, std::string>& params){
    std::string gameName = params.at("game_name");
    int windowWidth = std::stoi(params.at("window_width"));
    int windowHeight = std::stoi(params.at("window_height"));
    float speedOfProjectile = std::stof(params.at("speed_of_projectile"));
    StartUp(gameName, windowWidth, windowHeight, speedOfProjectile);
}



/**
 * @brief Destructs the Application object.
 */
Application::~Application(){
    Shutdown();
}


/**
 * @brief Logs a message to the SDL log.
 * @param message The message to log.
 */
void Application::Log(const char* message){
    SDL_Log("%s",message);
}


/**
 * @brief Starts up the application.
 * @param gameName The name of the game.
 * @param windowWidth The width of the window.
 * @param windowHeight The height of the window.
 * @param speedOfProjectile The speed of the projectile.
 */
void Application::StartUp(const std::string& gameName, int windowWidth, int windowHeight, float speedOfProjectile){
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
    mScene.StartUp(mRenderer, speedOfProjectile, windowWidth, windowHeight);
    mScene.SetSceneActiveStatus(true);
}


/**
 * @brief Shuts down the application.
 */
void Application::Shutdown(){
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}


/**
 * @brief Handles input for the application.
 * @param deltaTime The time since the last frame.
 */
void Application::Input(float deltaTime){
    SDL_Event event;
    // Processing input
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_EVENT_QUIT){
            SDL_Log("Program quit %llu",event.quit.timestamp);
            mScene.SetSceneActiveStatus(false);
        }
        else if(event.type== SDL_EVENT_KEY_DOWN){
            // SDL_Log("Some key was pressed down------------------");
            // SDL_Log("%u",event.key.keysym.sym);
            // if(event.key.keysym.sym == SDLK_0){
            //     SDL_Log("0 was pressed");
            // }
            // Check for arrow keys
            if(event.key.keysym.sym == SDLK_UP){
                SDL_Log("Up arrow key was pressed");
            }
            else if(event.key.keysym.sym == SDLK_DOWN){
                SDL_Log("Down arrow key was pressed");
            }
            else if(event.key.keysym.sym == SDLK_LEFT){
                SDL_Log("Left arrow key was pressed");
            }
            else if(event.key.keysym.sym == SDLK_RIGHT){
                SDL_Log("Right arrow key was pressed");
            }
        }
    }

    // Handle SDL_GetKeyboardState after -- your SDL_PollEvent
    mScene.Input(deltaTime);
}


/**
 * @brief Updates the application state.
 * @param deltaTime The time since the last frame.
 */
void Application::Update(float deltaTime){
    mScene.Update(deltaTime); 
}

/**
 * @brief Renders the application.
 * @param r The red component of the background color.
 * @param g The green component of the background color.
 * @param b The blue component of the background color.
 */
void Application::Render(int r, int g, int b) {
    mScene.Render(r, g, b);
}


/**
 * @brief The main game/application loop.
 * @param targetFPS The target frames per second for the game.
 * @param r The red component of the background color.
 * @param g The green component of the background color.
 * @param b The blue component of the background color.
 */
void Application::Loop(float targetFPS, int r, int g, int b){
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
        Render(r,g,b);
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
