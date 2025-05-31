#include <Entities/Characters/Player.hpp>
namespace Entities{
    namespace Characters {
        Player::Player(Math::CoordsF position, bool isPlayer1) : Entity(position, Math::CoordsF(P_SIZE_X, P_SIZE_Y), ID::player) , isPlayer1(isPlayer1) { } //constructor with defaults set
        Player::~Player(){ } //destructor empty

        void Player::update(float dt){ }
        void Player::initialize(){
            exit(1); //for tests
        }
    }
}

