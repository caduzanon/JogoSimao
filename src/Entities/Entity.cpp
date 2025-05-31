#include <Entities/Entity.hpp>

namespace Entities {
    Entity::Entity(Math::CoordsF position, Math::CoordsF size, ID id) : position(position), size(size), id(id) { } //declaração da construtora

    Entity::~Entity() { } //declaração da destrutora

    void Entity::setPosition(Math::CoordsF position) { this->position = position; }    

    void Entity::setSize(Math::CoordsF size){ this->size = size; }
    
    Math::CoordsF Entity::getPosition() const { return position; }

    Math::CoordsF Entity::getSize() const { return size; }

    ID Entity::getID() const { return id; }
}