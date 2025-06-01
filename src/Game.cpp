#include <Game.hpp>

using namespace Managers;

Game::Game() : pGraphicManager(Graphics::getInstance()), Player1(Math::CoordsF(200.f, 400.f), true) {
    execute();
}

Game::~Game(){ }

void Game::execute(){
    float dt;
    while (pGraphicManager->isWindowOpen()){
        dt = pGraphicManager->updateDeltaTime();
        pGraphicManager->clear();
        
        //Insert Updates
        Player1.update(dt);
        //Insert Renders
        Player1.render();

        pGraphicManager->display();
    }
}