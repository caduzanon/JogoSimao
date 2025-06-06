#include <Entities/Entity.hpp>

namespace Game{
    namespace Entities{
        Entity::Entity(const Vector2f position, const Vector2f size){
            cout << "Entity constructor called" << endl; //hello world

        }
        Entity::~Entity(){
            cout << "Entity destructor called" << endl; //hello world
        }
        void Entity::saveDataBuffer(){
            //hello 3
        }
        const RectangleShape Entity::getBody() const{
            //hello again
        }
    }
}