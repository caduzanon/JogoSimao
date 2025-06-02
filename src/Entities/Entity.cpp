#include <Entities/Entity.hpp>

namespace Game{
    namespace Entities{
        Entity::Entity(){
            cout << "Entity constructor called" << endl; //hello world
        }
        Entity::~Entity(){
            cout << "Entity destructor called" << endl; //hello world
        }
        void Entity::saveDataBuffer(){
            //hello 3
        }
    }
}