#include <Entities/Characters/Player.hpp>
#include <Managers/AnimationManager.hpp>

namespace Entities{
    namespace Characters {
        Player::Player(Math::CoordsF position, bool isPlayer1) : Entity(position, Math::CoordsF(P_SIZE_X, P_SIZE_Y), ID::player) , isPlayer1(isPlayer1) { 
            initialize();
            time = 0;
        } //constructor with defaults set
        Player::~Player(){ } //destructor empty

        void Player::update(float dt){ 
            time += dt;
            if (time < 3){
                sprite.update(Managers::Animation_ID::walk, true, position, dt); 
                position.x = position.x + 200*dt;
            }
            else if (time < 6){
                sprite.update(Managers::Animation_ID::idle, true, position, dt); 
            }
        }

        void Player::initialize(){
            //add animations here
            exit(1); //for tests
        }
    }
}

