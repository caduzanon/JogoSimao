#include <Entities/Being.hpp>

namespace Game{
    GraphicsManager* Being::pGM = NULL;
    Being::Being(){

    }
    Being::~Being(){

    }
    void Being::setGM(GraphicsManager* pointerGM){
        pGM = pointerGM->getInstance();
    }
    void Being::draw(){
        
    }
}