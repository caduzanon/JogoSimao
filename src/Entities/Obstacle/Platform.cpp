#include <Entities/Obstacles/Platform.hpp>
#include <SFML/Graphics.hpp>

namespace Game::Entities::Obstacles {

    Platform::Platform(const sf::Vector2f position, const sf::Vector2f size) :
        Obstacle(position, size, false) 
    {
        this->body.setPosition(position);
        this->body.setSize(size);
        this->body.setFillColor(sf::Color(150, 75, 0));
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

    void Platform::obstruct(Characters::Player* pPlayer) {
    }

}