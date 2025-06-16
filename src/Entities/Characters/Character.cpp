#include <Entities/Characters/Character.hpp>
#include <iostream>

namespace Game{
    namespace Entities{
        namespace Characters{
            Character::Character() : num_lives(0), velocity(0.0f, 0.0f) {
                cout << "Default Character constructor called" << endl; //hello world
            }

            Character::Character(const Vector2f position, const Vector2f size, const Game::IDs id) : 
                Entity(position, size, id) // 1. O 'id' é passado para o construtor da Entity
            {
                velocity = Vector2f(0.0f, 0.0f);
                num_lives = 0;
                cout << "Character constructor called with position and size" << endl; //hello world
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

            Vector2f Character::getVelocity(){
                return velocity;
            }

            void Character::setVelocity(Vector2f v){
                if (v != Vector2f()){
                    velocity = v;
                }
            }
        }
    }
}