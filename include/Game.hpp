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
<<<<<<< HEAD
            sf::Clock totalTimeClock;
=======
>>>>>>> b9e18797413fa56976b46db981d33b5be10ba0a8
        public:
            Game();
            ~Game();
            void update();
    };
}