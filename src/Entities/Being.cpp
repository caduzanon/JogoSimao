#include <Entities/Being.hpp>

namespace Game{
    Being::Being(){
        cout << "Being constructor called" << endl;
        shape = NULL;
    }
    Being::~Being(){
        cout << "Being destructor called" << endl;
    }
    void Being::setGM(Managers::GraphicsManager* pointerGM){
        if (pointerGM != NULL)
            pGM = pointerGM;
    }
    void Being::render(){
        pGM->renderBeing(this);
    }
    RectangleShape* Being::getShape(){
        if(shape != NULL){
            return shape;
        }
    }
}