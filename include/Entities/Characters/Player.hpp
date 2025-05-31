#pragma once

#include <Entities/Entity.hpp>

#define P_SIZE_X 100.0f
#define P_SIZE_Y 100.0f

namespace Entities{
    namespace Characters {
        class Player : public  Entity {
            private:
                const bool isPlayer1;
            public:
                Player(Math::CoordsF position = Math::CoordsF(0.0f, 0.0f), bool isPlayer1 = true);
                ~Player();
                void update(float dt);
                void initialize();
        };
    }
}