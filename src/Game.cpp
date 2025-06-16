#include <Game.hpp>
#include <Entities/Being.hpp>
#include <Entities/Characters/Player.hpp>
#include <Entities/Obstacles/Platform.hpp>
#include <Managers/EventsManager.hpp>
#include <vector>
#include <IDs.hpp>
#include <iostream>

#define ALTURA_PLATAFORMA 50.0f 
#define R_PLAT 157 //0 - 255
#define G_PLAT 10 //0 - 255
#define B_PLAT 0 //0 - 255

namespace Game{
    using namespace Entities;
    using namespace Characters;
    using namespace Obstacles;
 
    Game::Game() : 
        pGM(Managers::GraphicsManager::getInstance()), 
        pEM(Managers::EventsManager::getInstance()),
        entityList(),
        totalTimeClock(Clock()),
        pCM(new Managers::CollisionManager())
    {
        Being::setGM(pGM); 
        Being::setEM(pEM);

        Player* pPlayer1 = new Player(sf::Vector2f(100.0f, 500.0f), Vector2f(30.0f, 50.f), true, IDs::Player1);
        Player* pPlayer2 = new Player(sf::Vector2f(700.0f, 500.0f), Vector2f(30.0f, 50.f), false, IDs::Player2);

        entityList.addEntity(static_cast<Entity*>(pPlayer1));
        entityList.addEntity(static_cast<Entity*>(pPlayer2));

        float window_size_x = float(pGM->getWindow()->getSize().x);
        float window_size_y = float(pGM->getWindow()->getSize().y);

        Platform* pPlat = new Platform(Vector2f(0.0f, (window_size_y-ALTURA_PLATAFORMA)), Vector2f(window_size_x, ALTURA_PLATAFORMA), Color(R_PLAT, G_PLAT, B_PLAT), IDs::Platform);

        platList.addEntity(static_cast<Entity*>(pPlat));
        pCM->setLists(&entityList, &platList, nullptr, nullptr);
        // update(); 
    }

    Game::~Game(){
        std::cout << "'Main' destructor called" << std::endl;
        delete pCM;
    }

    void Game::update(){
        while(pGM->isWindowOpen()){
            pEM->handleEvents();
            
            pGM->clearWindow();

            platList.update();
            platList.RenderEntities(*(pGM->getWindow()));
            entityList.update(); 
            entityList.RenderEntities(*(pGM->getWindow()));
            pCM->update();

            pGM->display();
        }

        // sf::Time totalTime = totalTimeClock.getElapsedTime();
        // std::cout << "Total Time: " << totalTime.asSeconds() << "s" << std::endl;
    }
}