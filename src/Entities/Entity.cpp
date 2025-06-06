#include <Entities/Entity.hpp>

namespace Game{
    namespace Entities{
        Entity::Entity(int initial_x, int initial_y): 
            Being(),                      
            x(initial_x),
            y(initial_y)        
        {
            cout << "Entity constructor called" << endl;
        }
        Entity::~Entity(){
            cout << "Entity destructor called" << endl; //hello world
        }
        void Entity::saveDataBuffer(){
            //hello 3
        }
         void Entity::setPosition(int new_x, int new_y) {
            x = new_x;
            y = new_y;
        }

         sf::Vector2i Entity::getPosition() const {
            return sf::Vector2i(x, y);
        }
    }
}