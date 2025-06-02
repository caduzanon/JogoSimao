#include <Game.hpp>
#include <Entities/Being.hpp>
#include <Entities/Characters/Player.hpp>

namespace Game{
    using namespace Entities;
    using namespace Characters;

    Unique::Unique() : pGM(GraphicsManager::getInstance()){
        update();
    }

    Unique::~Unique(){

    }

    void Unique::update(){
        Player* Player1 = new Player(Vector2f(300.0f, 300.0f), Vector2f(20.0f, 20.0f));

        while(pGM->isWindowOpen()){
            Event evento;
            RenderWindow* window = pGM->getWindow();
            if(window->pollEvent(evento)){
                if(evento.type == Event::Closed || (evento.type == Event::KeyPressed && evento.key.code == Keyboard::Escape)){
                    pGM->closeWindow();
                }
            }
            pGM->clearWindow();
            Player1->move();
            pGM->render(&Player1->getBody());
            pGM->display();
        }
    }
}