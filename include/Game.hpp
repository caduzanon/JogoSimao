#pragma once
#include <Managers/GraphicsManager.hpp>
#include <Entities/Characters/Player.hpp>
#include <iostream>

namespace Game{
    using namespace Managers;
    using namespace Entities;
    using namespace Characters;
    class Unique{
        private:
            Player* pPlayer1;
            Player* pPlayer2;
            GraphicsManager* pGM;
        public:
            Unique();
            ~Unique();
            void update();
    };
}