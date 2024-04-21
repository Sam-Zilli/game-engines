#pragma once

#include <SDL3/SDL.h>
#include <unordered_map>
#include <string>
#include <memory>

//Functor
struct TextureFunctorDeleter{
    void operator()(SDL_Texture* texture) const{
        SDL_DestroyTexture(texture);
    }
};

// Function Declarations
std::shared_ptr<SDL_Texture> make_shared_texture(SDL_Renderer* renderer, SDL_Surface* pixels);

struct ResourceManager{

    static ResourceManager& Instance(){
        if(nullptr==mInstance){
            mInstance = new ResourceManager;
        }

        return *mInstance;
    }

    std::shared_ptr<SDL_Texture> LoadTexture(SDL_Renderer* renderer, std::string filepath){

        // C++ 20 -- just use contains
        //  If you don't have C++ 20, then you use 'find'
        //  - if mTextureResouces.find(filepath) != mTextureResouces.end()){...}
        if(!mTextureResouces.contains(filepath)){
            SDL_Surface* pixels = SDL_LoadBMP(filepath.c_str());
            SDL_SetSurfaceColorKey(pixels,SDL_TRUE,SDL_MapRGB(pixels->format,0xFF,0,0xFF));
            std::shared_ptr<SDL_Texture> texture = make_shared_texture(renderer,pixels);            
            // insert into our map
            mTextureResouces.insert({filepath,texture});
//            mTextureResouces[filepath] = texture; // Another alternative

            SDL_DestroySurface(pixels);
            SDL_Log("Created new resource %s",filepath.c_str());
        }
        else{
            SDL_Log("Reused resource %s",filepath.c_str());
        }

        return mTextureResouces[filepath];
    }

    private:
        ResourceManager(){
        }

        /// NOTE: You can inline which is sort of easier
        //        to deal with, though I am exposing some
        //        information to whoever see this .hpp file.
        inline static ResourceManager* mInstance{nullptr};

        // Store our texture resources
        std::unordered_map<std::string, std::shared_ptr<SDL_Texture>> mTextureResouces;
};