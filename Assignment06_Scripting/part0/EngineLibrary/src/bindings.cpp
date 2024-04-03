#ifndef SDLGRAPHICSPROGRAM
#define SDLGRAPHICSPROGRAM

// dependencies.
#if defined(LINUX) || defined(MINGW)
    #include <SDL2/SDL.h>
#else // This works for Mac
    #include <SDL.h>
#endif

// The glad library helps setup OpenGL extensions.
#include <glad/glad.h>

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

class SDLGraphicsProgram{
public:
    // Constructor
    SDLGraphicsProgram(int w, int h);
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
    // Draw a simple rectangle
    void DrawRectangle(int x, int y, int w, int h);
    // starts the ping pong game
    // void runPongGame();
    // loop poll
    void poll();

    bool getQuit();

private:
    // Screen dimension constants
    int screenHeight;
    int screenWidth;
    // The window we'll be rendering to
    SDL_Window* gWindow ;
    // Our renderer
    SDL_Renderer* gRenderer;

    // LEFT player travels on left y axis
    float leftPaddleY;
    float leftPaddleX;


    // RIGHT player travels on right y axis
    float rightPaddleY;
    float rightPaddleX;

    // ball location
    float ballx;
    float bally;
    // ball movement
    float ballVX;
    float ballVY;

    // move LEFT paddle
    void setLeftPaddleCoordinates();
    // move RIGHT paddle
    void setRightPaddleCoordinates();
    // move BALL location
    void setBallCoordinates();

    bool quit = false;
};


// Initialization function
// Returns a true or false value based on successful completion of setup.
// Takes in dimensions of window.
SDLGraphicsProgram::SDLGraphicsProgram(int w, int h):screenWidth(w),screenHeight(h){
	// Initialization flag
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
    	gWindow = SDL_CreateWindow( "Lab", 100, 100, screenWidth, screenHeight, SDL_WINDOW_SHOWN );

        // Check if Window did not create.
        if( gWindow == NULL ){
			errorStream << "Window could not be created! SDL Error: " << SDL_GetError() << "\n";
			success = false;
		}

		//Create a Renderer to draw on
        gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
        // Check if Renderer did not create.
        if( gRenderer == NULL ){
            errorStream << "Renderer could not be created! SDL Error: " << SDL_GetError() << "\n";
            success = false;
        }
  	}

    // If initialization did not work, then print out a list of errors in the constructor.
    if(!success){
        errorStream << "SDLGraphicsProgram::SDLGraphicsProgram - Failed to initialize!\n";
        std::string errors=errorStream.str();
        SDL_Log("%s\n",errors.c_str());
    }else{
        SDL_Log("SDLGraphicsProgram::SDLGraphicsProgram - No SDL, GLAD, or OpenGL, errors detected during initialization\n\n");
    }

}

// Proper shutdown of SDL and destroy initialized objects
SDLGraphicsProgram::~SDLGraphicsProgram(){
    //Destroy window
	SDL_DestroyWindow( gWindow );
	// Point gWindow to NULL to ensure it points to nothing.
	gWindow = NULL;
	//Quit SDL subsystems
	SDL_Quit();
}

// Logs keyboard presses and keeps loop 
void SDLGraphicsProgram::poll() {
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        switch (event.type) {
            case SDL_QUIT:
                SDL_Log("Quit event detected");
                quit = true;
                break;
            case SDL_KEYDOWN:
                SDL_Log("Key pressed: %s", SDL_GetKeyName(event.key.keysym.sym));
                break;
            case SDL_KEYUP:
                SDL_Log("Key released: %s", SDL_GetKeyName(event.key.keysym.sym));
                break;
            default:
                SDL_Log("Unknown event type: %d", event.type);
                break;
        }
    }
}

// Initialize OpenGL
// Setup any of our shaders here.
bool SDLGraphicsProgram::initGL(){
	//Success flag
	bool success = true;

	return success;
}


// Clear
// Clears the screen
void SDLGraphicsProgram::clear(){
	// Nothing yet!
    SDL_SetRenderDrawColor(gRenderer, 0x44,0x44,0x4,0xFF);
    SDL_RenderClear(gRenderer);   
}
// Flip
// The flip function gets called once per loop
// It swaps out the previvous frame in a double-buffering system
void SDLGraphicsProgram::flip(){
	// Nothing yet! fst
    SDL_RenderPresent(gRenderer);
}


void SDLGraphicsProgram::delay(int milliseconds){
    SDL_Delay(milliseconds); 
}

// Get Pointer to Window
SDL_Window* SDLGraphicsProgram::getSDLWindow(){
  return gWindow;
}


// Okay, render our rectangles!
void SDLGraphicsProgram::DrawRectangle(int x, int y, int w, int h){
    SDL_Rect fillRect = {x,y,w,h};
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderDrawRect(gRenderer, &fillRect); 
}


bool SDLGraphicsProgram::getQuit() {
    return quit;
}


















// START PONG LOGIC 
// python3.11 test.py -m ./mygameengine.so OR
// python3.11 pong.py -m ./mygameengine.so
// Assignment 6 functions
// void SDLGraphicsProgram::runPongGame() {
//     // keeps inner pong game loop running
//     bool quit = false;

//     leftPaddleY = 80.0f;
//     rightPaddleY = 80.0f;


//     while (!quit) {
//         // Handle events
//         SDL_Event e;
//         while (SDL_PollEvent(&e) != 0) {
//             if (e.type == SDL_QUIT) {
//                 quit = true;
//             }
//         }

//         // Clear the screen - use outer function later
//         clear();

//         setLeftPaddleCoordinates();
//         setRightPaddleCoordinates();
        
//         setBallCoordinates();

//         // Draw paddles
//         DrawRectangle(10, static_cast<int>(leftPaddleY), 20, 20);
//         DrawRectangle(780, static_cast<int>(rightPaddleY), 20, 20);

//         // Draw ball
//         DrawRectangle(static_cast<int>(ballx), static_cast<int>(bally), 20, 20);

//         flip();
//     }
// }

// // Move LEFT paddle along y axis
// void SDLGraphicsProgram::setLeftPaddleCoordinates() {
//     // Example: Move paddle based on keyboard input
//     const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
//     if (currentKeyStates[SDL_SCANCODE_W]) {
//         leftPaddleY -= 0.1f;
//     }
//     if (currentKeyStates[SDL_SCANCODE_S]) {
//         leftPaddleY += 0.1f;
//     }
// }

// // Move RIGHT paddle along y axis 
// void SDLGraphicsProgram::setRightPaddleCoordinates() {
//     // Example: Move paddle based on keyboard input
//     const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
//     if (currentKeyStates[SDL_SCANCODE_UP]) {
//         rightPaddleY -= 0.1f;
//     }
//     if (currentKeyStates[SDL_SCANCODE_DOWN]) {
//         rightPaddleY += 0.1f;
//     }
// }


// // Move BALL location (x and y values)
// void SDLGraphicsProgram::setBallCoordinates() {

//     if (ballx <= 0 || ballx >= 800) {
//         ballVX *= -1;
//     }
//     if (bally <= 0 || bally >= 600) {
//         ballVY *= -1;
//     }
// }

// // END PONG LOGIC



















// Loops
// void SDLGraphicsProgram::loop(){
//     // Main loop flag
//     // If this is quit = 'true' then the program terminates.
//     bool quit = false;
//     // Event handler that handles various events in SDL
//     // that are related to input and output
//     SDL_Event e;
//     // Enable text input
//     SDL_StartTextInput();

//     // Run the Pong game inside the loop
//     runPongGame();

//     // While application is running
//     while(!quit){
//      	 //Handle events on queue
// 		while(SDL_PollEvent( &e ) != 0){
//         	// User posts an event to quit
// 	        // An example is hitting the "x" in the corner of the window.
//     	    if(e.type == SDL_QUIT){
//         		quit = true;
// 	        }
//       	} // End SDL_PollEvent loop.

//       	//Update screen of our specified window
//       	SDL_GL_SwapWindow(getSDLWindow());
//     }

//     //Disable text input
//     SDL_StopTextInput();
// }














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
            .def(py::init<int,int>(), py::arg("w"), py::arg("h"))   // our constructor
            .def("clear", &SDLGraphicsProgram::clear) // Expose member methods
            .def("delay", &SDLGraphicsProgram::delay) 
            .def("flip", &SDLGraphicsProgram::flip) 
            // .def("loop", &SDLGraphicsProgram::loop) 
            .def("DrawRectangle", &SDLGraphicsProgram::DrawRectangle)
            // .def("runPongGame", &SDLGraphicsProgram::runPongGame)
            .def("poll", &SDLGraphicsProgram::poll)
            .def("getQuit", &SDLGraphicsProgram::getQuit) ;
// We do not need to expose everything to our users!
//            .def("getSDLWindow", &SDLGraphicsProgram::getSDLWindow, py::return_value_policy::reference) 
}
 
#endif