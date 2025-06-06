#include <Entities/Entity.hpp>

namespace Game{
    namespace Entities{
<<<<<<< HEAD
        Entity::Entity(int initial_x, int initial_y): 
            Being(),                      
            x(initial_x),
            y(initial_y)        
        {
            cout << "Entity constructor called" << endl;
=======
        Entity::Entity(const Vector2f position, const Vector2f size){
            cout << "Entity constructor called" << endl; //hello world

>>>>>>> b9e18797413fa56976b46db981d33b5be10ba0a8
        }
        Entity::~Entity(){
            cout << "Entity destructor called" << endl; //hello world
        }
        void Entity::saveDataBuffer(){
            //hello 3
        }
<<<<<<< HEAD
         void Entity::setPosition(int new_x, int new_y) {
            x = new_x;
            y = new_y;
        }

         sf::Vector2i Entity::getPosition() const {
            return sf::Vector2i(x, y);
=======
        const RectangleShape Entity::getBody() const{
            //hello again
>>>>>>> b9e18797413fa56976b46db981d33b5be10ba0a8
        }
    }
}