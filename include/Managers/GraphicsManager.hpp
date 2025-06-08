#pragma once
#include <SFML/Graphics.hpp>
//#include <Entities/Being.hpp>
#include <iostream>

using namespace sf;
using namespace std;


namespace Game{
    class Being;
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
                void display();
                void clearWindow();
                bool isWindowOpen() const;
                void closeWindow();
        };
    }
}