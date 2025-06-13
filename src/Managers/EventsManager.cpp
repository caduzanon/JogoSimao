// src/Managers/EventManager.cpp
#include <algorithm> 
#include <Managers/EventsManager.hpp>

namespace Game::Managers {

    EventsManager* EventsManager::instance = nullptr;

    EventsManager* EventsManager::getInstance() {
        if (instance == nullptr) {
            instance = new EventsManager();
        }
        return instance;
    }

    EventsManager::EventsManager() : pGraphicsManager(GraphicsManager::getInstance()) {}

    EventsManager::~EventsManager() {
        observerList.clear();
    }

    void EventsManager::addObserver(Observer::Observer* pObserver) {
        if (pObserver) {
            observerList.push_back(pObserver);
        }
    }

    void EventsManager::removeObserver(Observer::Observer* pObserver) {
        observerList.erase(std::remove(observerList.begin(), observerList.end(), pObserver), observerList.end());
    }

    void EventsManager::handleEvents() {
        sf::Event event;
        while (pGraphicsManager->getWindow()->pollEvent(event)) {
            // Itera por todos os observadores registrados
            for (auto* pObserver : observerList) {
                // Verifica se o observador está ativo antes de notificar
                // e se o evento é relevante para ele
                if (pObserver && pObserver->isActive()) {
                    switch (event.type) {
                        case sf::Event::KeyPressed:
                            pObserver->notifyKeyPressed(event.key.code);
                            break;
                        case sf::Event::KeyReleased:
                            pObserver->notifyKeyReleased(event.key.code);
                            break;
                        case sf::Event::MouseButtonPressed:
                            pObserver->notifyMouseButtonPressed(event.mouseButton);
                            break;
                        case sf::Event::MouseButtonReleased:
                            pObserver->notifyMouseButtonReleased(event.mouseButton);
                            break;
                        case sf::Event::MouseMoved:
                            pObserver->notifyMouseMoved(event.mouseMove);
                            break;
                        case sf::Event::Closed:
                            pGraphicsManager->closeWindow();
                            return; 
                    }
                }
            }
        }
    }
}