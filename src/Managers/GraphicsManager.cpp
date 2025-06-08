#include <Managers/GraphicsManager.hpp>
#include <Entities/Being.hpp>
#include <cstring>
#include <iostream>

#define VIDEO_W 1900
#define VIDEO_H 1000
#define FRAMERATE 180
namespace Game{
    namespace Managers{
        //Singleton
        GraphicsManager* GraphicsManager::instance = nullptr;

        GraphicsManager* GraphicsManager::getInstance(){
            if (instance == nullptr)
                instance = new GraphicsManager();
                cout << "Created GM at " << instance << endl;
            return instance;
        }

        GraphicsManager::GraphicsManager() : window(new RenderWindow(VideoMode(VIDEO_W, VIDEO_H), "Game", Style::Default)){
            window->setFramerateLimit(FRAMERATE);
            cout << "GM constructor called" << endl;
        }

        RenderWindow* GraphicsManager::getWindow(){
            return window;
        }

        GraphicsManager::~GraphicsManager(){
            cout << "GM destructor called" << endl;
            clearWindow();
            delete(window);
        }

        void GraphicsManager::display(){
            if(isWindowOpen()){
                window->display();
            }
        }

        void GraphicsManager::clearWindow(){
            if (isWindowOpen()){
                window->clear();
            }
        }

        bool GraphicsManager::isWindowOpen() const{
            if(window)
                return window->isOpen();
            return false;
        }

        void GraphicsManager::closeWindow(){
            if(window) 
                window->close();
        }
    }
}