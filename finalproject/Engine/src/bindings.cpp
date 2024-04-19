#ifndef SDLGRAPHICSPROGRAM
#define SDLGRAPHICSPROGRAM

#include <SDL3/SDL.h>

// The glad library helps setup OpenGL extensions.
#include <glad/glad.h>

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstring>
#include <stdio.h>

class SDLGraphicsProgram{
public:
    // Constructor
    SDLGraphicsProgram(int w, int h, const char* gameName);

    // Destructor
    ~SDLGraphicsProgram();

    // Setup OpenGL
    bool initGL();

    // Clears the screen
    void clear();

    // Flips to new buffer
    void flip();

    // Delay rendering
    void delay(int milliseconds);

    // loop that runs forever
    // void loop();
    // Get Pointer to Window
    SDL_Window* getSDLWindow();

    // Draw a simple 
    void DrawRectangle(int x, int y, int w, int h);

    // starts the ping pong game
    // void runPongGame();

    // loop poll
    void poll();

    bool getQuit();

    void setBackgroundColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

    // right paddle commands
    bool getRightPaddleUp();
    bool getRightPaddleDown();

    // left paddle commands
    bool getLeftPaddleUp();
    bool getLeftPaddleDown();

private:
    int screenWidth;
    int screenHeight;
    const char* gameName;

    // The window we'll be rendering to
    SDL_Window* gWindow ;

    // Our renderer
    SDL_Renderer* gRenderer;

    Uint8 backgroundRed;
    Uint8 backgroundGreen;
    Uint8 backgroundBlue;
    Uint8 backgroundAlpha;

    bool quit = false;

    // right paddle commands
    bool rightPaddleUp = false;
    bool rightPaddleDown = false;

    // left paddle commands
    bool leftPaddleUp = false;
    bool leftPaddleDown = false;

};





// Initialization function
// Returns a true or false value based on successful completion of setup.
// Takes in dimensions of window.
SDLGraphicsProgram::SDLGraphicsProgram(int w, int h, const char* gameNameParam)
    : screenWidth(w), screenHeight(h), gameName(gameNameParam) {
    // Initialization code
	bool success = true;
	// String to hold any errors that occur.
	std::stringstream errorStream;
	// The window we'll be rendering to
	gWindow = NULL;
	// Render flag

	// Initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO)< 0){
		errorStream << "SDL could not initialize! SDL Error: " << SDL_GetError() << "\n";
		success = false;
	}
	else{
	    //Create window
        SDL_Log("1");
    	gWindow = SDL_CreateWindow(gameName, screenWidth, screenHeight, SDL_WINDOW_OPENGL);
        SDL_Log("2");

        // Check if Window did not create.
        if( gWindow == NULL ){
            SDL_Log("ISSUE IS HERE");
			errorStream << "Window could not be created! SDL Error: " << SDL_GetError() << "\n";
			success = false;
		}
        
        SDL_Log("3");

		//Create a Renderer to draw on
        gRenderer = SDL_CreateRenderer(gWindow, NULL, SDL_RENDERER_ACCELERATED);
        SDL_Log("4");
        // Check if Renderer did not create.
        if( gRenderer == NULL ){
            errorStream << "Renderer could not be created! SDL Error: " << SDL_GetError() << "\n";
            success = false;
        }
        SDL_Log("5");
  	}

    SDL_Log("6");

    // If initialization did not work, then print out a list of errors in the constructor.
    if(!success){
        SDL_Log("7");
        errorStream << "SDLGraphicsProgram::SDLGraphicsProgram - Failed to initialize!\n";
        std::string errors=errorStream.str();
        SDL_Log("%s\n",errors.c_str());
    }else{
        SDL_Log("SDLGraphicsProgram::SDLGraphicsProgram - No SDL, GLAD, or OpenGL, errors detected during initialization\n\n");
    }

}

// Proper shutdown of SDL and destroy initialized objects
SDLGraphicsProgram::~SDLGraphicsProgram(){
    SDL_Log("In destructor!!!!!");
    //Destroy window
	SDL_DestroyWindow( gWindow );
	// Point gWindow to NULL to ensure it points to nothing.
	gWindow = NULL;
	//Quit SDL subsystems
	SDL_Quit();
}

// Logs keyboard presses and keeps loop 
void SDLGraphicsProgram::poll() {
    rightPaddleDown = false;
    rightPaddleUp = false;
    leftPaddleUp = false;
    leftPaddleDown = false;
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        switch (event.type) {
            case SDL_EVENT_QUIT:
                SDL_Log("Quit event detected");
                quit = true;
                break;
            case SDL_EVENT_KEY_DOWN:
                SDL_Log("Key pressed: %s", SDL_GetKeyName(event.key.keysym.sym));
                if(strcmp(SDL_GetKeyName(event.key.keysym.sym), "Up") == 0) {
                    rightPaddleUp = true;
                }
                if(strcmp(SDL_GetKeyName(event.key.keysym.sym), "Down") == 0) {
                    rightPaddleDown = true;
                }
                if(strcmp(SDL_GetKeyName(event.key.keysym.sym), "Left Option") == 0) {
                    leftPaddleUp = true;
                }
                if(strcmp(SDL_GetKeyName(event.key.keysym.sym), "Z") == 0) {
                    leftPaddleDown = true;
                }
            case SDL_EVENT_KEY_UP:
                // SDL_Log("Key released: %s", SDL_GetKeyName(event.key.keysym.sym));
                break;
            default:
                // SDL_Log("Unknown event type: %d", event.type);
                break;
        }
    }
}

// Initialize OpenGL
// Setup any of our shaders here.
bool SDLGraphicsProgram::initGL(){
    SDL_Log("In initGL!!!!!");
	//Success flag
	bool success = true;

	return success;
}

void SDLGraphicsProgram::setBackgroundColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    backgroundRed = r;
    backgroundGreen = g;
    backgroundBlue = b;
    backgroundAlpha = a;

}

// Clears the screen 
void SDLGraphicsProgram::clear(){
    SDL_Log("In clear!!!!");
	// Nothing yet!
    SDL_SetRenderDrawColor(gRenderer, backgroundRed,backgroundGreen,backgroundBlue, backgroundAlpha);
    SDL_RenderClear(gRenderer);   
}

// The flip function gets called once per loop
// It swaps out the previvous frame in a double-buffering system
void SDLGraphicsProgram::flip(){
    SDL_Log("In flip!!!!");
	// Nothing yet! 
    SDL_RenderPresent(gRenderer);
}


void SDLGraphicsProgram::delay(int milliseconds){
    SDL_Log("In delay!!!");
    SDL_Delay(milliseconds); 
}

// Get Pointer to Window
SDL_Window* SDLGraphicsProgram::getSDLWindow(){
SDL_Log("In getSDLWindow!!!");
  return gWindow;
}


// Okay, render our rectangles!
void SDLGraphicsProgram::DrawRectangle(int x, int y, int w, int h){
    

    SDL_FRect fillRectF = {(float)x, (float)y, (float)w, (float)h};

    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    // SDL2: int SDL_RenderDrawRect(SDL_Renderer * renderer, const SDL_Rect * rect);
    // SDL3: int SDL_RenderRect    (SDL_Renderer *renderer, const SDL_FRect *rect);
    SDL_RenderRect(gRenderer, &fillRectF); 
}



bool SDLGraphicsProgram::getQuit() {
    return quit;
}

bool SDLGraphicsProgram::getRightPaddleUp() {
    return rightPaddleUp;
}

bool SDLGraphicsProgram::getRightPaddleDown() {
    return rightPaddleDown;
}

bool SDLGraphicsProgram::getLeftPaddleUp() {
    return leftPaddleUp;
}

bool SDLGraphicsProgram::getLeftPaddleDown() {
    return leftPaddleDown;
}






















// --------------------- PYBIND ------------------- //


// Include the pybindings
#include <pybind11/pybind11.h>

namespace py = pybind11;

// Creates a macro function that will be called
// whenever the module is imported into python
// 'mygameengine' is what we 'import' into python.
// 'm' is the interface (creates a py::module object)
//      for which the bindings are created.
//  The magic here is in 'template metaprogramming'
PYBIND11_MODULE(mygameengine, m){
    m.doc() = "our game engine as a library"; // Optional docstring

    py::class_<SDLGraphicsProgram>(m, "SDLGraphicsProgram")
            .def(py::init<int, int, const char*>(), py::arg("width"), py::arg("height"), py::arg("game_name"))   // our constructor
            .def("clear", &SDLGraphicsProgram::clear) // Expose member methods
            .def("delay", &SDLGraphicsProgram::delay) 
            .def("flip", &SDLGraphicsProgram::flip) 
            // .def("loop", &SDLGraphicsProgram::loop) 
            .def("DrawRectangle", &SDLGraphicsProgram::DrawRectangle)
            .def("poll", &SDLGraphicsProgram::poll)
            .def("getQuit", &SDLGraphicsProgram::getQuit)
            .def("getRightPaddleUp", &SDLGraphicsProgram::getRightPaddleUp)
            .def("getRightPaddleDown", &SDLGraphicsProgram::getRightPaddleDown)
            .def("getLeftPaddleUp", &SDLGraphicsProgram::getLeftPaddleUp)
            .def("getLeftPaddleDown", &SDLGraphicsProgram::getLeftPaddleDown)
            .def("setBackgroundColor", &SDLGraphicsProgram::setBackgroundColor);
}
 
#endif