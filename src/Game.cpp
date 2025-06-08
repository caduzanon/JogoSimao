#include <Game.hpp>
#include <Entities/Being.hpp>
#include <Entities/Characters/Player.hpp>
#include <Entities/Obstacles/Platform.hpp>
#include <vector>

#define ALTURA_PLATAFORMA 150.0f 
#define R_PLAT 157 //0 - 255
#define G_PLAT 10 //0 - 255
#define B_PLAT 0 //0 - 255

namespace Game{
    using namespace Entities;
    using namespace Characters;
    using namespace Obstacles;
  
    Game::Game() : 
        pGM(Managers::GraphicsManager::getInstance()), 
        entityList(),
        platform()
    {
        Player* pPlayer1 = new Player(sf::Vector2f(100.0f, 500.0f), Vector2f(30.0f, 50.f), true);
        Player* pPlayer2 = new Player(sf::Vector2f(700.0f, 500.0f), Vector2f(30.0f, 50.f), false);

        entityList.addEntity(static_cast<Entity*>(pPlayer1));
        entityList.addEntity(static_cast<Entity*>(pPlayer2));

        if (pPlayer1) { Being::setGM(pGM); }
        

        float window_size_x = float(pGM->getWindow()->getSize().x);
        float window_size_y = float(pGM->getWindow()->getSize().y);

        Platform* pPlat = new Platform(Vector2f(0.0f, (window_size_y-ALTURA_PLATAFORMA)), Vector2f(window_size_x, ALTURA_PLATAFORMA), Color(R_PLAT, G_PLAT, B_PLAT));
        platform.push_back(pPlat);

        update(); 
    }

    Game::~Game(){
        std::cout << "'Main' destructor called" << std::endl;
        for (int i = 0; i < entityList.getSize(); i++) {
            Entity* pEnt = entityList[i]; 
            if (pEnt) {
                delete pEnt;
            }
        }
        for (auto* p : platform) {
            if (p) {
                delete p;
            }
        }
        platform.clear();
    }

    void Game::update(){
        Clock totalTimeClock;
        //sf::Clock deltaTimeClock;
        while(pGM->isWindowOpen()){
            //sf::Time deltaTime = deltaTimeClock.restart();
            Event evento;
            while(pGM->getWindow()->pollEvent(evento)){
                if(evento.type == Event::Closed || (evento.type == Event::KeyPressed && evento.key.code == Keyboard::Escape)){
                    pGM->closeWindow();
                }
            }

            pGM->clearWindow();
            
            for (auto* p : platform) {
                p->render(*(pGM->getWindow()));
            }

            entityList.update(); 
            entityList.RenderEntities(*(pGM->getWindow()));

            pGM->display();
        }

        sf::Time totalTime = totalTimeClock.getElapsedTime();
        std::cout << "Total Time: " << totalTime.asSeconds() << "s" << std::endl;
    }
}