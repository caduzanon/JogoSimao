#pragma once
#include <Managers/GraphicsManager.hpp>
#include <Entities/Characters/Player.hpp>
#include <iostream>
#include <Lists/EntityList.hpp>
#include <vector>                           // <<< ADICIONE ESTA LINHA
#include <Entities/Obstacles/Platform.hpp>  // <<< ADICIONE ESTA LINHA

namespace Game{
    using namespace Managers;
    using namespace Entities;
    using namespace Characters;
    using namespace Obstacles;
    class Game{
        private:
            //Player* pPlayer1;
            //Player* pPlayer2;
            GraphicsManager* pGM;
            Lists::EntityList entityList;
            std::vector<Obstacles::Platform*> platform;
            sf::Clock totalTimeClock;
        public:
            Game();
            ~Game();
            void update();
    };
}