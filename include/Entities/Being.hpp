#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
//Being - Abstract Class
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
            Image* pFig;
            RectangleShape body;
        public:
            Being(const Vector2f position, const Vector2f size);
            Being(const RectangleShape givenbody);
            Being();
            ~Being();
            virtual void update() = 0;
            RectangleShape getBody();
            static void setGM(Managers::GraphicsManager* pointerGM);
    };
}