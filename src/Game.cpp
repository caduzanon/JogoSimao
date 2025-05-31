#include <Game.hpp>

using namespace Managers;

Game::Game() : pGraphicManager() {
    execute();
}

Game::~Game(){ }

void Game::execute(){
    while (pGraphicManager.isWindowOpen()){
        pGraphicManager.updateDeltaTime();
        pGraphicManager.clear();
        
        //Insert Updates

        pGraphicManager.display();
    }
}