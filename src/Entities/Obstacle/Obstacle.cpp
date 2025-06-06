#include <Entities/Obstacles/Obstacle.hpp>

#include <iostream>

namespace Game::Entities::Obstacles {
    Obstacle::Obstacle(const sf::Vector2f& position, const sf::Vector2f& size, bool damage) 
        : Entity(static_cast<int>(position.x), static_cast<int>(position.y)), isdamage(damage)
    {
        this->shape->setPosition(position);
        this->shape->setSize(size);
    }

    Obstacle::~Obstacle() {
        
    }
}