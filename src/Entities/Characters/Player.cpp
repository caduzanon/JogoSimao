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
                Managers::EventsManager::getInstance()->removeObserver(this);
            }

            void Player::initialize(){
                if(isPlayer1){
                    velocity = Vector2f(8.0f, 8.0f);
                }else{
                    velocity = Vector2f(10.0f, 10.0f);
                }
                Managers::EventsManager::getInstance()->addObserver(this);
            }

            void Player::update(){
            }

            void Player::notifyKeyPressed(sf::Keyboard::Key key) {
                if (isPlayer1) {
                  cout << "Player 1 key pressed: " << key << endl;
                  if(key == Keyboard::A){
                        body.move(-velocity.x, 0.0f);
                    }
                    else if(key == Keyboard::D){
                        body.move(velocity.x, 0.0f);
                    }
                    else if(key == Keyboard::W){
                        body.move(0.0f, -velocity.y);
                    }
                    else if(key == Keyboard::S){
                        body.move(0.0f, velocity.y);
                    }
                } else { // Player 2 controls   
                    if(key == Keyboard::Left){
                        body.move(-velocity.x, 0.0f);
                    }
                    else if(key == Keyboard::Right){
                        body.move(velocity.x, 0.0f);
                    }
                    else if(key == Keyboard::Up){
                        body.move(0.0f, -velocity.y);
                    }
                    else if(key == Keyboard::Down){
                        body.move(0.0f, velocity.y);
                    }
                }
            }

            void Player::notifyKeyReleased(sf::Keyboard::Key key) {
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