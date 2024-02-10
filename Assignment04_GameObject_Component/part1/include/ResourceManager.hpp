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

        static ResourceManager* mInstance;
        std::unordered_map<std::string, std::shared_ptr<SDL_Texture>> mTextureResouces;
};

// Initialize static variables
ResourceManager* ResourceManager::mInstance = nullptr;




// #pragma once

// #include <SDL3/SDL.h>
// #include <unordered_map>
// #include <string>
// #include <dirent.h>

// //Functor
// struct TextureFunctorDeleter{
//     void operator()(SDL_Texture* texture) const{
//         SDL_DestroyTexture(texture);
//     }
// };

// std::shared_ptr<SDL_Texture> make_shared_texture(SDL_Renderer* renderer, SDL_Surface* pixels){
//     SDL_Texture* pTexture = SDL_CreateTextureFromSurface(renderer, pixels);

//     if(nullptr==pTexture){
//         SDL_Log("Could not load texture from surface");
//     }

//     return std::shared_ptr<SDL_Texture>(pTexture, TextureFunctorDeleter());
// }


// struct ResourceManager{

//     static ResourceManager& Instance(){
//         if(nullptr==mInstance){
//             mInstance = new ResourceManager;
//         }

//         return *mInstance;
//     }

// //     std::shared_ptr<SDL_Texture> LoadTexture(SDL_Renderer* renderer, std::string filepath){

// //         // C++ 20 -- just use contains
// //         //  If you don't have C++ 20, then you use 'find'
// //         //  - if mTextureResouces.find(filepath) != mTextureResouces.end()){...}
// //         if(!mTextureResouces.contains(filepath)){
// //             SDL_Surface* pixels = SDL_LoadBMP(filepath.c_str());
// //             SDL_SetSurfaceColorKey(pixels,SDL_TRUE,SDL_MapRGB(pixels->format,0xFF,0,0xFF));
// //             std::shared_ptr<SDL_Texture> texture = make_shared_texture(renderer,pixels);            
// //             // insert into our map
// //             mTextureResouces.insert({filepath,texture});
// // //            mTextureResouces[filepath] = texture; // Another alternative

// //             SDL_DestroySurface(pixels);
// //             SDL_Log("Created new resource %s",filepath.c_str());
// //         }
// //         else{
// //             SDL_Log("Reused resource %s",filepath.c_str());
// //         }

// //         return mTextureResouces[filepath];
// //     }


// std::shared_ptr<SDL_Texture> LoadTexture(SDL_Renderer* renderer, const std::string& filepath) {
//     // Check if the resource is already loaded
//     if (mTextureResources.contains(filepath)) {
//         SDL_Log("Reused resource %s", filepath.c_str());
//         return mTextureResources[filepath];
//     }

//     // Load the image
//     SDL_Surface* pixels = SDL_LoadBMP(filepath.c_str());

// std::string directoryPath = "./assets/";  // Adjust the directory path as needed

//     // Print the contents of the directory
//     DIR* dir = opendir(directoryPath.c_str());
//     if (dir) {
//         SDL_Log("Contents of directory %s:", directoryPath.c_str());
//         struct dirent* entry;
//         while ((entry = readdir(dir)) != nullptr) {
//             SDL_Log("%s", entry->d_name);
//         }
//         closedir(dir);
//     } else {
//         SDL_Log("Failed to open directory %s", directoryPath.c_str());
//     }


//     // Check if the image loading was successful
//     if (!pixels) {
//         SDL_Log("Failed to load image from %s: %s", filepath.c_str(), SDL_GetError());
//         return nullptr;  // Return nullptr to indicate an error
//     }

//     // Set color key
//     SDL_SetSurfaceColorKey(pixels, SDL_TRUE, SDL_MapRGB(pixels->format, 0xFF, 0, 0xFF));

//     // Create texture
//     std::shared_ptr<SDL_Texture> texture = make_shared_texture(renderer, pixels);

//     // Check if texture creation was successful
//     if (!texture) {
//         SDL_Log("Failed to create texture from image %s", filepath.c_str());
//         SDL_DestroySurface(pixels);  // Free the surface before returning
//         return nullptr;  // Return nullptr to indicate an error
//     }

//     // Insert into the map
//     mTextureResources.insert({filepath, texture});
//     SDL_Log("Created new resource %s", filepath.c_str());

//     // Free the surface now that the texture has been created
//     SDL_DestroySurface(pixels);

//     return texture;
// }


//     private:
//         ResourceManager(){
//         }

//         static ResourceManager* mInstance;
//         std::unordered_map<std::string, std::shared_ptr<SDL_Texture>> mTextureResources;
// };

// // Initialize static variables
// ResourceManager* ResourceManager::mInstance = nullptr;
