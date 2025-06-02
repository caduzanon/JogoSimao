#pragma once
#include <iostream>
#include <Character.hpp>

namespace Game{
    namespace Entities{
        namespace Characters{
            class Player : public Character{
                private:
                    int points;
                    RectangleShape body;
                    Vector2u velocity;
                    void initialize();
                public:
                    Player(const Vector2f position, const Vector2f size);
                    ~Player();
                    const RectangleShape getBody();
                    void update();
                    void move();
                    void save();
            };
        }
    }
}

