#pragma once
#include <Entities/Obstacles/Obstacle.hpp>

namespace Game::Entities::Obstacles {
    using namespace Characters;
    class Platform : public Obstacle {
    private:
        void initializeTexture();

    public:
        Platform(const Vector2f position, const Vector2f size, const sf::Color color, const Game::IDs id);
        ~Platform();

        // heranças de Entity
        void update() override;
        void save() override;
        void render(RenderTarget& target) override;
        //void onCollision(Entity* other) override; //this does NOT go in here. it belongs in CollisionManager.
        // heranças de Obstacle
        void obstruct(Characters::Player* pPlayer) override;
    };

} // namespace Game::Entities::Obstacles
