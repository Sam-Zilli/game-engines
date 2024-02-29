#pragma once

#include <SDL3/SDL.h>
#include <memory>
#include <string>

#include "Component.hpp"

struct InputComponent : public Component{
    InputComponent();

    ~InputComponent();

    ComponentType GetType() override;

	void Input(float deltaTime) override;

	void Update(float deltaTime) override;

	void Render(SDL_Renderer* renderer) override;

	private:
        float mSpeed{150.0f};
};
