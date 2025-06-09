#pragma once
#include <iostream>
#include <Entities/Characters/Character.hpp>

/**
 * @brief Essa classe é essencial
 */
namespace Game{
    namespace Entities{
        namespace Characters{
            class Player : public Character{
                private:
                    int player_id;
                protected:
                    int points;
                    bool isPlayer1;
                    void initialize();
                public:
                    Player(const Vector2f position, const Vector2f size, bool isPlayer1, const Game::IDs id = Game::IDs::Player1);
                    Player(const RectangleShape givenbody);
                    Player();
                    ~Player() override;
                    void render(sf::RenderTarget& target) override;
                    void update() override;
                    void save() override;
            };
        }
    }
}

