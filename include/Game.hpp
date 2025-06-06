#pragma once
#include <Managers/GraphicsManager.hpp>
#include <Entities/Characters/Player.hpp>
#include <iostream>

namespace Game{
    using namespace Managers;
    using namespace Entities;
    using namespace Characters;
    class Game{
        private:
            Player* pPlayer1;
            Player* pPlayer2;
            GraphicsManager* pGM;
            sf::Clock totalTimeClock;
        public:
            Game();
            ~Game();
            void update();
    };
}