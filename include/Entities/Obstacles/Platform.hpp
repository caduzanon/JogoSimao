#pragma once
#include <Entities/Obstacles/Obstacle.hpp>
#include <SFML/Graphics/RenderTarget.hpp> // Incluir para sf::RenderTarget
#include <SFML/Graphics/Texture.hpp>    // Incluir para sf::Texture

// Declaração antecipada de Player (melhor colocar fora da classe)
namespace Game::Entities::Characters {
    class Player;
}

namespace Game::Entities::Obstacles {
    
    class Platform : public Obstacle {
    private:
        sf::Texture platformTexture;
        void initializeTexture();

    public:
        Platform(const sf::Vector2f& position, const sf::Vector2f& size);
        ~Platform();

        // --- DECLARAÇÕES COMPLETAS DOS MÉTODOS OBRIGATÓRIOS ---

        // De Entity
        void update() override;
        void save() override;
        void draw(sf::RenderTarget& target) override;
        // void onCollision(Entity* other) override; // Opcional que você não quis

        // De Obstacle
        void obstruct(Characters::Player* pPlayer) override;
    };

} // namespace Game::Entities::Obstacles