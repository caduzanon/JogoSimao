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
                    int points;
                    bool isPlayer1;
                    RectangleShape body;
                    Vector2f velocity;
                    void initialize();
                public:
                    Player(const Vector2f position, const Vector2f size, bool isPlayer1);
                    Player(const RectangleShape body);
                    Player();
                    ~Player();
                    const RectangleShape& getBody() const; //const tava me pegando
                    void update();
                    void move();
                    void save();
            };
        }
    }
}

