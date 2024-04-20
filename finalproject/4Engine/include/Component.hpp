#pragma once
#include <SDL3/SDL.h>
#include <memory>

#include "ComponentType.hpp"

// Forward declaration of GameEntity which is included in our Component
struct GameEntity;

/// Components, must know about the gameEntity that they are associated with
/// Components, must have a 'Type'
struct Component{

    Component(){
    }

    virtual ~Component(){

    }

    virtual void Input(float deltaTime){

    }
    virtual void Update(float deltaTime){

    }
    virtual void Render(SDL_Renderer* renderer){
    }

    // Must be implemented
    virtual ComponentType GetType()=0;

    void SetGameEntity(std::shared_ptr<GameEntity> g){
        mGameEntity = g;
    }

    std::shared_ptr<GameEntity> GetGameEntity(){
        return mGameEntity;
    }

    /// Some things to think about -- component communication
    /// void send(int message){}
    /// void receive(int message){}
private:
    std::shared_ptr<GameEntity> mGameEntity;

};
