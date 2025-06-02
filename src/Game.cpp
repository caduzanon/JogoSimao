#include <Game.hpp>
#include <Entities/Being.hpp>
#include <Entities/Characters/Player.hpp>

namespace Game{
    using namespace Entities;
    using namespace Characters;

    Unique::Unique() : pGM(GraphicsManager::getInstance()), pPlayer1(nullptr), pPlayer2(nullptr){
        update();
    }

    Unique::~Unique(){
        cout << "'Main' destructor called" << endl;
        delete(pPlayer1);
        delete(pPlayer2);
    }

    void Unique::update(){
        pPlayer1 = new Player(Vector2f(300.0f, 300.0f), Vector2f(20.0f, 20.0f), true);
        pPlayer2 = new Player(Vector2f(400.0f, 400.0f), Vector2f(15.0f, 15.0f), false);

        while(pGM->isWindowOpen()){
            Event evento;
            RenderWindow* window = pGM->getWindow();
            if(window->pollEvent(evento)){
                if(evento.type == Event::Closed || (evento.type == Event::KeyPressed && evento.key.code == Keyboard::Escape)){
                    pGM->closeWindow();
                }
            }
            pGM->clearWindow();
            pPlayer1->move();
            pPlayer2->move();
            pGM->render(&pPlayer1->getBody());
            pGM->render(&pPlayer2->getBody());
            pGM->display();
        }
    }
}