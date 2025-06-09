#include <Entities/Characters/Character.hpp>
#include <iostream>

namespace Game{
    namespace Entities{
        namespace Characters{
            Character::Character(){
                cout << "Default Character constructor called" << endl; //hello world
                num_lives = 0;
                velocity = Vector2f(0.0f, 0.0f);
            }

            Character::Character(const Vector2f position, const Vector2f size) : Entity(position, size){
                velocity = Vector2f(0.0f, 0.0f);
                num_lives = 0;
            }

            Character::Character(const RectangleShape givenbody) : Entity(givenbody){
                velocity = Vector2f(0.0f, 0.0f);
                num_lives = 0;
            }

            Character::~Character(){
                cout << "Character destructor called" << endl; //hello world
            }
            void Character::saveDataBuffer(){
                //hello world
            }
        }
    }
}