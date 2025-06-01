#include <Managers/GraphicsManager.hpp>
#include <cstring>
#include <iostream>

#define VIDEO_W 1900
#define VIDEO_H 1000
#define FRAMERATE 120

namespace Managers{
    //Singleton
    GraphicsManager* GraphicsManager::instance = NULL;

    GraphicsManager* GraphicsManager::getInstance(){
        if (instance == NULL)
            instance = new GraphicsManager();
            cout << "Created GM at " << instance << endl;
        return instance;
    }

    GraphicsManager::GraphicsManager() : window(new RenderWindow(VideoMode(VIDEO_W, VIDEO_H), "Game", Style::Default)){
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

    void GraphicsManager::render(RectangleShape* body){
        window->draw(*body);
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
        return window->isOpen();
    }

    void GraphicsManager::closeWindow(){
        window->close();
    }
}