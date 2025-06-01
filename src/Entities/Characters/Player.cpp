#include <Entities/Characters/Player.hpp>
#include <Managers/Animation.hpp>

namespace Entities{
    namespace Characters {
        Player::Player(Math::CoordsF position, bool isPlayer1) : Entity(position, Math::CoordsF(P_SIZE_X, P_SIZE_Y), ID::player) , isPlayer1(isPlayer1) { initialize(); } //constructor with defaults set
        Player::~Player(){ } //destructor empty

        void Player::update(float dt){ 
            sprite.update(Managers::Animation_ID::attack, false, position, dt); 
            position.x = position.x + 300*dt;
        };
        void Player::initialize(){
            //add animations here
            exit(1); //for tests
        }
    }
}

