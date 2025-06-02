#include <Entities/Being.hpp>

namespace Game{
    GraphicsManager* Being::pGM = NULL;
    Being::Being(){
        cout << "Being constructor called" << endl;
    }
    Being::~Being(){
        cout << "Being destructor called" << endl;
    }
    void Being::setGM(GraphicsManager* pointerGM){
        pGM = pointerGM->getInstance();
    }
    void Being::draw(){
        
    }
}