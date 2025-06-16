#include <Entities/Obstacles/Platform.hpp>
#include <SFML/Graphics.hpp>

namespace Game::Entities::Obstacles {

    Platform::Platform(const sf::Vector2f position, const sf::Vector2f size, const Color color, const Game::IDs id) :
        Obstacle(position, size, id, false) 
    {
        this->body.setPosition(position);
        this->body.setSize(size);
        this->body.setFillColor(color);
    }

    Platform::~Platform() {
    }

    void Platform::update() {
    }

    void Platform::save() {
    }

    void Platform::render(sf::RenderTarget& target) {
        target.draw(this->body); //draw is for SF functions. render is in most of our own functions
    }

    void Platform::obstruct(Vector2f ds, Characters::Character* pChar) {
        Vector2i charPos = pChar->getPosition();
        Vector2f charSize = pChar->getBody().getSize();
        Vector2f charSpeed = pChar->getVelocity();
        if(ds.x < 0.0f && ds.y < 0.0f){ //houve colisao
            if(ds.x > ds.y){
                if(charPos.x < x){ //colisão em x
                    charPos.x += ds.x;
                } else {
                    charPos.x -= ds.x;
                }
                charSpeed.x = 0.0f;
            } else {
                if(charPos.y < y){ //colisão em y
                    charPos.y += ds.y;
                    if(pChar->get_id() == (int)IDs::Player1 || pChar->get_id() == (int)IDs::Player2){
                        //Player* pPlayer = static_cast<Player*>(pChar);
                        //pPlayer->podePular(); we don't have this
                    }
                } else {
                    charPos.y -= ds.y;
                }
                charSpeed.y = 0.0f;
            }
        }
        pChar->setPosition(charPos.x, charPos.y);
        pChar->setVelocity(charSpeed);
    }

    void Platform::collide(Entity* otherEnt, Vector2f ds){
        cout << "Platform Collide called!" << endl;
        if(otherEnt->get_id() == (int)IDs::Player1 || 
        otherEnt->get_id() == (int)IDs::Player2 || 
        otherEnt->get_id() == (int)IDs::Dragon || 
        otherEnt->get_id() == (int)IDs::Skeleton ||
        otherEnt->get_id() == (int)IDs::Sorcerer){
            cout << "Platform Obstruct called!" << endl;
            obstruct(ds, static_cast<Character*>(otherEnt));
        }
        else if (otherEnt->get_id() == (int)IDs::Projectile){
            //projectile hits platform
        }
        }

}