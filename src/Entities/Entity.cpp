#include <Entities/Entity.hpp>

namespace Game{
    namespace Entities{

        Entity::Entity(const Vector2f position, const Vector2f size) : Being(position, size), x(position.x), y(position.y){
            cout << "Entity constructor called" << endl; //hello world
            alive = true;
        }

        Entity::Entity(const RectangleShape givenbody) : Being(givenbody){
            x = givenbody.getPosition().x;
            y = givenbody.getPosition().y;
            alive = true;
        }

        Entity::Entity(){
            cout << "Default Entity constructor called" << endl; //hello world
            x = 0;
            y = 0;
            alive = true;
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

        Vector2i Entity::getPosition() const {
            return Vector2i(x, y);
        }
    }
}