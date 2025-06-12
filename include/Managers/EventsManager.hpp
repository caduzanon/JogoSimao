#pragma once
#include <vector>
#include <Managers/GraphicsManager.hpp>
#include <Observer/Observer.hpp>

namespace Game::Managers {

    class EventsManager {
    private:
        // Ponteiro para o singleton do Gerenciador Gráfico
        GraphicsManager* pGraphicsManager;
        
        // Lista de todos os observadores 
        std::vector<Observer::Observer*> observerList;

        //Singleton
        static EventsManager* instance;
        EventsManager();

    public:
        ~EventsManager();
        static EventsManager* getInstance();
        
        // Métodos para gerenciar os observadores
        void addObserver(Observer::Observer* pObserver);
        void removeObserver(Observer::Observer* pObserver);

        // Captura e distribui os eventos
        void handleEvents();
    };

}