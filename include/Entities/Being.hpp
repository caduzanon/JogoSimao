#pragma once
//#include <Managers/GraphicsManager.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
//Skeleton of Being - Abstract Class
using namespace std;
using namespace sf;

/*
TODO:
using namespace Entities;
using namespace Lists;
using namespace Levels; 
*/

namespace Game{  

    namespace Managers{
        class GraphicsManager;
    }
    class Being{
        protected:
            int id;
            static Managers::GraphicsManager* pGM;
            sf::Image* pFig;
            RectangleShape* shape;
        public:
            Being();
            ~Being();
            virtual void update() = 0;
            void render();
            RectangleShape* getShape();
            static void setGM(Managers::GraphicsManager* pointerGM);
    };
}