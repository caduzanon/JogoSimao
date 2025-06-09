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
                protected:
                    int points;
                    bool isPlayer1;
                    void initialize();
                public:
                    Player(const Vector2f position, const Vector2f size, bool isPlayer1);
                    Player(const RectangleShape givenbody);
                    Player();
                    void render(sf::RenderTarget& target) override;
                    ~Player();
                    void update();
                    void save();
            };
        }
    }
}

