#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

namespace Managers{
    class GraphicsManager{
        private:
            RenderWindow* window;
            //Singleton
            static GraphicsManager* instance;
            GraphicsManager();
        public:
            ~GraphicsManager();
            static GraphicsManager* getInstance();
            RenderWindow* getWindow();
            void renderBeing(RectangleShape* body);
            void renderBeing(const RectangleShape* body);
            void display();
            void clearWindow();
            bool isWindowOpen() const;
            void closeWindow();
    };
}
