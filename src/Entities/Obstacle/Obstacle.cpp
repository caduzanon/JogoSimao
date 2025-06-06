#include <Entities/Obstacles/Obstacle.hpp>

#include <iostream>

namespace Game::Entities::Obstacles {
    Obstacle::Obstacle(const Vector2f position, const Vector2f size, bool harms) 
        : Entity(position, size), harmful(harms)
    {
        this->body.setPosition(position);
        this->body.setSize(size);
    }

    Obstacle::~Obstacle() {
        
    }
}