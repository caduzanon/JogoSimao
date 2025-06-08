#include <Entities/Obstacles/Platform.hpp>
#include <SFML/Graphics.hpp>

namespace Game::Entities::Obstacles {

    Platform::Platform(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color):
        Obstacle(position, size, false) 
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
    
    void Platform::draw(sf::RenderTarget& target) {
        target.draw(this->body);
    }

    void Platform::obstruct(Characters::Player* pPlayer) {
    }

}