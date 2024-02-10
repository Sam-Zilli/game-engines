#pragma once
#include <SDL3/SDL.h>
#include <memory>
#include <string>
#include "Component.hpp"

struct SpriteComponent : public Component {
    SpriteComponent();

	void CreateSpriteComponent(SDL_Renderer* renderer, std::string filepath);

    ~SpriteComponent();

	void Update(float deltaTime) override; // needs override bc inherited from Component
	void Render(SDL_Renderer* renderer);

    void SetW(float w);

    void SetX(float x);
    void SetY(float y);

    float GetX() const;
    float GetY() const;

    void Move(float x, float y);

    SDL_FRect GetRectangle() const;

	private:
		SDL_FRect mRectangle{20.0f,20.0f,32.0f,32.0f};
        std::shared_ptr<SDL_Texture> mTexture;
};
