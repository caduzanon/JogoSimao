#include <Entities/Characters/Player.hpp>

namespace Game{
    namespace Entities{
        namespace Characters{
            Player::Player(const Vector2f position, const Vector2f size) : body(RectangleShape(size)) {
                body.setPosition(position);
                body.setFillColor(Color::Green);
                initialize();
            }

            Player::Player(const RectangleShape body) : body(body) {
                initialize();
            }

            Player::Player() : body() {
                initialize();
            }

            Player::~Player(){
                cout << "Player destructor called" << endl;
            }

            void Player::initialize(){
                velocity = Vector2f(8.0f, 8.0f);
            }

            const RectangleShape& Player::getBody() const {
                return body;
            }

            void Player::update(){
                
            }

            void Player::move(){
                //terei problemas pra fazer dois jogadores. Criar enum com as teclas dos dois?
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
            }

            void Player::save(){
                cout << "Player save() called" << endl;
            }

        }
    }
}