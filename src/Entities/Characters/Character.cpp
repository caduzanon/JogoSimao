#include <Entities/Characters/Character.hpp>
#include <iostream>

namespace Game{
    namespace Entities{
        namespace Characters{
            Character::Character(){
                cout << "Character constructor called" << endl; //hello world
            }
            Character::~Character(){
                cout << "Character destructor called" << endl; //hello world
            }
            void saveDataBuffer(){
                //hello world
            }
<<<<<<< HEAD
=======
            const RectangleShape& Character::getBody() const {
                return body;
            }
>>>>>>> b9e18797413fa56976b46db981d33b5be10ba0a8
        }
    }
}