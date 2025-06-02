#pragma once
#include <Managers/GraphicsManager.hpp>

//Skeleton of Being - Abstract Class
using namespace std;
using namespace Managers;
/*
TODO:
using namespace Entities;
using namespace Lists;
using namespace Levels; */

namespace Game{
    class Being{
        protected:
            int id;
            static GraphicsManager* pGM;
            sf::Image* pFig;
        public:
            Being();
            ~Being();
            virtual void update() = 0;
            void draw();
            static void setGM(GraphicsManager* pGM);
    };
}