#include <Entities/Characters/Player.hpp>

namespace Game{
    namespace Entities{
        namespace Characters{
            Player::Player(const Vector2f position, const Vector2f size, bool isPlayer1) : isPlayer1(isPlayer1), Character(position, size) {
                if (isPlayer1)
                    body.setFillColor(Color::Green);
                else
                    body.setFillColor(Color::Cyan);
                initialize();
            }

            Player::Player(const RectangleShape givenbody) : Character(givenbody){
                initialize();
            }

            Player::Player(){
                initialize();
            }

            Player::~Player(){
                cout << "Player destructor called" << endl;
            }

            void Player::initialize(){
                if(isPlayer1){
                    velocity = Vector2f(8.0f, 8.0f);
                }else{
                    velocity = Vector2f(10.0f, 10.0f);
                }
            }

            void Player::update(){
                if(isPlayer1){
                    if(Keyboard::isKeyPressed(Keyboard::A)){
                        body.move(-velocity.x, 0.0f);
                    }
                    else if(Keyboard::isKeyPressed(Keyboard::D)){
                        body.move(velocity.x, 0.0f);
                    }
                    else if(Keyboard::isKeyPressed(Keyboard::W)){
                        body.move(0.0f, -velocity.y);
                    }
                    else if(Keyboard::isKeyPressed(Keyboard::S)){
                        body.move(0.0f, velocity.y);
                    }
                } else{
                    if(Keyboard::isKeyPressed(Keyboard::Left)){
                        body.move(-velocity.x, 0.0f);
                    }
                    else if(Keyboard::isKeyPressed(Keyboard::Right)){
                        body.move(velocity.x, 0.0f);
                    }
                    else if(Keyboard::isKeyPressed(Keyboard::Up)){
                        body.move(0.0f, -velocity.y);
                    }
                    else if(Keyboard::isKeyPressed(Keyboard::Down)){
                        body.move(0.0f, velocity.y);
                    }
                }
            }
            void Player::render(sf::RenderTarget& target) {
                target.draw(this->body);
            }
            void Player::save(){
                cout << "Player save() called" << endl;
            }

        }
    }
}