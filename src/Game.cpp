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
        platform(),
        window(pGM->getWindow())
    {
        Player* pPlayer1 = new Player(sf::Vector2f(100.0f, 500.0f), sf::Vector2f(30.0f, 50.f), true);
        Player* pPlayer2 = new Player(sf::Vector2f(700.0f, 500.0f), sf::Vector2f(30.0f, 50.f), false);

        entityList.addEntity(static_cast<Entity*>(pPlayer1));
        entityList.addEntity(static_cast<Entity*>(pPlayer2));

        if (pPlayer1) { Being::setGM(pGM); }
        

        float window_size_x = float(window->getSize().x);
        float window_size_y = float(window->getSize().y);

        Platform* pPlat = new Platform(sf::Vector2f(0.0f, (window_size_y-ALTURA_PLATAFORMA)), sf::Vector2f(window_size_x, ALTURA_PLATAFORMA), sf::Color(R_PLAT, G_PLAT, B_PLAT));
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
        sf::Clock totalTimeClock;
        //sf::Clock deltaTimeClock;
        
        while(pGM->isWindowOpen()){
            //sf::Time deltaTime = deltaTimeClock.restart();

            sf::Event evento;
            while(pGM->getWindow()->pollEvent(evento)){
                if(evento.type == sf::Event::Closed || (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Escape)){
                    pGM->closeWindow();
                }
            }

            pGM->clearWindow();
            
            for (auto* p : platform) {
                p->draw(*(pGM->getWindow()));
            }

            entityList.update(); 
            entityList.RenderEntities(*(pGM->getWindow()));

            pGM->display();
        }

        sf::Time totalTime = totalTimeClock.getElapsedTime();
        std::cout << "Total Time: " << totalTime.asSeconds() << "s" << std::endl;
    }
}