#include <Game.hpp>
#include <Entities/Being.hpp>
#include <Entities/Characters/Player.hpp>
#include <Entities/Obstacles/Platform.hpp>
#include <vector>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

namespace Game{
    using namespace Entities;
    using namespace Characters;
    using namespace Obstacles;

    Game::Game() : 
        pGM(Managers::GraphicsManager::getInstance()), 
        entityList(),
        platform()
    {
        Player* pPlayer1 = new Player(sf::Vector2f(100.0f, 500.0f), sf::Vector2f(30.0f, 50.0f), true);
        Player* pPlayer2 = new Player(sf::Vector2f(700.0f, 500.0f), sf::Vector2f(30.0f, 50.0f), false);

        entityList.addEntity(static_cast<Entity*>(pPlayer1));
        entityList.addEntity(static_cast<Entity*>(pPlayer2));

        if (pPlayer1) { Being::setGM(pGM); }
        
        Platform* pPlat = new Platform(Vector2f(0.0f, 960.0f), Vector2f(1900.0f, 20.0f));
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