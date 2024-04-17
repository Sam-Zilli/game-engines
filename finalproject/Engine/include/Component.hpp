#pragma once
#include <SDL3/SDL.h>
struct Component {

    Component() { // Constructor

    }

    virtual ~Component() { // Destructor

    }

    virtual void Input(float deltaTime) {

    }

    virtual void Update(float deltaTime) {

    }

    virtual void Render(SDL_Renderer* renderer) {

    }
};