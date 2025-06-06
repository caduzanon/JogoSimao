#pragma once
#include <iostream>
#include <Entities/Characters/Character.hpp>

namespace Game{
    namespace Entities{
        namespace Characters{
            class Player : public Character{
                private:
                    int points;
                    bool isPlayer1;
                    void initialize();
                public:
                    Player(const Vector2f position, const Vector2f size, bool isPlayer1);
                    Player(const RectangleShape givenbody);
                    Player();
                    ~Player();
                    void update();
                    void move();
                    void save();
            };
        }
    }
}

