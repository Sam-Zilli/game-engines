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

    // loop poll
    void poll();

    bool getQuit();

    void setBackgroundColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

    // right Arrow commands
    bool getRightArrowUp();
    bool getRightArrowDown();

    // left Arrow commands
    bool getLeftArrowUp();
    bool getLeftArrowDown();

    bool Tilemap();



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

    bool rightArrowUp = false;
    bool rightArrowDown = false;

    // left Arrow commands
    bool leftArrowUp = false;
    bool leftArrowDown = false;

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
	
	// Initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO)< 0){
		errorStream << "SDL could not initialize! SDL Error: " << SDL_GetError() << "\n";
		success = false;
	}
	else{
	    //Create window
    	gWindow = SDL_CreateWindow(gameName, screenWidth, screenHeight, SDL_WINDOW_OPENGL);
        // Check if Window did not create.
        if( gWindow == NULL ){
			errorStream << "Window could not be created! SDL Error: " << SDL_GetError() << "\n";
			success = false;
		}

		//Create a Renderer to draw on
        gRenderer = SDL_CreateRenderer(gWindow, NULL, SDL_RENDERER_ACCELERATED);
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
    // SDL_Log("In poll");
    rightArrowDown = false;
    rightArrowUp = false;
    leftArrowUp = false;
    leftArrowDown = false;

    clear();


    // SDL_Surface* tile_map_surface = SDL_LoadBMP("src/assets/tile.bmp");
    SDL_Surface* tile_map_surface = SDL_LoadBMP("../assets/tile.bmp");
    if (tile_map_surface == nullptr) {
        SDL_Log("Failed to load BMP image: %s", SDL_GetError());

        return;
    }

    SDL_Texture* tile_texture = SDL_CreateTextureFromSurface(gRenderer, tile_map_surface);
    SDL_DestroySurface(tile_map_surface); // renamed from SDL_FreeSurface

    srand(time(NULL));

    int tilemap[40][15];

    // Assign randomly what tiles go where??
    for(int x = 0; x < 20; x++) {
        for(int y = 0; y < 15; y++) {
            // determines what tile is chosen for each 
            // (example: tilemap[x][y] = 4 % 4 + 1; puts tile "1" in every square)
            // or to randomly choose numbers 1-4:
            //  tilemap[x][y] = rand() % 4 + 1;
            tilemap[x][y] = 4 % 4 + 1;
        }
    }

    // Populating screen with tiles. Only need enough tiles to cover screen, okay to over approximate.
    SDL_FRect tile[20][15];
    for(int x = 0; x < 20; x++) {
        for(int y = 0; y < 15; y++) {
            tile[x][y].x = x*32;
            tile[x][y].y = y*32;
            tile[x][y].w = 32;
            tile[x][y].h = 32;
        }
    }

    SDL_FRect select_tile_1;
    select_tile_1.x = 0;
    select_tile_1.y = 0;
    select_tile_1.w = 32;
    select_tile_1.h = 32;

    SDL_FRect select_tile_2;
    select_tile_2.x = 32;
    select_tile_2.y = 0;
    select_tile_2.w = 32;
    select_tile_2.h = 32;

    SDL_FRect select_tile_3;
    select_tile_3.x = 0;
    select_tile_3.y = 32;
    select_tile_3.w = 32;
    select_tile_3.h = 32;

    SDL_FRect select_tile_4;
    select_tile_4.x = 32;
    select_tile_4.y = 32;
    select_tile_4.w = 32;
    select_tile_4.h = 32;


    SDL_Event event;

    while (SDL_PollEvent(&event) != 0) {
        switch (event.type) {
            case 527: // For some reason SDL_EVENT_QUIT doesn't work here.
                SDL_Log("Quit event detected");
                quit = true;
                break;
            case SDL_EVENT_KEY_DOWN:
                SDL_Log("Key pressed: %s", SDL_GetKeyName(event.key.keysym.sym));
                if(strcmp(SDL_GetKeyName(event.key.keysym.sym), "Up") == 0) {
                    rightArrowUp = true;
                }
                if(strcmp(SDL_GetKeyName(event.key.keysym.sym), "Down") == 0) {
                    rightArrowDown = true;
                }
                if(strcmp(SDL_GetKeyName(event.key.keysym.sym), "Left Option") == 0) {
                    leftArrowUp = true;
                }
                if(strcmp(SDL_GetKeyName(event.key.keysym.sym), "Z") == 0) {
                    leftArrowDown = true;
                }
            case SDL_EVENT_KEY_UP:
                SDL_Log("Key released: %s", SDL_GetKeyName(event.key.keysym.sym));
                break;
            default:
                // SDL_Log("Unknown event type: %d", event.type);
                break;
        }
    }

    SDL_SetRenderDrawColor(gRenderer, 0x66, 0x66, 0xBB, 0xFF);
    SDL_RenderClear(gRenderer);
        // Render tiles
        for(int x= 0; x<20; x++) {
            for(int y= 0; y < 15; y++) {
                switch(tilemap[x][y])
                {
                    case 1: // SDL_RenderCopy renamed SDL_RenderTexture
                        SDL_RenderTexture(gRenderer, tile_texture, &select_tile_1, &tile[x][y]);
                        break;
                    case 2:
                        SDL_RenderTexture(gRenderer, tile_texture, &select_tile_2, &tile[x][y]);
                        break;
                    case 3:
                        SDL_RenderTexture(gRenderer, tile_texture, &select_tile_3, &tile[x][y]);
                        break;
                    case 4:
                        SDL_RenderTexture(gRenderer, tile_texture, &select_tile_4, &tile[x][y]);
                        break;
                }
            }
        }

    // Render present
    SDL_RenderPresent(gRenderer);

    // Cleanup
    SDL_DestroyTexture(tile_texture);
}

// bool SDLGraphicsProgram::Tilemap(){
//     SDL_Surface* tile_map_surface = SDL_LoadBMP("../assets/tile.bpm");
//     SDL_Texture* tile_texture = SDL_CreateTextureFromSurface(gRenderer, tile_map_surface);
//     SDL_DestroySurface(tile_map_surface); // renamed from SDL_FreeSurface
//     srand(time(NULL));
//     int tilemap[20][15];

//     for(int x = 0; x < 20; x++) {
//         for(int y = 0; y < 15; y++) {
//             tilemap[x][y] = rand() % 4 + 1;
//         }
//     }

//     SDL_FRect tile[20][15];
//     for(int x = 0; x < 20; x++) {
//         for(int y = 0; y < 15; y++) {
//             tile[x][y].x = x*32;
//             tile[x][y].y = y*32;
//             tile[x][y].w = 32;
//             tile[x][y].h = 32;
//         }
//     }

//     SDL_FRect select_tile_1;
//     select_tile_1.x = 0;
//     select_tile_1.y = 0;
//     select_tile_1.w = 32;
//     select_tile_1.h = 32;

//     SDL_FRect select_tile_2;
//     select_tile_2.x = 32;
//     select_tile_2.y = 0;
//     select_tile_2.w = 32;
//     select_tile_2.h = 32;

//     SDL_FRect select_tile_3;
//     select_tile_3.x = 0;
//     select_tile_3.y = 32;
//     select_tile_3.w = 32;
//     select_tile_3.h = 32;

//     SDL_FRect select_tile_4;
//     select_tile_4.x = 32;
//     select_tile_4.y = 32;
//     select_tile_4.w = 32;
//     select_tile_4.h = 32;

//     // infinite loop runnning application
//     bool gameIsRunning = true;
//     while(gameIsRunning) {
//         SDL_Event event;

//         while(SDL_PollEvent(&event)) {
//             if(event.type == 527) {
//                 gameIsRunning = false;
//             }
//         }

//         SDL_SetRenderDrawColor(gRenderer, 0x66, 0x66, 0xBB, 0xFF);
//         SDL_RenderClear(gRenderer);

//         SDL_Delay(20);


//         // actually putting the tiles down?
//         for(int x= 0; x<20; x++) {
//             for(int y= 0; y < 15; y++) {
//                 switch(tilemap[x][y])
//                 {
//                     case 1: // SDL_RenderCopy renamed SDL_RenderTexture
//                         // SDL_RenderTexture(gRenderer, tile_texture, &select_tile_1, &tile[x][y]);
//                         break;
//                     case 2:
//                         SDL_RenderTexture(gRenderer, tile_texture, &select_tile_2, &tile[x][y]);
//                         break;
//                     case 3:
//                         SDL_RenderTexture(gRenderer, tile_texture, &select_tile_3, &tile[x][y]);
//                         break;
//                     case 4:
//                         SDL_RenderTexture(gRenderer, tile_texture, &select_tile_4, &tile[x][y]);
//                         break;
//                 }
//             }
//         }
//         // displaying in the renderer
//         SDL_RenderPresent(gRenderer);
//     }
//     // cleaning up each of the tectures
//     SDL_DestroyTexture(tile_texture);
//     return true;
// }

// Initialize OpenGL
// Setup any of our shaders here.
bool SDLGraphicsProgram::initGL(){
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
	// Nothing yet!
    SDL_SetRenderDrawColor(gRenderer, backgroundRed,backgroundGreen,backgroundBlue, backgroundAlpha);
    SDL_RenderClear(gRenderer);   
}

// The flip function gets called once per loop
// It swaps out the previvous frame in a double-buffering system
void SDLGraphicsProgram::flip(){
	// Nothing yet! 
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
    

    SDL_FRect fillRectF = {(float)x, (float)y, (float)w, (float)h};

    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    // SDL2: int SDL_RenderDrawRect(SDL_Renderer * renderer, const SDL_Rect * rect);
    // SDL3: int SDL_RenderRect    (SDL_Renderer *renderer, const SDL_FRect *rect);
    SDL_RenderRect(gRenderer, &fillRectF); 
}




bool SDLGraphicsProgram::getQuit() {
    return quit;
}

bool SDLGraphicsProgram::getRightArrowUp() {
    return rightArrowUp;
}

bool SDLGraphicsProgram::getRightArrowDown() {
    return rightArrowDown;
}

bool SDLGraphicsProgram::getLeftArrowUp() {
    return leftArrowUp;
}

bool SDLGraphicsProgram::getLeftArrowDown() {
    return leftArrowDown;
}


#endif















