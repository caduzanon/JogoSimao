#include <Entities/Entity.hpp>

namespace Game{
    namespace Entities{

        Entity::Entity(const Vector2f position, const Vector2f size) : Being(), x(position.x), y(position.y){
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
        
        void Entity::setPosition(int new_x, int new_y) {
            x = new_x;
            y = new_y;
        }

        sf::Vector2i Entity::getPosition() const {
            return sf::Vector2i(x, y);

        }
    }
}