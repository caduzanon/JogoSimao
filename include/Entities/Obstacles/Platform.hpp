#pragma once
#include <Entities/Obstacles/Obstacle.hpp>
#include <SFML/Graphics/RenderTarget.hpp> 
#include <SFML/Graphics/Texture.hpp>    
namespace Game::Entities::Characters {
    class Player;
}
namespace Game::Entities::Obstacles {
    
    class Platform : public Obstacle {
    private:
        sf::Texture platformTexture;
        void initializeTexture();

    public:
        Platform(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color);
        ~Platform();
        void update() override;
        void save() override;
        void draw(sf::RenderTarget& target) override;
        void obstruct(Characters::Player* pPlayer) override;
    };
}