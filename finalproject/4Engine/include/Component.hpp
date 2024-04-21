/**
 * @file Component.hpp
 * @brief This file contains the definition of the Component struct.
 */

#pragma once

#include <SDL3/SDL.h>
#include <memory>

#include "ComponentType.hpp"

// Forward declaration of GameEntity which is included in our Component
struct GameEntity;

/**
 * @struct Component
 * @brief A struct that represents a component.
 * @details Components must know about the game entity that they are associated with and must have a 'Type'.
 */
struct Component{

    /**
     * @brief Default constructor for the Component struct.
     */
    Component(){
    }

    /**
     * @brief Destructor for the Component struct.
     */
    virtual ~Component(){

    }

    /**
     * @brief Handles input for the Component.
     * @param deltaTime The time since the last frame.
     */
    virtual void Input(float deltaTime){

    }

    /**
     * @brief Updates the Component.
     * @param deltaTime The time since the last frame.
     */
    virtual void Update(float deltaTime){

    }

    /**
     * @brief Renders the Component.
     * @param renderer The SDL_Renderer to use.
     */
    virtual void Render(SDL_Renderer* renderer){
    }

    /**
     * @brief Gets the type of the Component.
     * @return The type of the Component.
     */
    virtual ComponentType GetType()=0;

    /**
     * @brief Sets the game entity that this Component is associated with.
     * @param g The game entity to associate with this Component.
     */
    void SetGameEntity(std::shared_ptr<GameEntity> g){
        mGameEntity = g;
    }

    /**
     * @brief Gets the game entity that this Component is associated with.
     * @return The game entity that this Component is associated with.
     */
    std::shared_ptr<GameEntity> GetGameEntity(){
        return mGameEntity;
    }

    /// Some things to think about -- component communication
    /// void send(int message){}
    /// void receive(int message){}

    private:
        /**
         * @brief The game entity that this Component is associated with.
         */
        std::shared_ptr<GameEntity> mGameEntity;

};