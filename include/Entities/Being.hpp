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
            RectangleShape body;
        public:
            Being(const Vector2f position, const Vector2f size);
            Being(const RectangleShape givenbody);
            Being();
            ~Being();
            virtual void update() = 0;
            void render();
            RectangleShape getBody();
            static void setGM(Managers::GraphicsManager* pointerGM);
    };
}