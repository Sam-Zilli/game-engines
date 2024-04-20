#ifndef SDLGRAPHICSPROGRAM_HPP
#define SDLGRAPHICSPROGRAM_HPP

#include <SDL3/SDL.h>

class SDLGraphicsProgram {
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

    // Get Pointer to Window
    SDL_Window* getSDLWindow();

    // Draw a simple rectangle
    void DrawRectangle(int x, int y, int w, int h);

    // Loop poll
    void poll();

    bool getQuit();

    void setBackgroundColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

    // Right Arrow commands
    bool getRightArrowUp();
    bool getRightArrowDown();

    // Left Arrow commands
    bool getLeftArrowUp();
    bool getLeftArrowDown();

private:
    int screenWidth;
    int screenHeight;
    const char* gameName;

    // The window we'll be rendering to
    SDL_Window* gWindow;

    // Our renderer
    SDL_Renderer* gRenderer;

    Uint8 backgroundRed;
    Uint8 backgroundGreen;
    Uint8 backgroundBlue;
    Uint8 backgroundAlpha;

    bool quit;

    // Right Arrow commands
    bool rightArrowUp;
    bool rightArrowDown;

    // Left Arrow commands
    bool leftArrowUp;
    bool leftArrowDown;
};

#endif
