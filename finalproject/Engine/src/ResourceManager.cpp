#include "ResourceManager.hpp"

/**
 * @brief Creates a shared pointer to an SDL_Texture from an SDL_Surface
 * @param renderer The SDL_Renderer used for creating the texture
 * @param pixels The SDL_Surface containing the pixel data
 * @return A shared pointer to the created SDL_Texture
 */
std::shared_ptr<SDL_Texture> make_shared_texture(SDL_Renderer* renderer, SDL_Surface* pixels){
    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(renderer, pixels);

    if(nullptr==pTexture){
        SDL_Log("Could not load texture from surface");
    }

    return std::shared_ptr<SDL_Texture>(pTexture, TextureFunctorDeleter());
}