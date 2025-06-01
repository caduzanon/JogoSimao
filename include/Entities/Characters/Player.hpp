#pragma once
#include <iostream>
#include <Unique.hpp>

using namespace sf;

namespace Game{
    namespace Player{
        class Player{
            private:
                RectangleShape body;
                Vector2u velocity;
                void initialize();
            public:
                Player(const Vector2f position, const Vector2f size);
                ~Player();
                const RectangleShape getBody();
                void move();
        };
    }
}

