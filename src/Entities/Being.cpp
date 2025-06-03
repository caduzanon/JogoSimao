#include <Entities/Being.hpp>
#include <Managers/GraphicsManager.hpp>
#include <iostream>

//Game::Managers::GraphicsManager* Game::Being::pGM = nullptr;

namespace Game{
    Managers::GraphicsManager* Being::pGM = nullptr;
    Being::Being(){
        cout << "Being constructor called" << endl;
        shape = nullptr;
    }
    Being::~Being(){
        cout << "Being destructor called" << endl;
    }
    void Being::setGM(Managers::GraphicsManager* pointerGM){
        if (pointerGM != NULL)
            pGM = pointerGM;
    }
    void Being::render(){
        if(pGM)
            pGM->renderBeing(this);
    }
    RectangleShape* Being::getShape(){
        if(shape != nullptr){
            return shape;
        }
        return nullptr;
    }
}