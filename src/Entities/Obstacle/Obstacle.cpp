#include <Entities/Obstacles/Obstacle.hpp>

#include <iostream>

namespace Game::Entities::Obstacles {
    Obstacle::Obstacle(const Vector2f position, const Vector2f size, const Game::IDs id, bool harms) 
        : Entity(position, size, id), harmful(harms)
    {
        this->body.setPosition(position);
        this->body.setSize(size);
    }

    Obstacle::~Obstacle() {
        
    }   
}