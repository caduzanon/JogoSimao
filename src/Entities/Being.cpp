#include <Entities/Being.hpp>
#include <Managers/GraphicsManager.hpp>
#include <iostream>

//Game::Managers::GraphicsManager* Game::Being::pGM = nullptr;

namespace Game{
    Managers::GraphicsManager* Being::pGM = nullptr;
    Being::Being(){
        cout << "Default Being constructor called" << endl;
        id = 0;
        pGM = nullptr;
        pFig = nullptr;
        body = RectangleShape();
    }

    Being::Being(const Vector2f position, const Vector2f size){
        id = 0;
        pGM = nullptr;
        pFig = nullptr;
        body = RectangleShape(size);
        body.setPosition(position);
    }
    Being::Being(const RectangleShape givenbody){
        id = 0;
        pGM = nullptr;
        pFig = nullptr;
        body = givenbody;
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
    
    RectangleShape Being::getBody(){
        return body;
    }
}