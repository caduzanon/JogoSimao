#include <Entities/Characters/Player.hpp>
#include <Managers/EventsManager.hpp>

namespace Game{
    namespace Entities{
        namespace Characters{
            Player::Player(const Vector2f position, const Vector2f size, bool isPlayer1, const Game::IDs id ) 
                : Character(position, size, id), isPlayer1(isPlayer1) {
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
                pEM->removeObserver(this);
            }

            void Player::initialize(){
                if(isPlayer1){
                    velocity = Vector2f(5.0f, 5.0f);
                }else{
                    velocity = Vector2f(7.0f, 7.0f);
                }
                pEM->addObserver(this);
            }

            void Player::update(){
                sf::Vector2f movement(0.f, 0.f);
                // Player 1 checks its keys
                if (isPlayer1) {
                    if (pressedKeys.count(sf::Keyboard::W)) movement.y -= velocity.y;
                    if (pressedKeys.count(sf::Keyboard::S)) movement.y += velocity.y;
                    if (pressedKeys.count(sf::Keyboard::A)) movement.x -= velocity.x;
                    if (pressedKeys.count(sf::Keyboard::D)) movement.x += velocity.x;
                } 
                // Player 2 checks its keys independently
                else { 
                    if (pressedKeys.count(sf::Keyboard::Up))    movement.y -= velocity.y;
                    if (pressedKeys.count(sf::Keyboard::Down))  movement.y += velocity.y;
                    if (pressedKeys.count(sf::Keyboard::Left))  movement.x -= velocity.x;
                    if (pressedKeys.count(sf::Keyboard::Right)) movement.x += velocity.x;
                }

                body.move(movement);
            }

            void Player::notifyKeyPressed(sf::Keyboard::Key key) {
                pressedKeys.insert(key);
            }

            void Player::notifyKeyReleased(sf::Keyboard::Key key) {
                pressedKeys.erase(key);
            }

            void Player::render(sf::RenderTarget& target) {
                target.draw(this->body);
            }
            void Player::save(){
                cout << "Player save() called" << endl;
            }

            void Player::collide(Entity* otherEnt, Vector2f ds){
                switch(otherEnt->get_id()){
                    case((int)IDs::Player1):{
                        
                    }
                        break;
                    case((int)IDs::Player2):{

                    }
                        break;
                    case((int)IDs::Platform):{
                        cout << "Platform hit player!" << endl;
                    }
                }
            }
        }
    }
}