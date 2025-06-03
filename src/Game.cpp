#include <Game.hpp>
#include <Entities/Being.hpp>
#include <Entities/Characters/Player.hpp>

namespace Game{
    using namespace Entities;
    using namespace Characters;

    Game::Game() : pGM(GraphicsManager::getInstance()), pPlayer1(nullptr), pPlayer2(nullptr){
        pPlayer1 = new Player(Vector2f(300.0f, 300.0f), Vector2f(20.0f, 20.0f), true);
        pPlayer2 = new Player(Vector2f(400.0f, 400.0f), Vector2f(15.0f, 15.0f), false);
        pPlayer1->setGM(pGM);
        pPlayer2->setGM(pGM);
        update();
    }

    Game::~Game(){
        cout << "'Main' destructor called" << endl;
        delete(pPlayer1);
        delete(pPlayer2);
    }

    void Game::update(){
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
            pPlayer1->render();
            pPlayer2->render();
            pGM->display();
        }
    }
}