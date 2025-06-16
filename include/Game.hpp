#pragma once
#include <Managers/GraphicsManager.hpp>
#include <Managers/CollisionManager.hpp>
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
    using namespace Lists;
    class Game{
        private:
            //Player* pPlayer1;
            //Player* pPlayer2;
            GraphicsManager* pGM;
            CollisionManager* pCM;
            EventsManager* pEM;
            EntityList entityList;
            EntityList platList;
            Clock totalTimeClock;
        public:
            Game();
            ~Game();
            void update();
    };
}