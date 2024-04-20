#pragma once

#include <SDL3/SDL.h>
#include <unordered_map>
#include <string>

//Functor
struct TextureFunctorDeleter{
    void operator()(SDL_Texture* texture) const{
        SDL_DestroyTexture(texture);
    }
};

std::shared_ptr<SDL_Texture> make_shared_texture(SDL_Renderer* renderer, SDL_Surface* pixels){
    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(renderer, pixels);

    if(nullptr==pTexture){
        SDL_Log("Could not load texture from surface");
    }

    return std::shared_ptr<SDL_Texture>(pTexture, TextureFunctorDeleter());
}



struct ResourceManager{

    static ResourceManager& Instance(){
        if(nullptr==mInstance){
            mInstance = new ResourceManager;
        }

        return *mInstance;
    }

std::shared_ptr<SDL_Texture> LoadTexture(const std::string& filepath, SDL_Renderer* renderer){
    SDL_Log("ResourceManager::LoadTexture: 1");
    auto it = mTextureResouces.find(filepath);
    if(it == mTextureResouces.end()){
        SDL_Log("ResourceManager::LoadTexture: 2");
        SDL_Surface* pixels = SDL_LoadBMP(filepath.c_str());
        if (pixels == nullptr) {
            SDL_Log("ResourceManager::LoadTexture: Failed to load BMP file %s. SDL Error: %s", filepath.c_str(), SDL_GetError());
            return nullptr;
        }
        SDL_Log("ResourceManager::LoadTexture: 3");
        std::shared_ptr<SDL_Texture> texture = make_shared_texture(renderer,pixels);  
        SDL_Log("ResourceManager::LoadTexture: 4");          
        // insert into our map
        mTextureResouces.insert({filepath,texture});
        SDL_Log("ResourceManager::LoadTexture: 5");
        SDL_DestroySurface(pixels);
        SDL_Log("ResourceManager::LoadTexture: 6");
        SDL_Log("Created new resource %s",filepath.c_str());
        SDL_Log("ResourceManager::LoadTexture: 7");
    }
    else{
        SDL_Log("Reused resource %s",filepath.c_str());
    }
    SDL_Log("ResourceManager::LoadTexture: 8");
    return mTextureResouces[filepath];
}

    private:
        ResourceManager(){
        }

        static ResourceManager* mInstance;
        std::unordered_map<std::string, std::shared_ptr<SDL_Texture>> mTextureResouces;
};

// Initialize static variables
ResourceManager* ResourceManager::mInstance = nullptr;