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
        }
    }
}