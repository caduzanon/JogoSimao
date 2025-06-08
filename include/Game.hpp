#pragma once
#include <Managers/GraphicsManager.hpp>
#include <Entities/Characters/Player.hpp>
#include <iostream>
#include <Lists/EntityList.hpp>
#include <vector>                        
#include <Entities/Obstacles/Platform.hpp>  

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
            RenderWindow* window;
        public:
            Game();
            ~Game();
            void update();
    };
}